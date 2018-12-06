#ifndef ADVENT2016_DAY1_H
#define ADVENT2016_DAY1_H

#pragma once

#include <cmath>
#include <iostream>
#include <map>

// Credit where credit is due, cuz I'm too lazy to worry about converting deg->rad, but too anal to not do it accurately!
// http://www.cplusplus.com/forum/beginner/42245/#msg228264
#ifndef M_PI
#define M_PI (4.0 * std::atan2(1.0, 1.0))
#endif

template <typename N> inline
N deg2rad(N d)
{
	return M_PI * d / 180.0;
}

template <typename N> inline
N rad2deg(N r)
{
	return 180.0 * r / M_PI;
}
namespace Day1
{
	void run();

	static const int LEFT = -90;
	static const int RIGHT = 90;

	class Avatar {

	public:
		void turn(int direction, int blocks);
		int getDistanceTravelled();
		int getFirstVisitedDistance();

		Avatar() noexcept;

	private:
		int currentDirection;
		int distanceTravelled[2];

		// tried to come up with a more primitive way without using STL,
		// but at the end of the day use the tools that make life easier
		std::map<std::string, bool> visited;

		int firstVisited;
	};

	void parseInput(std::string const& input, Avatar *avt);
}



#endif //ADVENT2016_DAY1_H
