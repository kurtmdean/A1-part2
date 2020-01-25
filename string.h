#pragma once
#include "object.h"
#include<iostream>
#include<string.h>
#include "helper.h"
#include "generic.h"

/**
 * String: the class that represents a string and contains information about size
 */
class String : public Object, public Generic {
public:
    char* val_;     //the array of characters that makes up the string
    size_t size_;   //the number of characters in the string
    
    /**
     * constructor that uses a not constant char*
     * @arg c: the char* that will be stored as the value of the String */
    String(char* c) {
        this->type = 3;
        size_ = strlen(c);
        val_ = new char[size_];
        for (size_t i=0; i < size_; i++) {
            val_[i] = c[i];
        }
    }

    /**
     * constructor that uses a const char* to generate a string
     * @arg c: the const char* that will be stored in the val_ part of the new String */
    String(const char* c) {
        size_ = strlen(c);
        val_ = new char[size_];
        for (size_t i=0; i < size_; i++) {
            val_[i] = c[i];
        }
    }

    /**
     * adds the input String to the back of the current String
     * @arg s: the new string that will be added to the back of the current string */
    String* concat(String* s) {
        size_t new_size = size_ + s->size_;
        char* c = new char[new_size];
        for (size_t i=0; i<size_; i++) {
            c[i] = val_[i];
        }
        for (size_t i=0; i<s->size_; i++) {
            c[i + s->size_] = s->val_[i];
        }
        return new String(c);
    }

    //grabs a copy of this
    String* get() {
        char* c = new char[size_];
        for (size_t i=0; i<size_; i++) {
            c[i] = val_[i];
        }
        return new String(c);
    }

    //returns the type of this: either BOOL, INT, FLOAT, or STRING 0-3 respectively
    size_t type_test() {
        type = 0;
        for (size_t i=0; val_[i]!=0; i++) {
            if ((val_[i] == '0' ||  val_[i] == '1') && i == 0) {

            } else if (isdigit(val_[i]) || (i == 0 && val_[i] == '+') || (i == 0 && val_[i] == '-')) {
                if (type == 0) {
                    type = 1;
                }
            } else if (val_[i] == '.') {
                if (type <= 2) {
                    type = 2;
                }
            } else {
                type = 3;
            }
        }
        return type;
    }

    //gets a hash value for the String
    size_t hash_me_() {
        size_t res = 0;
        for (size_t i=0; i<size_; i++) {
            res += val_[i];
        }
        return res;
    }

    /**
     * Checks to see if the other object is a string and the other string has the same value
     * @arg other: the object that will be compared for equality against this */
    bool equals(Object * other) {
        if (other == nullptr) {
            return false;
        }
        String *s = dynamic_cast<String*>(other);
        if (s == nullptr) {
            return false;
        }
        return strcmp(val_, s->val_) == 0;
    }

    //The things that need to be deleted are those notated with new
    //Desctuctror
    ~String() {
        delete[] val_;
    }
};

/**
 * the string that maintains the number of counts it has occurred in the list */
class CountedString : public String {
public:
    size_t count_; // the number of times it occurs in the input

    /**
     * the contructor that uses an const char* input string to make a CountedString
     * @arg c: the input string */
    CountedString(const char* c) : String(c) {
        count_ = 1;
    }

    /**
     * the constructor that uses a char* input string to make a CountedString
     * @arg c: the char* that gives the string its value */
    CountedString(char* c) : String(c) {
        count_ = 1;
    }

    /**
     * increases the count of the string by the given amount
     * @arg amount: the amount to increase the count of the CountedString */
    void iterate_count(size_t amount) {
        count_ += amount;     
    }
};