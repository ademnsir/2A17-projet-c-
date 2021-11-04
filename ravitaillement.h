#ifndef RAVITAILLEMENT_H
#define RAVITAILLEMENT_H
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>

class RAVITAILLEMENT
{
public:
    RAVITAILLEMENT();
    RAVITAILLEMENT(int,int,double);
    int getidRavitaillement();
    int getnbrproduits();
    double getdepense();
    void setidRavitaillement(int);
    void setnbrProduits(int);
    void setdepense(double);
    bool ajouterR();
    QSqlQueryModel* afficherR();
    bool supprimerR(int);
private:
        int idRavitaillement;
        int nbrProduits;
        double depense;
};

#endif // RAVITAILLEMENT_H
