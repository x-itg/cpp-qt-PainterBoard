INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src

INCLUDEPATH += $$PWD/tests
DEPENDPATH += $$PWD/tests

HEADERS += $$PWD/src/pugiconfig.hpp \
           $$PWD/src/HParseXml.h \
           $$PWD/src/parsexml.h \
           $$PWD/src/pugixml.hpp

SOURCES += $$PWD/src/pugixml.cpp \
    $$PWD/src/HParseXml.cpp \
    $$PWD/src/parsexml.cpp



#HEADERS += $$PWD/tests/allocator.hpp \
#            $$PWD/tests/helpers.hpp \
#            $$PWD/tests/writer_string.hpp \
#            $$PWD/tests/test.hpp \

#SOURCES += $$PWD/tests/allocator.cpp \
#            $$PWD/tests/fuzz_parse.cpp \
#            $$PWD/tests/fuzz_xpath.cpp \
#            $$PWD/tests/test.cpp \
#            $$PWD/tests/test_compact.cpp \
#            $$PWD/tests/test_deprecated.cpp \
#            $$PWD/tests/test_document.cpp \
#            $$PWD/tests/test_dom_modify.cpp \
#            $$PWD/tests/test_dom_text.cpp \
#            $$PWD/tests/test_dom_traverse.cpp \
#            $$PWD/tests/test_header_guard.cpp \
#            $$PWD/tests/test_header_iosfwd_1.cpp \
#            $$PWD/tests/test_header_iosfwd_2.cpp \
#            $$PWD/tests/test_header_iostream_1.cpp \
#            $$PWD/tests/test_header_iostream_2.cpp \
#            $$PWD/tests/test_header_only_1.cpp \
#            $$PWD/tests/test_header_only_2.cpp \
#            $$PWD/tests/test_header_string_1.cpp \
#            $$PWD/tests/test_header_string_2.cpp \
#            $$PWD/tests/test_header_string_iostream.cpp \
#            $$PWD/tests/test_memory.cpp \
#            $$PWD/tests/test_parse.cpp \
#            $$PWD/tests/test_parse_doctype.cpp \
#            $$PWD/tests/test_unicode.cpp \
#            $$PWD/tests/test_version.cpp \
#            $$PWD/tests/test_write.cpp \
#            $$PWD/tests/test_xpath.cpp \
#            $$PWD/tests/test_xpath_api.cpp \
#            $$PWD/tests/test_xpath_functions.cpp \
#            $$PWD/tests/test_xpath_operators.cpp \
#            $$PWD/tests/test_xpath_parse.cpp \
#            $$PWD/tests/test_xpath_paths.cpp \
#            $$PWD/tests/test_xpath_paths_abbrev_w3c.cpp \
#            $$PWD/tests/test_xpath_paths_w3c.cpp \
#            $$PWD/tests/test_xpath_variables.cpp \
#            $$PWD/tests/test_xpath_xalan_1.cpp \
#            $$PWD/tests/test_xpath_xalan_2.cpp \
#            $$PWD/tests/test_xpath_xalan_3.cpp \
#            $$PWD/tests/test_xpath_xalan_4.cpp \
#            $$PWD/tests/test_xpath_xalan_5.cpp \
#            $$PWD/tests/writer_string.cpp \
