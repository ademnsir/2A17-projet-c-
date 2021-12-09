#include "visite.h"


#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Visite::Visite()
{
id=0;
nb_visiteur=0;
prix=0;
date=QDate::currentDate();


}


Visite::Visite(int id,int nb_visiteur,QDate date,int prix)
{
    this->id=id;
    this->nb_visiteur=nb_visiteur;
     this->date=date;
    this->prix=prix;
}

int Visite::getid() {return id;}
int Visite::getnb() {return nb_visiteur;}
//QString Visite::getdate() {return date;}

void Visite::setid(int id) {this->id=id;}
void Visite::setnb(int nb_visiteur) {this->nb_visiteur=nb_visiteur;}
//void Visite::setdate(QString date) {this->date=date;}


 bool Visite::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO g_visites (ID , date_visite, nb_visiteurs,prix) "
              "VALUES (:id, :date, :nb_visiteur , :prix)");
query.bindValue(":id",id);
query.bindValue(":date",date);
query.bindValue(":nb_visiteur",nb_visiteur);
query.bindValue(":prix",prix);

return query.exec();

}






 bool Visite::modifier()
 {
     QSqlQuery query;
     query.prepare("select * from g_visites WHERE ID = :id ");
     query.bindValue(":id", id);
       if(query.exec())
       {
           if(query.next())  //==true
           {
     query.prepare("UPDATE g_visites SET   date_visite= :date, nb_visiteurs= :nb_visiteur , prix= :prix WHERE id=:id ");
     query.bindValue(":id",id);
     query.bindValue(":date",date);
     query.bindValue(":nb_visiteur",nb_visiteur);
     query.bindValue(":prix",prix);
     query.exec();
     return true;
           }
       }
    return false;
 }




 bool Visite::supprimer(int id_s)
 {
     QSqlQuery query;
     query.prepare("select * from g_visites WHERE ID = :id ");
     query.bindValue(":id", id_s);
       if(query.exec())
       {
           if(query.next())  //==true
           {
     query.prepare("delete from g_visites WHERE ID = :id ");
       query.bindValue(":id", id_s);
      query.exec();
      return true;
           }
       }
       return false;

 }




QSqlQueryModel * Visite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM g_visites");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_visite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nb_visiteurs"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

    return model;
}



QSqlQueryModel * Visite::trier_nb()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM  g_visites ORDER BY nb_visiteurs ASC");

   return model;
}


QSqlQueryModel * Visite::trier_nbd()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM  g_visites ORDER BY nb_visiteurs DESC");

   return model;
}



QSqlQueryModel * Visite::rechercher(int id)
{




    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from g_visites where id =:id ");
    query.bindValue(":id",id);
    query.exec();


    model->setQuery(query);



return model;
}
