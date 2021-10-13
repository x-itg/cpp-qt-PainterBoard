#ifndef WIDGET_H
#define WIDGET_H

#include <QFrame>
#include <QHBoxLayout>
#include <QPushButton>
#include <QCalendarWidget>
#include <QLCDNumber>
#include <QMenu>
#include "HMdiArea.h"
#include "qmath.h"

class HYMdiArea : public QFrame
{
    Q_OBJECT
private:
    QHBoxLayout layout;
    HMdiArea m_mdiArea;
public:
    HYMdiArea(bool isUseAnimation = false, QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~HYMdiArea();

    /** 测试用 **/
    void setTestPushButtonBar();

public:
    /*********************************** 核心功能 start ***********************************/
    /**
     * @brief 添加子窗口
     * @param widget：需要添加的子窗口
     * @param title：窗口名字
     * @param size：窗口大小
     * @return 返回子窗口
     */
    QMdiSubWindow * addSubWindow(QWidget * widget, QString title = "", const QSize &size = QSize(150,30));

    /**
     * @brief 设置关闭QMdiSubWindow时是否也析构QWidget
     */
    void setIsCloseSubWidget(const bool flag);

    /**
     * @brief 设置子窗口显示方式
     * @param mode：子窗口显示样式
     * @param size：子窗口大小
     */
    void setSubWindowViewMode(HMdiArea::SubWindowViewMode mode, QSize size = QSize());

    void setSubWindowSize(const QSize &size = QSize());

    /**
     * @brief 是否使用动画
     */
    void setAnimationEnable(const bool isUseAnimation);

    /**
     * @brief 设置动画时间
     * @param durationTime 持续时间
     * @param spacingTime 间隔时间
     */
    void setAnimationTime(const int durationTime = 750, const int spacingTime = 0);

    /**
     * @brief 设置动画曲线
     */
    void setAnimationCurveMode(const QEasingCurve::Type curveMode = QEasingCurve::Type::InOutBack);

    QMdiSubWindow * getCurrentWindow();

    bool hasSubWindow();

signals:
    void subWindowActivated(QMdiSubWindow *window);

public:
    /*********************************** 核心 end ***********************************/
    /**
     * @brief 设置 tab 朝向
     */
    void setTabPosition(QTabWidget::TabPosition position);
    /**
     * @brief 设置 tab 是否可以移动
     */
    void setTabsMovable(bool movable);
    /**
     * @brief 设置背景色
     */
    void setBackground(const QBrush &background);
    /**
     * @brief 设置tab是否可以关闭
     */
    void setTabsClosable(bool closable);


    //subMdiWindow接口
    void setSubWidgetsOption(const QMdiSubWindow::SubWindowOption &option);

protected:
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
    /**
     * @brief 更新状态,加入子窗口是需要更新一次
     */
    void updateStates();
private:
    //没摸清楚功能的函数
    void setActivationOrder(QMdiArea::WindowOrder order);
    void setSubWidgetsKeyboardSingleStep(int step);
    void setSubWidgetsKeyboardPageStep(int step);
};

#endif // WIDGET_H
