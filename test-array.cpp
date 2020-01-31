#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "array.h"
#include "helper.h"
#include "string.h"
#include "object.h"

void FAIL() {   exit(500);    }
void OK(const char* m) {
  printf("%s\n", m);
}
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

Array* arr = new Array();
Array* full = new Array();
Array* thing1 = new Array();
Array* thing2 = new Array();
Array* thing3 = new Array();

void init() {
    arr = new Array();
    full = new Array();
    full->add(new String("boii"));
    full->add(new String("lit"));
    full->add(new String("yeet"));
    full->add(new String("yolo"));
    thing1 = new Array();
    thing2 = new Array();
    thing1->add(new String("doctor"));
    thing3 = new Array();
    thing3->add(new String("doctor"));
    thing2->add_all(0, thing3);
}


/**
 * Actions in this comment should break.
void test_add_null() {
    init();
    arr->add(NULL); //should break
    arr->add(0, NULL); //should break
}

void test_add_bad_index() {
    init();
    arr->add(1, new Object()); //should break because the object was added past the size of the array
    arr->add(-1, new Object()); //should break because two's complement
}

void test_remove_breaks() {
    init();
    arr->remove(1); // no such element to remove
}

void test_set_breaks() {
    init();
    arr->set(1, new Object()); // no element at index 1, index out of bounds
}
*/

void test_int_arrays() {
    init();
    Integer * i = new Integer(1);
    arr->add(i);
    t_true(arr->size() == 1);
    t_true(arr->get_type() == 3);
}

void test_bool_arrays() {
    init();
    Bool* b = new Bool(true);
    arr->add(b);
    t_true(arr->size() == 1);
    t_true(arr->get_type() == 4);
}

void test_float_arrays() {
    init();
    Float * b = new Float(1.2);
    arr->add(b);
    t_true(arr->size() == 1);
    t_true(arr->get_type() == 2);
}

void test_add() {
    init();

    arr->add(new String("woot"));
    t_true(1 == arr->get_type());
    t_true((new String("woot"))->equals(arr->get(0)));
    arr->add(new String("yeet"));
    t_true((new String("yeet"))->equals(arr->get(1)));
    t_true((new String("woot"))->equals(arr->get(0)));
    arr->add(1, new String("lit"));
    t_true((new String("woot"))->equals(arr->get(0)));
    t_true((new String("lit"))->equals(arr->get(1)));
    t_true((new String("yeet"))->equals(arr->get(2)));
    arr->add(0, new String("yolo"));
    t_true((new String("yolo"))->equals(arr->get(0)));
    t_true((new String("woot"))->equals(arr->get(1)));
    t_true((new String("lit"))->equals(arr->get(2)));
    t_true((new String("yeet"))->equals(arr->get(3)));
    arr->add(4, new String("boii"));
    t_true((new String("yolo"))->equals(arr->get(0)));
    t_true((new String("woot"))->equals(arr->get(1)));
    t_true((new String("lit"))->equals(arr->get(2)));
    t_true((new String("yeet"))->equals(arr->get(3)));
    t_true((new String("boii"))->equals(arr->get(4)));
    OK("All adding functionality was a success");
}

void test_add_all() {
    init();
    arr->add(new String("woot"));
    arr->add_all(0, full);
    t_true((new String("boii"))->equals(arr->get(0)));
    t_true((new String("lit"))->equals(arr->get(1)));
    t_true((new String("yeet"))->equals(arr->get(2)));
    t_true((new String("yolo"))->equals(arr->get(3)));
    t_true((new String("woot"))->equals(arr->get(4)));
    arr->add_all(5, full);
    t_true((new String("boii"))->equals(arr->get(0)));
    t_true((new String("lit"))->equals(arr->get(1)));
    t_true((new String("yeet"))->equals(arr->get(2)));
    t_true((new String("yolo"))->equals(arr->get(3)));
    t_true((new String("woot"))->equals(arr->get(4)));
    t_true((new String("boii"))->equals(arr->get(5)));
    t_true((new String("lit"))->equals(arr->get(6)));
    t_true((new String("yeet"))->equals(arr->get(7)));
    t_true((new String("yolo"))->equals(arr->get(8)));
    init();
    arr->add_all(0, full);
    arr->add_all(2, new Array());
    t_true((new String("boii"))->equals(arr->get(0)));
    t_true((new String("lit"))->equals(arr->get(1)));
    t_true((new String("yeet"))->equals(arr->get(2)));
    t_true((new String("yolo"))->equals(arr->get(3)));
    Array* a = new Array();
    a->add(new String("a"));
    a->add(new String("b"));
    arr->add_all(2, a);
    t_true((new String("boii"))->equals(arr->get(0)));
    t_true((new String("lit"))->equals(arr->get(1)));
    t_true((new String("a"))->equals(arr->get(2)));
    t_true((new String("b"))->equals(arr->get(3)));
    t_true((new String("yeet"))->equals(arr->get(4)));
    t_true((new String("yolo"))->equals(arr->get(5)));
    OK("Add all was a success");
}

void test_clear() {
    init();
    full->clear();
    t_true(full->size() == 0);
    t_true(full->equals(new Array()));
    OK("Successfully cleared array");
}

void test_equals_null() {
    init();
    t_false(arr->equals(NULL));
    t_false(full->equals(NULL));
    OK("No array is equal to NULL");
}

void test_equals() {
    init();
    t_true(arr->equals(arr));
    t_true(full->equals(full));
    t_true(thing1->equals(thing2));
    t_false(thing1->equals(full));
    OK("Equals is a success");
}

void test_get() {
    init();
    t_true(full->get(0)->equals(full->get(0)));
    t_true(full->get(0)->equals(new String("boii")));
    OK("Get returns the correct values");
}

void test_get_type() {
    init();
    t_true(full->get_type() == 1);
    full->add(new Object());
    t_true(full->get_type() == 0);
    t_true(arr->get_type() == 0);
    OK("get_type");
}

void test_index_of() {
    init();
    t_true(arr->index_of(new Object()) >= arr->size());
    t_true(full->index_of(new String("lit")) == 1);
    OK("index_of");
}

void test_remove() {
    init();
    t_true(full->size() == 4);
    full->remove(0);
    t_true(full->size() == 3);
    t_true((new String("lit"))->equals(arr->get(0)));
    t_true((new String("yeet"))->equals(arr->get(1)));
    t_true((new String("yolo"))->equals(arr->get(2)));
    OK("remove");
}

void test_set() {
    init();
    size_t s = full->size();
    full->set(0, new String("test"));
    t_true(full->size() == s);
    t_true(full->get(0)->equals(new String("test")));
    OK("set");
}

void test_size() {
    init();
    t_true(arr->size() == 0);
    t_true(full->size() == 4);
    t_true(thing1->size() == 1);
    OK("size");
}

int main() {
    //test_add_null();
    //test_add_bad_index();
    test_add();
    test_add_all();
    test_clear();
    test_equals_null();
    test_equals();
    test_get();
    test_get_type();
    test_index_of();
    //test_remove_breaks();
    test_set();
    test_size();
}
