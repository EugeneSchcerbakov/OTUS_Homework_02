#include "a_plus_b.h"
#include "reverse_sqrt.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(a_plus_b_valid)
{
	BOOST_CHECK(A_Plus_B_Test());
}

BOOST_AUTO_TEST_CASE(reverse_sqrt_valid)
{
	BOOST_CHECK(ReverseSquareRootTest());
}

BOOST_AUTO_TEST_SUITE_END()
