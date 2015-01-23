#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "epilepsy.h"

#include <QMainWindow>

QT_FORWARD_DECLARE_CLASS(QShortcut)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void alpha() {
        startEpilepsy(12);
    }
    void beta() {
        startEpilepsy(24);
    }
    void theta() {
        startEpilepsy(6);
    }
    void delta() {
        startEpilepsy(3);
    }
    void custom() {
        startEpilepsy(m_hz);
    }

    void stopEpilepsy();
    void hzChanged(double value);
    void hzChanged(int value);

protected:
    //void keyPressEvent(QKeyEvent *k) Q_DECL_OVERRIDE;

private:
    void startEpilepsy(float hz = 7);

    Ui::MainWindow *ui;
    Epilepsy *m_epilepsy;
    QMainWindow *m_detached_window;
    QShortcut *m_shortcut;
    double m_hz = 1;
    bool full;
};

#endif // MAINWINDOW_H
