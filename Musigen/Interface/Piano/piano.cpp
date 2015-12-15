#include "piano.h"

Piano* Piano::instance = nullptr;

Piano* Piano::getInstance() {

    if (instance == nullptr) {

        instance = new Piano();

    }

    return instance;

    //return instance == nullptr ? instance = new Piano() : instance;

}

Piano::Piano(QWidget *parent) : QMainWindow(parent) {

    resize(500, 200);

}

Piano::~Piano() {

}

