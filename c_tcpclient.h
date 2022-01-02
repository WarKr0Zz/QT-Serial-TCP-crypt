#ifndef C_TCPCLIENT_H
#define C_TCPCLIENT_H
#include <string>
#include <winsock.h>

class C_TCPClient
{

private:
        HOSTENT* infoPoste;
        SOCKET  SocketClient;
        struct sockaddr_in  structSocketClient;
        char adIPserveur[20];
        int numPortServeur;
public:
        int result;
        char* messageEnvoye;
        char messageRecu[100];
        char* chReponseServeur;
        C_TCPClient();
        void connexion(int numPortServeur, std::string adIPserveur);
        int EnvoiRequete(std::string messageEnvoye);
        char* Recevoir_message_serveur(void);
        void Deconnecter_client(void);


};

#endif // C_TCPCLIENT_H
