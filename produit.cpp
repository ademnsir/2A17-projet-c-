#include "produit.h"
#include <QMessageBox>
#include <QDebug>
#include <QDate>

produit::produit()

    {id=0;nom=" ";prix=0;}

    produit::produit(long int id,int prix, QString nom )

    {
     this->id=id;
     this->prix=prix;
     this->nom=nom;

    }

    int produit::getid(){return id;}
    int produit::getprix(){return prix;}
    QString produit::getnom(){return nom;}

    void produit::setid(int id){this->id=id;}
    void produit::setprix(int prix){this->prix=prix;}
    void produit::setnom(QString nom){this->nom=nom;}
bool produit::ajouter()
        {
            QSqlQuery query;
            QString id_string=QString::number(id);
             QString r=QString::number(prix);
            query.prepare("INSERT INTO PRODUIT (id,prix,nom) "
                          "VALUES (:id,:prix,:nom)");
            query.bindValue(":id", id_string);
            query.bindValue(":prix", r);
            query.bindValue(":nom",nom);

            return query.exec();



    }

bool produit::ajouter_historique(QString nom)
        {
            QSqlQuery query;
            query.prepare("INSERT INTO OPERATION (NOM,DATEAJ) "
                          "VALUES (:NOM,:DATEAJ)");
            query.bindValue(":NOM", nom);
            query.bindValue(":DATEAJ", QDate::currentDate() );

            return query.exec();



    }


    bool produit::supprimer(int id){
        QSqlQuery query;
        produit C;
        bool test=C.recherche_id(id);
        if(test){
        query.prepare(" Delete from PRODUIT where id=:id");
        query.bindValue(":id", id);
        }
        return query.exec();
    }



    QSqlQueryModel* produit::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM  produit");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));


        return model;
    }

    QSqlQueryModel* produit::afficher_historique()
    {
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT* FROM  OPERATION");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date d'ajout"));


        return model;
    }

    bool produit::recherche_nom(QString nom)
    {
        QMessageBox msgBox;
        QSqlQuery query;

        query.prepare("SELECT * FROM PRODUIT WHERE NOM= :nom");
        query.bindValue(":nom", nom);
        if (query.exec() && query.next())
        {
                return true;
        }
        else
        {

            msgBox.setText("produit n existe pas");
            msgBox.exec();
            return false;
        }
    }



    bool produit::recherche_prix(int prix)
    {
        QMessageBox msgBox;
        QSqlQuery query;

        query.prepare("SELECT * FROM PRODUIT WHERE prix= :prix");
        query.bindValue(":prix", prix);
        if (query.exec() && query.next())
        {
                return true;
        }
        else
        {
            msgBox.setText("produit n existe pas");
            msgBox.exec();
            return false;
        }
    }



    bool produit::recherche_id(int id)
    {

        QMessageBox msgBox;
        QSqlQuery query;
         QString id_string=QString::number(id);
        query.prepare("SELECT * FROM PRODUIT WHERE id= :id");
        query.bindValue(":id", id_string);
        if (query.exec() && query.next())
        {
                return true;
        }
        else
        {
            msgBox.setText("produit n existe pas");
            msgBox.exec();
            return false;
        }
    }



    QSqlQueryModel* produit::afficher_id(int id)
    {
        QSqlQueryModel* model= new QSqlQueryModel();
        QString id_string=QString::number(id);

              model->setQuery("SELECT * FROM PRODUIT WHERE ID='"+id_string+"'");

        return model;
    }




    QSqlQueryModel* produit::afficher_nom(QString nom)
    {
        QSqlQueryModel* model= new QSqlQueryModel();

              model->setQuery("SELECT * FROM PRODUIT WHERE NOM='"+nom+"'");

        return model;
    }




    QSqlQueryModel* produit::afficher_prix(int prix)
    {
        QSqlQueryModel* model= new QSqlQueryModel();
        QString prix_string=QString::number(prix);


              model->setQuery("SELECT * FROM PRODUIT WHERE prix='"+prix_string+"'");

        return model;
    }





    bool produit::modifier(int id)
    {
        QSqlQuery query;
        QString id_string=QString::number(id);
        QString prix_string=QString::number(prix);

        if (recherche_id(id))
        {

              query.prepare("UPDATE PRODUIT SET nom=:nom, prix=:prix WHERE id=:id");
              query.bindValue(":id", id_string);
              query.bindValue(":prix", prix_string);
              query.bindValue(":nom",nom);

        }
              return query.exec();
    }


