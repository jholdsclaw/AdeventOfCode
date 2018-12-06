#include <cmath>
#include <iostream>
#include <cassert>
#include <sstream>
#include "Day1.h"

namespace Day1 {
	void run() {

		Day1::Avatar myAvatarTest1;

		//Test Case 1 = Result should be 5
		myAvatarTest1.turn(Day1::RIGHT, 2);
		myAvatarTest1.turn(Day1::LEFT, 3);
		std::cout << "Test 1: (R2, L3) = Distance Travelled: " << myAvatarTest1.getDistanceTravelled() << std::endl;
		assert(myAvatarTest1.getDistanceTravelled() == 5);

		Day1::Avatar myAvatarTest2;

		//Test Case 2 = Result should be 2
		myAvatarTest2.turn(Day1::RIGHT, 2);
		myAvatarTest2.turn(Day1::RIGHT, 2);
		myAvatarTest2.turn(Day1::RIGHT, 2);
		std::cout << "Test 2: (R2, R2, R2) = Distance Travelled: " << myAvatarTest2.getDistanceTravelled() << std::endl;
		assert(myAvatarTest2.getDistanceTravelled() == 2);

		Day1::Avatar myAvatarTest3;

		//Test Case 3 = Result should be 12
		myAvatarTest3.turn(Day1::RIGHT, 5);
		myAvatarTest3.turn(Day1::LEFT, 5);
		myAvatarTest3.turn(Day1::RIGHT, 5);
		myAvatarTest3.turn(Day1::RIGHT, 3);
		std::cout << "Test 3: (R5, L5, R5, L3) = Distance Travelled: " << myAvatarTest3.getDistanceTravelled()
			<< std::endl;
		assert(myAvatarTest3.getDistanceTravelled() == 12);

		Day1::Avatar myAvatarTest4;

		//Test Case 4 (Pt 2) = Result should be 4
		myAvatarTest4.turn(Day1::RIGHT, 8);
		myAvatarTest4.turn(Day1::RIGHT, 4);
		myAvatarTest4.turn(Day1::RIGHT, 4);
		myAvatarTest4.turn(Day1::RIGHT, 8);
		std::cout << "Test 4: (R8, R4, R4, R4) = First Visit Travelled: " << myAvatarTest4.getFirstVisitedDistance()
			<< std::endl;
		assert(myAvatarTest4.getFirstVisitedDistance() == 4);

		// Part 1 - Result unknown?
		Day1::Avatar myAvatar;
		const std::string input = "R1, L4, L5, L5, R2, R2, L1, L1, R2, L3, R4, R3, R2, L4, L2, R5, L1, R5, L5, L2, L3, L1, R1, R4, R5, L3, R2, L4, L5, R1, R2, L3, R3, L3, L1, L2, R5, R4, R5, L5, R1, L190, L3, L3, R3, R4, R47, L3, R5, R79, R5, R3, R1, L4, L3, L2, R194, L2, R1, L2, L2, R4, L5, L5, R1, R1, L1, L3, L2, R5, L3, L3, R4, R1, R5, L4, R3, R1, L1, L2, R4, R1, L2, R4, R4, L5, R3, L5, L3, R1, R1, L3, L1, L1, L3, L4, L1, L2, R1, L5, L3, R2, L5, L3, R5, R3, L4, L2, R2, R4, R4, L4, R5, L1, L3, R3, R4, R4, L5, R4, R2, L3, R4, R2, R1, R2, L4, L2, R2, L5, L5, L3, R5, L5, L1, R4, L1, R1, L1, R4, L5, L3, R4, R1, L3, R4, R1, L3, L1, R1, R2, L4, L2, R1, L5, L4, L5";
		parseInput(input, &myAvatar);
		std::cout << "Part 1 result = Distance Travelled: " << myAvatar.getDistanceTravelled() << std::endl;
		std::cout << "Part 2 result = Distance Travelled: " << myAvatar.getFirstVisitedDistance() << std::endl;

		return;
	}

	Avatar::Avatar() noexcept {
		// Per spec, avatar will always start facing North
		currentDirection = 0;

		// And of course we haven't moved yet
		distanceTravelled[0] = 0;
		distanceTravelled[1] = 0;

		firstVisited = 0;
	}

	void Avatar::turn(int direction, int blocks) {
		// variable to determine movement axis and movement direction
		int movementAxis = 0;
		int normalizedVector = 0;
		std::string key;

		// Start by turning the avatar
		currentDirection += direction;

		// Figure out if we're moving along the first or second axis
		movementAxis = std::abs((int)sin(deg2rad((double)currentDirection)));

		// We can deduce normalized movement vector using sin or cos depending on which way we're facing
		// Since this is a fairly controlled scenario, we can simply swap sin for cos if either is 0
		normalizedVector = (int)(movementAxis ? sin(deg2rad((double)currentDirection)) : cos(
			deg2rad((double)currentDirection)));


		for (int i = 1; i <= blocks; i++) {
			distanceTravelled[movementAxis] += normalizedVector;

			// build our key for the hash
			key = std::to_string(distanceTravelled[0]) + "," + std::to_string(distanceTravelled[1]);

			// check if we've been here before
			if ((visited.find(key) != visited.end()) && (firstVisited == 0))
				firstVisited = getDistanceTravelled();

			// add current position to our hash
			visited[key] = true;
		}
	}

	int Avatar::getDistanceTravelled() {
		// Return net sum of distance travelled across both axis
		return std::abs(distanceTravelled[0]) + std::abs(distanceTravelled[1]);
	}

	int Avatar::getFirstVisitedDistance() {
		// Return net sum of distance travelled across both axis
		return firstVisited;
	}

	void parseInput(std::string const &input, Avatar *avt) {
		// create a string stream to parse through our input
		std::stringstream ss(input);

		// go through and split out elements by comma
		while (ss.good()) {
			std::string substr;
			std::getline(ss, substr, ',');

			// definitely not robust for random input, but just chomping off leading ' ' (space) from sample input data
			if (substr[0] == ' ') substr.erase(0, 1);

			// Now turn based on input
			switch (substr[0]) {
			case 'R':
				avt->turn(RIGHT, atoi(substr.substr(1).c_str()));
				break;
			case 'L':
				avt->turn(LEFT, atoi(substr.substr(1).c_str()));
				break;
			}
		}
	}
}
