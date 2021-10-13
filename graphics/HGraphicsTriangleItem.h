#pragma once
#ifndef HGRAPHICSTRIANGLEITEM_H
#define HGRAPHICSTRIANGLEITEM_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

#include <QPen>
#include <QPainter>
#include <QBrush>

#include "define_global.h"
#ifdef OPEN_EDIT_MODE
#include <QGraphicsScene>
#include <QMenu>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QVector2D>
#include "math.h"
#endif

class HGraphicsTriangleItem : public QGraphicsRectItem
{
#ifdef OPEN_EDIT_MODE
public:
    bool        m_isResizing = false;
    bool        m_isRotating = false;
protected:

    inline qreal GetDegreeAngle(QVector2D vector2d) const
    {
        return fmod((atan2((qreal)vector2d.y(), (qreal)vector2d.x()) * AnglePerPI + 360.0), 360.0 );
    }
#endif

public:
    QPen pen;
    QBrush brush;

public:
    explicit HGraphicsTriangleItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsTriangleItem(QRectF &rect,QGraphicsItem *parent = nullptr);
    explicit HGraphicsTriangleItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
    virtual ~HGraphicsTriangleItem() override;


    void setPen(QPen pen);
    void setBrush(QBrush brush);

#ifdef OPEN_EDIT_MODE
    bool isInResizeArea(const QPointF &pos);
    bool isInRotateArea(const QPointF &pos);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
#endif

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    HGraphicsTriangleItem *createNew(QRectF &rectf);
    void deleteSelectedItems(QGraphicsScene *scene);
    void duplicateSelectedItems(QGraphicsScene *scene);
        void resetScaleItem();

protected:

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

};

#endif // HGRAPHICSTRIANGLEITEM_H
