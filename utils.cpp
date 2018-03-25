#include "utils.h"

#include <boost\lexical_cast.hpp>

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
		//numbers.push_back(std::stoll(num));
		numbers.push_back(boost::lexical_cast<long long int>(num));

		beg = input.find_first_of(tokens, end + 1);
		end = input.find_first_not_of(tokens, beg);
	}

	return numbers;
}
