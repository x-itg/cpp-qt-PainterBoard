#include "HGraphicsEllipseItem.h"


#ifdef OPEN_EDIT_MODE
bool HGraphicsEllipseItem::isInResizeArea(const QPointF &pos)
{
    int width = static_cast<int>(boundingRect().width()/2);
    int height = static_cast<int>(boundingRect().height()/2);

    QRectF rectf = QRectF(width-9, height-9, width, height);
    if(rectf.contains(pos))
    {
        return true;
    }
    else {
        return false;
    }
}

bool HGraphicsEllipseItem::isInRotateArea(const QPointF &pos)
{
    int height = static_cast<int>(boundingRect().height()/2);

    QRectF rectf = QRectF(-10, -height, 20 , -height+100);
    if(rectf.contains(pos))
    {
        return true;
    }
    else {
        return false;
    }
}

void HGraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsEllipseItem::paint(painter, option, widget);
#ifdef OPEN_EDIT_MODE
    if (option->state & QStyle::State_Selected)
    {
        painter->setRenderHint(QPainter::Antialiasing, true);
        if (option->state & QStyle::State_HasFocus)
        {
            painter->setPen(Qt::yellow);
        }
        else
        {
            painter->setPen(Qt::white);
        }
        // resize contrl area...
        painter->setPen(Qt::blue);
        int width = static_cast<int>(boundingRect().width()/2);
        int height = static_cast<int>(boundingRect().height()/2);
        painter->drawLine(width-9,  height,  width,  height-9);
        painter->drawLine(width-6,  height,  width,  height-6);
        painter->drawLine(width-3,  height,  width,  height-3);
        // rotate control point
        painter->setPen(Qt::blue);
        painter->drawLine(0, -height, 0, height);
        painter->setPen(QPen(Qt::blue, 5));
        painter->drawPoint(0, -height);

        painter->setRenderHint(QPainter::Antialiasing, false);
    }
#endif
}
#endif

void HGraphicsEllipseItem::setPen(QPen pen)
{
    this->pen = pen;
    QGraphicsEllipseItem::setPen(pen);
}

void HGraphicsEllipseItem::setBrush(QBrush brush)
{
    this->brush = brush;
    QGraphicsEllipseItem::setBrush(brush);
}

HGraphicsEllipseItem::HGraphicsEllipseItem(QGraphicsItem *parent):
    QGraphicsEllipseItem (parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsEllipseItem::HGraphicsEllipseItem(const QRectF &rect, QGraphicsItem *parent):
    QGraphicsEllipseItem (rect, parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsEllipseItem::HGraphicsEllipseItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):
    QGraphicsEllipseItem (x, y, w, h, parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF HGraphicsEllipseItem::boundingRect() const
{
    return QGraphicsEllipseItem::boundingRect();
}



#ifdef OPEN_EDIT_MODE
void HGraphicsEllipseItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    {
        if (m_isResizing || (isInResizeArea(event->pos()) && isSelected()))
        {
            qDebug() << "hoverMoveEvent size";
            setCursor(Qt::SizeFDiagCursor);
        }
        else if ((isInRotateArea(event->pos()) && isSelected()))
        {
            qDebug() << "hoverMoveEvent rotate";
            QCursor *rotateCursor = new QCursor(QPixmap(":/qrc/rotate_small.png"));
            setCursor(*rotateCursor);
        }
        else
        {
            setCursor(Qt::ArrowCursor);
        }
    }

    QGraphicsItem::hoverMoveEvent(event);
}


void HGraphicsEllipseItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_isResizing)
    {
        int dx = int(2.0 * event->pos().x());
        int dy = int(2.0 * event->pos().y());

        prepareGeometryChange();
        boundingRect();
        QRect rect = QRect(-dx/2, -dy/2, dx, dy);
        this->setRect(rect);
    }
    else if (m_isRotating)
    {
        QPointF cursorPos = event->pos();
        QVector2D vectorStart = QVector2D(QPointF(0.0, -boundingRect().height() / 2) - QPointF(0.0, 0.0));           // 起始向量
        QVector2D vectorEnd = QVector2D(cursorPos - QPointF(0.0, 0.0));                                             // 结束向量
        // 计算起始向量和结束向量之间的角度
        qreal angle = 0.0;
        qreal angleEnd = GetDegreeAngle(vectorEnd);
        qreal angleStart = GetDegreeAngle(vectorStart);
        angle = angleEnd - angleStart + rotation();
        if (angle > 360.0)
        {
            while(1)
            {
                angle -= 360.0;
                if (angle < 360.0) break;
            }
        }
        else if (angle < 0.0)
        {
            while(1)
            {
                angle += 360.0;
                if (angle > 0.0) break;
            }
        }

        setRotation((int)angle);
    }
    else
    {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void HGraphicsEllipseItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    {
        static qreal z = 0.0;
        setZValue(z += 1.0);

        if (event->button() == Qt::LeftButton && isInResizeArea(event->pos()))
        {
            m_isResizing = true;
        }
        else if (event->button() == Qt::LeftButton && isInRotateArea(event->pos()))
        {
            m_isRotating = true;
        }
        else
        {
            QGraphicsItem::mousePressEvent(event);
        }
    }
}

void HGraphicsEllipseItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->button() == Qt::LeftButton && m_isResizing)
    {
        m_isResizing = false;
    }
    else if (event->button() == Qt::LeftButton && m_isRotating)
    {
        m_isRotating = false;
    }
    else
    {
        QGraphicsItem::mouseReleaseEvent(event);
    }
}
#endif




#ifdef OPEN_EDIT_MODE

void HGraphicsEllipseItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
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

HGraphicsEllipseItem *HGraphicsEllipseItem::createNew(QRectF &rectf)
{
    HGraphicsEllipseItem * item = new HGraphicsEllipseItem(rectf);
    item->setPen(pen);
    item->setBrush(brush);
    return item;
}

void HGraphicsEllipseItem::resetScaleItem(){
    setScale(1);
}

void HGraphicsEllipseItem::duplicateSelectedItems(QGraphicsScene *scene)
{
    if (!scene)
        return;

    QList<QGraphicsItem *> selected;
    selected = scene->selectedItems();

    foreach (QGraphicsItem *item, selected)
    {
        HGraphicsEllipseItem *ellipseItem = qgraphicsitem_cast<HGraphicsEllipseItem *>(item);

        if (ellipseItem)
        {
            QRectF rect = item->boundingRect();
            QGraphicsEllipseItem * item2 = createNew(rect);
            item2->setPos(this->pos().rx()+50,this->pos().ry());

            scene->addItem(item2);
        }

    }
}

void HGraphicsEllipseItem::deleteSelectedItems(QGraphicsScene *scene)
{
    if (!scene)
        return;

    QList<QGraphicsItem *> selected;
    selected = scene->selectedItems();

    foreach (QGraphicsItem *item, selected)
    {
        QGraphicsRectItem *HGraphicsEllipseItem = static_cast<QGraphicsRectItem *>(item);
        if (HGraphicsEllipseItem)
            delete HGraphicsEllipseItem;
    }
}


void HGraphicsEllipseItem::wheelEvent(QGraphicsSceneWheelEvent *event)
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

