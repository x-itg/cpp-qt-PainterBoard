#ifndef HGRAPHICSVIEW_H
#define HGRAPHICSVIEW_H

#include "define_global.h"

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsView>


class HGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit HGraphicsView(QWidget *parent = nullptr);
    explicit HGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);


    /************************************************************/
public:

    virtual QVariant
    inputMethodQuery(Qt::InputMethodQuery query) const override;

    virtual QSize
    sizeHint() const override;

public:

private:

signals:
    void signal_send_view_pos(const QPointF pos);

protected:

    virtual void
    mouseMoveEvent(QMouseEvent *event) override;

    virtual void
    mousePressEvent(QMouseEvent *event) override;

    virtual void
    mouseReleaseEvent(QMouseEvent *event) override;

    virtual void
    contextMenuEvent(QContextMenuEvent *event) override;

    virtual void
    dragEnterEvent(QDragEnterEvent *event) override;

    virtual void
    dragLeaveEvent(QDragLeaveEvent *event) override;

    virtual void
    dragMoveEvent(QDragMoveEvent *event) override;

    virtual void
    dropEvent(QDropEvent *event) override;

    virtual void
    focusInEvent(QFocusEvent *event) override;

    virtual bool
    focusNextPrevChild(bool next) override;

    virtual void
    focusOutEvent(QFocusEvent *event) override;

    virtual void
    inputMethodEvent(QInputMethodEvent *event) override;

    virtual void
    keyPressEvent(QKeyEvent *event) override;

    virtual void
    keyReleaseEvent(QKeyEvent *event) override;

    virtual void
    mouseDoubleClickEvent(QMouseEvent *event) override;

    virtual void
    paintEvent(QPaintEvent *event) override;

    virtual void
    resizeEvent(QResizeEvent *event) override;

    virtual void
    scrollContentsBy(int dx, int dy) override;

    virtual void
    showEvent(QShowEvent *event) override;

    virtual bool
    viewportEvent(QEvent *event) override;

    virtual void
    wheelEvent(QWheelEvent *event) override;

    virtual bool
    event(QEvent *event) override;
};

#endif // HGRAPHICSVIEW_H
