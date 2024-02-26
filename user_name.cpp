#include <iostream>
#include <string>
#include <fstream>
#include "user_name.h"
#include "game.h"


void name()
{
	const std::string high_scores_filename = "high_scores.txt";

	std::string name;
	std::cout << "Please, enter your name: ";
	std::cin >> name;

	std::ofstream out_file{ high_scores_filename, std::ios_base::app };

	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		exit(1);
	}
	else {
		std::cout << "Name " << name << " is added to Leaderboard!\n";
		out_file.close();
	}

	int tries = game();

	out_file << name << ' ';
	out_file << tries << std::endl;

	std::ifstream in_file{ high_scores_filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		exit(1);
	}

	while (true) {
	in_file >> name;
	in_file >> tries;
	in_file.ignore();

	if (in_file.fail()) {
		std::cout << "Fail to read leaderboard!" << std::endl << std::endl;
		out_file.close();
		break;
	}
		
	std::cout << name << '\t' << tries << std::endl;
	}
}