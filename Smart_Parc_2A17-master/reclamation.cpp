#include "reclamation.h"

Reclamation::Reclamation()
{
id=0;
titre="";
corps="";
id_p=0;
}

Reclamation::Reclamation(int id,QString titre, QString corps, int id_p)
{
    this->id=id;
this->titre=titre;
    this->corps=corps;
    this->id_p=id_p;
}


bool Reclamation::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT into g_reclamations (id,titre,corps,id_p) "
                  "VALUES (:id, :titre ,:corps , :id_p)");
    query.bindValue(":id",id);
    query.bindValue(":titre",titre);
    query.bindValue(":corps",corps);
    query.bindValue(":id_p",id_p);
    return query.exec();

}

bool Reclamation::supprimer(int id_r)
{
    QSqlQuery query;
    query.prepare("select * from g_reclamations WHERE ID = :id ");
    query.bindValue(":id", id_r);
      if(query.exec())
      {
          if(query.next())  //==true
          {
              query.prepare("delete from g_reclamations WHERE ID = :id ");
                query.bindValue(":id", id_r);
                query.exec();
              return true;
          }

      }
     return false;
 }


QSqlQueryModel * Reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM g_reclamations");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("corps"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_p"));

    return model;
}


