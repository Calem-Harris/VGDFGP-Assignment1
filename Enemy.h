#pragma once
#include<iostream>

#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy(const string& name, int maxHealth, int damage, int gold);

	virtual void Attack(Entity* entityToAttack);
};