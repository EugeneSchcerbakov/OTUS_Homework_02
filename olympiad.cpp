#include "olympiad.h"

std::string IsPossiblyToSolve(int firstHourTasksNum)
{
	const int totalTimeHours = 5;
	const int totalTasksNum = 12;

	int x = (totalTimeHours - 1) * 60 / 45;

	bool isPossible = firstHourTasksNum + x >= totalTasksNum;

	std::string result = isPossible ? "YES" : "NO";

	return result;
}

bool TestIsPossibleToSolve()
{
	bool isPassed = true;

	isPassed = isPassed && IsPossiblyToSolve(7) == "YES";
	isPassed = isPassed && IsPossiblyToSolve(5) == "NO";

	return isPassed;
}
