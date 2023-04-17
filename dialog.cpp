#include<ui_dialog.h>
#include "Produit.h"
#include <vector>
#include <QTableWidget>
#include <QLabel>
#include <QDialog>
#include"ui_dialog.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setProduit(const std::vector<Produit> &produits);
    ~Dialog();

private:

    Ui::Dialog *ui;
    QTableWidget *tableWidget;
    QLabel *idLabel;
    QLabel *nomLabel;
    QLabel *prixLabel;
    QLabel *prixLivraisonLabel;
    QLabel *descriptionLabel;
};

#endif // PRODUCTTABLEWIDGET_H
    // DIALOG_H



