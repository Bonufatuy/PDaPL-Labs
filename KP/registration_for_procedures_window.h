#ifndef REGISTRATIONFORPROCEDURESWINDOW_H
#define REGISTRATIONFORPROCEDURESWINDOW_H

#include <QDialog>

namespace Ui {
class registrationforprocedureswindow;
}

class registrationforprocedureswindow : public QDialog
{
    Q_OBJECT

public:
    explicit registrationforprocedureswindow(QWidget *parent = nullptr);
    ~registrationforprocedureswindow();

    void setIdentifier(QString identifier);
    QString getIdentifier();

private slots:
    void on_pushButton_recording_clicked();

private:
    Ui::registrationforprocedureswindow *ui;
    QString m_identifier;
};

#endif // REGISTRATIONFORPROCEDURESWINDOW_H
