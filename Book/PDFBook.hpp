//
//  PDFBook.hpp
//  ReadMore
//
//  Created by alex on 02.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#ifndef PDFBook_hpp
#define PDFBook_hpp

#include <stdio.h>

#include "Book.hpp"
#include "../Page/PDFPage.hpp"
#include "../State/PDFState.h"
#include <poppler-qt5.h>

class PDFBook: public Book {
    
public:
    // Конструктор по умолчанию
    PDFBook();
    // Конструтор из указателя на документ
    PDFBook(std::string pass_to_book);
    // Деструктор
    ~PDFBook();
    
    // Возвращает ссылку на страницу с номером page_num
    Page* getPage( std::size_t page_num, double x_resolution, double y_resolution, std::size_t width, std::size_t height ) const;
    // Возвращает ссылку на обложку ( или первую страницу )
    Page* getCover(double x_resolution, double y_resolution, std::size_t width, std::size_t height ) const;
    // Возвращает следующую страницу и переходит на нее
    Page* nextPage();
    // Возвращает предыдущую страницу и переходит на нее
    Page* prevPage();
    // Возвращает название книжки
    std::string getTitle() const;
    // Возвращает количество страниц
    std::size_t getNumOfPages() const;
private:
    PDFState _state;
    std::string _pass;
    Poppler::Document* _document;
};

#endif /* PDFBook_hpp */
