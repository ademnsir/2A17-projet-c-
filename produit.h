#ifndef PRODUIT_H
#define PRODUIT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class produit;
}
class produit
{
    QString nom;
    int id,prix;

     public:
            produit();
            produit(long int,int,QString);



            int getid();
            int getprix();
            QString getnom();



            void setid(int id);
            void setprix(int prix);
            void setnom(QString nom);




            bool ajouter();
            QSqlQueryModel* afficher();
            QSqlQueryModel* afficher_id(int);
            QSqlQueryModel* afficher_nom(QString);
            QSqlQueryModel* afficher_prix(int);
            bool modifier(int);
            bool recherche_nom(QString);
            bool recherche_prix(int);
            bool recherche_id(int);
            bool supprimer(int);
            bool ajouter_historique(QString);
            QSqlQueryModel* afficher_historique();

      };




#endif // PRODUIT_H
