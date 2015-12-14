#ifndef OPENPIANOBUTTON_H
#define OPENPIANOBUTTON_H

#include <Interface/Buttons/button.h>

class OpenPianoButton : public Button {

    Q_OBJECT

public:
    OpenPianoButton(QWidget *parent = 0);

protected:
    virtual void draw();

signals:

public slots:
};

#endif // OPENPIANOBUTTON_H
