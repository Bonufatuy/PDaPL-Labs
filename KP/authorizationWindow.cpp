#include "authorizationWindow.h"
#include "ui_authorizationWindow.h"

#include <QTextStream>
#include <QFile>
#include <QMessageBox>

static QString amount_clients;

void authorizationWindow::setIdentifier(QString identifier){
    m_identifier = identifier;
}
void authorizationWindow::setId(QString id){
    m_id = id;
}
void authorizationWindow::setLogin(QString login){
    m_login = login;
}
void authorizationWindow::setPassword(QString password){
    m_password = password;
}

QString authorizationWindow::getIdentifier(){
    return m_identifier;
}
QString authorizationWindow::getId(){
    return m_id;
}
QString authorizationWindow::getLogin(){
    return m_login;
}
QString authorizationWindow::getPassword(){
    return m_password;
}


authorizationWindow::authorizationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorizationWindow)
{
    ui->setupUi(this);
    authorizationWindow::setWindowTitle("Авторизация");

    registration = new RegistrationWindow();
    connect(registration, &RegistrationWindow::Authorization_registration, this, &authorizationWindow::show);
    clientWindow = new ClientWindow;
    connect(clientWindow, &ClientWindow::Authorization_client, this, &authorizationWindow::show);
    adminwindow = new adminWindow;
    connect(adminwindow, &adminWindow::Authorization_admin, this, &authorizationWindow::show);
    workerwindow = new workerWindow;
    connect(workerwindow, &workerWindow::Authorization_worker, this, &authorizationWindow::show);
}

authorizationWindow::~authorizationWindow()
{
    delete ui;
}

void authorizationWindow::on_push_Authorization_clicked()
{
    this->setLogin(ui->login->text());
    this->setPassword(ui->password->text());

    QString* array = new QString[2];
    array = this->read_file();
    if (array){
    if (array[0] == "1"){
        clientWindow->setIdentifier(array[1]);
        clientWindow->show();
        this->close();
    }
    else if(array[0] == "3"){
        adminwindow->show();
        this->close();
    }
    else if(array[0] == "2"){
        workerwindow->show();
        this->close();
      }
    }
    else{
        QMessageBox::warning(this, "Авторизация", "Вы не авторизовались!");
    }
    delete[] array;
}

void authorizationWindow::write_to_file(){

    QFile File("Authorization.txt");

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
      out << amount_clients << Qt::endl;
      out << this->getId() << Qt::endl;
      out << this->getLogin() << Qt::endl;
      out << this->getPassword() << Qt::endl;

    } else {
      qWarning("Could not open file");
    }

    File.close();
}

QString* authorizationWindow::read_file(){

    QString* array = new QString[2];

    authorizationWindow class_for_check_Data;

    QFile file("Authorization.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        delete[] array;
        QMessageBox::warning(this, "Ошибка!", "Не удалось открыть файл!");
        return nullptr;
    }

    QTextStream in(&file);

    amount_clients = in.readLine();
    while(!in.atEnd()){
        class_for_check_Data.setIdentifier(in.readLine());
        class_for_check_Data.setId(in.readLine());
        class_for_check_Data.setLogin(in.readLine());
        class_for_check_Data.setPassword(in.readLine());
        if(this->getId() == class_for_check_Data.getId() && this->getLogin() == class_for_check_Data.getLogin() &&
                this->getPassword() == class_for_check_Data.getPassword()){
            file.close();
            array[0] = class_for_check_Data.getId();
            array[1] = class_for_check_Data.getIdentifier();
            return array;
        }
    }

    delete[] array;
    file.close();
    return nullptr;
}

void authorizationWindow::on_pushButton_Back_clicked()
{
    this->close();
    emit Register_Dist();
}

void authorizationWindow::on_push_Registration_clicked()
{
    registration->show();
    this->close();
}
