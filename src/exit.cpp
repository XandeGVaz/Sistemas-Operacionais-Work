#include "exit.hpp"

// Função auxiliar de visualização do score do jogador
//    Parâmetros: - window : janela de jogo
//    Saída: booleano true caso o usuário tenha escolhido sair do jogo || false caso contrário
bool scoreGame(sf::RenderWindow &window){

  // Estado de decisão
  int state = 0; // 1 - jogar || 2 - não jogar

  // Imagem de fundo da tela de captura de nome
  sf::Image image;
  if(! image.loadFromFile("./assets/images/game/scoreGame/init.png"))
    std::cout << "Erro na leitura de imagem inicial de jogo" << std::endl;
  
  // Textura do fundo da tela de jogo
  sf::Texture texture;
  texture.loadFromImage(image);

  // Sprite da tela de jogo
  sf::Sprite sprite;
  sprite.setTexture(texture);

  window.clear();       // Limpa a tela para atualização do nome digitado
  window.draw(sprite);  // Desenha background da tela (imagem de escolha entre jogar e sair)
  window.display();     // Atualiza a tela
  
  // Variável para verificação de eventos
  sf::Event event;
  
  // Enquanto o usuário não selecionar nenhuma opção
  while(1){

    // Se houver detecção de evento, o mesmo é tratado conforme o estado atual
    while(window.pollEvent(event)){

      switch(state){

        // Carrega nova imagem e atualiza estado
        case 0:
          
          if(event.type == sf::Event::KeyPressed && 
            (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::Up)){
            image.loadFromFile("./assets/images/game/scoreGame/exit.png");
            state = 1;
          }
          
          break;

        // Opção de sair está destacada
        case 1:
          
          // Se apertar down, destaca opção de jogar novamente
          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
            image.loadFromFile("./assets/images/game/scoreGame/play.png");
            state = 2;
          }

          // Se apertar enter, retorna true, pois usuário irá parar de jogar
          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            return true;

          break;
        
        // Opção de jogar está destacada
        case 2:
          
          // Se apertar up, destaca opção de sair do jogo
          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
            image.loadFromFile("./assets/images/game/scoreGame/exit.png");
            state = 1;
          }

          // Se apertar enter, retorna false, pois usuário continuará jogando
          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            return false;

          break;
      }
    }
    
    // Atualiza background que será exibido na tela
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    
    window.clear();       // Limpa a tela para atualização do nome digitado
    window.draw(sprite);  // Desenha background da tela (imagem de escolha entre jogar e sair)
    window.display();     // Atualiza a tela
  }
}

// Função de saída do game
//    Parâmetros: - window : janela de jogo
//    Saída: booleano true caso o usuário tenha escolhido sair do jogo || false caso contrário
bool exitGame(sf::RenderWindow &window){
  return scoreGame(window);
}