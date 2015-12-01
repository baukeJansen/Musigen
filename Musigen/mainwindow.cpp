#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    engine = irrklang::createIrrKlangDevice();
    instrument = new Instrument(engine);
    mp = new MusicPlayer(instrument);

    if (!engine) {

        qDebug(" === failed creating irrklang engine === ");

    }

    notefield = new NoteField(ui->notefieldWrapper, mp);

}

void MainWindow::on_pushButton_clicked() {

    //engine->play2D("C:\\Users\\Bauke\\Documents\\Files\\School\\4 - Minor ( 1 - 2 )\\Project\\Musigen\\Resources\\Sound\\piano_c.wav");

}

void MainWindow::keyPressEvent( QKeyEvent *key) {

    if (key->isAutoRepeat())
        return;

    switch ( key->key() ) {

        case Qt::Key_A: mp->playNote(0); break;
        case Qt::Key_S: mp->playNote(2); break;
        case Qt::Key_D: mp->playNote(3); break;
        case Qt::Key_F: mp->playNote(5); break;
        case Qt::Key_G: mp->playNote(7); break;
        case Qt::Key_H: mp->playNote(8); break;
        case Qt::Key_J: mp->playNote(10); break;

        case Qt::Key_W: mp->playNote(1); break;
        case Qt::Key_R: mp->playNote(4); break;
        case Qt::Key_T: mp->playNote(6); break;
        case Qt::Key_U: mp->playNote(9); break;

        // exit program
        case Qt::Key_Q: QApplication::exit(); break;

    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *key) {

    if (key->isAutoRepeat())
        return;

    switch ( key->key() ) {

        case Qt::Key_A: mp->stopNote(0); break;
        case Qt::Key_S: mp->stopNote(2); break;
        case Qt::Key_D: mp->stopNote(3); break;
        case Qt::Key_F: mp->stopNote(5); break;
        case Qt::Key_G: mp->stopNote(7); break;
        case Qt::Key_H: mp->stopNote(8); break;
        case Qt::Key_J: mp->stopNote(10); break;

        case Qt::Key_W: mp->stopNote(1); break;
        case Qt::Key_R: mp->stopNote(4); break;
        case Qt::Key_T: mp->stopNote(6); break;
        case Qt::Key_U: mp->stopNote(9); break;

    }

}

void MainWindow::on_Record_clicked() {
qDebug("startRec");
    mp->startRecording();

}

void MainWindow::on_Play_clicked() {
qDebug("playRec");
    Melody *m = mp->stopRecording();
    mp->play(m);

}


MainWindow::~MainWindow() {

    delete notefield;
    delete instrument;
    delete mp;

    engine->drop();
    delete ui;

}