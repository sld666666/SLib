#pragma once
#include "IteratorTraits.h"
namespace slib{

	template <typename Iterator>
	inline typename IteratorTraits<Iterator>::ValueType*
		valueType(const Iterator& )
	{
		return static_cast<typename IteratorTraits<Iterator>::ValueType*>(0);
	}
}