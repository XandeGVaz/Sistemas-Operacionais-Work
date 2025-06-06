#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "login.hpp"
#include "exit.hpp"
#include "fileManipulation.hpp"
#include "gameFlux.hpp"

/*================================ Variáveis Globais ======================================================*/
// Tela de jogo
sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "LOGIN", /*sf::Style::Titlebar*/ sf::Style::Fullscreen);

// Nome de jogador
std::string PlayerName;

// Score do jogador
int Score = 0;

// Fonte de escrita
sf::Font PrincipalFont;
sf::Font DejaVuSans;


/*=============================== Programa Princippal ======================================================*/

int main(){
    
    // Definição das propriedades da tela principal
    Window.setFramerateLimit(FRAME_RATE); 
    
    // Carregamento da fonte principal de texto
    PrincipalFont.loadFromFile("./assets/fonts/font.otf");
    DejaVuSans.loadFromFile("./assets/fonts/NotoSans-Bold.ttf");

    // Login do Jogador
    PlayerName = catchPlayerName(Window, PrincipalFont);
    if(!playGame(Window)){ // Caso não deseje jogar, fecha janela do programa
        Window.close();
        return 0;
    }

    // Loop de jogo
    while(1){
        
        // Funções referentes às perguntas do quis
        if(!summonContext(Window, DejaVuSans, 1)){
            break;
        }

        if(exitGame(Window, Score, PlayerName, PrincipalFont)){
            break; // Sai do loop de jogo e o programa termina
        }
        
        // Zera score do jogador para que ele jogue novamente
        Score = 0;
    }

    return 0;
}