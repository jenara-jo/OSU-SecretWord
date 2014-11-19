/****************************************************************
* Author: Jenise Araujo
* Modified by: Jenise
* Date Created: 10/26/14
* Last Modification Date: 10/26/14
* Filename: secretWord.cpp
*
* Overview: : In this game,	player 1 will pick a secret	word that can be no	longer	
* than 10 characters and cannot contain the following	characters ‘!’,	‘.’,‘?’ or numbers.Then player	
* 2 will have 10 chances to reveal secret word.	With each letter that player 2 guesses correctly	
* the secret wordwill revealwhere in the string that character is, the other	
* words will remain hidden by	an	asterisk. If player	2 guesses incorrectly, the	
* program will just notify the player	and	ask	them to	guess another letter. If player 2 manages
* to reveal the entire secret word then player 2 wins and has a chance to play again.
* If player 2 runs out of chances then player 2 loses but can still play again. 
*
* Input: The input for this program is one string, the secret word and a character which
* player 2 will guess. 
* Example: Secret Word - "John", Guessed_Letter: 'a'
*
* Output: The program will inform the player 2 if the letter they guessed is in the secret  
* word. If it is, the program will reveal the place the letter is in the secret word, if not player 2 
* will have another chance to guess again. 
* Example: Guess: 'b'  Output: Sorry that is not in the word
*
*****************************************************************/
#include <iostream>
#include <string>
using namespace std;

//Global variables -- holds the secret word
string secret_word, guesses;
char guessed_letter;

//Play again variable
string again;


//Guessing game function prototype
string guessing_game (char);

int main ()
{
	do 
	{
	//Introduce the game
	cout << "Let's play a game of guess the secret word!\n";
	cout << "Player 1 please enter a secret word, it can be no longer than 10\n";
	cout << "characters and can only contain letters\n";
	
	//Have player 1 enter their secret word
	cout << "Player 1 please enter your secret word\n";
	cin >> secret_word;
	
	cout << "The secret word is " << secret_word << endl;
	
	//Check if the length of the secret word is valid
	while (secret_word.length() > 10)
	{
		cout << "Please enter a secret word that has less than\n";
		cout << "ten characters\n";
		cin >> secret_word;	
	}
	
	//Check the secret word for invalid characters
	for (int x = 0; x < secret_word.length(); x++)
	{
		//Checks if the string has invalid characters
		if (secret_word.at(x) == '!' || secret_word.at(x) == ','|| secret_word.at(x) == '.' )
		{
			cout << "Please enter a secret word that is only made of letters" << endl;
			cin >> secret_word;
		}
		
		//Checks if the string has numbers
		if (secret_word.at(x) == '0' ||secret_word.at(x) == '1' || secret_word.at(x) == '2' || secret_word.at(x) == '3' ||secret_word.at(x) == '4' ||secret_word.at(x) == '5' ||secret_word.at(x) == '6' ||secret_word.at(x) == '7' || secret_word.at(x) == '8' || secret_word.at(x) == '0')
		{
			cout << "Please enter a secret word that is only made of letters" << endl;
			cin >> secret_word;
		}
	}
	
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	
	//Call the game
	guessing_game(guessed_letter);
	
	
	//To start game over
	} while (again =="yes" || again == "Yes");
	
	return 0;
}

//Define the guessing game function
string guessing_game(char guessed_letter)
{	
	//To show the word when guessed correctly
	string reveal(secret_word.length(), '*');

	//Variables to carry guesses letters
	string correct_guesses = "";
	string incorrect_guesses = "";
	
	//Give instructions to player 2
	cout << "Player 2 now it's time for you to play\n";
	cout << "You have 10 chances to guess the word\n";
	
	//Player 2 guesses a number
	cout << "What is your first guess?" << endl;
	cin >> guessed_letter;
	
	//Check if the guesses letter is in the secret word with 10 chances left
	for (int y = 9; y >= 0; y--)
	{
			//If the guessed letter is not in the word
			if (secret_word.find(guessed_letter) == string::npos)
			{
				cout << "Sorry that letter isn't in the secret word\n";
				incorrect_guesses += guessed_letter;
				cout << "You have " << y << " chances left" << endl;
				cout << "These are the letters you have guessed incorrectly so far: " << incorrect_guesses << endl;
				cout << "Guess another letter\n";
			} 
			//If the guessed letter is in the word
			else 
			{
				cout << "That letter is in the secret word!" <<endl;
				correct_guesses += guessed_letter;
				cout << "You have " << y << " chances left" << endl;
				
					//Check the secret word to find where guessed letter is 
					for (int x = 0; x < (secret_word.length()); x++)
					{
						if (guessed_letter == secret_word.at(x))
						{
							reveal.at(x) = secret_word.at(x);  
						} 
					}
				cout << "This is what you have gussed so far " << reveal << endl;
				cout << "These are the letters you have guessed correctly so far: " << correct_guesses << endl;
					
					//If secret_word is revealed
					if (reveal == secret_word)
					{
						cout << "Congratulations, you won!\n";
						cout << "The secret word was " << secret_word << endl;
						cout << "You used " << y << " chances\n";
						cout << "Would you like to play again? Yes or no?";
						cin >> again;
						return again;
					}
				cout << "Guess another letter\n";

			}
			cin >> guessed_letter;
		
		
		
	
		}
	//If the player loses
	cout << "Sorry, you lost. You ran out of chances\n";
	cout << "The secret word was " << secret_word << endl;
	cout << "Would you like to play again? Yes or no?";
	cin >> again;
	return again;
	
} 
