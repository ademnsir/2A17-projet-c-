#include "finance.h"

finance::finance()
{

}
//////////////////////////////////////////////////////////////////////////////
/// Cruds
//////////////////////////////////////////////////////////////////////////////
/////////afficher//////////
QSqlQueryModel * finance::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from FINANCE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRIX"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("GAIN"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DEPENCES"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NB_VISITEUR"));

    return model;
}
////////ajouter///////////
bool finance::ajouter(int ID ,int PRIX,int DEPENCES,QDate DATE_F ,int NB_VISITEUR)
{
    QSqlQuery query;
    query.prepare("INSERT INTO FINANCE(ID,PRIX,GAIN,DEPENCES,DATE_F,NB_VISITEUR)"
                  "VALUES (:id,:prix,:gain, :depences,:date_f,:nb_visiteur)");

                        query.bindValue(":id",ID);
                        query.bindValue(":nb_visiteur",NB_VISITEUR);
                        query.bindValue(":prix", PRIX );
                        int gain = (PRIX * NB_VISITEUR)-DEPENCES;
                         query.bindValue(":gain",gain);
                        query.bindValue(":depences", DEPENCES);
                        query.bindValue(":date_f", DATE_F);




    return query.exec();
}
///////supprimer/////////
bool finance::supprimer(int ID)
{
    QSqlQuery query;
    query.prepare("delete from FINANCE where (ID=:id)");
    query.bindValue(":id",ID);

    return query.exec();
}

//////modifier//////////
bool finance::modifier(int ID ,int PRIX,int DEPENCES,QDate DATE_F ,int NB_VISITEUR)
{
    QSqlQuery query;
    query.prepare("UPDATE FINANCE SET PRIX=:prix,GAIN=:gain,DEPENCES=:depences ,DATE_F=:date_f WHERE ID=:id");
    query.bindValue(":id",ID);
    query.bindValue(":nb_visiteur",NB_VISITEUR);
    query.bindValue(":prix", PRIX );
    int gain = (PRIX * NB_VISITEUR)-DEPENCES;
     query.bindValue(":gain",gain);
    query.bindValue(":depences", DEPENCES);
    query.bindValue(":date_f", DATE_F);


    return query.exec();

}

///////////////////////////////////
QSqlQueryModel * finance::Rech(QString choix,QString ch)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    if (choix == "ID"){
    model->setQuery("select * from FINANCE where ID like '"+ch+"%'");
    }
    else if (choix =="NB_VISITEUR")
    {
        model->setQuery("select * from FINANCE where NB_VISITEUR like '"+ch+"%'");
    }
    else if (choix =="PRIX")
    {
        model->setQuery("select * from FINANCE where PRIX like '"+ch+"%'");
    }
    if (choix == "DATE"){
    model->setQuery("select * from FINANCE where DATE_F like '"+ch+"%'");
    }
    else if (choix == "GAIN"){
        model->setQuery("select * from FINANCE where GAIN like '"+ch+"%'");
    }
    else if  (choix =="DEPENCES" ){
        model->setQuery("select * from FINANCE where DEPENCES like '"+ch+"%'");
    }

    return model;
}
QSqlQueryModel * finance::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FINANCE order by ID");
    return model;
}
/////////////////////////////////////
QSqlQueryModel * finance::triPRIX()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FINANCE order by PRIX");
    return model;
}

QSqlQueryModel * finance::triGAIN()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FINANCE order by GAIN");
    return model;
}

QSqlQueryModel * finance::triDATE()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from FINANCE order by DATE_F");
    return model;
}

void finance::convPDF (){
    QString str;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int Month = 1 + ltm->tm_mon;

    int Day= ltm->tm_mday ;
               str.append("<!DOCTYPE html><html lang='en'><head><style>#ipi-table > thead > tr, #ipi-table > thead > tr > td {font-size: .9em;font-weight: 400;background: #51596a;text-transform: uppercase;color: #ffffff;}#ipi-table > tbody > tr > td {max-height: 200px;vertical-align: middle!important;}</style></head><body><div class='container'><div class='row'><div class='col-md-12'><img src='C:/Users/Th3_D0cTor/OneDrive/Desktop/esprit.png'><h1>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; &nbsp; &nbsp; GESTION FINANCE  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</h1> </div></div></div><div class='container'><div class='card' id='TableSorterCard'><div class='row'><div class='col-12'><div><table class='table table tablesorter' id='ipi-table'><thead class='thead-dark'><tr><th>ID &nbsp; &nbsp;</th><th class='filter-false'>PRIX &nbsp; &nbsp;</th><th class='filter-false'>GAIN &nbsp; &nbsp;</th><th class='filter-false sorter-false'>DEPENCES &nbsp; &nbsp;</th><th class='filter-false sorter-false'>DATE_F &nbsp; &nbsp;</th><th class='filter-false sorter-false'>NB_VISITEUR &nbsp; &nbsp;</th></tr></thead><tbody>");




               QSqlQuery* query=new QSqlQuery();
               query->exec("SELECT * FROM FINANCE");

               while(query->next())
               {
               str.append("<tr><td>");
               str.append(query->value(0).toString()) ;
               str.append("</td><td>") ;
               str.append(query->value(1).toString());
               str.append("</td><td>") ;
               str.append(query->value(2).toString());
               str.append("</td><td>") ;
               str.append(query->value(3).toString());
               str.append("</td><td>") ;
               str.append(query->value(4).toString());
               str.append("</td><td>") ;
               str.append(query->value(5).toString());
               str.append("</td><td>") ;
               str.append(query->value(6).toString());
               str.append("</td><td>") ;






               }
            str.append("</tbody></table></div></div></div></div><p><h3>"+  QString::number(Day)+"/"+QString::number(Month)+"/"+QString::number(year)+"</h3></body></html>") ;

            QPrinter printer ;
            printer.setOrientation(QPrinter::Portrait);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4) ;

            QString path=QFileDialog::getSaveFileName(NULL,"Convertir a PDF","..","PDF(*.pdf)");

            if (path.isEmpty()) return ;
            printer.setOutputFileName(path) ;

            QTextDocument doc;
            doc.setHtml(str) ;
            doc.print(&printer);
}

bool finance::verifNum(QString n)
{
    bool test = true;
    int i;
    for(i=0;i<n.length();i++)
    {
        if (!(n[i]=="0")&&!(n[i]=="1")&&!(n[i]=="2")&&!(n[i]=="3")&&!(n[i]=="4")&&!(n[i]=="5")&&!(n[i]=="6")&&!(n[i]=="7")&&!(n[i]=="8")&&!(n[i]=="9"))
    {
            test = false;
        }
    }
    return test;
}


