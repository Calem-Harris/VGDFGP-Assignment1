#include <iostream>
#include <vector>
#include <string>

#include "Player.h"
#include "Enemy.h"

int AskNumber(string question, int high, int low);
void RemoveDeadMonster(std::vector<Enemy*>& monsters);

int main() {
    Room* room1 = new Room("Courtyard", "You see a bunch of people bustling about under the afternoon sun.");
    Room* room2 = new Room("Forest", "A dense grove of trees provides some shade against the harsh sunlight.");
    Room* room3 = new Room("Tavern", "You hear a chorus of boistrus laughter eminating from inside.");
    Room* room4 = new Room("Private Room", "A quite place with a small bed and table.");

    //Room1 has two exits: Room2 and Room3
    room1->AddExit(room2);
    room1->AddExit(room3);

    room2->AddExit(room1);

    //When we do this, we are creating a two-way door
    room3->AddExit(room4);
    room4->AddExit(room3);

    Enemy* enemy1 = new Enemy("Bob", 20, 10, 15);
    Enemy* enemy2 = new Enemy("Steve", 20, 10, 15);
    Enemy* enemy3 = new Enemy("Martin", 20, 10, 15);

    room1->AddEnemy(enemy1);
    room1->AddEnemy(enemy2);

    room2->AddEnemy(enemy3);

    string playerName;
    std::cout << "Enter your name" << std::endl;
    std::cin >> playerName;

    Player* player = new Player(playerName, 200, 15, 300);
    //The one time we are HARD setting their room.
    player->SetRoom(room1);
    player->GetRoom()->DisplayRoom();

    int choice;

    do {
        if (player->GetRoom()->GetNumberOfEnemies() <= 0) {
            player->GetRoom()->SetIsSafe(true);
        }
        else {
            player->GetRoom()->SetIsSafe(false);
        }

        std::cout << "1. Move to a new location" << std::endl;
        std::cout << "2. Display Room" << std::endl;
        std::cout << "3. Fight an Enemy" << std::endl;
        choice = AskNumber("What do you want to do? (0 to quit)", 4, 0);
        switch (choice) {
        case 1: 
        {
            //Option 1: Move to a new Room
            //I want to prevent the player from moving to a new room if there are enemies in the current room.
            if (!player->GetRoom()->GetIsSafe()) {
                std::cout << "\n\n You cannot leave while there are enemies in the room!\n\n";
                break;
            }

            int moveChoice;
            player->GetRoom()->ListExits();
            moveChoice = AskNumber("Where would you like to go? (0 to exit)", player->GetRoom()->GetNumberOfExits(), 0) - 1;
            player->SetRoom(player->GetRoom()->GetExits()[moveChoice]);
            //Player is in the new room
            player->GetRoom()->DisplayRoom();
            break;
        }

        case 2:
        {
            //Option 2: Look at Current Room
            player->GetRoom()->DisplayRoom();
            break;
        }

        case 3:
        {
            //Option 3: Fight an enemy
            std::cout << "A being stands before you blocking your path.\n\n";

            int combatChoice = -1;
            while ((!player->GetRoom()->GetEnemies()[0]->IsDead() && !player->IsDead()) && combatChoice != 0) {
                //Combat should happen!
                std::cout << "\n Your Health: " << player->GetCurrentHealth() << std::endl;
                std::cout << "\n Enemy Health: " << player->GetRoom()->GetEnemies()[0]->GetCurrentHealth() << std::endl;

                std::cout << "\n\n [1] To Attack\n";
                std::cout << "[2] To Use an Item\n";
                std::cout << "[0] To Run Away\n";


                combatChoice = AskNumber("What do you want to do?", 2, 0);

                switch (combatChoice) {
                case 1:
                    //Attack
                    //Favoring the player during attacks
                    player->Attack(player->GetRoom()->GetEnemies()[0]);

                    if (!player->GetRoom()->GetEnemies()[0]->IsDead()) {
                        player->GetRoom()->GetEnemies()[0]->Attack(player);
                    }
                    break;

                case 2:
                    //TODO Use an Item
                    break;
                case 0:
                    //Retreat
                    std::cout << "You flee from battle.\n\n";
                    break;
                default:
                    std::cout << "\nInvalid Input!\n";
                }

            }

            if (player->IsDead()) {
                std::cout << "You have died! GAME OVER\n\n";
                choice = 0;
            }

            if (player->GetRoom()->GetEnemies()[0]->IsDead()) {
                std::cout << "\nYou have won the battle!\n";
                std::cout << "You gained " << player->GetRoom()->GetEnemies()[0]->GetGold() << " gold.\n";
                std::cout << "You gained 50xp.\n\n";
                player->AddGold(player->GetRoom()->GetEnemies()[0]->GetGold());
                player->AddExp(50);
                RemoveDeadMonster(player->GetRoom()->GetEnemies());
                std::cout << "Total monsters left: " << player->GetRoom()->GetNumberOfEnemies() << "\n";
            }

            break;

        }
            
        case 4:
        {
            //TODO we still need to create things to inspect/interact with
            //Option 4: Inspect something in the Room

            break;
        }

        case 0 :
        {
            // We want to exit the program
            break;
        }

        default:
        {
            std::cout << "Invalid input, please try again\n\n";
        }

        }

    } while (choice != 0);

    //TODO make sure to delete and set pointer to nullptr
    delete room1;
    room1 = nullptr;

    delete room2;
    room2 = nullptr;

    delete room3;
    room3 = nullptr;

    delete room4;
    room4 = nullptr;

    delete player;
    player = nullptr;

    delete enemy1;
    enemy1 = nullptr;

    delete enemy2;
    enemy2 = nullptr;

    delete enemy3;
    enemy3 = nullptr;

    return 0;
}

//Pseudocode -> Writing code without actually writing any of the code

//While the player wants to play the game
    //Ask them what they want to do and give them a list of options

int AskNumber(string question, int high, int low)
{
    int number;
    do {
        std::cout << question << " (" << low << " - " << high << "): ";
        std::cin >> number;
    } while (number > high || number < low);

    return number;
}

void RemoveDeadMonster(std::vector<Enemy*>& monsters)
{
    if (!monsters.empty() && monsters[0]->GetCurrentHealth() <= 0) {
        delete monsters[0];
        monsters.erase(monsters.begin());
    }
}
