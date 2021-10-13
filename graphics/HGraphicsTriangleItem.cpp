#include "HGraphicsTriangleItem.h"

#ifdef OPEN_EDIT_MODE
bool HGraphicsTriangleItem::isInResizeArea(const QPointF &pos)
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

bool HGraphicsTriangleItem::isInRotateArea(const QPointF &pos)
{
    int height = static_cast<int>(boundingRect().height()/2);

    QRectF rectf = QRectF(-10, -height, 20 , -height+20);
    if(rectf.contains(pos))
    {
        return true;
    }
    else {
        return false;
    }
}
#endif

/***************************************************/

HGraphicsTriangleItem::HGraphicsTriangleItem(QGraphicsItem *parent):
    QGraphicsRectItem (parent)
{

    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsTriangleItem::HGraphicsTriangleItem(QRectF &rect, QGraphicsItem *parent):
    QGraphicsRectItem (rect, parent)
{

    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsTriangleItem::HGraphicsTriangleItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):
    QGraphicsRectItem (x, y, w, h, parent)
{

    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsTriangleItem::~HGraphicsTriangleItem()
{

}

void HGraphicsTriangleItem::setPen(QPen pen)
{
    this->pen = pen;
}

void HGraphicsTriangleItem::setBrush(QBrush brush)
{
    this->brush = brush;
}

void HGraphicsTriangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    {//三角
        painter->save();
        painter->setPen(pen);
        painter->setBrush(brush);
        QVector<QPointF> points;
        QPointF top(boundingRect().x() + boundingRect().width()/2, boundingRect().y());
        QPointF left(boundingRect().x(), boundingRect().y()+boundingRect().height());
        QPointF right(boundingRect().x()+boundingRect().width(), boundingRect().y()+boundingRect().height());
        points.append(top);
        points.append(left);
        points.append(right);
        painter->drawPolygon(QPolygonF(points));
        painter->restore();
    }

    {//矩形选择框 dotline rect boundingRect()
        if(isSelected()){
            painter->save();
            QPen pen;
            pen.setWidth(1);
            pen.setStyle(Qt::PenStyle::DashLine);
            painter->setPen(pen);
            painter->drawRect(QRectF(this->boundingRect()));
            painter->restore();
        }
    }
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


#ifdef OPEN_EDIT_MODE

void HGraphicsTriangleItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
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

HGraphicsTriangleItem *HGraphicsTriangleItem::createNew(QRectF &rectf)
{
    HGraphicsTriangleItem * item = new HGraphicsTriangleItem(rectf);
    item->setPen(pen);
    item->setBrush(brush);
    return item;
}

void HGraphicsTriangleItem::resetScaleItem(){
    setScale(1);
}

void HGraphicsTriangleItem::duplicateSelectedItems(QGraphicsScene *scene)
{
    if (!scene)
        return;

    QList<QGraphicsItem *> selected;
    selected = scene->selectedItems();

    foreach (QGraphicsItem *item, selected)
    {
        QGraphicsRectItem *HGraphicsTriangleItem = qgraphicsitem_cast<QGraphicsRectItem *>(item);

        if (HGraphicsTriangleItem)
        {
            QRectF rect = item->boundingRect();
            QGraphicsRectItem * item2 = createNew(rect);
            item2->setPos(this->pos().rx()+50,this->pos().ry());

            scene->addItem(item2);
        }

    }
}

void HGraphicsTriangleItem::deleteSelectedItems(QGraphicsScene *scene)
{
    if (!scene)
        return;

    QList<QGraphicsItem *> selected;
    selected = scene->selectedItems();

    foreach (QGraphicsItem *item, selected)
    {
        QGraphicsRectItem *HGraphicsTriangleItem = static_cast<QGraphicsRectItem *>(item);
        if (HGraphicsTriangleItem)
            delete HGraphicsTriangleItem;
    }
}


void HGraphicsTriangleItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    //    DBG;

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

    QGraphicsRectItem::hoverMoveEvent(event);
}


void HGraphicsTriangleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    DBG;
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

void HGraphicsTriangleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void HGraphicsTriangleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
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
        QGraphicsRectItem::mouseReleaseEvent(event);
    }
}

void HGraphicsTriangleItem::wheelEvent(QGraphicsSceneWheelEvent *event)
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
