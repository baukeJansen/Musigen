#ifndef NOTEFIELD_H
#define NOTEFIELD_H

#include <Interface/customwidgetbase.h>
#include <musicplayer.h>
#include <Melody/melody.h>


#include <QDebug>

#define notes 11
#define testSound false

class MainWindow;

class NoteField : public CustomWidgetBase {

    public:
        NoteField(QWidget *parent = 0, QSharedPointer<MusicPlayer> mp = QSharedPointer<MusicPlayer> (0), MainWindow *mainwindow = 0);

        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);

        void startRecording();
        void playMelody();        

        virtual void calculateSize(const QSize size);
        virtual void calculateLocation(const QSize size);
        virtual QSharedPointer<QRect> getArea();

        ~NoteField();

    private:

        //QSharedPointer<Melody> melody;
        QSharedPointer<MusicPlayer> mp;
        QSharedPointer<MainWindow> mainwindow;

        virtual void draw();

    signals:

    public slots:

};

#endif // NOTEFIELD_H
