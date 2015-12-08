//
//  State.hpp
//  ReadMore
//
//  Created by alex on 02.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>

class State {
public:
    // Конструктор по умолчанию соответствует состаянию неоткрытой книги
    State();
    // Деструктор
    virtual ~State() = 0;
    
    virtual void incState() = 0;
    virtual void decState() = 0;
    
};

#endif /* State_hpp */
