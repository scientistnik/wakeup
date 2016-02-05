#include <QApplication>

#ifndef QT_NO_SYSTEMTRAYICON

#include <QLabel>
//#include "dialog.h"

int main(int argc, char *argv[])
{
    //Q_INIT_RESOURCE(systray);

    QApplication a(argc, argv);
    /*
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Systray"),
                              QObject::tr("I couldn't detect any system tray "
                                          "on this system."));
        return 1;
    }
    QApplication::setQuitOnLastWindowClosed(false);

    Dialog w;
    //w.show();
    */

    QLabel label(argv[1]);
    label.setWordWrap(true);
    label.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QFont font;// = label.font();
    font.setPointSize(72);
    font.setBold(true);
    label.setFont(font);

    label.showFullScreen();

    return a.exec();
}

#else

#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text("QSystemTrayIcon is not supported on this platform");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}

#endif
