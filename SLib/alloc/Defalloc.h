#pragma once


template <class T>
class allocator {
public:
	T* allocate(){
		return new T();
	}

	void deallocate(T* p){
		delete p;
		p = NULL;
	}
};

