#ifndef BOOKPARSER_H
#define BOOKPARSER_H

#include <QObject>
#include <QQmlApplicationEngine>


class BookParser : public QObject
{
    Q_OBJECT
public:
//    explicit BookParser(QObject *parent = 0);

    BookParser() = default;

    void getBooksModels();

    void setBooksModel(QList<QObject *> *books);

    void setEngine(QQmlApplicationEngine* engine);

//    void parseBooks()
signals:

public slots:

private:
      QQmlApplicationEngine* _engine;

      QList<QObject*>* _booksModel;
};

#endif // BOOKPARSER_H


