#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QTime>
#include <QDate>

#include "clientWindow.h"
#include "ui_clientWindow.h"

void ClientWindow::setIdentifier(QString identifier){
    m_identifier = identifier;
}
QString ClientWindow::getIdentifier(){
    return m_identifier;
}

ClientWindow::ClientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ClientWindow::setWindowTitle("Личный кабинет: Client");
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_push_get_Address_clicked()
{
    QFile file("Info_Salons.txt");

    if (file.open(QIODevice::ReadOnly)){
         QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }else{
        QMessageBox::warning(this, "Ошибка!", "Не удалось открыть файл!");
    }
}

void ClientWindow::on_pushButton_Exit_clicked()
{
    this->close();
    emit Authorization_client();
}

void ClientWindow::on_pushButton_Add_pet_clicked(){
    addpetWindow = new addpetwindow;
    addpetWindow->setIdentifier(this->getIdentifier());
    addpetWindow->show();
}

void ClientWindow::on_push_get_info_procedure_clicked(){
    QFile file("Info_Procedures.txt");

    if (file.open(QIODevice::ReadOnly)){
         QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }else{
        QMessageBox::warning(this, "Ошибка!", "Не удалось открыть файл!");
    }
}

void ClientWindow::on_pushButton_priem_clicked(){
     registration_for_procedures_Window = new registrationforprocedureswindow;
     registration_for_procedures_Window->setIdentifier(this->getIdentifier());
     registration_for_procedures_Window->show();
}
