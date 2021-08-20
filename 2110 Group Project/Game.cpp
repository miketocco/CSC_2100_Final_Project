#include "Game.h"
#include <iostream>
#include <string>
using namespace std;

class invalidDirection{};
class invalidAnswer {};
class invalidItem {};
class emptySlot {};

char isCurrentRoom(bool r);

void Game::startItemPromt()
{
	// ******* START ITEM USE PROMPT ***********
	if (HeroName.bag[0] != nullptr || HeroName.bag[1] != nullptr || HeroName.bag[2] != nullptr)
	{

		cout << "Current Item Inventory: " << endl;

		for (int i = 0; i < 3; i++)
		{
			cout << "Slot " << i + 1 << ": ";

			if (HeroName.bag[i] != nullptr)
			{
				if (HeroName.bag[i]->isDefense())
				{
					cout << "Defence Potion for " << HeroName.bag[i]->getValue();
				}
				else
					cout << "Health Potion for " << HeroName.bag[i]->getValue();
			}
			else
			{
				cout << "Empty Slot";
			}
			cout << endl;
		}

		string ans;

		while (true)
		{
			try
			{
				cout << "Would you like to use any of your items? (y/n): ";
				cin >> ans;
				cout << endl;

				if (ans != "y" && ans != "n")
					throw invalidAnswer();

				break;
			}
			catch (invalidAnswer)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid answer, try again" << endl;
			}
		}

		if (ans == "y")
		{
			int itm;

			while (true)
			{
				try
				{
					cout << "Which item would you like to use? (enter number 1-3): ";
					cin >> itm;
					cout << endl;

					if (itm < 1 || itm > 3)
						throw invalidItem();

					if (HeroName.bag[itm - 1] == nullptr)
						throw emptySlot();

					break;
				}
				catch (invalidItem)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Invalid item, try again" << endl;
				}
				catch (emptySlot)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Empty slot, try again" << endl;
				}
			}

			if (HeroName.bag[itm - 1]->isDefense())
			{
				// add to defence
				HeroName.setDefensePower(HeroName.getDefensePower() + HeroName.bag[itm - 1]->getValue());
				cout << "Defence Power Increase - Current DP:  " << HeroName.getDefensePower();
			}
			else
			{
				// add to health
				HeroName.setHP(HeroName.getHP() + HeroName.bag[itm - 1]->getValue());
				cout << "Health Power Increase - Current HP:  " << HeroName.getHP();
			}
			cout << endl;

			// delete item
			delete HeroName.bag[itm - 1];
			HeroName.bag[itm - 1] = nullptr;

		}
	}			// ******* END ITEM USE PROMPT ***********
}



void Game::creatMap()
{
	//Room creation
	Room* StartRoom = new Room("Start Room" , nullptr, nullptr, nullptr, nullptr, false); //start room
	
	Room* ItemRoom1 = new Room("Old Courtyard", nullptr, nullptr, nullptr, nullptr, new Item(0,90)); //3 item rooms
	Room* ItemRoom2 = new Room("Armory", nullptr, nullptr, nullptr, nullptr, new Item(1, 9)); //defense room
	Room* ItemRoom3 = new Room("Old Shrine", nullptr, nullptr, nullptr, nullptr, new Item(0, 250)); //hp room
	
	Room* MonsterRoom1 = new Room("Ancient Laboratory", nullptr, nullptr, nullptr, nullptr, new Monster(30, 20)); //3 monster rooms
	Room* MonsterRoom2 = new Room("Dead Gardens", nullptr, nullptr, nullptr, nullptr, new Monster(55, 20));
	Room* MonsterRoom3 = new Room("Summoning Room", nullptr, nullptr, nullptr, nullptr, new Monster(200, 30));
	
	Room* Room1 = new Room("Empty Room 1", nullptr, nullptr, nullptr, nullptr, false); //filler rooms
	Room* Room2 = new Room("Empty Room 2", nullptr, nullptr, nullptr, nullptr, false);
	
	Room* ExitRoom = new Room("Exit Room", nullptr, nullptr, nullptr, nullptr, true); //Exit room

	//setting room paths
	StartRoom->setEastRoom(ItemRoom1); //sets next room from spawn
	
	ItemRoom1->setNorthRoom(Room1); //Item room 1 is a 4 way room, this paths all of the rooms
	ItemRoom1->setEastRoom(MonsterRoom1);
	ItemRoom1->setSouthRoom(Room2);

	Room1->setWestRoom(MonsterRoom2); // Room 1 is a filler room that leads to an extra monster room and item room

	MonsterRoom2->setWestRoom(ItemRoom3); // leads to item room

	MonsterRoom1->setEastRoom(ItemRoom2); // leads to item room

	Room2->setEastRoom(MonsterRoom3); // leads to last boss room, then exit

	MonsterRoom3->setEastRoom(ExitRoom); // leads to exit, game over

	currentRoom = StartRoom;
}

void Game::run()
{
	Room* PreviousRoom = nullptr;
	string direction;
	Room* temp;

	// Start while loop to detect where person wants to go, detect which room is entered.
	while (HeroName.getHP() > 0 && !currentRoom->isExit()) {
		
		displayMap();

		// ********* START MOVEMENT ************

		while (true)
		{
			try
			{
				cout << "\nWhich way would you like to go? (North, South, East, or West)   ";
				cin >> direction;
				cout << endl;

				for (int i = 0; i <= direction.length(); i++)
				{
					if (direction[i] >= 97 && direction[i] <= 122)          // converts input to all uppercase (easily manageable)
					{
						direction[i] = direction[i] - 32;
					}
				}

				if (direction == "EAST")
					temp = currentRoom->getEastRoom();

				else if (direction == "WEST")
					temp = currentRoom->getWestRoom();

				else if (direction == "SOUTH")
					temp = currentRoom->getSouthRoom();

				else if (direction == "NORTH")
					temp = currentRoom->getNorthRoom();
				else
					throw invalidDirection();
				
				if (temp == nullptr)
					throw invalidDirection();

				break;
			}
			catch (invalidDirection)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid direction, enter again." << endl;
			}
		}


		PreviousRoom = currentRoom;
		currentRoom = temp;

		displayMap();

		// ********* END MOVEMENT ************

		



		// *********** START ITEM ROOM *************
		if (currentRoom->getRoomItem() != NULL)
		{
			cout << "______________________________" << endl; 
			cout << "Entered: " << currentRoom->getName() << endl;

			if (currentRoom->getRoomItem()->isDefense())
			{
				cout << "This room has a Defense Potion!" << endl;
				cout << "Item Value: " << currentRoom->getRoomItem()->getValue() << " DP" << endl;
			}
			else
			{
				cout << "This room has a Health Potion!" << endl;
				cout << "Item Value: " << currentRoom->getRoomItem()->getValue() << " HP" << endl;
			}
			
			cout << "______________________________" << endl;
			cout << "Current Item Inventory: " << endl;

			for (int i = 0; i < 3; i++)
			{
				cout << "Slot " << i + 1 << ": ";

				if (HeroName.bag[i] != nullptr)
				{
					if (HeroName.bag[i]->isDefense())
					{
						cout << "Defence Potion for " << HeroName.bag[i]->getValue();
					}
					else
						cout << "Health Potion for " << HeroName.bag[i]->getValue();
				}
				else
				{
					if (currentRoom->getRoomItem() != nullptr)
					{
						HeroName.bag[i] = currentRoom->getRoomItem();
						cout << "Filled by current room's item";
						currentRoom->setRoomItem(nullptr);
					}
					else
						cout << "Empty Slot";
				}
				
				cout << endl;
			}
			cout << "______________________________" << endl;

			if (HeroName.bag[0] != nullptr && HeroName.bag[1] != nullptr && HeroName.bag[2] != nullptr)
			{
				string ans;

				cout << "Would you like to swap a bag item for this room item? (y/n): ";
				cin >> ans;
				cout << endl;

				if (ans == "y")
				{
					cout << "Which item would you like to swap? (enter number 1-3): ";
					int itm;

					cin >> itm;
					
					HeroName.bag[itm - 1] = currentRoom->getRoomItem();
					currentRoom->setRoomItem(nullptr);
				}
				cout << endl;
			}
		} // ********** END ITEM ROOM **********





		// ********** START MONSTER ROOM **********
		else if (currentRoom->getRoomMonster() != NULL)
		{
			cout << "______________________________" << endl << endl;
			cout << "Entered: " << currentRoom->getName() << endl;


			cout << "This room has a monster!" << endl;
			cout << "Monster's HP: " << currentRoom->getRoomMonster()->getHP() << " - Monster's AP: " << currentRoom->getRoomMonster()->getAttackPower() << endl;
			cout << "Your HP: " << HeroName.getHP() << "   Your DP: " << HeroName.getDefensePower() << endl;
			
			if (HeroName.bag[0] != nullptr || HeroName.bag[1] != nullptr || HeroName.bag[2] != nullptr)
				startItemPromt();

			string ans;

			while (true)
			{
				try
				{
					cout << "Would you like to retreat? (y/n): ";
					cin >> ans;

					if (ans != "y" && ans != "n")
						throw invalidAnswer();

					break;
				}
				catch (invalidAnswer)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Invalid answer, try again" << endl;
				}
			}
			
			if ((ans == "y") && HeroName.getRetreatCount() > 0)
			{
				HeroName.decreaseRetreatCount();
				currentRoom = PreviousRoom;
				cout << "You're now back in " << currentRoom->getName() << endl;
			}
			else
			{
				if (HeroName.getRetreatCount() == 0)
					cout << "No more retreats left." << endl;
				cout << "______________________________" << endl;
				cout << "You move to attack!" << endl;
				
				int status;

				do
				{
					status = HeroName * *currentRoom->getRoomMonster();

					//death
					if (status == -1)
					{
						cout << "______________________________" << endl;
						cout << "\nYou were slain by the monster.\n\n";
						break;
					}

					else if (status == 1)
					{
						cout << "______________________________" << endl;
						cout << "You've slain the monster!\n";
						cout << "Your HP: " << HeroName.getHP() << "   Your DP: " << HeroName.getDefensePower() << endl;
						cout << "______________________________" << endl << endl;
					}
					else
					{
						cout << "You and the monster exchange attacks, you both attack again." << endl;

						cout << "Your HP: " << HeroName.getHP() << "   Your DP: " << HeroName.getDefensePower() << endl;
						cout << "Monster HP: " << currentRoom->getRoomMonster()->getHP() << endl;
						
						if (HeroName.bag[0] != nullptr || HeroName.bag[1] != nullptr || HeroName.bag[2] != nullptr)
							startItemPromt();

					}

				} while (status == 0);
			}

			currentRoom->setRoomMonster(nullptr);
		}
		// ********** END MONSTER ROOM **********
		
		else if (currentRoom->isExit())
		{
		cout << endl << "===============================================================================================" << endl;
		cout << endl << "After defeating the final monster, you see your party members' torches, you found them!" << endl;
		}

		else
		{
		cout << endl << "This room is empty." << endl << endl;
		}
		

	} // End while loop

	
	if (currentRoom->isExit())
	{
		cout << "You have won! Game Over" << endl;
	}
	else
		cout << "You were slain. Game Over" << endl;
}

Game::Game()
{
	creatMap();
}

void Game::displayMap()
{
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Old Shrine") << "]";
	cout << "----";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Dead Gardens") << "]";
	cout << "----";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Empty Room 1") << "]";
	cout << endl << "               |" << endl;

	cout << "       ";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Start Room") << "]";
	cout << "----";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Old Courtyard") << "]";
	cout << "----";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Ancient Laboratory") << "]";
	cout << "----";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Armory") << "]";
	cout << endl << "               |" << endl;

	cout << "              ";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Empty Room 2") << "]";
	cout << "----";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Summoning Room") << "]";
	cout << "----";
	cout << "[" << isCurrentRoom(currentRoom->getName() == "Exit Room") << "]";
	cout << endl;

}

char isCurrentRoom(bool r)
{
	if (r == 1)
		return 'X';
	else
		return '_';
}