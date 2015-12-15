#ifndef CUSTOMWIDGETBASE_H
#define CUSTOMWIDGETBASE_H

#include <QWidget>
#include <QResizeEvent>
#include <QRect>
#include <QPainter>
#include <mouseaction.h>
#include <mouselistener.h>

#include <QDebug>

class CustomWidgetBase : public QWidget, public MouseAction {

    Q_OBJECT

public:
    CustomWidgetBase(QWidget *parent = 0);

    virtual void updateSize(const QSize size);
    virtual QSharedPointer<QRect> getArea() = 0;

protected:
    void initCanvas();
    bool containsMousePointer(QSharedPointer<QRect> rectangle, QMouseEvent *event);
    virtual void calculateSize(const QSize size) {Q_UNUSED(size)}
    virtual void calculateLocation(const QSize size) {Q_UNUSED(size)}
    void resize(int w, int h);

    virtual void paintEvent(QPaintEvent *pe);
    virtual void draw() = 0;


    QSharedPointer<QImage>  canvas;
    QSharedPointer<QBrush>  solidBrush;

signals:

public slots:
};

#endif // CUSTOMWIDGETBASE_H
