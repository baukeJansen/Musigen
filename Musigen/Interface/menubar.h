#ifndef MENUBAR_H
#define MENUBAR_H

#include <Interface/customwidgetbase.h>
#include <Interface/Buttons/openpianobutton.h>
#include <Interface/Buttons/closebutton.h>

class MenuBar : public CustomWidgetBase {

    Q_OBJECT

public:
    MenuBar(QWidget *parent = 0);

    virtual void updateSize(const QSize size);
    virtual void calculateSize(const QSize size);
    virtual QSharedPointer<QRect> getArea();

protected:
    virtual void draw();

private:

    const int HEIGHT = 28;

    QSharedPointer<CloseButton>     closeButton;
    QSharedPointer<OpenPianoButton> pianoButton;

signals:

public slots:
};

#endif // MENUBAR_H
