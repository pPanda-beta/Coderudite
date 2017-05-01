#ifndef RUNRESULT_H
#define RUNRESULT_H

#include <iostream>
#include <sstream>
#include <chrono>
#include "solution.h"
using namespace std;

class RunResult
{
public:
	enum STATUS { SUCC, CTE, RTE, TLE, ERR} status;
	stringstream m_inp,m_oup,m_err;
    Solution m_src;
	chrono::duration<double> exec_time;
	RunResult();
	RunResult(const RunResult&);

	string toString();
};

#endif // RUNRESULT_H
