#ifndef RAVITAILLEMENT_H
#define RAVITAILLEMENT_H
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QIntValidator>

class RAVITAILLEMENT
{
public:
    RAVITAILLEMENT();
    RAVITAILLEMENT(int,int,double);
    int getidRavitaillement();
    int getnbrproduitsR();
    double getdepense();
    void setidRavitaillement(int);
    void setnbrProduitsR(int);
    void setdepense(double);
    bool ajouterR();

private:
        int idRavitaillement;
        int nbrproduitR;
        double depense;
};

#endif // RAVITAILLEMENT_H
