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
	}
	else {
		std::cout << "Name " << name << " is added to Leaderboard!\n";
	}

	game();
	int tries = game();

	out_file << name << ' ';
	out_file << tries << std::endl;

	std::ifstream in_file{ high_scores_filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
	}

	while (true) {
	in_file >> name;
	in_file >> tries;
	in_file.ignore();

	if (in_file.fail()) {
		break;
	}
		
	std::cout << name << '\t' << tries << std::endl;
	}
}