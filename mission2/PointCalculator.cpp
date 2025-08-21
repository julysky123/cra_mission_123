#include "PointCalculator.h"

map<int, int> PointCalculator::run(const vector<Player>& players) {
	map<int, int> points;
	for (const auto& player : players)
	{
		points[player.id] = calculatePoint(player.attendance_counts);
	}
	return points;
}


bool PointCalculator::isTrainingDay(int day_index) {
	return day_index == training_day;
}

int PointCalculator::getPoint(const int day_index)
{
	static constexpr int NORMAL_DAY_POINT = 1;
	static constexpr int TRAINING_DAY_POINT = 3;
	static constexpr int WEEKEND_POINT = 2;
	if (isTrainingDay(day_index)) return TRAINING_DAY_POINT;
	else if (isWeekend(day_index)) return WEEKEND_POINT;
	return NORMAL_DAY_POINT;
}
int PointCalculator::calculateDayAttendancePoint(const int attendance_count, const int day_index)
{
	int point = getPoint(day_index);
	return attendance_count * point;
}
int PointCalculator::calculateAttendancePoint(const std::vector<int>& attendance_counts) {
	int point = 0;
	for (int day_index = 0; day_index < WEEK_DAYS; day_index++)
	{
		int attendance_count = attendance_counts[day_index];
		point += calculateDayAttendancePoint(attendance_count, day_index);
	}
	return point;
}
bool PointCalculator::isTrainingDayBonus(const vector<int>& attendance_counts)
{
	static constexpr int BONUS_BASELINE = 10;
	return attendance_counts[training_day] >= BONUS_BASELINE;
}
bool PointCalculator::isWeekendBonus(const vector<int>& attendance_counts) {
	static constexpr int BONUS_BASELINE = 10;
	int count = 0;
	vector<Week> weekend = getWeekend();
	for (Week day : weekend) {
		count += attendance_counts[day];
	}
	return count >= BONUS_BASELINE;
}
int PointCalculator::calculatePoint(const std::vector<int>& attendance_counts)
{
	static constexpr int TRAINING_DAY_BONUS = 10;
	static constexpr int WEEKEND_BONUS = 10;

	int point = calculateAttendancePoint(attendance_counts);
	if (isTrainingDayBonus(attendance_counts)) point += TRAINING_DAY_BONUS;
	if (isWeekendBonus(attendance_counts)) point += WEEKEND_BONUS;
	return point;
}
