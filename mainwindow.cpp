
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
#include "DaoManager.h"
#include "Errors.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString identifiant = ui->lineEdit_id->text();
    QString motdepasse = ui->lineEdit_mdp->text();

    DaoManager dao = DaoManager.GetInstance();

    try {
        dao.connect(identifiant, motdepasse);

        QMessageBox::information(this,"Login","Identifiant et mot de passe sont correct");
        hide();
        dialog= new Dialog(this);
        dialog->show();
    } catch (InvalidEmailOrPassword error) {
        QMessageBox::warning(this,"Login","Identifiant et mot de passe incorrect");
    }



}



