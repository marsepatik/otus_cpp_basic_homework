#include <iostream>
#include <string>
#include <fstream>
#include "random.h"

int random = random_value();

int guess = 0;
int tries = 0;

int game()
{
	while (guess != random)
	{
		std::cout << "Enter your guess...\n";
		std::cin >> guess;
		tries++;
		if (guess < random) {
			std::cout << "You think it " << guess << ", Hmmm...\n";
			std::cout << "Fail! Try greater!\n";
		}
		else if (guess > random) {
			std::cout << "You think it " << guess << ", Hmmm...\n";
			std::cout << "Fail! Try less!\n";
		}
		else break;
	}
	
	std::cout << "You think it " << guess << ", Hmmm...\n";

	if (tries == 1) {
		std::cout << "FIRST TRY!!! You are INCANE xDDD" << std::endl;
	}
	else {
		std::cout << "YEAH!\n";
		std::cout << "You win after " << tries << " tries!\n";
	}
	int trys = tries;
	return trys;
}