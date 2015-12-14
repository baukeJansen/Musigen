#ifndef BUTTON_H
#define BUTTON_H

#include <Interface/customwidgetbase.h>
#include <QApplication>

class Button : public CustomWidgetBase {

    Q_OBJECT

public:
    Button(QWidget *parent = 0);
    ~Button();

    virtual void calculateLocation(const QSize size);
    virtual QSharedPointer<QRect> getArea();


protected:
    const int HEIGHT = 28;
    const int WIDTH = 45;

    const QColor BUTTON_HOVER = QColor(0, 0, 0, 0);
    const QColor BUTTON_CLICKED = QColor(255, 90, 90, 255);

    bool inArea = false;
    bool pressed = false;

    virtual void mousePressed(QMouseEvent *event);
    virtual void mouseMoved(QMouseEvent *event);
    virtual void mouseReleased(QMouseEvent *event);

    virtual void draw();
    virtual QColor getButtonColor();

signals:

public slots:
};

#endif // BUTTON_H
