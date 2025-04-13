#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
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

class Enemy {
    string name;
    string description;
    float attackPower;
    float healthPoints;

public:
    Enemy() {}
    Enemy(string tempName,string tempDescription, float tempAttackPower, float tempHealthPoints) {
        name = tempName;
        description = tempDescription;
        attackPower = tempAttackPower;
        healthPoints = tempHealthPoints;
    }

    string getName() {
        return name;
    }
    string getDescription() {
        return description;
    }
    float getAttackPower() {
        return attackPower;
    }
    float getHealthPoints() {
        return healthPoints;
    }

    void setName(string tempName) {
        name = tempName;
    }
    void setDescription(string tempDescription) {
        description = tempDescription;
    }
    void setAttackPower(float tempAttackPower) {
        attackPower = tempAttackPower;
    }
    void setHealthPoints(float tempHealthPoints) {
        healthPoints = tempHealthPoints;
    }
};

class EnemyVector {
    vector<Enemy> enemies;

public:
    Enemy* getVectorItem() {
        return enemies.data();
    }
    int getSize() {
        return enemies.size();
    }
    void setVector(Enemy tempEnemy) {
        enemies.push_back(tempEnemy);
    }

    void displayEnemyVector() {
        Enemy* eTemp = getVectorItem();
        for(int i = 0; i < getSize(); i++) {
            cout << "Name: " << eTemp->getName() << endl;
            cout << "Description: " << eTemp->getDescription() << endl;
            cout << "Attack Power: " << eTemp->getAttackPower() << endl;
            cout << "Health Points: " << eTemp->getHealthPoints() << endl;
            eTemp++;
        }
    }
};

bool fightEnemy(player &p, string enemyName, string enemyDesc, float enemyAttack, float enemyHealth) {
    cout << "You are fighting a " << enemyName  << endl;
    cout << enemyDesc << endl;

    float playerHP = p.gethealth();

    while(playerHP > 0 && enemyHealth > 0) {
        float playerDamage = p.getstrength() * (1 + (p.getmagic() / 100));
        enemyHealth -= playerDamage;
        cout << "You deal " << playerDamage  << endl;

        if(enemyHealth <= 0) {
            cout << "You defeated the " << enemyName << endl;
            return true;
        }


        playerHP -= enemyAttack;
        cout << "The " << enemyName << " deals " << enemyAttack << " damage to you!" << endl;

        if(playerHP <= 0) {
            cout << "You were defeated by the " << enemyName  << endl;
            cout<<"game over"<< endl;
            p.sethealth(playerHP);
            return false;
        }

        cout << "Your health: " << playerHP <<"enemy" <<enemyName << "' health: " << enemyHealth << endl;
    }

    p.sethealth(playerHP);
    return false;
}

int main() {

    srand(time(NULL));

    PlayerVector s1;
    s1.readFile();
    s1.displayPlayersVector();

    EnemyVector enemySystem;
    Enemy darkWolf("Dark Wolf", "A wolf that can hide in shadows", 15.0, 50.0);
    Enemy dragon("Dragon", "A dragon only choose one can beat", 30.0, 200.0);
    Enemy demon("Demon", "A mysterious creature from another realm", 25.0, 100.0);
    Enemy goblin("Goblin", "A small goblin", 10.0, 30.0);
    Enemy bandit("Bandit", "A human who preys on people", 20.0, 75.0);

    enemySystem.setVector(darkWolf);
    enemySystem.setVector(dragon);
    enemySystem.setVector(demon);
    enemySystem.setVector(goblin);
    enemySystem.setVector(bandit);

    WeatherVector weatherSystem;
    weatherSystem.loadWeatherFromFile("weather.txt");

    int choice;
    int strength = 10, health = 100, magic = 10;
    int gameState = 0;

    cout << "Welcome to play brave adventure. \nWhen health less than 0, you die. \nPress 1 to start the game" << endl;
    cin >> choice;

    if (choice == 1) {
        gameState = 1;

        while (health > 0) {

            if (gameState > 1) {
                if (rand() % 100 < 25) {
                    Weather currentWeather = weatherSystem.getRandomWeather();
                    cout << "\nWeather Today " << endl;
                    currentWeather.displayWeather();

                    player currentPlayer(strength, health, magic);
                    currentWeather.applyWeatherEffect(currentPlayer);

                    strength = currentPlayer.getstrength();
                    health = currentPlayer.gethealth();
                    magic = currentPlayer.getmagic();

                    cout << "After weather effects your status" << endl;
                    status(strength, health, magic);
                }
            }

            switch (gameState) {
                case 1:
                    cout << "You turn to 18 today, now you find priest to become \n1 Swordsman \n2 Magician" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "You choose to become a Swordsman" << endl;
                    gameState = 2;
                }
                else if (choice == 2) {
                    cout << "You choose to become a Magician" << endl;
                    gameState = 10;
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }
                break;

                case 2:
                    cout << "now what should i do?\n1 Go out adventure \n2 keep training(10 years)" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "you find a dark area " << endl;
                    gameState = 3;
                }
                else if (choice == 2) {
                    cout << "you gain the 20 strength and 30 health " << endl;
                    strength += 20;
                    health += 30;
                    status(strength, health, magic);
                    gameState = 7;
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }
                break;

                case 3:
                    cout << "in dark area you met the dark wolf, this wolf can hide in the shadow. \n1 run away \n2 fight" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "you try to run away,your back got hit, you injured  " << endl;
                    health -= 20;
                    strength -= 2;
                    status(strength, health, magic);
                    gameState = 4;
                }
                else if (choice == 2) {
                    player currentPlayer(strength, health, magic);
                    bool victory = fightEnemy(currentPlayer, "Dark Wolf", "A wolf that can hide in shadows", 15.0, 50.0);

                    health = currentPlayer.gethealth();

                    if (victory) {
                        cout << "you beat the dark wolf and got dark material" << endl;
                        status(strength, health, magic);
                        gameState = 6;
                    } else {
                        if (health > 0) {
                            cout << "you lose, but lucky you run away" << endl;
                            health -= 10;
                            status(strength, health, magic);
                            gameState = 4;
                        } else {
                            cout << "please enter number 1 or 2" << endl;
                        }
                    }
                }
                break;

                case 4:
                    cout << "you are injured \n1 should i go hospital \n2 ignore it   " << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "you stay hospital 5 mouths you feel good now. " << endl;
                    health += 10;
                    status(strength, health, magic);
                    gameState = 5;
                }
                else if (choice == 2) {
                    cout << "The injury more serious than you expected. \nYou die \n---Contempt Ending---" << endl;
                    health = 0;
                }
                break;

                case 5:
                    cout << "After 5 months, a mysterious creature comes to your room, saying he can fulfill your wishes. \n1make a wish \n2you dont believe him " << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "He fulfills your wish, but he is a demon. The price of a wish was health, and now you only get 1 day to live. \n---Greedy Ending---" << endl;
                    health = 0;
                }
                else if (choice == 2) {
                    player currentPlayer(strength, health, magic);
                    bool victory = fightEnemy(currentPlayer, "Demon", "A mysterious creature from another realm", 25.0, 100.0);

                    health = currentPlayer.gethealth();

                    if (victory) {
                        cout << "You find out he is demon, he try to attack you, you beat him. The villagers find out that you defeated the mysterious creature, which is a demon, and you become a hero. \n---Hero Ending---" << endl;
                        health = 0;
                    } else {
                        cout << "You find out he is demon, he try to attack you, but you are too weak to avoid his attack. \nYou die. \n---Unlucky Ending---" << endl;
                        health = 0;
                    }
                }
                break;

                case 6:
                    cout << "You got dark material, go to weapon shop. make a? \n1 swords \n2 Armor " << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "you get a sword" << endl;
                    strength += 5;
                    status(strength, health, magic);
                    gameState = 8;
                }
                else if (choice == 2) {
                    cout << "you get a armor" << endl;
                    health += 15;
                    status(strength, health, magic);
                    gameState = 8;
                }
                break;

                case 7:
                    cout << "after 10 years training you turn to first-class swordsman. what should i do now ?  \n1 show your power to people \n2 keep training(20 years)" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "challenge swordsman ranking" << endl;
                    gameState = 9;
                }
                else if (choice == 2) {
                    cout << "keep training 20 years " << endl;
                    strength += 100;
                    health += 100;
                    status(strength, health, magic);
                    gameState = 9;
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }
                break;

                case 8:
                    cout << "One day, a dragon comes to town. \n1 Run away \n2 Participate in the fight with the Dragon" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "You survive. But after two days, you hear the whole town got burned. You feel very self-blaming and get depressed, then you suicide. \n---Coward Ending---" << endl;
                    health = 0;
                }
                else if (choice == 2) {
                    player currentPlayer(strength, health, magic);
                    bool victory = fightEnemy(currentPlayer, "Dragon", "A dragon only choose one can beat", 30.0, 200.0);

                    health = currentPlayer.gethealth();

                    if (victory) {
                        cout << "You bravely fight the dragon, after a hard battle, you victorious! \n---Hero Ending---." << endl;
                        health = 0;
                    } else {
                        cout << "You attempt to fight the dragon, but you are too weak. \n---Sad Ending---." << endl;
                        health = 0;
                    }
                }
                break;

                case 9:
                    cout << "you believe you are the best swordsman on the words you challenge the strongest swordsman " << endl;

                if (strength > 25) {
                    cout << "your are the strongest now\n---strongest Ending--- " << endl;
                    health = 0;
                }
                else {
                    cout << "you lose, you whole life try to become to best but you still cant reach that level \n---Normal Ending--- " << endl;
                    health = 0;
                }
                break;

                case 10:
                    cout << "your talent on magic is bad(fall 8 strength) \n1 exploring magic area(5 years) \n2 give up change to swordsmam  " << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "you keep exploring magic areas, yor magic still the same" << endl;
                    gameState = 11;
                }
                else if (choice == 2) {
                    cout << "you find priest change career, but he said when you already chose the career can't be change. \nIn rest of the year you done nothing until to dead \n---Lazy Ending---  " << endl;
                    health = 0;
                }
                else {
                    cout << "please enter number 1 or 2" << endl;
                }
                break;

                case 11:
                    cout << "you decided to \n1 get out \n2 keep training(20 years)" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "you join a Adventure team " << endl;
                    gameState = 12;
                }
                else if (choice == 2) {
                    cout << "you realise you almost hit the magic truth " << endl;
                    magic += 70;
                    status(strength, health, magic);
                    gameState = 14;
                }
                break;

                case 12:
                    cout << "The team in 5 year turn to A class, they deiced you be a leader \n1 accept \n2 reject" << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "You accept the leader " << endl;
                    gameState = 13;
                }
                else if (choice == 2) {
                    cout << "You reject the leader " << endl;
                    health = 0;
                }
                break;

                case 13:
                    cout << "You accept the leader, now have a option to become s tier s should we join the mission \n1 join \n2 reject  " << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "your team go to dungeon  " << endl;

                    int enemyType = rand() % 100;
                    string enemyName, enemyDesc;
                    float enemyAttack, enemyHealth;

                    if (enemyType == 0) {
                        enemyName = "Dark Elf";
                        enemyDesc = "A powerful magic user from the underworld";
                        enemyAttack = 25.0;
                        enemyHealth = 120.0;
                    } else if (enemyType == 1) {
                        enemyName = " Golem";
                        enemyDesc = "A massive stone creature guarding the dungeon";
                        enemyAttack = 35.0;
                        enemyHealth = 180.0;
                    } else {
                        enemyName = "Cave Troll";
                        enemyDesc = "A brutish creature with regenerative abilities";
                        enemyAttack = 30.0;
                        enemyHealth = 150.0;
                    }

                    player currentPlayer(strength, health, magic);
                    bool victory = fightEnemy(currentPlayer, enemyName, enemyDesc, enemyAttack, enemyHealth);

                    if (victory) {
                        cout << "Your team defeats the " << enemyName << " and becomes S-tier! \nhappy Ending" << endl;
                    } else {
                        cout << "Your team is defeated by the " << enemyName << ". \nUnfortunate Ending" << endl;
                    }
                    health = 0;
                }
                else if (choice == 2) {
                    cout << "you reject, cause you dont fill you guys ready yet \nthe party until you retired didn't do anything suprise \n---Normal Ending--- " << endl;
                    health = 0;
                }
                break;

                case 14:
                    cout << "After training (20 years), should i \n1 get out \n2 keep training(30 years) " << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "You a one of the best magician, a lot party try to invite you to join.  " << endl;
                    health = 0;
                }
                else if (choice == 2) {
                    cout << "you find out the true meaning of magic \n---greatest magician Ending---" << endl;
                    magic += 300;
                    status(strength, health, magic);
                    health = 0;
                }
                break;
            }



            if (health <= 0) {
                cout << "\n---Game Over---" << endl;
            }
        }
    }

    return 0;
}