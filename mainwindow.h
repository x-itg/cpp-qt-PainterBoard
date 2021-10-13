#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "HYMdiArea.h"
/******************/

#include <QMainWindow>
#include <QPainter>
#include <qmath.h>
#include <QPointF>
#include <QTextEdit>
#include <QToolBar>
#include <QCalendarWidget>
#include <QPushButton>
#include <QPalette>
#include <QLabel>
#include <QComboBox>
#include <QFontDialog>
#include <QSpacerItem>

/******************/

#include "XColorDialog.h"
#include "XColorMaster.h"

/*****************/

#include "bezier.h"

/*****************/

#include <QGraphicsWidget>

#include <QGraphicsScale>

/*****************/
#include "HGraphicsPixmapObject.h"

#include "HGraphicsTextItem.h"
#include "HGraphicsEllipseItem.h"
#include "HGraphicsPathItem.h"
#include "HGraphicsRectItem.h"
#include "HGraphicsWidget.h"
#include <QGraphicsLineItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsSimpleTextItem>


#include "HGraphicsScene.h"
#include "HGraphicsView.h"

/***************/
#include <QUndoCommand>
#include "commands.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTextEdit*	displayTextEdit;

private slots:

    void on_actionsave_triggered();

    void on_actionnew_triggered();

    void on_actionundo_triggered();

    void on_actionredo_triggered();

    void on_actionsave_as_triggered();

    void on_actionpen_triggered();

    void on_actionrect_triggered();

    void on_actiontriangle_triggered();

    void on_actionellipse_triggered();

    void on_actionbezier_curve_triggered();

    void on_actionmerge_triggered();

    void on_actionapart_triggered();

    void on_actionstraight_line_triggered();

    void on_actionBLine_triggered();

    void on_actionpoligon_triggered();

    void on_actionmove_triggered();

    void on_actiondraw_triggered();

    void slotValueChanged(int);

    void on_actionboderColor_triggered();

    void on_actiontext_triggered();

    void on_actionpixmap_triggered();

    void on_actionopen_triggered();

    void on_actionabout_Qt_triggered();

    void on_actionabout_drawBoard_triggered();

    void on_actiontab_triggered();

    void on_actiontritab_triggered();

    void on_actioncenter_triggered();

    void on_actionellipseSubwin_triggered();

    void on_action8_triggered();

    void on_actioncascade_triggered();

    void on_actiontitled_triggered();

    void on_actionrandom_triggered();

    void on_actionveritcal_triggered();

    void on_actionhorizental_triggered();

public slots:
    void updateCurrentWindowViewScene();

private:
    Ui::MainWindow *ui;

    XColorMaster * master;
    QSpinBox * penWidthBox;

    QComboBox * penStyleBox;

    HGraphicsScene * m_pScene;
    HGraphicsView * m_pView;
    HGraphicsScene * m_pCurrentScene;
    HGraphicsView * m_pCurrentView;


    QLabel * m_pViewPosLabel;

    QString m_curSavePath;

private:
    HYMdiArea m_mdiArea;
    QLineEdit * spaceEdit;
    QLineEdit * timeEdit;

public:

    void initToolMenu();

public:
    QUndoStack *undoStack;
    QUndoView *undoView;
    void createUndoView();
    void testUndoView();
};

#endif // MAINWINDOW_H
