#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include <QSqlQueryModel>
#include<QDateEdit>
#include<QDate>

class personnel
{
public:
    //constructeur
   personnel();
   personnel(int id ,QString nomprenom,QString fonctionalitte,QString numtel,QString ville,QString cin,QString email,QString adresse,QDate datenais,float salaire,QString etat);


   //crud
   bool ajouter();
   QSqlQueryModel *afficher();
   void supprimer();
   QSqlQueryModel* chercher();
    void  modifierPersonnel();


int getid()
{
return id;
}
   //setters
   void setid(int);

private:
   int id;
   QString nomprenom;
   QString fonctionalitte;
   QString numtel;
   QString ville;
   QString cin;
   QString email;
   QString adresse;
   QDate datenais;
   float salaire;
   QString etat;
};




#endif // PERSONNEL_H
