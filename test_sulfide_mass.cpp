#include "sulfide_mass.h"

#define BOOST_TEST_MODULE test_sulfide_mass

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test)
{
	BOOST_CHECK(CalcSulfideMassTest());
}

BOOST_AUTO_TEST_SUITE_END()
