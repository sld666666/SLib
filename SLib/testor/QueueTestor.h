#pragma once
#define  BOOST_TEST_MODULE StackTestor
#include <boost/test/included/unit_test.hpp>
#include "../container/Queue.h"
BOOST_AUTO_TEST_SUITE (StackTestor)

BOOST_AUTO_TEST_CASE (test1)
{
	slib::Queue<int> iqueue;
 	iqueue.push(1);
	iqueue.push(2);
	iqueue.push(3);
	iqueue.push(4);
	int size = iqueue.size();
 	BOOST_CHECK(4 == iqueue.size());
 	BOOST_CHECK(!iqueue.empty());
 	BOOST_CHECK(1 == iqueue.front());
 	iqueue.pop();
 	BOOST_CHECK(2 == iqueue.front()) ;
}

BOOST_AUTO_TEST_SUITE_END( )