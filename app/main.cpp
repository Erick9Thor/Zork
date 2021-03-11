#include <iostream>
#include "../include/World.h"

using namespace std;

int main() {

    string userInput;

    cout << "Welcome to MyZork!\n";
    cout << "----------------\n";

    cout << "What's your name? ";
    getline(cin, userInput);
    cout << userInput << "!!!, also the name of the hero of this adventure :D" << endl;

    World world(userInput);

    while (!world.IsGameOver()) {

        getline(cin, userInput);

        // Split string to words
        vector<string> words = Globals::split(userInput);

        world.ReadInput(words);

    }

    return 0;
}