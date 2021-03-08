#include "register_distributor_window.h"
#include "ui_register_distributor_window.h"

register_distributor_Window::register_distributor_Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_distributor_Window)
{
    ui->setupUi(this);

    authorizationwindow = new authorizationWindow;
    connect(authorizationwindow, &authorizationWindow::Register_Dist, this, &register_distributor_Window::show);
}

register_distributor_Window::~register_distributor_Window()
{
    delete ui;
}

void register_distributor_Window::on_pushButton_Admin_clicked(){
    authorizationwindow->setId("3");
    authorizationwindow->show();
    this->close();
}

void register_distributor_Window::on_pushButton_Worker_clicked(){
    authorizationwindow->setId("2");
    authorizationwindow->show();
    this->close();
}

void register_distributor_Window::on_pushButton_Client_clicked(){
    authorizationwindow->setId("1");
    authorizationwindow->show();
    this->close();
}
