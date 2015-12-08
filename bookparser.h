#ifndef BOOKPARSER_H
#define BOOKPARSER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "Library/Library.hpp"
#include "Book/Book.hpp"
#include <string>
#include "ImageProvider.h"

class BookParser : public QObject
{
    Q_OBJECT
public:
//    explicit BookParser(QObject *parent = 0);

    BookParser(Library* myLib);

    void getBooksModels();

    void setBooksModel(QList<QObject *> *books);

    void setEngine(QQmlApplicationEngine* engine);

    void addBook();

//    void parseBooks()
signals:

public slots:

private:
    Library* _myLib;
     QQmlApplicationEngine* _engine;

      QList<QObject*>* _booksModel;
};

#endif // BOOKPARSER_H


