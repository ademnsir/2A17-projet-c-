#include "stati1.h"
#include "ui_stati1.h"
#include<iostream>
stati1::stati1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stati1)
{
    ui->setupUi(this);
}

stati1::~stati1()
{
    delete ui;
}
int stati1::Statistique1()
{
    QSqlQuery query;
    int count=0 ;

    QSqlQuery requete("SELECT * FROM FINANCE where GAIN>= 100 ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}

int stati1::Statistique2()
{
    QSqlQuery query;
    int count=0 ;

    QSqlQuery requete("SELECT * FROM FINANCE where GAIN< 100 ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}




void stati1::paintEvent(QPaintEvent *)
{

    int b=Statistique1();
    cout<<b<<endl ;
    int c=Statistique2();
    cout<<c<<endl ;


        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;

    QPainter painter(this);
    QRectF size=QRectF(150,40,this->width()-300,this->width()-300);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("GAIN <100") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("GAIN > 100") ;


}


void stati1::on_pushButton_clicked()
{
    hide();
}



