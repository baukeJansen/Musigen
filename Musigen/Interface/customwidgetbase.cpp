#include "customwidgetbase.h"

CustomWidgetBase::CustomWidgetBase(QWidget *parent) : QWidget(parent) {



}

void CustomWidgetBase::updateSize(QResizeEvent *event) {

    calculateSize(event->size());
    calculateLocation(event->size());

}

bool CustomWidgetBase::containsMousePointer(QRect *rectangle, QMouseEvent *event) {

    return rectangle->contains(event->pos());

}
