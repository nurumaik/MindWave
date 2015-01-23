#ifndef EPILEPSY_H
#define EPILEPSY_H

#include <QtOpenGL/QGLWidget>
#include <chrono>

using namespace std::chrono;

class Epilepsy : public QGLWidget {
    Q_OBJECT
public:
    Epilepsy(QWidget *parent);
    ~Epilepsy();
    float getHz() {return m_hz;}
    void setHz(float hz) {m_hz = hz;}

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent*) Q_DECL_OVERRIDE;

private:
    bool m_black = false;
    float m_hz = 7;
    time_point<high_resolution_clock> last = high_resolution_clock::now();

};

#endif // EPILEPSY_H
