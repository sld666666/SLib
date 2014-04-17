#pragma once

#define  BOOST_TEST_MODULE AllocTest
#include <boost/test/included/unit_test.hpp>
#include "../alloc/MallocAlloc.h"
#include "../alloc/DefaultAlloc.h"
#include "../alloc/SimpleAlloc.h"
#include "../alloc/Construct.h"
BOOST_AUTO_TEST_SUITE (AllocTest)

BOOST_AUTO_TEST_CASE (test1)
{
	slib::MallocAlloc<0> allocator;
	void* buffer = allocator.allocate(100);
	BOOST_CHECK(NULL != buffer);

	buffer = allocator.reallocate(buffer, 100);
	BOOST_CHECK(NULL != buffer);

	allocator.deallocate(buffer);
}

BOOST_AUTO_TEST_CASE (test2)
{
	slib::DefaultAlloc<false, 0> allocator;
	void* buffer = allocator.allocate(100);
	BOOST_CHECK(NULL != buffer);

	allocator.deallocate(buffer, 100);
}

BOOST_AUTO_TEST_CASE (test3)
{
	typedef slib::DefaultAlloc<false, 0> Alloc;
	slib::SimpleAlloc<int, Alloc> simpleAlloc;
	int* buffer = simpleAlloc.allocate(10);
	BOOST_CHECK(NULL != buffer);
	simpleAlloc.deallocate(buffer);
}

BOOST_AUTO_TEST_CASE (test4)
{
	class Obj{
	public:
		Obj(){
			int i(0);
		}

		~Obj(){
			int i(0);
		}
	};

	typedef slib::DefaultAlloc<false, 0> Alloc;
	slib::SimpleAlloc<Obj, Alloc> simpleAlloc;
	Obj* buffer = simpleAlloc.allocate(1);
	BOOST_CHECK(NULL != buffer);
	//simpleAlloc.deallocate(buffer);

	construct<Obj>(buffer);
	destroy<Obj>(buffer);
}


BOOST_AUTO_TEST_SUITE_END( )