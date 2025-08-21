#pragma once
#include <vector>
#include <map>
#include <memory>
#include "player.h"
#include "IGradePolicy.h"
using std::vector;
using std::map;
using std::shared_ptr;

class GradeCalculator {
public:
	GradeCalculator(shared_ptr<IGradePolicy> gradePolicy) : gradePolicy{ gradePolicy } {}
	map<int, int> run(const vector<Player>& players, const map<int, int>& points);

private:
	shared_ptr<IGradePolicy> gradePolicy;
};