#include "WidgetCanvas.h"

WidgetCanvas::WidgetCanvas(QWidget *parent, Qt::WindowFlags f):
    QWidget (parent)
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));

}

void drawList(QPainter * painter, QList<QPointF> pointList, QColor color)
{
    if(painter){
        painter->save();
        QPen pen = painter->pen();
        pen.setColor(color);
        painter->setPen(pen);
        int n = pointList.length();
        for (int i = 0; i < n - 1; ++i) {
            painter->drawLine(pointList.at(i), pointList.at(i+1));
        }
        painter->restore();
    }
}

void drawPoints(QPainter * painter, QList<QPointF> pointList, QColor color)
{
    if(painter){
        painter->save();
        QPen pen = painter->pen();
        pen.setWidth(6);
        pen.setColor(color);
        painter->setPen(pen);
        int n = pointList.length();
        for (int i = 0; i < n; ++i) {
            painter->drawPoint(pointList.at(i));
        }
        painter->restore();
    }
}

#if 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QPointF p0(100,100);
    QPointF p1(500,500);

    QPainterPath path = BezierAlgorithmManager::getInstance()->pathOnceBezier(p0, p1);

    painter->drawPath(path);
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QPointF p0(100,100);
    QPointF p1(500,500);
    QPointF p2(100,500);

    painter->setPen(Qt::red);
    painter->drawLine(p0,p1);
    painter->drawLine(p1,p2);
    QPainterPath path;

    path = BezierAlgorithmManager::getInstance()->pathTwiceBezier(p0, p1, p2);

    painter->drawPath(path);
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointList;
    pointList = CommonSpace_global::generatePointfList(13,
                                                       200.0,260.0,
                                                       292.0,211.0,
                                                       410.0,250.0,
                                                       250.0,244.0,
                                                       250.0,315.0,
                                                       220.0,423.0,
                                                       356.0,216.0,
                                                       423.0,350.0,
                                                       550.0,433.0,
                                                       414.0,177.0,
                                                       288.0,144.0,
                                                       370.0,166.0,
                                                       263.0,293.0);
    painter->setPen(Qt::red);
    for (int i = 0; i < pointList.length()-1; ++i) {
        painter->drawLine(pointList[i], pointList[i+1]);
    }

    QPainterPath path;

    path = BezierAlgorithmManager::getInstance()->pathThriceBezier(p0, p1, p2, p3);

    painter->drawPath(path);
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);

    Bezier<QPointF> *bezier;// = new Bezier<QPointF>;
    bezier = new Bezier<QPointF>();

    QPointF p[5];

    p[0] = QPointF(100,100);
    p[1] = QPointF(700,800);
    p[2] = QPointF(100,500);
    p[3] = QPointF(500,100);

    painter->setPen(Qt::red);
    painter->drawLine(p[0],p[1]);
    painter->drawLine(p[1],p[2]);
    painter->drawLine(p[2],p[3]);

    bezier->appendPoint(p[0]);
    bezier->appendPoint(p[1]);
    bezier->appendPoint(p[2]);
    bezier->appendPoint(p[3]);


    QPainterPath path = bezier->getPainterPath();
    painter->setPen(m_pen);
    painter->drawPath(path);
    delete painter;
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointList;
    pointList = CommonSpace_global::generatePointfList(13,
                                                       200.0,260.0,
                                                       292.0,211.0,
                                                       410.0,250.0,
                                                       250.0,244.0,
                                                       250.0,315.0,
                                                       220.0,423.0,
                                                       356.0,216.0,
                                                       423.0,350.0,
                                                       550.0,433.0,
                                                       414.0,177.0,
                                                       288.0,144.0,
                                                       370.0,166.0,
                                                       263.0,293.0);

    painter->setPen(Qt::red);
    for (int i = 0; i < pointList.length()-1; ++i) {
        painter->drawLine(pointList[i], pointList[i+1]);
    }

    QPainterPath path = BezierAlgorithmManager::getInstance()->pahtRecursiveBezier(pointList);
    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointList;
    pointList = CommonSpace_global::generatePointfList(13,
                                                       200.0,260.0,
                                                       292.0,211.0,
                                                       410.0,250.0,
                                                       250.0,244.0,
                                                       250.0,315.0,
                                                       220.0,423.0,
                                                       356.0,216.0,
                                                       423.0,350.0,
                                                       550.0,433.0,
                                                       414.0,177.0,
                                                       288.0,144.0,
                                                       370.0,166.0,
                                                       263.0,293.0);


    painter->setPen(Qt::red);
    for (int i = 0; i < pointList.length()-1; ++i) {
        painter->drawLine(pointList[i], pointList[i+1]);
    }

    QPainterPath path;
    path = BezierAlgorithmManager::getInstance()->pathThriceAppendBezier(pointList);

    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointList;

    pointList = CommonSpace_global::generatePointfList(13,
                                                       200.0,260.0,
                                                       292.0,211.0,
                                                       410.0,250.0,
                                                       250.0,244.0,
                                                       250.0,315.0,
                                                       220.0,423.0,
                                                       356.0,216.0,
                                                       423.0,350.0,
                                                       550.0,433.0,
                                                       414.0,177.0,
                                                       288.0,144.0,
                                                       370.0,166.0,
                                                       263.0,293.0);

    painter->setPen(Qt::red);

    for (int i = 0; i < pointList.length()-1; ++i) {
        painter->drawLine(pointList[i], pointList[i+1]);
    }

    QPointF pTemp;
    QPainterPath path;

    path = BezierAlgorithmManager::getInstance()->pathTwiceAppendBezier(pointList);

    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointSrcList;
    QList<QPointF> pointPsList;

    pointSrcList = CommonSpace_global::generatePointfList(13,
                                                          200.0,260.0,
                                                          292.0,211.0,
                                                          410.0,250.0,
                                                          250.0,244.0,
                                                          250.0,315.0,
                                                          220.0,423.0,
                                                          356.0,216.0,
                                                          423.0,350.0,
                                                          550.0,433.0,
                                                          414.0,177.0,
                                                          288.0,144.0,
                                                          370.0,166.0,
                                                          263.0,293.0);

    {
        pointPsList = BezierAlgorithmManager::getInstance()->generateFountainPenList(pointSrcList);
    }

    /********************/
    painter->save();
    drawPoints(painter, pointPsList, QColor(Qt::GlobalColor::green));
    drawPoints(painter, pointSrcList, QColor(Qt::GlobalColor::red));
    painter->restore();
    /*******************/

    QPainterPath path;
    {
        path = BezierAlgorithmManager::getInstance()->pathFountainPenBezier(pointPsList);
    }

    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}

#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointSrcList;
    QList<QPointF> pointPsList;

    pointSrcList = CommonSpace_global::generatePointfList(13,
                                                          200.0,260.0,
                                                          292.0,211.0,
                                                          410.0,250.0,
                                                          250.0,244.0,
                                                          250.0,315.0,
                                                          220.0,423.0,
                                                          356.0,216.0,
                                                          423.0,350.0,
                                                          550.0,433.0,
                                                          414.0,177.0,
                                                          288.0,144.0,
                                                          370.0,166.0,
                                                          263.0,293.0);


    {
        pointPsList = BezierAlgorithmManager::getInstance()->generateBlineListNotEnough(pointSrcList[0], pointSrcList[1], pointSrcList[2]);
    }

    /*******************************/

    painter->save();
    drawPoints(painter, pointPsList, QColor(Qt::GlobalColor::green));
    drawPoints(painter, pointSrcList, QColor(Qt::GlobalColor::red));
    painter->restore();

    /*******************/

    QPointF pTemp;
    QPainterPath path;

    path = BezierAlgorithmManager::getInstance()->pathFountainPenCurveNotEnough(pointPsList);

    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointSrcList;
    QList<QPointF> pointPsList;

    pointSrcList = CommonSpace_global::generatePointfList(3,
                                                          200.0,260.0,
                                                          292.0,211.0,
                                                          410.0,250.0/*,
                                                                                                                  250.0,244.0,
                                                                                                                250.0,315.0,
                                                                                                                220.0,423.0,
                                                                                                                356.0,216.0,
                                                                                                                423.0,350.0,
                                                                                                                550.0,433.0,
                                                                                                                414.0,177.0,
                                                                                                                288.0,144.0,
                                                                                                                370.0,166.0,
                                                                                                                263.0,293.0*/);


    {
        pointPsList = BezierAlgorithmManager::getInstance()->generateBlineListByCenterFromThreePoint(pointSrcList[0], pointSrcList[1], pointSrcList[2]);
    }

    /*******************************/

    painter->save();
    drawPoints(painter, pointPsList, QColor(Qt::GlobalColor::green));
    drawPoints(painter, pointSrcList, QColor(Qt::GlobalColor::red));
    painter->restore();

    /*******************/

    QPointF pTemp;
    QPainterPath path;

    path = BezierAlgorithmManager::getInstance()->pathFountainPenCurveCentreVertical(pointPsList);

    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}
#elif 1
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointSrcList;
    QList<QPointF> pointPsList;

    pointSrcList = CommonSpace_global::generatePointfList(6,
                                                          200.0,260.0,
                                                          292.0,211.0,
                                                          410.0,250.0,
//                                                          250.0,244.0,
//                                                          250.0,315.0,
                                                          220.0,423.0,
                                                          356.0,216.0,
                                                          423.0,350.0/*,
                                                          550.0,433.0,
                                                          414.0,177.0,
                                                          288.0,144.0,
                                                          370.0,166.0,
                                                          263.0,293.0*/);


    pointPsList = BezierAlgorithmManager::getInstance()->generateBlineListByCenterFromList(pointSrcList); //???????????????????????? 检查算法  目的弯度钢笔工具



    /*******************************/

    painter->save();
    drawPoints(painter, pointPsList, QColor(Qt::GlobalColor::green));
    drawPoints(painter, pointSrcList, QColor(Qt::GlobalColor::red));
    painter->drawText(QPointF(100,100), QString::number(pointPsList.length()));
    painter->restore();

    /*******************/

    QPainterPath path;

    path = BezierAlgorithmManager::getInstance()->pathFountainPenCurveCentreVertical(pointPsList); //检查生成算法  目的弯度钢笔工具

    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}
#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointSrcList;
    QList<QPointF> pointPsList;

    pointSrcList = CommonSpace_global::generatePointfList(13,
                                                          200.0,260.0,
                                                          292.0,211.0,
                                                          410.0,250.0,
                                                          250.0,244.0,
                                                          250.0,315.0,
                                                          220.0,423.0,
                                                          356.0,216.0,
                                                          423.0,350.0,
                                                          550.0,433.0,
                                                          414.0,177.0,
                                                          288.0,144.0,
                                                          370.0,166.0,
                                                          263.0,293.0);



    pointPsList = BezierAlgorithmManager::getInstance()->generateBlineListNotReal(pointSrcList.at(0),pointSrcList.at(1),pointSrcList.at(2));


    /*******************************/

    painter->save();
    drawPoints(painter, pointPsList, QColor(Qt::GlobalColor::green));
    drawPoints(painter, pointSrcList, QColor(Qt::GlobalColor::red));
    painter->restore();

    /*******************/

    QPainterPath path = BezierAlgorithmManager::getInstance()->pathFountainPenCurveCentreVertical(pointPsList);
    painter->drawPath(path);

    delete painter;
}

#elif 0
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    QList<QPointF> pointInList;
    QList<QPointF> pointOutList;

    pointInList = CommonSpace_global::generatePointfList(10,
                                                         200.0,260.0,
                                                         292.0,211.0,
                                                         250.0,315.0,
                                                         220.0,423.0,
                                                         423.0,350.0,
                                                         500.0,293.0,
                                                         550.0,433.0,
                                                         414.0,177.0,
                                                         288.0,144.0,
                                                         370.0,166.0
                                                         );

    pointOutList = BezierAlgorithmManager::getInstance()->generateTwiceBlineList(pointInList);


    /*******************************/

    painter->save();
    drawPoints(painter, pointOutList, QColor(Qt::GlobalColor::green));
    drawPoints(painter, pointInList, QColor(Qt::GlobalColor::red));
    painter->restore();

    /*******************/

    QPainterPath path = BezierAlgorithmManager::getInstance()->pathBlineList(pointOutList);
    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}

#elif 1
void WidgetCanvas::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    /*******************************/

    painter->save();
    drawPoints(painter, pointBlineList, QColor(Qt::GlobalColor::green));
    drawPoints(painter, pointOriginList, QColor(Qt::GlobalColor::red));
    painter->restore();

    /*******************/

    QPainterPath path = BezierAlgorithmManager::getInstance()->pathBlineList(pointBlineList);
    painter->setPen(m_pen);
    painter->drawPath(path);

    delete painter;
}

#endif
void WidgetCanvas::mouseMoveEvent(QMouseEvent *event)
{

    {
        this->pointOriginList[pointOriginList.length()-1] = event->pos();
        this->pointBlineList[pointBlineList.length()-1] = event->pos();

        if(!pointBlineList.isEmpty()){
            if(pointBlineList.length()>1)
            {
                this->pointBlineList[pointBlineList.length()-2] =  (this->pointBlineList[pointBlineList.length()-3] + event->pos())/2;
            }
        }
    }

    update();
    QWidget::mouseMoveEvent(event);
}

void WidgetCanvas::mousePressEvent(QMouseEvent *event)
{
    this->pointOriginList.push_back(event->pos());

    if(pointOriginList.length() > 1){
        this->pointBlineList.push_back((pointOriginList[pointOriginList.length()-1] + event->pos())/2);

    }
    this->pointBlineList.push_back(event->pos());

    update();
    QWidget::mousePressEvent(event);
}

void WidgetCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    update();
    QWidget::mouseReleaseEvent(event);
}

