#pragma once
#include "TypeTraits.h"

namespace slib{
	template <typename T>
	inline void _destroy(T* pointer, const FalseType&)
	{
		if(pointer){
			pointer->~T();
		}
	}

	template <typename T>
	inline void _destroy(T* pointer, const TrueType&)
	{	
	}

	template<typename T>
	inline void construct(T* p)
	{
		new ((void*)p) T();
	}

	template<typename T1, typename T2>
	inline	void construct(T1* p, const T2& val)
	{
		new ((void*)p) T1(val);
	}

	template<typename T>
	inline void destroy(T* pointer)
	{
		typedef typename TypeTraits<T>::is_POD_type IsPod;
		_destroy(pointer, IsPod());
	}

	template<typename ForwardIterator>
	void destroy(ForwardIterator first, ForwardIterator last)
	{
		for (; first != last; ++first)
		{
			destroy(&*first);
		}
	}
}
