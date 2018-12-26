#ifndef ADVENT2016_DAY6_H
#define ADVENT2016_DAY6_H

#pragma once

#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <string>

namespace Day6
{
	typedef std::map<char, int> charmap;

	template<std::size_t SIZE>
	void parseInput(const std::string *input, std::array<charmap, SIZE> *result);

	template<std::size_t SIZE>
	void parseInput(std::ifstream &input, std::array<charmap, SIZE> *result);

	template<std::size_t SIZE>
	std::string decode(const std::array<charmap, SIZE> *charmap);

	void run();
}
#endif //ADVENT2016_DAY6_H
