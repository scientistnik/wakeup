#ifndef DIALOG_H
#define DIALOG_H

#include <QSystemTrayIcon>
#include <QDialog>
#include <QTime>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void messageClicked();
    void iconActivated(QSystemTrayIcon::ActivationReason act);
    void time_left();

    void on_add_button_clicked();

    void on_hide_button_clicked();

private:
    Ui::Dialog *ui;
    QSystemTrayIcon *trayIcon;
    QTime *time;
};

#endif // DIALOG_H
