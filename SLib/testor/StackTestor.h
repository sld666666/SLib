#pragma once
#define  BOOST_TEST_MODULE StackTestor
#include <boost/test/included/unit_test.hpp>
#include "../container/Stack.h"
BOOST_AUTO_TEST_SUITE (StackTestor)

BOOST_AUTO_TEST_CASE (test1)
{
	slib::Stack<int> istack;
 	istack.push(1);
	istack.push(2);
	istack.push(3);
	istack.push(4);
	int size = istack.size();
 	BOOST_CHECK(4 == istack.size());
 	BOOST_CHECK(!istack.empty());
 	BOOST_CHECK(4 == istack.top());
 	istack.pop();
 	BOOST_CHECK(3 == istack.top()) ;
}

BOOST_AUTO_TEST_SUITE_END( )