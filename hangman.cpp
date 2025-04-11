
# include <iostream>
# include <windows.h> 
#include <cstdlib>
#include <ctime>
using namespace std;
class Hangman
{
	private:
		//Initialize Variables 
		string animals[20] = 
		{
		    "tiger", "zebra", "panda", "horse", "sheep",
		    "mouse", "goose", "eagle", "frog", "koala",
		    "rabbit", "donkey", "monkey", "goat", "parrot",
		    "duck", "jaguar", "lion", "bear", "deer"
		};
	
		string fruits[20] = 
		{
	   		"apple", "mango", "grape", "peach", "melon",
		    "lemon", "kiwi", "plum", "guava", "berry",
		    "fig", "pear", "cherry", "coconut", "orange",
		    "date", "lime", "papaya", "banana", "apricot"
		};
	
		string vegetables[20] = 
		{
		    "carrot", "potato", "onion", "tomato", "cabbage",
		    "beans", "pepper", "corn", "lettuce", "peas",
		    "garlic", "radish", "beet", "spinach", "celery",
		    "turnip", "mushroom", "leek", "okra", "chili"
		};
	
		string objects[20] = 
		{
		    "table", "chair", "laptop", "phone", "bottle",
		    "clock", "backpack", "pencil", "book", "television",
		    "keyboard", "mouse", "camera", "sunglasses", "candle",
		    "wallet", "headphones", "mirror", "watch", "shoes"
		};
		
		char answer;
		int wrong = 0;
		int correct = 0;
		bool found;
		int Life = 6;
		char guess_characters[20];
		
		//func to select random word
		string Random_word(int number)
		{
			// Seed the random number generator
	        srand(time(0));
	        // Generate a random number between 1 - 999
	        int Random = (rand() % 20); 
			//Return random selected word 
			switch(number)
			{
				case 1:
					return objects[Random];
				case 2:
					return animals[Random];
				case 3:
					return vegetables[Random];
				case 4:
					return fruits[Random];
			}
		}
		
		//To Set color
	    void setColor(int color)
	    {
	    	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    	SetConsoleTextAttribute(hConsole, color);
		}
		
		//func to print hangman
		void print_hangman(int wrong)
		{
			cout << endl;
			cout << endl;
			setColor(3);
			//Which hangman to print
			switch (wrong)
			{
				case 0:
					{
						cout << "___________________________" << endl;
						cout << " |            |" << endl;
						cout << " |"<< endl; //face
						cout << " |"<< endl; //hand
						cout << " |"<< endl; //body
						cout << " |"<< endl; //legs
						cout << " |                                                       Make a Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
						break;
					}	
				case 1:
					{
						cout << "\a";
						cout << "___________________________" << endl;
						cout << " |            |" << endl;
						cout << " |            O "<< endl;
						cout << " |"<< endl; //hand
						cout << " |"<< endl; //body
						cout << " |"<< endl; //legs
						cout << " |                                                       Incorrect Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
				case 2:
					{
						cout << "\a";
						cout << "___________________________" << endl;
						cout << " |            |" << endl;
						cout << " |            O "<< endl;
						cout << " |           /"  << endl; 
						cout << " |"<< endl; //body
						cout << " |"<< endl; //legs
						cout << " |                                                       Incorrect Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
				case 3:
				  	{
				  		cout << "\a";
				  		cout << "___________________________" << endl;
						cout << " |            |   " << endl;
						cout << " |            O    "<< endl;
						cout << " |           / \\"  << endl; 
						cout << " |                 "<< endl; 
						cout << " |               "  << endl; 
						cout << " |                                                       Incorrect Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;	
					}
				case 4:	
					{
						cout << "\a";
						cout << "___________________________" << endl;
						cout << " |            |   " << endl;
						cout << " |            O    "<< endl;
						cout << " |           / \\"  << endl; 
						cout << " |            |    "<< endl; 
						cout << " |               "  << endl; 
						cout << " |                                                       Incorrect Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
				case 5:	
					{
						cout << "\a";
						cout << "___________________________" << endl;
						cout << " |            |   " << endl;
						cout << " |            O    "<< endl;
						cout << " |           / \\"  << endl; 
						cout << " |            |    "<< endl; 
						cout << " |           /   "  << endl; 
						cout << " |                                                       Incorrect Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
				case 6:	
					{
						cout << "\a";
						cout << "___________________________" << endl;
						cout << " |            |   " << endl;
						cout << " |            O    "<< endl;
						cout << " |           / \\"  << endl; 
						cout << " |            |    "<< endl; 
						cout << " |           / \\"  << endl; 
						cout << " |                                                       Bye Bye Loser!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    /      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
			}
			cout << endl;
			cout << endl;
			setColor(15);
			cout << "==============================================" << endl;
	   		cout << "                 LIFE: " << Life                << endl;
	        cout << "==============================================" << endl;
		}		
		void correct_print_hangman(int wrong)
		{
			cout << endl;
			cout << endl;
			setColor(3);
			//Which hangman to print
			switch (wrong)
			{
				case 0:
					{
						cout << "___________________________" << endl;
						cout << " |            |" << endl;
						cout << " |"<< endl; //face
						cout << " |"<< endl; //hand
						cout << " |"<< endl; //body
						cout << " |"<< endl; //legs
						cout << " |                                                       Nice Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
						break;
					}
				case 1:
					{
						cout << "___________________________" << endl;
						cout << " |            |" << endl;
						cout << " |            O "<< endl;
						cout << " |"<< endl; //hand
						cout << " |"<< endl; //body
						cout << " |"<< endl; //legs
						cout << " |                                                       Nice Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
				case 2:
					{
						cout << "___________________________" << endl;
						cout << " |            |" << endl;
						cout << " |            O "<< endl;
						cout << " |           /"  << endl; 
						cout << " |"<< endl; //body
						cout << " |"<< endl; //legs
						cout << " |                                                       Nice Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
				case 3:
				  	{
				  		cout << "___________________________" << endl;
						cout << " |            |   " << endl;
						cout << " |            O    "<< endl;
						cout << " |           / \\"  << endl; 
						cout << " |                 "<< endl; 
						cout << " |               "  << endl; 
						cout << " |                                                       Nice Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;	
					}
				case 4:	
					{
						cout << "___________________________" << endl;
						cout << " |            |   " << endl;
						cout << " |            O    "<< endl;
						cout << " |           / \\"  << endl; 
						cout << " |            |    "<< endl; 
						cout << " |               "  << endl; 
						cout << " |                                                       Nice Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					break;
					}
				case 5:	
					{
						cout << "___________________________" << endl;
						cout << " |            |   " << endl;
						cout << " |            O    "<< endl;
						cout << " |           / \\"  << endl; 
						cout << " |            |    "<< endl; 
						cout << " |           /   "  << endl; 
						cout << " |                                                       Nice Guess!"<< endl;
						cout << " |                                                     /  "<< endl;
						cout << " |      ==================                            O"   << endl;
						cout << " |      ||               ||                          / \\" << endl;
						cout << " |      ||               ||                    |      |"   << endl;
						cout << " |      ||               ||                  =====   / \\" << endl;
						cout << "---------------------------------------------|---|--------------------------------" << endl;
					}
			}
			cout << endl;
			cout << endl;
			setColor(15);
			cout << "==============================================" << endl;
	   		cout << "                 LIFE: " << Life                << endl;
	        cout << "==============================================" << endl;
		}
//Access Specifier 	
public:
		void Input(int number)
		{
			correct = 0;
			wrong = 0;
			Life = 6;
			//get the word from function
			string word_to_guess = Random_word(number);
			//cal the size of word
			int len = word_to_guess.length();
			//Print input msg
			cout << "\nGUESS THE WORD:   ";
			//Print the blanks eqaul to the len
			for(int i = 0; i < len; i++)
			{
				cout << " __ ";
			}
			//new line
			cout << endl;
			print_hangman(wrong);
			//Make an Input 
			char arr[len];
			int count;
			//Initialize the array 
			for(int i = 0; i <len; i++)
			{
				arr[i] = '0';
			}
			count = 0;
			//While the wrong try is not equal to 6
			while(wrong != 6)
			{
				found = false;
				//Tell the gueesed characters 
				cout << "\n ~ Word you already guessed: [";
				for(int i = 0; i < count; i++)
				{
					cout << guess_characters[i] << ' ';
				}
				cout << " ]" << endl;
				//Take input 
				cout << "\nEnter the Letter:   ";
				cin >> answer;
				if(isspace(answer))
				{
					continue;
				}
				guess_characters[count] = answer;
				count++;
				for(int i = 0; i < len; i++ )
				{
						if(answer == word_to_guess[i])
						{
							found = true;
							correct++;
							arr[i] = answer;
						}
						if(answer == guess_characters[i])
						{
							correct--;
						}
				}
			//If the guessed letter is wrong 
			if(!found)
			{
				wrong++;
				Life--;
				print_hangman(wrong);
				for(int i = 0; i <len; i++ )
				{
						if(arr[i] == '0')
						{
							cout << " __ ";
						}
						else
						{
							cout << " " << arr[i] << " ";
						}
				}
				cout << endl;	
			}
			//If the guessed letter is correct 
			else
			{	
				for(int i = 0; i <len; i++ )
				{
						if(arr[i] == '0')
						{
							cout << " __ ";
						}
						else
						{
							cout << " " << arr[i] << " ";
						}
				}
				correct_print_hangman(wrong);
				cout << endl;
				if(correct == len)
				{
					cout << "\n\nThe Word was : " << word_to_guess << endl;
					cout << "==============================================" << endl;
	        		cout << "                   You Won!                " << endl;
	        		cout << "==============================================" << endl;
					return;
				}		
			}				
		}
		cout << "\n\nThe Word was : " << word_to_guess << endl;
		cout << endl;
		cout << "==============================================" << endl;
	    cout << "                   \a You Lose!                " << endl;
		cout << "==============================================" << endl;
	}
};
	//To Set color
    void setColor(int color)
    {
    	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(hConsole, color);
	}
int main()
{
	cout << "\t\t\t===========================================================" << endl;
    cout << "\t\t\t\t\t      H A N G M A N      O \n\t\t\t\t\t\t\t       < | >" << endl;
    cout << "\t\t\t\t\t        G A M E         / \\                           " << endl;
    cout << "\t\t\t===========================================================" << endl;
	Hangman man;
	int option;
	int choice;
	// Seed the random number generator
	srand(time(0));
	do
	{
	cout << endl;
	cout << "--------------------------------------\n"
            << "|          Choose a Category         |\n"
            << "--------------------------------------\n"
            << "|  1. Object                         |\n"
            << "|  2. Animal                         |\n"
            << "|  3. Vegetable                      |\n"
            << "|  4. Fruit                          |\n"
            << "--------------------------------------\n"
            << "Enter your choice: ";
	cin >> option;
	man.Input(option);
	A:
	cout << endl;
	cout << "Do you want to play again ??" 
		 << "\n 1 = Yes" 
		 << "\n 2 = NO" 
		 << endl;
	cin >> choice;
	if(choice > 2 || choice < 1)
	{
		cout << "Invalid choice !" << endl;
		goto A;
	}
	cout << endl;
	}while(choice == 1);
		
	for(int i = 0; i <= 15; i++) 
	{
		setColor(i);
        cout << "\t\t\t\tTTTTT  H   H  AAAAA  N   N  K   K    U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  NN  N  K  K     U   U" << endl;
	    cout << "\t\t\t\t  T    HHHHH  AAAAA  N N N  K K      U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  N  NN  KK       U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  N   N  K  K     U   U" << endl;
	    cout << "\t\t\t\t  T    H   H  A   A  N   N  K   K    UUUUU" << endl;
        
        Sleep(300); 
    }
	return 0;
}

