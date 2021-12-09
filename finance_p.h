#ifndef FINANCE_P_H
#define FINANCE_P_H

#include "finance.h"
#include <QWidget>
#include "stati1.h"
namespace Ui {
class finance_p;
}

class finance_p : public QWidget
{
    Q_OBJECT

public:
    explicit finance_p(QWidget *parent = nullptr);
    ~finance_p();

private slots:
    void on_supprimer_clicked();

    void on_cnvpdf_clicked();

    void on_chercher_clicked();

    void on_tri_clicked();

    void on_pushButton_6_clicked();

    void on_modifier_clicked();

    void on_actualiser_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_translateEN_clicked();

    void on_pushButton_2_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::finance_p *ui;
    finance f;
    stati1 s;
};

#endif // FINANCE_P_H
