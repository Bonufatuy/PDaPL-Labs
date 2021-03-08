#pragma once

#include <iostream>
#include <QString>
#include <QDate>

class Pet{
private:
    QString m_identifier;
    QString m_pet_name;
    QString m_breed;
    QDate m_pet_birthday;
public:
    Pet(QString identifier = "", QString pet_name = "", QString breed = "", QDate pet_birthday = QDate::currentDate()):
        m_identifier(identifier),m_pet_name(pet_name), m_breed(breed), m_pet_birthday(pet_birthday){}
    ~Pet(){}
};
