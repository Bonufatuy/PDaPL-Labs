#pragma once

#include <iostream>
#include <QString>
#include <QDate>

class GeneralType{
private:
    QString m_name;
    QString m_surname;
    QString m_middle_name;
    QString m_email;
    QDate m_birthday;
public:
    GeneralType(QString name = "", QString surname = "", QString middle_name = "", QString email = "", QDate birthday = QDate::currentDate()):
        m_name(name), m_surname(surname), m_middle_name(middle_name), m_email(email), m_birthday(birthday){}
    ~GeneralType(){}

    QString getName();
    QString getSurname();
    QString getMiddle_name();
    QString getEmail();
    QDate getBirthday();

};
