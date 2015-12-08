//
//  PDFPage.hpp
//  ReadMore
//
//  Created by alex on 06.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#ifndef PDFPage_hpp
#define PDFPage_hpp

#include <stdio.h>
#include "Page.hpp"
#include <poppler-qt5.h>


class PDFPage : public Page {
public:
    PDFPage();
    // Конструктор по объекту библиотеки  poppler
    PDFPage(const QImage &image);
    // Деструктор
    ~PDFPage();
    // Возвращает картинку по заданному разрешению null image в случае ошибки
    QImage getImage() const;
private:
    QImage _pdf_page;
};

#endif /* PDFPage_hpp */
