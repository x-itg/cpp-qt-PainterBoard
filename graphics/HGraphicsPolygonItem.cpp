#include "HGraphicsPolygonItem.h"


HGraphicsPolygonItem::HGraphicsPolygonItem(QGraphicsItem *parent):
    QGraphicsPolygonItem (parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);


}

HGraphicsPolygonItem::HGraphicsPolygonItem(const QPolygonF &polygon, QGraphicsItem *parent):
    QGraphicsPolygonItem (polygon, parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void HGraphicsPolygonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    DBG;
    QGraphicsPolygonItem::mousePressEvent(event);
}

void HGraphicsPolygonItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    DBG;
    QGraphicsPolygonItem::mouseMoveEvent(event);
}

void HGraphicsPolygonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    DBG;
    QGraphicsPolygonItem::mouseReleaseEvent(event);
}

void HGraphicsPolygonItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    DBG;
    QGraphicsPolygonItem::hoverEnterEvent(event);
}

void HGraphicsPolygonItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    DBG;
    QGraphicsPolygonItem::hoverMoveEvent(event);
}

void HGraphicsPolygonItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    DBG;
    QGraphicsPolygonItem::hoverLeaveEvent(event);
}

void HGraphicsPolygonItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    DBG;
    QGraphicsPolygonItem::dragEnterEvent(event);
}

void HGraphicsPolygonItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    DBG;
    QGraphicsPolygonItem::dragLeaveEvent(event);
}

void HGraphicsPolygonItem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    DBG;
    QGraphicsPolygonItem::dragMoveEvent(event);
}

