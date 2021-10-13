#ifndef HGRAPHICSTEXTITEM_H
#define HGRAPHICSTEXTITEM_H

#include <QGraphicsTextItem>

class HGraphicsTextItem : public QGraphicsTextItem
{
public:
    explicit HGraphicsTextItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsTextItem(const QString &text, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)override;

};

#endif // HGRAPHICSTEXTITEM_H
