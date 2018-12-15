#ifndef ADVENT2016_DAY3_H
#define ADVENT2016_DAY3_H

#pragma once

#include <iostream>
#include <vector>

namespace Day3
{
	namespace Part1 {
		void parseInput(std::ifstream &input);
	}
	namespace Part2 {
		void parseInput(std::ifstream &input);
	}

	void run();

	bool validTriangle(std::vector<int> const triangle);
}
#endif //ADVENT2016_DAY3_H
