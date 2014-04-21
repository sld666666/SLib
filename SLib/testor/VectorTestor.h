#pragma once
#define  BOOST_TEST_MODULE VectorTestor
#include <boost/test/included/unit_test.hpp>
#include "../container/Vector.h"
BOOST_AUTO_TEST_SUITE (VectorTestor)

BOOST_AUTO_TEST_CASE (test1)
{
	_CrtSetBreakAlloc(1080); 
	slib::Vector<int> vec0;
	vec0.push_back(1);
	vec0.push_back(2);

	BOOST_CHECK(1==vec0[0]);
	BOOST_CHECK(2==vec0[1]);

	BOOST_CHECK(!vec0.empty());
	BOOST_CHECK( 2== vec0.size());
	BOOST_CHECK( 4== vec0.capacity());


}

BOOST_AUTO_TEST_SUITE_END( )