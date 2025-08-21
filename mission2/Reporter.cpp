#include "Reporter.h"
#include <iostream>
void Reporter::printPlayerReport(const vector<Player>& players, const map<int, int>& points, const map<int, int>& grades) {
	for (const auto& player : players)
	{
		int point = points.at(player.id);
		const string& grade = gradePolicy->getGradeName(grades.at(player.id));
		std::cout << "NAME : " << player.name << ", ";
		std::cout << "POINT : " << point << ", ";
		std::cout << "GRADE : " << grade << "\n";
	}
}
void Reporter::printRemovedPlayers(const vector<string>& removed_players) {

	std::cout << "\n";
	std::cout << "Removed player\n";
	std::cout << "==============\n";

	for (const auto& removed_player : removed_players)
	{
		std::cout << removed_player << "\n";
	}
}