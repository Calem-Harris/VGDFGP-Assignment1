#include "Enemy.h"

Enemy::Enemy(const string& name, int maxHealth, int damage, int gold) : 
	Entity(name, maxHealth, maxHealth, damage, gold) { }

void Enemy::Attack(Entity* entityToAttack) {
	std::cout << "\nThe enemy swings their sword and hits you!\n";
	Entity::Attack(entityToAttack);
}