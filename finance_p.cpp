#include "finance_p.h"
#include "ui_finance_p.h"
#include "finance.h"

finance_p::finance_p(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finance_p)
{
    ui->setupUi(this);
    ui->stackedWidget->insertWidget(1,&s);
}

finance_p::~finance_p()
{
    delete ui;
}

void finance_p::on_supprimer_clicked()
{
    int id=ui->supp->text().toInt();
    bool test=f.supprimer(id);
    ui->tableView->setModel(f.afficher());
}


void finance_p::on_cnvpdf_clicked()
{
    f.convPDF();
}


void finance_p::on_chercher_clicked()
{
    QString choix = ui->comboBox->currentText();
    QString ch = ui->rech->text();
    ui->tableView->setModel(f.Rech(choix,ch));
}


void finance_p::on_tri_clicked()
{

    QString choix = ui->comboBox_2->currentText();
    if (choix =="ID" ){
        ui->tableView->setModel(f.triID());
    }
    else if(choix=="GAIN")
    {
        ui->tableView->setModel(f.triGAIN());
    }
    else if(choix=="PRIX")
    {
        ui->tableView->setModel(f.triPRIX());
    }
    else if(choix=="DATE")
    {
        ui->tableView->setModel(f.triDATE());
    }
}


void finance_p::on_pushButton_6_clicked()
{
    QDate date=ui->calendarWidget->selectedDate();
    int id=ui->id->text().toInt();
    int nb = ui->nb_visiteur->text().toInt();
    float prix = ui->prix->text().toFloat();
    int dep = ui->depences->text().toInt();
    bool t=true;
    if (id<=0)
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                QObject::tr("id est numerique\n""click cancel to exit."),QMessageBox::Cancel);
        t=false;
    }
    if (nb<=0)
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                QObject::tr("nombre visiteur est numerique\n""click cancel to exit."),QMessageBox::Cancel);
        t=false;
    }
    if (dep<=0)
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                QObject::tr("depence est numerique\n""click cancel to exit."),QMessageBox::Cancel);
        t=false;
    }

    if (t){
    bool test=f.ajouter(id,prix,dep,date,nb);
    if (test){
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("ajouter est  effectue\n""click cancel to exit."),QMessageBox::Cancel);
        ui->tableView->setModel(f.afficher());
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                 QObject::tr("ajouter non effectuee! \n"
                                              "click Cancel to exit"),QMessageBox::Cancel);
}
    }
}


void finance_p::on_modifier_clicked()
{
    QDate date=ui->calendarWidget->selectedDate();
    int id=ui->id->text().toInt();
    int nb = ui->nb_visiteur->text().toInt();
    float prix = ui->prix->text().toFloat();
    int dep = ui->depences->text().toInt();
    bool t=true;
    if (id<=0)
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                QObject::tr("id est numerique\n""click cancel to exit."),QMessageBox::Cancel);
        t=false;
    }
    if (nb<=0)
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                QObject::tr("nombre visiteur est numerique\n""click cancel to exit."),QMessageBox::Cancel);
        t=false;
    }
    if (dep<=0)
    {
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                QObject::tr("depence est numerique\n""click cancel to exit."),QMessageBox::Cancel);
        t=false;
    }

     if (t){
     bool test=f.modifier(id,prix,dep,date,nb);
     if (test){
         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("modifier effectue\n""click cancel to exit."),QMessageBox::Cancel);
         ui->tableView->setModel(f.afficher());
     }
     else{
         QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                  QObject::tr("modifier non effectuee! \n"
                                               "click Cancel to exit"),QMessageBox::Cancel);
 }
     }

}


void finance_p::on_actualiser_clicked()
{
     ui->tableView->setModel(f.afficher());
}


void finance_p::on_tabWidget_tabBarClicked(int index)
{
    ui->stackedWidget->setCurrentIndex(1);
}


void finance_p::on_translateEN_clicked()
{
    ui->chercher->setText("Search");
    ui->pushButton_6->setText("ADD");
    ui->modifier->setText("Update");
    ui->supprimer->setText("Delete");
    ui->actualiser->setText("Refresh");
    ui->tri->setText("TRI");
    ui->label->setText("ID");
    ui->label_2->setText("Visitor Number");
    ui->label_3->setText("Price");
    ui->label_4->setText ("expenses");


}


void finance_p::on_pushButton_2_clicked()
{
    ui->chercher->setText("Chercher");
    ui->pushButton_6->setText("Ajouter");
    ui->modifier->setText("Modifier");
    ui->supprimer->setText("Supprimer");
    ui->actualiser->setText("Actualiser");
    ui->tri->setText("TRI");
    ui->label->setText("ID");
    ui->label_2->setText("Nombre visiteur");
    ui->label_3->setText("Prix");
}


void finance_p::on_rech_textChanged(const QString &arg1)
{
    QString choix = ui->comboBox->currentText();
    QString ch = ui->rech->text();
    ui->tableView->setModel(f.Rech(choix,ch));
}


void finance_p::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString choix = ui->comboBox_2->currentText();
    if (choix =="ID" ){
        ui->tableView->setModel(f.triID());
    }
    else if(choix=="GAIN")
    {
        ui->tableView->setModel(f.triGAIN());
    }
    else if(choix=="PRIX")
    {
        ui->tableView->setModel(f.triPRIX());
    }
    else if(choix=="DATE")
    {
        ui->tableView->setModel(f.triDATE());
    }
}

