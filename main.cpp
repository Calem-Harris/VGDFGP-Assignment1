// Lost Fortune
// A personalized adventure
// By Calem Harris

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::vector;

void displayInventory();
void doYouWantToBuySomethingElse(string question);
int askNumber(int high, int low = 1);

vector<string> merchantInventory;
vector<int> merchantInventoryQuantity;

vector<string>::const_iterator iter;
char response = ' ';

int main()
{
	//Creating our inventory objects
	merchantInventory.push_back("sword: 20G");
	merchantInventory.push_back("shield: 10G");
	merchantInventory.push_back("armor: 5G");

	//Linking this vector's elements to the elements above!
	merchantInventoryQuantity.push_back(2);
	merchantInventoryQuantity.push_back(1);
	merchantInventoryQuantity.push_back(5);

	do {
		displayInventory();

		for (int i = 0; i < merchantInventory.size(); ++i) {
			cout << "Object: " << merchantInventory[i] << "   Quantity: " << merchantInventoryQuantity[i] << std::endl;
		}

		switch (askNumber(3, 1)) {
		case 1:
			cout << "You bought a sword!";
			merchantInventoryQuantity[0] = merchantInventoryQuantity[0] - 1;

			if (merchantInventoryQuantity[0] == 0) {
				merchantInventory[0] = "SOLD OUT";
			}
			break;

		case 2:
			cout << "You bought a shield";
			break;

		case 3:
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

void displayInventory() {
	cout << "\nMerchant items: \n";

	for (iter = merchantInventory.begin(); iter != merchantInventory.end(); iter++) {
		cout << *iter << std::endl;
	}
}


void doYouWantToBuySomethingElse(string question)
{
	do {
		cout << question << " (y/n)" << std::endl;
		std::cin >> response;
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
