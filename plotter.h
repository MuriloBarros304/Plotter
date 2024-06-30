#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
private:
    float theta;
    float amplitude;
    float frequencia;
    float velocidade;
    int fundoR, fundoG, fundoB;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:
    void mudaX(int);
    void mudaY(int);
public slots:
    void mudaAmp(int amp);
    void mudaFreq(int freq);
    void mudaVel(int vel);
};

#endif // PLOTTER_H
