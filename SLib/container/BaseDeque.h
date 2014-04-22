#pragma  once
#include "../iterator/DequeIterator.h"

namespace slib{
	template< typename T, typename Alloc>
	class BaseDeque{
		typedef DequeIterator<T>	Iterator;
	public:
		BaseDeque() 
			: map_(0)
			, mapSize_(0)
			, begin_()
			, end_()
		{

		}

	protected:
		T**			map_;
		size_t		mapSize_;
		Iterator	begin_;
		Iterator	end_;

	};
}