#pragma 
#include "BaseDeque.h"
#include "alloc/DefaultAlloc.h"
#include "TypeDefinition.h"

namespace slib{

	template <typename T, typename Alloc = slib::DefaultAlloc<false, 0>>
	class Deque : public BaseDeque<T, Alloc>
			, public TypeDefinition<T>{

	};

}