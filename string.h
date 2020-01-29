#pragma once                                                                     
//lang::CwC                                                                      
#include "object.h"                                                              
#include <cassert>                                                                                                                                                
/**                                                                              
 * An immutable string class. Values passed in are copied and deleted            
 * upon destruction.                                                             
 * author: vitekj@me.com                                                         
 */                                                                              
class String : public Object {                                                   
 public:                                                                                                                                                        
  char* val_; // data                                                            
  size_t size_; // number of characters (excluding \0)                           
                                                                                 
  /** Construct a string copying s */                                            
  String(char* s);                                                                              
                                                                                 
  /** Construct a string copying s */                                            
  String(const char* s);                                                                            
                                                                                 
  /** This constructor takes ownership of the char* s. The char*                 
   *  will be delete with the string. Use with caution. The first                
   *  argument is there to differentiate this constructor from the               
   *  standard one. */                                                           
  String(bool steal, char* s);                                                                              
                                                                                 
  /** Delete the string and free its data */                                     
  ~String ();                                                 
                                                                                 
  /** Compare strings for equality. */                                           
  bool equals(Object* other);                                                                              
                                                                                          
  /** Returns 0 if strings are equal, >0 if this string is larger,               
   *  <0 otherwise */                                                            
  int compare(String* tgt);                  
                                                                                 
  /** Textbook hash function on strings.   */                                    
  size_t hash_me_();                                                                             
                                                                                 
  /** Number of non \0 characters in this string */                              
  size_t size();                                         
                                                                                 
  /** Concatenate the strings, return a new object */                            
  String* concat(String* other);                                                                             
                                                                                 
  /** Return a newly allocated char* with this string value */                   
  char* to_string();                                 
                                                                                 
  /** Print this string on stdout. */                                            
  void print();                         
};    