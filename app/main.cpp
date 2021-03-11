#include <iostream>
#include "../include/World.h"

#define WHITE_ "\033[1;36m"
#define _WHITE "\033[0m"

using namespace std;

int main() {

    string userInput;

    cout << WHITE_ "Welcome to MyZork!\n" _WHITE;
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