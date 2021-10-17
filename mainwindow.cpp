#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // inserer  une  image
    QPixmap pix("C:/Users/user/Documents/maquetteQT/data.png");
    QPixmap pix2("C:/Users/user/Documents/maquetteQT/data.png");
    QPixmap pix3("C:/Users/user/Documents/maquetteQT/data.png");
    QPixmap pix4("C:/Users/user/Documents/maquetteQT/user.png");
     QPixmap pix5("C:/Users/user/Documents/maquetteQT/data.png");
    ui->label_pic->setPixmap(pix.scaled(900,1000,Qt::KeepAspectRatio));
     ui->label_->setPixmap(pix2.scaled(900,1000,Qt::KeepAspectRatio));
 ui->label_15->setPixmap(pix3.scaled(900,1000,Qt::KeepAspectRatio));
  ui->label_19->setPixmap(pix4.scaled(100,100,Qt::KeepAspectRatio));
 ui->label_53->setPixmap(pix5.scaled(900,1000,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

