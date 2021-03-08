#include "adminwindow.h"
#include "ui_adminwindow.h"

#include <QTextStream>
#include <QFile>
#include <QMessageBox>

adminWindow::adminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminWindow)
{
    ui->setupUi(this);
    adminWindow::setWindowTitle("Личный кабинет: Admin");
}

adminWindow::~adminWindow()
{
    delete ui;
}

void adminWindow::on_pushButton_Exit_clicked(){
    this->close();
    emit Authorization_admin();
}

void adminWindow::on_push_Buttom_add_information_clicked(){
    addinformationWindow = new addinformationwindow;
    addinformationWindow->show();
}

void adminWindow::on_pushButton_get_client_information_clicked(){

    QFile file_auth("Authorization.txt");
    QFile file_client("About client.txt");
    QFile file_pet("Pets.txt");
    QFile new_file("FILE.txt");

    if (!file_auth.open(QIODevice::ReadOnly) || !file_client.open(QIODevice::ReadOnly)
            || !file_pet.open(QIODevice::ReadOnly) || !new_file.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, "Ошибка!", "Не удалось открыть файл!");
        return;
    }

    QTextStream in_auth(&file_auth);
    QTextStream in_client(&file_client);
    QTextStream in_pet(&file_pet);
    QTextStream in_new_file(&new_file);
    QTextStream out(&new_file);

    QString identifier, find_identifier = "", ffind_identifier = "", data;


    QString amount_clients = in_auth.readLine();
    while(!in_auth.atEnd()){
        identifier = in_auth.readLine();
        out << Qt::endl << "About authorization: " << Qt::endl;
        for(int i = 0; i < 3; i++){
            out << in_auth.readLine() << Qt::endl;
        }
        file_client.seek(0);
        amount_clients = in_client.readLine(); find_identifier = "0";
        while(!in_client.atEnd() && find_identifier != identifier){
            find_identifier = in_client.readLine();
            if(find_identifier == identifier){
                out << "          About client: " << Qt::endl;
                for(int i = 0; i < 5; i++){
                    out << in_client.readLine() << Qt::endl;
                }
            }else{
                for(int i = 0; i < 5; i++){
                    data = in_client.readLine();
                }
            }
        }
        file_pet.seek(0); ffind_identifier = "0";
        while(!in_pet.atEnd() && ffind_identifier != identifier){
            ffind_identifier = in_pet.readLine();
            if(ffind_identifier == identifier){
                 out << "          About pet: " << Qt::endl;
                for(int i = 0; i < 3; i++){
                    out << in_pet.readLine() << Qt::endl;
                }
            }else{
                for(int i = 0; i < 3; i++){
                    data = in_pet.readLine();
                }
            }
        }
    }

    new_file.seek(0);
    ui->textBrowser->setText(in_new_file.readAll());

    file_auth.close();
    file_client.close();
    file_pet.close();
    new_file.close();

    return;
}
