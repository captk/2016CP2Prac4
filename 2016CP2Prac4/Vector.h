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

#include <iostream>
using namespace std;

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
        memSize = 1000;
        items = new WordInfo[memSize];
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
        //When we run out of space, allocate 5x more:
        //cout << "wtf";
        //cout << "memSize: " << memSize << endl;
        if(used == memSize){
            int newSize = memSize*5;
            WordInfo* newStorage = new WordInfo[newSize];
            for(int i = 0; i < memSize; i++){
                newStorage[i] = items[i];
                delete items[i];
            }
            delete items;
            items = newStorage;
            memSize = newSize;
        }
        
        //cout << "******item: " << item << " pos: " << (position - items) << " ";
        //cout << "pbi: " << position->text << endl;
        WordInfo newText;
        newText.count = 1;
        newText.text = item;

        WordInfo oldText = *(position);
        for (iterator i = position; i <= items + used; i++) {
            *(i) = newText;
            //cout << "pai: " << i->text << endl;
            newText = oldText;
            oldText = *(i + 1);
        }

        //cout << "post: " << position->text << endl;
        used++;
        return position;
    }

    T operator[](int i) {
        return items[i].text;
    }
    
    void increment(int i){
        items[i].count++;
    }
    int getCount(int i){
        return items[i].count;
    }
private:
    WordInfo* items;
    int used;
    int memSize;
};

#endif /* VECTOR_H */

