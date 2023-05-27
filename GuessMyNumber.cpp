// GuessMyNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

namespace settings {
	const int lowRangeVal = 1, 
			  highRangeVal = 100; //low and high value of number range 
}

/// <summary>
/// ask user for a number in a range
/// </summary>
/// <param name="text">instruction or question for user asking for number</param>
/// <param name="lowVal">low value of the range</param>
/// <param name="highVal">high value of the range</param>
/// <returns>number between range</returns>
int askNumber(std::string text, int lowVal, int highVal);

int main()
{
	//rng
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(settings::lowRangeVal, settings::highRangeVal); //set range of random number

	int secretNumber = dist(mt); //get random number
	int tries = 0;
	int guess = 0;

	std::cout << "\tWelcome to Guess My Number\n\n";

	do
	{
		guess = askNumber("Enter a guess", settings::lowRangeVal, settings::highRangeVal);
		tries++;

		if (guess > secretNumber)
			std::cout << "You guessed too high!\n\n";
		else if (guess < secretNumber)
			std::cout << "You guessed too low!\n\n";
		else
			std::cout << "You guessed it! You got it in " << tries << " guesses!\n\n";
		

	} while (guess != secretNumber);

	std::cout << "Press enter to close the program.";

	std::cin.ignore();
	std::cin.get();
}

int askNumber(std::string text, int lowVal, int highVal) {
	int answer = 0;
	do
	{
		std::cout << text << " between " << lowVal << "-" << highVal << ": ";
		std::cin >> answer;
		//user gave non-numeric input
		if (std::cin.fail()) {
			std::cout << "Please input numbers only!\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		//user input number outside the range 
		else if (answer < lowVal || answer > highVal)
		{
			std::cout << "Please input number between " << lowVal << "-" << highVal << "!\n\n";
		}
	} while (std::cin.fail() || answer < lowVal || answer > highVal);

	return answer;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
