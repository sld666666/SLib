#ifndef CONTAINER_SBASEVECTOR_H
#define  CONTAINER_SBASEVECTOR_H
#include "../alloc/SimpleAlloc.h"
#include "../alloc/Construct.h"

namespace slib{
	template <typename T, typename Alloc>
	class BaseVector{
	public:
		BaseVector()
			: begin_(0)
			, end_(0)
			, endOfStorage_(0)
		{
		}

		BaseVector(const size_t n,  const T& value)
		{
			begin_ = DataAllocator::allocate(n);
			end_ = begin_;
			endOfStorage_ = begin_ + n;
		}

	protected:
		typedef SimpleAlloc<T, Alloc>	DataAllocator;

	protected:
		void	auxInsert(T* positon, const T& value);
		void	insert(T* newbegin, T* positon, const T& value);
		size_t	size() const;

	protected:
		T*	begin_;
		T*	end_;
		T*	endOfStorage_;

	};


	template <typename T, typename Alloc>
	void BaseVector<T, Alloc>::auxInsert(T* positon
										, const T& value)
	{
		if (end_ != endOfStorage_){
			construct(end_, *(end_-1));
			++end_;
			copy_backward(positon, end_-1, end_);
			*positon = value;
		}else{
			const size_t length =  (0 ==size())? 2 : 2*size();
			T* newbegin = DataAllocator::allocate(length);
			insert(newbegin, positon, value);

			endOfStorage_ = newbegin + length;
		}
	}

	template <typename T, typename Alloc>
	void BaseVector<T, Alloc>::insert(T* newbegin
										, T* positon
										, const T& value)
	{
		T* newFinish = uninitialized_copy(begin_, positon, newbegin);
		construct(newFinish, value);
		++newFinish;
		newFinish = uninitialized_copy(positon, end_, newFinish);

		destroy(begin_, end_);
		begin_ = newbegin;
		end_ = newFinish;
	}

	template <typename T, typename Alloc>
	size_t BaseVector<T, Alloc>::size()const
	{
		return size_t(end_ - begin_);
	}

}

#endif