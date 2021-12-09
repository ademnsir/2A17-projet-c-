#ifndef WINDOWRECLAMATION_H
#define WINDOWRECLAMATION_H

#include <QDialog>
#include <QMessageBox>
#include<QPixmap>
#include "visite.h"
#include "reclamation.h"
#include <QSqlQueryModel>
#include "arduino.h"
#include <QDate>
#include <QDateEdit>
#include <QDebug>
namespace Ui {
class windowreclamation;
}

class windowreclamation : public QDialog
{
    Q_OBJECT

public:
    explicit windowreclamation(QWidget *parent = nullptr);
    ~windowreclamation();

private slots:

  QSqlQueryModel *combo();

     void on_tab_rec_activated(const QModelIndex &index);

     void on_ajouter_rec_clicked();

     void on_supp_rec_2_clicked();

     void on_affichage_2_clicked();


private:
    Ui::windowreclamation *ui;
    Visite V;
    Reclamation R;
    QByteArray data;
    arduino a;
};

#endif // WINDOWRECLAMATION_H
