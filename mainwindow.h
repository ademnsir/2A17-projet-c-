#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produits.h"

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QIntValidator> /*controle saisie id*/
#include <QSqlQuery>

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_afficher_clicked();

   void on_tabProduits_activated(const QModelIndex &index);


    void on_pb_modifier_clicked();


    void on_pb_ajoutR_2_clicked();

    void on_tabR_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pb_vendre_clicked();

    //void on_recherche_textChanged(int id);

   void on_recherche_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Produits P;

};

#endif // MAINWINDOW_H
