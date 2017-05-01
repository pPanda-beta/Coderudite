#include "runresult.h"

RunResult::RunResult():status(STATUS::SUCC)
{
}

RunResult::RunResult(const RunResult& other)
{
	m_src = other.m_src;
	m_inp.str(other.m_inp.str());
	m_oup.str(other.m_oup.str());
	m_err.str(other.m_err.str());
	status = other.status;
	exec_time = other.exec_time;
}

string RunResult::toString()
{
	if(status == STATUS::SUCC)
		return m_oup.str();
	return m_err.str();
}
