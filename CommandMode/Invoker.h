#ifndef INVOKER_H
#define INVOKER_H

#pragma once
#include <list>
#include <QList>
#include <QTime>
#include <QThread>
#include <QCoreApplication>
#include <QEventLoop>

#include "ICommand.h"

/************* 命令执行序列 *************/
class Invoker
{
public:
    Invoker();
    ~Invoker();
    void AddCmd(ICommand* cmd);
    void RemoveCmd(ICommand* cmd);
    void excuteCommands();
    void reExcuteCommands();

    bool redo();
    bool undo();

    QStringList generateXmlSequece();

private:
    int index;//当前下标
    QList<ICommand*> cmd_list;
};

#endif // INVOKER_H
