#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <assert.h>

#include "reverse_sqrt.h"
#include "localization_problem.h"
#include "sulfide_mass.h"
#include "olympiad.h"

typedef std::vector<std::string> ip_addr;

std::vector<std::string> split(const std::string &str, char d)
{
	std::vector<std::string> r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

std::vector<ip_addr> read_ip(const std::string& filename)
{
	std::ifstream file;
	std::vector<ip_addr> ip_pool;

	file.open(filename);

	if (!file.is_open()) {
		return ip_pool;
	}

	std::string ip_line;

	while (std::getline(file, ip_line))
	{
		std::vector<std::string> v = split(ip_line, '\t');
		ip_pool.push_back(split(v.at(0), '.'));
	}

	file.close();

	return ip_pool;
}

std::vector<ip_addr> ip_sort(const std::vector<ip_addr>& input)
{
	std::vector<ip_addr> ip_filter(input);

	std::sort(ip_filter.begin(), ip_filter.end(), [](const ip_addr& ip_a, const ip_addr& ip_b)
	{
		for (std::size_t i = 0; i < std::min(ip_a.size(), ip_b.size()); i++)
		{
			int byte_a = std::atoi(ip_a[i].c_str());
			int byte_b = std::atoi(ip_b[i].c_str());

			if (byte_a == byte_b) {
				continue;
			} else {
				return byte_a > byte_b;
			}
		}

		return false;
	});

	return ip_filter;
}

template<typename ...Args>
std::vector<ip_addr> filter(const std::vector<ip_addr>& ip_pool, Args ...args)
{
	assert(sizeof...(args) <= 4);

	std::vector<ip_addr> result;
	int filter[] = { args... };

	for (auto iter = ip_pool.cbegin(); iter != ip_pool.cend(); iter++)
	{
		const ip_addr& ip = *iter;
		bool passed = true;

		for (int i = 0; i < sizeof...(args); i++) {
			if (std::atoi(ip[i].c_str()) != filter[i]) {
				passed = false;
				break;
			}
		}

		if (passed) {
			result.push_back(ip);
		}
	}

	return result;
}

std::vector<ip_addr> filter_any(const std::vector<ip_addr>& ip_pool, int byte)
{
	std::vector<ip_addr> result;

	for (auto iter = ip_pool.cbegin(); iter != ip_pool.cend(); iter++)
	{
		for (auto ip_iter = (*iter).cbegin(); ip_iter != (*iter).cend(); ip_iter++)
		{
			if (std::atoi((*ip_iter).c_str()) == byte) {
				result.push_back(*iter);
				break;
			}
		}
	}

	return result;
}

void ip_print(const std::vector<ip_addr>& ip_pool)
{
	for (std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
	{
		for (std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
		{
			if (ip_part != ip->cbegin())
			{
				std::cout << ".";

			}
			std::cout << *ip_part;
		}
		std::cout << std::endl;
	}
}

int main()
{
	try
	{
		std::vector<ip_addr> ip_pool;
#ifdef _WIN32
		ip_pool = read_ip("ip.tsv");
#else
		for (std::string line; std::getline(std::cin, line);)
		{
			std::vector<std::string> v = split(line, '\t');
			ip_pool.push_back(split(v.at(0), '.'));
		}
#endif

		// TODO reverse lexicographically sort

		ip_print(ip_sort(ip_pool));

		// 222.173.235.246
		// 222.130.177.64
		// 222.82.198.61
		// ...
		// 1.70.44.170
		// 1.29.168.152
		// 1.1.234.8

		// TODO filter by first byte and output
		// ip = filter(1)

		std::cout << std::endl << "filter by first byte 1" << std::endl << std::endl;
		ip_print(ip_sort(filter(ip_pool, 1)));

		// 1.231.69.33
		// 1.87.203.225
		// 1.70.44.170
		// 1.29.168.152
		// 1.1.234.8

		// TODO filter by first and second bytes and output
		// ip = filter(46, 70)
		std::cout << std::endl << "filter by first and second bytes 46, 70" << std::endl << std::endl;
		ip_print(ip_sort(filter(ip_pool, 46, 70)));

		// 46.70.225.39
		// 46.70.147.26
		// 46.70.113.73
		// 46.70.29.76

		// TODO filter by any byte and output
		// ip = filter_any(46)

		std::cout << std::endl << "filter by any byte 46" << std::endl << std::endl;
		ip_print(ip_sort(filter_any(ip_pool, 46)));

		// 186.204.34.46
		// 186.46.222.194
		// 185.46.87.231
		// 185.46.86.132
		// 185.46.86.131
		// 185.46.86.131
		// 185.46.86.22
		// 185.46.85.204
		// 185.46.85.78
		// 68.46.218.208
		// 46.251.197.23
		// 46.223.254.56
		// 46.223.254.56
		// 46.182.19.219
		// 46.161.63.66
		// 46.161.61.51
		// 46.161.60.92
		// 46.161.60.35
		// 46.161.58.202
		// 46.161.56.241
		// 46.161.56.203
		// 46.161.56.174
		// 46.161.56.106
		// 46.161.56.106
		// 46.101.163.119
		// 46.101.127.145
		// 46.70.225.39
		// 46.70.147.26
		// 46.70.113.73
		// 46.70.29.76
		// 46.55.46.98
		// 46.49.43.85
		// 39.46.86.85
		// 5.189.203.46
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
#ifdef _WIN32
	std::cin.get();
#endif // _WIN32

	return 0;
}
