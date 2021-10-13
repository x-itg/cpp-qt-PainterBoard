#ifndef BEZIER_H
#define BEZIER_H

#include "QList"
#include "QPoint"
#include "QPainter"
#include "QPainterPath"


template<typename Point> //Point 我使用的是qt的内部类QPointF 你可以使用自己定义的
class Bezier{
private:
    double precision=0.01; //你可以自己设置精度，确保所画直线的细腻程度
    QList<Point> * pointList;

private:
    void AllBernstein(int n,double u,double *B);
    Point PointOnBezierCurve(double u);

public:

    Bezier();
    ~Bezier();

    void setPrecision(double precision);
    void appendPoint(Point point) ;
    QPainterPath getPainterPath();//你可以定义自己的画图方法 这里就不写虚方法了，
    int getListLengh();
    double getPrecision();

    // Point getPoint(int index);
    // Point deletePoint(int index);
    // void insertPoint();

};


template<typename Point>
Bezier<Point>::Bezier()
{
    pointList = new QList<Point>;
}


template<typename Point>
Bezier<Point>::~Bezier()
{
    delete pointList;
}


template<typename Point>
void Bezier<Point>::appendPoint(Point point)
{
    pointList->append(point);
}

template<typename Point>
QPainterPath Bezier<Point>::getPainterPath()
{
    QPainterPath path;
    path.moveTo(pointList->at(0));

    for(double t=0; t<1; t+= precision)
    {
        Point pTemp = PointOnBezierCurve(t);
        path.lineTo(pTemp);
    }
    return path;
}

template<typename Point>
void Bezier<Point>::setPrecision(double precision)
{
    if(precision<1)
    {
        this->precision =precision;
    }
}

template<typename Point>
double Bezier<Point>::getPrecision()
{
    return this->precision;
}

template<typename Point>
void Bezier<Point>::AllBernstein(int n, double u, double *B)
{
    B[0] = 1.0;
    double u1 = 1.0-u;
    for(int j=1; j<=n;j++)
    {
        double saved = 0.0;
        for(int k=0; k<j; k++)
        {
            double temp = B[k];
            B[k] = saved+u1*temp;
            saved = u*temp;
        }
        B[j] = saved;
    }
}

template<typename Point>
Point Bezier<Point>::PointOnBezierCurve(double u)
{
    int n = pointList->length();

    double *coefficient =new double[n]; //系数数组
    memset(coefficient,0,sizeof(coefficient));

    AllBernstein(n-1,u,coefficient);//计算系数

    Point tempPoint(0.0,0.0);
    for(int i=0;i<pointList->length();i++)
    {
        Point temp = pointList->at(i);
        tempPoint = tempPoint +temp*coefficient[i];
    }
    return tempPoint;
}

#endif // BEZIER_H
