#include "olympiad.h"

#define BOOST_TEST_MODULE test_olympiad

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_olympiad)

BOOST_AUTO_TEST_CASE(test)
{
	BOOST_CHECK(TestIsPossibleToSolve());
}

BOOST_AUTO_TEST_SUITE_END()
