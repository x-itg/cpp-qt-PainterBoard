#include "HGraphicsRectItem.h"

#ifdef OPEN_EDIT_MODE
bool HGraphicsRectItem::isInResizeArea(const QPointF &pos)
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

bool HGraphicsRectItem::isInRotateArea(const QPointF &pos)
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
#endif


/*******************************/


HGraphicsRectItem::HGraphicsRectItem(QGraphicsItem *parent):
    QGraphicsRectItem (parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);


}

HGraphicsRectItem::HGraphicsRectItem(const QRectF &rect, QGraphicsItem *parent):
    QGraphicsRectItem (rect, parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsRectItem::HGraphicsRectItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent):
    QGraphicsRectItem (x, y, w, h, parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

HGraphicsRectItem::~HGraphicsRectItem()
{
}

QRectF HGraphicsRectItem::boundingRect() const
{
    //    DBG;
    //    {
    //        qreal adjust = 0.5;
    //        return QRectF(-10 - adjust, -10 - adjust,
    //                      2 + adjust, 2 + adjust);
    //    }

    {
        return QGraphicsRectItem::boundingRect();
    }

}

bool HGraphicsRectItem::contains(const QPointF &point) const
{
    DBG;
    return QGraphicsRectItem::contains(point);
}

bool HGraphicsRectItem::isObscuredBy(const QGraphicsItem *item) const
{
    DBG;
    return QGraphicsRectItem::isObscuredBy(item);
}

QPainterPath HGraphicsRectItem::opaqueArea() const
{
    DBG;
    return QGraphicsRectItem::opaqueArea();
}


void HGraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsRectItem::paint(painter,option,widget);

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
        qDebug() << boundingRect();
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


QPainterPath HGraphicsRectItem::shape() const
{
    //    DBG;
    return QGraphicsRectItem::shape();
}

int HGraphicsRectItem::type() const
{
    //    DBG;
    return QGraphicsRectItem::type();
}

/***************************************************/

void HGraphicsRectItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    DBG;
    {
        //        QMenu menu;
        //        QAction *moveAction = menu.addAction("move back");
        //        QAction *selectedAction = menu.exec(event->screenPos());
        //        if (selectedAction == moveAction) {
        //            setPos(0, 0);
        //        }
    }

    {
        QGraphicsRectItem::contextMenuEvent(event);
    }

}

void HGraphicsRectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    DBG;
    QGraphicsRectItem::dragEnterEvent(event);
}

void HGraphicsRectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    DBG;
    QGraphicsRectItem::dragLeaveEvent(event);
}

void HGraphicsRectItem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    DBG;
    QGraphicsRectItem::dragMoveEvent(event);
}

void HGraphicsRectItem::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    DBG;
    QGraphicsRectItem::dropEvent(event);
}

void HGraphicsRectItem::focusInEvent(QFocusEvent *event)
{
    DBG;
    QGraphicsRectItem::focusInEvent(event);
}

void HGraphicsRectItem::focusOutEvent(QFocusEvent *event)
{
    DBG;
    QGraphicsRectItem::focusOutEvent(event);
}

void HGraphicsRectItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //    DBG;

    {
        setCursor(Qt::OpenHandCursor); //设置光标为手张开的形状
        setToolTip("矩形");
    }

    {
        QGraphicsRectItem::hoverEnterEvent(event);
    }

}

void HGraphicsRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //    DBG;
    QGraphicsRectItem::hoverLeaveEvent(event);
}
#ifdef OPEN_EDIT_MODE
void HGraphicsRectItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    //    DBG;

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
    QGraphicsRectItem::hoverMoveEvent(event);
}
#endif

void HGraphicsRectItem::inputMethodEvent(QInputMethodEvent *event)
{
    DBG;
    QGraphicsRectItem::inputMethodEvent(event);
}

QVariant HGraphicsRectItem::inputMethodQuery(Qt::InputMethodQuery query) const
{
    DBG;
    return QGraphicsRectItem::inputMethodQuery(query);
}

QVariant HGraphicsRectItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    //    DBG;
    return QGraphicsRectItem::itemChange(change, value);
}

void HGraphicsRectItem::keyPressEvent(QKeyEvent *event)
{
    DBG;
    QGraphicsRectItem::keyPressEvent(event);

}

void HGraphicsRectItem::keyReleaseEvent(QKeyEvent *event)
{
    DBG;
    QGraphicsRectItem::keyReleaseEvent(event);
}

void HGraphicsRectItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    DBG;
    QGraphicsRectItem::mouseDoubleClickEvent(event);
}


#ifdef OPEN_EDIT_MODE
void HGraphicsRectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void HGraphicsRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    DBG;

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

void HGraphicsRectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    DBG;

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
#endif

void HGraphicsRectItem::prepareGeometryChange()
{
    //    DBG;
    QGraphicsRectItem::prepareGeometryChange();
}

bool HGraphicsRectItem::sceneEvent(QEvent *event)
{
    return QGraphicsRectItem::sceneEvent(event);
}

bool HGraphicsRectItem::sceneEventFilter(QGraphicsItem *watched, QEvent *event)
{
    //    DBG;
    return QGraphicsRectItem::sceneEventFilter(watched, event);
}

void HGraphicsRectItem::updateMicroFocus()
{
    //    DBG;
    QGraphicsRectItem::updateMicroFocus();
}

void HGraphicsRectItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    //    DBG;
    QGraphicsRectItem::wheelEvent(event);
}
