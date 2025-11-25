#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <random>
#include <ctime>

int main() {
    std::vector <std::string> Ideas =
    {
"Painting",
"Disney draw along",
"Clay",
"Album listening and ranking",
"Scrap booking",
"Bucket list",
"Trivia night",
"Long walk",
"Origami tutorial",
"Write letters to each other in the future",
"rock painting",
"paint glasses",
"Name That Song!"
    };


    std::srand(std::time(0));
    int randomIndex = std::rand() % Ideas.size();
    std::string Winner = Ideas[randomIndex];
    std::cout << Winner << std::endl;
    return 0;
}
