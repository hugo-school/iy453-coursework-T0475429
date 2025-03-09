#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


class player{
     float strength;
     float health;
     float magic;
public:
    player(){
}

    player(float tempstrength,float temphealth,float tempmagic){
        strength=tempstrength;
        health=temphealth;
        magic=tempmagic;
}

    float getstrength(){
        return strength;
}
    float gethealth(){
        return health;
}
    float getmagic(){
        return magic;
}
    void setstrength(float tempstrength){
        strength=tempstrength;
}
    void sethealth(float temphealth){
        health=temphealth;
}
    void setmagic(float tempmagic){
        magic=tempmagic;
}
    void display() {
        cout<<"strength:"<<strength<<endl;
        cout<<"health:"<<health<<endl;
        cout<<"magic:"<<magic<<endl;
    }
};

void readFile() {
    vector<player> tempplayers;
    string tempLine;
    string tempWord;
    float tempStrength;
    float tempHealth;
    float tempMagic;

    fstream fs;
    fs.open("playerRead.txt");
    if(fs.is_open()) {
        cout<<"File opened"<<endl;

        while (getline(fs, tempLine)) {
            stringstream ss(tempLine);
            int counter = 0;
            while (getline(ss>>ws ,tempWord, ',')) {
                if (counter == 0) {
                    tempStrength = stof(tempWord);
                }
                if (counter == 1) {
                    tempHealth = stof(tempWord);
                }
                if (counter == 2) {
                    tempMagic = stof(tempWord);
                }
                counter++;
            }
            player tempPlayer(tempStrength, tempHealth, tempMagic);
            setVector(tempPlayer);
        }
        fs.close();
    }
    else {
        cout << "File not found" << endl;

        }
    };
int main() {
    PlayerVector s1;
    s1.readFile();
    s1.displayers();
    return 0;
}





int main() {
    int choice;
    int strength =10, health=100, magic=10; //status

    cout << "Welcome to play brave adventure. \nWhen health less than 0, you die. \nPress 1 to start the game" <<endl;
    cin >> choice;
    if (choice == 1) {
        //start the game
        cout << "You turn to 18 today, now you find priest to become \n1 Swordsman \n2 Magician" << endl;
        cin >> choice;

        while (health>0) {
            if (choice == 1) { //swordsman 1 //number mean the story line
                cout << "You choose to become a Swordsman" << endl;
            }
            else if (choice == 2) { //magic 1
                cout << "You choose to become a Magician" << endl;
            }
            else {
                cout << "please enter number 1 or 2" << endl;
            }

            if (choice == 1) {
                cout << "now what should i do?\n1 Go out adventure \n2 keep training(10 years)"<<endl;
                cin >> choice;
                if (choice == 1) {// swordsman 3
                    cout << "you find a dark area " << endl;
                }
                else if (choice == 2) { //swordsman 4
                    cout << "you gain the 20 strength and 30 health " << endl;
                    strength += 20;
                    health += 30;
                    status(strength, health, magic);
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }

            if (choice == 1) {
                cout<<" in dark area you met the dark wolf, this wolf can hide in the shadow. \n1 run away \n2 fight"<<endl;
                cin >> choice;
                if (choice == 1) {// swordsman5
                    cout<< "you try to run away,your back got hit, you injured  " << endl;
                    health -= 20;
                    strength -= 2;
                    status(strength, health, magic);
                }
                else if (choice == 2) {// swordsman 6
                    cout<< "you bet the dark wolf (Minor injuries), you got dark material   " << endl;
                    health -= 8;
                    status(strength, health, magic);
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }
            }

            if (choice == 2) {
                cout<< "after 10 years training you turn to first-class swordsman. what should i do now ?  \n1 show your power to people \n2 keep training(20 years)" << endl;
                cin >> choice;
                if (choice == 1) {
                    cout<< "challenge swordsman ranking" << endl;
                }
                else if (choice == 2) {
                    cout<< "keep training 20 years " << endl;
                    strength += 100;
                    health += 100;
                    status(strength, health, magic);
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }
            }

            if (choice == 1) {
                cout << "after run away dark area, you go to town rest 2 years, but cause curse  " << endl;
            }



            }else if (choice == 2) { //magic 1
                cout << "your talent on magic is bad(fall 8 strength) \n1 exploring magic area(5 years) \n2 give up change to swordsmam  "<<endl;
                cin >> choice;
                if (choice == 1) { //magic 2
                    cout << "you keep exploring magic areas, yor magic still the same" << endl;
                }
                else if (choice == 2) {// magic 3
                    cout << "you find priest change career, but he said when you already chose the career can't be change. \nIn rest of the year you done nothing until to dead \nLazy Ending  " << endl;
                    health= 0;
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }
            }
            if (choice ==1){ //magic 2
                cout << "you decided to \n1 get out \n2 keep training(20 years)" << endl;
                cin >> choice;
                if (choice == 1) {//magic 4
                    cout << "you join a Adventure team "<< endl;
                }
                else if (choice == 2) { //magic 5
                    cout <<"you realise you almost hit the magic truth " << endl;
                    magic += 70;
                    status(strength, health, magic);
                }

            }
            if (health <= 0) {
                cout << "\nGame Over" << endl;
                health = 0;

            }
        }
    }
return 0;
}





