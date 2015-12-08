//
//  Library.cpp
//  ReadMore
//
//  Created by alex on 02.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#include "Library.hpp"
#include <poppler-qt5.h>
#include "../Book/PDFBook.hpp"

Library::Library() {

}

Library::~Library() {
    for (auto book : _books) {
        delete book;
    }
}

bool is_valid(std::string path) {
    return true;
}

void Library::addBook(std::string path) {
    if (is_valid(path)) {
        PDFBook* book = new PDFBook(path);
        _books.push_back(book);
    }
}

Book* Library::getBook(std::size_t id) const {
    if ( id < _books.size()) {
        return _books[id];
    }
}
