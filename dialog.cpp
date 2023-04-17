#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QTableWidgetItem>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels({"ID", "Nom", "Prix", "Prix Livraison", "Description"});
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(tableWidget, &QTableWidget::itemSelectionChanged, [this]() {
        auto selectedItems = tableWidget->selectedItems();
        if (!selectedItems.isEmpty()) {
            idLabel->setText(selectedItems[0]->text());
            nomLabel->setText(selectedItems[1]->text());
            prixLabel->setText(selectedItems[2]->text());
            prixLivraisonLabel->setText(selectedItems[3]->text());
            descriptionLabel->setText(selectedItems[4]->text());
        }
    });

    idLabel = new QLabel(this);
    nomLabel = new QLabel(this);
    prixLabel = new QLabel(this);
    prixLivraisonLabel = new QLabel(this);
    descriptionLabel = new QLabel(this);

    QVBoxLayout *labelsLayout = new QVBoxLayout();
    labelsLayout->addWidget(new QLabel("ID:"));
    labelsLayout->addWidget(idLabel);
    labelsLayout->addWidget(new QLabel("Nom:"));
    labelsLayout->addWidget(nomLabel);
    labelsLayout->addWidget(new QLabel("Prix:"));
    labelsLayout->addWidget(prixLabel);
    labelsLayout->addWidget(new QLabel("Prix Livraison:"));
    labelsLayout->addWidget(prixLivraisonLabel);
    labelsLayout->addWidget(new QLabel("Description:"));
    labelsLayout->addWidget(descriptionLabel);
    labelsLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(tableWidget);
    mainLayout->addLayout(labelsLayout);
}

void Dialog::setProduit(const std::vector<Produit> &produits)
{
    tableWidget->setRowCount(produits.size());

    for (size_t i = 0; i < produits.size(); ++i) {
        const auto &produit = produits[i];

        tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(produit.getId())));
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(produit.getNom())));
        tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(produit.getPrix())));
        tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(produit.getPrixlivraison())));
        tableWidget->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(produit.getDescription())));
    }
}


Dialog::~Dialog()
{

}



/*void Dialog::on_pushButton_clicked()
{

}
*/

