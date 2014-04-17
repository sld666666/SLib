#pragma  once

#define  BOOST_TEST_MODULE UnInitializedTestor
#include <boost/test/included/unit_test.hpp>
#include "../alloc/uninitialized.h"
BOOST_AUTO_TEST_SUITE (UnInitializedTestor)

BOOST_AUTO_TEST_CASE (testCopy)
{
	int ary[6]= {0,1,2,3,4,5};
	int* begin = ary;
	int* end = ary+3;
	int* result = ary+3;
	result = uninitialized_copy<int* ,int*, int*>(begin, end, result);
	BOOST_CHECK(1==ary[4]);
	BOOST_CHECK(ary[5]==*(result-1));
}

BOOST_AUTO_TEST_CASE(testCopy2)
{
	struct Test{
		Test(int _a): a( _a){}
		int a;
	};

	Test tests[6] = {Test(0), Test(1), Test(2), Test(3), Test(4), Test(5)};
	Test* begin = tests;
	Test* end = tests + 3;
	Test* result = tests + 3;
	uninitialized_copy<Test*, Test*, Test*>(begin, end, result);
	BOOST_CHECK(1==tests[4].a);
}

BOOST_AUTO_TEST_CASE(testCopy3)
{
	struct Test{
		Test(int _a): a( _a){}
		int a;
	};

	Test tests[6] = {Test(0), Test(1), Test(2), Test(3), Test(4), Test(5)};
	Test* begin = tests;
	Test* end = tests + 3;
	Test* result = tests + 3;
	uninitialized_copy<Test*, Test*, Test>(begin, end, result);
	BOOST_CHECK(1==tests[4].a);
}


BOOST_AUTO_TEST_SUITE_END( )