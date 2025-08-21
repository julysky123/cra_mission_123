#pragma once
#include "gmock/gmock.h"
#include "IReporter.h"

class ReporterMock : public IReporter {
public:
	MOCK_METHOD(void, printPlayerReport, (const vector<Player>&, (const map<int, int>&), (const map<int, int>&)), (override));
	MOCK_METHOD(void, printRemovedPlayers, (const vector<string>&), (override));
};