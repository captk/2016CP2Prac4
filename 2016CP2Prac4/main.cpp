/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: k
 *
 * Created on 7 September 2016, 4:54 PM
 */

#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "Vector.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    enum {
        total, unique, alphabetical
    } mode = alphabetical;
    for (int c; (c = getopt(argc, argv, "itu")) != -1;) {
        switch (c) {
            case 't': mode = total;
                cout << "total mode" << endl;
                break;
            case 'u': mode = unique;
                cout << "unique mode" << endl;
                break;
            case 'i': mode = alphabetical;
                cout << "alphabetical mode" << endl;
                break;
        }
    }
    argc -= optind;
    argv += optind;
    std::string word;
    bool found = false;

    Vector<std::string> stringVector;


    int count = 0;
    while (cin >> word) {
        for (int i = 0; i < stringVector.size(); i++) {
            if (stringVector[i] == word) {
                //cout << "found a match" << endl;
                stringVector.increment(i);
                found = true;
            }
        }
        if (!found) {
            bool added = false;
            for (int i = 0; i < stringVector.size(); i++) {
                if (word < stringVector[i] && !added) {
                    stringVector.insert(stringVector.begin() + i, word);
                    added = true;
                }
            }
            if(!added) stringVector.insert(stringVector.end(), word);
        }
        count += 1;
        found = false;
    }
    switch (mode) {
        case total: cout << "Total: " << count << endl;
            break;
        case unique: cout << "Unique: " << stringVector.size() << endl;
            break;
        case alphabetical:
            for(int i = 0; i < stringVector.size(); i++){
                cout << stringVector[i] << ": " << stringVector.getCount(i) << endl;
            }
    }
    /*cout << stringVector[11] << endl;
    for(int i = 0; i < stringVector.size(); i++){
        cout << stringVector[i] << endl;
    }
    */
    //cout << ("a" == "a") << endl;
    return 0;
}

