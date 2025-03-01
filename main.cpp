#include<iostream>
#include<string>
using namespace std;

void status(int strength, int health, int magic) { //show status
    cout <<"strength: "<<strength << "\nhealth:" <<health << "\nmagic:" << magic<<endl;
}

int main() {
    int choice;
    int strength =10 , health =100, magic= 10; // player status

    if (health <= 0) {
        cout <<"You are dead \ngame over"<<endl;
        return 0;
    }

    cout << "Welcome to play brave adventure. \nIn this game all you decision will affect to the story. \npress 1 to start the game" <<endl;
    cin >> choice;
    if (choice == 1) { //swordman
        cout << "now what should i do?\n1 Go out adventure \n2 keep training(10 years)"<<endl;
        cin >> choice;
        if (choice == 1) { // Go out adventure
            cout << "you find a dark area " << endl;
        }
        else if (choice == 2) { //keep training
            cout << "you gain the 20 strength and 30 health " << endl;
        }
        else {
            cout << "please enter number 1 or 2" << endl;
    }
        }
    if (choice == 1) //swordman
        cout << "should i take a risk \n1 yes \n2 no"<< endl;
    cin >> choice;
    if (choice == 1) { //yes
        cout << "you met the dark wolf" << endl;
    }
    else if (choice == 2) { //no
        cout << "you decided pass away"<<endl;
    }
    else {
        cout << "please enter number 1 or 2" << endl;
    }
    if (choice == 2) { //magic
        cout << "your talent on magic is bad(fall 8 strength) \n1 keep training(10years) \n2 give up change to swordsmam  "<<endl;
        cin >> choice;
        if (choice == 1) { //magic
            cout << "you keep exploring magic area  " << endl;
        }
        else if (choice == 2) { //magic bad ending
            cout << "you find priest change career, unfortunately when you already chose the career can't be change. \nIn rest of the year you done nothing \nLazy Ending  " << endl;
        }
    }

    }






