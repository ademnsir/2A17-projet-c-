#ifndef WINDOWVISITE_H
#define WINDOWVISITE_H
#include "visite.h"
#include "reclamation.h"
#include <QDialog>
#include"arduino.h"
#include <QSqlQueryModel>
#include <QDate>
#include <QDateEdit>

namespace Ui {
class windowvisite;
}

class windowvisite : public QDialog
{
    Q_OBJECT

public:
    explicit windowvisite(QWidget *parent = nullptr);
    ~windowvisite();

private slots:
    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
 void on_affichage_clicked();

   void on_tri_nb_clicked();

   void on_rechercher_clicked();



    void  chart ();


     void on_tri_nb_2_clicked();

     void update_label1();
   //  void aff();
     void alerte();


private:
    Ui::windowvisite *ui;
    Visite V;
      Reclamation R;
      QByteArray data;
      arduino a;
};

#endif // WINDOWVISITE_H
