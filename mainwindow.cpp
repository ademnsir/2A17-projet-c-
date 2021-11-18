#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produits.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/LENOVO/Desktop/Atelier_Connexion/Menu.png");
    ui->labelPIC->setPixmap(pix.scaledToHeight(745,Qt::FastTransformation));


    ui->lineEditID->setValidator(new QIntValidator(0,999999,this));
    ui->lineEditNBR->setValidator(new QIntValidator(0,9999,this));
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
    int depense = 0;
    QMessageBox msgBox;

    Produits P(id , nomProduit , nbrProduit , depense);
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
    int depense=0;
    QMessageBox msgbox;
    Produits P(id,nomProduit,nbrProduit,depense);
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

void MainWindow::on_pb_ajoutR_2_clicked()
{

    int nbrProduit= ui->lineEditNBR->text().toInt();
    int depense=ui->lineEdit_DEPENSE->text().toInt();
    int id=ui->lineEditID->text().toInt();
    QString nomProduit;

    QMessageBox msgBox;

    Produits P(id,nomProduit,nbrProduit,depense);
    bool test=P.achat();
    if (test)
    {msgBox.setText("achat avec succés");
        ui->tabProduits->setModel((P.afficher()));
    }
    else
        msgBox.setText("échec d'achat");
    msgBox.exec();


}


void MainWindow::on_pb_vendre_clicked()
{
    int id = ui->lineEditID->text().toInt();
    int nbrProduit = ui->lineEditNBR ->text().toInt();
    QString nomProduit = ui->lineEditNOM->text() ;
    int depense = 0;
    QMessageBox msgbox;
    Produits P(id,nomProduit,nbrProduit,depense);
    bool test=P.vendre(id,nomProduit,nbrProduit);
    if(test)
        {
            msgbox.setText("vente avec succés");
            ui->tabProduits->setModel(P.afficher());
        }
        else
            msgbox.setText("Echec de vente");
            msgbox.exec();
}


void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    ui->tabProduits->setModel(P.recherche(arg1));
}

