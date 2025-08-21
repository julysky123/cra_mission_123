#pragma once
#include <vector>
#include <map>
#include <string>
#include "Player.h"

using std::vector;
using std::map;
using std::string;

struct IReporter {
	virtual void printPlayerReport(const vector<Player>& players, const map<int, int>& points, const map<int, int>& grades) = 0;
	virtual void printRemovedPlayers(const vector<string>& removed_players) = 0;
};