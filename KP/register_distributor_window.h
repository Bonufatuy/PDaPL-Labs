#ifndef REGISTER_DISTRIBUTOR_WINDOW_H
#define REGISTER_DISTRIBUTOR_WINDOW_H

#include"authorizationWindow.h"

#include <QDialog>

namespace Ui {
class register_distributor_Window;
}

class register_distributor_Window : public QDialog
{
    Q_OBJECT

public:
    explicit register_distributor_Window(QWidget *parent = nullptr);
    ~register_distributor_Window();

private slots:
    void on_pushButton_Admin_clicked();

    void on_pushButton_Worker_clicked();

    void on_pushButton_Client_clicked();

private:
    Ui::register_distributor_Window *ui;
    authorizationWindow* authorizationwindow;
};

#endif // REGISTER_DISTRIBUTOR_WINDOW_H
