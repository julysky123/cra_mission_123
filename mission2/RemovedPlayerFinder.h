#pragma once
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "IGradePolicy.h"
#include "player.h"
#include "Week.h"

using std::vector;
using std::map;
using std::string;
using std::shared_ptr;

class RemovedPlayerFinder {
public:
	RemovedPlayerFinder(shared_ptr<IGradePolicy> gradePolicy, Week training_day) :gradePolicy{ gradePolicy }, training_day{ training_day } {}
	vector<string> run(const vector<Player>& players, const map<int, int>& grades);
private:
	shared_ptr<IGradePolicy> gradePolicy;
	Week training_day;

	bool isLowGrade(const map<int, int>& grades, int player_id);
	bool isAttendanceTrainingDay(const vector<int>& attendance_counts);
	bool isAttendanceWeekend(const vector<int>& attendance_counts);
};