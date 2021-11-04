#include "ravitaillement.h"

    RAVITAILLEMENT::RAVITAILLEMENT()
    {
    idRavitaillement=0; nbrProduits=0; depense=0;
    }
    RAVITAILLEMENT::RAVITAILLEMENT(int idRavitaillement, int nbrProduits, double depense)
    {this->idRavitaillement=idRavitaillement ; this->nbrProduits=nbrProduits;this->depense=depense;}
    int RAVITAILLEMENT :: getidRavitaillement(){return idRavitaillement;}
    int RAVITAILLEMENT :: getnbrproduits(){return nbrProduits;}
    double RAVITAILLEMENT :: getdepense(){return depense;}
    void  RAVITAILLEMENT :: setidRavitaillement(int idRavitaillement ){this->idRavitaillement=idRavitaillement;}
    void RAVITAILLEMENT :: setnbrProduits(int nbrProduits) {this->nbrProduits=nbrProduits;}
    void RAVITAILLEMENT :: setdepense(double depense){this->depense=depense;}


