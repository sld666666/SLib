#pragma once
#include "BaseVector.h"
#include "TypeDefinition.h"

namespace slib{
	template <typename T, typename Alloc = DefaultAlloc>
	class Vector : public BaseVector<T, Alloc>
		, public TypeDefinition<T>{

	public:
		Vector(): Base(){}
		Vector(const SizeType n,  const T& value);
	public:
		Iterator	begin();
		Iterator	end();

		SizeType	size() const;
		SizeType	capacity() const;
		bool		empty() const;

		void		pushback(const T& val);
		void		popback();

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

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::SizeType Vector<T, Alloc>::size() const 
	{
		return (end() - begin());
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::SizeType Vector<T, Alloc>::capacity() const
	{
		return (endOfStorage_ - begin());
	}

	template<typename T, typename Alloc>
	bool Vector<T, Alloc>::empty() const 
	{
		return (begin() == end());
	}


	template<typename T, typename Alloc>
	void Vector<T, Alloc>::pushback(const T& val)
	{
		insert(end(), val);
	}

	template<typename T, typename Alloc>
	void Vector<T, Alloc>::popback()
	{
		--end_;
		destroy(end_);
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator 
		Vector<T, Alloc>::insert(Iterator pos
								 , const T& val)
	{
		Base::auxInsert(pos, val);
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator
		Vector<T, Alloc>::erase(Iterator pos)
	{
		if(pos +1 != end()){
			copy(pos+1, end_, pos);
		}
		--end_;
		destroy(end_);
		return pos;
	}

	template<typename T, typename Alloc>
	typename Vector<T, Alloc>::Iterator
		Vector<T, Alloc>::erase(Iterator first
								, Iterator last)
	{
		Iterator pos = copy(last, end_, first);
		destroy(pos, end_);
		end_ = end_ - (last - first);
	}

	template<typename T, typename Alloc>
	void Vector<T, Alloc>::clear()
	{
		erase(begin(), end());
	}



}
