#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include <ctime>
void Picker ()
{
    std::vector <std::string> Ideas =
{
"time",
"year",
"people",
"way",
"day",
"man",
"thing",
"woman",
"life",
"child",
"world",
"school",
"state",
"family",
"student",
"group",
"country",
"problem",
"hand",
"part",
"place",
"case",
"week",
"company",
"system",
"program",
"question",
"work",
"government",
"number",
"night",
"point",
"home",
"water",
"room",
"mother",
"area",
"money",
"story",
"fact",
"month",
"lot",
"right",
"study",
"book",
"eye",
"job",
"word",
"business",
"issue",
"side",
"kind",
"head",
"house",
"service",
"friend",
"father",
"power",
"hour",
"game",
"line",
"end",
"member",
"law",
"car",
"city",
"community",
"name",
"president",
"team",
"minute",
"idea",
"kid",
"body",
"information",
"back",
"parent",
"face",
"others",
"level",
"office",
"door",
"health",
"person",
"art",
"war",
"history",
"party",
"result",
"change",
"morning",
"reason",
"research",
"girl",
"guy",
"moment",
"air",
"teacher",
"force",
"education"
    };

    std::string Winner;
    static std::string picked = ""; // must be static for this to work, it must persist
    std::srand(std::time(0));
    int randomIndex = std::rand() % Ideas.size();
    Winner = Ideas[randomIndex];

    if (Winner == picked)
    {
        randomIndex = std::rand() % Ideas.size();
        Winner = Ideas[randomIndex];
        
    }       
    std::cout << Winner << std::endl;
    picked = Winner;
}
int main() {

    Picker(); // calls picker, picker randomly selects a word from the list
    std::cout << "Press enter if you want another song!" << std::endl;
    std::string input;
    std::getline(std::cin, input); // checks for enter pressed 
    if (input.empty())
    {
        main();

    }
    else // if anything else is pressed then end program
    {
        return 0;
    }
    return 0;
}