#ifndef HGRAPHICSBEZIERITEM_H
#define HGRAPHICSBEZIERITEM_H

#include <QGraphicsPathItem>
#include <QPainter>

class HGraphicsBezierItem : public QGraphicsPathItem
{
public:
    bool isDrawPoints;
    void drawPointsEnable(bool flag);
protected:

    QList<QPointF> fountainPoints;
public:
    explicit HGraphicsBezierItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsBezierItem(const QPainterPath &path, QGraphicsItem *parent = nullptr);

    void setPath(const QPainterPath &path, QList<QPointF> &pointList);
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    void drawPoints(QPainter *painter, QList<QPointF> pointList, QColor color);
};

#endif // HGRAPHICSBEZIERITEM_H
