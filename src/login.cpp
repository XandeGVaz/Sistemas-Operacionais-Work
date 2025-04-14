#include "login.hpp"

// Função de captura de nome do jogador
//    Parâmetros: - window : janela de jgo
//                - font : fonte de texto utilizada
//    Saída: string c++ que contêm nome do jogador
std::string catchPlayerName(sf::RenderWindow &window, sf::Font &font){

    // Variáveis para captura do nome do jogador
    std::string playerName;

    // Imagem de fundo da tela de captura de nome
    sf::Image image;
    if(! image.loadFromFile("./assets/images/game/catchPlayerName/catchPlayerName.png"))
      std::cout << "Erro na leitura de imagem de captura de nome" << std::endl;
    
    // Textura do fundo da tela de jogo
    sf::Texture texture;
    texture.loadFromImage(image);

    // Sprite da tela de jogo
    sf::Sprite sprite;
    sprite.setTexture(texture);
  
    // Texto de exibição do nome do jogador até então digitado
    sf::Text textName;
    textName.setFillColor(sf::Color::White);
    textName.setCharacterSize(32);
    textName.setPosition(SCREEN_WIDTH / 2 + 20, 340); // posição do texto na tela
  
    // Configuração da fonte do texto
    textName.setFont(font);
  
    // Variável para verificação de eventos
    sf::Event event;
  
    // Enquanto usuário não apertar enter, captura-se o nome do jogador
    while(1){
  
      // Caso um evento seja detectado
      while(window.pollEvent(event)){
  
        // Caso o evento seja de fechamento da janela, fecha a janela
        if(event.type == sf::Event::Closed){
          window.close();
        }
  
        // Caso o evento seja de digitação de texto
        if(event.type == sf::Event::TextEntered){
  
          // Se o usuário apertar backspace e o nome não estiver vazio, apaga o último caractere
          if(event.text.unicode == '\b' && !playerName.empty())
            playerName.pop_back();
          
          /* Se o caractere adicionado for alfanumérico, e 
          *a string for menor que 30 caracteres, adiciona o caractere à string
          */
          else if(event.text.unicode < 128 && playerName.size() < 27){
              playerName += event.text.unicode;
          }
        }
  
        // Caso o evento seja de apertar a tecla enter, fecha tela de captura de nome
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
          return playerName;
  
      }
  
      textName.setString(playerName); // Atualiza o texto com o nome digitado
  
      // Centralziação de texto na tela
      sf::FloatRect textNameRect = textName.getLocalBounds(); // armazenar as dimensões do texto
      textName.setOrigin(textNameRect.width/2, textNameRect.height/2); // seta origem no centro do texto
              
      window.clear();       // Limpa a tela para atualização do nome digitado
      window.draw(sprite);  // Desenha background da tela (imagem de captura de nome de jogador)
      window.draw(textName);// Desenha o nome digitado na tela
      window.display();     // Atualiza a tela
  
    }
}

// Função do menu de seleção
//    Parâmetros: - window : janela de jogo
//    Saída: booleano true caso o usuário tenha escolhido jogar o game || false caso contrário
bool playGame(sf::RenderWindow &window){

  // Estado de decisão
  int state = 0; // 1 - jogar || 2 - não jogar

  // Imagem de fundo da tela de captura de nome
  sf::Image image;
  if(! image.loadFromFile("./assets/images/game/playGame/init.png"))
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
            image.loadFromFile("./assets/images/game/playGame/play.png");
            state = 1;
          }
          
          break;

        // Opção de jogar está destacada
        case 1:
          
          // Se apertar down, destaca opção de sair
          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down){
            image.loadFromFile("./assets/images/game/playGame/exit.png");
            state = 2;
          }

          // Se apertar enter, retorna true, pois usuário jogará o game
          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            return true;

          break;
        
        // Opção de sair destacada
        case 2:
          
          // Se apertar up, destaca opção de jogar
          if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
            image.loadFromFile("./assets/images/game/playGame/play.png");
            state = 1;
          }

          // Se apertar enter, retorna false, pois usuário sairá do jogo
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