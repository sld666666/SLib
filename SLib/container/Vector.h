#pragma once
#include "BaseVector.h"
#include "TypeDefinition.h"
#include "alloc/DefaultAlloc.h"

namespace slib{
	template <typename T, typename Alloc = slib::DefaultAlloc<false, 0>>
	class Vector : public BaseVector<T, Alloc>
		, public TypeDefinition<T>{

	public:
		typedef ValueType*			Iterator;
		typedef const ValueType*	ConstIterator;

		Vector(): Base(){}
		Vector(const SizeType n,  const T& value);

		Reference operator[](SizeType n){return *(begin()+n);}
		~Vector(){Base::objDestroy(begin_, endOfStorage_);}
	public:
		Iterator	begin();
		Iterator	begin() const;
		Iterator	end();
		Iterator	end() const;

		SizeType	size() const;
		SizeType	capacity() const;
		bool		empty() const;

		void		push_back(const T& val);
		void		pop_back();

		Iterator	insert(Iterator pos, const T& val);
		Iterator	erase(Iterator pos);
		Iterator	erase(Iterator first, Iterator last);
		void		clear();


	private:
		typedef BaseVector<T, Alloc> Base;

	};


	template <typename T, typename Alloc>
	Vector<T, Alloc>::Vector(const SizeType n
							,  const T& value)
	{
		end_  = uninitialized_fill_n(begin_, n, value);
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator  Vector<T, Alloc>::begin()
	{
		return begin_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator Vector<T, Alloc>::end()
	{
		return end_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator  Vector<T, Alloc>::begin() const
	{
		return begin_;
	}

	template <typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator Vector<T, Alloc>::end() const
	{
		return end_;
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::SizeType Vector<T, Alloc>::size() const 
	{
		return SizeType(end() - begin());
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::SizeType Vector<T, Alloc>::capacity() const
	{
		return SizeType(endOfStorage_ - begin());
	}

	template<typename T, typename Alloc>
	bool Vector<T, Alloc>::empty() const 
	{
		return (begin() == end());
	}


	template<typename T, typename Alloc>
	void Vector<T, Alloc>::push_back(const T& val)
	{
		insert(end(), val);
	}

	template<typename T, typename Alloc>
	void Vector<T, Alloc>::pop_back()
	{
		--end_;
		Base::mDestroy(end_);
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator 
		Vector<T, Alloc>::insert(Iterator pos
								 , const T& val)
	{
		Base::auxInsert(pos, val);
		return end_;
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator
		Vector<T, Alloc>::erase(Iterator pos)
	{
		if(pos +1 != end()){
			copy(pos+1, end_, pos);
		}
		--end_;
		Base::mDestroy(end_);
		return pos;
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator
		Vector<T, Alloc>::erase(Iterator first
								, Iterator last)
	{
		Iterator pos = copy(last, end_, first);
		Base::objDestroy(pos, end_);
		end_ = end_ - (last - first);
		return pos;
	}

	template<typename T, typename Alloc>
	void Vector<T, Alloc>::clear()
	{
		erase(begin(), end());
	}



}
