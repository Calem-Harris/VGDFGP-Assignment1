#pragma once
#include "Entity.h"
#include "Room.h"

class Player : public Entity {
public:
	Player(const string& name, int health, int damage, int gold);

	virtual void Attack(Entity* entityToAttack);

	int GetExp();
	void AddExp(int expToAdd);

	void AddGold(int goldToAdd);

	//Player is in control of what room they are in
	//And when they want to naviagate to a different room.
	void SetRoom(Room* room);
	Room* GetRoom();

private:
	int mLevel = 1;
	int mExp = 0;
	int mExpToLevelUp = 100;
	Room* mCurrentRoom = nullptr;
};
