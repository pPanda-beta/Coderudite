#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
using namespace std;

class Solution
{
	string m_src,m_type;
public:
	Solution(string src="", string type="txt");
	string getType();
	virtual string getSource();
};

#endif // SOLUTION_H
