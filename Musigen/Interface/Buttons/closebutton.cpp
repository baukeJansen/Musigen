#include "closebutton.h"

CloseButton::CloseButton(QWidget *parent) : Button(parent) {

    // set button size
    resize(WIDTH, HEIGHT);

}

void CloseButton::mouseReleased(QMouseEvent *event) {

    QSharedPointer<QRect> area = getArea();

    // if button was pressed and released in the area
    if (containsMousePointer(area, event) && pressed) {

        // exit the aplication
        QApplication::quit();

    }

    Button::mouseReleased(event);

}

void CloseButton::calculateLocation(const QSize size) {

    // update widget location
    move(size.width() - WIDTH, 0);

}

void CloseButton::draw() {

    // draw default button
    Button::draw();

    // get painter
    auto painter = QSharedPointer<QPainter>  (new QPainter(canvas.data()));

    // draw cross
    const int centerWidth = width() / 2;
    const int centerHeight = height() / 2;
    painter->setPen( QPen(getButtontextColor()));
    painter->drawLine(centerWidth - CROSS_SIZE, centerHeight - CROSS_SIZE, centerWidth + CROSS_SIZE, centerHeight + CROSS_SIZE);
    painter->drawLine(centerWidth - CROSS_SIZE, centerHeight + CROSS_SIZE, centerWidth + CROSS_SIZE, centerHeight - CROSS_SIZE);

    // update widget
    update();

}

QColor CloseButton::getButtonColor() {

    // get button color by state
    if (inArea) {

        if(pressed)
            return BUTTON_CLICKED;
        else
            return Qt::red;

    } else {

        return Qt::lightGray;

    }

}

QColor CloseButton::getButtontextColor() {

    // get button text (cross) color by state
    if (inArea) {

        return Qt::white;

    } else {

        return Qt::black;

    }

}
