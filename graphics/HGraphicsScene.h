#ifndef HGRAPHICSSCENE_H
#define HGRAPHICSSCENE_H

#include "define_global.h"

#include <QGraphicsItemGroup>
#include <QGraphicsItem>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPathItem>
#include <QGraphicsEllipseItem>

#include "HGraphicsPolygonItem.h"   //多边形
#include "HGraphicsEllipseItem.h"   //椭圆
#include "HGraphicsLineItem.h"      //直线
#include "HGraphicsRectItem.h"      //矩形
#include "HGraphicsTriangleItem.h"  //三角形
#include "HGraphicsPixmapItem.h"    //图片
#include "HGraphicsPathItem.h"      //线条？
#include "HGraphicsBezierItem.h"    //Bezier
#include "HGraphicsBlineItem.h"     //B样条
//缺了 Bline
//缺了 Bezier

//命令模式
#include "ICommand.h"
#include "Invoker.h"

//Qt命令模式
#include "commands.h"

/**算法 **/
#include "BezierAlgorithmManager.h"

class HGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum shapeType
    {
        handlePenType,  //手笔
        straightType,   //直线
        triangleType,   //三角形
        rectType,       //正方形
        ellipseType,    //圆形
        poligenType,    //多边形
        bezierType,     //贝塞尔
        bLineType,      //B样条
        text,           //文字
        pixmap,         //图片
    };

    enum sceneState
    {
        NoneState,
        DrawType,
        MoveType,
    };

private:
    bool isEditing;     //false 表示编辑结束, true 正在编辑
    bool isDrawing;      //false表示结束画图，true表示正在画图

    QPointF movePoint;
    QPointF origPoint;

private:
    /**
     * @brief 历史命令序列
     */
    Invoker invo;

    /********* 自定义撤销重做 *************/
public:
    QUndoStack *undoStack;
    QUndoView *undoView;
    /********* end *************/

    /********* 自定义撤销重做 *************/
public:
    bool redo();//撤销
    bool undo();//重做

public:
    QStack<QGraphicsItem *> m_redoStack;//重做栈
    /********* end *************/

private:
    QVector<QPointF> points;    //绘制的图形对应的坐标   poligenType、
    QVector<QGraphicsItem*> m_shapes;


public:
    QColor brushColor;   //填充颜色
    QPen pen;
    int frontZ = 0;

public:
    HGraphicsPolygonItem * m_pPolygonItem;//多边
    HGraphicsEllipseItem * m_pEllipseItem;//圆形
    HGraphicsLineItem * m_pLineItem;//直线
    HGraphicsTriangleItem * m_pTriangleItem;//三角形 实验中!!!!!!!!!!!!!!
    HGraphicsRectItem * m_pRectItem;//矩形
    HGraphicsPixmapItem * m_pPixmapItem;//图片
    HGraphicsPathItem * m_pPathItem; QPainterPath *m_path;//手绘
    HGraphicsBezierItem * m_pBezierItem;//贝塞尔
    HGraphicsBlineItem * m_pBlineItem;//B样条

private:
    sceneState m_curState = sceneState::DrawType;//操作类型
    shapeType m_curShape = shapeType::handlePenType;//形状

public:
    /**
     * @brief 获取操作类型
     */
    shapeType & getShapeType();
    void setShapeType(shapeType type);

    sceneState & getSceneState();
    void setSceneState(sceneState type);

public:
    HGraphicsScene(QWidget *parent = nullptr);
    HGraphicsScene(const QRectF &sceneRect, QObject *parent = nullptr);
    HGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);

signals:
    void signal_send_pos(const QPointF item_src_pos, const QPointF scene_pos, const QPointF item_pos);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;   //鼠标按下事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *)  override;   //鼠标移动事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;   //鼠标释放事件

    void mousePressDraw(QGraphicsSceneMouseEvent *);
    void mousePressMove(QGraphicsSceneMouseEvent *);
    void mousePressEdit(QGraphicsSceneMouseEvent *);

    void mouseMoveDraw(QGraphicsSceneMouseEvent *);
    void mouseMoveMove(QGraphicsSceneMouseEvent *);
    void mouseMoveEdit(QGraphicsSceneMouseEvent *);

    void mouseReleaseDraw(QGraphicsSceneMouseEvent *);
    void mouseReleaseMove(QGraphicsSceneMouseEvent *);
    void mouseReleaseEdit(QGraphicsSceneMouseEvent *);


    //    virtual void
    //    contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent) override;

    //    virtual void
    //    dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;

    //    virtual void
    //    dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;

    //    virtual void
    //    dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;

    //    virtual void
    //    drawBackground(QPainter *painter, const QRectF &rect) override;

    //    virtual void
    //    drawForeground(QPainter *painter, const QRectF &rect) override;

    //    virtual void
    //    dropEvent(QGraphicsSceneDragDropEvent *event) override;

    //    virtual void
    //    focusInEvent(QFocusEvent *focusEvent) override;

    //    virtual void
    //    focusOutEvent(QFocusEvent *focusEvent) override;

    //    virtual void
    //    helpEvent(QGraphicsSceneHelpEvent *helpEvent) override;

    //    virtual void
    //    inputMethodEvent(QInputMethodEvent *event) override;

    virtual void
    keyPressEvent(QKeyEvent *keyEvent) override;

    //    virtual void
    //    keyReleaseEvent(QKeyEvent *keyEvent) override;

    //    virtual void
    //    mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

    //    virtual void
    //    wheelEvent(QGraphicsSceneWheelEvent *wheelEvent) override;

    //    /************ Reimplemented Protected Functions ************/

    //    virtual bool
    //    event(QEvent *event) override;

    //    virtual bool
    //    eventFilter(QObject *watched, QEvent *event) override;

    /***********************************************************/

    void showShape(QVector<QGraphicsItem*> m_shapes);
};

#endif // HGRAPHICSSCENE_H
