#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>

#include "Day4.h"

namespace Day4 {
	void run() {
		std::cout << "Day 4:\n" << std::endl;

		// Test Case 1
		std::string Test1 = "aaaaa-bbb-z-y-x-123[abxyz]";
		bool result = validRoom(&Test1);
		std::cout << "Test Case 1 " << Test1 << " - result = true" << std::endl;
		std::cout << "Result: " << result << " (" << ((result == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 2
		std::string Test2 = "a-b-c-d-e-f-g-h-987[abcde]";
		result = validRoom(&Test2);
		std::cout << "Test Case 2 - " << Test2 << " - result = true" << std::endl;
		std::cout << "Result: " << result << " (" << ((result == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 3
		std::string Test3 = "not-a-real-room-404[oarel]";
		result = validRoom(&Test3);
		std::cout << "Test Case 3 - " << Test3 << " - result = true" << std::endl;
		std::cout << "Result: " << result << " (" << ((result == true) ? "Pass" : "Fail") << ")\n" << std::endl;

		// Test Case 4
		std::string Test4 = "totally-real-room-200[decoy]";
		result = validRoom(&Test4);
		std::cout << "Test Case 4 - " << Test4 << " - result = false" << std::endl;
		std::cout << "Result: " << result << " (" << ((result == false) ? "Pass" : "Fail") << ")\n" << std::endl;

	}

	bool validRoom(std::string const *input) {
		EncryptedRoom room;

		// Assumptions: the sector id is always 3 digits,
		// so the substring for the encrypted room name will
		// be length - 10 (3 (sector id) + 5 (checksum) + 2 (brackets))
		const unsigned int SECTOR_ID_LEN = 3;
		const unsigned int CHECKSUM_LEN = 5;
		const unsigned int TAIL_LEN = SECTOR_ID_LEN + CHECKSUM_LEN + 2;
		const unsigned int ENC_ROOM_LEN = input->length() - TAIL_LEN;

		// Grab the encrypted name
		room.Name = input->substr(0, ENC_ROOM_LEN);

		// Grab the sector id 
		room.SectorID = std::stoi(input->substr(ENC_ROOM_LEN, CHECKSUM_LEN));

		// And finally grab the checksum
		room.Checksum = input->substr((input->length() - (CHECKSUM_LEN + 1)), CHECKSUM_LEN);

		// We'll use an ordered map as a quick shortcut so when we sort later on 
		// occurance counts, ties will automatically be sorted alphabetically
		std::map<char, unsigned int> letters;

		// Build our hash map to keep count of occurances of letters
		for (int i = 0; i < room.Name.length(); i++) {
			// ignore the dashes
			if (room.Name[i] != '-')
				(letters.count((room.Name[i])) == 0) ? letters[(room.Name[i])] = 1 : letters[(room.Name[i])]++;
		}

		// Now we'll create a descending ordered map using the count as the key
		std::multimap<unsigned int, char, std::greater<int>> ordered_letters;
		for (const auto& l : letters) {
			ordered_letters.insert(std::pair<unsigned int, char>(l.second, l.first));
		}

		// Assumptions: Every encrypted room name will have at least 5 unique characters
		// And finally build our checksum
		std::stringstream checksum;
		for (const auto& l : ordered_letters) {
			checksum << l.second;
			
			// only want the first 5
			if (checksum.str().length() >= 5) break;
		}

		return (checksum.str() == room.Checksum);
	}

}