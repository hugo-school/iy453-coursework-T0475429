#include<iostream>
#include<string>
using namespace std;

int main() {
    int choice;
    cout << "Welcome to play brave adventure. \nIn this game all you decision will affect to the story. \npress 1 to start the game" <<endl;
    cin >> choice;
    if (choice == 1) {
        cout << "you turn to 18 today, now you find priest to become \n1 Swordsman \n2 Magician" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "You choose to become a Swordsman" << endl;
        }
        else if (choice == 2) {
            cout << "You choose to become a Magician" << endl;
        }
        else {
            cout << "please enter number 1 or 2" << endl;
        }
    }
    if (choice == 1) {
        cout << "now what should i do?\n1 Go out adventure \n2 keep training(10 years)"<<endl;
        cin >> choice;
        if (choice == 1) {
            cout << "you find a dark area " << endl;
        }
        else if (choice == 2) {
            cout << "you gain the 20 strength and 30 health " << endl;
        }
        else {
            cout << "please enter number 1 or 2" << endl;
        }
        }
    if (choice == 2) {
        cout << "your talent on magic is bad(fall 8 strength) \n1 keep training(10years) \n2 give up change to swordsmam  "<<endl;
        cin >> choice;
        if (choice == 1) {
            cout << "you find start exploring unkown areas " << endl;
        }
        else if (choice == 2) {
            cout << "you find priest change career, but he said when you already chose the career can't be change. \nIn rest of the year you done nothing until to dead \nLazy Ending  " << endl;
        }
    }
    }




