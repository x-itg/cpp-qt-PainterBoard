#ifndef BEZIERALGORITHMMANAGER_H
#define BEZIERALGORITHMMANAGER_H

#include <QtWidgets>
#include "boolinq.h"

class BezierAlgorithmManager
{
public:
    static BezierAlgorithmManager * getInstance();

    /***************************** 算法 *****************************/

    /**
     * @brief 三点生成圆心算法
     * @param A
     * @param B
     * @param C
     * @return
     */
    QPointF circleCenter(QPointF A, QPointF B, QPointF C);


    /***************************** 贝塞尔 *******************************/
    /**
     * @brief 点 一次贝塞尔中间点
     */
    QPointF pointOnece(QPointF pointA, QPointF pointB, double t);

    /**
     * @brief 点 二次贝塞尔中间点
     */
    QPointF pointThrice(QPointF pointA, QPointF pointB, QPointF pointC, QPointF pointD, double t);

    /**
     * @brief 点 三次贝塞尔中间点
     */
    QPointF pointTwice(QPointF pointA, QPointF pointB, QPointF pointC, double t);

    /**
     * @brief 点 递归贝塞尔中间
     */
    QPointF pointRecursive(QList<QPointF> &pointList, int n, int time, double t);

    /**
     * @brief 点 N次贝塞尔中间点(对 递归recursivePointOnece的封装)
     */
    QPointF pointRecursiveBezierCurve(QList<QPointF> &pointList, double t);

    /**
     * @brief 一次贝塞尔
     */
    QPainterPath pathOnceBezier(QPointF p1, QPointF p2);

    /**
     * @brief 二次贝塞尔
     */
    QPainterPath pathTwiceBezier(QPointF p0, QPointF p1, QPointF p2);

    /**
     * @brief 三次贝塞尔
     */
    QPainterPath pathThriceBezier(QPointF p0, QPointF p1, QPointF p2, QPointF p3);

    /**
     * @brief 递归贝塞尔
     */
    QPainterPath pahtRecursiveBezier(QList<QPointF> pointList);

    /**
     * @brief 三次贝塞尔 叠加
     */
    QPainterPath pathThriceAppendBezier(QList<QPointF> pointList);

    /**
     * @brief 两次贝塞尔 叠加
     */
    QPainterPath pathTwiceAppendBezier(QList<QPointF> pointList);

    /**
     * @brief 钢笔贝塞尔(步进二 + 三次贝塞尔 叠加 步进三)
     */
    QPainterPath pathFountainPenBezier(QList<QPointF> pointList);
    QPainterPath pathFountainPenBezier(QVector<QPointF> pointList);

    /**
     * @brief //迭代 三次贝塞尔 叠加 步进三, 模拟弯曲钢笔工具
     * @return
     */
    QPainterPath pathFountainPenCurveNotEnough(QList<QPointF> pointList);

    /**
     * @brief 迭代 二次贝塞尔 叠加 步进二， 模拟弯曲钢笔工具
     * @return
     */
    QPainterPath pathFountainPenCurveCentreVertical(QList<QPointF> pointList);
    QPainterPath pathFountainPenCurveCentreVertical(QVector<QPointF> pointList);

    /**
     * @brief 生成 钢笔工具 List
     */
    QList<QPointF> generateFountainPenList(QList<QPointF> pointSrcList);
    QList<QPointF> generateFountainPenList(QVector<QPointF> pointSrcList);

    /**
     * @brief (弯度钢笔工具)(假 B 样条)
     */
    QList<QPointF> generateBlineListNotReal(QPointF p0, QPointF p1, QPointF p2);

    /**
     * @brief 生成 (弯度钢笔工具)(B 样条不够)
     */
    QList<QPointF> generateBlineListNotEnough(QPointF p0, QPointF p1, QPointF p2);

    QList<QPointF> generateBlineListByCenterFromThreePoint(QPointF p0, QPointF p1, QPointF p2);
    QVector<QPointF> generateBlineVectorByCenterFromThreePoint(QPointF p0, QPointF p1, QPointF p2);

    /***************** 不成样子 *******************/
    /**
     * @brief 生成真正的 B样条
     * @param pointInList
     * @return
     */
    QList<QPointF> generateBlineListByCenterFromList(QList<QPointF> pointInList);
    QPointF generateBlineOnePointByCenterFromThreePoint(QPointF p0, QPointF p1, QPointF p2);
    /***************** 不成样子 *******************/

    /**
     * @brief 生成 B样条List,(弯度钢笔工具)(二次)
     */
    QList<QPointF> generateTwiceBlineList(QList<QPointF> &pointList);
    QVector<QPointF> generateTwiceBlineList(QVector<QPointF> &pointList);

    /**
     * @brief 生成 B样条 path (一半路径版本)
     * @param pointList
     * @return
     */
    QPainterPath pathBlineList(QList<QPointF> pointList);
    QPainterPath pathBlineList(QVector<QPointF> pointList);


private:
    BezierAlgorithmManager();

};

#endif // BEZIERALGORITHMMANAGER_H
