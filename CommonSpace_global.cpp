#include "CommonSpace_global.h"


int CommonSpace_global::va_list_test_int(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i)
    {
        int arg = va_arg(args, int);
        qDebug() << "i=" << i << "arg=" << arg;
    }
    va_end(args);


    return 0;
}

void CommonSpace_global::va_list_test_char_p(const char *format, ...)
{
    va_list args;
    const char *args1;
    const char *args2;
    const char *args3;

    va_start(args, format);
    args1 = va_arg(args,const char *);
    args2 = va_arg(args,const char *);
    args3 = va_arg(args,const char *);
    va_end(args);

    printf("format = %s  args1 = %s",  format,  args1);
    qDebug() << format << ", " << args1 << ", " << args2 << ", " << args3;
}

QList<QPointF> CommonSpace_global::generatePointfList(int count, ...)
{
    QList<QPointF> pointList;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count*2; i+=2)
    {
        qreal point1 = va_arg(args, qreal);
        qreal point2 = va_arg(args, qreal);

        QPointF pf(point1, point2);
        pointList.push_back(pf);
    }
    va_end(args);

    return pointList;
}

QList<QPoint> CommonSpace_global::generatePointList(int count, ...)
{
    QList<QPoint> pointList;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count*2; i+=2)
    {
        int point1 = va_arg(args, int);
        int point2 = va_arg(args, int);

        QPoint pf(point1, point2);
        pointList.push_back(pf);
    }
    va_end(args);

    return pointList;
}
