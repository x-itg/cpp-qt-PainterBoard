#ifndef HGRAPHICSPIXMAPITEM_H
#define HGRAPHICSPIXMAPITEM_H

#include <QGraphicsPixmapItem>

#include "define_global.h"
#ifdef OPEN_EDIT_MODE
#include <QPainter>
#include <QGraphicsScene>
#include <QMenu>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QVector2D>
#include "math.h"
#endif

class HGraphicsPixmapItem : public QGraphicsPixmapItem
{
public:
    explicit HGraphicsPixmapItem(QGraphicsItem *parent = nullptr);
    explicit HGraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;


#ifdef OPEN_EDIT_MODE
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
#endif

    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
    HGraphicsPixmapItem *createNew(QPixmap &pixmap);
    void deleteSelectedItems(QGraphicsScene *scene);
    void duplicateSelectedItems(QGraphicsScene *scene);
        void resetScaleItem();
};

#endif // HGRAPHICSPIXMAPITEM_H
