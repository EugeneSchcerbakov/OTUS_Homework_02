#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <vector>
#include <array>
#include <string>
#include <algorithm>

#include <assert.h>

using ip_addr = std::array<unsigned int, 4>;

std::vector<std::string>	split(const std::string &str, char d);
std::vector<ip_addr>		read_ip(const std::string& filename);
std::vector<ip_addr>		ip_sort(const std::vector<ip_addr>& input);
std::vector<ip_addr>		filter_any(const std::vector<ip_addr>& ip_pool, int byte);
ip_addr						str_to_ip(const std::string& str);
void						ip_print(const std::vector<ip_addr>& ip_pool);

template<typename ...Args>
std::vector<ip_addr> filter(const std::vector<ip_addr>& ip_pool, Args ...args)
{
	assert(sizeof...(args) <= 4);

	std::vector<ip_addr> result(ip_pool.size());
	auto filter = std::array<int, sizeof...(args)>{args...};

	auto iter = std::copy_if(ip_pool.cbegin(), ip_pool.cend(), result.begin(), [f = filter](const ip_addr& ip)
	{
		for (int i = 0; i < f.size(); i++) {
			if (ip[i] != f[i]) {
				return false;
			}
		}

		return true;
	});

	result.resize(std::distance(result.begin(), iter));

	return result;
}

#endif // !IP_FILTER_H
