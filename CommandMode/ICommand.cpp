#include "ICommand.h"

/************* 命令基类 *************/

ICommand::ICommand(QGraphicsItem *item):graphicsItem(item){}

ICommand::~ICommand(){}

/************* 具体命令 *************/

CmdRotate::CmdRotate(QGraphicsItem *item, int angle):
    ICommand(item)
{
    pm.angle = angle;
}

void CmdRotate::excute()
{
    qDebug() << "CmdRotate excute";
    graphicsItem->setRotation(pm.angle);

}

void CmdRotate::reverse()
{
    qDebug() << "CmdRotate reverse";
    graphicsItem->setRotation(-pm.angle);
}

QString CmdRotate::generateXmlNode()
{
    QString xmlNode = QString("ICommand:") + "rotate=" + QString::number(this->pm.angle) + "," + "trans=''" + "scale=''";
    return xmlNode;
}

CmdTranslation::CmdTranslation(QGraphicsItem *item, QTransform transform):
    ICommand(item)
{
    pm.trans = transform;
}

void CmdTranslation::excute()
{
    qDebug() << "CmdTranslation excute";
//    QList<QGraphicsTransform *> transFromlist;
//    graphicsItem->setTransformations(transFromlist);
}

void CmdTranslation::reverse()
{
    qDebug() << "CmdTranslation reverse";
    //    QList<QGraphicsTransform *> transFromlist;
    //    graphicsItem->setTransformations(transFromlist);
}

QString CmdTranslation::generateXmlNode()
{
    QString xmlNode = QString("ICommand:") + "rotate=''"  + "," + "trans=''" + "scale=''";
    return xmlNode;
}

CmdScale::CmdScale(QGraphicsItem *item, int scale):
    ICommand(item)
{
    pm.scale = scale;
}

void CmdScale::excute()
{
    qDebug() << "CmdScale excute";
    graphicsItem->setScale(pm.scale);
}

void CmdScale::reverse()
{
    qDebug() << "CmdScale reverse";
//    graphicsItem->setScale(1/scale);
    graphicsItem->setScale(1);
}

QString CmdScale::generateXmlNode()
{
    QString xmlNode = QString("ICommand:") + "rotate='',"  + "," + "trans=''" + "scale="+ QString::number(this->pm.angle);
    return xmlNode;
}
