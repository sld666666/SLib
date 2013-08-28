#ifndef ALLOC_NODEALLOC_H
#define ALLOC_NODEALLOC_H

class NodeAlloc
{
public:
	NodeAlloc(){}
	~NodeAlloc(){}

public:
	static void* allocate(size_t n);
	static void deAllocate(void* p, size_t size);
	static void* mAllocate(size_t n);
	static void* mDeAllocate(void*p, size_t size);
};

#endif // ALLOC_NODEALLOC_H