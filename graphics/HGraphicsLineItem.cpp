#include "HGraphicsLineItem.h"


#ifdef OPEN_EDIT_MODE
bool HGraphicsLineItem::isInResizeArea(const QPointF &pos)
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

bool HGraphicsLineItem::isInRotateArea(const QPointF &pos)
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

HGraphicsLineItem::HGraphicsLineItem(QGraphicsItem *parent):
    QGraphicsLineItem (parent)
{

}

HGraphicsLineItem::HGraphicsLineItem(const QLineF &line, QGraphicsItem *parent):
    QGraphicsLineItem (line, parent)
{
}

HGraphicsLineItem::HGraphicsLineItem(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem *parent):
    QGraphicsLineItem (x1, y1, x2, y2, parent)
{
}


void HGraphicsLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsLineItem::paint(painter,option,widget);

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
        painter->drawRect(boundingRect());
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
void HGraphicsLineItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
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

    QGraphicsItem::hoverMoveEvent(event);
}


void HGraphicsLineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    DBG;
    if (m_isResizing)
    {
        {
//            int dx = int(2.0 * event->pos().x());
//            int dy = int(2.0 * event->pos().y());

//            prepareGeometryChange();
//            boundingRect();
//            QRect rect = QRect(-dx/2, -dy/2, dx, dy);
//            this->setRect(rect);
        }

        {
            int dx = int(2.0 * event->pos().x());
            int dy = int(2.0 * event->pos().y());

            QRectF srcRect = boundingRect();
            QRect rect = QRect(-dx/2, -dy/2, dx, dy);

            qreal wScale = rect.width()/srcRect.width();
            qreal hScale = rect.height()/srcRect.height();

            QPointF p1 = line().p1();
            QPointF p2 = line().p2();

            qreal w = line().p2().rx() - line().p1().rx();
            qreal h = line().p2().ry() - line().p1().ry();
            qreal wAdd = w * (wScale - 1);
            qreal hAdd = h * (hScale - 1);

            QPointF p11(p1.rx() - wAdd/2, p1.ry() - hAdd/2);
            QPointF p22(p2.rx() + wAdd/2, p2.ry() + hAdd/2);

            this->setLine(QLineF(p11,p22));
        }

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

void HGraphicsLineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void HGraphicsLineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
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
