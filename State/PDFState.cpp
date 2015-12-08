#include "PDFState.h"

PDFState::PDFState() : page_num(0)
{

}

void PDFState::incState() {
    page_num++;
}

void PDFState::decState() {
    page_num--;
}

int PDFState::getPageNumber() const {
    return page_num;
}

PDFState::~PDFState() {

}

PDFState::PDFState( int _page_num ) : page_num(_page_num) {

}
