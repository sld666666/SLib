#ifndef SVECTOR_H
#define  SVECTOR_H

template <typename T>
class SVector{

public:
	SVector()
		: begin_(0)
		, end_(0)
	{

	}

public:
	void pushBack(const T& val);
private:
	void inserOverflow();

private:
	T*	begin_;
	T*	end_;

};

template <typename T>
void SVector<T>::pushBack(const T& val)
{
	if (this->begin_ != this->end_){

	}else{
		
	}
}

#endif