#pragma once
#include <vector>
#include <string>
#include <stdexcept>
using std::string;
using std::vector;

constexpr int WEEK_DAYS = 7;
enum Week
{
	monday = 0,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
	sunday
};

static int getDayIndex(const string& day_name)
{
	if (day_name == "monday") {
		return monday;
	}
	if (day_name == "tuesday") {
		return tuesday;
	}
	if (day_name == "wednesday") {
		return wednesday;
	}
	if (day_name == "thursday") {
		return thursday;
	}
	if (day_name == "friday") {
		return friday;
	}
	if (day_name == "saturday") {
		return saturday;
	}
	if (day_name == "sunday") {
		return sunday;
	}
	throw std::runtime_error("요일이 잘못되었습니다.");
}

static bool isWeekend(int day_index)
{
	return day_index == saturday || day_index == sunday;
}

static vector<Week> getWeekend() {
	static const vector<Week> weekend = { saturday, sunday };
	return weekend;
}