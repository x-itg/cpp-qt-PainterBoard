#include "HGraphicsView.h"


/*****************************************/

/*******************************/


HGraphicsView::HGraphicsView(QWidget *parent):
    QGraphicsView(parent)
{
}

HGraphicsView::HGraphicsView(QGraphicsScene *scene, QWidget *parent):
    QGraphicsView(scene, parent)
{
}


QVariant HGraphicsView::inputMethodQuery(Qt::InputMethodQuery query) const
{
    //    DBG;
    return QGraphicsView::inputMethodQuery(query);
}

QSize HGraphicsView::sizeHint() const
{
//        DBG;
    return QGraphicsView::sizeHint();
}

void HGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
//        DBG;
    emit(signal_send_view_pos(event->pos()));

//    emit(signal_send_view_pos(mapToScene(event->pos())));

    QGraphicsView::mouseMoveEvent(event);
}

void HGraphicsView::mousePressEvent(QMouseEvent *event)
{
//        DBG << "=============";
    QGraphicsView::mousePressEvent(event);
}

void HGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
//        DBG;
    QGraphicsView::mouseReleaseEvent(event);
}

void HGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    //    DBG;
    QGraphicsView::contextMenuEvent(event);
}

void HGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    //    DBG;
    QGraphicsView::dragEnterEvent(event);
}

void HGraphicsView::dragLeaveEvent(QDragLeaveEvent *event)
{
    //    DBG;
    QGraphicsView::dragLeaveEvent(event);
}

void HGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    //    DBG;
    QGraphicsView::dragMoveEvent(event);
}

void HGraphicsView::dropEvent(QDropEvent *event)
{
    //    DBG;
    QGraphicsView::dropEvent(event);
}

void HGraphicsView::focusInEvent(QFocusEvent *event)
{
    //    DBG;
    QGraphicsView::focusInEvent(event);
}

bool HGraphicsView::focusNextPrevChild(bool next)
{
    //    DBG;
    return QGraphicsView::focusNextPrevChild(next);
}

void HGraphicsView::focusOutEvent(QFocusEvent *event)
{
    //    DBG;
    QGraphicsView::focusOutEvent(event);
}

void HGraphicsView::inputMethodEvent(QInputMethodEvent *event)
{
    //    DBG;
    QGraphicsView::inputMethodEvent(event);
}

void HGraphicsView::keyPressEvent(QKeyEvent *event)
{
    //    DBG;
    {
    }

    {
        QGraphicsView::keyPressEvent(event);
    }

}

void HGraphicsView::keyReleaseEvent(QKeyEvent *event)
{
    //    DBG;
    QGraphicsView::keyReleaseEvent(event);
}

void HGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
    //    DBG;
    QGraphicsView::mouseDoubleClickEvent(event);
}

void HGraphicsView::paintEvent(QPaintEvent *event)
{
    //    DBG;
    QGraphicsView::paintEvent(event);
}

void HGraphicsView::resizeEvent(QResizeEvent *event)
{
    //    DBG;
    QGraphicsView::resizeEvent(event);
}

void HGraphicsView::scrollContentsBy(int dx, int dy)
{
    //    DBG;
    QGraphicsView::scrollContentsBy(dx, dy);
}

void HGraphicsView::showEvent(QShowEvent *event)
{
    //    DBG;
    QGraphicsView::showEvent(event);
}

bool HGraphicsView::viewportEvent(QEvent *event)
{
    //    DBG;
    return QGraphicsView::viewportEvent(event);
}

void HGraphicsView::wheelEvent(QWheelEvent *event)
{
    //    DBG;
    {
    }

    {
        QGraphicsView::wheelEvent(event);
    }

}

bool HGraphicsView::event(QEvent *event)
{
    //    DBG << event->type();
    return  QGraphicsView::event(event);
}

