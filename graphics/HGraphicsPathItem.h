#ifndef HGRAPHICSITEM_H
#define HGRAPHICSITEM_H

#include <QGraphicsPathItem>
#include <QPainter>
#include <QCursor>


class HGraphicsPathItem : public QGraphicsPathItem
{

public:
    HGraphicsPathItem(QGraphicsItem *parent = nullptr);
    HGraphicsPathItem(const QPainterPath &path, QGraphicsItem *parent = nullptr);

protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

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

};

#endif // HGRAPHICSITEM_H
