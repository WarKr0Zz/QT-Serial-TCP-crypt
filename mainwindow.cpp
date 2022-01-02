#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ccryptage.h"
#include <string>
#include "c_tcpclient.h"
#include "c_rs232.h"
#include <QByteArray>
#include <cstring>
#include "QDebug"
#include <QPixmap>
#define KEY_LEFT 75


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test = new CCryptage();
    Client = new C_TCPClient();
    CRS23 = new C_RS232();
    QPixmap pix("E:/lets gooooooooooooooooooo/912/photo_preojet/cc.png");
    QPixmap serie("E:/lets gooooooooooooooooooo/912/photo_preojet/serial-port.jpg");
    QPixmap tcp("E:/lets gooooooooooooooooooo/912/photo_preojet/ethernet.jpg");
    QPixmap template_tcp("E:/lets gooooooooooooooooooo/912/photo_preojet/template_tcp.png");
    QPixmap template_serie("E:/lets gooooooooooooooooooo/912/photo_preojet/template_serie.png");
    QPixmap template_explain("E:/lets gooooooooooooooooooo/912/photo_preojet/template_explain.png");
    QPixmap explain_cesar("E:/lets gooooooooooooooooooo/912/photo_preojet/explain_cesar.png");
    QPixmap explain_vigenere("E:/lets gooooooooooooooooooo/912/photo_preojet/explain_vigenere.png");
    QPixmap easter_egg("E:/lets gooooooooooooooooooo/912/photo_preojet/easter_egg.jpg");
    ui->label_2->setPixmap(template_explain);
    ui->label_5->setPixmap(easter_egg);
    ui->label_4->setPixmap(explain_vigenere);
    ui->label_3->setPixmap(explain_cesar);
    ui->label_pic->setPixmap(pix);
    ui->label_pix2->setPixmap(serie);
    ui->label_11->setPixmap(tcp);
    ui->label_10->setPixmap(template_tcp);
    ui->labeltest->setPixmap(template_serie);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//********************************** CRYPTAGE | DECRYPTAGE TCP ***********************************//
void MainWindow::on_BCryptCesar_clicked() //chiffrage Cesar
{
    ui->ECryptage->setText(test->CrypterCesar(ui->EEnvoiServeur->text().toStdString(), ui->Clecesar->text().toInt()));
}

void MainWindow::on_BCryptVigenere_clicked() // chiffrage Vigenere
{
    ui->ECryptage->setText(test->CrypterVigenere(ui->EEnvoiServeur->text().toStdString(), ui->ECleVigenere->text().toStdString()));
}

void MainWindow::on_BDecryptCesar_clicked()  //Dechiffrage Cesar
{
    ui->lineEdit_2->setText(test->DecrypterCesar(ui->EReception->text().toStdString(),ui->Clecesar->text().toInt()));
}

void MainWindow::on_BDecryptVigenere_clicked() //Dechiffrage Vigenere
{
    ui->lineEdit_2->setText(test->DecrypterVigenere(ui->EReception->text().toStdString(),ui->Clecesar->text().toStdString()));
}

void MainWindow::on_pushButton_8_clicked()  // Chiffrage Cesar DEMO
{
    ui->lineEdit_4->setText(test->CrypterCesar(ui->lineEdit_3->text().toStdString(),ui->spinBox->text().toInt()));
}

void MainWindow::on_BDemo2_clicked()    // Chiffrage Vigenere DEMO
{
   ui->Etestchiffrer->setText(test->CrypterVigenere(ui->ETestpaschiffrer->text().toStdString(),ui->Etestcle->text().toStdString()));
}
//*********************************************************************************************************************************//

//*****************************Cryptage / DECHIFFRAGE SERIE********************************************************************//
void MainWindow::on_BCesarChiffrage_clicked()   //chiffrage Cesar
{
    ui->EEnvoi->setText(test->CrypterCesar(ui->ECryptageserie->text().toStdString(), ui->EKeyCesar->text().toInt()));
}

void MainWindow::on_BVigenerechiffrage_clicked() //chiffrage vigenere
{
    ui->EEnvoi->setText(test->CrypterVigenere(ui->ECryptageserie->text().toStdString(),ui->EKeyVigenere->text().toStdString()));
}

void MainWindow::on_BVigenereDechiffre_clicked() // dechiffrement Cesar
{
    ui->labeltest->setText(test->DecrypterVigenere(ui->lineEdit->text().toStdString(),ui->EKeyVigenere->text().toStdString()));
}

void MainWindow::on_BCesarDechiffre_clicked()   //dechiffrement Vigenere
{
    ui->labeltest->setText(test->DecrypterCesar(ui->lineEdit->text().toStdString(),ui->EKeyCesar->text().toInt()));
}


//*********************************************************************************************************************************//

//********************************************************** CHANGEMENT DE PAGE ***************************************************************************************
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_BExplication_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_BRetour3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
//*********************************************************************************************************************************//

//********************************************* CONNEXION TCP**********************************************************************************************//

//************OUVERTURE***********//
void MainWindow::on_BConnect_clicked()
{
    int result;
    int LNumPortServeur=ui->ENumPort->text().toInt();
    std::string adIPserveur = ui->EIpServeur->text().toStdString();
     Client= new C_TCPClient();
     Client->connexion(LNumPortServeur,adIPserveur);
     if (result==INVALID_SOCKET)   //Verification de la connection
     {
            printf("defaut de connexion");
               }
            else      // connection réussie, attente message client
               {
            printf("Connexion etablie");

               }
}

//******** ENVOIE ****************//
void MainWindow::on_BEnvoyer_clicked()
{
    Client->EnvoiRequete(ui->ECryptage->text().toUtf8().constData());
       ui->EEnvoiServeur->text()=Client->Recevoir_message_serveur();
}

//******* RECEPTION*****************//
void MainWindow::on_BReception_clicked()
{
    ui->EReception->setText(Client->Recevoir_message_serveur());
}

//*****************************************************************************************************************************************************//

//********************************************************CONNEXION SERIE*********************************************************************//

void MainWindow::on_BConnectSerie_clicked()
{
        char COM_choisi[6] = "COM4";
        unsigned long vitesse = 9600;
        unsigned char parite = 0;
        unsigned char nbreBits = 8;
        float nbreStop = 1;

        CRS23= new C_RS232();
        CRS23->connect(COM_choisi,vitesse);

}

void MainWindow::on_BEnvoi_clicked()
{
    char Buf_emission[100];
        unsigned long nbCaractEmis;

        std::strcpy(Buf_emission, ui->EEnvoi->text().toUtf8().constData());

        qDebug() << "on_BEnvoi_clicked :: " << Buf_emission << "|";
        nbCaractEmis = CRS23->EmettreTrame(Buf_emission);
        qDebug() << "nbCaractEmis :: " << nbCaractEmis << "|" ;

        if (nbCaractEmis == 0) {
            printf("Defaut d'emission sur le com!!");
        }
}

void MainWindow::on_BReception2_clicked()
{
  ui->lineEdit->setText(CRS23->RecevoirTrame(100));
}
//*********************************************************************************************************************************************************************

void MainWindow::on_commandLinkButton_clicked()         //easter-egg site php
{
   system("firefox ""http://localhost/Site_flo/finalboo.php");
}



