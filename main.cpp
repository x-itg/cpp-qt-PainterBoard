#include "mainwindow.h"
#include "pugixml.hpp"
#include "HParseXml.h"

#include <iostream>
#include <QApplication>


#include "Invoker.h"
#include "ICommand.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 1


    MainWindow w;
    w.show();

#elif 1
    {
        Invoker* invo = new Invoker;

        QGraphicsRectItem * rectItem = new QGraphicsRectItem(QRectF(0,0,100,100), nullptr);
        QGraphicsEllipseItem * ellipseItem = new QGraphicsEllipseItem(QRectF(100,100,100,100), nullptr);

        QGraphicsScene * scene = new QGraphicsScene(QRectF(0, 0, 500, 500));
        QGraphicsView * view = new QGraphicsView(scene);

        scene->addItem(rectItem);
        scene->addItem(ellipseItem);

        view->show();

        ICommand* rotate_cmd = nullptr;
        ICommand* translation_cmd = nullptr;
        ICommand * scale_cmd = nullptr;

        rotate_cmd = new CmdRotate(rectItem, 30);
        invo->AddCmd(rotate_cmd);

        QTransform transform1(QMatrix(1,1,0,1,0,0));
        translation_cmd = new CmdTranslation(rectItem, transform1);
        invo->AddCmd(translation_cmd);

        scale_cmd = new CmdScale(rectItem, 2);
        invo->AddCmd(scale_cmd);

        rotate_cmd = new CmdRotate(ellipseItem, 30);
        invo->AddCmd(rotate_cmd);

        QTransform transform(QMatrix(1,1,0,1,0,0));
        translation_cmd = new CmdTranslation(ellipseItem, transform);
        invo->AddCmd(translation_cmd);

        scale_cmd = new CmdScale(ellipseItem,2);
        invo->AddCmd(scale_cmd);

//        invo->excuteCommands();

//        qDebug() << endl;
//        invo->reExcuteCommands();

        auto list = invo->generateXmlSequece();
        for(auto iter: list)
        {
            qDebug() << iter;
            //??如何通过 ICommand 生成 string(或者其他中间结构) 再生成 xml node ，如果反向通过 xml node 再生成 IComand
        }

        qDebug() << "==================" << __LINE__;

        //    SAFE_DELETE(scene);
        //    SAFE_DELETE(view);
        //    SAFE_DELETE(rectItem);
        //    SAFE_DELETE(ellipseItem);
        //    SAFE_DELETE(rotate_cmd);
        //    SAFE_DELETE(translation_cmd);
        //    SAFE_DELETE(invo);
    }
#elif 1
    HParseXml px;
//    qDebug() << px.loadFile("C:/Users/yiqiyong/Desktop/Project.xml");

//    qDebug() << px.loadString("<aaa><bb>哈哈哈</bb></aaa>");
//    qDebug() << px.loadString("<aaa></aaa><bb>哈哈哈</bb>");
//    px.saveFile(QString("haha.xml"), true);

//    px.test();
    px.writeFileTest("writeXmlTest.xml");
    px.readFileTest("writeXmlTest.xml");
#endif

    return a.exec();
}

