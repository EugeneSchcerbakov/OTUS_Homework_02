#include "localization_problem.h"

#include <assert.h>

NumberLocalizationState::Entry::Entry(int _lower, int _upper, const std::string& _word)
	: lower(_lower), upper(_upper), word(_word)
{
}

NumberLocalizationState::NumberLocalizationState()
{
	RegisterEntry(1, 4, "few");
	RegisterEntry(5, 9, "several");
	RegisterEntry(10, 19, "pack");
	RegisterEntry(20, 49, "lots");
	RegisterEntry(50, 99, "horde");
	RegisterEntry(100, 249, "throng");
	RegisterEntry(250, 499, "swarm");
	RegisterEntry(500, 999, "zounds");
	RegisterEntry(1000, 2000, "legion");
}

void NumberLocalizationState::RegisterEntry(int lower, int upper, const std::string& world)
{
	entries.push_back(Entry(lower, upper, world));
}

const std::vector<NumberLocalizationState::Entry>& NumberLocalizationState::GetEntries() const
{
	return entries;
}

std::string LocalizeNumber(int number)
{
	static NumberLocalizationState state;

	for (const auto& entry : state.GetEntries())
	{
		if (number >= entry.lower && number <= entry.upper)
		{
			return entry.word;
		}
	}

	assert(false);
	return std::string();
}

bool LocalizeNumberTest()
{
	bool isPassed = true;

	isPassed = isPassed && LocalizeNumber(2) == "few";
	isPassed = isPassed && LocalizeNumber(7) == "several";
	isPassed = isPassed && LocalizeNumber(10) == "pack";
	isPassed = isPassed && LocalizeNumber(30) == "lots";
	isPassed = isPassed && LocalizeNumber(80) == "horde";
	isPassed = isPassed && LocalizeNumber(150) == "throng";
	isPassed = isPassed && LocalizeNumber(300) == "swarm";
	isPassed = isPassed && LocalizeNumber(700) == "zounds";
	isPassed = isPassed && LocalizeNumber(1024) == "legion";

	return false;
}
