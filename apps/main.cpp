#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "login.hpp"
#include "exit.hpp"

/*================================ Variáveis Globais ======================================================*/
// Tela de jogo
sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "LOGIN", /*sf::Style::Titlebar*/ sf::Style::Fullscreen);

// Nome de jogador
std::string PlayerName;

// Score do jogador
int Score = 0;

// Fonte de escrita
sf::Font Font;


/*=============================== Programa Princippal ======================================================*/

int main(){
    
    // Definição das propriedades da tela principal
    Window.setFramerateLimit(FRAME_RATE); 
    
    // Carregamento da fonte principal de texto
    Font.loadFromFile("./assets/fonts/font.otf");

    // Login do Jogador
    PlayerName = catchPlayerName(Window, Font);
    if(!playGame(Window)){ // Caso não deseje jogar, fecha janela do programa
        Window.close();
        return 0;
    }

    // Loop de jogo
    while(1){
        
        // Funções referentes às perguntas do quis
    
        if(exitGame(Window, Score, PlayerName, Font)){
            break; // Sai do loop de jogo e o programa termina
        }
        
        // Zera score do jogador para que ele jogue novamente
        Score = 0;
    }

    return 0;
}