#include "a_plus_b.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test)
{
	BOOST_CHECK(A_Plus_B_Test());
}

BOOST_AUTO_TEST_SUITE_END()
