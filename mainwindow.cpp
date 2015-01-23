#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWindow>
#include <QStackedLayout>
#include <QKeyEvent>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    full(false)
{
    ui->setupUi(this);
    ui->expertPanel->hide();
    m_detached_window = new QMainWindow(this);
    m_epilepsy = new Epilepsy(m_detached_window);
    m_detached_window->setCentralWidget(m_epilepsy);

    m_shortcut = new QShortcut(m_detached_window);
    m_shortcut->setKey(Qt::Key_Space);
    connect(m_shortcut, SIGNAL(activated()), this, SLOT(stopEpilepsy()));

    connect(ui->alpha, SIGNAL(clicked()), this, SLOT(alpha()));
    connect(ui->beta, SIGNAL(clicked()), this, SLOT(beta()));
    connect(ui->theta, SIGNAL(clicked()), this, SLOT(theta()));
    connect(ui->delta, SIGNAL(clicked()), this, SLOT(delta()));
    connect(ui->custom, SIGNAL(clicked()), this, SLOT(custom()));
    connect(ui->expertBox, SIGNAL(toggled(bool)), ui->expertPanel, SLOT(setVisible(bool)));
    connect(ui->hzSlider, SIGNAL(valueChanged(int)), this, SLOT(hzChanged(int)));
    connect(ui->hzSpin, SIGNAL(valueChanged(double)), this, SLOT(hzChanged(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_detached_window;
    delete m_epilepsy;
    delete m_shortcut;
}

void MainWindow::startEpilepsy(float hz) {
    m_epilepsy->setHz(hz);
    hide();
    m_detached_window->showFullScreen();
}

void MainWindow::stopEpilepsy() {
    m_detached_window->hide();
    showNormal();
}

void MainWindow::hzChanged(double value) {
    ui->hzSlider->setValue(value);
    ui->hzSpin->setValue(value);
    m_hz = value;
}

void MainWindow::hzChanged(int value) {
    hzChanged(double(value));
}
