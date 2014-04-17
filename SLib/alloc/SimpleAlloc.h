#pragma once

namespace slib{
	template<typename T, typename Alloc>
	class SimpleAlloc{
	public:
		static T* allocate(size_t n)
		{ return 0 == n ? 0 : (T*) Alloc::allocate(n * sizeof (T)); }

		static T* allocate()
		{ return (T*) Alloc::allocate(sizeof (T)); }

		static void deallocate(T* p, size_t n)
		{ if (0 != n) Alloc::deallocate(p, n * sizeof (T)); }

		static void deallocate(T* p)
		{ Alloc::deallocate(p, sizeof (T)); }

	};
}