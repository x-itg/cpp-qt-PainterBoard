#ifndef COMMONGRAPHICSPIXMAP_H
#define COMMONGRAPHICSPIXMAP_H

#include <QGraphicsObject>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QPushButton>

class HGraphicsPixmapObject : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit HGraphicsPixmapObject(QPixmap pixmap,QString title,QGraphicsItem *parent = nullptr);
//    void setTitle(QString string);
//    QString getTitle()const
//    {
//        return this->title;
//    }
//    void setTextColor(QColor color);
signals:
    void sendItemInfo(QVariant);

protected:
//    QVariant itemChange(GraphicsItemChange change, const QVariant &value)override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
    virtual QRectF boundingRect()const override;
//    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event)override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
//    void hoverMoveEvent(QGraphicsSceneHoverEvent* event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)override;

private:
//    void setNewPixmap();
//    bool IsInResizeArea(const QPointF& pos);

    QPixmap pixmap;
    QString title;
    QColor textColor;
    QSizeF itemSize;
    bool isResizing;  //是否正在改变大小的过程中
};

#endif // COMMONGRAPHICSPIXMAP_H
