#include "gameFlux.hpp"

// Função de definição do fluxo de jogo
//  Parâmetros: - answer: array de respostas do jogador.
//              - expected: array de respostas esperadas.
//  Retorno:    - 0: Alguma função de invocação apresentou erro. Mensagens de erro serão responsabilidade das respectivas funções.
//              - 1: Funcionamento esperado.

int gameFlux(sf::RenderWindow &window, sf::Font &font, int* score, Answer_t* expected) {

    // Variaveis de controle do jogo
    int state = 1;
    Answer_t answer;
    bool correct = false;

    // Loop de jogo
    while(state <= N_QUESTIONS) {

        // Invoca a tela de contexto e lida com retornos de erro.
        if(!summonContext(window, font, state)){
            std::cout << "Erro na exibição de contexto de questão" << std::endl;
            return 0;
        }
        
        // Invoca a tela de pergunta e armazena a ação do usuario
        if(!summonQuestion(window, font, state, &answer)){
            std::cout << "Erro na exibição das alternativas" << std::endl;
            return 0;
        }
        
        // Delimita as acoes do usuario
        if(answer == ERROR){
            std::cout << "Erro na exibição de questão" << std::endl;
            return 0;
        }

        // Compara resposta do usuario com o esperado
        if(answer == expected[state-1]) {
            (*score)++;
            correct = true;
        }

        if(!summonReview(window, font, state, correct)){
            std::cout << "Erro na exibição de review de questão" << std::endl;
            return 0;
        }
        
        // Avança o fluxo de jogo para novo estado.
        state++;
        correct = false;
    }

    // Função executada com sucesso
    return 1;
}

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
    std::wstring title = getContextTitle(file_path);
    if(!title.compare(L"FILE_ERROR")){
        return false;
    }

    // Obtenção da string correspondente ao corpo do contexto
    std::wstring body = getContextBody(file_path);
    if(!body.compare(L"FILE_ERROR")){
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

    // Exibição da tela para o usuário
    window.display();

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
    }
}

bool summonReview(sf::RenderWindow &window, sf::Font &font, int n, bool correct){

    //Paths
    std::string pathReview = "./assets/rawTexts/reviews/";
    std::string pathImage;

    // Definição do caminho da imagem
    if(correct){
        pathImage = "./assets/images/game/review/baseCorrectReview.png";
    } else{
        pathImage = "./assets/images/game/review/baseIncorrectReview.png";
    }

    // Imagem de fundo da tela de contexto base
    sf::Image image;
    if(! image.loadFromFile(pathImage)) {
      std::cout << "Erro na leitura de imagem base de review." << std::endl;
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
    std::string file_path = pathReview + str_number + ".txt";

    // Obtenção da string correspondente ao corpo do contexto
    std::wstring body = getContextBody(file_path);
    if(!body.compare(L"FILE_ERROR")){
        return false;
    }

    // Texto de exibição do corpo do contexto
    sf::Text sfTextBody;
    sfTextBody.setFillColor(sf::Color::Black);
    sfTextBody.setCharacterSize(25);
    sfTextBody.setFont(font);
    sfTextBody.setString(body);
    sfTextBody.setPosition(230, 250);

    // Desenha corpo do contexto na tela
    window.draw(sfTextBody);

    // Exibição da tela para o usuário
    window.display();

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
    }
}


bool summonQuestion(sf::RenderWindow &window, sf::Font &font, int n, Answer_t* answer){
    //Path
    std::string path = "./assets/rawTexts/questions/";

    // Imagem de fundo da tela de pergunta
    sf::Image image;
    if(!image.loadFromFile("./assets/images/game/question/baseQuestion.png")) {
      std::cout << "Erro na leitura de imagem de pergunta." << std::endl;
      return false;
    }

    // Textura do fundo da tela de pergunta
    sf::Texture texture;
    texture.loadFromImage(image);

    // Sprite da tela de pergunta
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Centralização do sprite
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    
    // Limpa a tela e desenha a imagem base de fundo
    window.clear();       
    window.draw(sprite);  

    // Variável para verificação de eventos
    sf::Event event;

   // Nome do arquivo de texto da pergunta
    std::string str_number = std::to_string(n);
    std::string file_path = path + str_number + ".txt";

    // String correspondente ao titulo do contexto
    std::string title = "Pergunta " + str_number + ":";

    // Obtenção da string correspondente à pergunta
    std::wstring body = getQuestionBody(file_path);
    if(!body.compare(L"FILE_ERROR")){
        return false;
    }

    // String de instruções
    std::string instruction = "(Aperte a letra da alternativa no teclado.)";

    // Obtenção das alternativas
    std::wstring *alternatives = new std::wstring[4];

    for(int i = 0; i < 4; i++){
        alternatives[i] = getAlternative(file_path, 'A'+i);
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

    // Center the text
    sf::FloatRect bodyRect = sfTextBody.getLocalBounds();
    sfTextBody.setOrigin(bodyRect.left + bodyRect.width/2.0f, bodyRect.top + bodyRect.height/2.0f);
    sfTextBody.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f - 150));

    // Desenha corpo do contexto na tela
    window.draw(sfTextBody);

    // Texto de exibição das instruções
    sf::Text sfTextInstruct;
    sfTextInstruct.setFillColor(sf::Color::Black);
    sfTextInstruct.setCharacterSize(20);
    sfTextInstruct.setFont(font);
    sfTextInstruct.setString(instruction);

    // Center the text
    sf::FloatRect instructRect = sfTextInstruct.getLocalBounds();
    sfTextInstruct.setOrigin(instructRect.left + instructRect.width/2.0f, instructRect.top + instructRect.height/2.0f);
    sfTextInstruct.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f + 300));

    // Desenha as instruções na tela
    window.draw(sfTextInstruct);

    // Alternativas
    sf::Text *sfTextAlternative = new sf::Text[4];

    // Local offsets
    float refX = 320, refY = 300;
    float localOff[4][2] = {{refX, refY},{refX+450, refY},{refX, refY+170},{refX+450, refY+170}};

    for(int i = 0; i < 4; i++) {

        // Texto das alternativas
        sfTextAlternative[i].setFillColor(sf::Color::White);
        sfTextAlternative[i].setCharacterSize(25);
        sfTextAlternative[i].setFont(font);
        sfTextAlternative[i].setString(alternatives[i]);
        sfTextAlternative[i].setPosition(localOff[i][0], localOff[i][1]);

        // Desenha a alternativa na tela
        window.draw(sfTextAlternative[i]);
    }

    // Exibição da tela para o usuário
    window.display();

    bool choiceMade = false;
    // Loop de espera de entrada
    while(1) {
        
        while(window.pollEvent(event)) {
            
            // Caso o evento seja de fechamento da janela, fecha a janela
            if(event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
            
            // Caso o usuário aperte enter, ele é direcionado para a próxima tela de jogo
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && choiceMade){
                return true;
            }

            // Caso o usuário selecione uma alternativa
            // Tenho noção que este condicional está feio, mas preciso garantir que o texto fique branco
            // apenas quando uma das alternativas for escolhida. Ass.: Gabriel.
            else if(event.type == sf::Event::KeyPressed && 
                (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::B || 
                event.key.code == sf::Keyboard::C || event.key.code == sf::Keyboard::D)) {

                // Deixa todos os textos na cor original
                for(int j = 0; j < 4; j++){
                    sfTextAlternative[j].setFillColor(sf::Color::White);
                }

                if(event.key.code == sf::Keyboard::A) {
                    sfTextAlternative[0].setFillColor(sf::Color::Yellow);
                    *answer = A;
                    choiceMade = true;
                }

                else if(event.key.code == sf::Keyboard::B) {
                    sfTextAlternative[1].setFillColor(sf::Color::Yellow);
                    *answer = B;
                    choiceMade = true;
                }

                else if(event.key.code == sf::Keyboard::C) {
                    sfTextAlternative[2].setFillColor(sf::Color::Yellow);                    
                    *answer = C;
                    choiceMade = true;
                }

                else if(event.key.code == sf::Keyboard::D) {
                    sfTextAlternative[3].setFillColor(sf::Color::Yellow);
                    *answer = D;
                    choiceMade = true;
                }
            }
            // Renderiza a tela novamente a cada interação
            window.clear();
            window.draw(sprite);
            window.draw(sfTextTitle);
            window.draw(sfTextBody);
            window.draw(sfTextInstruct);
            for(int i = 0; i < 4; i++) window.draw(sfTextAlternative[i]);
            window.display();
        }

    }
}

