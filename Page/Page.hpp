//
//  Page.hpp
//  ReadMore
//
//  Created by alex on 02.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#ifndef Page_hpp
#define Page_hpp

#include <stdio.h>
#include <QPixmap>

class Page {
public:
    // Конструктор по умолчания
    Page();
    // конструктор по разрешению страницы
    Page(const QImage& image);
    // Деструктор
    virtual ~Page();
    
    // Функция возвращает  QImage по данной странице
    virtual QImage getImage() const = 0;
};

#endif /* Page_hpp */
