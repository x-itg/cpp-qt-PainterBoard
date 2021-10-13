#include "Invoker.h"

Invoker::Invoker()
{
    index = 0;
}


Invoker::~Invoker()
{
}

void Invoker::AddCmd(ICommand* cmd)
{
    cmd_list.insert(index++, cmd);
}

void Invoker::RemoveCmd(ICommand* cmd)
{
    cmd_list.removeOne(cmd);
    if(index > 0)
        index--;
}

void Invoker::excuteCommands()
{
    QList<ICommand*>::iterator it = cmd_list.begin();
    for (;it!=cmd_list.end();it++)
    {

        QTime dieTime = QTime::currentTime().addMSecs(1000);
        while( QTime::currentTime() <dieTime )
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 500);
        }

        (*it)->excute();
    }
}

void Invoker::reExcuteCommands()
{
    QList<ICommand*>::iterator it = cmd_list.end();
    it--;
    do{
        QTime dieTime = QTime::currentTime().addMSecs(500);
        while( QTime::currentTime() <dieTime )
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }

        (*it)->reverse();
    }
    while (it--!=cmd_list.begin());
}

bool Invoker::redo()
{
    if(index == 0)
        return false;

    this->cmd_list.at(index)->reverse(/* xml中或者内存中的操作结构体数据 */);
    if(index >= 1)
        index--;

    return true;
}

bool Invoker::undo()
{
    if(index < cmd_list.length()-1){
        cmd_list.at(index)->excute(/* xml中或者内存中的操作结构体数据 */);
    }
}

QStringList Invoker::generateXmlSequece()
{
    QStringList tmpList;
    for(auto i : cmd_list){
        tmpList.append(i->generateXmlNode());
    }
    return tmpList;
}
