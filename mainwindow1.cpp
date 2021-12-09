#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "QWidget"
#include <QMessageBox>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QSqlQuery>
#include <QTabWidget>
#include<QDebug>
#include <QPrintDialog>
#include<QFileDialog>
#include<QPdfWriter>
#include<QPrinter>
#include<QFile>
#include "smtp.h"
#include <QAbstractSocket>
#include <QSslSocket>
#include<QStringList>
#include <iostream>
#include<QTextDocument>
#include<QUrl>
#include <QPixmap>
#include <QValidator>
#include <QIntValidator>
#include"produit.h"




MainWindow1::MainWindow1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow1)
{
    ui->setupUi(this);


    ui->id->setValidator (new QIntValidator(0,99999999, this));

    //connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    //connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    //connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));


    socket = new QTcpSocket(this);

    // This is how we tell Qt to call our readyRead() and connected()
    // functions when the socket has text ready to be read, and is done
    // connecting to the server (respectively):
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));


    ui->table_produit->setModel(C.afficher());

}

MainWindow1::~MainWindow1()
{
    delete ui;
}


void MainWindow1::on_pushButton_clicked()
{

    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    int prix=ui->prix->text().toInt();

    produit C(id, prix, nom);
    bool test=C.ajouter();
    QMessageBox msgBox;
    if(test)
  {
    msgBox.setText("ajout avec succée");
    ui->table_produit->setModel(C.afficher());
    ui->id->clear();
    ui->nom->clear();
    ui->prix->clear();
    // Put the focus back into the input box so they can type again:
   ui->id->setFocus();
   C.ajouter_historique("ajout d'un produit");
    }

    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow1::on_pushButton_4_clicked()
{

    QMessageBox msgBox;
    produit C1;
    C1.setid(ui->idsupp->text().toInt());
    bool test=C1.supprimer(C1.getid());
    if (test){
        ui->idsupp->clear();
        ui->idsupp->setFocus();

        ui->table_produit->setModel(C.afficher());
            msgBox.setText("produit supprimé");
            msgBox.exec();
            C.ajouter_historique("suppression d'un produit");
           }
}

void MainWindow1::on_pushButton_2_clicked()
{
    produit C;
    QSqlQuery query;
    int id=ui->idmodif->text().toInt();
    QString id_string=QString::number(id);
   if(C.recherche_id(id))
   {
       query.prepare("SELECT * FROM PRODUIT WHERE ID like :id");
       query.bindValue(0,id_string);
       query.exec();
       while(query.next())
   {
       ui->prixmodif->setText(query.value(1).toString());
       ui->nommodif->setText(query.value(2).toString());


    }
   }
}

void MainWindow1::on_pushButton_3_clicked()
{
    produit C;
    QMessageBox msg;
    C.setid(ui->idmodif->text().toInt());
    C.setprix(ui->prixmodif->text().toInt());
    C.setnom(ui->nommodif->text());

    bool test=C.modifier(C.getid());
    C.ajouter_historique("modification d'un produit");
    if(test)
    {
        msg.setText("modification avec succès");
        ui->table_produit->setModel(C.afficher());
        ui->idmodif->clear();
        ui->nommodif->clear();
        ui->prixmodif->clear();
        ui->idmodif->setFocus();

    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

void MainWindow1::on_pushButton_8_clicked()
{

    QMessageBox msgBox ;

  QSqlQueryModel *model = new QSqlQueryModel();
           model->setQuery("SELECT * FROM PRODUIT order by id ASC");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_production"));
           ui->table_produit->setModel(model);
           ui->table_produit->show();
           msgBox.setText("Tri avec succès.");
           msgBox.exec();
}

void MainWindow1::on_pushButton_6_clicked()
{

    QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("SELECT * FROM PRODUIT order by nom ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_production"));
             ui->table_produit->setModel(model);
             ui->table_produit->show();
             msgBox.setText("Tri avec succès.");
             msgBox.exec();
}

void MainWindow1::on_pushButton_7_clicked()
{
    QMessageBox msgBox ;

    QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("SELECT * FROM PRODUIT order by prix ASC");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_production"));

             ui->table_produit->setModel(model);
             ui->table_produit->show();
             msgBox.setText("Tri avec succès.");
             msgBox.exec();
}

void MainWindow1::on_pushButton_5_clicked()
{
    produit C;
        if (ui->comboBox->currentText()=="rechercher par id")
        {
            int id=ui->lineEdit->text().toInt();
            if (C.recherche_id(id))
            {
                ui->table_produit->setModel(C.afficher_id(id));
            }
        }
        else if(ui->comboBox->currentText()=="rechercher par nom")
        {
            QString nom=ui->lineEdit->text();
            if (C.recherche_nom(nom))
            {
                ui->table_produit->setModel(C.afficher_nom(nom));
            }

        }
        else if(ui->comboBox->currentText()=="rechercher par prix")
        {
            int prix=ui->lineEdit->text().toInt();
            if(C.recherche_prix(prix))
            {
                ui->table_produit->setModel(C.afficher_prix(prix));
            }
        }
}

void MainWindow1::on_pushButton_9_clicked()
{
    QString strStream;
                  QTextStream out(&strStream);

                  const int rowCount = ui->table_produit->model()->rowCount();
                  const int columnCount = ui->table_produit->model()->columnCount();

                  out <<  "<html>\n"
                      "<head>\n"
                      "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                      <<  QString("<title>%1</title>\n").arg("strTitle")
                      <<  "</head>\n"
                      "<body bgcolor=#ffffff link=#5000A0>\n"

                     //     "<align='right'> " << datefich << "</align>"
                      "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                  // headers
                  out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                  for (int column = 0; column < columnCount; column++)
                      if (!ui->table_produit->isColumnHidden(column))
                          out << QString("<th>%1</th>").arg(ui->table_produit->model()->headerData(column, Qt::Horizontal).toString());
                  out << "</tr></thead>\n";

                  // data table
                  for (int row = 0; row < rowCount; row++) {
                      out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                      for (int column = 0; column < columnCount; column++) {
                          if (!ui->table_produit->isColumnHidden(column)) {
                              QString data = ui->table_produit->model()->data(ui->table_produit->model()->index(row, column)).toString().simplified();
                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                      }
                      out << "</tr>\n";
                  }
                  out <<  "</table> </center>\n"
                      "</body>\n"
                      "</html>\n";

            QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
              if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

             QPrinter printer (QPrinter::PrinterResolution);
              printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);

             QTextDocument doc;
              doc.setHtml(strStream);
              doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
              doc.print(&printer);
              C.ajouter_historique("pdf generé");

}

void MainWindow1::on_pushButton_10_clicked()
{

    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;

}

void MainWindow1::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow1::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->text(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->text());
    C.ajouter_historique("email envoyé");
}


void MainWindow1::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


/*void MainWindow1::readyRead()
{
    // We'll loop over every (complete) line of text that the server has sent us:
    while(socket->canReadLine())
    {
        // Here's the line the of text the server sent us (we use UTF-8 so
        // that non-English speakers can chat in their native language)
        QString line = QString::fromUtf8(socket->readLine()).trimmed();

        // These two regular expressions describe the kinds of messages
        // the server can send us:

        //  Normal messges look like this: "username:The message"
        QRegExp messageRegex("^([^:]+):(.*)$");

        // Any message that starts with "/users:" is the server sending us a
        // list of users so we can show that list in our GUI:
        QRegExp usersRegex("^/users:(.*)$");

        // Is this a users message:
        if(usersRegex.indexIn(line) != -1)
        {
            // If so, udpate our users list on the right:
            QStringList users = usersRegex.cap(1).split(",");
            ui->userListWidget->clear();
            foreach(QString user, users)
                new QListWidgetItem(QPixmap(":/user.png"), user, ui->userListWidget);
        }
        // Is this a normal chat message:
        else if(messageRegex.indexIn(line) != -1)
        {
            // If so, append this message to our chat box:
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);

            ui->roomTextEdit->append("<b>" + user + "</b>: " + message);
        }
    }
}

void MainWindow1::connected()
{
    // Flip over to the chat page:
    ui->chatPage_3->setCurrentWidget(ui->chatPage);

    // And send our username to the chat server.
    socket->write(QString("/me:" + ui->userLineEdit->text() + "\n").toUtf8());
}
*/

void MainWindow1::on_pushButton_11_clicked()
{
ui->stackedWidget->setCurrentIndex(1);
ui->tableView->setModel(C.afficher_historique());
}

void MainWindow1::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow1::update_label(){
data=A.read_from_arduino();
if(data=="1"){
    ui->etat_porte->setText("porte ouverte");}
    else if(data=="0"){
     ui->etat_porte->setText("porte fermée");}


}

void MainWindow1::on_pushButton_13_clicked()
{
    A.write_to_arduino("1");
}
