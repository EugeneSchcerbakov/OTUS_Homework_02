#include "ip_filter.h"

#include <iostream>
#include <functional>
#include <fstream>

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

ip_addr str_to_ip(const std::string& str)
{
	auto ip_str = split(str, '.');
	ip_addr ip;

	ip[0] = std::stoi(ip_str[0]);
	ip[1] = std::stoi(ip_str[1]);
	ip[2] = std::stoi(ip_str[2]);
	ip[3] = std::stoi(ip_str[3]);

	return ip;
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
		ip_pool.push_back(str_to_ip(v.at(0)));
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
			if (ip_a[i] == ip_b[i]) {
				continue;
			}
			else {
				return ip_a[i] > ip_b[i];
			}
		}

		return false;
	});

	return ip_filter;
}

void ip_print(const std::vector<ip_addr>& ip_pool)
{
	for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
	{
		for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
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

std::vector<ip_addr> filter_any(const std::vector<ip_addr>& ip_pool, int byte)
{
	std::vector<ip_addr> result(ip_pool);

	auto iter = std::copy_if(ip_pool.cbegin(), ip_pool.cend(), result.begin(), [filter = byte](const ip_addr& ip)
	{
		for (int i = 0; i < ip.size(); i++) {
			if (ip[i] == filter) {
				return true;
			}
		}

		return false;
	});

	result.resize(std::distance(result.begin(), iter));

	return result;
}
