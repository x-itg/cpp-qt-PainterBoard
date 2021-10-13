#include "HParseXml.h"


/*********************************************************************/

// tag::code[]
struct xml_string_writer: pugi::xml_writer
{
    std::string result;

    virtual void write(const void* data, size_t size)
    {
        result.append(static_cast<const char*>(data), size);
    }
};
// end::code[]

struct xml_memory_writer: pugi::xml_writer
{
    char* buffer;
    size_t capacity;

    size_t result;

    xml_memory_writer(): buffer(0), capacity(0), result(0)
    {
    }

    xml_memory_writer(char* buffer, size_t capacity): buffer(buffer), capacity(capacity), result(0)
    {
    }

    size_t written_size() const
    {
        return result < capacity ? result : capacity;
    }

    virtual void write(const void* data, size_t size)
    {
        if (result < capacity)
        {
            size_t chunk = (capacity - result < size) ? capacity - result : size;

            memcpy(buffer + result, data, chunk);
        }

        result += size;
    }
};

//std::string node_to_string(pugi::xml_node node)
//{
//    xml_string_writer writer;
//    node.print(writer);

//    return writer.result;
//}

QString node_to_string(pugi::xml_node node)
{
    xml_string_writer writer;
    node.print(writer);
    return QString(writer.result.data());
//    QString result = QString(QString::fromUtf8(writer.result.c_str()));;
//    return result;
}



char* node_to_buffer(pugi::xml_node node, char* buffer, size_t size)
{
    if (size == 0) return buffer;

    // leave one character for null terminator
    xml_memory_writer writer(buffer, size - 1);
    node.print(writer);

    // null terminate
    buffer[writer.written_size()] = 0;

    return buffer;
}

char* node_to_buffer_heap(pugi::xml_node node)
{
    // first pass: get required memory size
    xml_memory_writer counter;
    node.print(counter);

    // allocate necessary size (+1 for null termination)
    char* buffer = new char[counter.result + 1];

    // second pass: actual printing
    xml_memory_writer writer(buffer, counter.result);
    node.print(writer);

    // null terminate
    buffer[writer.written_size()] = 0;

    return buffer;
}


/*********************************************************************/

HParseXml::HParseXml()
{
    this->m_pDoc = new pugi::xml_document();
}

HParseXml::~HParseXml()
{
    delete m_pDoc;
}

bool HParseXml::loadFile(const QString &path) const
{
    QFile file(path);
    m_Path = path;

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return false;
    }

    /************/

    QTextStream vReadStream(&file);//生成文本流
    QString instruction = vReadStream.readLine().toLower();//读取第一行
    QString codec = instruction.split("encoding=\"").last();
    codec = codec.split("\"").first();//获得 编码方式

    QTextCodec *vCodec = QTextCodec::codecForName(codec.toUtf8().data());
    vReadStream.setCodec(vCodec);//文本流设置编码

    QString vXmlDataStr = vReadStream.readAll();//读出文本流
    file.close();

    /************/

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

bool HParseXml::loadString(const QString &contents) const
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

bool HParseXml::saveFile(const QString &path, bool isCover) const
{
    if(isCover){
        QFile::remove(path);
        m_pDoc->save_file(path.toUtf8());
        return true;
    }
    else {
        return false;
    }
}


bool HParseXml::writeFileTest(const QString &filename){
    pugi::xml_document doc;

    // tag::code[]
    // add node with some name
    pugi::xml_node iCommandList = doc.append_child("ICommandList");

    // add description node with text child
    for(int i = 0; i < 20; i++)
    {
        pugi::xml_node iCommand = iCommandList.append_child("ICommand");
        iCommand.append_child(pugi::node_pcdata).set_value("Simple node");
        iCommand.append_attribute("name") = "version";
        iCommand.append_attribute("value") = 1.1;
        iCommand.insert_attribute_after("type", iCommand.attribute("name")) = "float";

    }

    return doc.save_file(filename.toUtf8());
}

bool HParseXml::readFileTest(const QString &filename)
{
    pugi::xml_document doc;
    if (!doc.load_file(filename.toUtf8())) return false;

    pugi::xml_node items = doc.child("ICommandList");
    // tag::basic[]
    for (pugi::xml_node item = items.first_child(); item; item = item.next_sibling())
    {
        qDebug() << "ICommand:";

        for (pugi::xml_attribute attr = item.first_attribute(); attr; attr = attr.next_attribute())
        {
            qDebug() << " " << attr.name() << "=" << attr.value();
        }
    }
}



void HParseXml::test()
{
    /******************************* Accessing document data *********************************/
    {
//        pugi::xml_document doc;
//        if (!doc.load_file("commandTest.xml")) return;

//        pugi::xml_node items = doc.child("Items");
//        // tag::basic[]
//        for (pugi::xml_node item = items.first_child(); item; item = item.next_sibling())
//        {
//            qDebug() << "item:";

//            for (pugi::xml_attribute attr = item.first_attribute(); attr; attr = attr.next_attribute())
//            {
//                qDebug() << " " << attr.name() << "=" << attr.value();
//            }

//        }
//        // end::basic[]
    }


    {//手动找到 遍历节点  child 、 next_sibling 、attribute 、value 、 child_value
//        pugi::xml_document doc;
//        if (!doc.load_file("commandTest.xml")) return;

//        pugi::xml_node items = doc.child("Items");
//        // tag::data[]
//        for (pugi::xml_node item = items.child("Item"); item; item = item.next_sibling("Item"))
//        {
//            qDebug() << item.attribute("shapeName").value() << ":" << item.attribute("penColor").value();
//            qDebug() << item.attribute("shapeName").value() << ":" << item.attribute("brushColor").as_bool();
//            qDebug() << item.attribute("shapeName").value() << ":" << item.attribute("width").as_int();
//            qDebug() << item.attribute("shapeName").value() << ":" << item.child_value("Command") << "'\n";
//        }
//        // end::data[]
    }


    {//找到节点 通过 条件   find_child_by_attribute
//        pugi::xml_document doc;
//        if (!doc.load_file("commandTest.xml")) return;

//        pugi::xml_node items = doc.child("Items");
//        // tag::contents[]
//        qDebug() << "item for green generation: " << items.find_child_by_attribute("Item", "penColor", "green").attribute("shapeName").value() << "\n";

//        for (pugi::xml_node item = items.child("Item"); item; item = item.next_sibling("Item"))
//        {
//            qDebug() << "item " << item.attribute("shapeName").value() << item.attribute("penColor").value();
//        }
//        // end::contents[]
    }


    {//自动便利  x节点的孩子节点(共两层)  begin,end 、 name 、 value
//        pugi::xml_document doc;
//        if (!doc.load_file("commandTest.xml")) return;

//        pugi::xml_node items = doc.child("Items");
//        // tag::code[]
//        for (pugi::xml_node_iterator it = items.begin(); it != items.end(); ++it)
//        {
//            qDebug() << "Item:";

//            for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
//            {
//                qDebug() << " " << ait->name() << "=" << ait->value();
//            }
//            qDebug();
//        }
//        // end::code[]
    }


    {//自动便利 x节点的孩子节点的孩子节点(共三层) children 、 attributes 、 text
//        pugi::xml_document doc;
//        if (!doc.load_file("commandTest.xml")) return;

//        pugi::xml_node items = doc.child("Items");

//        // tag::code[]
//        for (pugi::xml_node item: items.children("Item"))
//        {
//            qDebug() << "Item:";

//            for (pugi::xml_attribute attr: item.attributes())
//            {
//                qDebug() << " " << attr.name() << "=" << attr.value();
//            }

//            for (pugi::xml_node child: item.children())
//            {
//                qDebug() << "child " << child.name() << child.text().data().value();
//                for (pugi::xml_attribute_iterator ait = child.attributes_begin(); ait != child.attributes_end(); ++ait) {
//                    qDebug() << " " << ait->name() << "=" << ait->value();
//                }
//            }
//        }
//        // end::code[]
    }


    {// xpath  select_node:  "/Items/Item[@penColor='red']"  ,  "//Item[contains(Command, 'miao')]"
//        pugi::xml_document doc;
//        if (!doc.load_file("commandTest.xml")) return;

//        pugi::xpath_node_set items = doc.select_nodes("/Items/Item[@penColor='red']");
//        qDebug() << "Items:";
//        for (pugi::xpath_node_set::const_iterator it = items.begin(); it != items.end(); ++it)
//        {
//            pugi::xpath_node node = *it;
//            qDebug() << node.node().attribute("shapeName").value();
//        }
//        qDebug();
//        pugi::xpath_node build_tool = doc.select_node("//Item[contains(Command, 'miao')]");

//        if (build_tool)
//            qDebug() << "Build item: " << build_tool.node().attribute("shapeName").value();
    }

    /******************************* Modifying document data *********************************/

    {//修改 node 修改 comment 修改 attribute:  set_name,set_value;   last_child,
//        pugi::xml_document doc;
//        if (!doc.load_string("<node id='123'>text</node><!-- comment -->", pugi::parse_default | pugi::parse_comments)) return;

//        // tag::node[]
//        pugi::xml_node node = doc.child("node");

//        // change node name
//        qDebug() << node.set_name("notnode");
//        qDebug() << ", new node name: " << node.name();

//        // change comment text
//        qDebug() << doc.last_child().set_value("useless comment");
//        qDebug() << ", new comment text: " << doc.last_child().value();

//        // we can't change value of the element or name of the comment
//        qDebug() << node.set_value("1") << ", " << doc.last_child().set_name("2");
//        // end::node[]

//        // tag::attr[]
//        pugi::xml_attribute attr = node.attribute("id");

//        // change attribute name/value
//        qDebug() << attr.set_name("key") << ", " << attr.set_value("345");
//        qDebug() << ", new attribute: " << attr.name() << "=" << attr.value();

//        // we can use numbers or booleans
//        attr.set_value(1.234);
//        qDebug() << "new attribute value: " << attr.value();

//        // we can also use assignment operators for more concise code
//        attr = true;
//        qDebug() << "final attribute value: " << attr.value();
//        // end::attr[]
    }


    {//写 xml :  append_child,append_attribute,  insert_child_before, insert_attribute_after, set_value
//        pugi::xml_document doc;

//        // tag::code[]
//        // add node with some name
//        pugi::xml_node node = doc.append_child("node");

//        // add description node with text child
//        pugi::xml_node descr = node.append_child("description");
//        descr.append_child(pugi::node_pcdata).set_value("Simple node");

//        // add param node before the description
//        pugi::xml_node param = node.insert_child_before("param", descr);

//        // add attributes to param node
//        param.append_attribute("name") = "version";
//        param.append_attribute("value") = 1.1;
//        param.insert_attribute_after("type", param.attribute("name")) = "float";
//        // end::code[]

//        doc.save_file("modify_add.xml");
    }


    {//modify_remove : remove_child, remove_attribute
//        pugi::xml_document doc;
//        if (!doc.load_string("<node> <description>Simple node</description> <param name='id' value='123'/></node>")) return;

//        // tag::code[]
//        // remove description node with the whole subtree
//        pugi::xml_node node = doc.child("node");
//        node.remove_child("description");

//        // remove id attribute
//        pugi::xml_node param = node.child("param");
//        param.remove_attribute("value");

//        // we can also remove nodes/attributes by handles
//        pugi::xml_attribute id = param.attribute("name");
//        param.remove_attribute(id);
//        // end::code[]

//        doc.save_file("modify_remove.xml");
    }

    /******************************* Modifying document data *********************************/

    {// save_custom_writer
//        // get a test document
//        pugi::xml_document doc;
//        doc.load_string("<foo bar='baz'>hey</foo>");

//        // get contents as std::string (single pass)
//       qDebug().noquote() << "contents: " << node_to_string(doc);

//        // get contents into fixed-size buffer (single pass)
//        char large_buf[128];
//        qDebug() << "contents: " << node_to_buffer(doc, large_buf, sizeof(large_buf));

//        // get contents into fixed-size buffer (single pass, shows truncating behavior)
//        char small_buf[22];
//        qDebug() << "contents: " << node_to_buffer(doc, small_buf, sizeof(small_buf));

//        // get contents into heap-allocated buffer (two passes)
//        char* heap_buf = node_to_buffer_heap(doc);
//        qDebug() << "contents: " << heap_buf;
//        delete[] heap_buf;
    }
}

