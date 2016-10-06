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

    struct WordInfo {
        T text;
        int count;
    };

public:
    typedef WordInfo* iterator;

    Vector() {
        used = 0;
        items = new WordInfo[1000];
    }

    iterator begin() {
        return items;
    }

    iterator end() {
        return items + used;
    }

    int size() {
        return used;
    }

    iterator insert(iterator position, const T& item) {
        WordInfo newText;
        newText.count = 1;
        newText.text = item;
        
        WordInfo oldText = *(position);
        for(iterator i = position; i <= items + used; i++){
            *(position) = newText;
            newText = oldText;
            oldText = *(i + 1);
        }
        
        used++;
        return position;
    }

    T operator[](int i) {
        return items[i].text;
    }
private:
    WordInfo* items;
    int used;
};

#endif /* VECTOR_H */

