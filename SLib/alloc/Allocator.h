#ifndef ALLOCATOR_H
#define ALLOCATOR_H

template<typename T>
class Allocator
{

public:
	Allocator(){}
	~Allocator(){}

public:
	T*	address(T& val);
	const T* address(const T& val);
	T* allocate(size_t allocSize);
	void deAllocate(T* address, size_t size);
	void deAllocate(T* address);
	size_t maxSize() const ;


};

template<typename T>
T* Allocator<T>::address(T& val)
{
	return & val;
}

template<typename T>
const T* Allocator<T>::address(const T& val)
{
	return &val;
}

template<typename T>
T* allocate(size_t allocSize)
{

}

template<typename T>
void Allocator<T>::deAllocate(T* address, size_t size)
{

}

template<typename T>
void Allocator<T>::deAllocate(T* address)
{

}

template<typename T>
size_t Allocator<T>::maxSize() const 
{
	return sizeof(-1)/sizeof(T);
	//得本机能申请的最大内存
}


#endif // ALLOCATOR_H
