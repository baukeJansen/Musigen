#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <Interface/Buttons/button.h>

class CloseButton : public Button {

    Q_OBJECT

public:
    CloseButton(QWidget *parent = 0);

protected:

    virtual void mouseReleased(QMouseEvent *event);

    virtual void draw();
    virtual QColor getButtonColor();
    virtual QColor getButtontextColor();

private:
    const int CROSS_SIZE = 5;

signals:

public slots:
};

#endif // CLOSEBUTTON_H
