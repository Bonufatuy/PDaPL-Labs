#ifndef ADDPETWINDOW_H
#define ADDPETWINDOW_H

#include <QDialog>

namespace Ui {
class addpetwindow;
}

class addpetwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addpetwindow(QWidget *parent = nullptr);
    ~addpetwindow();

    void setIdentifier(QString Identifier);
    QString getIdentifier();

private slots:
    void on_pushButton_Add_pet_clicked();

private:
    Ui::addpetwindow *ui;
    QString m_identifier;
};

#endif // ADDPETWINDOW_H
