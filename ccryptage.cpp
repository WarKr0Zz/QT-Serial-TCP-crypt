#include "ccryptage.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>
CCryptage::CCryptage()
{

}
// ****************** Methode CrypterCesar de la class CCrypter ******************

char* CCryptage::CrypterCesar(std::string ChaineCaractere, int ClefCesar) {
    int TailleChaine = ChaineCaractere.length();
    // calcul taille buffer non crypté
    char* ChaineCryptee = new char[TailleChaine];
    // allocation mémoire taille buffer
    for (int z = 0; z < TailleChaine; z++) {
        if (ChaineCaractere[z] == 0x20) // Si le caractère est un blanc
        {
            ChaineCryptee[z] = 0x20;
        }
        else {
            ChaineCryptee[z] = (ChaineCaractere[z] + (ClefCesar));

        }
    }

    return(ChaineCryptee);
}

// ***************** Methode Decryptercesar de la class CCrypter *****************

char* CCryptage::DecrypterCesar(std::string WaitText, int ClefCesar) {
    int TailleChaine1 = WaitText.length(); // calcul taille buffer non crypté
    char* ChaineCryptee1 = new char[TailleChaine1];
    // allocation mémoire taille buffer
    for (int p = 0; p < TailleChaine1; p++) {
        if (WaitText[p] == 0x20) // Si le caractère est un blanc
        {
            ChaineCryptee1[p] = 0x20;
        }
        else {
            ChaineCryptee1[p] = (WaitText[p] - (ClefCesar));

        }
    }

    return(ChaineCryptee1);
}

// ***************** Methode CryptVigenere de la class CCrypter *****************

char* CCryptage::CrypterVigenere(std::string text, std::string key) {
    int size = key.length();
    int size2 = text.length();
    char* ciphertext = new char[size2];
    for (int i = 0; i < size2; i++) {
        for (int d = 0; d < size; d++) {


            if ((text[i] >= 0) && (text[i] <= 127)) {
                int rang = (text[i] + key[i % size]) % 127;
                ciphertext[i] = 0 + rang;
            }

            else
                ciphertext[i] = text[i];
    }
    }
    // ciphertext[i] = '\0';
    return(ciphertext);
}

// ***************** Methode DecryptVigenere de la class CCrypter *****************
char* CCryptage::DecrypterVigenere(std::string text1, std::string key) {
    int size = key.length();
    int size2 = text1.length();
    char* ciphertext = new char[size2];
    for (int i = 0; i < size2; i++) {
        for (int d = 0; d < size; d++) {


        if ((text1[i] >= 0) && (text1[i] <= 127)) {
            int rang = (text1[i] - key[i % size] ) % 127;
            ciphertext[i] = 0 + rang;
        }

        else
            ciphertext[i] = text1[i];
    }
    }
    // ciphertext[i] = '\0';
    return(ciphertext);
}
