#ifndef WINDOWCOMMIDITES_H
#define WINDOWCOMMIDITES_H
#include "produits.h"

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QIntValidator> /*controle saisie id*/
#include <QSqlQuery>
#include <QDialog>

namespace Ui {
class windowcommidites;
}

class windowcommidites : public QDialog
{
    Q_OBJECT

public:
    explicit windowcommidites(QWidget *parent = nullptr);
    ~windowcommidites();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_afficher_clicked();

    void on_tabProduits_activated(const QModelIndex &index);

    void on_pb_modifier_clicked();

    void on_pb_ajoutR_2_clicked();

    void on_pb_recherche_clicked();

    void on_pb_stock_clicked();

    void on_pb_vendre_clicked();

private:
    Ui::windowcommidites *ui;
    Produits P;
};

#endif // WINDOWCOMMIDITES_H
