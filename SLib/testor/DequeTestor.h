#pragma once
#define  BOOST_TEST_MODULE DequeTestor
#include <boost/test/included/unit_test.hpp>
#include "../container/Deque.h"
BOOST_AUTO_TEST_SUITE (DequeTestor)

BOOST_AUTO_TEST_CASE (test1)
{
	slib::Deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_front(0);
	int val = deq[1];
	BOOST_CHECK(1 == val);
	slib::Deque<int>::Iterator pos = deq.begin();
	val = *pos;

	val = *(++pos);
	slib::Deque<int>::Iterator pos1 = deq.end();
	for (slib::Deque<int>::Iterator pos = deq.begin()
		; pos != deq.end(); ++ pos){
		val = *pos;
	}
}

BOOST_AUTO_TEST_SUITE_END( )