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
    Produits(int,QString,int,int);
    int getid();
    QString getnomProduit();
    int getnbrProduit();
    void setid(int);
    void setnomProduit(QString);
    void setnbrProduit(int);
    void setdepense(int);
    int getdepense();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,QString,int);
    bool vendre(int,QString,int);
    bool achat();
    QSqlQueryModel* recherche(int);
    QSqlQueryModel* afficherProduitexpire();

private:
    int id, nbrProduit;
    QString nomProduit;
    int depense;
};

#endif // PRODUITS_H
