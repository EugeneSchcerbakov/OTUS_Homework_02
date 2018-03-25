#include "utils.h"

#include <stdlib.h>

std::vector<long long> ExtractInt64FromString(const std::string & input)
{
	std::vector<long long> numbers;

	const char* tokens = "0123456789";

	std::size_t beg = input.find_first_of(tokens);
	std::size_t end = input.find_first_not_of(tokens, beg);

	while (beg != std::string::npos)
	{
		if (end == std::string::npos) {
			end = input.size();
		}

		std::string num = input.substr(beg, beg - end);
		// COMP FAILED at g++: error: stoll is not a member of std
		// numbers.push_back(std::stoll(num));
		numbers.push_back(strtoll(num.c_str(), nullptr, 0));

		beg = input.find_first_of(tokens, end + 1);
		end = input.find_first_not_of(tokens, beg);
	}

	return numbers;
}
