#ifndef C_RS232_H
#define C_RS232_H
#include <stdio.h>
#include <windows.h>
#include <string>
//#include <ExtCtrls.hpp>

class C_RS232
{
private:
    // Variables privées de la classe
     DCB dcb; //Declaration structure DCB
     HANDLE hComm; // permet la gestion du COM (comme Gestion de fichier)
     unsigned long NbCaractRecus;
public:
    C_RS232();

     //variables et méthodes publiques
    public:
     int etatPort; //indique l'etat du port
    int connect(char COM_choisi[6],unsigned long vitesse); // Constructeur servant à initialiser la liaison
     unsigned long EmettreTrame(std::string chTrameAEmettre);
     char* RecevoirTrame(int delai);
};

#endif // C_RS232_H
