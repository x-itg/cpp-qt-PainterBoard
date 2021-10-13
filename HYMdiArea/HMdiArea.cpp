#include "HMdiArea.h"
#include "HMdiArea.h"
#include "HMdiArea.h"


//BUG： 当取消动画的时候，层叠不能正确层叠， bug

HMdiArea::HMdiArea(QWidget *parent, bool useAnimation) : QMdiArea (parent)
  ,useAnimation(useAnimation)
  ,curveMode(QEasingCurve::InOutBack)
  ,animationDurationTime(750)
  ,animationSubwinSpacingTime(0)
  ,subWindowItem(nullptr)
  ,groupTemp(nullptr)
  ,anim(nullptr)
  ,rootState(new QState)
  ,ellipseState(new QState(rootState))
  ,figure8State(new QState(rootState))
  ,randomState(new QState(rootState))
  ,tiledState(new QState(rootState))
  ,centeredState(new QState(rootState))
  ,cascadeState(new QState(rootState))
  ,horizentalState(new QState(rootState))
  ,verticalState(new QState(rootState))
  ,ellipseTrans(nullptr)
  ,figure8Trans(nullptr)
  ,randomTrans(nullptr)
  ,tiledTrans(nullptr)
  ,centeredTrans(nullptr)
  ,cascadeTrans(nullptr)
  ,horizentalTrans(nullptr)
  ,verticalTrans(nullptr)
  ,group(new QParallelAnimationGroup)
{
    isCloseSubWidget = true;
    initStateMachine();
}

HMdiArea::~HMdiArea()
{
}

bool HMdiArea::eventFilter(QObject *obj, QEvent *ev)
{
    if(QString(obj->metaObject()->className()) == "QMdiSubWindow" && (ev->type() == QEvent::Close) && !isCloseSubWidget)
    {
        QWidget * widget = dynamic_cast<QMdiSubWindow *>(obj)->widget();
        widget->setParent(nullptr);
        const_cast<QList<QObject *> *>(&dynamic_cast<QMdiSubWindow *>(obj)->children())->removeOne(widget);
        return true;
    }
    return false;
}

void HMdiArea::initStateMachine()
{
    setActivationOrder(QMdiArea::WindowOrder::StackingOrder);

    stateMachine.addState(rootState);
    stateMachine.setInitialState(rootState);//初始状态
    rootState->setInitialState(randomState);//根状态设置为中心状态

    stateMachine.start();
}

void HMdiArea::isUseAnimation(bool isUseAnimation)
{
    this->useAnimation = isUseAnimation;
}

QMdiSubWindow *HMdiArea::addSubWindow(QWidget *widget, Qt::WindowFlags windowFlags)
{
    QList<QMdiSubWindow *> subList = subWindowList();
    for(auto iter : subList)
    {
        if(iter->widget() == widget)
            return  iter;
    }

    QMdiSubWindow * subWin = QMdiArea::addSubWindow(widget, windowFlags);
    subWin->installEventFilter(this);
    return subWin;
}

void HMdiArea::updateStates()
{
    updateStateObjects();
    updateAnimationGroup();
}

void HMdiArea::updateStateObjects(){

    // Values 图片组状态设置
    int centerWidth = width()/2;
    int cenerHeight = height()/2;
    int count = subWindowList().count();

    for (int i = 0; i < count; ++i) {

        QMdiSubWindow *item = subWindowList().at(i);
        int itemCenterWidth = centerWidth - item->width()/2;
        int itemcenerHeigth = cenerHeight - item->height()/2;

        // Ellipse
        ellipseState->assignProperty(item, "pos", QPointF(itemCenterWidth + qCos((i / (qreal)(count)) * 6.28) * itemCenterWidth,
                                                          itemcenerHeigth + qSin((i / (qreal)(count)) * 6.28) * itemcenerHeigth));
        ellipseState->assignProperty(item, "size" , QSize(item->width(), item->height()));

        // Figure 8
        figure8State->assignProperty(item, "pos", QPointF(itemCenterWidth + qSin((i / (qreal)(count)) * 6.28) * itemCenterWidth,
                                                          itemcenerHeigth + qSin(((i * 2)/(qreal)(count)) * 6.28) * itemcenerHeigth));
        figure8State->assignProperty(item, "size" , QSize(item->width(), item->height()));

        // Random
        //randomState->assignProperty(item, "pos", QPointF(qrand() % itemCenterWidth * 2, qrand() % itemcenerHeigth * 2));//setGeometry 错误
        randomState->assignProperty(item, "pos", QPointF(qrand() % centerWidth * 2, qrand() % cenerHeight * 2));
        randomState->assignProperty(item, "size" , QSize(item->width(), item->height()));

        // Tiled
        qreal rCeil = ceil(sqrt(count));//上二次根
        int nCeil = (int)rCeil;//上二次根
        int columnCount = nCeil;
        int rowCount = count/nCeil;
        if(count%nCeil)
            rowCount ++;
        int atColumn = i%columnCount;
        int atRow = i/columnCount;
        int itemWidth = item->width();
        int itemHeigth = item->height();
        //求起始点
        tiledState->assignProperty(item, "pos", QPointF((qreal)centerWidth - ((qreal)(columnCount*itemWidth))/2 + (atColumn)*itemWidth,
                                                        (qreal)cenerHeight - ((qreal)(rowCount*itemHeigth))/2 + (atRow)*itemHeigth));
        tiledState->assignProperty(item, "size" , QSize(item->width(), item->height()));

        // Centered
        centeredState->assignProperty(item, "pos", QPointF(itemCenterWidth, itemcenerHeigth));
        centeredState->assignProperty(item, "size" , QSize(item->width(), item->height()));

        // cascadeState
        cascadeState->assignProperty(item, "pos", QPointF((width()/ count) * i + 1/* +1解决非动画界面 0,0位置不对 */, (height() / count) * i + 1/* +1解决非动画界面 0,0位置不对 */));
        qDebug() << "cascadeState" << i << width()/count * i << height()/count * i;
        cascadeState->assignProperty(item, "size" , QSize(item->width(), item->height()));

        // horizentalState
        horizentalState->assignProperty(item, "pos", QPointF(0 + (this->width()/count) * i, 0));
        horizentalState->assignProperty(item, "size" , QSize(this->width()/count, this->height()));

        // verticalState
        verticalState->assignProperty(item, "pos", QPointF(0, 0 + (this->height()/count) * i ));
        verticalState->assignProperty(item, "size" , QSize(this->width(), this->height()/count));
    }
    qDebug() << endl;
}

void HMdiArea::updateAnimationGroup(){

    //平行动画组
    groupTemp = new QParallelAnimationGroup;
    for (int i = 0; i < subWindowList().count(); ++i) {
        anim = new QPropertyAnimation(subWindowList()[i], "pos");
        anim->setDuration(animationDurationTime + i * animationSubwinSpacingTime);
        anim->setEasingCurve(curveMode);
        groupTemp->addAnimation(anim);
        anim = new QPropertyAnimation(subWindowList()[i], "size");
        anim->setDuration(animationDurationTime + i * animationSubwinSpacingTime);
        anim->setEasingCurve(curveMode);
        groupTemp->addAnimation(anim);


    }

    //清除原动画
    if(ellipseTrans)
        rootState->removeTransition(ellipseTrans);
    if(figure8Trans)
        rootState->removeTransition(figure8Trans);
    if(randomTrans)
        rootState->removeTransition(randomTrans);
    if(tiledTrans)
        rootState->removeTransition(tiledTrans);
    if(centeredTrans)
        rootState->removeTransition(centeredTrans);
    if(cascadeTrans)
        rootState->removeTransition(cascadeTrans);
    if(horizentalTrans)
        rootState->removeTransition(horizentalTrans);
    if(verticalTrans)
        rootState->removeTransition(verticalTrans);


    //添加动画
    ellipseTrans = rootState->addTransition(this, SIGNAL(ellipsePressed()), ellipseState);
    if(useAnimation)
        ellipseTrans->addAnimation(groupTemp);

    figure8Trans = rootState->addTransition(this, SIGNAL(figure8Pressed()), figure8State);
    if(useAnimation)
        figure8Trans->addAnimation(groupTemp);

    randomTrans = rootState->addTransition(this, SIGNAL(randomPressed()), randomState);
    if(useAnimation)
        randomTrans->addAnimation(groupTemp);

    tiledTrans = rootState->addTransition(this, SIGNAL(tiledPressed()), tiledState);
    if(useAnimation)
        tiledTrans->addAnimation(groupTemp);

    centeredTrans = rootState->addTransition(this, SIGNAL(centeredPressed()), centeredState);
    if(useAnimation)
        centeredTrans->addAnimation(groupTemp);

    cascadeTrans = rootState->addTransition(this, SIGNAL(cascadePressed()), cascadeState);
    if(useAnimation)
        cascadeTrans->addAnimation(groupTemp);

    horizentalTrans = rootState->addTransition(this, SIGNAL(horizentalPressed()), horizentalState);
    if(useAnimation)
        horizentalTrans->addAnimation(groupTemp);

    verticalTrans = rootState->addTransition(this, SIGNAL(verticalPressed()), verticalState);
    if(useAnimation)
        verticalTrans->addAnimation(groupTemp);

}

void HMdiArea::setSubWindowViewMode(SubWindowViewMode subMode){
    if(viewMode() != ViewMode::SubWindowView)
        setViewMode(ViewMode::SubWindowView);

    /**实现模式**/
    switch (subMode) {
    case SubWindowViewMode::tabStateMode:{
        setViewMode(ViewMode::TabbedView);
        setTabShape(QTabWidget::TabShape::Rounded);
    }break;
    case SubWindowViewMode::tabTriStateMode:{
        setViewMode(ViewMode::TabbedView);
        setTabShape(QTabWidget::TabShape::Triangular);
    }break;
    case SubWindowViewMode::ellipseStateMode:{
        emit(ellipsePressed());
    }break;
    case SubWindowViewMode::figure8StateMode:{
        emit(figure8Pressed());
    }break;
    case SubWindowViewMode::QrandomStateMode:{
        emit(randomPressed());
    }break;
    case SubWindowViewMode::tiledStateMode:{
        emit(tiledPressed());
    }break;
    case SubWindowViewMode::centeredStateMode:{
        emit(centeredPressed());
    }break;
    case SubWindowViewMode::cascadeStateMode:{
        emit(cascadePressed());
    }break;
    case SubWindowViewMode::horizentalStateMode:{
        emit(horizentalPressed());
    }break;
    case SubWindowViewMode::verticalStateMode:{
        emit(verticalPressed());
    }break;
    }
}

void HMdiArea::setIsCloseSubWidget(const bool flag)
{
    this->isCloseSubWidget = flag;
}
