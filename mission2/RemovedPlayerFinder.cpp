#include "RemovedPlayerFinder.h"
#include "Week.h"

bool RemovedPlayerFinder::isLowGrade(const map<int, int>& grades, int player_id) {
	return gradePolicy->isLowGrade(grades.at(player_id));
}
bool RemovedPlayerFinder::isAttendanceTrainingDay(const vector<int>& attendance_counts)
{
	return attendance_counts[training_day] != 0;
}
bool RemovedPlayerFinder::isAttendanceWeekend(const vector<int>& attendance_counts)
{
	vector<Week> weekend = getWeekend();
	for (Week day : weekend) {
		if (attendance_counts[day] != 0) return true;
	}
	return false;
}
vector<string> RemovedPlayerFinder::run(const vector<Player>& players, const map<int, int>& grades)
{
	vector<string> removed_players;
	for (const auto& player : players)
	{
		if (isLowGrade(grades, player.id) == false) continue;
		if (isAttendanceTrainingDay(player.attendance_counts) == true) continue;
		if (isAttendanceWeekend(player.attendance_counts) == true) continue;
		removed_players.push_back(player.name);
	}
	return removed_players;
}