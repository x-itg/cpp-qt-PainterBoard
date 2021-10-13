#include "HGraphicsBezierItem.h"


void HGraphicsBezierItem::drawPointsEnable(bool flag)
{
    isDrawPoints = flag;
}

HGraphicsBezierItem::HGraphicsBezierItem(QGraphicsItem *parent):QGraphicsPathItem (parent)
{
    isDrawPoints = false;

    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsBezierItem::HGraphicsBezierItem(const QPainterPath &path, QGraphicsItem *parent):QGraphicsPathItem (path, parent)
{
    isDrawPoints = false;

    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void HGraphicsBezierItem::setPath(const QPainterPath &path, QList<QPointF> &pointList)
{
    this->fountainPoints = pointList;
    QGraphicsPathItem::setPath(path);
}

void HGraphicsBezierItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isDrawPoints){
        painter->save();
        drawPoints(painter, fountainPoints, Qt::blue);
        painter->restore();
    }

    QGraphicsPathItem::paint(painter, option, widget);
}

void HGraphicsBezierItem::drawPoints(QPainter * painter, QList<QPointF> pointList, QColor color)
{
    if(painter){
        painter->save();
        QPen pen = painter->pen();
        pen.setWidth(4);
        pen.setColor(color);
        painter->setPen(pen);
        int n = pointList.length();
        if(n>3){
            for (int i = n-3; i < n; ++i) {
                painter->drawPoint(pointList.at(i));
            }
        }
        painter->restore();
    }
}



