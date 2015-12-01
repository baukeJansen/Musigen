#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <irrKlang.h>
#include <QKeyEvent>
#include <Melody/instrument.h>
#include <musicplayer.h>
#include <notefield.h>

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void keyPressEvent(QKeyEvent *key);
    virtual void keyReleaseEvent(QKeyEvent *key);

private slots:
    void on_pushButton_clicked();

    void on_Play_clicked();

    void on_Record_clicked();

private:
    Ui::MainWindow *ui;
    irrklang::ISoundEngine* engine;
    Instrument *instrument;
    MusicPlayer *mp;
    NoteField *notefield;

};

#endif // MAINWINDOW_H
