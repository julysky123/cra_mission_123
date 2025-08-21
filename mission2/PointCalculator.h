#pragma once
#include <vector>
#include <map>
#include "Week.h"
#include "player.h"
using std::vector;
using std::map;
class PointCalculator {
public:
	PointCalculator(Week training_day) : training_day{ training_day } {}
	map<int, int> run(const vector<Player>& players);

private:
	Week training_day;
	bool isTrainingDay(int day_index);
	int getPoint(const int day_index);
	int calculateDayAttendancePoint(const int attendance_count, const int day_index);
	int calculateAttendancePoint(const std::vector<int>& attendance_counts);
	bool isTrainingDayBonus(const vector<int>& attendance_counts);
	bool isWeekendBonus(const vector<int>& attendance_counts);
	int calculatePoint(const std::vector<int>& attendance_counts);
};