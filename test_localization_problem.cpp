#include "localization_problem.h"

#define BOOST_TEST_MODULE test_localization_problem

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_localization_problem)

BOOST_AUTO_TEST_CASE(test)
{
	BOOST_CHECK(LocalizeNumberTest());
}

BOOST_AUTO_TEST_SUITE_END()
