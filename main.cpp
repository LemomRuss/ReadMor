#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlEngine>
//#include <QQuickWindow>
//#include <QSurfaceFormat>
#include <QQmlContext>
#include <QDebug>
#include "bookview.h"
#include "bookparser.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    QList<QObject *> * booksModel = new QList<QObject *>();
    qmlRegisterType<bookView>("BookView", 1, 0, "BookView");


    engine.rootContext()->setContextProperty("booksModel", QVariant::fromValue(*booksModel));

    BookParser* parser = new BookParser();
    parser->setEngine(&engine);
    parser->setBooksModel(booksModel);
    parser->getBooksModels();

//    QList<QObject *> *model = new QList<QObject *>();
//    bookView* book = nullptr;
//    QString artBook = "Book.jpg";
//    for (int i = 0; i < 100; ++i) {
//        book = new bookView("test book", artBook);
//        model->append(book);
//    }
//    booksModel = model;
//     engine.rootContext() -> setContextProperty("booksModel", QVariant::fromValue(*booksModel));

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    return app.exec();
}

