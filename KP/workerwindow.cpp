#include "workerwindow.h"
#include "ui_workerwindow.h"

workerWindow::workerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::workerWindow)
{
    ui->setupUi(this);
    workerWindow::setWindowTitle("Личный кабинет: Worker");
}

workerWindow::~workerWindow()
{
    delete ui;
}

void workerWindow::on_pushButton_Exit_clicked()
{
    this->close();
    emit Authorization_worker();
}
