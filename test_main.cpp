#define BOOST_TEST_MODULE test_main

#include "ip_filter.h"

#include "a_plus_b.h"
#include "reverse_sqrt.h"
#include "localization_problem.h"
#include "sulfide_mass.h"
#include "olympiad.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(ip_split_test)
{
	std::string ip_s{ "113.162.145.156" };
	ip_addr ip{ 113, 162, 145, 156 };

	auto result = split(ip_s, '.');

	for (std::size_t i = 0; i < ip.size(); i++) {
		BOOST_CHECK_EQUAL(ip[i], std::stoi(result[i]));
	}
}

BOOST_AUTO_TEST_CASE(ip_sort_test)
{
	ip_addr ip0{ 128, 0, 0, 0 };
	ip_addr ip1{ 64, 0, 0, 4 };
	ip_addr ip2{ 64, 0, 0, 2 };

	std::vector<ip_addr> data{
		ip2,
		ip0,
		ip1
	};

	std::vector<ip_addr> result = ip_sort(data);

	BOOST_CHECK_EQUAL_COLLECTIONS(result[0].begin(), result[0].end(), ip0.begin(), ip0.end());
	BOOST_CHECK_EQUAL_COLLECTIONS(result[1].begin(), result[1].end(), ip1.begin(), ip1.end());
	BOOST_CHECK_EQUAL_COLLECTIONS(result[2].begin(), result[2].end(), ip2.begin(), ip2.end());
}

BOOST_AUTO_TEST_CASE(ip_filter_test)
{
	std::vector<ip_addr> data{
		ip_addr{ 128, 0, 0, 2 },
		ip_addr{ 128, 0, 0, 4 },
		ip_addr{ 256, 0, 0, 8 },
		ip_addr{ 256, 16, 0, 8 }
	};

	std::vector<ip_addr> check0 = filter(data, 128);

	BOOST_CHECK_EQUAL_COLLECTIONS(check0[0].begin(), check0[0].end(), data[0].begin(), data[0].end());
	BOOST_CHECK_EQUAL_COLLECTIONS(check0[1].begin(), check0[1].end(), data[1].begin(), data[1].end());

	std::vector<ip_addr> check1 = filter(data, 256, 16);

	BOOST_CHECK_EQUAL_COLLECTIONS(check1[0].begin(), check1[0].end(), data[3].begin(), data[3].end());

	std::vector<ip_addr> check2 = filter_any(data, 16);

	BOOST_CHECK_EQUAL_COLLECTIONS(check2[0].begin(), check2[0].end(), data[3].begin(), data[3].end());
}

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
