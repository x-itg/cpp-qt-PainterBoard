#ifndef HGRAPHICSPOLYGONITEM_H
#define HGRAPHICSPOLYGONITEM_H

#include <QGraphicsPolygonItem>
#include "define_global.h"

class HGraphicsPolygonItem : public QGraphicsPolygonItem
{
public:
    explicit HGraphicsPolygonItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsPolygonItem(const QPolygonF &polygon,
                                  QGraphicsItem *parent = nullptr);

    QVector<QPointF> points;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;//目前只捕获这个函数，而且快速点击
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;

private:
    //    QRectF m_rect;
    bool cScale;
    QCursor* m_cursor;
    QPointF start;
    QPointF end;
    int direction;
    bool isReadyToEdit;

    int nearByPointI(QPointF point);
};

#endif // HGRAPHICSPOLYGONITEM_H
