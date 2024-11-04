#include "player.h"

Player::Player(const string& name, int health, int damage, int gold) : 
	Entity(name, health, health, damage, gold) {}

void Player::Attack(Entity* entityToAttack) {
	std::cout << "\nThe player lands an attack!\n";
	Entity::Attack(entityToAttack);
}

int Player::GetExp() {
	return mExp;
}

void Player::AddExp(int expToAdd) {
	mExp += expToAdd;

	if (mExp >= mExpToLevelUp) {
		//We have leveled up!
		mLevel++;
		
		std::cout << "You leveled up! You are now level " << mLevel << std::endl;

		int difference = mExp - mExpToLevelUp;
		mExp = 0 + difference;
		//Everytime we level up, we need 50 more EXP to reach the next level than we did prior
		mExpToLevelUp += 50;
	}
}

void Player::AddGold(int goldToAdd) {
	mGold += goldToAdd;
}

void Player::SetRoom(Room* room) {
	mCurrentRoom = room;
	std::cout << "\n" << mName << " is at the " << room->GetName() << std::endl;
}

Room* Player::GetRoom() {
	return mCurrentRoom;
}