#ifndef HMDIAREA_H
#define HMDIAREA_H

#include <QSize>
#include <QDebug>
#include <QMdiArea>
#include <QState>
#include <QStateMachine>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QAbstractAnimation>
#include <QAbstractTransition>
#include <QSignalTransition>
#include <QMdiSubWindow>
#include <QTimer>
#include <QtMath>

class HMdiArea : public QMdiArea
{
    Q_OBJECT
public:
    enum SubWindowViewMode{
        /** 原生区域 tabView **/
        tabStateMode,//table页签模式
        tabTriStateMode,//三角table模式
        /** 自定义区域 subWindowView  **/
        ellipseStateMode,//圆形
        figure8StateMode,//8行
        QrandomStateMode,//随机
        tiledStateMode,//平铺
        centeredStateMode,//中心
        cascadeStateMode,//级联
        horizentalStateMode,//水平模式
        verticalStateMode//垂直模式
    };
public:
    void setSubWindowViewMode(SubWindowViewMode subMode);
    void setIsCloseSubWidget(const bool flag);
private:
    bool isCloseSubWidget;

public:
    HMdiArea(QWidget * parent = nullptr, bool useAnimation = false);
    ~HMdiArea() override;

protected:
    bool eventFilter(QObject * obj, QEvent * ev) override;


    /**************状态start****************/
public:
    QMdiSubWindow * addSubWindow(QWidget *widget, Qt::WindowFlags windowFlags = Qt::WindowFlags());

signals:
    void ellipsePressed();
    void figure8Pressed();
    void randomPressed();
    void tiledPressed();
    void centeredPressed();
    void cascadePressed();
    void horizentalPressed();
    void verticalPressed();

private:
    void initStateMachine();//初始化状态机

public:
    bool useAnimation;
    QEasingCurve::Type curveMode;//动画曲线
    int animationDurationTime;//动画持续时间
    int animationSubwinSpacingTime;//动画间隔时间

protected:
    QMdiSubWindow *subWindowItem;
    QParallelAnimationGroup *groupTemp;
    QPropertyAnimation *anim;

    // states
    QState *rootState;
    QState *ellipseState;//ok
    QState *figure8State;//ok
    QState *randomState;//ok
    QState *tiledState;//ok
    QState *centeredState;//ok
    QState *cascadeState;//ok
    QState *horizentalState;//ok
    QState *verticalState;//ok

    //trans
    QAbstractTransition * ellipseTrans;
    QAbstractTransition * figure8Trans;
    QAbstractTransition * randomTrans;
    QAbstractTransition * tiledTrans;
    QAbstractTransition * centeredTrans;
    QAbstractTransition * cascadeTrans;
    QAbstractTransition * horizentalTrans;
    QAbstractTransition * verticalTrans;

    //状态机
    QStateMachine stateMachine;
    QParallelAnimationGroup *group;

public:
    void isUseAnimation(bool isUseAnimation);
    void updateStates();
    void updateStateObjects();
    void updateAnimationGroup();

protected:


    /**************状态end****************/
};


#endif // HMDIAREA_H
