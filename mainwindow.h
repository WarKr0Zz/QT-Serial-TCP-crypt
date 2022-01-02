#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ccryptage.h"
#include "c_tcpclient.h"
#include "c_rs232.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    CCryptage *test;
    C_TCPClient *Client;
    C_RS232 *CRS23;

private slots:
    void on_BCryptCesar_clicked();

    void on_BCryptVigenere_clicked();

    void on_BConnect_clicked();

    void on_BEnvoyer_clicked();

    void on_BReception_clicked();

    void on_BConnectSerie_clicked();

    void on_BEnvoi_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Bconnect2_clicked();

    void on_BExplication_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_BReception2_clicked();

    void on_BDecryptCesar_clicked();

    void on_BDecryptVigenere_clicked();

    void on_BRetour3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_commandLinkButton_clicked();

    void on_BCesarChiffrage_clicked();

    void on_BVigenerechiffrage_clicked();

    void on_BVigenereDechiffre_clicked();

    void on_BCesarDechiffre_clicked();

    void on_BDemo2_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
