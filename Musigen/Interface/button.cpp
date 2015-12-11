#include "button.h"

Button::Button(QWidget *parent) : CustomWidgetBase(parent) {

    resize(WIDTH, HEIGHT);

    board = new QPixmap(width(), height());
    painter = new QPainter(board);
    solidBrush = new QBrush(Qt::SolidPattern);

    draw();

    MouseListener::Register(this);

}

void Button::mousePressed(QMouseEvent *event) {

    if (containsMousePointer(getArea(), event)) {

        pressed = true;
        draw();

    }

}

void Button::mouseMoved(QMouseEvent *event) {

    QRect *area = getArea();

    if (containsMousePointer(area, event) != inArea) {

        inArea = !inArea;
        draw();

    }

    delete area;

}


void Button::mouseReleased(QMouseEvent *event) {

    QRect *area = getArea();

    if (containsMousePointer(area, event) && pressed) {

        QApplication::quit();

    }

    if (pressed) {

        pressed = false;
        draw();

    }

    delete area;

}

void Button::draw() {

    // draw background
    solidBrush->setColor(getButtonColor());
    painter->fillRect(0, 0, width(), height(), *solidBrush);

    const int centerWidth = width() / 2;
    const int centerHeight = height() / 2;
    painter->setPen( QPen(getButtontextColor()));
    painter->drawLine(centerWidth - CROSS_SIZE, centerHeight - CROSS_SIZE, centerWidth + CROSS_SIZE, centerHeight + CROSS_SIZE);
    painter->drawLine(centerWidth - CROSS_SIZE, centerHeight + CROSS_SIZE, centerWidth + CROSS_SIZE, centerHeight - CROSS_SIZE);

    update();

}

void Button::calculateLocation(const QSize size) {

    move(size.width() - WIDTH, 0);

}

void Button::paintEvent(QPaintEvent *paintEvent) {

    Q_UNUSED(paintEvent)
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), (*board) );

}

QRect* Button::getArea() {

    return new QRect(pos(), size());

}

QColor Button::getButtonColor() {

    if (inArea) {

    if(pressed)
        return BUTTON_CLICKED;
    else
        return Qt::red;

    } else {

        return Qt::lightGray;

    }

}

QColor Button::getButtontextColor() {

    if (inArea) {

        return Qt::white;

    } else {

        return Qt::black;

    }

}

Button::~Button() {

    delete solidBrush;
    delete painter;
    delete board;

}
