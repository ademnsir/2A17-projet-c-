#include "produits.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Produits::Produits()
{
id=0; nbrProduit=0; nomProduit="",depense=0;
}
Produits :: Produits(int id,QString nomProduit,int nbrProduit,int depense)
{
    this->id=id ; this->nomProduit=nomProduit;this->nbrProduit=nbrProduit;this->depense=depense;
}

int Produits :: getdepense(){return depense;}
int Produits :: getid(){return id;}
QString Produits :: getnomProduit(){return nomProduit;}
int Produits :: getnbrProduit(){return nbrProduit;}
void  Produits :: setid(int id){this->id=id;}
void Produits :: setnomProduit(QString nomProduit) {this->nomProduit=nomProduit;}
void Produits :: setnbrProduit(int nbrProduit){this->nbrProduit=nbrProduit;}
void Produits :: setdepense(int depense){this->depense=depense;}


bool Produits::ajouter()
{
   QString id_string = QString :: number(id);
   QString nbrProduit_string = QString :: number(nbrProduit);
    int depense=0;
   QSqlQuery query;
       query.prepare("INSERT INTO PRODUIT (id_produits,nom_produit ,nbr_produit ) "
                     "VALUES (:id, :nomProduit, :nbrProduit)");
       query.bindValue(":id", id_string);
       query.bindValue(":nomProduit", nomProduit);
       query.bindValue(":nbrProduit", nbrProduit_string);
       query.bindValue(":depense", depense);

   return  query.exec();
}


bool Produits :: supprimer(int id)
{
    QSqlQuery query;

        query.prepare("Delete from produit where id_produits=:id");
        query.bindValue(0,id);

    return  query.exec();
}


QSqlQueryModel* Produits:: afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
          model->setQuery("SELECT * FROM Produit");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUITS"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PRODUIT"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBR_PRODUIT"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("DEPENSE"));

    return model;
}

bool Produits :: modifier(int, QString, int)
{
    QString id_string = QString :: number(id);
    QString nbrProduit_string = QString :: number(nbrProduit);
    QString depense_string = QString :: number (depense);

    QSqlQuery query;
    query.prepare ("update produit set id_produits='"+id_string+"', nom_produit='"+nomProduit+"',nbr_produit='"+nbrProduit_string+"' , depense='"+depense_string+"' where id_produits=:id_produits");
    query.bindValue(0,id_string);
    query.bindValue(1,nomProduit);
    query.bindValue(2,nbrProduit_string);
    return query.exec();

}

bool Produits :: vendre(int, QString, int)
{
    QString id_string = QString :: number(id);
    QString nbrProduit_string = QString :: number(nbrProduit);

    QSqlQuery query;
    query.prepare ("update produit set nbr_produit= nbr_produit-'"+nbrProduit_string+"' where id_produits=:id_produits");
    query.bindValue(0,id_string);
    query.bindValue(1,nomProduit);
    query.bindValue(2,nbrProduit_string);
    return query.exec();

}

bool Produits ::achat()
{

    QString id_string = QString :: number(id);
    QString nbrproduit_string = QString :: number(nbrProduit);
    QString depense_string = QString :: number (depense);
    QSqlQuery query;
        query.prepare("update produit set nbr_produit= nbr_produit+'"+nbrproduit_string+"',depense= depense+'"+depense_string+"' where id_produits=:id_produits");

        query.bindValue(0,id_string);
        query.bindValue(1,nomProduit);
        query.bindValue(2,nbrproduit_string);
        query.bindValue(3,depense_string);

        return query.exec();
}

QSqlQueryModel* Produits ::recherche(QString)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString searchid = QString :: number(id);
            model->setQuery("SELECT * from produit where id_produits LIKE searchid");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_produit"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbr_produit"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("depense"));
                return model;
}




