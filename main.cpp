#include<iostream>
#include<string>
using namespace std;

int main() {
    int choice;
    cout << "Welcome to play brave adventure. \nIn this game all you decision will affect to the story. \npress 1 to start the game" <<endl;
    cin >> choice;
    if (choice == 1) {
        cout << "you turn to 18 today, now you become a \n1 Swordsman \n2 Magician" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "You choose to become a Swordsman" << endl;
        }
    }

}

