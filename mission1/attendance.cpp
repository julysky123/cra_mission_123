#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
using namespace std;

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
constexpr Week TRAINING_DAY = wednesday;
int getDayIndex(const string& day_name)
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

enum Grade
{
	normal = 0,
	silver,
	gold
};
string getGradeName(const int grade)
{
	static constexpr int GRADE_COUNT = 3;
	static const string GRADE_NAME[GRADE_COUNT] = { "NORMAL", "SILVER", "GOLD" };
	if (grade < 0 || grade >= GRADE_COUNT) {
		throw std::runtime_error("grade가 잘못되었습니다.");
	}
	return GRADE_NAME[grade];
}

struct Player
{
	int id;
	string name;
	vector<int> attendance_counts;
};

vector<pair<string, string>> readData(const string& file_name) {
	ifstream fin{ file_name };
	if (fin.is_open() == false) {
		throw std::runtime_error("파일을 열 수 없습니다.");
	}

	vector<pair<string, string>> player_attendance_data;
	for (int line = 0; line < 500; line++) {
		string name, day_name;
		fin >> name >> day_name;
		player_attendance_data.push_back(make_pair(name, day_name));
	}
	return player_attendance_data;
}

map<string, int> createPlayerIdMap(const vector<pair<string, string>>& raw_data)
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

vector<pair<int, int>> translateStringToIntData(const vector < pair<string, string>>& raw_data, const map<string, int>& player_id_map)
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
vector<string> playerNames(const map<string, int>& player_id_map)
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
vector<vector<int>> gatherAttendanceData(const vector<pair<int, int>>& id_data, int size)
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
vector<int> makeAttendanceInfo(const vector<int>& attendance_data)
{
	vector<int> attendance_counts(WEEK_DAYS);
	for (const int day_index : attendance_data) {
		attendance_counts[day_index]++;
	}
	return attendance_counts;
}
vector<Player> makePlayerData(const vector<vector<int>>& user_attendance_data, const vector<string>& names)
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
vector<Player> parseData(const vector<pair<string, string>>& raw_data)
{
	const map<string, int> player_id_map = createPlayerIdMap(raw_data);
	const vector<pair<int, int>> int_raw_data = translateStringToIntData(raw_data, player_id_map);
	const vector<string> names = playerNames(player_id_map);
	const int player_count = static_cast<int> (names.size());
	const vector<vector<int>> gathered_attendance_data = gatherAttendanceData(int_raw_data, player_count);
	return makePlayerData(gathered_attendance_data, names);
}

bool isTrainingDay(int day_index) {
	return day_index == TRAINING_DAY;
}
bool isWeekend(int day_index)
{
	return day_index == saturday || day_index == sunday;
}
int getPoint(const int day_index)
{
	static constexpr int NORMAL_DAY_POINT = 1;
	static constexpr int TRAINING_DAY_POINT = 3;
	static constexpr int WEEKEND_POINT = 2;
	if (day_index < 0 || day_index >= WEEK_DAYS) {
		throw std::runtime_error("요일 인덱스가 잘못되었습니다.");
	}
	if (isTrainingDay(day_index)) {
		return TRAINING_DAY_POINT;
	}
	else if (isWeekend(day_index)) {
		return WEEKEND_POINT;
	}
	else {
		return NORMAL_DAY_POINT;
	}
}
int calculateDayAttendancePoint(const int attendance_count, const int day_index)
{
	int point = getPoint(day_index);
	return attendance_count * point;
}
int calculateAttendancePoint(const std::vector<int>& attendance_counts) {
	int point = 0;
	for (int day_index = 0; day_index < WEEK_DAYS; day_index++)
	{
		int attendance_count = attendance_counts[day_index];
		point += calculateDayAttendancePoint(attendance_count, day_index);
	}
	return point;
}
bool isTrainingDayBonus(const vector<int>& attendance_counts)
{
	static constexpr int BONUS_BASELINE = 10;
	return attendance_counts[TRAINING_DAY] >= BONUS_BASELINE;
}
bool isWeekendBonus(const vector<int>& attendance_counts) {
	static constexpr int BONUS_BASELINE = 10;
	return attendance_counts[saturday] + attendance_counts[sunday] >= BONUS_BASELINE;
}
int calculatePoint(const std::vector<int>& attendance_counts)
{
	static constexpr int TRAINING_DAY_BONUS = 10;
	static constexpr int WEEKEND_BONUS = 10;

	int point = calculateAttendancePoint(attendance_counts);
	if (isTrainingDayBonus(attendance_counts)) point += TRAINING_DAY_BONUS;
	if (isWeekendBonus(attendance_counts)) point += WEEKEND_BONUS;
	return point;
}

map<int, int> calculaterPlayerPoint(const vector<Player>& players)
{
	map<int, int> points;
	for (const auto& player : players)
	{
		points[player.id] = calculatePoint(player.attendance_counts);
	}
	return points;
}
int calculateGrade(const int point)
{
	static constexpr int GOLD_POINT = 50;
	static constexpr int SILVER_POINT = 30;

	if (point >= GOLD_POINT) {
		return gold;
	}
	else if (point >= SILVER_POINT) {
		return silver;
	}
	else {
		return normal;
	}
}

bool isNormalGrade(const map<int, int>& grades, int player_id) {
	return grades.at(player_id) == normal;
}
bool isAttendanceTrainingDay(const vector<int>& attendance_counts)
{
	return attendance_counts[TRAINING_DAY] != 0;
}
bool isAttendanceWeekend(const vector<int>& attendance_counts)
{
	return attendance_counts[saturday] != 0 || attendance_counts[sunday] != 0;
}
vector<string> filterRemovedPlayer(const vector<Player>& players, const map<int, int>& grades)
{
	vector<string> removed_players;
	for (const auto& player : players)
	{
		if (isNormalGrade(grades, player.id) == false) continue;
		if (isAttendanceTrainingDay(player.attendance_counts) == true) continue;
		if (isAttendanceWeekend(player.attendance_counts) == true) continue;
		removed_players.push_back(player.name);
	}
	return removed_players;
}

map<int, int> calculatePlayerGrade(const vector<Player>& players, const map<int, int>& points)
{
	map<int, int> grades;
	for (const auto& player : players)
	{
		int point = points.at(player.id);
		int grade = calculateGrade(point);
		grades[player.id] = grade;
	}
	return grades;
}

void printPlayerReport(const vector<Player>& players, const map<int, int>& points, const map<int, int>& grades)
{
	for (const auto& player : players)
	{
		int point = points.at(player.id);
		const string& grade = getGradeName(grades.at(player.id));
		cout << "NAME : " << player.name << ", ";
		cout << "POINT : " << point << ", ";
		cout << "GRADE : " << grade << "\n";
	}
}

void printRemovedPlayers(const vector<string>& removed_players) {

	std::cout << "\n";
	std::cout << "Removed player\n";
	std::cout << "==============\n";

	for (const auto& removed_player : removed_players)
	{
		std::cout << removed_player << "\n";
	}
}

void run() {
	try {
		const string& file_name = "attendance_weekday_500.txt";
		const vector<pair<string, string>> raw_player_attendance_data = readData(file_name);
		const vector<Player> players = parseData(raw_player_attendance_data);

		const map<int, int> points = calculaterPlayerPoint(players);
		const map<int, int> grades = calculatePlayerGrade(players, points);
		const vector<string> removed_players = filterRemovedPlayer(players, grades);

		printPlayerReport(players, points, grades);
		printRemovedPlayers(removed_players);
	}
	catch (const std::runtime_error& error) {
		std::cerr << "예외 발생: " << error.what() << std::endl;
	}
}

int main() {
	run();
}
