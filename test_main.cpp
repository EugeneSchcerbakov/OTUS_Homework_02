#define BOOST_TEST_MODULE test_main

#include "a_plus_b.h"
#include "reverse_sqrt.h"
#include "localization_problem.h"
#include "sulfide_mass.h"
#include "olympiad.h"

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

BOOST_AUTO_TEST_CASE(number_localization_valid)
{
	BOOST_CHECK_EQUAL(LocalizeNumber(2), "few");
	BOOST_CHECK_EQUAL(LocalizeNumber(7), "several");
	BOOST_CHECK_EQUAL(LocalizeNumber(10), "pack");
	BOOST_CHECK_EQUAL(LocalizeNumber(30), "lots");
	BOOST_CHECK_EQUAL(LocalizeNumber(80), "horde");
	BOOST_CHECK_EQUAL(LocalizeNumber(150), "throng");
	BOOST_CHECK_EQUAL(LocalizeNumber(300), "swarm");
	BOOST_CHECK_EQUAL(LocalizeNumber(700), "zounds");
	BOOST_CHECK_EQUAL(LocalizeNumber(1024), "legion");
}

BOOST_AUTO_TEST_CASE(sulfide_mass_valid)
{
	BOOST_CHECK(CalcSulfideMassTest());
}

BOOST_AUTO_TEST_CASE(olympiad_valid)
{
	BOOST_CHECK(TestIsPossibleToSolve());
}

BOOST_AUTO_TEST_SUITE_END()
