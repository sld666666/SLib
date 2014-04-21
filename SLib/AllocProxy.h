#ifndef ALLOC_ALLOCPROXY_H
#define ALLOC_ALLOCPROXY_H

template<typename Value, typename T, typename ReboundAllco>

class AllocProxy : public ReboundAllco
{
public:
	AllocProxy(const ReboundAllco& alloc, Value value)
		: ReboundAllco(alloc)
		, data_(value){

	}

	~AllocProxy(){}

	T* allocate(size_t len, size_t* allocatedLen)
	{
		return ReboundAllco::allocate(len, allocatedLen);
	}

public:
	value	data_;

};

#endif // ALLOC_ALLOCPROXY_H