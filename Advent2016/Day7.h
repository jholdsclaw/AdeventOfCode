#ifndef ADVENT2016_DAY7_H
#define ADVENT2016_DAY7_H

#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace Day7
{
	bool supportTLS(const std::string *input);
	bool isAbba(const std::string input);

	bool supportSSL(const std::string *input);
	bool isAba(const std::string input);
	bool isBab(const std::string input, const std::string aba);

	int parseInput(std::ifstream &input);

	void run();
}
#endif //ADVENT2016_DAY7_H
