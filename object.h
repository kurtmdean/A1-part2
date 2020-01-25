#pragma once

// lang::CwC

#include <stdlib.h>

/**
 * Object: the class that represents any object and has a default hash
 */
class Object {
public:
    size_t hash_;

    //default constructor for an Object
    Object() {
        hash_ = 0; 
    }

    //How to define a destuctor
    virtual ~Object() {

    }

    //size_t is unsigned 64-bit integer
    size_t hash() {
        //Computer the hash if the hash is 0
        if (hash_ == 0) {
            hash_ = hash_me_();
        }
        return hash_;
    }

    //creates a hash for the input
    virtual size_t hash_me_() {
        return reinterpret_cast<size_t>(this);
    }

    /**
     * checks equality by whether they are literally the same object
     * @arg other: the object that will be compared against this */
    virtual bool equals(Object* other) {
        return this == other;
    }
};