#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "addinformationwindow.h"

namespace Ui {
class adminWindow;
}

class adminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = nullptr);
    ~adminWindow();

signals:
    void Authorization_admin();

private slots:
    void on_pushButton_Exit_clicked();

    void on_push_Buttom_add_information_clicked();

    void on_pushButton_get_client_information_clicked();

private:
    Ui::adminWindow *ui;
    addinformationwindow* addinformationWindow;
};

#endif // ADMINWINDOW_H
