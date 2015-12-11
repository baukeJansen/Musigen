#ifndef CUSTOMWIDGETBASE_H
#define CUSTOMWIDGETBASE_H

#include <QWidget>
#include <QResizeEvent>
#include <QRect>

class CustomWidgetBase : public QWidget {

    Q_OBJECT

public:
    CustomWidgetBase(QWidget *parent = 0);

    void updateSize(QResizeEvent *event);
    virtual void calculateSize(const QSize size) {Q_UNUSED(size)}
    virtual void calculateLocation(const QSize size) {Q_UNUSED(size)}

protected:
    bool containsMousePointer(QRect *rectangle, QMouseEvent *event);

signals:

public slots:
};

#endif // CUSTOMWIDGETBASE_H
