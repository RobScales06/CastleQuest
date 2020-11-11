#include <iostream>
#include <map>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

string playerName;
string startInfo;
string commandStr;
string skillClasses[3]={"sword","gunner","magic"};
bool blocked = false;

class Player {
    public:
    string pName = "Hero";
    string pSkill;
    int pHealth = 200;
    string pAttack1 = "Attack";
    int pAttack1Dmg = 1;
    int pAttack1Heal = 0;
    string pAttack2;
    int pAttack2Dmg;
    int pAttack2Heal;
    string pAttack3;
    int pAttack3Dmg;
    int pAttack3Heal;
};

class Enemy {
    public:
    string eName = "Null Monster";
    string eSprite ="            \n"
                    "    (o.o)   \n"
                    "  *|/| |/   \n"
                    "     | |    \n";
    string eSpriteKO ="            \n"
                      "    (x.x)   \n"
                      "    /| |\\   \n"
                      "  *_ | |    \n";
    string eAttack1 = "Scrub";
    int eAttack1Dmg = 2;
    int eAttack1Prob = 80;
    int eDefense = 1;
    int eHealth = 50;
};


void defineSelf(Player& p){
    system("cls");
    cout << "---Start---\n";
    cout << "What is your name? (one word; others will be ignored)\n------\n";
    cin >> p.pName;
    cout << "\n------\n";
    while(true){
        system("cls");
        cout << "What is your skill class?\n";
        for(int i = 0; i < 3; i++){
            cout << skillClasses[i] << "\n";
        }
        cout << "------\n";
        cin >> p.pSkill;
        if(p.pSkill == "sword"||p.pSkill == "gunner"||p.pSkill == "magic"){
            break;
        }
        else{
            system("cls");
            cout << "*****************\n";
            cout << "**Invalid input**\n";
            cout << "*****************\n\n";
            Sleep(500);
        }
    }
    if(p.pSkill==skillClasses[0]){ //sword stats
        p.pHealth = 150;
        p.pAttack1 = "slash";
        p.pAttack1Dmg = 3;
    }
    else if(p.pSkill==skillClasses[1]){ //gunner stats
        p.pHealth = 110;
        p.pAttack1 = "shoot";
        p.pAttack1Dmg = 5;
        p.pAttack1Heal = 0;
    }
    else if(p.pSkill==skillClasses[2]){ //magic stats
        p.pHealth = 900;
        p.pAttack1 = "healhit";
        p.pAttack1Dmg = 2;
        p.pAttack1Heal = 1;
    }
    cout << "\n*So you are " << p.pName << " and your skill is " << p.pSkill << "*\n\n";  
}

void pAtkHandler(Player& p, Enemy& e){
    //Player Turn
    string attack;
    cin >> attack;
    if(attack == p.pAttack1){
        e.eHealth=e.eHealth-p.pAttack1Dmg;
    }
    if(attack == "run"){
        return;
    }
    if(attack == "heal"){
        p.pHealth+=3;
    }
}

void eAtkHandler(Player& p, Enemy& e){
    //Enemy Turn
    srand((int)time(0));
	int i = 0;
    int r = 0;
	while(i++ < 10) {
		r = (rand() % 100) + 1;
		cout << r << " ";
	}
    if(r < e.eAttack1Prob){
        p.pHealth=p.pHealth-e.eAttack1Dmg;
    }
}

void battle(Player& p, Enemy& e){
    system("cls");
    cout << "\n------" << e.eName << "------\n" << "monster" << "   HP: " << e.eHealth << "   Attacks: [" << e.eAttack1 << " " << e.eAttack1Dmg << "]\n------------------\n";
    cout << e.eSprite;
    cout << "\n------" << p.pName << "------\n" << p.pSkill << "   HP: " << p.pHealth << "   Attacks: [" << p.pAttack1 << " " << p.pAttack1Dmg << "]   " << "[heal]" << "\n------------------\n";
    if(e.eHealth <= 0){
        system("cls");
        cout << e.eSpriteKO;
        Sleep(500);
        cout << "\n***Victory!***";
        Sleep(500);
        
        //system("start win.ogg");
        return;
    }
    if(p.pHealth <= 0){
        system("cls");
        cout << "YOU DIED"; 
        return;
    }
    pAtkHandler(p,e);
    eAtkHandler(p,e);
    battle(p,e);
}

int main()
{
    Player player1;
    Enemy enemy1;
    Enemy enemy2;
    Enemy enemy3;

    //Squib
    enemy2.eName = "Squib";
    enemy2.eSprite ="            \n" 
                    "   \'(. _ .)\' \n"
                    "    /// \\\\\\ \n"
                    "    ||| ||| \n";
    enemy2.eSpriteKO ="            \n"  
                      "   *(x o x)* \n"
                      "    /// \\\\\\ \n"
                      "    \\\\\\ /// \n";
    enemy2.eAttack1 = "bubble blow";
    enemy2.eAttack1Dmg = 10;
    enemy2.eAttack1Prob = 30;
    enemy2.eHealth = 80;
    //


    //
    enemy3.eName = "赤いドラゴン";
    enemy3.eSprite ="            \n"
                    ",,,'{  //// \n" 
                    "```\\ \\/// _,\n"
                    "   (  \\___/ \n"
                    " ,,/,,/,\\,\\ \n";
    enemy3.eSpriteKO ="            \n"
                    "            \n" 
                    ",,,-{  //// \n"
                    "```\\&&///   \n"
                    "  ,,),,)\\  \n";
    enemy3.eAttack1 = "...";
    enemy3.eAttack1Dmg = 20;
    enemy3.eAttack1Prob = 10;
    enemy3.eHealth = 80;

    defineSelf(player1);
    battle(player1,enemy1);
    battle(player1,enemy2);
    battle(player1,enemy3);
    Sleep(5000);
    return 0;
}