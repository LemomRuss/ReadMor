#include "bookview.h"

bookView::bookView(): QObject() {}

bookView::bookView(QString title, QString artBook) {
     _title = title;
     _artBook = artBook;
}

QString bookView::getArtBook() {
    return _artBook;
}

QString bookView::getTitle() {
    return _title;
}

void bookView::setTitle(const QString &title) {
    _title = title;
}

void bookView::setArtBook(const QString &artBook) {
    _artBook = artBook;
}
