#include "solution.h"

Solution::Solution(string src, string type):m_src(src), m_type(type)
{
}

string Solution::getSource()
{
	return m_src;
}


string Solution::getType()
{
	return m_type;
}

