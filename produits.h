#ifndef PRODUITS_H
#define PRODUITS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>

class Produits
{
public:
    Produits();
    Produits(int,QString,int);
    int getid();
    QString getnomProduit();
    int getnbrProduit();
    void setid(int);
    void setnomProduit(QString);
    void setnbrProduit(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    int id, nbrProduit;
    QString nomProduit;
};

#endif // PRODUITS_H
