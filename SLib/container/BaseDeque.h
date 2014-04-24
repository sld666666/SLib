#pragma  once
#include "../iterator/DequeIterator.h"
#include "Vector.h"

namespace slib{
	template< typename T, typename Alloc>
	class BaseDeque{
	public:
		typedef DequeIterator<T>	Iterator;
	public:
		BaseDeque() 
			: begin_()
			, end_()
		{
			initializate();
		}

	protected: 
		typedef SimpleAlloc<T, Alloc>	DataAllocator;

		void allocateNodeAtBack()
		{
			T* node = DataAllocator::allocate(dequeBufSize(sizeof(T)));
			map_.push_back(node);
			
			resetNode();
		}

		void allocateNodeAtFront()
		{
			T* node = DataAllocator::allocate(dequeBufSize(sizeof(T)));
			map_.insert(map_.begin(), node);
			resetNode();
			begin_.cur = begin_.last;
		}

		void initializate()
		{
			T* node = DataAllocator::allocate(dequeBufSize(sizeof(T)));
			map_.push_back(node);
			resetNode();
		}

		void resetNode(){
			begin_ =  Iterator(map_[0], &map_[0]);

			Vector<T*>::Iterator iter = map_.end();
			iter = iter -1;
			end_ = Iterator(*iter, iter);

		}
	protected:
		Vector<T*>	map_;
		Iterator	begin_;
		Iterator	end_;

	};
}