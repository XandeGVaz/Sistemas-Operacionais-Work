#include "login.hpp"

std::string catchPlayerName(sf::RenderWindow &window, sf::Font &font){

    // Variáveis para captura do nome do jogador
    std::string playerName;

    // Imagem de fundo da tela de captura de nome
    sf::Image image;
    if(! image.loadFromFile("./assets/images/game/catchPlayerName.png"))
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
  
    // Enquanto a janela estiver aberta, digitamos captura-se o nome do jogador
    while(window.isOpen()){
  
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
  
        // Caso o evento seja de apertar a tecla enter, fecha a janela
        if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
          window.close();
  
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
  
    // Retorna o nome do jogador
    return playerName; 
  }