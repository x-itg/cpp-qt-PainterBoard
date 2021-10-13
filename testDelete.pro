#include(./ribbon/ribbon.pro)
include(./pugixml/pugixml.pri)
include(./CommandMode/CommandMode.pri)
include(./shareTools/shareTools.pri)
include(./colorRect/colorRect.pri)
include(./HYMdiArea/HYMdiArea.pri)
include(./QCommandMode/QCommandMode.pri)

#-------------------------------------------------
#
# Project created by QtCreator 2021-03-02T20:50:51
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testDelete
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/shareTools
DEPENDPATH += $$PWD/shareTools

INCLUDEPATH += $$PWD/components
DEPENDPATH += $$PWD/components

INCLUDEPATH += $$PWD/colorRect
DEPENDPATH += $$PWD/colorRect

INCLUDEPATH += $$PWD/graphics
DEPENDPATH += $$PWD/graphics

CONFIG += c++11

SOURCES += \
#    components/WidgetCanvas.cpp \
    BezierAlgorithmManager.cpp \
    CommonSpace_global.cpp \
#    colorRect/XColorDialog.cpp \
#    colorRect/XColorMaster.cpp \
#    colorRect/XColorPreview.cpp \
#    colorRect/XColorSquare.cpp \
#    colorRect/XGradientSlider.cpp \
#    colorRect/dialog.cpp \
    graphics/HGraphicsBezierItem.cpp \
    graphics/HGraphicsBlineItem.cpp \
    graphics/HGraphicsEllipseItem.cpp \
    graphics/HGraphicsLineItem.cpp \
    graphics/HGraphicsPathItem.cpp \
    graphics/HGraphicsPixmapItem.cpp \
    graphics/HGraphicsPixmapObject.cpp \
    graphics/HGraphicsPolygonItem.cpp \
    graphics/HGraphicsRectItem.cpp \
    graphics/HGraphicsScene.cpp \
    graphics/HGraphicsTextItem.cpp \
    graphics/HGraphicsTriangleItem.cpp \
    graphics/HGraphicsView.cpp \
    graphics/HGraphicsWidget.cpp \
        main.cpp \
        mainwindow.cpp \

HEADERS += \
#        components/WidgetCanvas.h \
        BezierAlgorithmManager.h \
        CommonSpace_global.h \
        bezier.h \
#        colorRect/XColorDialog.h \
#        colorRect/XColorMaster.h \
#        colorRect/XColorPreview.hpp \
#        colorRect/XColorSquare.h \
#        colorRect/XGradientSlider.hpp \
#        colorRect/dialog.h \
        define_global.h \
        graphics/HGraphicsBezierItem.h \
        graphics/HGraphicsBlineItem.h \
        graphics/HGraphicsEllipseItem.h \
        graphics/HGraphicsLineItem.h \
        graphics/HGraphicsPathItem.h \
        graphics/HGraphicsPixmapItem.h \
        graphics/HGraphicsPixmapObject.h \
        graphics/HGraphicsPolygonItem.h \
        graphics/HGraphicsRectItem.h \
        graphics/HGraphicsScene.h \
        graphics/HGraphicsTextItem.h \
        graphics/HGraphicsTriangleItem.h \
        graphics/HGraphicsView.h \
        graphics/HGraphicsWidget.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc
