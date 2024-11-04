#include "Entity.h"

Entity::Entity(const string& name, int currentHealth, int maxHealth, int damage, int gold): 
	mName(name), mCurrentHealth(currentHealth), mMaxHealth(maxHealth), mDamage(damage), mGold(gold) { }

const string& Entity::Getname() const {
	return mName;
}

int Entity::GetDamage() const {
	return mDamage;
}

int Entity::GetMaxHealth() const {
	return mMaxHealth;
}

int Entity::GetCurrentHealth() const {
	return mCurrentHealth;
}

int Entity::GetGold() const {
	return mGold;
}

void Entity::ReduceHealth(int damageTaken) {
	mCurrentHealth -= damageTaken;
}

void Entity::Attack(Entity* entityToAttack) {
	entityToAttack->ReduceHealth(mDamage);
}

bool Entity::IsDead() const {
	//return is going to return the value true IF the condition is true, otherwise it will return false
	return (mCurrentHealth <= 0);
}
