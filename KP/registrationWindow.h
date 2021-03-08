#pragma once

#include <QDialog>

#include "clientWindow.h"
#include "adminwindow.h"
#include "workerwindow.h"

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

signals:
    void Authorization_registration();

private slots:
    void on_push_ZRegistration_clicked();
    void on_push_back_to_Authorization_clicked();

private:
    Ui::RegistrationWindow *ui;
    ClientWindow* clientwindow;
    adminWindow* adminwindow;
    workerWindow* workerwindow;
};
