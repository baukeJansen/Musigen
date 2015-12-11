#include "mouselistener.h"

std::vector<MouseArea> MouseListener::actionList;

MouseListener::MouseListener(QWidget *parent) : QWidget(parent) {

    grabMouse();
    setMouseTracking(true);

}

void MouseListener::mousePressEvent(QMouseEvent *event) {

    for(std::vector<MouseArea>::iterator it = MouseListener::actionList.begin(); it != MouseListener::actionList.end(); ++it) {


        (*it).listener->mousePressed(event);

    }

}

void MouseListener::mouseReleaseEvent(QMouseEvent *event) {

    for(std::vector<MouseArea>::iterator it = actionList.begin(); it != actionList.end(); ++it) {

        (*it).listener->mouseReleased(event);

    }

}

void MouseListener::mouseMoveEvent(QMouseEvent *event) {
qDebug("move");
    for(std::vector<MouseArea>::iterator it = actionList.begin(); it != actionList.end(); ++it) {

        (*it).listener->mouseMoved(event);

    }

}

void MouseListener::leaveEvent(QEvent *event) {

    Q_UNUSED(event)

    QPointF p = QPointF(-1, -1);
    QMouseEvent *m = new QMouseEvent(QEvent::MouseMove, p, Qt::NoButton, Qt::NoButton, Qt::NoModifier);
    mouseMoveEvent(m);

}

MouseListener::~MouseListener() {

}
