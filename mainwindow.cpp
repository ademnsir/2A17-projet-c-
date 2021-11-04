#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produits.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditID->setValidator(new QIntValidator(0,999999,this));
    ui->tabProduits->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->lineEditID->text().toInt();
    QString nomProduit=ui->lineEditNOM->text();
    int nbrProduit= ui->lineEditNBR->text().toInt();
    QMessageBox msgBox;

    Produits P(id,nomProduit,nbrProduit);
    bool test=P.ajouter();
    if (test)
    {msgBox.setText("ajout avec succes");
        ui->tabProduits->setModel((P.afficher()));
    }
    else
        msgBox.setText("echec d'ajout");
    msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Produits P;P.setid(ui->lineEditID->text().toInt());
    bool test=P.supprimer(P.getid());
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("supprission avec succes");
        ui->tabProduits->setModel(P.afficher());
    }
    else
        msgBox.setText("echec de supprission");
    msgBox.exec();

}



void MainWindow::on_pb_afficher_clicked()
{
    ui->tabProduits->setModel(P.afficher());
}

void MainWindow::on_tabProduits_activated(const QModelIndex &index)
{
    QString val=ui->tabProduits->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from PRODUITS where id='"+val+"'");
    if (query.exec())
    {while (query.next())
        {
            ui->lineEditID->setText(query.value(0).toInt());

        }
}}
