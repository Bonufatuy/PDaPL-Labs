#include "registration_for_procedures_window.h"
#include "ui_registration_for_procedures_window.h"

#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QTime>
#include <QDate>
#include <iostream>

registrationforprocedureswindow::registrationforprocedureswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationforprocedureswindow)
{
    ui->setupUi(this);
}

registrationforprocedureswindow::~registrationforprocedureswindow()
{
    delete ui;
}

void registrationforprocedureswindow::setIdentifier(QString identifier){
    m_identifier = identifier;
}
QString registrationforprocedureswindow::getIdentifier(){
    return m_identifier;
}

void registrationforprocedureswindow::on_pushButton_recording_clicked()
{
    QFile file("Registration for procedures.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Could not open file");
    }else{
        QTextStream in(&file);

        while(!in.atEnd()){

            QString identifier = in.readLine();
            QString time = in.readLine();
            QString date = in.readLine();
        }

        file.close();
    }

    if (file.open(QIODevice::Append)){
        QTextStream out(&file);

        out << this->getIdentifier() << Qt::endl;
        out << ui->dateEdit->text() << Qt::endl;
        out <<  ui->timeEdit->text() << Qt::endl;

        file.close();
    } else {
        qWarning("Could not open file");
    }

    this->close();
}
