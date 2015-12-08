//
//  PDFPage.cpp
//  ReadMore
//
//  Created by alex on 06.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#include "PDFPage.hpp"

PDFPage::PDFPage( const QImage& image) {
    _pdf_page = image;
}

PDFPage::~PDFPage() {
}

QImage PDFPage::getImage() const {
    return _pdf_page;
}

