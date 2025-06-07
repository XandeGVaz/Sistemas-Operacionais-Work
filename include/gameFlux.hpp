#ifndef GAME_FLUX_HPP
#define GAME_FLUX_HPP

#include "globals.hpp"
#include "fileManipulation.hpp"

typedef enum{
    ERROR = 0U,
    A ,
    B ,
    C ,
    D
}Answer_t;

int gameFlux(sf::RenderWindow &window, sf::Font &font, int* score, Answer_t* expected);
bool summonContext(sf::RenderWindow &window, sf::Font &font, int n);
bool summonReview(sf::RenderWindow &window, sf::Font &font, int n, bool correct);
//bool summonQuestion(sf::RenderWindow &window, sf::Font &font, int n, int* answer);

#endif