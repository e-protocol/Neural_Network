#ifndef MYSPLASH_H
#define MYSPLASH_H

#include <QObject>
#include <QSplashScreen>

class MySplash : public QSplashScreen
{
public:
    MySplash(const QPixmap &pixmap = QPixmap());
    bool eventFilter (QObject *target, QEvent *event);
    bool flag = false;
};

#endif // MYSPLASH_H
