#include "gameFlux.hpp"

// Função de definição do fluxo de jogo
//  Parâmetros: - answer: array de respostas do jogador.
//              - expected: array de respostas esperadas.
//  Retorno:    - 0: Alguma função de invocação apresentou erro. Mensagens de erro serão responsabilidade das respectivas funções.
//              - 1: Funcionamento esperado.

int gameFlux(sf::RenderWindow &window, sf::Font &font, int* answer, int* expected) {
    // Inicialização do vetor de respostas
    answer = new int[N_QUESTIONS];

    // Variaveis de controle do jogo
    int performance, action, state = 1;

    // Loop de jogo
    while(state <= N_QUESTIONS) {
        // Invoca a tela de contexto e lida com retornos de erro.
        if(!summonContext(window, font, state)) return 0;

        // Invoca a tela de pergunta e armazena a ação do usuario
        action = summonQuestion(window, font, state, answer);

        // Delimita as acoes do usuario
        if(!action) return 0;

        // Usuario deseja avancar
        else if(action == 1) {

            // Compara resposta do usuario com o esperado
            if(answer[state] == expected[state]) performance = 1;
            else performance = 0;

            // Invoca tela de review e lida com retornos de erro.
            if(!summonReview(window, font, state, performance)) return 0;

            // Avança o fluxo de jogo para novo estado.
            state++;
        }
    }
    return 1;
}

// Função de invocação da tela de contexto.
//  Parâmetros: - n: variável comum à outras funções de invocação. Rege o estado do jogo.
//  Retorno:    - 0: Apresentou erro.
//              - 1: Funcionou como esperado.

int summonContext(sf::RenderWindow &window, sf::Font &font, int n) {

    //Path
    std::string path = "../assets/rawTexts/contexts/";

    // Imagem de fundo da tela de contexto base
    sf::Image image;
    if(! image.loadFromFile("./assets/images/game/context/baseContext.png")) {
      std::cout << "Erro na leitura de imagem de contexto base." << std::endl;
      return 0;
    }
    
    // Textura do fundo da tela de jogo
    sf::Texture texture;
    texture.loadFromImage(image);

    // Sprite da tela de jogo
    sf::Sprite sprite;
    sprite.setTexture(texture);

    window.clear();       // Limpa a tela
    window.draw(sprite);  // Desenha background da tela
    window.display();     // Atualiza a tela

    // Variável para verificação de eventos
    sf::Event event;

    // Nome do arquivo de texto
    std::string str_number = std::to_string(n);
    std::string file_path = path + str_number + ".txt";

    // Definição dos textos
    std::string title = getContextTitle(file_path);
    if(!title.compare("FILE_ERROR"))
        return 0;

    std::string body = getContextBody(file_path);
    if(!title.compare("FILE_ERROR"))
        return 0;

    // Texto de exibição título do contexto
    sf::Text textTitle;
    textTitle.setFillColor(sf::Color::Black);
    textTitle.setCharacterSize(40);
    textTitle.setPosition(SCREEN_WIDTH / 2 + 20, 100); // posição do texto na tela
    textTitle.setFont(font);
    textTitle.setString(title);

    // Texto de exibição do corpo do contexto
    sf::Text textBody;
    textBody.setFillColor(sf::Color::Black);
    textBody.setCharacterSize(30);
    textBody.setPosition(SCREEN_WIDTH / 2 + 20, 200); // posição do texto na tela
    textBody.setFont(font);
    textBody.setString(body);

    // Loop de espera de entrada
    while(1) {
        while(window.pollEvent(event)) {

            // Caso o evento seja de fechamento da janela, fecha a janela
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            // Caso o evento seja de apertar a tecla enter, retorne a função
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                return 1;
        }
    }
}

