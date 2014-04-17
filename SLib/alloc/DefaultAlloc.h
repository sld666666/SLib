#pragma once
#include "MallocAlloc.h"

namespace slib{
	template<bool threads, int inst>
	class DefaultAlloc
	{
	private:
		enum {ALIGN = 8};
		enum {MAX_BYTES = 128};
		enum {NFREELISTS = 16};

		union Obj{
			union Obj* free_list_link;
			char CleintData[1];
		};

		typedef MallocAlloc<0>  Alloc;

	private:
		static Obj* freeList_;
	public:
		static void* allocate(size_t n);
		static void deallocate(void* buffer, size_t n);

	private:
		static  size_t freelistIndex(size_t bytes) {
			return (((bytes) + (size_t)bytes-1)/(size_t)bytes - 1);
		}

		static size_t roundUp(size_t bytes) { 
			return (((bytes) + (size_t) ALIGN-1) & ~((size_t) ALIGN - 1)); }

	};

	template<bool threads, int inst>
	void* DefaultAlloc<threads, inst>:: allocate(size_t n)
	{
		void* rtn = 0;
		//	if(n > (size_t)(MAX_BYTES)){
		rtn = Alloc::allocate(n);
		// 	}else{
		// 		
		// 	}

		return rtn;
	}

	template<bool threads, int inst>
	void DefaultAlloc<threads, inst>::deallocate(void* buffer, size_t n)
	{
		Alloc::deallocate(buffer);
	}
}