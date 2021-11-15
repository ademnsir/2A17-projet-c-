#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produits.h"
#include "ravitaillement.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditID->setValidator(new QIntValidator(0,999999,this));
    ui->lineEditNBR->setValidator(new QIntValidator(0,99999,this));
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

    Produits P(id , nomProduit , nbrProduit);
    bool test=P.ajouter();
    if (test)
    {msgBox.setText("ajout avec succés");
        ui->tabProduits->setModel((P.afficher()));
    }
    else
        msgBox.setText("échec d'ajout");
    msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Produits P;
    P.setid(ui->lineEditID->text().toInt());

    bool test=P.supprimer(P.getid());

    QMessageBox msgBox;
    if (test)
    {msgBox.setText("supprission avec succés");
        ui->tabProduits->setModel(P.afficher());
    }
    else
        msgBox.setText("échec de supprission");
    msgBox.exec();

}



void MainWindow::on_pb_afficher_clicked()
{
    Produits P;
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
            ui->lineEditID->setText(query.value(0).toString());
            ui->lineEditNOM->setText(query.value(2).toString());
            ui->lineEditNBR->setText(query.value(1).toString());


        }
}}
void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->lineEditID->text().toInt();
    int nbrProduit = ui->lineEditNBR ->text().toInt();
    QString nomProduit = ui->lineEditNOM->text() ;
    QMessageBox msgbox;
    Produits P(id,nomProduit,nbrProduit);
    bool test=P.modifier(id,nomProduit,nbrProduit);
    if(test)
        {
            msgbox.setText("Modification avec succés");
            ui->tabProduits->setModel(P.afficher());
        }
        else
            msgbox.setText("Echec de modification");
            msgbox.exec();
    }










