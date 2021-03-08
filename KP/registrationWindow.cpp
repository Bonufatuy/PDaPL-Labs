#include "registrationWindow.h"
#include "ui_registrationWindow.h"
#include "authorizationWindow.h"
#include "client.h"

#include <QTextStream>
#include <QFile>
#include <iostream>
#include <QMessageBox>
#include <locale>

bool setValid(QString parameter);

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_push_ZRegistration_clicked()
{
    if ((setValid(ui->reg_Name->text()) && setValid(ui->reg_Surname->text()) && setValid(ui->reg_Middle_name->text()))
            && ui->reg_Login->text() != "" && ui->reg_Name->text() != "" && ui->reg_Surname->text() != "" && ui->reg_Middle_name->text() != "" &&
            ui->reg_Identificator->text() != ""){

        authorizationWindow to_file;

        to_file.setId(ui->reg_Identificator->text());
        to_file.setLogin(ui->reg_Login->text());
        to_file.setPassword(ui->reg_Password->text());

        Client client(ui->reg_Name->text(), ui->reg_Surname->text(), ui->reg_Middle_name->text(),
               ui->reg_Email->text(), ui->reg_DR->date());

        if(to_file.read_file()){
            QMessageBox::warning(this, "Ошибка", "Такой пользователь уже существует!");
        }else if(ui->reg_Pas_repeat->text() != ui->reg_Password->text()){
            QMessageBox::warning(this, "Ошибка", "Пароли не совпадают!");
        }else if(to_file.getId() == "1"){
            to_file.write_to_file();
            client.write_to_file();
            clientwindow = new ClientWindow;

            QString identifier;
            QFile file("Authorization.txt");
            if(file.open(QIODevice::ReadWrite)){
                QTextStream in_file(&file);
                identifier = in_file.readLine();
            }
            clientwindow->setIdentifier(identifier);
            clientwindow->show();
            this->close();
        }
        else if(to_file.getId() == "3"){
            to_file.write_to_file();
            client.write_to_file();
            adminwindow = new adminWindow;
            adminwindow->show();
            this->close();
        }else if(to_file.getId() == "2"){
            to_file.write_to_file();
            client.write_to_file();
            workerwindow = new workerWindow;
            workerwindow->show();
            this->close();
        }
    }else {
        QMessageBox::warning(this, "Ошибка!", "Некорректный ввод данных! Повторите попытку снова.");
    }
}

void RegistrationWindow::on_push_back_to_Authorization_clicked()
{
    this->close();
    emit Authorization_registration();
}

bool setValid(QString parameter) {       // Проверка на состав строк ФИО
    for(QChar i: parameter){
        if((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')){
        } else {
            return false;
        }
    }
    return true;
}
