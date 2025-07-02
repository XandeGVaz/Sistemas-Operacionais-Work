#ifndef FILE_MANIPULATION_HPP
#define FILE_MANIPULATION_HPP

#include "globals.hpp"

std::wstring convertToWstring(std::string str);

std::wstring getContextTitle(std::string fileName);
std::wstring getContextBody(std::string fileName);
std::wstring getQuestionBody(std::string fileName);
std::wstring getAlternative(std::string fileName, char alternative);

#endif