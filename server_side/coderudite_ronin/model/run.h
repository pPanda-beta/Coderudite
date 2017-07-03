#ifndef RUN_H
#define RUN_H

#include <QFile>
#include <QProcess>
#include <map>
#include <functional>
#include "runresult.h"
#include "helpers.hxx"
#include "constants.hxx"

class Run
{
	int run_id;
	Solution m_src;
	QProcess m_handle;
	RunResult result;

	string workingDir;
public:
	Run(Solution src);
	RunResult execute(string input, int ms);
};

#endif // RUN_H
