#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produits.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    Produits P;
};

#endif // MAINWINDOW_H
