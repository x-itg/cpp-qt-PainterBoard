#include "HGraphicsPixmapObject.h"

const qreal g_cResizePos[] = {9, 6, 3};

HGraphicsPixmapObject::HGraphicsPixmapObject(QPixmap pixmap, QString title, QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);//图形项可发送位置变化信号
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    this->pixmap = pixmap;
    this->title = title;
    this->textColor = QColor(Qt::red);
    this->itemSize = pixmap.size();
    isResizing = false;
}

QRectF HGraphicsPixmapObject::boundingRect() const
{
//    QRectF rect = pixmap.rect();
//    rect.setHeight(rect.height() + 10);
//    return QRectF(rect);
    return  QRectF(0, 0, itemSize.width() + 10, itemSize.height() + 10);
}

//void HGraphicsPixmapObject::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
//{
//    QMenu menu;
////    menu.setStyleSheet(QString("QMenu{background-color:#FFFFFF; border:1px solid #%1;}"
////                               "QMenu::item{padding-right:15px;padding-top:5px;padding-bottom:5px;}"
////                               "QMenu::item:checked{border: 1px solid #%2;background: #F2F2F2;}"
////                               "QMenu::item:selected{color:#FFFFFF;background:#%1;}").arg(uiEditorColor::style_main_color).arg(uiEditorColor::style_hover_color));

//    QAction * setPixmapAction = menu.addAction(tr("设置图片"));
//    connect(setPixmapAction,&QAction::triggered,this,&HGraphicsPixmapObject::setNewPixmap);
//    menu.exec(event->screenPos());
//}

//void HGraphicsPixmapObject::setNewPixmap()
//{
//    QString filepath = QFileDialog::getOpenFileName(nullptr, tr("设置图片"), QString(), "*.png *.jpg");
//    if(filepath.isEmpty())
//    {
//        return;
//    }
//    QPixmap p;
//    p.load(filepath);
//    if(p.width() >= scene()->width() || p.height() >= scene()->height())
//    {
//        QMessageBox msg;
//        msg.setAutoFillBackground(true);
//        msg.setPalette(Qt::white);
//        msg.setParent(nullptr, Qt::Dialog|Qt::WindowCloseButtonHint);
//        msg.setText(tr("图片尺寸大于视图尺寸"));
//        QPushButton * btn = (msg.addButton(tr("Yes"),QMessageBox::AcceptRole));
//        btn->setCursor(Qt::PointingHandCursor);
////        btn->setStyleSheet(QString("QPushButton{color: #FFFFFF;padding:6px 10px 6px 10px;border-radius:6px;font-weight:bold;background: #%1;}"
////                                   "QPushButton:hover{background: #%2;}"
////                                   "QPushButton:pressed{background: #%3;}"
////                                   "QPushButton:disabled{background: #d8d8d8;}").arg(uiEditorColor::style_main_color)
////                                                                                .arg(uiEditorColor::style_hover_color)
////                                                                                .arg(uiEditorColor::style_press_color));
//        msg.exec();
//        return;
//    }
//    pixmap = p;
//    update();
//}

void HGraphicsPixmapObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    if(event->button() == Qt::LeftButton)
//    {
//        if(IsInResizeArea(event->pos()))
//            isResizing = true;

//        QGraphicsObject::mousePressEvent(event);
//        emit sendItemInfo(this->title);
//        emit sendItemInfo(this->textColor);
//        return;
//    }
//    else if(event->button() == Qt::RightButton)
//    {
//        return;
//    }
    return QGraphicsObject::mousePressEvent(event);
}

void HGraphicsPixmapObject::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
//    if (event->button() == Qt::LeftButton && isResizing)
//        isResizing = false;
//    else
        QGraphicsObject::mouseReleaseEvent(event);
}

//void HGraphicsPixmapObject::setTitle(QString string)
//{
//    this->title = string;
//    update();
//}

//void HGraphicsPixmapObject::setTextColor(QColor color)
//{
//    this->textColor = color;
//    update();
//}

//QVariant HGraphicsPixmapObject::itemChange(GraphicsItemChange change, const QVariant &value)
//{
//    if ((change == ItemPositionChange || change == ItemPositionHasChanged) && scene()) // 控件发生移动
//    {
//        QPointF newPos = value.toPointF();
//        QRectF rect(0, 0, scene()->width(), scene()->height());
//        if (!rect.contains(newPos))//左上角
//        {
//            newPos.setX(qMin(rect.width(), qMax(newPos.x(), 0.0)));
//            newPos.setY(qMin(rect.height(), qMax(newPos.y(), 0.0)));

////            newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
////            newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
//            return newPos;
//        }

//        QRectF thisRectF = boundingRect();
//        QPointF nowPos = QPointF(newPos.x() + thisRectF.width(),newPos.y());
//        if(!rect.contains(nowPos))//右上角
//        {
//            newPos.setX(rect.width() - thisRectF.width());
//            this->setPos(newPos);
//            return newPos;
//        }

//        nowPos = QPointF(newPos.x(),newPos.y() + thisRectF.height());
//        if(!rect.contains(nowPos))//左下角
//        {
//            newPos.setY(rect.height() - thisRectF.height());
//            this->setPos(newPos);
//            return newPos;
//        }
//    }
//    return QGraphicsItem::itemChange(change, value);
//}

void HGraphicsPixmapObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);

    QRectF thisRectF = boundingRect();

    {//画边框
//        if(option->state & QStyle::State_Selected)
//        {
//            painter->setPen(QColor("#D8D8D8"));
//            painter->drawRect(thisRectF);
//            setZValue(2);
//        }
//        else
//        {
//            setZValue(1);
//            painter->fillRect(thisRectF, QBrush(Qt::transparent));
//        }
    }


    {//画图
        if(!pixmap.isNull())
        {
            QRect rect = thisRectF.toRect();
            painter->drawPixmap(rect, pixmap);//绘制图片
        }
    }


    {//画字
//        if(!title.isEmpty())
//        {
//            QRectF textRect;
//            textRect.setRect(0, 0, thisRectF.width(), 30);

//            textRect.moveTo(QPoint(0,static_cast<int>((thisRectF.height() - 30)/2)));
//            QPen p(Qt::SolidLine);
//            p.setColor(textColor);
//            p.setWidth(2);
//            painter->setPen(p);
//            QFont font = painter->font();
//            font.setPixelSize(24);
//            painter->setFont(font);
//            painter->drawText(textRect, Qt::AlignCenter|Qt::AlignVCenter, title);//绘制文字
//        }
    }


    {
        //    if(option->state & QStyle::State_Selected)
        //    {
        //        qreal w = thisRectF.width();
        //        qreal h = thisRectF.height();
        //        painter->setPen(Qt::red);
        //        for (int i = 0; i < 3; ++i)//三角形
        //            painter->drawLine(static_cast<int>(w - g_cResizePos[i]) , static_cast<int>(h), static_cast<int>(w), static_cast<int>(h - g_cResizePos[i]));
        //    }
    }


    painter->restore();
}

//void HGraphicsPixmapObject::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
//{
//    if (isResizing || (IsInResizeArea(event->pos()) && isSelected()))
//        setCursor(Qt::SizeFDiagCursor);
//    else
//        setCursor(Qt::ArrowCursor);

//    QGraphicsObject::hoverMoveEvent(event);
//}

void HGraphicsPixmapObject::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    if (isResizing)
    {
//        qreal w = event->pos().x();
//        qreal h = event->pos().y();
//        if (w > 0)
//            itemSize.setWidth(w);
//        if (h > 0)
//            itemSize.setHeight(h);
//        prepareGeometryChange();
    }
    else
    {
        QGraphicsObject::mouseMoveEvent(event);
    }
}

//bool HGraphicsPixmapObject::IsInResizeArea(const QPointF& pos)
//{
//    return (pos.x() - itemSize.width() + g_cResizePos[0]) > (itemSize.height() - pos.y());
//}

