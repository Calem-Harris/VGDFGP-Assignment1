#pragma once
#include <iostream>
#include <string>

using std::string;

class Entity {
public:
	Entity(const string& name = "NEEDS NAME", int currentHealth = 100, int maxHealth = 100, int damage = 10, int gold = 20);
	const string& Getname() const;
	int GetDamage() const;
	int GetMaxHealth() const;
	int GetCurrentHealth() const;
	int GetGold() const;

	//Combat Functionality
	void ReduceHealth(int damageTaken);
	virtual void Attack(Entity* entityToAttack);
	bool IsDead() const;

//AddHealth()
//RestoreFullHealth();
//AddDamage();
//AddMaxHealth();

protected:
	string mName;
	int mCurrentHealth;
	int mMaxHealth;
	int mDamage;
	int mGold;
};
