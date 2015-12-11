#ifndef NOTEFIELD_H
#define NOTEFIELD_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>

#include <musicplayer.h>
#include <Melody/melody.h>
#include <QDebug>

#define notes 11
#define testSound false

class NoteField : public QWidget {

    public:
        NoteField(QWidget *parent = 0, MusicPlayer *mp = 0);
        void paintEvent(QPaintEvent *pe);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);

        void startRecording();
        void playMelody();
        void resizeEvent(QResizeEvent *event);

        ~NoteField();

    private:
        QPixmap *board;
        QPainter *painter;
        QBrush *solidBrush;

        Melody *melody;
        MusicPlayer *mp;

        void drawBoard();

    signals:

    public slots:

};

#endif // NOTEFIELD_H
