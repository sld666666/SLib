#pragma  once

namespace slib{
	template <int inst>//�Ժ������Ҫ�µķ��䷽ʽ������ƫ�ػ�֮
	class MallocAlloc
	{
	public:
		static void*	allocate(size_t size);
		static void*	reallocate(void* buffer, size_t newSize);
		static void		deallocate(void* buffer);
	};

	template <int inst>
	void* MallocAlloc<inst>::allocate(size_t size)
	{
		void* result = malloc(size);
		return result;
	}

	template <int inst>
	void*	MallocAlloc<inst>::reallocate(void* buffer, size_t newSize)
	{
		void* result = realloc(buffer, newSize);
		return result;
	}

	template <int inst>
	void MallocAlloc<inst>::deallocate(void*buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}