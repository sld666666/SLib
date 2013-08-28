#ifndef CONTAINER_SBASEVECTOR_H
#define  CONTAINER_SBASEVECTOR_H

template <typename T, typename Alloc>
class SBaseVector{

public:
	SBaseVector()
		: begin_(0)
		, end_(0){

	}

protected:
	void inserOverflow(T* pos, const T& x, size_t fillLen);
protected:
	T*	begin_;
	T*	end_;

};


template <typename T>
void SBaseVector<T>::inserOverflow(T* pos, const T& x, size_t fillLen)
{

}

#endif