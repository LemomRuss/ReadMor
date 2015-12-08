#include "bookparser.h"
#include <QDebug>
#include <QTime>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include "bookview.h"


BookParser::BookParser(Library *myLib):_myLib(myLib) {}

void BookParser::setBooksModel(QList<QObject *> *books) {
    _booksModel = books;
}

void BookParser::getBooksModels() {
//    QList<QObject *> *model = new QList<QObject *>();
//    bookView* book = NULL;
//    addBook();
//    QString artBook = "Book.jpg";
//    for (int i = 0; i < 2; ++i) {
//        Book* currentBook = _myLib->getBook(0);
//        Page* titlePage = currentBook->getPage(0, 72, 72, 30, 80);
//        QImage titleImage = titlePage->getImage();
//        QString title = QString::fromUtf8(currentBook->getTitle().c_str());
////        ImageProvider* imageProvider = new ImageProvider();
////        _engine->addImageProvider();
//        book = new bookView(title,artBook);
//        model->append(book);
//    }

//////    setBooksModel(model);
//    _booksModel = model;
//    qDebug()<<"gotIt";
//     _engine -> rootContext() -> setContextProperty("booksModel", QVariant::fromValue(*_booksModel));
//    delete(model);
}

void BookParser::addBook() {
   _myLib->addBook("/Users/Leman/Documents/ReadMore/qml/test.pdf");
}

void BookParser::setEngine(QQmlApplicationEngine *engine) {
    _engine = engine;
}
