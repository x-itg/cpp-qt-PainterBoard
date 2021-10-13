#include "HGraphicsScene.h"



HGraphicsScene::HGraphicsScene(QWidget *parent):
    QGraphicsScene(parent),
    m_pPolygonItem(nullptr),
    m_pEllipseItem(nullptr),
    m_pLineItem(nullptr),
    m_pTriangleItem(nullptr),
    m_pRectItem(nullptr),
    m_pPixmapItem(nullptr),
    m_pPathItem(nullptr),m_path(nullptr),
    m_pBezierItem(nullptr),
    m_pBlineItem(nullptr)
{
    //撤销重做栈和ListView视图
    undoStack = new QUndoStack(this);
    undoView = new QUndoView(undoStack);
    undoView->setWindowTitle(tr("Command List"));
    undoView->setAttribute(Qt::WA_QuitOnClose, false);

    //
    m_curShape = this->handlePenType;
    m_curState=this->DrawType;
    isDrawing=false;
    isEditing=false;
    pen.setWidth(1);
    pen.setColor(Qt::black);
    brushColor = Qt::yellow;
}

HGraphicsScene::HGraphicsScene(const QRectF &sceneRect, QObject *parent):
    QGraphicsScene(sceneRect, parent),
    m_pPolygonItem(nullptr),
    m_pEllipseItem(nullptr),
    m_pLineItem(nullptr),
    m_pTriangleItem(nullptr),
    m_pRectItem(nullptr),
    m_pPixmapItem(nullptr),
    m_pPathItem(nullptr),m_path(nullptr),
    m_pBezierItem(nullptr),
    m_pBlineItem(nullptr)
{
    //撤销重做栈和ListView视图
    undoStack = new QUndoStack(this);
    undoView = new QUndoView(undoStack);
    undoView->setWindowTitle(tr("Command List"));
    undoView->setAttribute(Qt::WA_QuitOnClose, false);

    m_curShape = this->handlePenType;
    m_curState=this->DrawType;
    isDrawing=false;
    isEditing=false;
    pen.setWidth(1);
    pen.setColor(Qt::black);
    brushColor = Qt::yellow;
}

HGraphicsScene::HGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent):
    QGraphicsScene(x, y, width, height, parent),
    m_pPolygonItem(nullptr),
    m_pEllipseItem(nullptr),
    m_pLineItem(nullptr),
    m_pTriangleItem(nullptr),
    m_pRectItem(nullptr),
    m_pPixmapItem(nullptr),
    m_pPathItem(nullptr),m_path(nullptr),
    m_pBezierItem(nullptr),
    m_pBlineItem(nullptr)
{
    //撤销重做栈和ListView视图
    undoStack = new QUndoStack(this);
    undoView = new QUndoView(undoStack);
    undoView->setWindowTitle(tr("Command List"));
    undoView->setAttribute(Qt::WA_QuitOnClose, false);

    //
    m_curShape = this->handlePenType;
    m_curState=this->DrawType;
    isDrawing=false;
    isEditing=false;
    pen.setWidth(1);
    pen.setColor(Qt::black);
    brushColor = Qt::yellow;
}

bool HGraphicsScene::redo()
{
    this->invo;
}

bool HGraphicsScene::undo()
{

}

HGraphicsScene::shapeType &HGraphicsScene::getShapeType()
{
    return this->m_curShape;
}

void HGraphicsScene::setShapeType(HGraphicsScene::shapeType type)
{
    this->m_curShape = type;
}

HGraphicsScene::sceneState &HGraphicsScene::getSceneState()
{
    return this->m_curState;
}

void HGraphicsScene::setSceneState(HGraphicsScene::sceneState type)
{
    this->m_curState = type;
}

void HGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(m_curState==DrawType)
    {
        mousePressDraw(event);
    }
    else if(m_curState==MoveType)
    {
#if 0
        mousePressMove(event);
#else
        QGraphicsScene::mousePressEvent(event);
#endif
    }

}

void HGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    //    DBG;

    if(m_curState==DrawType)
    {
        mouseMoveDraw(event);
    }
    else if(m_curState==MoveType)
    {
#if 0
        mouseMoveMove(event);
#else
        QGraphicsScene::mouseMoveEvent(event);
        if(selectedItems().length())
            emit(signal_send_pos(event->pos(), event->scenePos(), selectedItems().at(0)->pos()));
#endif
    }

}

void HGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e )
{
    if(m_curState==DrawType)
    {
        mouseReleaseDraw(e);
    }
    else if(m_curState==MoveType)
    {
#if 0
        mouseReleaseMove(e);
#else
        QGraphicsScene::mouseReleaseEvent(e);
#endif
    }

}


void HGraphicsScene::mousePressDraw(QGraphicsSceneMouseEvent *event)
{
    //    DBG;
    {
        switch (this->m_curShape) {
        case shapeType::handlePenType:{
            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                if(m_pPathItem == nullptr && m_path == nullptr)
                {
                    m_path = new QPainterPath(event->scenePos());
                    m_pPathItem = new HGraphicsPathItem(*m_path);
                    m_pPathItem->setPen(pen);
                    addItem(m_pPathItem);
                    AddCommand * addCommand = new AddCommand("笔画", m_pPathItem, this);
                    undoStack->push(addCommand);
                }

                isDrawing = true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {

            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {

            }
        }break;
        case shapeType::straightType:{
            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                if(origPoint.isNull()){
                    origPoint = event->scenePos();
                }
                if(m_pLineItem == nullptr){
                    m_pLineItem = new HGraphicsLineItem;
                    m_pLineItem->setPen(pen);
                    addItem(m_pLineItem);
                    AddCommand * addCommand = new AddCommand("直线", m_pLineItem, this);
                    undoStack->push(addCommand);
                }
                isDrawing=true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {

            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
            }
        }break;
        case shapeType::triangleType:{
            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                if(origPoint.isNull()){
                    origPoint = event->scenePos();
                }
                if(m_pTriangleItem == nullptr){
                    m_pTriangleItem = new HGraphicsTriangleItem;
                    m_pTriangleItem->setPen(pen);
                    m_pTriangleItem->setBrush(brushColor);
                    addItem(m_pTriangleItem);
                    AddCommand * addCommand = new AddCommand("三角", m_pTriangleItem, this);
                    undoStack->push(addCommand);
                }
                isDrawing=true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {

            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
            }
        }break;
        case shapeType::rectType:{
            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                if(origPoint.isNull()){
                    origPoint = event->scenePos();
                }
                if(m_pRectItem == nullptr){
                    m_pRectItem = new HGraphicsRectItem;
                    m_pRectItem->setPen(pen);
                    m_pRectItem->setBrush(brushColor);
                    addItem(m_pRectItem);
                    AddCommand * addCommand = new AddCommand("矩形", m_pRectItem, this);
                    undoStack->push(addCommand);
                }
                isDrawing=true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
            }
        }break;
        case shapeType::ellipseType:{
            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                if(origPoint.isNull()){
                    origPoint = event->scenePos();
                }
                if(m_pEllipseItem == nullptr){
                    m_pEllipseItem = new HGraphicsEllipseItem;
                    m_pEllipseItem->setPen(pen);
                    m_pEllipseItem->setBrush(brushColor);
                    addItem(m_pEllipseItem);
                    AddCommand * addCommand = new AddCommand("圆形", m_pEllipseItem, this);
                    undoStack->push(addCommand);
                }
                isDrawing=true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {

            }
        }break;
        case shapeType::poligenType:{

            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                points.clear();
                points.append(event->scenePos());

                if(m_pPolygonItem == nullptr){
                    m_pPolygonItem = new HGraphicsPolygonItem;
                    m_pPolygonItem->setPen(pen);
                    m_pPolygonItem->setBrush(brushColor);
                    addItem(m_pPolygonItem);
                    AddCommand * addCommand = new AddCommand("多边形", m_pPolygonItem, this);
                    undoStack->push(addCommand);
                }

                isDrawing=true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {
                {
                    points.append(event->scenePos());
                    QPolygonF curPolygon(points);
                    m_pPolygonItem->setPolygon(curPolygon);
                }
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QPolygonF *curPolygon=new QPolygonF(points);
                m_pPolygonItem->setPolygon(*curPolygon);

                QRectF rect = m_pPolygonItem->boundingRect();
                m_pPolygonItem->setTransformOriginPoint(rect.x() + rect.width()/2, rect.y() + rect.height()/2);

                m_pPolygonItem->setFlag(QGraphicsItem::ItemIsMovable,true);
                m_pPolygonItem->setFlag(QGraphicsItem::ItemIsSelectable,true);
                m_shapes.append(m_pPolygonItem);

                //                showShape(m_shapes);//这里才是(一个)

                isDrawing=false;
                m_pPolygonItem = nullptr;
            }
        }break;
        case shapeType::bezierType:{
            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                points.clear();
                points.append(event->scenePos());

                if(m_pBezierItem == nullptr){
                    m_pBezierItem = new HGraphicsBezierItem;
                    m_pBezierItem->drawPointsEnable(true);
                    m_pBezierItem->setPen(pen);
                    addItem(m_pBezierItem);
                    AddCommand * addCommand = new AddCommand("贝塞尔", m_pBezierItem, this);
                    undoStack->push(addCommand);
                }

                isDrawing=true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {
                points.append(event->scenePos());
                QList<QPointF> fountainPoints = BezierAlgorithmManager::getInstance()->generateFountainPenList(points);
                QPainterPath path = BezierAlgorithmManager::getInstance()->pathFountainPenBezier(fountainPoints);
                m_pBezierItem->setPath(path, fountainPoints);
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QList<QPointF> fountainPoints = BezierAlgorithmManager::getInstance()->generateFountainPenList(points);
                QPainterPath path = BezierAlgorithmManager::getInstance()->pathFountainPenBezier(fountainPoints);
                m_pBezierItem->setPath(path, fountainPoints);
                m_pBezierItem->drawPointsEnable(false);

                QRectF rect = m_pBezierItem->boundingRect();
                m_pBezierItem->setTransformOriginPoint(rect.x() + rect.width()/2, rect.y() + rect.height()/2);

                m_pBezierItem->setFlag(QGraphicsItem::ItemIsMovable,true);
                m_pBezierItem->setFlag(QGraphicsItem::ItemIsSelectable,true);

                m_shapes.append(m_pBezierItem);
                //                showShape(m_shapes);//这里才是(一个)

                isDrawing=false;
                m_pBezierItem = nullptr;
            }
        }break;
        case shapeType::bLineType:{
            if(event->button()==Qt::LeftButton && !this->isDrawing) //如果之前没有开始画图，则单击开始画图
            {
                points.clear();
                points.append(event->scenePos());

                if(m_pBlineItem == nullptr){
                    m_pBlineItem = new HGraphicsBlineItem;
                    m_pBlineItem->drawPointsEnable(true);
                    m_pBlineItem->setPen(pen);
                    addItem(m_pBlineItem);
                    AddCommand * addCommand = new AddCommand("B样条", m_pBlineItem, this);
                    undoStack->push(addCommand);
                }

                isDrawing=true;
            }
            else if(event->button()==Qt::LeftButton && this->isDrawing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
            {
                {
                    points.append(event->scenePos());
                    QVector<QPointF> bLinePoints = BezierAlgorithmManager::getInstance()->generateTwiceBlineList(points);
                    QPainterPath path = BezierAlgorithmManager::getInstance()->pathBlineList(bLinePoints);
                    m_pBlineItem->setPath(path, bLinePoints);
                }
            }
            else if(event->button()==Qt::RightButton && this->isDrawing)
            {
                points.append(event->scenePos());
                QVector<QPointF> bLinePoints = BezierAlgorithmManager::getInstance()->generateTwiceBlineList(points);
                QPainterPath path = BezierAlgorithmManager::getInstance()->pathBlineList(bLinePoints);
                m_pBlineItem->setPath(path, bLinePoints);
                m_pBlineItem->drawPointsEnable(false);

                QRectF rect = m_pBlineItem->boundingRect();
                m_pBlineItem->setTransformOriginPoint(rect.x() + rect.width()/2, rect.y() + rect.height()/2);

                m_pBlineItem->setFlag(QGraphicsItem::ItemIsMovable,true);
                m_pBlineItem->setFlag(QGraphicsItem::ItemIsSelectable,true);

                m_shapes.append(m_pBlineItem);
                //                showShape(m_shapes);//这里才是(一个)

                isDrawing=false;
                m_pBlineItem = nullptr;
            }
        }break;
        }
    }
}

void HGraphicsScene::mousePressMove(QGraphicsSceneMouseEvent *event)
{
    DBG;
    this->views()[0]->setCursor(Qt::ClosedHandCursor);
    if(this->items().count()>0)
    {
        QGraphicsItem* curSelectItem = this->itemAt(event->scenePos(), this->items()[0]->transform());//获取点击图元
        if(curSelectItem != NULL)
        {
            this->clearSelection();
            origPoint=event->scenePos();//设置七点
            curSelectItem->setSelected(true);//设置选中(并显示选中虚线框框)
        }
    }
}

void HGraphicsScene::mousePressEdit(QGraphicsSceneMouseEvent *event)
{
    if((event->button()==Qt::LeftButton && !this->isEditing) || (event->button()==Qt::LeftButton && (event->modifiers() & Qt::ControlModifier))) //如果之前没有开始画图，则单击开始画图
    {
        if(hasFocus()){


            QGraphicsItem * item =  itemAt(event->scenePos(), items().at(0)->transform());
            if(item){
                item->setSelected(true);
            }

            isEditing=true;
        }


    }
    else if(event->button()==Qt::LeftButton && this->isEditing)//左键、正在绘图。 可以优化,这样 new 的太多,没必要,最好高在 图元内部,解耦
    {
    }
    else if(event->button()==Qt::RightButton && this->isEditing)
    {
        foreach(auto iter, items()){
            iter->setSelected(false);
        }
        isEditing = false;

    }
    else if(event->button()==Qt::MidButton){

        qDebug() << "MidButton";
        QList<QGraphicsItem *> items = selectedItems();

        static int i = 0;
        i+= 30;
        foreach(auto iter, items)
        {
            iter->setRotation(i);
        }

    }
}

void HGraphicsScene::mouseMoveDraw(QGraphicsSceneMouseEvent *event)
{
    //    DBG;

    this->views()[0]->setCursor(Qt::CrossCursor);

    if(isDrawing)
    {
        {
            switch (this->m_curShape) {
            case shapeType::handlePenType:{
                if(m_path && m_pPathItem){
                    m_path->lineTo(event->scenePos());
                    m_pPathItem->setPath(*m_path);
                }
            }break;
            case shapeType::straightType:{
                movePoint = event->scenePos();
                if(m_pLineItem)
                {
                    m_pLineItem->setLine(QLineF(origPoint, movePoint));
                }
            }break;
            case shapeType::triangleType:{
                movePoint = event->scenePos();
                QRectF rectf(origPoint, movePoint);
                if(m_pTriangleItem)
                {
                    qreal width = movePoint.rx()-origPoint.rx();
                    qreal height = movePoint.ry()-origPoint.ry();

                    m_pTriangleItem->setRect(-width/2, -height/2, width, height);
                    m_pTriangleItem->setPos(origPoint.rx()+width/2, origPoint.ry()+height/2);
                }
            }break;
            case shapeType::rectType:{
                movePoint = event->scenePos();
                QRectF rectf(origPoint, movePoint);
                if(m_pRectItem)
                {
                    qreal width = movePoint.rx()-origPoint.rx();
                    qreal height = movePoint.ry()-origPoint.ry();

                    m_pRectItem->setRect(-width/2, -height/2,  width, height);
                    m_pRectItem->setPos(origPoint.rx()+width/2, origPoint.ry()+height/2);
                }
            }break;
            case shapeType::ellipseType:{
                movePoint = event->scenePos();
                QRectF rectf(origPoint, movePoint);
                if(m_pEllipseItem)
                {
                    qreal width = movePoint.rx()-origPoint.rx();
                    qreal height = movePoint.ry()-origPoint.ry();

                    m_pEllipseItem->setRect(-width/2, -height/2, width, height);
                    m_pEllipseItem->setPos(origPoint.rx()+width/2, origPoint.ry()+height/2);
                }
            }break;
            case shapeType::poligenType:{
                QVector<QPointF> tempPoints = points;
                tempPoints.append(event->scenePos());
                QPolygonF *curPolygon=new QPolygonF(tempPoints);
                if(m_pPolygonItem){
                    m_pPolygonItem->setPolygon(*curPolygon);
                }
            }break;
            case shapeType::bezierType:{
                QVector<QPointF> tempPoints = points;
                tempPoints.append(event->scenePos());
                QList<QPointF> fountainPoints = BezierAlgorithmManager::getInstance()->generateFountainPenList(tempPoints);
                QPainterPath path = BezierAlgorithmManager::getInstance()->pathFountainPenBezier(fountainPoints);
                if(m_pBezierItem){
                    m_pBezierItem->setPath(path, fountainPoints);
                }
            }break;
            case shapeType::bLineType:{
                QVector<QPointF> tempPoints = points;
                tempPoints.append(event->scenePos());
                QVector<QPointF> bLinePoints = BezierAlgorithmManager::getInstance()->generateTwiceBlineList(tempPoints);
                QPainterPath path = BezierAlgorithmManager::getInstance()->pathBlineList(bLinePoints);
                if(m_pBlineItem){
                    m_pBlineItem->setPath(path, bLinePoints);
                }
            }break;
            }
        }
    }
}

void HGraphicsScene::mouseMoveMove(QGraphicsSceneMouseEvent *event)
{
    //    DBG;
    if(( event->buttons()&Qt::LeftButton)&& isDrawing==false && this->selectedItems().count()>0)
    {

        {
            DBG << "scene pos:" << event->scenePos() << event->pos() << selectedItems().at(0)->pos();
            emit(signal_send_pos(event->pos(), event->scenePos(), selectedItems().at(0)->pos()));
        }

        movePoint=event->scenePos();
        qreal dx=movePoint.x()-origPoint.x();//移动向量 微分dx
        qreal dy=movePoint.y()-origPoint.y();//移动向量 微分dy

        //多选中的图元都同时移动
        for(int i=0;i<this->selectedItems().count();++i)
        {
            this->selectedItems()[i]->moveBy(dx,dy);
        }
        origPoint=movePoint;
    }

}

void HGraphicsScene::mouseMoveEdit(QGraphicsSceneMouseEvent * event)
{
    QList<QGraphicsItem *>  items = selectedItems();
    foreach(auto iter, items){
        QEvent event(QEvent::Type::MouseMove);
        sendEvent(iter, &event);
    }
}

void HGraphicsScene::mouseReleaseDraw(QGraphicsSceneMouseEvent * event)
{
    if(isDrawing)
    {

        switch (this->m_curShape) {
        case shapeType::handlePenType:{

            if(m_path && m_pPathItem){
                m_path->lineTo(event->scenePos());
                m_pPathItem->setPath(*m_path);

                QRectF rect = m_pPathItem->boundingRect();
                m_pPathItem->setTransformOriginPoint(rect.x() + rect.width()/2, rect.y() + rect.height()/2);

                m_pPathItem->setFlag(QGraphicsItem::ItemIsMovable,true);
                m_pPathItem->setFlag(QGraphicsItem::ItemIsSelectable,true);
                m_shapes.append(m_pPathItem);
            }

            isDrawing = false;
            m_pPathItem = nullptr;
            m_path = nullptr;
        }break;
        case shapeType::straightType:{
            movePoint = event->scenePos();

            m_pLineItem->setLine(QLineF(origPoint, movePoint));
            m_pLineItem->setFlag(QGraphicsItem::ItemIsMovable,true);
            m_pLineItem->setFlag(QGraphicsItem::ItemIsSelectable,true);
            m_shapes.append(m_pLineItem);

            QRectF rect = m_pLineItem->boundingRect();
            m_pLineItem->setTransformOriginPoint(rect.x() + rect.width()/2, rect.y() + rect.height()/2);

            isDrawing=false;

            origPoint = QPointF();
            movePoint = QPointF();
            m_pLineItem = nullptr;
        }break;
        case shapeType::triangleType:{
            movePoint = event->scenePos();
            QRectF rectf(origPoint, movePoint);

            qreal width = movePoint.rx()-origPoint.rx();
            qreal height = movePoint.ry()-origPoint.ry();

            m_pTriangleItem->setRect(-width/2, -height/2, width, height);
            m_pTriangleItem->setPos(origPoint.rx()+width/2, origPoint.ry()+height/2);


            m_pTriangleItem->setFlag(QGraphicsItem::ItemIsMovable,true);
            m_pTriangleItem->setFlag(QGraphicsItem::ItemIsSelectable,true);
            m_shapes.append(m_pTriangleItem);

            isDrawing=false;

            origPoint = QPointF();
            movePoint = QPointF();
            m_pTriangleItem = nullptr;
        }break;
        case shapeType::rectType:{
            movePoint = event->scenePos();
            QRectF rectf(origPoint, movePoint);

            qreal width = movePoint.rx()-origPoint.rx();
            qreal height = movePoint.ry()-origPoint.ry();

            m_pRectItem->setRect(-width/2, -height/2, width, height);
            m_pRectItem->setPos(origPoint.rx()+width/2, origPoint.ry()+height/2);

            m_pRectItem->setFlag(QGraphicsItem::ItemIsMovable,true);
            m_pRectItem->setFlag(QGraphicsItem::ItemIsSelectable,true);
            m_shapes.append(m_pRectItem);

            isDrawing=false;

            origPoint = QPointF();
            movePoint = QPointF();
            m_pRectItem = nullptr;
        }break;
        case shapeType::ellipseType:{
            movePoint = event->scenePos();
            QRectF rectf(origPoint, movePoint);

            qreal width = movePoint.rx()-origPoint.rx();
            qreal height = movePoint.ry()-origPoint.ry();

            m_pEllipseItem->setRect(-width/2, -height/2, width, height);
            m_pEllipseItem->setPos(origPoint.rx()+width/2, origPoint.ry()+height/2);

            m_pEllipseItem->setFlag(QGraphicsItem::ItemIsMovable,true);
            m_pEllipseItem->setFlag(QGraphicsItem::ItemIsSelectable,true);
            m_shapes.append(m_pEllipseItem);

            isDrawing=false;

            origPoint = QPointF();
            movePoint = QPointF();
            m_pEllipseItem = nullptr;
        }break;
        case shapeType::poligenType:{

        }break;
        case shapeType::bezierType:{

        }break;
        case shapeType::bLineType:{

        }break;
        }
    }
}

void HGraphicsScene::mouseReleaseMove(QGraphicsSceneMouseEvent *)
{
    this->views()[0]->setCursor(Qt::OpenHandCursor);
    this->clearSelection();//禁止远程点击直接拖动、具体含义待定？？？
}

void HGraphicsScene::mouseReleaseEdit(QGraphicsSceneMouseEvent *)
{
}

void HGraphicsScene::keyPressEvent(QKeyEvent *keyEvent)
{
    if(keyEvent->key() == Qt::Key::Key_Escape){
        clearSelection();
    }
    else if (keyEvent->key() == Qt::Key::Key_Left) {
        foreach(auto iter, selectedItems()){
            iter->moveBy(-1,0);
        }
    }
    else if (keyEvent->key() == Qt::Key::Key_Up) {
        foreach(auto iter, selectedItems()){
            iter->moveBy(0,-1);
        }
    }
    else if (keyEvent->key() == Qt::Key::Key_Right) {
        foreach(auto iter, selectedItems()){
            iter->moveBy(1,0);
        }
    }
    else if (keyEvent->key() == Qt::Key::Key_Down) {
        foreach(auto iter, selectedItems()){
            iter->moveBy(0,1);
        }
    }

    QGraphicsScene::keyPressEvent(keyEvent);
}


//void HGraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *contextMenuEvent)
//{
//    DBG;
//    QGraphicsScene::contextMenuEvent(contextMenuEvent);
//}

//void HGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
//{
//    DBG;
//    QGraphicsScene::dragEnterEvent(event);
//}

//void HGraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
//{
//    DBG;
//    QGraphicsScene::dragLeaveEvent(event);
//}

//void HGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
//{
//    DBG;
//    QGraphicsScene::dragMoveEvent(event);
//}

//void HGraphicsScene::drawBackground(QPainter *painter, const QRectF &rect)
//{
//    DBG;
//    QGraphicsScene::drawBackground(painter, rect);
//}

//void HGraphicsScene::drawForeground(QPainter *painter, const QRectF &rect)
//{
//    DBG;
//    QGraphicsScene::drawForeground(painter, rect);
//}

//void HGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event)
//{
//    DBG;
//    QGraphicsScene::dropEvent(event);
//}

//void HGraphicsScene::focusInEvent(QFocusEvent *focusEvent)
//{
//    DBG;
//    QGraphicsScene::focusInEvent(focusEvent);
//}

//void HGraphicsScene::focusOutEvent(QFocusEvent *focusEvent)
//{
//    DBG;
//    QGraphicsScene::focusOutEvent(focusEvent);
//}

//void HGraphicsScene::helpEvent(QGraphicsSceneHelpEvent *helpEvent)
//{
//    DBG;
//    QGraphicsScene::helpEvent(helpEvent);
//}

//void HGraphicsScene::inputMethodEvent(QInputMethodEvent *event)
//{
////    DBG;
//    QGraphicsScene::inputMethodEvent(event);
//}

//void HGraphicsScene::keyPressEvent(QKeyEvent *keyEvent)
//{
////    DBG;
//    QGraphicsScene::keyPressEvent(keyEvent);
//}

//void HGraphicsScene::keyReleaseEvent(QKeyEvent *keyEvent)
//{
////    DBG;
//    QGraphicsScene::keyReleaseEvent(keyEvent);
//}

//void HGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
//{
////    DBG;
//    QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
//}

//void HGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *wheelEvent)
//{
////    DBG;
//    QGraphicsScene::wheelEvent(wheelEvent);
//}

//bool HGraphicsScene::event(QEvent *event)
//{
////    DBG;
//    return QGraphicsScene::event(event);
//}

//bool HGraphicsScene::eventFilter(QObject *watched, QEvent *event)
//{
////    DBG;
//    return QGraphicsScene::eventFilter(watched, event);
//}


/*************/

void HGraphicsScene::showShape(QVector<QGraphicsItem*> m_shapes)
{
    //    DBG;
    //先清除原来的 items 列表, 可以优化
    while(this->items().count()>0)
    {
        this->removeItem(this->items()[0]);
    }

    //再添加现在的 items
    for(int i=0; i<m_shapes.count(); ++i)
    {
        this->addItem(m_shapes[i]);
    }
}

