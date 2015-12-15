#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) : CustomWidgetBase(parent) {

    closeButton = QSharedPointer<CloseButton> (new CloseButton(this));
    pianoButton = QSharedPointer<OpenPianoButton> (new OpenPianoButton(this));

}

void MenuBar::draw() {

    // create paint devince
    auto painter = QSharedPointer<QPainter>  (new QPainter(canvas.data()));

    // draw background
    solidBrush->setColor(Qt::lightGray);
    painter->fillRect(0, 0, width(), height(), *solidBrush);

    // update widget
    update();

}

void MenuBar::calculateSize(const QSize size) {

    // update window size
    resize(size.width(), HEIGHT);

}

void MenuBar::updateSize(const QSize size) {

    CustomWidgetBase::updateSize(size);

    closeButton->updateSize(size);
    pianoButton->updateSize(size);

}

QSharedPointer<QRect> MenuBar::getArea() {

    return QSharedPointer<QRect>(new QRect(pos(),size()));

}
