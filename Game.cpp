#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
const int max_wrong_guesses = 10; // This is the max amount of wrong guesses
bool checker(char, std::string&, std::string); // This function will check wether you guessed a letter from the word correctly or not
std::vector<std::string> words_list{ "kinan not found", "alaa", "ahmad", "rawan", "loganpaul" }; // This is the words list
int main()
{
	system("cls");
	srand(time(0)); // This will give the unix time as a seed for the random number gnerator function
	char playing_again; // This var will check wether the player wants to play again or not
	int win_or_lose = 0; // This var will know if the user won or lost (win : 1, lose : 2)
	int wrong_guess = 0; // This var will count the number of wrong guesses
	char letter; // This var will be the letter that user will enter
	int index = rand() % words_list.size(); // This var will be a random index from the list
	std::string choosed_word = words_list[index]; // This object will hold the element that allocated in the random index
	std::string board(words_list[index].length(), '_'); // This object will be the board
	words_list.erase(words_list.begin() + index); // This will erase the word we got from the list (to avoid words repetation)
	while (!win_or_lose)
	{
		std::cout << "You have : " << wrong_guess << "/10 wrong answer/s\n\n";
		std::cout << board << std::endl << std::endl;
		std::cout << "Enter your guess : ";
		std::cin >> letter;
		std::cout << std::endl;
		if (checker(letter, board, choosed_word))
		{
			std::cout << "Congrats for guessing the right letter!" << std::endl;
		}
		else
		{
			std::cout << "It's a wrong answer :(" << std::endl;
			wrong_guess++;
		}
		if (board == choosed_word)
		{
			win_or_lose = 1;
		}
		if (wrong_guess == max_wrong_guesses)
		{
			win_or_lose = 2;
		}
		std::cout << "\n-------------------------------------------\n\n";
	}
	system("cls");
	if (win_or_lose == 1)
	{
		std::cout << "Congratssssss you won the game!!!!!" << std::endl;
	}
	else
	{
		std::cout << "Sad for telling you that but you lost :(" << std::endl;
	}
	std::cout << "The word was : " << choosed_word << std::endl;
	std::cout << "Want to play again? (y / n)" << std::endl;
	do
	{
		std::cin >> playing_again;
		if (playing_again == 'y')
		{
			main();
		}
		if (playing_again == 'n')
		{
			return 0;
		}
	} while (playing_again != 'y' && playing_again != 'n');
}
bool checker(char letter, std::string& board, std::string choosed_word)
{
	bool temp = false;
	for (size_t i = 0; i < choosed_word.size(); i++)
	{
		if (letter == board[i])
			return false;
		if (letter == choosed_word[i])
		{
			board[i] = letter;
			temp = true;
		}
	}
	return temp;
}