#ifndef MOUSEACTION
#define MOUSEACTION

#include <QMouseEvent>

class MouseAction {
public:

    virtual void mousePressed(QMouseEvent *event) {Q_UNUSED(event)}
    virtual void mouseMoved(QMouseEvent *event) {Q_UNUSED(event)}
    virtual void mouseReleased(QMouseEvent *event) {Q_UNUSED(event)}

    virtual void areaContainsMouse (QRect area, QMouseEvent *event) {

        area.contains(event->x(), event->y());

    }

signals:

public slots:
};

#endif // MOUSEACTION
