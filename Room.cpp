#include "Room.h"

Room::Room(string name, string description, bool locked): mName(name), mDescription(description), mIsSafe(locked) { }

void Room::AddExit(Room* room) {
	mExits.push_back(room);
}

vector<Room*>& Room::GetExits() {
	return mExits;
}

int Room::GetNumberOfExits() {
	return mExits.size();
}

void Room::ListExits() {
	if (mExits.size() > 0) {
		std::cout << "You see the following exits: " << std::endl;
		for (int i = 0; i < mExits.size(); i++) {
			std::cout << i + 1 << ". " << mExits[i]->GetName() << std::endl;
		}
	}
	else {
		std::cout << "There is no escape!" << std::endl;
	}

	std::cout << std::endl;
}

string Room::GetName() const {
	return mName;
}

void Room::DisplayRoom() {
	std::cout << mName << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << mDescription << std::endl;

	//List the number of exits
	ListExits();

	//TODO
	//List any/all Entities inside the room
}

void Room::AddEnemy(Enemy* enemy) {
	mEnemies.push_back(enemy);
}

vector<Enemy*>& Room::GetEnemies() {
	return mEnemies;
}

int Room::GetNumberOfEnemies() {
	return mEnemies.size();
}

bool Room::GetIsSafe() {
	return mIsSafe;
}

void Room::SetIsSafe(bool isSafe) {
	mIsSafe = isSafe;
}