#pragma once

#define  BOOST_TEST_MODULE LisTestor
#include <boost/test/included/unit_test.hpp>
#include "../container/List.h"
BOOST_AUTO_TEST_SUITE (LisTestor)
BOOST_AUTO_TEST_CASE (test1)
{
	slib::List<int> list;
	list.push_back(1);
 	list.push_back(2);
 	BOOST_CHECK(2 == list.size());

	slib::List<int> ::Iterator iter = list.begin();
 	BOOST_CHECK(1 == *iter);
	++iter;
	BOOST_CHECK(2 == *iter);

	list.insert(list.end(), 3);
	++iter;
	BOOST_CHECK(3 == *iter);

	list.erase(iter);
	BOOST_CHECK(2 == list.size());

	list.pop_front();
	BOOST_CHECK(2 == *list.begin());

	list.clear();
	BOOST_CHECK(0 == list.size());
}
BOOST_AUTO_TEST_SUITE_END( )