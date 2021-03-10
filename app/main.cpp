#include <iostream>
#include "../include/World.h"

using namespace std;

int main() {

    string userInput;

    cout << "Welcome to Zork!" << endl;

    cout << "What's your name? ";
    getline(cin, userInput);
    cout << userInput << "!!!, also the name of the hero of this adventure :D" << endl;

    World world(userInput);

    while (!world.IsGameOver()) {

    }
    return 0;
}