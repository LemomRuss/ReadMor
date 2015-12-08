//
//  Book.hpp
//  ReadMore
//
//  Created by alex on 02.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "../Page/Page.hpp"


class Book
{
public:
    // Конструктор по умолчанию создает "пустую книгу"
    Book();
    // Конструктор по пути к файлу
    Book(std::string pass_to_book);
    // Деструктор
    virtual ~Book();
    
    // Возвращает ссылку на страницу с номером page_num
    virtual Page* getPage( std::size_t page_num, double x_resolution, double y_resolution, std::size_t width, std::size_t height ) const = 0;
    // Возвращает ссылку на обложку ( или первую страницу )
    virtual Page* getCover(double x_resolution, double y_resolution, std::size_t width, std::size_t height ) const = 0;
    // Возвращает следующую страницу и переходит на нее
    virtual Page* nextPage() = 0;
    // Возвращает предыдущую страницу и переходит на нее
    virtual Page* prevPage() = 0;
    // Возвращает название книги
    virtual std::string getTitle() const = 0;
    // Возвращает количество страниц в книге
    virtual std::size_t getNumOfPages() const = 0;
    
private:
    std::string _title;
    std::string _pass;
    std::size_t _numberOfPages;
};

#endif /* Book_hpp */
