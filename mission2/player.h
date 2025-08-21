#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

struct Player
{
	int id;
	string name;
	vector<int> attendance_counts;
};