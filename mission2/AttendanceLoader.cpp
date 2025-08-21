#include <fstream>
#include "AttendanceLoader.h"
#include "Week.h"
#include <stdexcept>

using std::ifstream;
using std::make_pair;

vector<Player> AttendanceLoader::parse(const vector<string>& lines) {
	const vector<pair<string, string>> raw_player_attendance_data = loadData(lines);
	return parseData(raw_player_attendance_data);
}

vector<pair<string, string>> AttendanceLoader::loadData(const vector<string>& lines) {
	vector<pair<string, string>> player_attendance_data;
	for (const auto& line : lines) {
		auto pos = line.find(" ");
		string name = line.substr(0, pos);
		string day_name = line.substr(pos+1);
		player_attendance_data.push_back(make_pair(name, day_name));
	}
	return player_attendance_data;
}
vector<Player> AttendanceLoader::parseData(const vector<pair<string, string>>& raw_player_attendance_data) {
	const map<string, int> player_id_map = createPlayerIdMap(raw_player_attendance_data);
	const vector<pair<int, int>> int_raw_data = translateStringToIntData(raw_player_attendance_data, player_id_map);
	const vector<string> names = playerNames(player_id_map);
	const int player_count = static_cast<int> (names.size());
	const vector<vector<int>> gathered_attendance_data = gatherAttendanceData(int_raw_data, player_count);
	return makePlayerData(gathered_attendance_data, names);
}


map<string, int> AttendanceLoader::createPlayerIdMap(const vector<pair<string, string>>& raw_data)
{
	map<string, int> player_id_map;
	int id_cnt = 0;
	for (const auto& item : raw_data)
	{
		const string& player = item.first;
		if (player_id_map.count(player) == 0) {
			player_id_map.insert({ player, id_cnt++ });
		}
	}
	return player_id_map;
}

vector<pair<int, int>> AttendanceLoader::translateStringToIntData(const vector < pair<string, string>>& raw_data, const map<string, int>& player_id_map)
{
	vector<pair<int, int>> parsed_data;
	for (const auto& item : raw_data)
	{
		const string& player = item.first;
		const string& day_name = item.second;
		const int player_id = player_id_map.at(player);
		const int day_index = getDayIndex(day_name);
		parsed_data.push_back(make_pair(player_id, day_index));
	}
	return parsed_data;
}
vector<string> AttendanceLoader::playerNames(const map<string, int>& player_id_map)
{
	vector<string> names(player_id_map.size());
	for (const auto& item : player_id_map)
	{
		const string& player = item.first;
		const int id = item.second;
		names[id] = player;
	}
	return names;
}
vector<vector<int>> AttendanceLoader::gatherAttendanceData(const vector<pair<int, int>>& id_data, int size)
{
	vector<vector<int>> user_attendance_data(size);
	for (const auto& item : id_data)
	{
		const int player_id = item.first;
		const int day_index = item.second;
		user_attendance_data[player_id].push_back(day_index);
	}
	return user_attendance_data;
}
vector<int> AttendanceLoader::makeAttendanceInfo(const vector<int>& attendance_data)
{
	vector<int> attendance_counts(WEEK_DAYS);
	for (const int day_index : attendance_data) {
		attendance_counts[day_index]++;
	}
	return attendance_counts;
}
vector<Player> AttendanceLoader::makePlayerData(const vector<vector<int>>& user_attendance_data, const vector<string>& names)
{
	vector<Player> players;
	for (int player_id = 0; player_id < user_attendance_data.size(); player_id++)
	{
		const auto& attendance_data = user_attendance_data[player_id];
		const vector<int> attendance_counts = makeAttendanceInfo(attendance_data);
		players.push_back({ player_id, names[player_id], attendance_counts });
	}
	return players;
}