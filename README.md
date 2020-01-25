# Summary
This is a description of the user facing API for the Array class. The array class allows for storage of any type that extends Object, and the Object class. Currently one class extends the Object class and that is the String class.

# Methods

* add: allows a user to add an object to the back of the array or at the index
    * exists to allow users to add elements to the array in the location they would like
* add_all: allows a user to add an array of objects to an index in the array.
    * allows for bulk insertions at an index where a user believes this is useful. This can also be used to append two arrays.
* clear: allows a user to delete all of the elements in the array
    * is useful to clear out memory when the contents of the array are no longer necesary
* equals: checks to see if the given object is equal to this
    * makes sure that two objects are of the same type and then compares them with the equals method for that type
* get: allows a user to access the elements in this array by their indices
    * gives public-facing access to array contents
* get_type: allows the user to determine the type of object stored in this array
    * useful for utilizing any additional functionality provided by that type over and above Object
* index_of: allows a user to determine the first index of the given object
    * If the given object is not an element in this array, return size
* remove: allows the user to remove an element in this array by index
    * necessary to remove elements from an array without clearing it
* set: allows the user to replace the element at the given index
    * shortcut to removing the element at that index and adding the given element to that index
* size: allows the user to check the number of elements in this array
