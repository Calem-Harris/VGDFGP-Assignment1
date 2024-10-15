// Lost Fortune
// A personalized adventure
// By Calem Harris

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::vector;

int main()
{
	vector<string> inventory;
									//Crossbow
	inventory.push_back("sword"); //BattleAxe
	inventory.push_back("shield"); // = end() - 2
	inventory.push_back("armor");
									//end is looking here

	vector<string>::iterator myIterator;
	vector<string>::const_iterator iter;

	cout << "You have " << inventory.size() << " items\n";

	cout << "\nYour items: \n";

	for (iter = inventory.begin(); iter != inventory.end(); iter++) {
		cout << *iter << std::endl;
	}

	cout << "\nYou trade your sword for a Battleaxe\n";
	myIterator = inventory.begin();
	*myIterator = "BattleAxe";

	cout << "\nYour items: \n";

	for (iter = inventory.begin(); iter != inventory.end(); iter++) {
		cout << *iter << std::endl;
	}

	cout << "\nYou recover a crossbow from a slain enemy.\n";
	inventory.insert(inventory.begin(), "crossbow");
	for (iter = inventory.begin(); iter != inventory.end(); iter++) {
		cout << *iter << std::endl;
	}

	cout << "\nYour shield was destroyed in a fire\n";
	inventory.erase(inventory.end() - 2);

	for (iter = inventory.begin(); iter != inventory.end(); iter++) {
		cout << *iter << std::endl;
	}

	cout << "\nYou fought a fierce battle and lost your armor.\n";
	inventory.pop_back();
	
	cout << "\nYour items: \n";

	for (int i = 0; i < inventory.size(); i++) {
		cout << inventory[i] << std::endl;
	}

	cout << "\nYou run into a theif who steals all your remaining items!\n";
	inventory.clear();

	cout << "\nYour items: \n";

	for (int i = 0; i < inventory.size(); i++) {
		cout << inventory[i] << std::endl;
	}
}