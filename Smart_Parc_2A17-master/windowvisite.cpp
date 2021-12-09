#include "windowvisite.h"
#include "ui_windowvisite.h"
#include <QSqlQueryModel>
#include "arduino.h"
#include <QDate>
#include <QDateEdit>
#include "visite.h"

windowvisite::windowvisite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowvisite)
{
    ui->setupUi(this);
    chart();

        ui->tab_visite->setModel(V.afficher());

        QPixmap pix("C:/Users/DELL/OneDrive/Documents/maquetteQT/violet.jpg");
        QPixmap pix1("C:/Users/DELL/OneDrive/Documents/maquetteQT/violet.jpg");
        QPixmap pix2("C:/Users/DELL/OneDrive/Documents/maquetteQT/violet.jpg");
        QPixmap pix3("C:/Users/DELL/OneDrive/Documents/maquetteQT/violet.jpg");
           ui->label_11->setPixmap(pix.scaled(1920,900,Qt::KeepAspectRatio));
           ui->label_12->setPixmap(pix1.scaled(1920,900,Qt::KeepAspectRatio));
           ui->label_14->setPixmap(pix2.scaled(1920,900,Qt::KeepAspectRatio));
             ui->label_15->setPixmap(pix3.scaled(1920,900,Qt::KeepAspectRatio));

    ui->id_ajout->setValidator(new QIntValidator(100,9999,this));

}

windowvisite::~windowvisite()
{
    delete ui;
}



void windowvisite::update_label1()
{int count=0;
     QString msg="";

    data = a.read_from_arduino();
    qDebug() << " ";
  QSqlQuery query;
    query.prepare("select * from g_visites ");
    if (query.exec())
    {
        while(query.next())
        {
            count++;

        }

      if(data  == "2")

       {

            QMessageBox::information(nullptr, QObject::tr("visite"),
                            QObject::tr("mouvement !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
         count++;
           QString n=QString::number(count);
           ui->text->setText("le nombre de visites est"+n);

       }
     //   else if(data  ==  "3"){}
  }


}








void windowvisite::on_ajouter_clicked()
{



    int id=ui->id_ajout->text().toInt();
    QDate date=ui->date_ajout->date();
    int nb_visiteur=ui->nb_ajout->text().toInt();
    int prix=ui->prix_ajout->text().toInt();

 // QByteArray n=QByteArray::number(nb_visiteur);

//A.write_to_arduino(n);

 // V.save( ui->nb_ajout->text() );

    Visite V1(id,nb_visiteur,date,prix);


     bool test=V1.ajouter();

    if(test)
    {ui->tab_visite->setModel(V.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter une visite"),
                    QObject::tr(" ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

     a.write_to_arduino("1");

    }
    else
       { QMessageBox::critical(nullptr, QObject::tr("ajouter une visite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    a.write_to_arduino("0");
}


}



void windowvisite::on_supprimer_clicked()
{

    int id=ui->id_supp->text().toInt();
    bool test=V.supprimer(id);
    if(test)
    {ui->tab_visite->setModel(V.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une visite"),
                    QObject::tr(" supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un visite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void windowvisite::on_modifier_clicked()
{

   int  id=ui->id_modifier->text().toInt();
   QDate date=ui->date_modifier->date();
    int nb_visiteur=ui->nb_modifier->text().toInt();
   int  prix=ui->prix_modifier->text().toInt();
   Visite V1(id,nb_visiteur,date,prix);
   bool test= V1.modifier();
    if(test)
    {ui->tab_visite->setModel(V.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier une visite"),
                    QObject::tr(" modifie.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    QMessageBox::critical(nullptr, QObject::tr("modifierun visite"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

 void windowvisite::on_affichage_clicked()
{
    ui->tab_visite->setModel(V.afficher());
    alerte();

}



void windowvisite::on_tri_nb_clicked()
{
      ui->tab_visite->setModel(V.trier_nb());
}

void windowvisite::on_tri_nb_2_clicked()
{
    ui->tab_visite->setModel(V.trier_nbd());
}




void windowvisite::on_rechercher_clicked()
{
    int id=ui->id_rechercher->text().toInt();
    ui->tab_visite->setModel(V.rechercher(id));
      ui->id_rechercher->clear();
}




 void windowvisite::chart()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
     gradient.setColorAt(0, QColor(90, 90, 90));
     gradient.setColorAt(0.38, QColor(105, 105, 105));
     gradient.setColorAt(1, QColor(70, 70, 70));
     ui->stat->setBackground(QBrush(gradient));

     // create empty bar chart objects:

     QCPBars *bar = new QCPBars(ui->stat->xAxis, ui->stat->yAxis);
     bar->setAntialiased(false);
     bar->setStackingGap(1);
     bar->setName("Moyenne des visiteurs");
     bar->setPen(QPen(QColor(70, 9, 60).lighter(110)));
     bar->setBrush(QColor(1, 80, 50));


     // prepare x axis with  labels:
     QVector<double> ticks;
     QVector<QString> labels;

     QSqlQuery query2("select  prix from g_visites   ");
     while (query2.next()) {
         int  nbr_fautee=0;

              nbr_fautee = query2 .value(3).toInt();

                            ticks<<   nbr_fautee ;

                              }




   //  ticks << 1<<2   ;
     labels << "visite"   ;
     QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
     textTicker->addTicks(ticks, labels);
     ui->stat->xAxis->setTicker(textTicker);
     ui->stat->xAxis->setTickLabelRotation(60);
     ui->stat->xAxis->setSubTicks(false);
     ui->stat->xAxis->setTickLength(0, 8);
  //   ui->stat->xAxis->setRange(1, 10);
     ui->stat->xAxis->setBasePen(QPen(Qt::white));
     ui->stat->xAxis->setTickPen(QPen(Qt::white));
     ui->stat->xAxis->grid()->setVisible(true);
     ui->stat->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
     ui->stat->xAxis->setTickLabelColor(Qt::white);
     ui->stat->xAxis->setLabelColor(Qt::white);

     // prepare y axis:
   //  ui->stat->yAxis->setRange(0,12.1);
      ui->stat->yAxis->setPadding(5);
     ui->stat->yAxis->setLabel("nombre de visiteur");

     ui->stat->yAxis->setBasePen(QPen(Qt::white));
     ui->stat->yAxis->setTickPen(QPen(Qt::white));
     ui->stat->yAxis->setSubTickPen(QPen(Qt::white));
     ui->stat->yAxis->grid()->setSubGridVisible(true);
       ui->stat->yAxis->setTickLength(0, 4);
     ui->stat->yAxis->setTickLabelColor(Qt::white);
     ui->stat->yAxis->setLabelColor(Qt::white);
     ui->stat->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
     ui->stat->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

     // Add data:
     QVector<double> barData;

     QSqlQuery query1("select nb_visiteurs  from g_visites   ");
     while (query1.next()) {
         int  nbr_faute=0;

              nbr_faute = query1 .value(2).toInt();

                            barData<<   nbr_faute ;

                              }
     bar->setData(ticks,barData );


     ui->stat->legend->setVisible(true);
     ui->stat->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter); //Returns the alignment of the element with the specified index
     ui->stat->legend->setBrush(QColor(255, 255, 255, 100));
     ui->stat->legend->setBorderPen(Qt::NoPen);
     QFont legendFont = font();
     legendFont.setPointSize(10);
     ui->stat->legend->setFont(legendFont);
     ui->stat->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void windowvisite::alerte()
{
    QSqlQuery query;
    query.prepare("select * from g_visites where nb_visiteurs>5 ");
    if (query.exec())
    {
       int count=0;
        while(query.next())
        {
            count++;

        }
        if (count>5)
        {
            QMessageBox::information(nullptr, QObject::tr("alerte"),
                        QObject::tr( "affecter plus d'employés"), QMessageBox::Cancel);

        }}

}


