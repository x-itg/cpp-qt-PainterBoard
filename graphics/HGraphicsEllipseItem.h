#ifndef HGRAPHICSELLIPSEITEM_H
#define HGRAPHICSELLIPSEITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>

#include "define_global.h"
#ifdef OPEN_EDIT_MODE
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QVector2D>
#include <QMenu>
#include <QGraphicsScene>
#include "math.h"
#endif

class HGraphicsEllipseItem : public QGraphicsEllipseItem
{
#ifdef OPEN_EDIT_MODE
public:
    bool        m_isResizing = false;
    bool        m_isRotating = false;

public:
    QPen pen;
    QBrush brush;

    void setPen(QPen pen);
    void setBrush(QBrush brush);

protected:
    inline qreal GetDegreeAngle(QVector2D vector2d) const
    {
        return fmod((atan2((qreal)vector2d.y(), (qreal)vector2d.x()) * AnglePerPI + 360.0), 360.0 );
    }
#endif

public:
    HGraphicsEllipseItem(QGraphicsItem *parent = nullptr);
    HGraphicsEllipseItem(const QRectF &rect, QGraphicsItem *parent = nullptr);
    HGraphicsEllipseItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);

    virtual QRectF
    boundingRect() const override;



protected:
#ifdef OPEN_EDIT_MODE
    bool isInResizeArea(const QPointF &pos);
    bool isInRotateArea(const QPointF &pos);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
#endif


#ifdef OPEN_EDIT_MODE
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
#endif

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    HGraphicsEllipseItem *createNew(QRectF &rectf);
    void deleteSelectedItems(QGraphicsScene *scene);
    void duplicateSelectedItems(QGraphicsScene *scene);
    void resetScaleItem();

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

};

#endif // HGRAPHICSELLIPSEITEM_H
