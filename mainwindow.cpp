#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qchatcommunicator.h"

MainWindow::MainWindow(char* chatparam,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QChatCommunicator test(chatparam,this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
