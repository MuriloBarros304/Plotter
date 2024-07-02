#include "mainwindow.h"

#include <QDebug>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButtonQuit, 
    SIGNAL(clicked(bool)),
    this, 
    SLOT(finaliza()));

    connect(ui->horizontalSliderAmp, 
    SIGNAL(valueChanged(int)), 
    ui->widgetPlot,
    SLOT(mudaAmp(int)));

    connect(ui->horizontalSliderFreq, 
    SIGNAL(valueChanged(int)), 
    ui->widgetPlot,
    SLOT(mudaFreq(int)));

    connect(ui->horizontalSliderVel, 
    SIGNAL(valueChanged(int)), 
    ui->widgetPlot,
    SLOT(mudaVel(int)));
    
    ui->horizontalSliderAmp->setValue(100);
    ui->horizontalSliderFreq->setValue(50);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::finaliza() { exit(0); }
