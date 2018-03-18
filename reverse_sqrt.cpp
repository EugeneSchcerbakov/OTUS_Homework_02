#include "reverse_sqrt.h"

#include <boost/format.hpp>

#include <sstream>
#include <vector>
#include <cctype>
#include <assert.h>

static std::vector<long long> ExtractInt64FromString(const std::string& input)
{
	std::vector<long long> numbers;

	const char* tokens = "0123456789";

	std::size_t beg = input.find_first_of(tokens);
	std::size_t end = input.find_first_not_of(tokens, beg);

	while (beg != std::string::npos)
	{
		if (end == std::string::npos) {
			end = input.size() - 1;
		}

		std::string num = input.substr(beg, beg - end);
		numbers.push_back(std::stoll(num));

		beg = input.find_first_of(tokens, end + 1);
		end = input.find_first_not_of(tokens, beg);
	}

	return numbers;
}

std::string ReverseSquareRoot(const std::string& input)
{
	const size_t inputSizeBytesMax = 256 * 1000; // 256 kilobytes
	const size_t inputSizeBytes = input.size() * sizeof(std::string::value_type);

	assert(inputSizeBytes < inputSizeBytesMax);

	std::vector<long long> numbers = ExtractInt64FromString(input);
	std::stringstream ss;

	for (auto iter = numbers.crbegin(); iter < numbers.crend(); iter++)
	{
		ss << boost::format("%.4f") % sqrt(*iter);

		if (iter < numbers.crend() - 1) {
			ss << "\n";
		}
	}

	return ss.str();
}

bool ReverseSquareRootTest()
{
	const std::string input("1427  0\n  876652098643267843 \n 5276538");	
	const std::string output("2297.0716\n936297014.1164\n0.0000\n37.7757");
	
	const std::string result = ReverseSquareRoot(input);
	const bool isPassed = result == output;

	return isPassed;
}
