#pragma once
#define  BOOST_TEST_MODULE VectorTestor
#include <boost/test/included/unit_test.hpp>
#include "../container/Vector.h"
BOOST_AUTO_TEST_SUITE (VectorTestor)

BOOST_AUTO_TEST_CASE (test1)
{
	slib::Vector<int> vec0;
	vec0.push_back(1);
	vec0.push_back(2);

	BOOST_CHECK(1==vec0[0]);
	BOOST_CHECK(2==vec0[1]);

	BOOST_CHECK(!vec0.empty());
	BOOST_CHECK( 2== vec0.size());
	BOOST_CHECK( 2== vec0.capacity());

	vec0.insert((vec0.begin()+1), 3);
	BOOST_CHECK(3==vec0[1]);

	BOOST_CHECK( 3== vec0.size());
	BOOST_CHECK( 4== vec0.capacity());
	vec0.pop_back();
	BOOST_CHECK( 2== vec0.size());

	vec0.erase(vec0.begin(), vec0.end());
	BOOST_CHECK(vec0.empty());
}

BOOST_AUTO_TEST_SUITE_END( )