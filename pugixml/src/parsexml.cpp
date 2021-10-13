#include "parsexml.h"
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include <QDebug>


struct xml_string_writer: pugi::xml_writer
{
    std::string result;

    virtual void write(const void* data, size_t size)
    {
        result.append(static_cast<const char*>(data), size);
    }
};

Parsexml::Parsexml()
{
    this->m_pDoc = new pugi::xml_document();
}

Parsexml::~Parsexml()
{
    delete this->m_pDoc;
}

/************************************************************************/
/* loadFile                                                             */
/************************************************************************/
bool Parsexml::loadFile(const QString &path) const
{
    QFile file(path);
    m_Path = path;

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return false;
    }


    QTextStream vReadStream(&file);//生成文本流
    QString instruction = vReadStream.readLine().toLower();
    QString codec = instruction.split("encoding=\"").last();
    codec = codec.split("\"").first();//获得 编码方式
    QTextCodec *vCodec = QTextCodec::codecForName(codec.toUtf8().data());
    vReadStream.setCodec(vCodec);//文本流设置编码
    QString vXmlDataStr = vReadStream.readAll();//读出文本流
    file.close();


    pugi::xml_parse_result res = m_pDoc->load_string(vXmlDataStr.toUtf8());

    if (res.status == pugi::status_ok)
    {
        return true;
    }
    else
    {
        qDebug() << "Load file error: " << res.description();
        return false;
    }
}
bool Parsexml::loadString(const QString &contents) const
{
    pugi::xml_parse_result res = m_pDoc->load_string(contents.toUtf8());
    // add a custom declaration node
    pugi::xml_node decl = m_pDoc->prepend_child(pugi::node_declaration);
    decl.append_attribute("version") = "1.0";
    decl.append_attribute("encoding") = "UTF-8";

    if (res.status == pugi::status_ok)
    {
        return true;
    }
    else
    {
        qDebug() << "Load file error: " << res.description();
        return false;
    }
}

/************************************************************************/
/* saveFile                                                             */
/************************************************************************/
bool Parsexml::saveFile(const QString &path, bool isCover) const
{
    if(isCover)
    {
        QFile::remove(path);//删除文件
    }
    return m_pDoc->save_file(path.toUtf8());
}

bool Parsexml::saveFile(bool isCover) const
{
    if(isCover)
    {
        QFile::remove(m_Path);
    }
    return m_pDoc->save_file(m_Path.toUtf8());
}

/************************************************************************/
/* deleteAttribute                                                      */
/************************************************************************/
bool Parsexml::deleteAttribute(const QString xPath, QString attributeName)  const
{
    try
    {
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();

            //pugi::xml_attribute attr = node.attribute(attributeName.toUtf8());
            while (node.remove_attribute(attributeName.toUtf8()));
        }

        if (root.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* deleteElement                                                        */
/************************************************************************/
bool Parsexml::deleteElement(const QString xPath) const
{
    try
    {
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        if (root.empty())
        {
            return true;//路径不存在也返回成功
        }

        bool res = false;

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();

            if(node.parent().remove_child(node))
            {
                res = true;
            }
        }

        if (root.size() && res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* insertAttribute                                                      */
/************************************************************************/
bool Parsexml::insertAttribute(const QString xPath, QString attributeName, QString attributeValue) const
{
    try
    {
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();

            QByteArray ba = attributeValue.toUtf8();
            char * value = ba.data();

            pugi::xml_attribute attr = node.attribute(attributeName.toUtf8());

            if (attr)
            {
                if (!attr.set_value(value))
                {
                    return false;
                }
            }
            else
            {
                if(!node.append_attribute(attributeName.toUtf8()).set_value(value))
                {
                    return false;
                }
            }
        }

        return true;
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* insertElement                                                        */
/************************************************************************/
bool Parsexml::insertElement(const QString xPath, QString elementContent, INSERT_FLAG flag/*=INSERT_AFTER_HEAD*/) const
{
    try
    {
        bool res = false;
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        pugi::xml_document new_doc;
        new_doc.load_string(elementContent.toUtf8());

        //pugi::xml_node child = m_pDoc->first_child();

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();

            for (pugi::xml_node child = new_doc.first_child(); child; child = child.next_sibling())
            {
                switch(flag)
                {
                case Parsexml::INSERT_AFTER_HEAD:
                {
                    //if(node.prepend_child(pugi::node_pcdata).set_value(elementContent.toUtf8()))
                    if(node.prepend_copy(child))
                    {
                        res = true;
                    }

                    break;
                }

                case Parsexml::INSERT_BEFORE_TAIL:
                {
                    //if(node.append_child(pugi::node_pcdata).set_value(elementContent.toUtf8()))
                    if(node.append_copy(child))
                    {
                        res = true;
                    }

                    break;
                }

                case  Parsexml::INSERT_BEFORE:
                {
                    pugi::xml_node parent_node = node.parent();

                    if(parent_node.insert_copy_before(child, node))
                    {
                        res = true;
                    }

                    break;
                }

                case  Parsexml::INSERT_AFTER:
                {
                    pugi::xml_node parent_node = node.parent();

                    if(parent_node.insert_copy_after(child, node))
                    {
                        res = true;
                    }

                    break;
                }
                }
            }
        }

        if (root.size() && res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* modifyAttribute                                                      */
/************************************************************************/
bool Parsexml::modifyAttribute(const QString xPath, QString attributeName, QString attributeValue) const
{
    try
    {
        bool res = false;
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();
            QByteArray ba = attributeValue.toUtf8();
            char * value = ba.data();
            //char * value = attributeValue.toUtf8().data();

            if (node.attribute(attributeName.toUtf8()).empty())
            {
                if(node.append_attribute(attributeName.toUtf8()).set_value(value))
                {
                    res = true;
                }
            }
            else
            {
                if (node.attribute(attributeName.toUtf8()).set_value(value))
                {
                    res = true;
                }
            }
        }

        if (root.size() && res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* modifyElementText                                                    */
/************************************************************************/
bool Parsexml::modifyElementText(const QString xPath, QString elementText) const
{
    try
    {
        bool res = false;
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();
            QByteArray ba = elementText.toUtf8();
            char* value = ba.data();

            if(node.text().set(value))
            {
                res = true;
            }
        }

        if (root.size() && res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* queryAttribute                                                       */
/************************************************************************/
bool Parsexml::queryAttribute(const QString xPath, QString attributeName, QStringList &queryResults) const
{
    try
    {
        bool res = false;
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();
            pugi::xml_attribute attr = node.attribute(attributeName.toUtf8());

            if (attr)
            {
                res = true;
                QString queryResult = QString::fromUtf8(attr.value());
                queryResults.append(queryResult);
            }
        }

        if (root.size() && res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* queryAttributes                                                      */
/************************************************************************/
bool Parsexml::queryAttributes(const QString xPath, QList<QMap<QString, QString>> &queryResults) const
{
    try
    {
        //xPath.replace("\"","'");
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xpath_node node = *it;
            QMap<QString, QString> map;

            for (pugi::xml_attribute_iterator attr_it = node.node().attributes_begin(); attr_it != node.node().attributes_end(); ++attr_it)
            {
                map.insert(QString::fromUtf8(attr_it->name()), QString::fromUtf8(attr_it->value()));
            }

            queryResults.append(map);
        }

        if (root.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

xpath_node_set Parsexml::selectNodes(const QString xPath) const
{
    return m_pDoc->select_nodes(xPath.toUtf8());
}

xpath_node Parsexml::selectNode(const QString xPath) const
{
    return m_pDoc->select_node(xPath.toUtf8());
}

xpath_node Parsexml::getRootNode() const
{
    return m_pDoc->root();
}

/************************************************************************/
/* queryElement                                                         */
/************************************************************************/
bool Parsexml::queryElement(const QString xPath, QStringList &queryResults) const
{
    try
    {
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xpath_node node = *it;
            xml_string_writer writer;
            node.node().print(writer);

            QString result = QString(QString::fromUtf8(writer.result.c_str()));
            queryResults.append(result);
        }

        if (root.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* queryElementText                                                     */
/************************************************************************/
bool Parsexml::queryElementText(const QString xPath, QStringList &queryResults) const
{
    try
    {
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xpath_node node = *it;
            QString result = QString::fromUtf8(node.node().child_value());
            queryResults.append(result);
        }

        if (root.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* queryElementMap                                                      */
/************************************************************************/
bool Parsexml::queryElementMap(const QString xPath,QList<QMap<QString,QString>> &queryResults) const
{
    try
    {
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xpath_node node = *it;
            QMap<QString,QString> map;

            for (pugi::xml_node child = node.node().first_child(); child; child = child.next_sibling())
            {
                QString tagName = QString::fromUtf8(child.name());
                QString tagText = QString::fromUtf8(child.child_value());
                map.insert(tagName,tagText);
            }

            queryResults.append(map);
        }

        if (root.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}

/************************************************************************/
/* updateElementContent                                                 */
/************************************************************************/
bool Parsexml::updateElementContent(const QString xPath, QString newContent) const
{
    try
    {
        bool res = false;
        pugi::xpath_node_set root = m_pDoc->select_nodes(xPath.toUtf8());

        for (pugi::xpath_node_set::const_iterator it = root.begin(); it != root.end(); ++it)
        {
            pugi::xml_node node = (*it).node();
            pugi::xml_document doc;

            if(m_pDoc->load_string(newContent.toUtf8()))
            {
                //node = m_pDoc->first_child();
                for (pugi::xml_node child = m_pDoc->first_child(); child; child = child.next_sibling())
                {
                    if(node.parent().insert_copy_after(child, node))
                    {
                        res = true;
                    }
                }

                if (res)
                {
                    node.parent().remove_child(node);
                }
            }
        }

        if (root.size() && res)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch(const pugi::xpath_exception& e)
    {
        qDebug() << QString("Select %1 failed: ").arg(xPath) << e.what();
        return false;
    }
}
