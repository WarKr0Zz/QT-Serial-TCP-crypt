#include "c_rs232.h"
#include <windows.h>
#include <fileapi.h>
#include <string>
#include <iostream>
#include "QDebug"
//using namespace gpsProject;
//using namespace System;
//using namespace System::Windows::Forms;
using namespace std;
C_RS232::C_RS232()
{

}
int C_RS232::connect(char COM_choisi[6],unsigned long vitesse)
{
 hComm = CreateFile(L"\\\\.\\COM4",
                    GENERIC_READ | GENERIC_WRITE,
                    0,
                    NULL,
                    OPEN_EXISTING,
                    FILE_FLAG_WRITE_THROUGH,
                    0);
if (hComm == INVALID_HANDLE_VALUE)
 {
    cout << "error opening handle\n";
 }
else
 {if(hComm == INVALID_HANDLE_VALUE)
     {
         throw("ERROR: Could not open com port");
     }
     else
     {
         // set timeouts
         COMMTIMEOUTS cto = { MAXDWORD, 0, 0, 0, 0};
         DCB dcb;
         if(!SetCommTimeouts(hComm,&cto))
         {
             throw("ERROR: Could not set com port time-outs");
         }
           // set DCB
         memset(&dcb,0,sizeof(dcb));
         dcb.DCBlength = sizeof(dcb);
         dcb.BaudRate = 9600;
         dcb.fBinary = 1;
         dcb.fDtrControl = DTR_CONTROL_ENABLE;
         dcb.fRtsControl = RTS_CONTROL_ENABLE;
         dcb.Parity = NOPARITY;
         dcb.StopBits = ONESTOPBIT;
         dcb.ByteSize = 8;
         if(!SetCommState(hComm,&dcb))
         {
             throw("ERROR: Could not set com port parameters");
         }
     }
}
}

unsigned long C_RS232::EmettreTrame(std::string chTrameAEmettre)
{

 //emission gérée par buffer dans windows
 unsigned long nb_caraemettre=chTrameAEmettre.length();
 unsigned long nb_car_emis=0;


 qDebug() << "nb_caraemettre :: " << nb_caraemettre << "|";
 qDebug() << "EmettreTrame :: " << QString::fromStdString(chTrameAEmettre) << "|";
 WriteFile(hComm,chTrameAEmettre.c_str(),nb_caraemettre,&nb_car_emis,NULL);


 return nb_car_emis;
}

//-------- Methode RecevoirTrame de la classe RS232 -------------------------
char* C_RS232::RecevoirTrame(int delai)
{
 static char chTrameRecue[50];
 // controle par time out appliqué à ReadFile
 COMMTIMEOUTS Timeout; //instanciation de la structure COMMTIMEOUTS (Builder)
 int DureeTimeoutRead = delai; // durée timeout en millisecondes
 Timeout.ReadIntervalTimeout = MAXWORD;
 Timeout.ReadTotalTimeoutMultiplier = 0;
 Timeout.ReadTotalTimeoutConstant = DureeTimeoutRead; // pas de time out = 0
 Timeout.WriteTotalTimeoutMultiplier = 0;
 Timeout.WriteTotalTimeoutConstant = 0;
 SetCommTimeouts(hComm,&Timeout); // configure le timeout pour le port ouvert
 NbCaractRecus=1;
 unsigned long NbCarMaxi=100;
 ReadFile(hComm,&chTrameRecue,sizeof (chTrameRecue),&NbCaractRecus,nullptr);
 //Remplacement du return (fin de trame) par NULL (fin de chaine)
 if(NbCaractRecus!=0)
 {
 NbCaractRecus=NbCaractRecus-1; // rang du dernier caractère recu
 chTrameRecue[NbCaractRecus]=0; // remplacement du dernier caractère par NULL
 }
 return chTrameRecue;
}
//--------------------------------------------------------------------------------------



