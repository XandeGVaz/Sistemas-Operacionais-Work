#include "fileManipulation.hpp"

/*====================== Funções Auxiliares====================*/

/* Função auxiliar que busca adicionar uma quebra de linha(a uma string) após uma certa quantidade de caracteres
    Parâmetros:
        - input: string de entrada onde desejamos adicionar as quebras)
        - masCharsPerLine: uma previsão (um pouco mais baixa) da quantidade de caracteres que cabem
        no quadrado da imagem
    Retorna:
        - result: a mesma string do input, mas com quebras de linhas nos locais certos 
*/
std::string insertNewlineEveryNChars(std::string input, size_t maxCharsPerLine) {
    // String de resultado
    std::string result = input;

    // Posiçãop inicial a ser considerada na string
    size_t pos = maxCharsPerLine;
    
    // Retira quebras de linha já existentes na string e substitui por um espaço
    std::replace(result.begin(), result.end(), '\n', ' ');   
    
    // Enquanto a posição não ultrapassar o tamanho da string de entrada
    while (pos < result.size()) {

        // Procura o primeiro espaço após a posição 'pos'
        size_t spacePos = result.find(' ', pos);
        if (spacePos == std::string::npos)
            break;

        // Se o espaço for encontrado, é substituido por uma quebra de linha
        result[spacePos] = '\n';

        // Remove espaços após a quebra de linha, se houver
        while (spacePos + 1 < result.size() && result[spacePos + 1] == ' ') {
            result.erase(spacePos + 1, 1);
        }

        /* Posicção pula a máxima quantidade de caracteres por linha para que uma nova quebra
            de linha seja incluida na string
        */
        pos = spacePos + maxCharsPerLine + 1; // +1 para não cair no mesmo espaço
    }

    // Retorna string com quebra de linhas
    return result;
}

/*====================== Funções principais====================*/
/* Obtenção do título do contexto
    Parâmetro: 
        fileName: diretório do arquivo txt de contexto
    Saída:
        title: string cujo conteúdo é o título do contexto 
*/
std::string getContextTitle(std::string fileName){

    // Obtenção do título do arquivo
    std::string title;

    // Abertura do arquivo para leitura
    std::fstream arq(fileName);
    if(!arq.is_open()){
        std::cout << "Erro na obtenção do arquivo" + fileName << std::endl;
       return "FILE_ERROR";
       arq.close();
    }

    // Leitura do título
    std::getline(arq, title);
    
    std::cout << title[0] << std::endl;

    // Fecha arquivo
    arq.close();

    // Filtra caracteres $
    if(title[0] == '$'){
        title.erase(std::remove(title.begin(), title.end(), '$'), title.end());
        return title;
    }

    return "FILE_ERROR";
}

/* Obtenção do corpo do contexto
    Parâmetro: 
        fileName: diretório do arquivo txt de contexto
    Saída:
        body: string cujo conteúdo é o corpo do contexto 
*/
std::string getContextBody(std::string fileName){
    // Obtenção do título do arquivo
    std::string aux_str;
    std::string Body;
    std::ostringstream streamBody;

    // Abertura do arquivo para leitura
    std::fstream arq(fileName);
    if(!arq.is_open()){
        arq.close();
        return "FILE_ERROR";
    }
    
    // Leitura do título
    std::getline(arq, aux_str);

    // Verifica consistência do título
    if(aux_str[0] != '$'){
        arq.close();
        return "FILE_ERROR";
    }

    // Leitura do corpo de texto (até o final do arquivo)
    streamBody << arq.rdbuf();
    Body = streamBody.str();
     
    //Fecha arquivo 
    arq.close();

    // Retorna vector com linhas do corpo de texto
    return insertNewlineEveryNChars(Body, 1500/25);
}