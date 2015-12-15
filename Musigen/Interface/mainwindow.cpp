#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    engine = irrklang::createIrrKlangDevice();

    if (!engine) {

        qDebug(" === failed creating irrklang engine === ");

    }

    mouseListener   = QSharedPointer<MouseListener> (new MouseListener(ui->centralWidget));
    instrument      = QSharedPointer<Instrument>    (new Instrument(engine));
    musicplayer     = QSharedPointer<MusicPlayer>   (new MusicPlayer(instrument));

    menubar         = QSharedPointer<MenuBar>       (new MenuBar(ui->centralWidget));
    notefield       = QSharedPointer<NoteField>     (new NoteField(ui->centralWidget, musicplayer, this));

    setWindowFlags(Qt::Widget | Qt::CustomizeWindowHint);
    //setWindowFlags(Qt::FramelessWindowHint );

}

void MainWindow::on_pushButton_clicked() {

}

void MainWindow::keyPressEvent( QKeyEvent *key) {

    if (key->isAutoRepeat())
        return;

    switch ( key->key() ) {

        case Qt::Key_A: musicplayer->playNote(0); break;
        case Qt::Key_S: musicplayer->playNote(2); break;
        case Qt::Key_D: musicplayer->playNote(3); break;
        case Qt::Key_F: musicplayer->playNote(5); break;
        case Qt::Key_G: musicplayer->playNote(7); break;
        case Qt::Key_H: musicplayer->playNote(8); break;
        case Qt::Key_J: musicplayer->playNote(10); break;

        case Qt::Key_W: musicplayer->playNote(1); break;
        case Qt::Key_R: musicplayer->playNote(4); break;
        case Qt::Key_T: musicplayer->playNote(6); break;
        case Qt::Key_U: musicplayer->playNote(9); break;

        // exit program
        case Qt::Key_Q: QApplication::exit(); break;

    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *key) {

    if (key->isAutoRepeat())
        return;

    switch ( key->key() ) {

        case Qt::Key_A: musicplayer->stopNote(0); break;
        case Qt::Key_S: musicplayer->stopNote(2); break;
        case Qt::Key_D: musicplayer->stopNote(3); break;
        case Qt::Key_F: musicplayer->stopNote(5); break;
        case Qt::Key_G: musicplayer->stopNote(7); break;
        case Qt::Key_H: musicplayer->stopNote(8); break;
        case Qt::Key_J: musicplayer->stopNote(10); break;

        case Qt::Key_W: musicplayer->stopNote(1); break;
        case Qt::Key_R: musicplayer->stopNote(4); break;
        case Qt::Key_T: musicplayer->stopNote(6); break;
        case Qt::Key_U: musicplayer->stopNote(9); break;

    }

}

void MainWindow::on_Record_clicked() {

    musicplayer->startRecording();

}

void MainWindow::on_Play_clicked() {

    Melody *m = musicplayer->stopRecording();
    musicplayer->play(m);

}

void MainWindow::resizeEvent(QResizeEvent *event) {

    resize(event->size());

    menubar->updateSize(event->size());
    notefield->updateSize(event->size());

}

MainWindow::~MainWindow() {

    engine->drop();
    delete ui;

}
