#include "ravitaillement.h"

    RAVITAILLEMENT::RAVITAILLEMENT()
    {
    idRavitaillement=0; nbrproduitR=0; depense=0;
    }
    RAVITAILLEMENT::RAVITAILLEMENT(int idRavitaillement, int nbrproduitR, double depense)
    {this->idRavitaillement=idRavitaillement ; this->nbrproduitR=nbrproduitR;this->depense=depense;}
    int RAVITAILLEMENT :: getidRavitaillement(){return idRavitaillement;}
    int RAVITAILLEMENT :: getnbrproduitsR(){return nbrproduitR;}
    double RAVITAILLEMENT :: getdepense(){return depense;}
    void  RAVITAILLEMENT :: setidRavitaillement(int idRavitaillement ){this->idRavitaillement=idRavitaillement;}
    void RAVITAILLEMENT :: setnbrProduitsR(int nbrproduitR) {this->nbrproduitR=nbrproduitR;}
    void RAVITAILLEMENT :: setdepense(double depense){this->depense=depense;}




