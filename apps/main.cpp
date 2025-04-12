#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "login.hpp"

/*================================ Variáveis Globais ======================================================*/
// Tela de jogo
sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "LOGIN", /*sf::Style::Titlebar*/ sf::Style::Fullscreen);

// Nome de jogador
std::string PlayerName;

// Score do jogador
int Score;


int main(){

    // Definição das propriedades da tela principal
    Window.setFramerateLimit(FRAME_RATE); 

    // Login do Jogador
    PlayerName = catchPlayerName(Window);
    return 0;
}