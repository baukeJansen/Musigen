#ifndef CLOSEBUTTON_H
#define CLOSEBUTTON_H

#include <Interface/Buttons/button.h>

class CloseButton : public Button {

    Q_OBJECT

public:
    CloseButton(QWidget *parent = 0);

    virtual void calculateLocation(const QSize size);

protected:
    const int HEIGHT = 28;
    const int WIDTH = 45;

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
