#ifndef PDFSTATE_H
#define PDFSTATE_H

#include "State.hpp"

class PDFState : public State {
public:
    PDFState();
    PDFState( int _page_num );
    ~PDFState();

    void incState();
    void decState();
    int getPageNumber() const;

private:
    int page_num;
};

#endif // PDFSTATE_H
