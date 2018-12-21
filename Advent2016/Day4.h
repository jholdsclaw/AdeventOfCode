#ifndef ADVENT2016_DAY4_H
#define ADVENT2016_DAY4_H

#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Day4
{
	namespace Part1 {
		unsigned int parseInput(std::ifstream &input);
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

	EncryptedRoom deserializeRoom(std::string const *input);
	bool validRoom(const EncryptedRoom *room);
	std::string decryptRoomName(const EncryptedRoom *room);
}
#endif //ADVENT2016_DAY4_H
