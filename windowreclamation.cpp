#include "windowreclamation.h"
#include "ui_windowreclamation.h"

windowreclamation::windowreclamation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowreclamation)
{
    ui->setupUi(this);
    ui->tab_rec->setModel(R.afficher());

       ui->id_per->setModel( combo());


       QPixmap pix("C:/Users/DELL/OneDrive/Documents/maquetteQT/violet.jpg");
          ui->label_1->setPixmap(pix.scaled(1920,900,Qt::KeepAspectRatio));
          ui->label_2->setPixmap(pix.scaled(1920,900,Qt::KeepAspectRatio));
          ui->label_23->setPixmap(pix.scaled(1920,900,Qt::KeepAspectRatio));

           ui->idr_ajout->setValidator(new QIntValidator(100,9999,this));
}

windowreclamation::~windowreclamation()
{
    delete ui;
}
QSqlQueryModel *windowreclamation::combo()
{
   QSqlQueryModel *model=new  QSqlQueryModel();
   QSqlQuery query;

   query.prepare("select id from personnel");
   query.exec();
   model->setQuery(query);
   return model;

}



void windowreclamation::on_ajouter_rec_clicked()
{
    int id=ui->idr_ajout->text().toInt();
     QString titre=ui->titre->text() ;
     QString corps=ui->corps->toPlainText() ;
      int id_p=ui->id_per->currentText().toInt();

      Reclamation R1(id,titre,corps,id_p);
      bool test=R1.ajouter();
      if (test)
      {ui->tab_rec->setModel(R.afficher());

          QMessageBox::information(nullptr, QObject::tr("Ajouter une reclamation"),
                      QObject::tr(" ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
      else
         { QMessageBox::critical(nullptr, QObject::tr("ajouter une reclamation"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



      }
}



void windowreclamation::on_supp_rec_2_clicked()
{
int id_r=ui->supp_rec->text().toInt();
bool test=R.supprimer(id_r);
if(test)
{ui->tab_rec->setModel(R.afficher());
    QMessageBox::information(nullptr, QObject::tr("Supprimer une reclamation"),
                QObject::tr(" supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   { QMessageBox::critical(nullptr, QObject::tr("Supprimer un reclamation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


}

void windowreclamation::on_affichage_2_clicked()
{
    ui->tab_rec->setModel(R.afficher());
}



void windowreclamation::on_tab_rec_activated(const QModelIndex &index)
{
    QSqlQuery query;
QString res=ui->tab_rec->model()->data(index).toString();
    query.prepare("select * from personnel   WHERE id='"+res+"' ");

    if (query.exec())
    {
        while(query.next())  //while we are getting the data
        {
            ui->text_id->setText(query.value(0).toString());
             ui->text_nom->setText(query.value(1).toString());
              ui->text_fonc->setText(query.value(2).toString());
               ui->text_tel->setText(query.value(3).toString());
                ui->text_mail->setText(query.value(4).toString());
                 ui->text_ville->setText(query.value(5).toString());
                  ui->text_ad->setText(query.value(6).toString());
                   ui->text_cin->setText(query.value(7).toString());
                    ui->text_date->setText(query.value(8).toString());
                     ui->text_sal->setText(query.value(9).toString());
                      ui->text_etat->setText(query.value(10).toString());

         }

    }
}
