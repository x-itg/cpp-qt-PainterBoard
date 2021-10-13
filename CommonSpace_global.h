#pragma once
#ifndef COMMONSPACE_GLOBAL_H
#define COMMONSPACE_GLOBAL_H

#include <stdarg.h>
#include <stdio.h>
#include <QDebug>
#include <QPointF>

namespace CommonSpace_global {

    int va_list_test_int(int count, ...);

    void va_list_test_char_p(const char *format, ...);

    QList<QPointF> generatePointfList(int count, ...);

    QList<QPoint> generatePointList(int count, ...);
}

#endif // COMMONSPACE_GLOBAL_H
