#ifndef __Globals__
#define __Globals__

#include <iostream>
#include <string>
#include <vector>

using namespace std;


enum class Direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};

namespace Globals
{
	vector<string> split(string& str);

	string dirToStr(const Direction& dir);
	Direction* strToDir(const string& str);

	bool isDir(const string& str);
};

#endif //__Globals__
