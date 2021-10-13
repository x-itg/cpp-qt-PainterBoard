#ifndef HPARSEXML_H
#define HPARSEXML_H

#include <QString>
#include <QDebug>
#include <QtWidgets>
#include "pugixml.hpp"


#include <iostream>


class HParseXml
{
private:
    mutable QString m_Path;//路径
    pugi::xml_document *m_pDoc;//xml节点

public:
    HParseXml();

    ~HParseXml();

    /**
     * @brief 加载XML对象
     * @param[in] 要打开的文本路径
     * @return 成功返回true，失败返回false
     */
    bool loadFile(const QString &path) const;
    bool loadString(const QString &contents) const;

    /**
     * @brief 保存XML
     * @param[in] 保存的路径
     * @param[in] 是否需要覆盖 覆盖=true,不覆盖=false
     * @return 成功返回true，失败返回false
     */
    bool saveFile(const QString &path, bool isCover = true) const;

    /************* Accessing document data **************/






    /************* test **************/
    void test();
    bool writeFileTest(const QString &filename);
    bool readFileTest(const QString &filename);
};

#endif // HPARSEXML_H
