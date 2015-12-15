#include "customwidgetbase.h"

CustomWidgetBase::CustomWidgetBase(QWidget *parent) : QWidget(parent) {

    solidBrush  = QSharedPointer<QBrush>    (new QBrush(Qt::SolidPattern));
    canvas      = QSharedPointer<QImage>   (new QImage(size(), QImage::Format_RGB16));
}

void CustomWidgetBase::updateSize(const QSize size) {

    calculateSize(size);
    calculateLocation(size);

    draw();

}

void CustomWidgetBase::resize(int w, int h) {

    // resize widget
    QWidget::resize(w, h);

    // resize canvas
    canvas = QSharedPointer<QImage> (new QImage(w, h, QImage::Format_RGB16));

}

bool CustomWidgetBase::containsMousePointer(QSharedPointer<QRect> rectangle, QMouseEvent *event) {

    return rectangle->contains(event->pos());

}

void CustomWidgetBase::paintEvent(QPaintEvent *paintEvent) {

    Q_UNUSED(paintEvent)
    QPainter drawWidget(this);

    drawWidget.drawImage(0,  0, (*canvas));

}
