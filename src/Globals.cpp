#include "../include/Globals.h"


namespace Globals {

	string dirToStr(const Direction& dir)
	{
		string result = "";

		switch (dir) {
		case Direction::NORTH:
			result = "north";
			break;
		case Direction::EAST:
			result = "east";
			break;
		case Direction::SOUTH:
			result = "south";
			break;
		case Direction::WEST:
			result = "west";
			break;
		default:
			break;
		}

		return result;
	}

	Direction* strToDir(const string& str)
	{
		Direction* result = nullptr;

		if (str.compare("north") == 0)
			result = new Direction(Direction::NORTH);
		else if (str.compare("east") == 0)
			result = new Direction(Direction::EAST);
		else if (str.compare("south") == 0)
			result = new Direction(Direction::SOUTH);
		else if (str.compare("west") == 0)
			result = new Direction(Direction::WEST);

		return result;
	}

	bool isDir(const string& str)
	{
		return strToDir(str) != nullptr;
	}

	vector<string> split(string& str) {
		vector<string> words;
		size_t pos = 0;
		string word;

		if (!str.empty()) {
			while ((pos = str.find(" ")) != string::npos) {
				word = str.substr(0, pos);
				words.push_back(word);
				str.erase(0, pos + 1);
			}

			if (!str.empty())
				words.push_back(str);
		}

		return words;
	}
}
