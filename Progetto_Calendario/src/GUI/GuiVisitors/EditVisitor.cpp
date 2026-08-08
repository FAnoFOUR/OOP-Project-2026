#include "EditVisitor.h"

EditPage* EditVisitor::getEditPage(){
    return page;
}

void EditVisitor::visit(Activity* a){
    if(!page){
        delete page;
    }
    page = new EditPage(a);
}

void EditVisitor::visit(Reminder* r){
    if(!page){
        delete page;
    }
    page = new EditPage(r);
}

void EditVisitor::visit(Work* w){
    if(!page){
        delete page;
    }
    page = new EditPage(w);
}

void EditVisitor::visit(Bill* b){
    if(!page){
        delete page;
    }
    page = new EditPage(b);
}

void EditVisitor::visit(Project* p){
    if(!page){
        delete page;
    }
    page = new EditPage(p);
}

