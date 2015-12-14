#include "customwidgetbase.h"

CustomWidgetBase::CustomWidgetBase(QWidget *parent) : QWidget(parent) {

    solidBrush  = QSharedPointer<QBrush>    (new QBrush(Qt::SolidPattern));
    canvas      = QSharedPointer<QImage>   (new QImage(size(), QImage::Format_RGB16));
}

void CustomWidgetBase::updateSize(QResizeEvent *event) {

    calculateSize(event->size());
    calculateLocation(event->size());

    draw();

}

bool CustomWidgetBase::containsMousePointer(QSharedPointer<QRect> rectangle, QMouseEvent *event) {

    return rectangle->contains(event->pos());

}

void CustomWidgetBase::paintEvent(QPaintEvent *paintEvent) {

    Q_UNUSED(paintEvent)
    QPainter drawWidget(this);

    drawWidget.drawImage(0,  0, (*canvas));
    //drawWidget.drawPixmap(0, 0, (*canvas));

}
