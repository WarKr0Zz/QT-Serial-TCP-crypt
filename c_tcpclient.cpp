#include "c_tcpclient.h"
#include <winsock.h>
#include <winsock2.h>
#include <string>
#include <QDebug>
C_TCPClient::C_TCPClient()
{

}
void C_TCPClient::connexion(int numPortServeur,std::string adIPserveur)
{
     int tailleMax=20; //
     // *****  teste la présence du driver winsock.dll en mémoire *****
     WORD VersionSockets;
     WSADATA wsadata;
     VersionSockets=MAKEWORD(2,0);        //version des sockets
     result=WSAStartup(VersionSockets,&wsadata) ;
     if (result==SOCKET_ERROR)
        {
         qDebug() << "ERROR";

        //  Abandonner le demarrage du client
        }
     else  // *****  parametrage de  la structure socket   *****
     {
           qDebug() << "BON";
           //mise à 0 d'une structure socket client
           memset(&structSocketClient,0,sizeof(struct sockaddr_in));
           memset(&SocketClient,0,sizeof(SOCKET));
           //initialisation de la structure associée à la connection sur port du serveur
           structSocketClient.sin_family = AF_INET;     //type de socket protocole internet
           structSocketClient.sin_addr.s_addr=::inet_addr(adIPserveur.c_str());   //adresse IP du serveur
           //demande ouverture connection sur port du serveur (port libre entre 1024 et 5000)
           structSocketClient.sin_port = htons(numPortServeur);

           //creation de la socket (AF_INET -> mecanisme internet SOCK STREAM-> mode connecté)
           SocketClient=socket(AF_INET,SOCK_STREAM,0);
           int result=connect(SocketClient,(struct sockaddr *)&structSocketClient, sizeof(structSocketClient));
           qDebug() << "ERROR " << result;
           if (result==SOCKET_ERROR)
              {
               qDebug() << "ERROR";
           }
     }
}

int C_TCPClient::EnvoiRequete(std::string messageEnvoye)
{
     int nbCarEnvoyes=send(SocketClient,messageEnvoye.c_str() ,sizeof(messageEnvoye),0);
     return(nbCarEnvoyes);
}

char* C_TCPClient::Recevoir_message_serveur(void)
{
    int nbCarRecus=recv(SocketClient,messageRecu,100,0);    //reception de 100 car maxi
    if(nbCarRecus==0) return("pas de message à lire : connexion fermée!!");
    if(nbCarRecus!=-1)
    {
       messageRecu[nbCarRecus]=0;  //termine la chaine
    }
    return(messageRecu);
}






