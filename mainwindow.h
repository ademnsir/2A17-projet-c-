#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produits.h"
#include "ravitaillement.h"
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

    void on_pushButton_2_clicked();

    void on_pb_ajoutR_2_clicked();

private:
    Ui::MainWindow *ui;
    Produits P;
    RAVITAILLEMENT R;
};

#endif // MAINWINDOW_H
