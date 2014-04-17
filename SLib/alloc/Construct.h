#pragma once

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
	if(pointer)pointer->~T();
}

template<typename ForwardIterator>
void destroyAux(ForwardIterator first, ForwardIterator last)
{
	for (; first != last; +=first)
	{
		destroy(&*first);
	}
}