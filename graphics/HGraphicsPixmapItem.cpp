#include "HGraphicsPixmapItem.h"


HGraphicsPixmapItem::HGraphicsPixmapItem(QGraphicsItem *parent):
    QGraphicsPixmapItem (parent)
{

}

HGraphicsPixmapItem::HGraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent):
    QGraphicsPixmapItem (pixmap, parent)
{

}

void HGraphicsPixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
}


#ifdef OPEN_EDIT_MODE

void HGraphicsPixmapItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (!isSelected() && scene())
    {
        return;
    }
    else {
        QMenu menu;
        QAction *newAction = menu.addAction("复制");
        QAction *resetAction = menu.addAction("复原");
        QAction *delAction = menu.addAction("删除");

        QAction *selectedAction = menu.exec(event->screenPos());

        if (selectedAction == delAction)
            deleteSelectedItems(scene());
        else if (selectedAction == newAction)
            duplicateSelectedItems(scene());
        else if (selectedAction == resetAction)
            resetScaleItem();
    }
}

HGraphicsPixmapItem *HGraphicsPixmapItem::createNew(QPixmap &pixmap)
{
    HGraphicsPixmapItem * item = new HGraphicsPixmapItem(pixmap);
    item->setAcceptHoverEvents(true);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    return item;
}

void HGraphicsPixmapItem::resetScaleItem(){
    setScale(1);
}

void HGraphicsPixmapItem::duplicateSelectedItems(QGraphicsScene *scene)
{
    if (!scene)
        return;

    QList<QGraphicsItem *> selected;
    selected = scene->selectedItems();

    foreach (QGraphicsItem *item, selected)
    {
        QGraphicsPixmapItem *HGraphicsPixmapItem = qgraphicsitem_cast<QGraphicsPixmapItem *>(item);

        if (HGraphicsPixmapItem)
        {
            QPixmap pixmap = HGraphicsPixmapItem->pixmap();
            QGraphicsPixmapItem * item2 = createNew(pixmap);
            item2->setPos(this->pos().rx()+50,this->pos().ry());

            scene->addItem(item2);
        }

    }
}

void HGraphicsPixmapItem::deleteSelectedItems(QGraphicsScene *scene)
{
    if (!scene)
        return;

    QList<QGraphicsItem *> selected;
    selected = scene->selectedItems();

    foreach (QGraphicsItem *item, selected)
    {
        QGraphicsRectItem *HGraphicsPixmapItem = static_cast<QGraphicsRectItem *>(item);
        if (HGraphicsPixmapItem)
            delete HGraphicsPixmapItem;
    }
}

void HGraphicsPixmapItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    prepareGeometryChange();
    if(event->delta()>0){
        setScale(scale()+0.1);
    }
    else if (event->delta()<0) {
        setScale(scale()-0.1);
    }
}

#endif
