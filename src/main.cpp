#include "paint.h"
#include <QApplication>
#include <QTime>
#include <QPainter>
#include <QMainWindow>
#include <mysplash.h>
#include <QSound>
#include <QEvent>

#define LOAD_TIME 12500
#define PROGRESS_X_PX 100
#define PROGRESS_Y_PX 520
#define PROGRESS_WIDTH_PX 220
#define PROGRESS_HEIGHT_PX 28


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    //медиаплеер для звука
    QSound sound(":/sound/nirp_intro.wav");
    sound.play();

    //заставка загрузки
    QPixmap pix(":/nirp_logo.png");
    MySplash *splashScreen = new MySplash(pix);
    splashScreen->show();

    QTime time;
    time.start();
    while( time.elapsed() < LOAD_TIME )
    {
        const int progress = static_cast< double >( time.elapsed() ) / LOAD_TIME * 100.0;
        splashScreen->showMessage("Press any key to Skip",Qt::AlignBottom | Qt::AlignCenter,Qt::white);
        QPainter painter;
        painter.begin( &pix );

        painter.fillRect(
            PROGRESS_X_PX,
            PROGRESS_Y_PX,
            progress / 100.0 * PROGRESS_WIDTH_PX,
            PROGRESS_HEIGHT_PX, Qt::gray
            );

        painter.end();
        splashScreen->setPixmap(pix);
        if(splashScreen->flag == true)
        {
            sound.stop();
            break;
        }

    }
    splashScreen->showMessage("Uploaded",Qt::AlignBottom | Qt::AlignCenter,Qt::white);
    QMainWindow win;
    splashScreen->finish( &win );
    delete splashScreen;

    //основная программа
    Paint w;
    w.show();

    return a.exec();
}
