#pragma once

#include <iostream>
#include <vector>

#include "Pet.h"
#include "GeneralType.h"

#include "Worker.h"
class Worker;

class Client: protected GeneralType{
private:
    std::vector<Pet> pets;
    std::vector<Worker> workers;
public:
    Client(QString name = "", QString surname = "", QString middle_name = "", QString email = "", QDate birthday = QDate::currentDate()):
        GeneralType(name, surname, middle_name, email, birthday){}
    ~Client(){}

    void write_to_file();
};

