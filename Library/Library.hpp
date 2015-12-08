//
//  Library.hpp
//  ReadMore
//
//  Created by alex on 02.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#ifndef Library_hpp
#define Library_hpp

#include <stdio.h>
#include <vector>
#include <string>

#include "Book/Book.hpp"

class Library {
public:
    // Конструктор по умолчанию
    Library();
    // Деструктор
    ~Library();
    
    // Синхронизитует книги с онлайн билблиотекой
    void sync();
    // Добавляет книгу в список книг из локального хранилища
    void addBook(std::string path);
    // Возвращает ссылку на книгу с заданным id
    Book* getBook(std::size_t id) const;
    // Удаляет книгу с данным id
    void deleteBook(std::size_t id);
    // Возвращает все книги
    std::vector< Book* > getAllBooks() const;
    
    
private:
    // Массив указателей на книги
    std::vector< Book* > _books;
    
};

#endif /* Library_hpp */
