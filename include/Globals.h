#ifndef __Globals__
#define __Globals__

#include <iostream>
#include <string>

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
	string dirToStr(const Direction& dir);
	Direction* strToDir(const string& str);

	bool isDir(const string& str);
};

#endif //__Globals__
