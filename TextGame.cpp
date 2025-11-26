#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include<Windows.h>
//#include <unistd.h>
#include <ctime>
#include <random>
using namespace std;
void enemy();
// enemy values
int Ehp, Estre = 5, Elvl = 1, Espeed;
//player values
void player();
void stats();
bool alive = true;
int PL = 1, Pstre, Pstam, Pspeed, SP = 10, Php = 100, Newstat;
std::string PN, answer, Batanswer, Pstats;

void battle();
void fight();
void win();

void fight()
{
    if (Pstam != 0)
    {

        Pstam = Pstam - 1;
        while (Php > 0 && Ehp > 0)
        {
            if (Pspeed >= Espeed)
            {
                cout << "you hit first! you did: " << Pstre << endl;
                Ehp = Ehp - Pstre;
                cout << Ehp << " health remaining." << endl;
                cout << "the enemy attacks you! he does:" << Estre;
                Php = Php - Estre;
                cout << "You have: " << Php << "HP remaining" << endl;
                Sleep(100);
            }
            else
            {
                cout << "the enemy attacks you! he does:" << Estre;
                Php = Php - Estre;
                cout << "You have: " << Php << "HP remaining" << endl;
                cout << "you hit next! you did: " << Pstre << endl;
                Ehp = Ehp - Pstre;
                Sleep(100);
            }
        }
        if (Ehp <= 0)
        {
            cout << "You killed your enemy" << endl;
            Sleep(200);
            win();

        }
        else if (Php <= 0)
        {
            cout << "You died" << endl;
            alive = false;
        }
    }
    else
        {
            cout << "You dont have enough stamina. you need to make sure you have a stamina before each fight" << endl;
        }

}
void battle()
{
    cout << "-----------\n Your enemy's level is: " << Elvl << endl;

        cout << "you encountered an emeny" << "his stats are" << std::endl;
        Sleep(10);
        cout << Ehp << " hp " << Estre << " strength " << std::endl;
        Sleep(10);
        cout << "do you want to run or fight?" << endl;
        cin >> Batanswer;
        if (Batanswer == "run")
        {
            if (Pspeed < Espeed)
            {
                cout << "You tried to run but your enemy is faster than you" << endl << "the enemy hits for:" << Estre << "damage!";
                Php = Php - Estre;
                cout << "remaining HP" << Php;
                battle();
            }
            else
            {
                cout << "you escaped this battle"<< endl;
                battle();
            }
        }
        else if (Batanswer == "fight")
        {
            fight();
            

        }
        else
        {
            cout << "You can only fight or run!" << endl;
        };

       
    

}
void win()
{
    cout << "for killing your enemy your health ia fully restored and you have 10 new skill points!" << endl;
    Php = 100;
    SP = 10;
    Elvl = Elvl + 1;
    Espeed = Espeed + 1;
    stats();
    enemy();
    battle();
}
void enemy() {
    //int min = 10;
    //int max = 100;
    //int range = max - min + 1;
    //another way for randomised numbers
    //int Ehp = rand() % range + min;

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int>distribution(1, 55);
    Ehp = distribution(rng);
    /*if(Elvl == 2)
     {
      Ehp = Ehp*2;
      Estre = Estre * 2;
     }
     else if(Elvl == 3)
     {
      Ehp =Ehp*3;
      Estre = Estre*3;
     }
     else
     {
         Elvl= 1;
     };*/

    int i = Elvl;
    
        Ehp = Ehp * i;
        if (Espeed > 1)
        {
            Espeed = Espeed + 1;
        }
        Estre = Ehp / 2;
   // cout << Ehp << endl;
}

void player()
{

    std::cout << "what is your players name? ", std::cin >> PN;
    std::cout << PN << std::endl;
    Sleep(20);

    stats();


};
void stats()
{
    std::cout << "pick your character trates!\n" << "you have 10 skill points \n" << "strength: " << std::endl, std::cin >> Newstat, std::cout << " ";
    Pstre = Newstat + Pstre;
    SP = SP - Newstat;

    Sleep(20);
    std::cout << SP << " skill points remaining! \n";

    if (SP > 0)
    {
        std::cout << "Stamina : " << std::endl, std::cin >> Newstat;
        Pstam = Newstat + Pstam;
        SP = SP - Newstat;
        Sleep(20);
        std::cout << SP << " Skill points remaining \n";

    }
    else
    {
        cout << "you spent all your points on strength and cant even move, you lose\n"<< endl;

    };

    if (SP > 0)
    {

        std::cout << "speed :", std::cin >> Newstat;
        Pspeed = Newstat + Pspeed;
        SP = SP - Newstat;

    }
    else
    {
        Pspeed = 0;
        std::cout << "You spent all your skill points! \n";
        Sleep(10);
        std::cout << "Your skills are :\n"
            << "strength: ", std::cout << Pstre << "\n" <<
            "stamina: ", std::cout << Pstam << "\n" <<
            "speed: ", std::cout << Pspeed << "\n";

    };

    if (SP > 0)
    {
        std::cout << "You need to spend all your skill points!" << "do you want put your remaining points in strength, stamina or speed?";
        std::cin >> answer;

        if (answer == "strength")
        {
            Pstre = Pstre + SP;
        }
        else if (answer == "stamina")
        {
            Pstam = Pstam + SP;
        }
        else if (answer == "speed")
        {
            Pspeed = Pspeed + SP;
        }
        else
        {

        }
    };




    std::cout << "You spent all your skill points! \n";
    std::cout << "Your skills are :\n"
        << "strength: ", std::cout << Pstre << "\n" <<
        "stamina: ", std::cout << Pstam << "\n" <<
        "speed: ", std::cout << Pspeed << "\n";
}

int main()
{
    while(alive = true)
    {
        player();
        enemy();
        battle();
    
    }
    return(0);
    //Elvl = Elvl + 1;


    return 0;
}
