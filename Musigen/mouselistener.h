#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include <QWidget>
#include <vector>
#include <mouseaction.h>

#include <QDebug>

struct MouseArea {

    MouseAction *listener;
    int top, right, bottom, left;
    bool useOffset = false;
    bool restrictArea = false;

};

class MouseListener : public QWidget {

    Q_OBJECT

public: 
    static std::vector<MouseArea> actionList;
    static void Register(MouseAction *listener) {

        MouseArea area = MouseArea();
        area.listener = listener;
        actionList.push_back(area);

    }

    static void Register(MouseAction *listener, int top, int left) {

        MouseArea area = MouseArea();
        area.listener = listener;
        area.top = top;
        area.left = left;
        area.useOffset = true;
        actionList.push_back(area);

    }

    static void Register(MouseAction *listener, int top, int right, int bottom, int left) {

        MouseArea area = MouseArea();
        area.listener = listener;
        area.top = top;
        area.right = right;
        area.bottom = bottom;
        area.left = left;
        area.useOffset = true;
        area.restrictArea = true;
        actionList.push_back(area);

    }

    static void Unregister(MouseAction *listener) {

        for(std::vector<MouseArea>::iterator it = actionList.begin(); it != actionList.end(); ++it) {

            if ((*it).listener == listener ) {

                actionList.erase(it);
                return;

            }

        }

    }

    MouseListener(QWidget *parent = 0);
    ~MouseListener();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void leaveEvent(QEvent *event);

private:

    bool inArea(MouseArea area);

signals:

public slots:
};

//_MouseListener::actionList;// = std::vector<MouseArea*>;

#endif // MOUSELISTENER_H
