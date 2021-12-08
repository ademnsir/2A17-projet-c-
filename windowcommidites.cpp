#include "windowcommidites.h"
#include "ui_windowcommidites.h"

windowcommidites::windowcommidites(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowcommidites)
{
    ui->setupUi(this);
    QPixmap pix13("C:/Users/user/Documents/maquetteQT/violet.jpg");

 ui->label_3->setPixmap(pix13.scaled(1920,900,Qt::KeepAspectRatio));
}

windowcommidites::~windowcommidites()
{
    delete ui;
}



void windowcommidites::on_pb_ajouter_clicked()
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

void windowcommidites::on_pb_supprimer_clicked()
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

void windowcommidites::on_pb_afficher_clicked()
{
    Produits P;
    ui->tabProduits->setModel(P.afficher());
}




void windowcommidites::on_tabProduits_activated(const QModelIndex &index)
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


void windowcommidites::on_pb_modifier_clicked()
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

void windowcommidites::on_pb_ajoutR_2_clicked()
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


void windowcommidites::on_pb_vendre_clicked()
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




void windowcommidites::on_pb_recherche_clicked()
{
    int id=ui->recherche->text().toInt();
    ui->tabProduits->setModel(P.recherche(id));

}



void windowcommidites::on_pb_stock_clicked()
{
    Produits Etmp;

   QMessageBox::critical(nullptr, QObject::tr("liste des produits finis"),
                QObject::tr("voici la liste des produits qui risquent de finir.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    {ui->tabProduits->setModel(Etmp.afficherProduitexpire());}
}














