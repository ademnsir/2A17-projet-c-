#ifndef RECLAMATION_H
#define RECLAMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlQueryModel>
#include "arduino.h"
#include <QDate>
#include <QDateEdit>
#include <QDebug>
#include "visite.h"

class Reclamation
{
private:
    int id,id_p;
    QString titre,corps;


public:
    Reclamation();
    Reclamation(int,QString,QString,int);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
  //  QSqlQueryModel *combo();
};
#endif // RECLAMATION_H
