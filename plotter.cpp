#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>

Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{
    theta = 0;
    amplitude = 1;
    frequencia = 1;
    velocidade = 0;
    startTimer(10);
    setMouseTracking(true);
}

void Plotter::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    painter.setRenderHint(QPainter::Antialiasing);
    brush.setColor(QColor(255, 255, 200));
    brush.setStyle(Qt::SolidPattern);
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0, 0, width(), height());
    pen.setColor(QColor(200, 200, 0));
    painter.setPen(pen);
    painter.drawLine(0, height()/2, width(), height()/2);
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    float x0, x1, y0, y1;

    x0 = 0;
    y0 = amplitude * sin(2*M_PI*frequencia*x0 + theta);
    for (int i=1; i<width(); i++) {
        x1 = 2*M_PI*i/(float)width();
        y1 = amplitude * sin(2*M_PI*frequencia*x1 + theta);
        painter.drawLine(x0*width(),
                         height()/2 - y0*height()/2,
                         x1*width(),
                         height()/2 - y1*height()/2);
        x0 = x1;
        y0 = y1;
    }
}

void Plotter::timerEvent(QTimerEvent *event) {
    theta = theta + velocidade;
    if (theta > 2*M_PI) {
        theta = 0;
    }
    repaint();
}

void Plotter::mousePressEvent(QMouseEvent *event) {
    emit mudaX(event->x());
    emit mudaY(event->y());
}

void Plotter::mudaAmp(int amp) {
    amplitude = amp/100.0;
    repaint();
}

void Plotter::mudaFreq(int freq) {
    frequencia = (float)freq/50;
    repaint();
}

void Plotter::mudaVel(int vel) {
    velocidade = (float)vel/1000;
    repaint();
}
