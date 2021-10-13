#ifndef ICOMMAND_H
#define ICOMMAND_H

#pragma once
#include <iostream>
#include <QGraphicsItem>
#include <QString>
#include <QDebug>


typedef struct commandPara{
    int angle;
    QTransform trans;
    int scale;
}cmdParam;

using namespace std;

/************* 命令基类 *************/

class ICommand
{
public:
    ICommand(QGraphicsItem * item);
    virtual ~ICommand();
protected:
    QGraphicsItem * graphicsItem;//命令的对象(对象也是基类,对不同的对象做不同的处理)
    cmdParam pm;
public:
    virtual void excute() = 0;//操作
    virtual void reverse() = 0;//反向操作
    virtual QString generateXmlNode() = 0;//生成xml操作节点
};

/************* 具体命令 *************/

//class CmdAdd : public ICommand
//{
//public:
//    CmdAdd(QGraphicsItem * item);
//    void excute();
//    void reverse();
//    QString generateXmlNode();
//};


//class CmdRemove : public ICommand
//{
//public:
//    CmdRemove(QGraphicsItem * item);
//    void excute();
//    void reverse();
//    QString generateXmlNode();
//};



class CmdRotate : public ICommand
{
public:
    CmdRotate(QGraphicsItem * item, int angle);
    void excute();
    void reverse();
    QString generateXmlNode();
};


class CmdTranslation : public ICommand
{
public:
    CmdTranslation(QGraphicsItem * item, QTransform transform);
    void excute();
    void reverse();
    QString generateXmlNode();
};

class CmdScale:public ICommand
{
public:
    CmdScale(QGraphicsItem * item, int scale);
    void excute();
    void reverse();
    QString generateXmlNode();
};


#endif // ICOMMAND_H
