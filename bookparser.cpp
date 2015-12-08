#include "bookparser.h"
#include <QDebug>
#include <QTime>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include "bookview.h"


void BookParser::setBooksModel(QList<QObject *> *books) {
    _booksModel = books;
}

void BookParser::getBooksModels() {
    QList<QObject *> *model = new QList<QObject *>();
    bookView* book = nullptr;
    QString artBook = "Book.jpg";
    for (int i = 0; i < 2; ++i) {
        book = new bookView("test book", artBook);
        model->append(book);
    }

////    setBooksModel(model);
    _booksModel = model;
    qDebug()<<"gotIt";
     _engine -> rootContext() -> setContextProperty("booksModel", QVariant::fromValue(*_booksModel));
    delete(model);
}

void BookParser::setEngine(QQmlApplicationEngine *engine) {
    _engine = engine;
}
