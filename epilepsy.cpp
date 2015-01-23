#include "epilepsy.h"
#include <QKeyEvent>


Epilepsy::Epilepsy(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::DoubleBuffer), parent)
{
    startTimer(0, Qt::PreciseTimer);
}

Epilepsy::~Epilepsy()
{

}

void Epilepsy::initializeGL() {

}

void Epilepsy::paintGL() {
    if (m_black)
        glClearColor(0, 0, 0, 1);
    else
        glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Epilepsy::timerEvent(QTimerEvent *) {
    auto tick = microseconds(int(1000000/(m_hz*2)));
    time_point<high_resolution_clock> curr = high_resolution_clock::now();
    while (curr - last >= tick) {
        last += tick;
        m_black = !m_black;
        update();
    }
}


