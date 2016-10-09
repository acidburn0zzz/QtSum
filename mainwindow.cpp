#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home");

    QFile* file = new QFile(fileName);


     if(file->open(QIODevice::ReadOnly))
     {


       QString hash_type = ui->combo_hash->currentText();

       if (hash_type == "MD5")
       {
            QString fileSum = QString(QCryptographicHash::hash(file->readAll(),QCryptographicHash::Md5).toHex());

            QMessageBox msgBox;
            msgBox.setText("Somme MD5 : \n" + fileSum );
            msgBox.exec();
       }

       file->close();
     }
}

