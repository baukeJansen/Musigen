#ifndef PIANO_H
#define PIANO_H

#include <QMainWindow>

class Piano : public QMainWindow {

    Q_OBJECT

public:
    static Piano* getInstance();
    ~Piano();

    static Piano *instance;

private:
    Piano(QWidget *parent = 0);

signals:

public slots:

};

#endif // PIANO_H
