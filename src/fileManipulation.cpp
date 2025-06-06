#include "fileManipulation.hpp"
#include <fstream>

std::string getContextTitle(std::string fileName){

    // Obtenção do título do arquivo
    std::string title;

    // Abertura do arquivo para leitura
    std::fstream arq(fileName);
    if(!arq.is_open()){
        return "FILE_ERROR";
    

    // Leitura do título
    std::getline(arq, title);

    
}