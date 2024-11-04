#pragma once //Definition for our header

#include <iostream>
#include <string>
#include <vector>

#include "Enemy.h"

using std::string;
using std::vector;

class Room {
public:
    Room(string name = "Empty Room", string description = "This is an empty room.", bool isSafe = false);

    void AddExit(Room* roomToAdd); //Add one room at a time
    vector<Room*>& GetExits();
    int GetNumberOfExits();
    void ListExits();

    void AddEnemy(Enemy* enemy);
    vector<Enemy*>& GetEnemies();
    int GetNumberOfEnemies();

    //A safe room is a room with NO Enemies in it!
    bool GetIsSafe();
    void SetIsSafe(bool isSafe);

    void DisplayRoom();
    string GetName() const;

    //AddEntity(Entity* entity);
    //vector<Entity*> GetEntities();
    //void ListEntities();

private:
    string mName;
    string mDescription;
    //TODO
    //Add a vector of Entities that will store any/all entities (NPCs/Enemies) that are in this room
    vector<Room*> mExits;
    vector<Enemy*> mEnemies;

    bool mIsSafe;

    //Extra detail -> Implement if time but is not a REQUIRED part of my room
    //bool mLocked;
};
