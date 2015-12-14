#include "openpianobutton.h"

OpenPianoButton::OpenPianoButton(QWidget *parent) : Button(parent) {

}

void OpenPianoButton::draw() {

    // draw default button
    Button::draw();

    // get painter
    auto painter = QSharedPointer<QPainter>  (new QPainter(canvas.data()));


    // update widget
    update();

}
