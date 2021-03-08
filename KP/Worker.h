#pragma once

#include <iostream>
#include <vector>
#include <QDate>

#include "GeneralType.h"
#include "client.h"

class Client;

class Worker: protected GeneralType{
private:
    std::vector<Client> clients;
public:
    Worker(QString name = "", QString surname = "", QString middle_name = "", QString email = "", QDate birthday = QDate::currentDate()):
        GeneralType(name, surname, middle_name, email, birthday){}
    ~Worker(){}
};

