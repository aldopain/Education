#include "header.h"
using namespace std;



List::List():name('E'),elements(nullptr){}

void List::add(char c){
    ListElement a(c, nullptr);
    this->end->next = &a;
    end = &a;
}

List::List(char c):name(c){
    for(int i = 0; i < 26; i++){
        if(rand()%2){
            this->add(i + 97);
        }
    }
}

List List::operator = (const List&B){
    
}

List List::operator|(const List&B){
    List a;   
    for(ListElement i = head; i; i = i->next)
        a.add(i.element)
    for(ListElement j = B->head; j; j = j->next)
        a.add(i.element)
    a = a.deleteRepeats(); //написать это
    return a;
}

List List::operator&(const List&B){
    List a;   
    for(ListElement i = head; i; i = i->next)
        for(ListElement j = B->head; j; j = j->next)
            if(i.element == j.element)
                a.add(i.element)
    return a;
}

List List::operator~() const{
                                                                                                            
}

void List::print(){
    
}
