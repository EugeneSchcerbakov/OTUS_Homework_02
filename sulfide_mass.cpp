#include "sulfide_mass.h"

#include "utils.h"

PanelsBuildingData ParsePanelsData(const std::string & input)
{
	auto panelsData = ExtractInt64FromString(input);
	return PanelsBuildingData((int)panelsData[0], (int)panelsData[1], (int)panelsData[2]);
}

int CalcSulfideMass(const PanelsBuildingData & data)
{
	const int sulfideMassPerSquareMeter = 1;

	int onePanelSulfideMass = data.width * data.height * sulfideMassPerSquareMeter;
	int totalSulfideMass = onePanelSulfideMass * data.count;
	int twosidedSulfideMass = totalSulfideMass * 2;

	return twosidedSulfideMass;
}

bool CalcSulfideMassTest()
{
	const std::string input("5 2 3");
	const int output = 60;

	int result = CalcSulfideMass(ParsePanelsData(input));

	bool isPassed = output == result;

	return isPassed;
}
