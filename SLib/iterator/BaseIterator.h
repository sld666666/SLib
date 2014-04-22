#pragma once
#include "IteratorTraits.h"
namespace slib{

	template <typename Iterator>
	inline typename IteratorTraits<Iterator>::ValueType*
		valueType(const Iterator& )
	{
		return static_cast<typename IteratorTraits<Iterator>::ValueType*>(0);
	}

	template<typename InputIterator, typename Distance>
	inline void distance(InputIterator first, InputIterator last, Distance& result)
	{
		while(first != last){++ first; ++result;}
	}
}