#ifndef PARSEXML_H
#define PARSEXML_H
#include "pugixml.hpp"
#include <QString>

#include <QtCore/qglobal.h>

#if defined(PARSEXML_LIBRARY)
#  define PARSEXMLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PARSEXMLSHARED_EXPORT Q_DECL_IMPORT
#endif


//专业术语: XPath 是一门在 XML 文档中查找信息的语言。XPath 用于在 XML 文档中通过元素和属性进行导航。
using namespace pugi;

class Parsexml
{
public:
    enum INSERT_FLAG
    {
        INSERT_AFTER_HEAD=0,    //在当前元素里开头插入 --- 儿子节点
        INSERT_BEFORE_TAIL,     //在当前元素里末尾插入 --- 儿子节点
        INSERT_BEFORE,          //在当前元素之前插入 --- 兄弟节点
        INSERT_AFTER            //在当前元素之后插入 --- 兄弟节点
    };

    Parsexml();
    ~Parsexml();

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
    bool saveFile(const QString &path, bool isCover=true) const;
    bool saveFile(bool isCover=true) const;

    /**
     * @brief 查询节点对应的所有元素
     * @param[in] xPath
     * @param[out] queryResults
     * @return 成功返回true，失败返回false
     */
    bool queryElement(const QString xPath, QStringList &queryResults) const;

    /**
     * @brief 查询元素文本
     * @param[in] xPath
     * @param[out] 返回的结果
     * @return 成功返回true，失败返回false
     */
    bool queryElementText(const QString xPath, QStringList &queryResults) const;
    /**
     * @brief 查询当前节点下所有子节点文本，注:不包括孙子节点
     * @param[in] xPath
     * @param[out] 返回查询到的子节点所有文本
     * @return 成功返回true，失败返回false
     */
    bool queryElementMap(const QString xPath,QList<QMap<QString,QString> > &queryResults) const;

    /**
     * @brief 查询属性对应的值
     * @param[in] xPath
     * @param[in] 要查询的属性名称
     * @param[out] 返回查询到的当前节点所有同名元素的属性所对应的值
     * @return 成功返回true，失败返回false
     */
    bool queryAttribute(const QString xPath,QString attributeName, QStringList &queryResults) const;

    /**
     * @brief 查询当前节点所有属性名称值
     * @param[in] xPath
     * @param[out] 返回查询到的属性名称和属性值
     * @return 成功返回true，失败返回false
     */
    bool queryAttributes(const QString xPath,QList<QMap<QString,QString> > &queryResults) const;


    xpath_node_set selectNodes(const QString xPath) const;
    xpath_node selectNode(const QString xPath) const;
    xpath_node getRootNode() const;
    //====================================================以下操作需要调用saveFile保存XML文件================================================

    /**
     * @brief 删除元素
     * @param[in] xPath
     * @return 成功返回true，失败返回false
     */
    bool deleteElement(const QString xPath) const;

    /**
     * @brief 删除元素中的一个属性值
     * @param[in] xPath
     * @param[in] 要删除的节点
     * @return 成功返回true，失败返回false
     */
    bool deleteAttribute(const QString xPath,QString attributeName) const;

    /**
     * @brief 向元素中插入一个属性值
     * @param[in] xPath
     * @param[in] 需要插入的属性名称
     * @param[in] 需要插入的属性值
     * @return 成功返回true，失败返回false
     */
    bool insertAttribute(const QString xPath,QString attributeName,QString attributeValue) const;

    /**
     * @brief 插入一个元素节点
     * @param[in] xPath
     * @param[in] 要插入的节点内容 例如<a id=1>insert</a>
     * @param[in] 插入的位置,请参考 枚举:INSERT_FLAG
     * @return 成功返回true，失败返回false
     */
    bool insertElement(const QString xPath,QString elementContent,INSERT_FLAG flag=INSERT_AFTER_HEAD) const;

    /**
     * @brief 更新元素的内容
     * @param[in] xPath
     * @param[in] 需要更新的节点内容，例如<a id=1>insert</a>
     * @return 成功返回true，失败返回false
     */
    bool updateElementContent(const QString xPath,QString newContent) const;

    /**
     * @brief 修改一个属性的值
     * @param[in] xPath
     * @param[in] 属性名
     * @param[in] 属性值
     * @return 成功返回true，失败返回false
     */
    bool modifyAttribute(const QString xPath,QString attributeName, QString attributeValue) const;

    /**
     * @brief 修改元素的文本
     * @param[in] xPath
     * @param[in] 文本内容
     * @return 成功返回true，失败返回false
     */
    bool modifyElementText(const QString xPath,QString elementText) const;



private:
    mutable QString m_Path;
    pugi::xml_document *m_pDoc;
};

#endif // PARSEXML_H
