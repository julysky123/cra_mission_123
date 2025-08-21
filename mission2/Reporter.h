#pragma once
#include <vector>
#include <map>
#include <string>
#include <memory>
#include "IReporter.h"
#include "Player.h"
#include "IGradePolicy.h"

using std::vector;
using std::map;
using std::string;
using std::shared_ptr;
class Reporter : public IReporter{
public:
	Reporter(shared_ptr<IGradePolicy> gradePolicy) : gradePolicy{ gradePolicy } {}
	void printPlayerReport(const vector<Player>& players, const map<int, int>& points, const map<int, int>& grades);
	void printRemovedPlayers(const vector<string>& removed_players);
private:
	shared_ptr<IGradePolicy> gradePolicy;
};