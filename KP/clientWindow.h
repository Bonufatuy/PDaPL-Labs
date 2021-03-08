#pragma once

#include "addpetwindow.h"
#include "registration_for_procedures_window.h"
#include <QDialog>

namespace Ui {
class ClientWindow;
}

class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

    void setIdentifier(QString Identifier);
    QString getIdentifier();

signals:
    void Authorization_client();

private slots:
    void on_push_get_Address_clicked();

    void on_pushButton_Exit_clicked();

    void on_pushButton_Add_pet_clicked();

    void on_push_get_info_procedure_clicked();

    void on_pushButton_priem_clicked();

private:
    Ui::ClientWindow *ui;
    addpetwindow* addpetWindow;
    registrationforprocedureswindow* registration_for_procedures_Window;
    QString m_identifier;
};
