// Lost Fortune
// A personalized adventure
// By Calem Harris

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::vector;

void display(const vector<string>& inventoryVector);
string& referenceToElement(vector<string>& inventoryVector, int elementPosition);

int main() {
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	//Display the string that the returned reference refers to
	cout << "Sending the returned reference to cout:\n";
	cout << referenceToElement(inventory, 0) << "\n\n";

	//Assign one reference to another -- inexpensive assignment
	cout << "Assigning the returned reference to another reference.\n";
	string& referenceString = referenceToElement(inventory, 1);
	cout << "Sending the new reference to cout\n";
	cout << referenceString << "\n\n";

	//Making a reference to a reference
	cout << "Assigning a reference to another reference.\n";
	string& referenceToStringReference = referenceString;
	cout << "Sending the new reference to cout\n";
	cout << referenceToStringReference << "\n\n";

	//Copying a string object -- expensive assignment!!!
	cout << "Assign the returned reference to a string object.\n";
	string str = referenceToElement(inventory, 2);
	cout << "Send the new string object to cout:\n";
	cout << str << "\n\n";

	//Altering a string object through returned references
	cout << "Altering a string object through returned references\n";
	referenceString = "Healing Potion";
	cout << "Sending the altered object to cout\n";
	cout << inventory[1] << std::endl;

	cout << "Altering a string object through returned references\n";
	referenceToStringReference = "Greataxe";
	cout << "Sending the altered object to cout\n";
	cout << inventory[1] << std::endl;

	return 0;
}

//Allows us to have access to the referred type BUT WE CANNOT EDIT IT
void display(const vector<string>& inventoryVector)
{
	cout << "Your items: " << "\n";
	for (vector<string>::const_iterator iter = inventoryVector.begin(); iter != inventoryVector.end(); ++iter) {
		cout << *iter << std::endl;
	}
}

string& referenceToElement(vector<string>& inventoryVector, int elementPosition)
{
	return inventoryVector[elementPosition];
}
