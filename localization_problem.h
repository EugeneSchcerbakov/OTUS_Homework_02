#ifndef LOCALIZATION_PROBLEM_H
#define LOCALIZATION_PROBLEM_H

#include <string>
#include <vector>

class NumberLocalizationState
{
public:
	struct Entry
	{
		const int lower;
		const int upper;
		const std::string word;

		Entry(int _lower, int _upper, const std::string& _word);
	};

public:
	NumberLocalizationState();

	void RegisterEntry(int lower, int upper, const std::string& world);

	const std::vector<NumberLocalizationState::Entry>& GetEntries() const;

private:
	std::vector<Entry> entries;
};

std::string LocalizeNumber(int number);
bool LocalizeNumberTest();

#endif
