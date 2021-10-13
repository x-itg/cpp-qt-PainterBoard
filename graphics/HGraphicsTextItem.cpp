#include "HGraphicsTextItem.h"


HGraphicsTextItem::HGraphicsTextItem(QGraphicsItem *parent):
    QGraphicsTextItem (parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsTextItem::HGraphicsTextItem(const QString &text, QGraphicsItem *parent):
    QGraphicsTextItem (text, parent)
{
//    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
//    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
//    setFlag(QGraphicsItem::ItemIsSelectable);
//    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF HGraphicsTextItem::boundingRect() const
{
//    return  QRectF(0, 0, itemSize.width() + 10, itemSize.height() + 10);
    return QGraphicsTextItem::boundingRect();
}


void HGraphicsTextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsTextItem::mousePressEvent(event);
}

void HGraphicsTextItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsTextItem::mouseMoveEvent(event);
}

void HGraphicsTextItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsTextItem::mouseReleaseEvent(event);
}
