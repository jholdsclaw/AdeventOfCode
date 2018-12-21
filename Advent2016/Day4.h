#ifndef ADVENT2016_DAY4_H
#define ADVENT2016_DAY4_H

#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Day4
{
	namespace Part1 {
		void parseInput(std::ifstream &input);
	}
	namespace Part2 {
		void parseInput(std::ifstream &input);
	}

	struct EncryptedRoom {
		std::string Name;
		int SectorID;
		std::string Checksum;
	};

	void run();

	bool validRoom(std::string const * input);

}
#endif //ADVENT2016_DAY4_H
