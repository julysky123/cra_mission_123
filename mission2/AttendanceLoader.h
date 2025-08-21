#pragma once
#include <string>
#include <vector>
#include <map>
#include "player.h"
using std::string;
using std::vector;
using std::map;
using std::pair;

class AttendanceLoader{
public:
	vector<Player> parse(const vector<string>& lines);
private:
	vector<pair<string, string>> loadData(const vector<string>& lines);
	vector<Player> parseData(const vector<pair<string, string>>& raw_player_attendance_data);
	map<string, int> createPlayerIdMap(const vector<pair<string, string>>& raw_data);
	vector<pair<int, int>> translateStringToIntData(const vector < pair<string, string>>& raw_data, const map<string, int>& player_id_map);
	vector<string> playerNames(const map<string, int>& player_id_map);
	vector<vector<int>> gatherAttendanceData(const vector<pair<int, int>>& id_data, int size);
	vector<int> makeAttendanceInfo(const vector<int>& attendance_data);
	vector<Player> makePlayerData(const vector<vector<int>>& user_attendance_data, const vector<string>& names);
};