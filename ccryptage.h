#ifndef CCRYPTAGE_H
#define CCRYPTAGE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>

class CCryptage
{
public:
    CCryptage();
    int ClefCesar;
    char* CrypterCesar(std::string ChaineCaractere, int ClefCesar);
    char* DecrypterCesar(std::string WaitText, int ClefCesar);
    char* CrypterVigenere(std::string text, std::string key);
    char* DecrypterVigenere(std:: string text1, std::string key);
};

#endif // CCRYPTAGE_H
