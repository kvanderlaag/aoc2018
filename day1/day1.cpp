// day1.cpp
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector> // fuck
#include <algorithm>

int part1()
{
	// Open input stream
	std::ifstream inFile("input.txt");

	// Initialize total
	int total = 0;

	// For each line in the input
	while (inFile.good())
	{
		// Initialize a line and read it
		std::string line;
		std::getline(inFile, line);

		// Create a stringstream from the line
		std::istringstream lineStream(line);
		
		// Initialize an int and use stringstream to convert the line
		// to an int.
		int lineAsInt = 0;
		lineStream >> lineAsInt;

		// Add it to the total frequency.
		total += lineAsInt;
	}

	inFile.close();

	return total;

}

int part2()
{
	// Open input stream
	std::ifstream inFile("input.txt");

	// Initialize total
	int total = 0;

	// Initialize a list of totals we've seen already.
	std::vector<int> totals;

	// Repeat the input until we find a duplicate.
	for (;;)
	{
		// For each line in the input
		while (!inFile.eof())
		{
			// Initialize a line and read it
			std::string line;
			std::getline(inFile, line);

			// Create a stringstream from the line
			std::istringstream lineStream(line);
			
			// Initialize an int and use stringstream to convert the line
			// to an int.
			int lineAsInt = 0;
			lineStream >> lineAsInt;

			// Add it to the total frequency.
			total += lineAsInt;

			// If this frequency is new, add it to the list and continue.
			if (std::find(totals.begin(), totals.end(), total) == totals.end())
			{
				totals.push_back(total);
			}
			// Otherwise, stop.
			else
			{
				return total;
			}
		}
		inFile.clear();
		inFile.seekg(0);
	}

	// Close the input stream.
	inFile.close();

	return total;

}


int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		if (*argv[1] == '1')
		{
			int value = part1();
			std::cout << value;
			return value;
		}
		else if (*argv[1] == '2')
		{
			int value = part2();
			std::cout << value;
			return value;
		}
	}
	std::cout << "Invalid argument.";
	return 0;
}
