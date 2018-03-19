#ifndef SULFIDE_MASS_H
#define SULFIDE_MASS_H

#include <string>
#include <tuple>

struct PanelsBuildingData
{
	int count;
	int width;
	int height;

	PanelsBuildingData(int n, int w, int h)
		: count(n), width(w), height(h)
	{
	}
};

PanelsBuildingData ParsePanelsData(const std::string & input);

int CalcSulfideMass(const PanelsBuildingData & data);

bool CalcSulfideMassTest();

#endif
