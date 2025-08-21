#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include "Attendance.h"

using std::vector;
using std::map;
using std::pair;
using std::make_pair;
using std::string;
using std::ifstream;
using std::cout;

constexpr Week TRAINING_DAY = wednesday;

void Attendance::run() {
	const vector<string> lines = file_reader->read(file_name);
	const vector<Player> players = attendance_loader->parse(lines);

	const map<int, int> points = point_calculator->run(players);

	const map<int, int> grades = grade_calculator->run(players, points);

	const vector<string> removed_players = removed_player_finder->run(players, grades); //removed player 정책

	reporter->printPlayerReport(players, points, grades);
	reporter->printRemovedPlayers(removed_players);
}