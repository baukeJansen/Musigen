#ifndef OPENPIANOBUTTON_H
#define OPENPIANOBUTTON_H

#include <Interface/Buttons/button.h>
#include <Interface/Piano/piano.h>

class OpenPianoButton : public Button {

    Q_OBJECT

public:
    OpenPianoButton(QWidget *parent = 0);

    virtual void calculateLocation(const QSize size);

protected:
    virtual void draw();
    virtual void mouseReleased(QMouseEvent *event);

signals:

public slots:
};

#endif // OPENPIANOBUTTON_H
