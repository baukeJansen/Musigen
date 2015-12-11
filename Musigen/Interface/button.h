#ifndef BUTTON_H
#define BUTTON_H

#include <Interface/customwidgetbase.h>
#include <mouselistener.h>
#include <mouseaction.h>
#include <QPainter>
#include <QApplication>

#define HEIGHT 28
#define WIDTH 45
#define CROSS_SIZE 5
#define BUTTON_HOVER QColor(0, 0, 0, 0)
#define BUTTON_CLICKED QColor(255, 90, 90, 255)

class Button : public CustomWidgetBase , public MouseAction {

    Q_OBJECT

public:
    Button(QWidget *parent = 0);
    ~Button();

    virtual void calculateLocation(const QSize size);
    virtual QRect* getArea();

protected:
    virtual void mousePressed(QMouseEvent *event);
    virtual void mouseMoved(QMouseEvent *event);
    virtual void mouseReleased(QMouseEvent *event);

    virtual void paintEvent(QPaintEvent *pe);
    virtual void draw();

private:
    QPixmap *board;
    QPainter *painter;
    QBrush *solidBrush;

    bool inArea = false;
    bool pressed = false;

    QColor getButtonColor();
    QColor getButtontextColor();

signals:

public slots:
};

#endif // BUTTON_H
