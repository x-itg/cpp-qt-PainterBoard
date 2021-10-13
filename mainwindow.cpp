#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"



/***** ribbon test *****/

/***** ribbon test *****/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    master(new XColorMaster),
    penWidthBox(new QSpinBox),
    penStyleBox(new QComboBox),
    m_pScene(nullptr),
    m_pView(nullptr),
    m_pCurrentScene(nullptr),
    m_pCurrentView(nullptr),
    spaceEdit(nullptr),
    timeEdit(nullptr),
    undoStack(nullptr),
    undoView(nullptr)
{
    ui->setupUi(this);

    setWindowTitle(" ");
    setWindowIcon(QIcon(":/qrc/drawBoard.png"));

    /**** undoView 插销重做窗口 ****/
    createUndoView();
//    testUndoView();


    /***/

    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::tabStateMode);
    setCentralWidget(&m_mdiArea);
    connect(&m_mdiArea, &HYMdiArea::subWindowActivated, this, [&](QMdiSubWindow *window){

        //取消关联当前窗口(即将成为历史窗口)信号槽
        if(m_pCurrentView)
            qDebug() << m_pCurrentView << __LINE__;
        HGraphicsScene::shapeType type;
        HGraphicsScene::sceneState state;
        QPen pen;

        if(m_pCurrentScene)
        {
            type = m_pCurrentScene->getShapeType();
            state = m_pCurrentScene->getSceneState();
            pen = m_pCurrentScene->pen;
        }
        else {
            type = HGraphicsScene::shapeType::handlePenType;
            state = HGraphicsScene::sceneState::DrawType;
        }

        //激活窗口关联信号槽
        if(m_mdiArea.hasSubWindow()){

            updateCurrentWindowViewScene();

            qDebug() << m_pCurrentView << __LINE__;

            m_pCurrentScene->setShapeType(type);
            m_pCurrentScene->setSceneState(state);
            m_pCurrentScene->pen = pen;

            ui->dockWidget_3->setWidget(m_pCurrentScene->undoView);
        }
        else {
            m_pCurrentView = nullptr;
            m_pCurrentScene = nullptr;
        }

    });

    /***************************************************************/

    //初始化菜单
    initToolMenu();
    ui->actiondraw->setChecked(true);
    ui->actionpen->setChecked(true);

    //初始化状态栏
    m_pViewPosLabel = new QLabel;
    ui->statusBar->addWidget(m_pViewPosLabel);
    /**************************** 图形视图 ***************************/
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createUndoView()
{
    undoStack = new QUndoStack(this);
    undoView = new QUndoView(undoStack);
    undoView->setWindowTitle(tr("Command List"));
    undoView->show();
    undoView->setAttribute(Qt::WA_QuitOnClose, false);
    ui->dockWidget_3->setWidget(undoView);
    ui->dockWidget_3->setFixedWidth(200);
}

void MainWindow::testUndoView(){
    QUndoCommand *testCommand = new TestCommand("测试一下");
    undoStack->push(testCommand);
    QUndoCommand *testCommand1 = new TestCommand("测试二下");
    undoStack->push(testCommand1);
    QUndoCommand *testCommand2 = new TestCommand("测试三下");
    undoStack->push(testCommand2);


    QUndoCommand *deleteCommand = new DeleteCommand("测试一下");
    undoStack->push(deleteCommand);
    QUndoCommand *deleteCommand1 = new DeleteCommand("测试二下");
    undoStack->push(deleteCommand1);
    QUndoCommand *deleteCommand2 = new DeleteCommand("测试三下");
    undoStack->push(deleteCommand2);
}

void MainWindow::initToolMenu(){

    //    setAutoFillBackground(true);
    //    setPalette(QPalette(Qt::black));

    //界面相关
    {//界面相关
        QToolBar * penToolBar = new QToolBar(this);
        this->addToolBar(Qt::TopToolBarArea, penToolBar);

        QToolBar * stateToolBar = new QToolBar(this);
        this->addToolBar(Qt::TopToolBarArea, stateToolBar);

        QToolBar * shapeToolBar = new QToolBar(this);
        this->addToolBar(Qt::TopToolBarArea, shapeToolBar);

        QToolBar * specialShapeToolBar = new QToolBar(this);
        this->addToolBar(Qt::TopToolBarArea, specialShapeToolBar);

        QToolBar * operationToolBar = new QToolBar(this);
        this->addToolBar(Qt::TopToolBarArea, operationToolBar);

        QToolBar * mdiAreaToolBar = new QToolBar(this);
        this->addToolBar(Qt::LeftToolBarArea, mdiAreaToolBar);

        QToolBar * animationToolBar = new QToolBar(this);
        this->addToolBar(Qt::LeftToolBarArea, animationToolBar);

        //多界面工具条
        {
            mdiAreaToolBar->addAction(ui->actiontab);
            mdiAreaToolBar->addAction(ui->actiontritab);
            mdiAreaToolBar->addAction(ui->actioncenter);
            mdiAreaToolBar->addAction(ui->actionellipseSubwin);
            mdiAreaToolBar->addAction(ui->action8);
            mdiAreaToolBar->addAction(ui->actioncascade);
            mdiAreaToolBar->addAction(ui->actiontitled);
            mdiAreaToolBar->addAction(ui->actionrandom);
            mdiAreaToolBar->addAction(ui->actionveritcal);
            mdiAreaToolBar->addAction(ui->actionhorizental);

        }

        {//动画工具条
            QFrame * timeWidget = new QFrame;
            timeWidget->setLineWidth(1);
            QVBoxLayout *layout = new QVBoxLayout;
            QLabel * timeLabel = new QLabel("动画持续(s):");
            timeEdit = new QLineEdit(QString::number(750));
            timeEdit->setFixedWidth(100);
            QRegExp regx("[0-9]+$");
            QValidator *validator = new QRegExpValidator(regx, timeEdit );
            timeEdit->setValidator( validator );
            layout->addWidget(timeLabel);
            layout->addWidget(timeEdit);
            timeWidget->setLayout(layout);
            animationToolBar->addWidget(timeWidget);
            connect(timeEdit, &QLineEdit::textEdited, [&](){
                m_mdiArea.setAnimationTime(timeEdit->text().toInt(), spaceEdit->text().toInt());
            });
            animationToolBar->addSeparator();



            QFrame * spaceWidget = new QFrame;
            QVBoxLayout *spacelayout = new QVBoxLayout;
            QLabel * spaceLabel = new QLabel("动画间隔(s):");
            spaceEdit = new QLineEdit(QString::number(25));
            spaceEdit->setFixedWidth(100);
            QRegExp spaceregx("[0-9]+$");
            QValidator *spacevalidator = new QRegExpValidator(spaceregx, spaceEdit );
            spaceEdit->setValidator( spacevalidator );
            spacelayout->addWidget(spaceLabel);
            spacelayout->addWidget(spaceEdit);
            spaceWidget->setLayout(spacelayout);
            animationToolBar->addWidget(spaceWidget);
            connect(spaceEdit, &QLineEdit::textEdited, [&](){
                m_mdiArea.setAnimationTime(timeEdit->text().toInt(), spaceEdit->text().toInt());
            });
            animationToolBar->addSeparator();



            QFrame * curveWidget = new QFrame;
            curveWidget->setLineWidth(1);
            QVBoxLayout *layout2 = new QVBoxLayout;
            QLabel * curveLabel = new QLabel("动画曲线:");
            QComboBox * curveEdit = new QComboBox();
            curveEdit->setFixedWidth(100);
            QStringList strList;
            strList << "线性" << "缓入缓出" << "InOutBack" << "OutInBack";
            curveEdit->addItems(strList);
            curveEdit->setCurrentText("InOutBack");
            layout2->addWidget(curveLabel);
            layout2->addWidget(curveEdit);
            curveWidget->setLayout(layout2);
            animationToolBar->addWidget(curveWidget);
            connect(curveEdit, QOverload<const QString &>::of(&QComboBox::activated), [&](const QString & text){
                if(text == "线性")
                    m_mdiArea.setAnimationCurveMode(QEasingCurve::Type::Linear);
                else if(text == "缓入缓出")
                    m_mdiArea.setAnimationCurveMode(QEasingCurve::Type::InOutQuint);
                else if(text == "InOutBack")
                    m_mdiArea.setAnimationCurveMode(QEasingCurve::Type::InOutBack);
                else if(text == "OutInBack")
                    m_mdiArea.setAnimationCurveMode(QEasingCurve::Type::OutInBack);
            });
            animationToolBar->addSeparator();



            QFrame * isAnimationWidget = new QFrame;
            isAnimationWidget->setLineWidth(1);
            QHBoxLayout *layout3 = new QHBoxLayout;
            QLabel * animaitonLabel = new QLabel("使用动画:");
            QCheckBox * animationEdit = new QCheckBox();
            layout3->addWidget(animaitonLabel);
            layout3->addWidget(animationEdit);
            layout3->addSpacing(10);
            isAnimationWidget->setLayout(layout3);
            animationToolBar->addWidget(isAnimationWidget);
            connect(animationEdit, &QCheckBox::clicked, [&](bool checked){
                m_mdiArea.setAnimationEnable(checked);
            });

        }

        //主工具条
        {
            ui->mainToolBar->addAction(ui->actionnew);
            ui->mainToolBar->addAction(ui->actionopen);
            ui->mainToolBar->addAction(ui->actionsave);
            ui->mainToolBar->addAction(ui->actionsave_as);
        }

        //画笔工具条
        {
            {//画笔宽度
                QHBoxLayout * hlayout = new QHBoxLayout;
                connect(penWidthBox,  QOverload<int>::of(&QSpinBox::valueChanged), this, [&](int value){
                    if(m_pCurrentScene)
                        m_pCurrentScene->pen.setWidth(value);
                });
                hlayout->addWidget(penWidthBox);
                penWidthBox->setValue(1);
                hlayout->setContentsMargins(10,10,10,10);
                QFrame * frameWidth = new QFrame;
                frameWidth->setLayout(hlayout);
                penToolBar->addWidget(frameWidth);
            }

            {//画笔颜色
                penToolBar->addAction(ui->actionboderColor);
            }

            penToolBar->addSeparator();

            {//颜色选择器
                connect(master, &XColorMaster::signalColorChanged, this, [&](QColor color){
                    qDebug() << color << __LINE__;
                    if(m_pCurrentScene)
                        m_pCurrentScene->brushColor = color;
                });
                master->setToolTip("brush color");
                QHBoxLayout * hlayout = new QHBoxLayout;
                hlayout->addWidget(master);
                master->ChangeColor(Qt::yellow);
                hlayout->setContentsMargins(10,10,10,10);
                QFrame * frameColor = new QFrame;
                frameColor->setLayout(hlayout);
                frameColor->setMinimumSize(40,40);
                penToolBar->addWidget(frameColor);
            }
        }

        //状态工具条
        {
            ui->actionmove->setCheckable(true);
            ui->actiondraw->setCheckable(true);

            stateToolBar->addAction(ui->actiondraw);
            stateToolBar->addAction(ui->actionmove);
        }

        //形状工具条
        {
            shapeToolBar->addAction(ui->actionpen);
            shapeToolBar->addAction(ui->actionstraight_line);
            shapeToolBar->addAction(ui->actionrect);
            shapeToolBar->addAction(ui->actiontriangle);
            shapeToolBar->addAction(ui->actionpoligon);
            shapeToolBar->addAction(ui->actionellipse);
            shapeToolBar->addAction(ui->actionbezier_curve);
            shapeToolBar->addAction(ui->actionBLine);
        }

        {//特殊形状工具条
            specialShapeToolBar->addAction(ui->actiontext);
            specialShapeToolBar->addAction(ui->actionpixmap);
        }

        //操作符工具条
        {
            operationToolBar->addAction(ui->actionundo);
            operationToolBar->addAction(ui->actionredo);

            operationToolBar->addAction(ui->actionmerge);
            operationToolBar->addAction(ui->actionapart);
        }
    }
}

void MainWindow::on_actionnew_triggered()
{
    m_pScene = new HGraphicsScene(-300, -300, 600, 600);//场景

    m_pView = new HGraphicsView(&m_mdiArea);
    m_pView->setScene(m_pScene);
    m_pView->setMouseTracking(true);//设置鼠标追踪)
    m_pView->setAlignment(/*Qt::AlignLeft | Qt::AlignTop*/ Qt::AlignCenter);

    /****/

    QMdiSubWindow * subWin = m_mdiArea.addSubWindow(m_pView, "新建");
    subWin->resize(300,300);
    subWin->show();
    updateCurrentWindowViewScene();
}

void MainWindow::on_actionopen_triggered()
{
    QString OpenFile;
    QImage image;
    QPixmap pixmap;

    OpenFile = QFileDialog::getOpenFileName(this,
                                            "please choose an image file",
                                            "",
                                            "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");

    if (OpenFile != "")
    {
        if (image.load(OpenFile))
            pixmap = QPixmap::fromImage(image).scaled(m_pCurrentView->size());//图片需要缩放
    }

    if(!pixmap.isNull())
    {
        HGraphicsPixmapItem * pixmapItem = new HGraphicsPixmapItem(QPixmap(pixmap));
        m_pCurrentScene->addItem(pixmapItem);
        QPointF viewPoint =  m_pCurrentView->mapToScene(0,0);//核心：从视图映射到场景,坐标以视图为准
        pixmapItem->setPos(viewPoint);
    }
}

void MainWindow::on_actionsave_triggered()
{
    qDebug() << "保存";

    QPixmap map = m_pCurrentView->grab();
    if(m_curSavePath.isEmpty()){//当前保存路径为空
        QString filename = QFileDialog::getSaveFileName(this,tr("Save Image"), "",
                                                        tr("*.bmp;; *.png;; *.jpg;; *.tif;; *.GIF")); //选择路径
        if (filename.isEmpty())
            return;
        else{

            if (!(map.save(filename))){
                QMessageBox::information(this,tr("Failed to save the pixmap"),tr("Failed to save the pixmap!"));
                return;
            }

        }
    }
    else {//当前保存路径存在
        if (!(map.save(m_curSavePath)))
            QMessageBox::information(this,tr("Failed to save the pixmap"),tr("Failed to save the pixmap!"));
    }
}

void MainWindow::on_actionsave_as_triggered()
{

    QPixmap map = m_pCurrentView->grab();
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Image"),
                                                    "",
                                                    tr("*.bmp;; *.png;; *.jpg;; *.tif;; *.GIF")); //选择路径
    if (filename.isEmpty())
        return;
    else{
        if (!(map.save(filename))){
            QMessageBox::information(this,tr("Failed to save the pixmap"),tr("Failed to save the pixmap!"));
            return;
        }
    }
}

void MainWindow::on_actionundo_triggered()
{
#if 0
    {//自定义撤销重做
        if(!m_pCurrentScene->items().isEmpty())
        {
            qDebug() << "回退";
            m_pCurrentScene->m_redoStack.push_back(m_pCurrentScene->items().first());//装入
            m_pCurrentScene->removeItem(m_pCurrentScene->items().first());//弹出
        }
        m_pCurrentScene->update();
    }
#else
    {//Qt 撤销重做
        if(!m_pCurrentScene->items().isEmpty())
        {
            m_pCurrentScene->undoStack->undo();
        }
        m_pCurrentScene->update();
    }
#endif
}

void MainWindow::on_actionredo_triggered()
{
#if 0
    {//自定义撤销重做
        qDebug() << "反回退";

        if(!m_pCurrentScene->m_redoStack.isEmpty()){
            m_pCurrentScene->addItem(m_pCurrentScene->m_redoStack.pop());//装入
        }
        m_pCurrentScene->update();
    }
#else
    {//Qt 官方撤销重做
        if(!m_pCurrentScene->items().isEmpty())
        {
            m_pCurrentScene->undoStack->redo();
        }
        m_pCurrentScene->update();
    }
#endif
}

void MainWindow::on_actionpen_triggered()
{
    if(ui->actionpen->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::handlePenType);

        ui->actionstraight_line->setChecked(false);
        ui->actionrect->setChecked(false);
        ui->actiontriangle->setChecked(false);
        ui->actionellipse->setChecked(false);
        ui->actionpoligon->setChecked(false);
        ui->actionbezier_curve->setChecked(false);
        ui->actionBLine->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }

    qDebug() << __FUNCTION__ << __LINE__;
}

void MainWindow::on_actionrect_triggered()
{
    if(ui->actionrect->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::rectType);

        ui->actionpen->setChecked(false);
        ui->actionstraight_line->setChecked(false);
        ui->actiontriangle->setChecked(false);
        ui->actionellipse->setChecked(false);
        ui->actionpoligon->setChecked(false);
        ui->actionbezier_curve->setChecked(false);
        ui->actionBLine->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }

    qDebug() << __FUNCTION__ << __LINE__;
}

void MainWindow::on_actiontriangle_triggered()
{
    if(ui->actiontriangle->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::triangleType);

        ui->actionpen->setChecked(false);
        ui->actionstraight_line->setChecked(false);
        ui->actionrect->setChecked(false);
        ui->actionellipse->setChecked(false);
        ui->actionpoligon->setChecked(false);
        ui->actionbezier_curve->setChecked(false);
        ui->actionBLine->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }

    qDebug() << __FUNCTION__ << __LINE__;
}

void MainWindow::on_actionellipse_triggered()
{
    if(ui->actionellipse->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::ellipseType);

        ui->actionpen->setChecked(false);
        ui->actionstraight_line->setChecked(false);
        ui->actionrect->setChecked(false);
        ui->actiontriangle->setChecked(false);
        ui->actionpoligon->setChecked(false);
        ui->actionbezier_curve->setChecked(false);
        ui->actionBLine->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }

    qDebug() << __FUNCTION__ << __LINE__;
}

void MainWindow::on_actionbezier_curve_triggered()
{
    if(ui->actionbezier_curve->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::bezierType);

        ui->actionpen->setChecked(false);
        ui->actionstraight_line->setChecked(false);
        ui->actionrect->setChecked(false);
        ui->actiontriangle->setChecked(false);
        ui->actionellipse->setChecked(false);
        ui->actionpoligon->setChecked(false);
        ui->actionBLine->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }

    qDebug() << __FUNCTION__ << __LINE__;
}

void MainWindow::on_actionBLine_triggered()
{
    if(ui->actionBLine->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::bLineType);

        ui->actionpen->setChecked(false);
        ui->actionstraight_line->setChecked(false);
        ui->actionrect->setChecked(false);
        ui->actiontriangle->setChecked(false);
        ui->actionellipse->setChecked(false);
        ui->actionpoligon->setChecked(false);
        ui->actionbezier_curve->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }

    qDebug() << __FUNCTION__ << __LINE__;
}

void MainWindow::on_actionpoligon_triggered()
{
    qDebug() << __FUNCTION__ << __LINE__;
    if(ui->actionpoligon->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::poligenType);

        ui->actionpen->setChecked(false);
        ui->actionstraight_line->setChecked(false);
        ui->actionrect->setChecked(false);
        ui->actiontriangle->setChecked(false);
        ui->actionellipse->setChecked(false);
        ui->actionbezier_curve->setChecked(false);
        ui->actionBLine->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }
}

void MainWindow::on_actionstraight_line_triggered()
{
    if(ui->actionstraight_line->isChecked()){
        m_pCurrentScene->setShapeType(HGraphicsScene::shapeType::straightType);

        ui->actionpen->setChecked(false);
        ui->actionrect->setChecked(false);
        ui->actiontriangle->setChecked(false);
        ui->actionellipse->setChecked(false);
        ui->actionpoligon->setChecked(false);
        ui->actionbezier_curve->setChecked(false);
        ui->actionBLine->setChecked(false);
        ui->actionpixmap->setChecked(false);
        ui->actiontext->setChecked(false);
    }

    qDebug() << __FUNCTION__ << __LINE__;
}

void MainWindow::on_actiontext_triggered()
{
    HGraphicsTextItem *testText;

    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);


    if(m_pCurrentScene){
        if(m_pCurrentScene->selectedItems().length() == 1)
            testText = new HGraphicsTextItem(m_pCurrentScene->selectedItems().at(0));
        else
            testText = new HGraphicsTextItem(nullptr);
    }
    testText->setFont(font);
    m_pCurrentScene->addItem(testText);
    testText->setPlainText(tr("输入文字:"));
    testText->setPos(0, 0);
    testText->setTextInteractionFlags(Qt::TextEditable);
    testText->setTextInteractionFlags(Qt::TextEditorInteraction);//设置光标可以移动,比如方向键

}

void MainWindow::on_actionpixmap_triggered()
{
    QString OpenFile;
    QImage image;
    QPixmap pixmap;

    OpenFile = QFileDialog::getOpenFileName(this,
                                            "please choose an image file",
                                            "",
                                            "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");

    if (OpenFile != "")
    {
        if (image.load(OpenFile))
            pixmap = QPixmap::fromImage(image).scaled(600,600);//图片需要缩放
    }

    if(!pixmap.isNull())
    {
        HGraphicsPixmapItem * pixmapItem = new HGraphicsPixmapItem(QPixmap(pixmap));
        m_pCurrentScene->addItem(pixmapItem);
        QPointF viewPoint =  m_pCurrentView->mapToScene(0,0);//核心：从视图映射到场景,坐标以视图为准
        pixmapItem->setPos(-300,-300);

        pixmapItem->setAcceptHoverEvents(true);
        pixmapItem->setFlag(QGraphicsItem::ItemIsMovable);
        pixmapItem->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
        pixmapItem->setFlag(QGraphicsItem::ItemIsSelectable);
        pixmapItem->setFlag(QGraphicsItem::ItemIsFocusable);
    }
}

void MainWindow::on_actionmerge_triggered()
{
    //组合
    qDebug() << __FUNCTION__ << __LINE__;
    if(m_pCurrentScene)
    {
        int cnt= m_pCurrentScene->selectedItems().count();
        if (cnt>1)
        {
            QGraphicsItemGroup* group =new QGraphicsItemGroup; //创建组合
            m_pCurrentScene->addItem(group); //组合添加到场景中

            for (int i=0;i<cnt;i++)
            {
                QGraphicsItem* item=m_pCurrentScene->selectedItems().at(0);
                item->setSelected(false); //清除选择虚线框
                item->clearFocus();
                group->addToGroup(item); //添加到组合
            }
            group->setFlags(QGraphicsItem::ItemIsMovable
                            | QGraphicsItem::ItemIsSelectable
                            | QGraphicsItem::ItemIsFocusable);

            group->setZValue(++m_pCurrentScene->frontZ);

            m_pCurrentScene->clearSelection();
            group->setSelected(true);
        }
    }
}

void MainWindow::on_actionapart_triggered()
{
    //打散组合
    qDebug() << __FUNCTION__ << __LINE__;
    if(m_pCurrentScene)
    {
        int cnt=m_pCurrentScene->selectedItems().count();
        if (cnt==1)
        {
            QGraphicsItemGroup  *group;
            group=(QGraphicsItemGroup*)m_pCurrentScene->selectedItems().at(0);
            m_pCurrentScene->destroyItemGroup(group);
        }
    }
}

void MainWindow::on_actionmove_triggered()
{
    if(ui->actionmove->isChecked()){
        this->m_pCurrentScene->setSceneState(HGraphicsScene::sceneState::MoveType);
        ui->actiondraw->setChecked(false);
    }
}

void MainWindow::on_actiondraw_triggered()
{
    if(ui->actiondraw->isChecked())
    {
        this->m_pCurrentScene->setSceneState(HGraphicsScene::sceneState::DrawType);
        ui->actionmove->setChecked(false);
    }
}

void MainWindow::slotValueChanged(int width)
{
    this->m_pCurrentScene->pen.setWidth(width);
}

void MainWindow::on_actionboderColor_triggered()
{
    QColor color = QColorDialog::getColor();
    if(this->m_pCurrentScene){
        m_pCurrentScene->pen.setColor(color);
    }
}


void MainWindow::on_actionabout_Qt_triggered()
{
    QMessageBox::aboutQt(this, QString("关于Qt"));
}

void MainWindow::on_actionabout_drawBoard_triggered()
{
    QMessageBox::about(this, QString("使用方法"), QString("该画板目前一共有两种模式，但只会存在于一种模式：\n"
                                                      "一、绘制模式(F1):\n"
                                                      "    绘制模式中选择绘制图形：手绘、直线、三角形、圆形、矩形、多边形、钢笔曲线、B样条曲线，\n"
                                                      "然后通过鼠标左键右键来操作绘制。"
                                                      "二、编辑模式(F2):\n"
                                                      "    编辑模式每个图元支持的操作是不一样的，部分图元支持变形、旋转，右键编辑操作，部分不支持"
                                                      "文本和图片是不存在绘制模式和编辑模式。"
                                                      "快捷键：\n"
                                                      "F1(绘制模式)\n"
                                                      "F2(编辑模式)\n"
                                                      "Ctrl+S(保存)\n"
                                                      "Ctrl+O(打开)\n"
                                                      "Ctrl+X(回退)\n"
                                                      "Ctrl+Y(取消回退)\n"
                                                      "鼠标滚轮可以标量放大缩小图元,右键菜单可以复原"));
}

void MainWindow::updateCurrentWindowViewScene()
{
    QMdiSubWindow * subWin = m_mdiArea.getCurrentWindow();
    if(subWin->widget())
    {
        m_pCurrentView = dynamic_cast<HGraphicsView *>(subWin->widget());
        m_pCurrentScene = dynamic_cast<HGraphicsScene *>(m_pCurrentView->scene());
    }
}

void MainWindow::on_actiontab_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::tabStateMode, QSize(200,200));
}

void MainWindow::on_actiontritab_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::tabTriStateMode);
}

void MainWindow::on_actioncenter_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::centeredStateMode);
}

void MainWindow::on_actionellipseSubwin_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::ellipseStateMode);
}

void MainWindow::on_action8_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::figure8StateMode);
}

void MainWindow::on_actioncascade_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::cascadeStateMode);
}

void MainWindow::on_actiontitled_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::tiledStateMode);
}

void MainWindow::on_actionrandom_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::QrandomStateMode);
}

void MainWindow::on_actionveritcal_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::verticalStateMode);
}

void MainWindow::on_actionhorizental_triggered()
{
    m_mdiArea.setSubWindowViewMode(HMdiArea::SubWindowViewMode::horizentalStateMode);
}
