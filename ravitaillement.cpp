#include "ravitaillement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
//#include "produits.h"

    RAVITAILLEMENT::RAVITAILLEMENT()
    {
    idR=0; nbrproduitR=0; depense=0;
    }

    RAVITAILLEMENT::RAVITAILLEMENT(int nbrproduitR, int depense ,int idR)
    {this->idR=idR ; this->nbrproduitR=nbrproduitR;this->depense=depense;}

    int RAVITAILLEMENT :: getidRavitaillement(){return idR;}
    int RAVITAILLEMENT :: getnbrproduitsR(){return nbrproduitR;}
    int RAVITAILLEMENT :: getdepense(){return depense;}
    void  RAVITAILLEMENT :: setidRavitaillement(int idR ){this->idR=idR;}
    void RAVITAILLEMENT :: setnbrProduitsR(int nbrproduitR) {this->nbrproduitR=nbrproduitR;}
    void RAVITAILLEMENT :: setdepense(int depense){this->depense=depense;}

    QSqlQueryModel* RAVITAILLEMENT:: afficherR()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
              model->setQuery("SELECT* FROM RAVITAILLEMENT");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("NBR_PRODUIT_R"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("DEPENSE"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID_RAVITAILLEMENT"));

        return model;
    }


    bool RAVITAILLEMENT ::ajouterR()
    {
        //Produits P;
        QString idR_string = QString :: number(idR);
        QString nbrproduitR_string = QString :: number(nbrproduitR);
        QString depense_string = QString :: number (depense);
        //QString nbrProduit_string = QString :: number(P.getnbrProduit());
        QSqlQuery query;
            query.prepare("INSERT INTO RAVITAILLEMENT (NBR_PRODUIT_R,DEPENSE ,ID_RAVITAILLEMENT ) "
                          "VALUES (:nbrproduitR, :depense, :idR)");
            //query.prepare("update produits set nbr_produit= nbrproduit+'"+nbrProduit_string+"' where id_produits=:id_produits");

            query.bindValue(":nbrproduitR", nbrproduitR_string);
            query.bindValue(":depense", depense_string);
            query.bindValue(":idR", idR_string);

        return  query.exec();
    }




