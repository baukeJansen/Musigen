#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) : CustomWidgetBase(parent) {

    pianoButton = QSharedPointer<OpenPianoButton> (new OpenPianoButton(this));

}

void MenuBar::draw() {

    // create paint devince
    auto painter = QSharedPointer<QPainter>  (new QPainter(canvas.data()));

    // draw background
    solidBrush->setColor(Qt::red);
    painter->fillRect(0, 0, width(), height(), *solidBrush);
    solidBrush->setColor(Qt::blue);
    painter->fillRect(0, 0, 10, 10, *solidBrush);

    // update widget
    update();

}

void MenuBar::calculateSize(const QSize size) {

    // update window size
    resize(size.width(), HEIGHT);

    // update canvas size
    canvas = QSharedPointer<QImage> (new QImage(size.width(), HEIGHT, QImage::Format_RGB16));

}

void MenuBar::updateSize(QResizeEvent *event) {

    CustomWidgetBase::updateSize(event);

    pianoButton->updateSize(event);

}

QSharedPointer<QRect> MenuBar::getArea() {

    return QSharedPointer<QRect>(new QRect(pos(),size()));

}
