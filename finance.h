#ifndef FINANCE_H
#define FINANCE_H
#include <QString>
#include <QDate>
#include <QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include <QWidget>
#include <QSqlQueryModel>
#include <QMessageBox>
#include<QSqlQuery>
class finance
{
public:
    finance();

    ////////////afficher//////////
    QSqlQueryModel * afficher();
    ////////ajouter///////////
    bool ajouter(int ID ,int PRIX,int DEPENCES,QDate DATE_F ,int NB_VISITEUR);
    ///////supprimer/////////
    bool supprimer(int);
    //////modifier//////////
    bool modifier(int ID ,int PRIX,int DEPENCES,QDate DATE_F ,int NB_VISITEUR);
    //////////////////////////////////////////////////////////////////////////////
    QSqlQueryModel * Rech(QString choix,QString ch);
    QSqlQueryModel * triDATE();
    QSqlQueryModel * triID();
    QSqlQueryModel * triGAIN();
    QSqlQueryModel * triPRIX();
    void convPDF ();
    bool verifNum(QString n);
};

#endif // FINANCE_H
