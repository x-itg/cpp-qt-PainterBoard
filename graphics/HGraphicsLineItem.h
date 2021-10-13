#ifndef HGRAPHICSLINEITEM_H
#define HGRAPHICSLINEITEM_H

#include <QGraphicsLineItem>

#include "define_global.h"

#ifdef OPEN_EDIT_MODE
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QVector2D>
#include <QPainter>
#include "math.h"
#endif

class HGraphicsLineItem : public QGraphicsLineItem
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

    bool isInResizeArea(const QPointF &pos);
    bool isInRotateArea(const QPointF &pos);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
#endif

public:
    explicit HGraphicsLineItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsLineItem(const QLineF &line, QGraphicsItem *parent = nullptr);
    explicit HGraphicsLineItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // HGRAPHICSLINEITEM_H
