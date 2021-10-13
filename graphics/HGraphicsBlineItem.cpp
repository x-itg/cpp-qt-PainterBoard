#include "HGraphicsBlineItem.h"


void HGraphicsBlineItem::drawPointsEnable(bool flag)
{
    isDrawPoints = flag;
}

HGraphicsBlineItem::HGraphicsBlineItem(QGraphicsItem *parent):QGraphicsPathItem (parent)
{

    isDrawPoints = false;
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsBlineItem::HGraphicsBlineItem(const QPainterPath &path, QGraphicsItem *parent):QGraphicsPathItem (path, parent)
{
    isDrawPoints = false;
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void HGraphicsBlineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isDrawPoints){
        painter->save();
        drawPoints(painter, blinePoints, Qt::blue);
        painter->restore();
    }

    QGraphicsPathItem::paint(painter, option, widget);
}

void HGraphicsBlineItem::setPath(const QPainterPath &path, QVector<QPointF> &pointList)
{
    this->blinePoints = pointList;
    QGraphicsPathItem::setPath(path);
}


void HGraphicsBlineItem::drawPoints(QPainter * painter, QVector<QPointF> pointList, QColor color)
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

