#include "openpianobutton.h"

OpenPianoButton::OpenPianoButton(QWidget *parent) : Button(parent) {

}

void OpenPianoButton::calculateLocation(const QSize size) {

    Q_UNUSED(size)

}

void OpenPianoButton::mouseReleased(QMouseEvent *event) {

    QSharedPointer<QRect> area = getArea();

    // if button was pressed and released in the area
    if (containsMousePointer(area, event) && pressed) {

        // exit the aplication
        Piano* p = Piano::getInstance();
        p->show();
        //p->activateWindow();

    }

    Button::mouseReleased(event);

}


void OpenPianoButton::draw() {

    // draw default button
    Button::draw();

    // get painter
    auto painter = QSharedPointer<QPainter>  (new QPainter(canvas.data()));


    // update widget
    update();

}
