#ifndef GAME_FLUX_HPP
#define GAME_FLUX_HPP

#include "globals.hpp"
#include "fileManipulation.hpp"

int gameFlux(sf::RenderWindow &window, sf::Font &font, int* answer, int* expected);
int summonContext(sf::RenderWindow &window, sf::Font &font, int n);
int summonQuestion(sf::RenderWindow &window, sf::Font &font, int n, int* answer);
int summonReview(sf::RenderWindow &window, sf::Font &font, int n, int performance);

#endif