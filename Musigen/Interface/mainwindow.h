#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mouselistener.h>
#include <QKeyEvent>
#include <musicplayer.h>
#include <Interface/notefield.h>
#include <Interface/menubar.h>
#include <Interface/button.h>
#include <Melody/instrument.h>
#include <QGraphicsAnchorLayout>


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

    void resizeEvent(QResizeEvent *event);


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

    MenuBar *menubar;
    MouseListener *mouseListener;
    Button *closeButton;

};

#endif // MAINWINDOW_H