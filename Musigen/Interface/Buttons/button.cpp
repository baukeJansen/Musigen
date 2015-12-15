#include "button.h"

Button::Button(QWidget *parent) : CustomWidgetBase(parent) {

    // set button size
    resize(WIDTH, HEIGHT);

    // register for mouse input
    MouseListener::Register(this);

}

void Button::mousePressed(QMouseEvent *event) {

    QSharedPointer<QRect> area = getArea();

    // if mouse was clicked in the area
    if (containsMousePointer(area, event)) {

        // change color
        pressed = true;
        draw();

    }

}

void Button::mouseMoved(QMouseEvent *event) {

    QSharedPointer<QRect> area = getArea();

    // if mouse was moved in or out of the area
    if (containsMousePointer(area, event) != inArea) {

        // change colors
        inArea = !inArea;
        draw();

    }

}


void Button::mouseReleased(QMouseEvent *event) {

    Q_UNUSED(event);

    // if pressed inside area and released outside
    if (pressed) {

        // reset color
        pressed = false;
        draw();

    }

}

void Button::draw() {

    auto painter = QSharedPointer<QPainter>  (new QPainter(canvas.data()));
    //QPainter painter = QPainter(canvas.data());

    // draw background
    solidBrush->setColor(getButtonColor());
    painter->fillRect(0, 0, width(), height(), *solidBrush);

    update();

}

QSharedPointer<QRect> Button::getArea() {

    return QSharedPointer<QRect>(new QRect(pos(), size()));

}

QColor Button::getButtonColor() {

    // get button color by state
    if (inArea) {

        if(pressed)
            return BUTTON_CLICKED;
        else
            return BUTTON_HOVER;

    } else {

        return BUTTON_DEFAULT;

    }

}

Button::~Button() {

}
