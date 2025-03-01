#include<iostream>
#include<string>
using namespace std;

void status(int strength, int health, int magic) {
    cout<<"\n player status;"<<endl;\
    cout << "Strength"<< strength<<"\nHealth:"<<health<<"\nMagic"<<magic <<endl;
}

int main() {
    int choice;
    int strength =10, health=100, magic=10; //status

    cout << "Welcome to play brave adventure. \nWhen health less than 0, you die. \nPress 1 to start the game" <<endl;
    cin >> choice;
    if (choice == 1) { //start the game
        cout << "You turn to 18 today, now you find priest to become \n1 Swordsman \n2 Magician" << endl;
        cin >> choice;
        if (choice == 1) { //swordsman
            cout << "You choose to become a Swordsman" << endl;
        }
        else if (choice == 2) { //magic
            cout << "You choose to become a Magician" << endl;
        }
        else {
            cout << "please enter number 1 or 2" << endl;
        }
    }
        if (choice == 1) { //swordsman
            cout << "now what should i do?\n1 Go out adventure \n2 keep training(10 years)"<<endl;
            cin >> choice;
            if (choice == 1) {
                cout << "you find a dark area " << endl;
            }
            else if (choice == 2) { //swordsman
                cout << "you gain the 20 strength and 30 health " << endl;
                strength += 20;
                health += 30;
                status(strength, health, magic);
            }
            else {
                cout << "please enter number 1 or 2" << endl;
            }


        }else if (choice == 2) { //magic
                cout << "your talent on magic is bad(fall 8 strength) \n1 exploring magic area(5 years) \n2 give up change to swordsmam  "<<endl;
                cin >> choice;
                if (choice == 1) { //magic
                    cout << "you keep exploring magic areas, yor magic still same" << endl;
                }
                else if (choice == 2) {
                    cout << "you find priest change career, but he said when you already chose the career can't be change. \nIn rest of the year you done nothing until to dead \nLazy Ending  " << endl;
                }
            else {
                cout << "please enter number 1 or 2" << endl;
            }
        }
    if (choice ==1){ //magic
        cout << "you decided to \n1 get out \n2 keep training(20 years)" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "you join a Adventure team "<< endl;
        }
        else if (choice == 2) { //magic
            cout <<"you realise you almost hit the magic truth " << endl;
            magic += 70;
            status(strength, health, magic);
        }

    }
    if (health <= 0) {
        cout << "your health is less than 0 \n Game Over" << endl;
        return 0;
    }


    }






