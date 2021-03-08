#pragma once

#include <QDialog>

namespace Ui {
class workerWindow;
}

class workerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit workerWindow(QWidget *parent = nullptr);
    ~workerWindow();

signals:
    void Authorization_worker();

private slots:
    void on_pushButton_Exit_clicked();

private:
    Ui::workerWindow *ui;
};

