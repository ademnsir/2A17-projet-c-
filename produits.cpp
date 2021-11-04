#include "produits.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Produits::Produits()
{
id=0; nbrProduit=0; nomProduit="";
}
Produits :: Produits(int id,QString nomProduit,int nbrProduit)
{this->id=id ; this->nomProduit=nomProduit;this->nbrProduit=nbrProduit;}
int Produits :: getid(){return id;}
QString Produits :: getnomProduit(){return nomProduit;}
int Produits :: getnbrProduit(){return nbrProduit;}
void  Produits :: setid(int id){this->id=id;}
void Produits :: setnomProduit(QString nomProduit) {this->nomProduit=nomProduit;}
void Produits :: setnbrProduit(int nbrProduit){this->nbrProduit=nbrProduit;}
bool Produits::ajouter()
{

   QString id_string = QString :: number(id);
   QString nbrProduit_string = QString :: number(nbrProduit);

   QSqlQuery query;
       query.prepare("INSERT INTO PRODUIT (id,nomProduit ,nbrProduit ) "
                     "VALUES (:id, :nomProduit, :nbrProduit)");
       query.bindValue(0, id_string);
       query.bindValue(1, nomProduit);
       query.bindValue(2, nbrProduit_string);

   return  query.exec();

}

bool Produits :: supprimer(int id)
{
    QSqlQuery query;
        query.prepare("Delete from produits where id=:id");
        query.bindValue(0,id);

    return  query.exec();

}
QSqlQueryModel* Produits:: afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
          model->setQuery("SELECT* FROM Produits");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUITS"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_PRODUIT"));

    return model;
}

