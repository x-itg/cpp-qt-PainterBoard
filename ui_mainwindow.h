/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionsave_as;
    QAction *actionpen;
    QAction *actionrect;
    QAction *actiontriangle;
    QAction *actionellipse;
    QAction *actionbezier_curve;
    QAction *actionredo;
    QAction *actionundo;
    QAction *actionmerge;
    QAction *actionapart;
    QAction *actionstraight_line;
    QAction *actionpoligon;
    QAction *actionBLine;
    QAction *actionmove;
    QAction *actiondraw;
    QAction *actionboderColor;
    QAction *actiontext;
    QAction *actionpixmap;
    QAction *actionabout_Qt;
    QAction *actionabout_drawBoard;
    QAction *actiontab;
    QAction *actiontritab;
    QAction *actioncenter;
    QAction *actionellipseSubwin;
    QAction *action8;
    QAction *actioncascade;
    QAction *actiontitled;
    QAction *actionrandom;
    QAction *actionveritcal;
    QAction *actionhorizental;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QMenuBar *menuBar;
    QMenu *menutest;
    QMenu *menufileOperation;
    QMenu *menuanimationOperation;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QString::fromUtf8("actionnew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qrc/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionnew->setIcon(icon);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qrc/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon1);
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qrc/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave->setIcon(icon2);
        actionsave_as = new QAction(MainWindow);
        actionsave_as->setObjectName(QString::fromUtf8("actionsave_as"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/qrc/save_as.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave_as->setIcon(icon3);
        actionpen = new QAction(MainWindow);
        actionpen->setObjectName(QString::fromUtf8("actionpen"));
        actionpen->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/qrc/pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpen->setIcon(icon4);
        actionrect = new QAction(MainWindow);
        actionrect->setObjectName(QString::fromUtf8("actionrect"));
        actionrect->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/qrc/rect (6).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionrect->setIcon(icon5);
        actiontriangle = new QAction(MainWindow);
        actiontriangle->setObjectName(QString::fromUtf8("actiontriangle"));
        actiontriangle->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/qrc/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontriangle->setIcon(icon6);
        actionellipse = new QAction(MainWindow);
        actionellipse->setObjectName(QString::fromUtf8("actionellipse"));
        actionellipse->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/qrc/ellipse (4).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionellipse->setIcon(icon7);
        actionbezier_curve = new QAction(MainWindow);
        actionbezier_curve->setObjectName(QString::fromUtf8("actionbezier_curve"));
        actionbezier_curve->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/qrc/curve.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionbezier_curve->setIcon(icon8);
        actionredo = new QAction(MainWindow);
        actionredo->setObjectName(QString::fromUtf8("actionredo"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/qrc/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionredo->setIcon(icon9);
        actionundo = new QAction(MainWindow);
        actionundo->setObjectName(QString::fromUtf8("actionundo"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/qrc/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionundo->setIcon(icon10);
        actionmerge = new QAction(MainWindow);
        actionmerge->setObjectName(QString::fromUtf8("actionmerge"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/qrc/merge (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionmerge->setIcon(icon11);
        actionapart = new QAction(MainWindow);
        actionapart->setObjectName(QString::fromUtf8("actionapart"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/qrc/apart (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionapart->setIcon(icon12);
        actionstraight_line = new QAction(MainWindow);
        actionstraight_line->setObjectName(QString::fromUtf8("actionstraight_line"));
        actionstraight_line->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/qrc/straight_line (4).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionstraight_line->setIcon(icon13);
        actionpoligon = new QAction(MainWindow);
        actionpoligon->setObjectName(QString::fromUtf8("actionpoligon"));
        actionpoligon->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/qrc/rect (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpoligon->setIcon(icon14);
        actionBLine = new QAction(MainWindow);
        actionBLine->setObjectName(QString::fromUtf8("actionBLine"));
        actionBLine->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/qrc/B_Line (3).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBLine->setIcon(icon15);
        actionmove = new QAction(MainWindow);
        actionmove->setObjectName(QString::fromUtf8("actionmove"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/qrc/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionmove->setIcon(icon16);
        actiondraw = new QAction(MainWindow);
        actiondraw->setObjectName(QString::fromUtf8("actiondraw"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/qrc/pen (3).png"), QSize(), QIcon::Normal, QIcon::Off);
        actiondraw->setIcon(icon17);
        actionboderColor = new QAction(MainWindow);
        actionboderColor->setObjectName(QString::fromUtf8("actionboderColor"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/qrc/color (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionboderColor->setIcon(icon18);
        actiontext = new QAction(MainWindow);
        actiontext->setObjectName(QString::fromUtf8("actiontext"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/qrc/text (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontext->setIcon(icon19);
        actionpixmap = new QAction(MainWindow);
        actionpixmap->setObjectName(QString::fromUtf8("actionpixmap"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/qrc/pixmap (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpixmap->setIcon(icon20);
        actionabout_Qt = new QAction(MainWindow);
        actionabout_Qt->setObjectName(QString::fromUtf8("actionabout_Qt"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/qrc/qt_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionabout_Qt->setIcon(icon21);
        actionabout_drawBoard = new QAction(MainWindow);
        actionabout_drawBoard->setObjectName(QString::fromUtf8("actionabout_drawBoard"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/qrc/drawBoard (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionabout_drawBoard->setIcon(icon22);
        actiontab = new QAction(MainWindow);
        actiontab->setObjectName(QString::fromUtf8("actiontab"));
        actiontritab = new QAction(MainWindow);
        actiontritab->setObjectName(QString::fromUtf8("actiontritab"));
        actioncenter = new QAction(MainWindow);
        actioncenter->setObjectName(QString::fromUtf8("actioncenter"));
        actionellipseSubwin = new QAction(MainWindow);
        actionellipseSubwin->setObjectName(QString::fromUtf8("actionellipseSubwin"));
        action8 = new QAction(MainWindow);
        action8->setObjectName(QString::fromUtf8("action8"));
        actioncascade = new QAction(MainWindow);
        actioncascade->setObjectName(QString::fromUtf8("actioncascade"));
        actiontitled = new QAction(MainWindow);
        actiontitled->setObjectName(QString::fromUtf8("actiontitled"));
        actionrandom = new QAction(MainWindow);
        actionrandom->setObjectName(QString::fromUtf8("actionrandom"));
        actionveritcal = new QAction(MainWindow);
        actionveritcal->setObjectName(QString::fromUtf8("actionveritcal"));
        actionhorizental = new QAction(MainWindow);
        actionhorizental->setObjectName(QString::fromUtf8("actionhorizental"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menutest = new QMenu(menuBar);
        menutest->setObjectName(QString::fromUtf8("menutest"));
        menufileOperation = new QMenu(menutest);
        menufileOperation->setObjectName(QString::fromUtf8("menufileOperation"));
        menuanimationOperation = new QMenu(menutest);
        menuanimationOperation->setObjectName(QString::fromUtf8("menuanimationOperation"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setMinimumSize(QSize(0, 0));
        MainWindow->setStatusBar(statusBar);
        dockWidget_3 = new QDockWidget(MainWindow);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        dockWidget_3->setWidget(dockWidgetContents_3);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, dockWidget_3);

        menuBar->addAction(menutest->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menutest->addAction(actionnew);
        menutest->addAction(actionopen);
        menutest->addAction(actionsave);
        menutest->addAction(actionsave_as);
        menutest->addSeparator();
        menutest->addAction(menufileOperation->menuAction());
        menutest->addAction(menuanimationOperation->menuAction());
        menufileOperation->addAction(actiontab);
        menufileOperation->addAction(actiontritab);
        menufileOperation->addAction(actioncenter);
        menufileOperation->addAction(actionellipseSubwin);
        menufileOperation->addAction(action8);
        menufileOperation->addAction(actioncascade);
        menufileOperation->addAction(actiontitled);
        menufileOperation->addAction(actionrandom);
        menufileOperation->addAction(actionveritcal);
        menufileOperation->addAction(actionhorizental);
        menu->addAction(actionpen);
        menu->addAction(actionrect);
        menu->addAction(actiontriangle);
        menu->addAction(actionellipse);
        menu->addAction(actionbezier_curve);
        menu->addAction(actionstraight_line);
        menu->addAction(actionpoligon);
        menu->addAction(actionBLine);
        menu->addAction(actiontext);
        menu->addAction(actionpixmap);
        menu_2->addAction(actionboderColor);
        menu_3->addAction(actionredo);
        menu_3->addAction(actionundo);
        menu_3->addAction(actionmerge);
        menu_3->addAction(actionapart);
        menu_3->addAction(actionmove);
        menu_3->addAction(actiondraw);
        menu_help->addAction(actionabout_Qt);
        menu_help->addAction(actionabout_drawBoard);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionnew->setText(QCoreApplication::translate("MainWindow", "new", nullptr));
#if QT_CONFIG(shortcut)
        actionnew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionopen->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
#if QT_CONFIG(shortcut)
        actionopen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
#if QT_CONFIG(shortcut)
        actionsave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionsave_as->setText(QCoreApplication::translate("MainWindow", "save as", nullptr));
        actionpen->setText(QCoreApplication::translate("MainWindow", "pen", nullptr));
#if QT_CONFIG(shortcut)
        actionpen->setShortcut(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionrect->setText(QCoreApplication::translate("MainWindow", "rect", nullptr));
#if QT_CONFIG(shortcut)
        actionrect->setShortcut(QCoreApplication::translate("MainWindow", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        actiontriangle->setText(QCoreApplication::translate("MainWindow", "triangle", nullptr));
#if QT_CONFIG(shortcut)
        actiontriangle->setShortcut(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionellipse->setText(QCoreApplication::translate("MainWindow", "ellipse", nullptr));
#if QT_CONFIG(shortcut)
        actionellipse->setShortcut(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        actionbezier_curve->setText(QCoreApplication::translate("MainWindow", "bezier curve", nullptr));
#if QT_CONFIG(shortcut)
        actionbezier_curve->setShortcut(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        actionredo->setText(QCoreApplication::translate("MainWindow", "redo", nullptr));
#if QT_CONFIG(shortcut)
        actionredo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionundo->setText(QCoreApplication::translate("MainWindow", "undo", nullptr));
#if QT_CONFIG(shortcut)
        actionundo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionmerge->setText(QCoreApplication::translate("MainWindow", "merge", nullptr));
#if QT_CONFIG(shortcut)
        actionmerge->setShortcut(QCoreApplication::translate("MainWindow", "F12", nullptr));
#endif // QT_CONFIG(shortcut)
        actionapart->setText(QCoreApplication::translate("MainWindow", "apart", nullptr));
        actionstraight_line->setText(QCoreApplication::translate("MainWindow", "straight line", nullptr));
#if QT_CONFIG(shortcut)
        actionstraight_line->setShortcut(QCoreApplication::translate("MainWindow", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionpoligon->setText(QCoreApplication::translate("MainWindow", "poligon", nullptr));
#if QT_CONFIG(shortcut)
        actionpoligon->setShortcut(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBLine->setText(QCoreApplication::translate("MainWindow", "BLine", nullptr));
#if QT_CONFIG(shortcut)
        actionBLine->setShortcut(QCoreApplication::translate("MainWindow", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        actionmove->setText(QCoreApplication::translate("MainWindow", "move", nullptr));
#if QT_CONFIG(shortcut)
        actionmove->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actiondraw->setText(QCoreApplication::translate("MainWindow", "draw", nullptr));
#if QT_CONFIG(shortcut)
        actiondraw->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionboderColor->setText(QCoreApplication::translate("MainWindow", "boderColor", nullptr));
        actiontext->setText(QCoreApplication::translate("MainWindow", "text", nullptr));
#if QT_CONFIG(shortcut)
        actiontext->setShortcut(QCoreApplication::translate("MainWindow", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        actionpixmap->setText(QCoreApplication::translate("MainWindow", "pixmap", nullptr));
#if QT_CONFIG(shortcut)
        actionpixmap->setShortcut(QCoreApplication::translate("MainWindow", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        actionabout_Qt->setText(QCoreApplication::translate("MainWindow", "about_Qt", nullptr));
        actionabout_drawBoard->setText(QCoreApplication::translate("MainWindow", "about_drawBoard", nullptr));
        actiontab->setText(QCoreApplication::translate("MainWindow", "\351\241\265\347\255\276\346\250\241\345\274\217", nullptr));
        actiontritab->setText(QCoreApplication::translate("MainWindow", "\351\241\265\347\255\276\346\250\241\345\274\2172", nullptr));
        actioncenter->setText(QCoreApplication::translate("MainWindow", "\344\270\255\345\277\203\345\270\203\345\261\200", nullptr));
        actionellipseSubwin->setText(QCoreApplication::translate("MainWindow", "\345\234\206\345\275\242\345\270\203\345\261\200", nullptr));
        action8->setText(QCoreApplication::translate("MainWindow", "8\345\255\227\345\270\203\345\261\200", nullptr));
        actioncascade->setText(QCoreApplication::translate("MainWindow", "\345\261\202\345\217\240\345\270\203\345\261\200", nullptr));
        actiontitled->setText(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272\345\270\203\345\261\200", nullptr));
        actionrandom->setText(QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\345\270\203\345\261\200", nullptr));
        actionveritcal->setText(QCoreApplication::translate("MainWindow", "\345\236\202\347\233\264\345\270\203\345\261\200", nullptr));
        actionhorizental->setText(QCoreApplication::translate("MainWindow", "\346\260\264\345\271\263\345\270\203\345\261\200", nullptr));
        menutest->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menufileOperation->setTitle(QCoreApplication::translate("MainWindow", "\345\244\232\347\252\227\344\275\223\346\216\247\345\210\266", nullptr));
        menuanimationOperation->setTitle(QCoreApplication::translate("MainWindow", "\345\212\250\347\224\273\351\200\211\351\241\271", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\275\242\347\212\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\224\273\347\254\224", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234", nullptr));
        menu_help->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
