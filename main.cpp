// Lost Fortune
// A personalized adventure
// By Calem Harris

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::vector;

//Function Prototype
//void means that the function doesn't return anything
//Step 1: Create function prototype
void displayInventory();
void doYouWantToBuySomethingElse(string question);
//If low isn't given a value, its value is 1
int askNumber(int high, int low = 1);

//These now belong to our script which means ANYTHING inside our script can access them
vector<string> inventory;
vector<string>::const_iterator iter;
char response = ' ';

//This is the function that is being run on PLAY
int main()
{
	inventory.push_back("sword");
	inventory.push_back("shield");
	inventory.push_back("armor");
	//end is looking here

	do {
		//These variables are LOCAL to main
		/*vector<string> inventory;*/

		vector<string>::iterator myIterator;


		//Step 3: Call the function in main()
		displayInventory();

		//When askNumber finishes running, it is going to give us a integer value that we can use.
		switch (askNumber(3, 1)) {
		case 1:
			//User buys sword
			cout << "You bought a sword!";
			break;

		case 2:
			//User buys shield
			cout << "You bought a shield";
			break;

		case 3:
			//User buys armor
			cout << "You bought some armor!";
			break;
		default:
			cout << "Invalid number. Try again";
		}


		string questionToAsk = "Would you like to buy something else?";
		doYouWantToBuySomethingElse(questionToAsk);
	} while (response != 'n');
	
	return 0;
}

//Step 2: Define the actual function
void displayInventory() {
	cout << "\nMerchant items: \n";

	for (iter = inventory.begin(); iter != inventory.end(); iter++) {
		cout << *iter << std::endl;
	}
}

//We only have access to our question variable INSIDE of this function.
//This is known as a temporary variable.
void doYouWantToBuySomethingElse(string question)
{
	do {
		cout << question << " (y/n)" << std::endl;
		std::cin >> response;
		//Either the left OR the right needs to be true
	} while (response != 'y' && response != 'n');
}

int askNumber(int high, int low)
{
	int num = 0;
	do {
		cout << "Please enter a number " << "(" << low << " - " << high << "): ";
		std::cin >> num;
	} while (num > high || num < low);

	return num;
}
