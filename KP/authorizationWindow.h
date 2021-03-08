#pragma once

#include "clientWindow.h"
#include "registrationWindow.h"
#include "adminwindow.h"
#include "workerwindow.h"

#include <QDialog>

namespace Ui {
class authorizationWindow;
}

class authorizationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit authorizationWindow(QWidget *parent = nullptr);
    ~authorizationWindow();

    void write_to_file();
    QString* read_file();

    void setIdentifier(QString identifier);
    void setId(QString id);
    void setLogin(QString login);
    void setPassword(QString password);

    QString getIdentifier();
    QString getId();
    QString getLogin();
    QString getPassword();

signals:
    void Register_Dist();

private slots:
    void on_push_Authorization_clicked();
    void on_push_Registration_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::authorizationWindow *ui;
    ClientWindow* clientWindow;
    RegistrationWindow* registration;
    adminWindow* adminwindow;
    workerWindow* workerwindow;

    QString m_identifier;
    QString m_id;
    QString m_login;
    QString m_password;
};
