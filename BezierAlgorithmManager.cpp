#include "BezierAlgorithmManager.h"

static BezierAlgorithmManager * m_pBezierAlgorithmManager = nullptr;

BezierAlgorithmManager *BezierAlgorithmManager::getInstance()
{
    if(m_pBezierAlgorithmManager){
        return m_pBezierAlgorithmManager;
    }
    else {
        m_pBezierAlgorithmManager = new BezierAlgorithmManager;
        return m_pBezierAlgorithmManager;
    }
}

BezierAlgorithmManager::BezierAlgorithmManager()
{

}

QPointF BezierAlgorithmManager::circleCenter(QPointF A, QPointF B, QPointF C) {

   qreal yDelta_a = B.ry() - A.ry();
   qreal xDelta_a = B.rx() - A.rx();
   qreal yDelta_b = C.ry() - B.ry();
   qreal xDelta_b = C.rx() - B.rx();

   QPointF center;

   qreal aSlope = yDelta_a/xDelta_a;
   qreal bSlope = yDelta_b/xDelta_b;

   center.rx() = (aSlope*bSlope*(A.ry() - C.ry()) + bSlope*(A.rx() + B.rx())
       - aSlope*(B.rx()+C.rx()) )/(2* (bSlope-aSlope) );
   center.ry() = -1*(center.rx() - (A.rx()+B.rx())/2)/aSlope +  (A.ry()+B.ry())/2;

   return center;
 }

/******************************************/

QPointF BezierAlgorithmManager::pointOnece(QPointF pointA, QPointF pointB, double t){
    return (1-t)*pointA + t*pointB;
}

QPointF BezierAlgorithmManager::pointTwice(QPointF pointA, QPointF pointB, QPointF pointC, double t){
    return pointOnece(pointOnece(pointA, pointB, t), pointOnece(pointB, pointC, t), t);
}

QPointF BezierAlgorithmManager::pointThrice(QPointF pointA, QPointF pointB, QPointF pointC, QPointF pointD, double t){
    return pointOnece(pointTwice(pointA, pointB, pointC, t), pointTwice(pointB, pointC, pointD, t), t);
}

QPointF BezierAlgorithmManager::pointRecursive(QList<QPointF> &pointList, int n, int time, double t){

    if(n == 0){
        return pointOnece(pointList.at(time), pointList.at(time+1), t);
    }
    else {
        return pointOnece(pointRecursive(pointList, n-1, time, t), pointRecursive(pointList, n-1, time+1, t), t);
    }
}

QPointF BezierAlgorithmManager::pointRecursiveBezierCurve(QList<QPointF> &pointList, double t){
    int n = pointList.length();
    return pointRecursive(pointList, n-2, 0, t);
}

QPainterPath BezierAlgorithmManager::pathOnceBezier(QPointF p1, QPointF p2)
{
    QPainterPath path;
    QPointF pTemp;
    for(double t=0; t<1; t+=0.01) //1次Bezier曲线
    {
        pTemp = pointOnece(p1,p2,t);
        path.lineTo(pTemp);
    }
    return path;
}

QPainterPath BezierAlgorithmManager::pathTwiceBezier(QPointF p0, QPointF p1, QPointF p2){

    QPainterPath path;
    path.moveTo(p0);
    QPointF pTemp;
    for(double t=0; t<1; t+=0.01) //2次Bezier曲线
    {
        pTemp = pointTwice(p0,p1,p2,t);
        path.lineTo(pTemp);
    }
    return path;
}

QPainterPath BezierAlgorithmManager::pathThriceBezier(QPointF p0, QPointF p1, QPointF p2, QPointF p3){

    QPainterPath path;
    path.moveTo(p0);
    QPointF pTemp;
    for(double t=0; t<1; t+=0.01) //3次Bezier曲线
    {
        pTemp = pointThrice(p0,p1,p2,p3,t);
        path.lineTo(pTemp);
    }

    return path;
}

QPainterPath BezierAlgorithmManager::pahtRecursiveBezier(QList<QPointF> pointList){

    QPointF pTemp;
    QPainterPath path;

    if(pointList.length()){
        path.moveTo(pointList.at(0));
    }

    for(double t=0; t<1; t+=0.01) //递归任意次数 Bezier曲线
    {
        pTemp = pointRecursiveBezierCurve(pointList, t);
        path.lineTo(pTemp);
    }

    return path;
}

QPainterPath BezierAlgorithmManager::pathTwiceAppendBezier(QList<QPointF> pointList){
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length())
        path.moveTo(pointList.at(0));

    int n = pointList.length();
    for (int i = 0; i < n-2; i+=2) {
        for(double t=0; t<1; t+=0.01) //两次贝塞尔 叠加
        {
            pTemp = pointTwice(pointList.at(i), pointList.at(i+1),pointList.at(i+2), t);
            path.lineTo(pTemp);
        }
    }
    return path;
}

QPainterPath BezierAlgorithmManager::pathThriceAppendBezier(QList<QPointF> pointList)
{
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length())
        path.moveTo(pointList.at(0));

    int n = pointList.length();
    for (int i = 0; i < n-3; i+=3) {
        for(double t=0; t<1; t+=0.01) //三次贝塞尔 叠加
        {
            pTemp = pointThrice(pointList.at(i), pointList.at(i+1),pointList.at(i+2),pointList.at(i+3), t);
            path.lineTo(pTemp);
        }
    }
    return path;
}

QList<QPointF> BezierAlgorithmManager::generateFountainPenList(QList<QPointF> pointSrcList)
{
    QList<QPointF> pointFPList;

    for (int i = 0; i < pointSrcList.length()-1; i++) {
        qDebug() << "i%2 = " << i%2 << "   i = "<< i;
        if(i%2){//比如 3、5、7、9
            qDebug() << i;
            QPointF tp(2* pointSrcList.at(i) - pointSrcList.at(i+1));
            pointFPList.push_back(tp);
        }
        pointFPList.push_back(pointSrcList.at(i));
    }
    pointFPList.push_back(pointSrcList.at(pointSrcList.length()-1));

    return pointFPList;
}

QList<QPointF> BezierAlgorithmManager::generateFountainPenList(QVector<QPointF> pointSrcList)
{
    QList<QPointF> pointFPList;

    for (int i = 0; i < pointSrcList.length()-1; i++) {
        qDebug() << "i%2 = " << i%2 << "   i = "<< i;
        if(i%2){//比如 3、5、7、9
            qDebug() << i;
            QPointF tp(2* pointSrcList.at(i) - pointSrcList.at(i+1));
            pointFPList.push_back(tp);

        }
        pointFPList.push_back(pointSrcList.at(i));
    }
    pointFPList.push_back(pointSrcList.at(pointSrcList.length()-1));

    return pointFPList;
}

QPainterPath BezierAlgorithmManager::pathFountainPenBezier(QList<QPointF> pointList)
{
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length() < 3){
    }
    else if(pointList.length() == 3)
    {
        path.moveTo(pointList.at(0));

        for (double t=0; t<1; t+=0.01) {//开始是 二次贝塞尔
            pTemp = pointTwice(pointList.at(0), pointList.at(1), pointList.at(2), t);
            path.lineTo(pTemp);
        }
    }
    else if (pointList.length() > 3) {
        path.moveTo(pointList.at(0));

        for (double t=0; t<1; t+=0.01) {//开始是 二次贝塞尔
            pTemp = pointTwice(pointList.at(0), pointList.at(1), pointList.at(2), t);
            path.lineTo(pTemp);
        }
        for (int i = 2; i < pointList.length()-3; i+=3) {//然后是 迭代 三次贝塞尔 叠加 步进三
            for(double t=0; t<1; t+=0.01)
            {
                pTemp = pointThrice(pointList.at(i), pointList.at(i+1),pointList.at(i+2),pointList.at(i+3), t);
                path.lineTo(pTemp);
            }
        }
    }
    return path;
}

QPainterPath BezierAlgorithmManager::pathFountainPenBezier(QVector<QPointF> pointList)
{
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length() < 3){

    }
    else if(pointList.length() == 3)
    {
        path.moveTo(pointList.at(0));

        for (double t=0; t<1; t+=0.01) {//开始是 二次贝塞尔
            pTemp = pointTwice(pointList.at(0), pointList.at(1), pointList.at(2), t);
            path.lineTo(pTemp);
        }
    }
    else if (pointList.length() > 3) {
        path.moveTo(pointList.at(0));

        for (double t=0; t<1; t+=0.01) {//开始是 二次贝塞尔
            pTemp = pointTwice(pointList.at(0), pointList.at(1), pointList.at(2), t);
            path.lineTo(pTemp);
        }
        for (int i = 2; i < pointList.length()-3; i+=3) {//然后是 迭代 三次贝塞尔 叠加 步进三
            for(double t=0; t<1; t+=0.01)
            {
                pTemp = pointThrice(pointList.at(i), pointList.at(i+1),pointList.at(i+2),pointList.at(i+3), t);
                path.lineTo(pTemp);
            }
        }
    }

    return path;
}

QList<QPointF> BezierAlgorithmManager::generateBlineListNotReal(QPointF p0, QPointF p1, QPointF p2)
{
    QList<QPointF> pointList;
    QPointF pointMiddle = (p0 + p2)/2;//底边中点
    QPointF vec = p1-pointMiddle;//底边中点 到 中点 向量
    QPointF vecToP0(p1.rx() + vec.ry()/2, p1.ry() - vec.rx()/2);//垂直"左"偏移
    QPointF vecToP2(p1.rx() - vec.ry()/2, p1.ry() + vec.rx()/2);//垂直"右"偏移

    pointList.push_back(p0);
    pointList.push_back(vecToP0);
    pointList.push_back(p1);
    pointList.push_back(vecToP2);
    pointList.push_back(p2);

    return pointList;
}

QList<QPointF> BezierAlgorithmManager::generateBlineListNotEnough(QPointF p0, QPointF p1, QPointF p2)
{
    QList<QPointF> pointList;
    QPointF pointMiddle = (p0 + p2)/2;//底边中点
    QPointF vec = p1-pointMiddle;//底边中点 到 中点 向量
    QPointF vecToP0(p1.rx() + vec.ry()/2, p1.ry() - vec.rx()/2);//垂直"左"偏移
    QPointF vecToP2(p1.rx() - vec.ry()/2, p1.ry() + vec.rx()/2);//垂直"右"偏移

    pointList.push_back(p0);
    pointList.push_back(vecToP0);
    pointList.push_back(vecToP2);
    pointList.push_back(p2);

    return pointList;
}

QList<QPointF> BezierAlgorithmManager::generateBlineListByCenterFromThreePoint(QPointF p0, QPointF p1, QPointF p2)
{
    QList<QPointF> pointList;
   QPointF center = circleCenter(p0,p1,p2);//三点圆心
    QPointF vec = p1-center;//圆心 到 中点 向量
    QPointF vecToP0(p1.rx() + vec.ry()/2, p1.ry() - vec.rx()/2);//垂直"左"偏移
    QPointF vecToP2(p1.rx() - vec.ry()/2, p1.ry() + vec.rx()/2);//垂直"右"偏移

    pointList.push_back(p0);
    pointList.push_back(vecToP0);
    pointList.push_back(p1);
    pointList.push_back(vecToP2);
    pointList.push_back(p2);

    return pointList;
}

QPointF BezierAlgorithmManager::generateBlineOnePointByCenterFromThreePoint(QPointF p0, QPointF p1, QPointF p2)
{
    QList<QPointF> pointList;
   QPointF center = circleCenter(p0,p1,p2);//三点圆心
    QPointF vec = p1-center;//圆心 到 中点 向量
//    QPointF vecToP0(p1.rx() + vec.ry()/2, p1.ry() - vec.rx()/2);//垂直"左"偏移
    QPointF vecToP2(p1.rx() - vec.ry()/2, p1.ry() + vec.rx()/2);//垂直"右"偏移

    return vecToP2;
}

QVector<QPointF> BezierAlgorithmManager::generateBlineVectorByCenterFromThreePoint(QPointF p0, QPointF p1, QPointF p2)
{
    QVector<QPointF> pointList;
    QPointF center = circleCenter(p0,p1,p2);//三点圆心
    QPointF vec = p1-center;//圆心 到 中点 向量
    QPointF vecToP0(p1.rx() + vec.ry(), p1.ry() - vec.rx());//垂直"左"偏移
    QPointF vecToP2(p1.rx() - vec.ry(), p1.ry() + vec.rx());//垂直"右"偏移

    pointList.push_back(p0);
    pointList.push_back(vecToP0);
    pointList.push_back(p1);
    pointList.push_back(vecToP2);
    pointList.push_back(p2);

    return pointList;
}

QList<QPointF> BezierAlgorithmManager::generateBlineListByCenterFromList(QList<QPointF> pointInList)
{
    QList<QPointF> pointOutList;

    int len = pointInList.length();

    if(len == 0){
        return pointOutList;
    }
    else if (len == 1) {
        //一个点
        pointOutList = pointInList;
    }
    else if (len == 2) {
        //两个点
        pointOutList = pointInList;
    }
    else if (len == 3) {
        //五个点(3 + 2)
        pointOutList = generateBlineListByCenterFromThreePoint(pointInList[0], pointInList[1], pointInList[2]);
    }
    else if (len >= 4) {
        //七个点(5 - 1 + 3)
        pointOutList = generateBlineListByCenterFromThreePoint(pointInList[0], pointInList[1], pointInList[2]);

        for (int i = 3; i <= pointInList.length()-1; i++)
        {
            QPointF rightPoint = generateBlineOnePointByCenterFromThreePoint(pointInList[i-2],pointInList[i-1],pointInList[i]);
            pointOutList << rightPoint;
            pointOutList << pointInList[i];
        }
    }

    return pointOutList;
}

QList<QPointF> BezierAlgorithmManager::generateTwiceBlineList(QList<QPointF> &pointInList)
{
    QList<QPointF> pointOutList;

    int len = pointInList.length();

    if(len == 0){
        return pointOutList;
    }
    else if (len == 1) {
        pointOutList = pointInList;
    }
    else if (len >= 2) {
        for (int i = 0; i < pointInList.length()-1; i++) {
            QPointF midPoint;
            midPoint = (pointInList[i] + pointInList[i+1])/2;
            pointOutList.push_back(pointInList[i]);
            pointOutList.push_back(midPoint);
        }
        pointOutList.push_back(pointInList[len-1]);
    }

    return pointOutList;
}

QVector<QPointF> BezierAlgorithmManager::generateTwiceBlineList(QVector<QPointF> &pointInList)
{
    QVector<QPointF> pointOutList;

    int len = pointInList.length();

    if(len == 0){
        return pointOutList;
    }
    else if (len == 1) {
        pointOutList = pointInList;
    }
    else if (len >= 2) {
        for (int i = 0; i < pointInList.length()-1; i++) {
            QPointF midPoint;
            midPoint = (pointInList[i] + pointInList[i+1])/2;
            pointOutList.push_back(pointInList[i]);
            pointOutList.push_back(midPoint);
        }
        pointOutList.push_back(pointInList[len-1]);
    }

    return pointOutList;
}

QPainterPath BezierAlgorithmManager::pathFountainPenCurveNotEnough(QList<QPointF> pointList)
{
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length()){
        path.moveTo(pointList.at(0));
    }

    for (int i = 0; i < pointList.length()-3; i+=3) {//然后是 迭代 三次贝塞尔 叠加 步进三, 模拟弯曲钢笔工具
        for(double t=0; t<1; t+=0.01)
        {
            pTemp = pointThrice(pointList.at(i), pointList.at(i+1),pointList.at(i+2),pointList.at(i+3), t);
            path.lineTo(pTemp);
        }
    }

    return path;
}

QPainterPath BezierAlgorithmManager::pathFountainPenCurveCentreVertical(QList<QPointF> pointList)
{
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length()){
        path.moveTo(pointList.at(0));
    }

    for (int i = 0; i < pointList.length()-2; i+=2) {//然后是 迭代 二次贝塞尔 叠加 步进二， 模拟弯曲钢笔工具
        for(double t=0; t<1; t+=0.01)
        {
            pTemp = pointTwice(pointList.at(i), pointList.at(i+1), pointList.at(i+2), t);
            path.lineTo(pTemp);
        }
    }

    return path;
}

QPainterPath BezierAlgorithmManager::pathFountainPenCurveCentreVertical(QVector<QPointF> pointList)
{
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length()){
        path.moveTo(pointList.at(0));
    }

    for (int i = 0; i < pointList.length()-2; i+=2) {//然后是 迭代 二次贝塞尔 叠加 步进二， 模拟弯曲钢笔工具
        for(double t=0; t<1; t+=0.01)
        {
            pTemp = pointTwice(pointList.at(i), pointList.at(i+1), pointList.at(i+2), t);
            path.lineTo(pTemp);
        }
    }

    return path;
}

QPainterPath BezierAlgorithmManager::pathBlineList(QList<QPointF> pointList){

    QPointF pTemp;
    QPainterPath path;

    if(pointList.length() > 1){
        path.moveTo(pointList.at(1));
    }
    else {
        return QPainterPath();
    }

    int n = pointList.length();

    for (int i = 1; i < n-2; i+=2) {
        for(double t=0; t<1; t+=0.01) //两次贝塞尔 叠加
        {
            pTemp = pointTwice(pointList.at(i), pointList.at(i+1),pointList.at(i+2), t);
            path.lineTo(pTemp);
        }
    }

    return path;
}

QPainterPath BezierAlgorithmManager::pathBlineList(QVector<QPointF> pointList)
{
    QPointF pTemp;
    QPainterPath path;

    if(pointList.length() > 1){
        path.moveTo(pointList.at(1));
    }
    else {
        return QPainterPath();
    }

    int n = pointList.length();

    for (int i = 1; i < n-2; i+=2) {
        for(double t=0; t<1; t+=0.01) //两次贝塞尔 叠加
        {
            pTemp = pointTwice(pointList.at(i), pointList.at(i+1),pointList.at(i+2), t);
            path.lineTo(pTemp);
        }
    }

    return path;
}








