#include "addpetwindow.h"
#include "ui_addpetwindow.h"
#include "Pet.h"
#include "client.h"
#include "authorizationWindow.h"

#include <QTextStream>
#include <QFile>
#include <QMessageBox>

void addpetwindow::setIdentifier(QString Identifier){
    m_identifier = Identifier;
}
QString addpetwindow::getIdentifier(){
    return m_identifier;
}

addpetwindow::addpetwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addpetwindow)
{
    ui->setupUi(this);
    addpetwindow::setWindowTitle("Добавление питомца");
}

addpetwindow::~addpetwindow()
{
    delete ui;
}

void addpetwindow::on_pushButton_Add_pet_clicked(){

    if(ui->lineEdit_Name->text() != "" && ui->lineEdit_breed->text() != ""){
        Pet pet(this->getIdentifier(), ui->lineEdit_Name->text(), ui->lineEdit_breed->text(), ui->dateEdit_DR->date());

        QFile File("Pets.txt");
        if (File.open(QIODevice::Append)) {

          QTextStream out(&File);
          out << this->getIdentifier() << Qt::endl;
          out << ui->lineEdit_Name->text() << Qt::endl;
          out << ui->lineEdit_breed->text() << Qt::endl;
          out << ui->dateEdit_DR->date().toString() << Qt::endl;

        } else {
          qWarning("Could not open file");
        }

        File.close();
        this->close();
    }
    else QMessageBox::warning(this, "Ошибка!", "Некорректный ввод данных!");
}
