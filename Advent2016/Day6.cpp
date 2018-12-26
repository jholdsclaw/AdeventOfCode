#include "Day6.h"

#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

namespace Day6 {
	void run() {
		std::cout << "Day 6:\n" << std::endl;

		// Test Case 1
		std::string test_input = "eedadn\ndrvtee\neandsr\nraavrd\natevrs\ntsrnev\nsdttsa\nrasrtv\nnssdts\nntnada\nsvetve\ntesnvt\nvntsnd\nvrdear\ndvrsen\nenarar";
		std::array<charmap, 6> test_charmap;
		parseInput(&test_input, &test_charmap);
		
		std::string result1 = decode(&test_charmap);

		std::cout << "Test Case 1:\n" << test_input << "\n\nresult = easter" << std::endl;
		std::cout << "Result: " << result1 << " (" << ((result1 == "easter") ? "Pass" : "Fail") << ")\n" << std::endl;

		// Part 1 
		std::ifstream part1("./Day6.txt");
		std::array<charmap, 8> charmap1;

		parseInput(part1, &charmap1);
		std::cout << "Part 1 - result = ???" << std::endl;
		std::cout << "Result: " << decode(&charmap1) << "\n" << std::endl;

		return;
	}

	template<std::size_t SIZE>
	void parseInput(const std::string *input, std::array<charmap, SIZE> *result) {
		std::stringstream ss(*input);
		std::string line;

		while (std::getline(ss, line)) {
			int i = 0;
			for (char &c : line) {
				(result->at(i).count(c) == 0) ? result->at(i)[c] = 1 : result->at(i)[c]++;

				i++;
			}
		}
	}

	template<std::size_t SIZE>
	void parseInput(std::ifstream &input, std::array<charmap, SIZE> *result) {
		std::string line;

		while (std::getline(input, line)) {
			int i = 0;
			for (char &c : line) {
				(result->at(i).count(c) == 0) ? result->at(i)[c] = 1 : result->at(i)[c]++;

				i++;
			}
		}
	}

	template<std::size_t SIZE>
	std::string decode(const std::array<charmap, SIZE> *charmap) {
		std::stringstream ss;
		
		for (int i = 0; i < charmap->size(); i++) {
			char c;
			int biggest = 0; 

			for (auto const& item : charmap->at(i)) {
				// Spec doesn't exactly say how to handle ties, so just going to keep the first highest found
				if (item.second > biggest) { 
					c = item.first;
					biggest = item.second;
				}
			}

			ss << c;
		}

		return ss.str();
	}
}