#ifndef HGRAPHICSRECTITEM_H
#define HGRAPHICSRECTITEM_H

#include <QGraphicsObject>
#include <QGraphicsRectItem>
#include <QCursor>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>

#include "define_global.h"

#ifdef OPEN_EDIT_MODE
#include <QStyleOptionGraphicsItem>
#include "math.h"
#endif

class HGraphicsRectItem : public QGraphicsRectItem
{
#ifdef OPEN_EDIT_MODE
public:
    bool m_isResizing = false;
    bool m_isRotating = false;

protected:
    inline qreal GetDegreeAngle(QVector2D vector2d) const
    {
        return fmod((atan2((qreal)vector2d.y(), (qreal)vector2d.x()) * AnglePerPI + 360.0), 360.0 );
    }
#endif

public:
    explicit HGraphicsRectItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsRectItem(const QRectF &rect, QGraphicsItem *parent = nullptr);
    explicit HGraphicsRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
    ~HGraphicsRectItem() override;

public:
    virtual QRectF
    boundingRect() const override;

    virtual bool
    contains(const QPointF &point) const override;

    virtual bool
    isObscuredBy(const QGraphicsItem *item) const override;

    virtual QPainterPath
    opaqueArea() const override;

    virtual void
    paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    virtual QPainterPath
    shape() const override;

    virtual int
    type() const override;

#ifdef OPEN_EDIT_MODE
public:
    bool isInResizeArea(const QPointF &pos);
    bool isInRotateArea(const QPointF &pos);

protected:


    virtual void
    hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

    virtual void
    mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void
    mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    virtual void
    mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
#endif

protected:
    virtual void
    contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    virtual void
    dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;

    virtual void
    dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;

    virtual void
    dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;

    virtual void
    dropEvent(QGraphicsSceneDragDropEvent *event) override;

    virtual void
    focusInEvent(QFocusEvent *event) override;

    virtual void
    focusOutEvent(QFocusEvent *event) override;

    virtual void
    hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    virtual void
    hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    virtual void
    inputMethodEvent(QInputMethodEvent *event) override;

    virtual QVariant
    inputMethodQuery(Qt::InputMethodQuery query) const override;

    virtual QVariant
    itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

    virtual void
    keyPressEvent(QKeyEvent *event) override;

    virtual void
    keyReleaseEvent(QKeyEvent *event) override;

    virtual void
    mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

    void
    prepareGeometryChange();

    virtual bool
    sceneEvent(QEvent *event) override;

    virtual bool
    sceneEventFilter(QGraphicsItem *watched, QEvent *event) override;

    void
    updateMicroFocus();

    virtual void
    wheelEvent(QGraphicsSceneWheelEvent *event) override;
};

#endif // HGRAPHICSRECTITEM_H
