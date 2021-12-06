#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "visite.h"
#include "reclamation.h"
#include "arduino.h"
#include <QDate>
#include <QDateEdit>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
 void on_affichage_clicked();

   void on_tri_nb_clicked();

   void on_rechercher_clicked();

  QSqlQueryModel *combo();

     void on_tab_rec_activated(const QModelIndex &index);

     void on_ajouter_rec_clicked();

     void on_supp_rec_2_clicked();


    void  chart ();

     void on_affichage_2_clicked();

     void on_tri_nb_2_clicked();

     void update_label();
     void alerte();


private:
    Ui::MainWindow *ui;
    Visite V;
    Reclamation R;
    QByteArray data;
   Arduino A;

};

#endif // MAINWINDOW_H
