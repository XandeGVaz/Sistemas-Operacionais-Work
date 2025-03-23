#include "arq1.hpp"

std::string catchPlayerName(){

    // Variáveis para captura do nome do jogador
    std::string playerName;
  
    // Título de exibição da janela para usuário digitar o nome
    sf::Text title;
    title.setString("NOME DO Jogador");
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(48);
    title.setPosition(500, 200);
  
    // Texto de exibição do nome do jogador até então digitado
    sf::Text textName;
    textName.setFillColor(sf::Color::White);
    textName.setCharacterSize(24);
    textName.setPosition(SCREEN_WIDTH / 2, 350); // posição do texto na tela
  
    // Retânqulo para exibição do nome do jogador
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(2);
    rect.setSize(sf::Vector2f(400, 50));
    rect.setPosition(450, 330);
  
    // Configuração da fonte do texto
    sf::Font font;
    font.loadFromFile("./assets/fonts/font.otf");
    textName.setFont(font);
    title.setFont(font);
  
    // Criação da janeal para captura do nome do jogador
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "LOGIN", sf::Style::Titlebar);
    window.setFramerateLimit(FRAME_RATE); 
  
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
          
          /* Se o caractere adicionado for alfanumérico, diferente de espaço (" ") e 
          *a string for menor que 30 caracteres, adiciona o caractere à string
          */
          else if(event.text.unicode < 128 &&  event.text.unicode != 32 && playerName.size() < 30){
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
      window.draw(title);   // Desenha o título da janela
      window.draw(rect);    // Desenha o retângulo para exibição do nome
      window.draw(textName);// Desenha o nome digitado na tela
      window.display();     // Atualiza a tela
  
    }
  
    // Retorna o nome do jogador
    return playerName; 
  }