#include "notefield.h"

NoteField::NoteField(QWidget *parent, MusicPlayer *mp) : CustomWidgetBase(parent) {

    resize(parent->width(), parent->height());

    this->mp = mp;

    draw();

    if (testSound) {

        melody = new Melody(mp->getInstrument());

        melody->addNote(new Note(0, 500, 0));
        melody->addNote(new Note(500, 300, 5));
        melody->addNote(new Note(1000, 300, 5));

        melody->addNote(new Note(1500, 500, 9));
        melody->addNote(new Note(2000, 300, 7));
        melody->addNote(new Note(2500, 300, 7));

        melody->addNote(new Note(3000, 500, 10));
        melody->addNote(new Note(3500, 300, 4));
        melody->addNote(new Note(4000, 300, 4));

        melody->addNote(new Note(4500, 500, 7));
        melody->addNote(new Note(5000, 600, 5));


        mp->play(melody);

    }

}

void NoteField::mousePressEvent(QMouseEvent *event) {

    event->pos();
    float y = event->pos().ry();
    int toneHeight = (int)floor(y / height() * notes);

    mp->playNote(toneHeight);

}

void NoteField::mouseReleaseEvent(QMouseEvent *event) {

    event->pos();
    float y = event->pos().ry();
    int toneHeight = (int)floor(y / height() * notes);

    mp->stopNote(toneHeight);

}

void NoteField::draw() {

    // create paint devince
    auto painter = QSharedPointer<QPainter>  (new QPainter(canvas.data()));


    // draw background
    solidBrush->setColor(Qt::gray);
    painter->fillRect(0, 0, width(), height(), *solidBrush);

    solidBrush->setColor(Qt::darkGray);

    for (int i = 0; i < notes; i++) {

        painter->drawLine(0, (int)round(height() / notes * i), width(), (int)round(height() / notes * i));

    }

    update();

}

void NoteField::calculateLocation(const QSize size) {

    Q_UNUSED(size)

    //MainWindow *p = dynamic_cast<MainWindow> (parent());


    //move();

}

void NoteField::calculateSize(const QSize size) {

    Q_UNUSED(size)

}

QSharedPointer<QRect> NoteField::getArea() {

    return QSharedPointer<QRect>(new QRect(pos(),size()));

}


void NoteField::playMelody() {

    mp->play(melody);

}

NoteField::~NoteField() {

    if (testSound) {

        delete melody;

    }

}
