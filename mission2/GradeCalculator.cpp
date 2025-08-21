#include "GradeCalculator.h"

map<int, int> GradeCalculator::run(const vector<Player>& players, const map<int, int>& points)
{
	map<int, int> grades;
	for (const auto& player : players)
	{
		int point = points.at(player.id);
		int grade = gradePolicy->getGrade(point);
		grades[player.id] = grade;
	}
	return grades;
}