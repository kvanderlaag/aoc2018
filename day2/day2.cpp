// Day 2

#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

int part1()
{
	std::ifstream inFile("input.txt");

	int twoCount = 0;
	int threeCount = 0;

	while (!inFile.eof())
	{
		std::string line;
		std::getline(inFile, line);
		
		int counts[26];
		{
			for (int i = 0; i < 26; ++i)
			{
				counts[i] = 0;
			}
		}
		
		{
			for (int i = 0; i < line.length(); ++i)
			{
				int character = line[i] - 'a';

				counts[character]++;
			}
		}
		
		bool hasTwo = false;
		bool hasThree = false;
		{
			for (int i = 0; i < 26; ++i)
			{
				if (counts[i] == 2)
				{
					hasTwo = true;
				}
				if (counts[i] == 3)
				{
					hasThree = true;
				}
			}
		}

		if (hasTwo)
		{
			twoCount++;
		}
		if (hasThree)
		{
			threeCount++;
		}
	}

	return twoCount * threeCount;

	inFile.close();

	return 0;
}

std::string part2()
{
	std::ifstream inFile("input.txt");

	while (inFile.good())
	{
		std::string line1;
		std::getline(inFile, line1);

		std::ios::pos_type oldPosition = inFile.tellg();
		while (!inFile.eof())
		{
			std::string line2;
			std::getline(inFile, line2);

			int differences = 0;
			int position = 0;

			if (line1.length() != line2.length())
			{
				continue;
			}

			for (int i = 0; i < line1.length(); ++i)
			{
				if (line1[i] != line2[i])
				{
					position = i;
					differences++;
				}

				if (differences > 1)
				{
					break;
				}

			}
			if (differences == 1)
			{
				std::string similar;
				for (int i = 0; i < line1.length(); ++i)
				{
					if (i != position)
					{
						similar.append(1, line1[i]);
					}

				}
				return similar;
			}
		}

		inFile.clear();
		inFile.seekg(oldPosition);
		++line;
	}

	inFile.close();
	return 0;
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
			std::string value = part2();
			std::cout << value;
			return value.length();
		}
	}
	std::cout << "Invalid argument.";
	return 0;
}