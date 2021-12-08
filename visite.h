#ifndef VISITE_H
#define VISITE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDateEdit>
#include <QFile>
#include <QTextStream>

class Visite
{
private:
    int id,nb_visiteur,prix;
    QDate date;


public:
    Visite();
    Visite(int, int, QDate, int);

    int getid();
    int getnb();

    int getprix();

    void setid(int);
    void setnb(int);

    void setprix(int);

    bool ajouter();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * afficher();

    QSqlQueryModel * trier_nb();
    QSqlQueryModel * trier_nbd();
   QSqlQueryModel * rechercher (int );

//  void save(  QString);

};

#endif // VISITE_H
