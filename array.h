#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "object.h"

/**
 * this class represents an array that takes any values that extend objects */
class Array: public Object {
    Object** val_; // stored values
    size_t size_; //the number of stored values
    size_t type_; //the type of the values

public:
    //the default constructor for an Array
    Array(): Object() {}

    //the default destructor for Array
    ~Array() {}

    /**
     * adds the object to the back of the array
     * @arg o: the object that will be added to the back of the array */
    void add(Object* o);

    /**
     * adds the o object at the idx index and shifts the rest of the array up by 1
     * @arg idx: the index where the object will be added
     * @arg o: the object that will be added at index idx */
    void add(size_t idx, Object* o);

    /**
     * adds all of the objects at the index
     * @arg idx: the index where the objects will be added
     * @arg aoo: the list of objects that will be added at the index */
    void add_all(size_t idx, Array* aoo);

    //deletes all of the values in thearray
    void clear();

    /**
     * checks for equality by checking type and then contents
     * @arg other: the object that will be checked against this for equality */
    bool equals(Object* other);

    /**
     * gets the object at the given index
     * @arg idx: the index to get the object from */
    Object* get(size_t idx);

    /**
     * returns the type of the array as a size_t
     * 0 is Object
     * 1 is String */
    size_t get_type();

    /**
     * gets the index of o if it exists
     * @arg o:the object that is searched for */
    size_t index_of(Object* o);

    /**
     * removes the object at the given index and returns it
     * @arg idx: the index of the object that will be removed from the array */
    Object* remove(size_t idx);

    /**
     * sets the value at this index to the o object
     * @arg i: the index where the object will be set in the array
     * @arg o: the object that will be placed at index i */
    void set(size_t idx, Object* o);

    // gets current size of the array, meaning the number of filled elements
    size_t size();

};