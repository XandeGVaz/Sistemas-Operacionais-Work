#include "gameFlux.hpp"

// Função de definição do fluxo de jogo
//  Parâmetros: - answer: array de respostas do jogador.
//              - expected: array de respostas esperadas.
//  Retorno:    - 0: Alguma função de invocação apresentou erro. Mensagens de erro serão responsabilidade das respectivas funções.
//              - 1: Funcionamento esperado.

// int gameFlux(sf::RenderWindow &window, sf::Font &font, int* answer, int* expected) {
//     // Inicialização do vetor de respostas
//     answer = new int[N_QUESTIONS];

//     // Variaveis de controle do jogo
//     int performance, action, state = 1;

//     // Loop de jogo
//     while(state <= N_QUESTIONS) {
//         // Invoca a tela de contexto e lida com retornos de erro.
//         if(!summonContext(window, font, state)) return 0;

//         // Invoca a tela de pergunta e armazena a ação do usuario
//         action = summonQuestion(window, font, state, answer);

//         // Delimita as acoes do usuario
//         if(!action) return 0;

//         // Usuario deseja avancar
//         else if(action == 1) {

//             // Compara resposta do usuario com o esperado
//             if(answer[state] == expected[state]) performance = 1;
//             else performance = 0;

//             // Invoca tela de review e lida com retornos de erro.
//             if(!summonReview(window, font, state, performance)) return 0;

//             // Avança o fluxo de jogo para novo estado.
//             state++;
//         }
//     }
//     return 1;
// }

// Função de invocação da tela de contexto.
//  Parâmetros: - n: variável comum à outras funções de invocação. Rege o estado do jogo.
//  Retorno:    - false: Apresentou erro.
//              - true: Funcionou como esperado.
bool summonContext(sf::RenderWindow &window, sf::Font &font, int n) {

    //Path
    std::string path = "./assets/rawTexts/contexts/";

    // Imagem de fundo da tela de contexto base
    sf::Image image;
    if(! image.loadFromFile("./assets/images/game/context/baseContext.png")) {
      std::cout << "Erro na leitura de imagem de contexto base." << std::endl;
      return false;
    }
    
    // Textura do fundo da tela de jogo
    sf::Texture texture;
    texture.loadFromImage(image);

    // Sprite da tela de jogo
    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    // Limpa a tela e desenha a imagem base de fundo
    window.clear();       
    window.draw(sprite);  

    // Variável para verificação de eventos
    sf::Event event;

    // Nome do arquivo de texto
    std::string str_number = std::to_string(n);
    std::string file_path = path + str_number + ".txt";

    // Obtençaõ da string correspondente ao titulo do contexto
    std::string title = getContextTitle(file_path);
    std::cout << title << std::endl;
    if(!title.compare("FILE_ERROR")){
        return false;
    }

    // Obtenção da string correspondente ao corpo do contexto
    std::string body = getContextBody(file_path);
    std::cout << body << std::endl;
    if(!body.compare("FILE_ERROR")){
        return false;
    }

    // Texto de exibição título do contexto
    sf::Text sfTextTitle;
    sfTextTitle.setFillColor(sf::Color::Black);
    sfTextTitle.setCharacterSize(40);
    sfTextTitle.setFont(font);
    sfTextTitle.setString(title);

    // Centralziação  e posicionamento do título na tela
    sf::FloatRect sfTextTitleRect = sfTextTitle.getLocalBounds(); 
    sfTextTitle.setOrigin(sfTextTitleRect.width/2, sfTextTitleRect.height/2); 
    sfTextTitle.setPosition(SCREEN_WIDTH / 2 , 140);
     
    // Desenha título do contexto na tela
    window.draw(sfTextTitle);

    // Texto de exibição do corpo do contexto
    sf::Text sfTextBody;
    sfTextBody.setFillColor(sf::Color::Black);
    sfTextBody.setCharacterSize(25);
    sfTextBody.setFont(font);
    sfTextBody.setString(body);
    sfTextBody.setPosition(230, 250);

    // Desenha corpo do contexto na tela
    window.draw(sfTextBody);

    // Loop de espera de entrada
    while(1) {
        
        while(window.pollEvent(event)) {
            
            // Caso o evento seja de fechamento da janela, fecha a janela
            if(event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
            
            // Caso o usuário aperte enter, ele é direcionado para a próxima tela de jogo
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter){
                return true;
            }
        }

        // Exibição da tela para o usuário
        window.display();
    }
}

