#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    trayIcon = new QSystemTrayIcon(this);

    connect(trayIcon, SIGNAL(messageClicked()), this, SLOT(messageClicked()));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    connect(ui->exit_button, SIGNAL(clicked(bool)),qApp,SLOT(quit()));


    trayIcon->setIcon(QIcon(":image/bad.png"));
    trayIcon->show();
    trayIcon->showMessage(QTime::currentTime().toString(),"Time over!");

    time = new QTime();
}

Dialog::~Dialog()
{
    delete ui;
    delete trayIcon;
    delete time;
}

void Dialog::messageClicked()
{
    //show();
    qDebug() << "Hello";
}

void Dialog::iconActivated(QSystemTrayIcon::ActivationReason act)
{
    switch (act) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick: (this->isHidden()) ? (show()) : (hide()); break;
    default:break;
    }

}


void Dialog::on_add_button_clicked()
{
    *time = ui->timeEdit->time();
    int left_time = QTime::currentTime().msecsTo(*time)+1;
    QTimer::singleShot(left_time,this,SLOT(time_left()));
    qDebug() << left_time/1000;
}

void Dialog::time_left()
{
     trayIcon->showMessage(QTime::currentTime().toString(),"Time over!");
}
