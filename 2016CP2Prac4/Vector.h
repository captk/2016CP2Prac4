/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.h
 * Author: k
 *
 * Created on 7 September 2016, 6:13 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector {
public:
    typedef T iterator;

    Vector() {
        used = 0;
    }

    iterator begin() {
        return items[0];
    }

    iterator end() {
        return items[used];
    }

    int size() {
        return used;
    }

    iterator insert(iterator position, const T& item) {
        return 0;
    }
    
    void push_back(const T& item){
        items[used] = item;
        used++;
    }
    
    T operator [](int i){
        return items[i];
    }
private:
    T items[1000];
    int used;
};

#endif /* VECTOR_H */

