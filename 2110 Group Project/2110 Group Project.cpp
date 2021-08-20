// 2110 Group Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Game.h"

int main()
{

    //Application header
    cout << "\t\t\t\t\tThe Journey" << endl << endl;
    cout << "Created by: Nicholas Arsenault, Kamren Deddeh, Arben Gacaferi, Matthew Meyer, and Michael Tocco" << endl;
    cout << "===============================================================================================" << endl << endl;

    cout << "You and your party were exploring ancient ruins when monsters attacked, while fighting you were separated." << endl;
    cout << "You are currently recuperating in a small empty room." << endl;
    cout << "The monsters managed to hit you multiple times leaving you at 10 HP." << endl;
    cout << "Your armor is damaged but still has a DP of 10. " << endl;
    cout << "Your sword is still intact allowing you to deal 10 damage to monsters." << endl;
    cout << "You were already beaten back into a corner so you know running wont always help, you can only retreat once." << endl;
    cout << "While trying to come up with a plan to get back to your party, you find an old map of the ruins." << endl;
    cout << "With the map in hand, you decide to find your way out..." << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl << endl;

    Game game;
    game.run();

}


