#ifndef WIDGETCANVAS_H
#define WIDGETCANVAS_H

#include <QWidget>
#include <QDebug>
#include <BezierAlgorithmManager.h>
#include <QPainter>

#include "CommonSpace_global.h"

class WidgetCanvas : public QWidget
{
public:
    WidgetCanvas(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


    QPointF pointOnece(QPointF pointA, QPointF pointB, double t);
    QPointF recursivePointOnece(QList<QPointF> &pointList, int lenth, int time, double t);
    QPointF generateBezierCurve(QList<QPointF> &pointList, double t);
    QPointF pointTwice(QPointF pointA, QPointF pointB, QPointF pointC, double t);
    QPointF pointThrice(QPointF pointA, QPointF pointB, QPointF pointC, QPointF pointD, double t);

    QPen m_pen;
private:
    QList<QPointF> pointOriginList;
    QList<QPointF> pointBlineList;
    QList<QPointF> pointFountainPenList;
};

#endif // WIDGETCANVAS_H
