#include <mysplash.h>
#include <QEvent>

MySplash::MySplash(const QPixmap &pixmap)
{
    this->setPixmap(pixmap);
    this->installEventFilter(this);
}

bool MySplash::eventFilter(QObject *target, QEvent *event)
{
    Q_UNUSED(target)
    if((event->type() == QEvent::KeyPress) ||
            (event->type() == QEvent::KeyRelease))
        flag = true;
    if((event->type() == QEvent::MouseButtonPress) ||
        (event->type() == QEvent::MouseButtonDblClick) ||
            (event->type() == QEvent::MouseButtonRelease))/* ||
            (event->type() == QEvent::KeyPress) ||
            (event->type() == QEvent::KeyRelease))*/
        return true;
    return false;
}
