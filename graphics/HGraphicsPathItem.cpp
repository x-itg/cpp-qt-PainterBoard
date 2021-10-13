#include "HGraphicsPathItem.h"

HGraphicsPathItem::HGraphicsPathItem(QGraphicsItem *parent):
    QGraphicsPathItem (parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);


}

HGraphicsPathItem::HGraphicsPathItem(const QPainterPath &path, QGraphicsItem *parent):
    QGraphicsPathItem (path, parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

//void HGraphicsPathItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    DBG;
//    setFocus();
//    setCursor(Qt::ClosedHandCursor);
//}

QRectF HGraphicsPathItem::boundingRect() const
{
    {
        //    return QRectF(0,0,600,600);
    }

    {
        return QGraphicsPathItem::boundingRect();
    }

}

bool HGraphicsPathItem::contains(const QPointF &point) const
{
    return QGraphicsPathItem::contains(point);
}

bool HGraphicsPathItem::isObscuredBy(const QGraphicsItem *item) const
{
    return QGraphicsPathItem::isObscuredBy(item);
}

QPainterPath HGraphicsPathItem::opaqueArea() const
{
    return QGraphicsPathItem::opaqueArea();
}

void HGraphicsPathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //    painter->setPen(pen());
    //    painter->setBrush(brush());
    //    painter->drawPath(path());

    QGraphicsPathItem::paint(painter, option, widget);
}

QPainterPath HGraphicsPathItem::shape() const
{
    return QGraphicsPathItem::shape();
}

int HGraphicsPathItem::type() const
{
    return QGraphicsPathItem::type();
}
