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
    RAVITAILLEMENT(int,int,int);
    int getidRavitaillement();
    int getnbrproduitsR();
    int getdepense();
    void setidRavitaillement(int);
    void setnbrProduitsR(int);
    void setdepense(int);
    bool ajouterR();
    QSqlQueryModel* afficherR();

private:
        int idR;
        int nbrproduitR;
        ;
};

#endif // RAVITAILLEMENT_H
