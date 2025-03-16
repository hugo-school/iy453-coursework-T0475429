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
    player():strength(0), health(0), magic(0){}

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

class Weather {
public:
    string type;
    int strengthEffect;
    int healthEffect;
    int magicEffect;

    Weather(string weatherType, int strEffect, int hpEffect, int magEffect) {
        type = weatherType;
        strengthEffect = strEffect;
        healthEffect = hpEffect;
        magicEffect = magEffect;
    }

    void applyWeatherEffect(player &p) {
        p.setstrength(p.getstrength() + strengthEffect);
        p.sethealth(p.gethealth() + healthEffect);
        p.setmagic(p.getmagic() + magicEffect);
    }
    void displayWeather() {
        cout << "Current Weather: " << type << endl;
        cout << "Strength Effect: " << strengthEffect << endl;
        cout << "Health Effect: " << healthEffect << endl;
        cout << "Magic Effect: " << magicEffect << endl;
    }
};

class WeatherVector {
    vector<Weather> tempWeather;

public:
    void loadWeatherFromFile(string filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string type;
            int strength, health, magic;

            getline(ss, type, ',');
            ss >> strength;
            ss.ignore();
            ss >> health;
            ss.ignore();
            ss >> magic;

            Weather weather(type, strength, health, magic);
            tempWeather.push_back(weather);
        }
    }
    Weather getRandomWeather() {
        if (tempWeather.empty()) {
            return Weather("Unknown", 0, 0, 0);
        }
        int index = rand() % tempWeather.size();
        return tempWeather[index];
    }
};

class PlayerVector {
    vector<player> tempplayers;

public:
    void setVector(player& tempPlayer) {
        tempplayers.push_back(tempPlayer);
    }

    void displayPlayersVector() {
        for (int i = 0; i < tempplayers.size(); i++) {
            cout << "Player " << i + 1 << " Info:" << endl;
            tempplayers[i].display();
            cout << endl;
        }
    }

    void readFile() {
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

        }
    };

void status(int strength, int health, int magic) {
    cout<<"strength:"<<strength<<endl;
    cout<<"health:"<<health<<endl;
    cout<<"magic:"<<magic<<endl;
}




    int main() {
    PlayerVector s1;
    s1.readFile();
    s1.displayPlayersVector();


    int choice;
    int strength =10, health=100, magic=10; //status

    cout << "Welcome to play brave adventure. \nWhen health less than 0, you die. \nPress 1 to start the game" <<endl;
    cin >> choice;
    if (choice == 1) {
        //start the game
        cout << "You turn to 18 today, now you find priest to become \n1 Swordsman \n2 Magician" << endl;
        cin >> choice;

        while (health>0) {
            if (choice == 1) { //swordsman
                cout << "You choose to become a Swordsman" << endl;
            }
            else if (choice == 2) { //magic
                cout << "You choose to become a Magician" << endl;
            }
            else {
                cout << "please enter number 1 or 2" << endl;
            }

            if (choice == 1) {//swordsman 1
                cout << "now what should i do?\n1 Go out adventure \n2 keep training(10 years)"<<endl;
                cin >> choice;
                if (choice == 1) {
                    cout << "you find a dark area " << endl;
                }
                else if (choice == 2) {
                    cout << "you gain the 20 strength and 30 health " << endl;
                    strength += 20;
                    health += 30;
                    status(strength, health, magic);
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }

                if (choice == 1) { //swordsman 1 out adventure
                    cout<<" in dark area you met the dark wolf, this wolf can hide in the shadow. \n1 run away \n2 fight"<<endl;
                    cin >> choice;
                    if (choice == 1) {
                        cout<< "you try to run away,your back got hit, you injured  " << endl;
                        health -= 20;
                        strength -= 2;
                        status(strength, health, magic);
                    }
                    else if (choice == 2) {
                        if (health > 100 && strength > 11) {
                            cout<< "you bet the dark wolf (Minor injuries), you got dark material   " << endl;
                            health -= 8;
                            status(strength, health, magic);
                        }
                        else {
                            cout << "you lose, but lucky you run away" << endl;
                            health -= 10;
                            status(strength, health, magic);
                        }
                    }

                    if (choice == 1) {//swordsman 1
                        cout << "you are injured \n1 should i go hospital \n2 ignore it   " << endl;
                        cin >> choice;
                        if (choice == 1) {
                            cout<< "you stay hospital 5 mouths you feel good now. " << endl;
                            health += 10;
                            status(strength, health, magic);
                        }
                        else if (choice == 2) {
                            cout<< "The injury more serious than you expected. \nYou die \n Contempt Ending"<< endl;
                        }
                    }

                    if (choice == 1) {
                        cout << "After 5 months, a mysterious creature comes to your room, saying he can fulfill your wishes. \n1 make a wish \n2 ignore him" << endl;
                        cin >> choice;

                        if (choice == 1) {
                            cout << "He fulfills your wish, but he is a demon. The price of a wish was health, and now you only get 1 day to live. \nGreedy Ending" << endl;
                            health = 0;
                        }
                        else if (choice == 2) {
                            if (health > 110 && strength > 15) {
                                cout << "You don't believe what he said. You try to go away but he starts attacking you. \nYou defeat him. \nThe villagers find out that you defeated the mysterious creature, which is a demon, and you become a hero. \nHero Ending" << endl;
                            }
                        }
                        else {
                            cout << "You don't believe what he said. You try to go away but he starts attacking you. \nYou are too weak to avoid his attack. \nYou die. \nUnlucky Ending" << endl;
                        }
                    }




                    if (choice == 2) { //swordsman 2
                        cout << "You got dark material, go to weapon shop. make a? \n1 swords \n2 Armor " << endl;
                        cin >> choice;
                        if (choice == 1) {
                            cout<< "you get a sword"<<endl;
                            strength += 5;
                        }
                        else if (choice == 2) {
                            cout<< "you get a armor"<<endl;
                            health += 10;
                        }
                    }
                    if (choice == 1) { //swordsman 2
                        cout << "One day, a dragon comes to town. \n1 Run away \n2 Participate in the fight with the Dragon" << endl;
                        cin >> choice;

                        if (choice == 1) {
                            cout << "You survive. But after two days, you hear the whole town got burned. You feel very self-blaming and get depressed, then you suicide. \nCoward Ending" << endl;
                        }
                        else if (choice == 2) {
                            if (health > 110 && strength > 15) {
                                cout << "You bravely fight the dragon, after a hard battle, you victorious! \nHero Ending." << endl;
                            }
                            else {
                                cout << "You attempt to fight the dragon, but you are too weak. \nSad Ending." << endl;
                            }
                        }
                    }




                        if (choice == 2) { //swordsman 2 training
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
                            cout<<"you belive you are the best swordsman on the words you challenge the strengthest swordsman "<<endl;
                            if (strength > 20) {
                                cout<<" your are the strongest now\n strongest Ending "<<endl;
                                health = 0;
                            }
                            else {
                                cout<<"you lose, you whole life try to become to best but you still cant reach that level \nNormal Ending  "<<endl;
                            }
                        }









                    }else if (choice == 2) { //magic
                        cout << "your talent on magic is bad(fall 8 strength) \n1 exploring magic area(5 years) \n2 give up change to swordsmam  "<<endl;
                        cin >> choice;
                        if (choice == 1) {
                            cout << "you keep exploring magic areas, yor magic still the same" << endl;
                        }
                        else if (choice == 2) {
                            cout << "you find priest change career, but he said when you already chose the career can't be change. \nIn rest of the year you done nothing until to dead \nLazy Ending  " << endl;
                            health= 0;
                        }
                        else {
                            cout << "please enter number 1 or 2" << endl;
                        }
                    }
                    if (choice ==1){  //magic
                        cout << "you decided to \n1 get out \n2 keep training(20 years)" << endl;
                        cin >> choice;
                        if (choice == 1) {
                            cout << "you join a Adventure team "<< endl;
                        }
                        else if (choice == 2) {
                            cout <<"you realise you almost hit the magic truth " << endl;
                            magic += 70;
                            status(strength, health, magic);
                        }
                    }


                    if (health <= 0) {
                        cout << "\nGame Over" << endl;
                    }
                }
            }
            return 0;
        }
    }
































