//
// Created by andresold on 25.11.17.
//

#ifndef COM_3SEM_45LABANDREANDVIKA_LIST_H
#define COM_3SEM_45LABANDREANDVIKA_LIST_H

#include <cstdlib>
#include "CorSnake.h"
#include <list>

class list {
    std::list<CorSnake> head;
    int length;
public:
    list() {
        head = NULL;
        length = 0;
    }

    void add(CorSnake s) {

        head.push_front(s);
        length++;
    }

    int listLength() {
        return length;
    }
    CorSnake get( int n) {
        int count = 1;

        for (CorSnake x:head) {
            if (count == n)
                return (x);
            count++;
        }

    }
    void remove() {
        head.pop_back();
        length--;
    }

};


#endif //COM_3SEM_45LABANDREANDVIKA_LIST_H
