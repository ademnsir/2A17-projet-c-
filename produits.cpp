#include "produits.h"

Produits::Produits()
{
id=0; nbrProduit=0; nomProduit="";
}
Produits :: Produits(int id,QString nomProduit,int nbrProduit)
{this->id=id ; this->nomProduit=nomProduit;this->nbrProduit=nbrProduit;}
int Produits :: getid(){return id;}
QString Produits :: getnomProduit(){return nomProduit;}
int Produits :: getnbrProduit(){return nbrProduit;}
void  Produits :: setid(int id){this->id=id;}
void Produits :: setnomProduit(QString nomProduit) {this->nomProduit=nomProduit;}
void Produits :: setnbrProduit(int nbrProduit){this->nbrProduit=nbrProduit;}
