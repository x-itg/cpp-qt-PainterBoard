#ifndef HGRAPHICSBLINEITEM_H
#define HGRAPHICSBLINEITEM_H

#include <QGraphicsPathItem>
#include <QPen>
#include <QPainter>

class HGraphicsBlineItem : public QGraphicsPathItem
{
public:
    bool isDrawPoints;
    void drawPointsEnable(bool flag);
protected:

    QVector<QPointF> blinePoints;
public:
    explicit HGraphicsBlineItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsBlineItem(const QPainterPath &path, QGraphicsItem *parent = nullptr);

    void drawPoints(QPainter *painter, QVector<QPointF> pointList, QColor color);
    void setPath(const QPainterPath &path, QVector<QPointF> &pointList);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

};

#endif // HGRAPHICSBLINEITEM_H
