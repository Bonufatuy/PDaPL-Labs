#include "client.h"

#include <QTextStream>
#include <QFile>

static QString amount_clients;

void Client::write_to_file(){
    QFile File("About client.txt");

    if(File.open(QIODevice::ReadWrite)){
        File.seek(0);
        QTextStream in(&File);
        QTextStream out(&File);
        QString space = in.readLine();                  // Отслеживание кол-ва записей в файле (установка идентификатора клиента)
        int point = space.toInt(); point++;
        QString amount_writes = QString::number(point);
        amount_clients = amount_writes;
        File.seek(0);
        out << amount_writes << Qt::endl;

        File.close();
    }

    if (File.open(QIODevice::Append)) {

      QTextStream out(&File);
      out << amount_clients << Qt::endl;                // Идентификатор клиента для разных файлов
      out << this->getName() << Qt::endl;
      out << this->getSurname() << Qt::endl;
      out << this->getMiddle_name() << Qt::endl;
      out << this->getEmail() << Qt::endl;
      out << this->getBirthday().toString() << Qt::endl;

    } else {
      qWarning("Could not open file");
    }

    File.close();
}
