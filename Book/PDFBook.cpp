//
//  PDFBook.cpp
//  ReadMore
//
//  Created by alex on 02.11.15.
//  Copyright © 2015 readmore_team. All rights reserved.
//

#include "PDFBook.hpp"
#include <QDebug>

PDFBook::~PDFBook() {
    delete _document;
}

PDFBook::PDFBook(std::string pass_to_book): _pass(pass_to_book) {
    _document = Poppler::Document::load(QString::fromUtf8(_pass.c_str()));
}

Page* PDFBook::getPage( std::size_t page_num, double x_resolution, double y_resolution, std::size_t width, std::size_t height ) const {
    Poppler::Page* pdfPage = _document->page(page_num);
    float pageWidth = pdfPage->pageSize().width();
    float pageHeight = pdfPage->pageSize().height();
    qDebug()<<"pagew " << pageWidth << " w" << width;
    qDebug()<<"pageh " << pageHeight << " h" << height;
    // Вычисление множителя скалирующего изображение
    float scaleFactor = (float)(pageWidth)/width > (float)(pageHeight)/height ? (float)(pageWidth)/width : (float)(pageHeight)/height;
    width *= scaleFactor;
    height *= scaleFactor;
    int xPosition = (float)(pageWidth)/width == 1.0 ? xPosition = -1 : xPosition = -1*(width - pageWidth)/2;
    int yPosition = (float)(pageHeight)/height == 1.0 ? yPosition = -1 : yPosition = -1*(height - pageHeight)/2;
    QImage image = pdfPage->renderToImage(x_resolution, y_resolution, xPosition, yPosition, width, height);
    delete pdfPage;
    Page* page = new PDFPage(image);
    return page;
}

Page* PDFBook::getCover(double x_resolution, double y_resolution, std::size_t width, std::size_t height ) const {
    Poppler::Page* pdfPage = _document->page("0");
    QImage image = pdfPage->renderToImage(x_resolution, y_resolution, -1, -1, width, height);
    delete pdfPage;
    Page* page = new PDFPage(image);
    return page;
}

Page* PDFBook::nextPage() {

}

Page* PDFBook::prevPage() {

}

std::string PDFBook::getTitle() const {
    auto first = _pass.begin();
    auto last = _pass.end();
    for (auto letter = _pass.begin() ; letter != _pass.end(); ++letter) {
        if ( *letter == '/' ) {
            first = letter + 1;
        }
        if ( *letter == '.' && letter != _pass.begin()) {
            last = letter - 1;
        }
    }
    std::string title;
    for (auto letter = first ; letter != last; ++letter) {
        title.push_back(*letter);
    }
    return title;
}

std::size_t PDFBook::getNumOfPages() const {
    return _document->numPages();
}
