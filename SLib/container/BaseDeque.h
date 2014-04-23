#pragma  once
#include "../iterator/DequeIterator.h"
#include "Vector.h"

namespace slib{
	template< typename T, typename Alloc>
	class BaseDeque{
		typedef DequeIterator<T>	Iterator;
	public:
		BaseDeque() 
			: begin_()
			, end_()
		{

		}

	protected:
		Vector<T*>	map_;
		Iterator	begin_;
		Iterator	end_;

	};
}