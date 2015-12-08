TEMPLATE = app

QT += qml quick
CONFIG += c++11

INCLUDEPATH += /usr/local/Cellar/poppler/0.37.0/include/poppler/qt5

LIBS += -L/usr/local/lib -lpoppler-qt5

SOURCES += main.cpp \
    bookview.cpp \
    bookparser.cpp \
    Book/Book.cpp \
    Book/PDFBook.cpp \
    Library/Library.cpp \
    Page/Page.cpp \
    Page/PDFPage.cpp \
    State/PDFState.cpp \
    State/State.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    bookview.h \
    bookparser.h \
    Book/Book.hpp \
    Book/PDFBook.hpp \
    Library/Library.hpp \
    Page/Page.hpp \
    Page/PDFPage.hpp \
    State/PDFState.h \
    State/State.hpp \
    imageprovider.h

