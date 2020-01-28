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
  String(char* s) {                                                              
    size_ = strlen(s);                                                           
    val_ = duplicate(s);                                                         
  }                                                                              
                                                                                 
  /** Construct a string copying s */                                            
  String(const char* s) {                                                        
    size_ = strlen(s);                                                           
    val_ = duplicate(s);                                                         
  }                                                                              
                                                                                 
  /** This constructor takes ownership of the char* s. The char*                 
   *  will be delete with the string. Use with caution. The first                
   *  argument is there to differentiate this constructor from the               
   *  standard one. */                                                           
  String(bool steal, char* s){                                                   
    assert(steal);                                                               
    size_ = strlen(s);                                                           
    val_ = s;                                                                    
  }                                                                              
                                                                                 
  /** Delete the string and free its data */                                     
  ~String () { delete[] val_; }                                                  
                                                                                 
  /** Compare strings for equality. */                                           
  bool equals(Object* other) {                                                   
    if (other == nullptr) return false;                                          
    String* tgt = dynamic_cast<String*>(other);                                  
    if (tgt == nullptr) return false;                                            
    return compare(tgt)== 0;                                                     
  }                                                                              
                                                                                          
  /** Returns 0 if strings are equal, >0 if this string is larger,               
   *  <0 otherwise */                                                            
  int compare(String* tgt) { return strcmp(val_, tgt->val_); }                   
                                                                                 
  /** Textbook hash function on strings.   */                                    
  size_t hash_me_() {                                                            
    size_t hash = 0;                                                             
    for (size_t i = 0; i < size_; ++i)                                           
      hash = val_[i] + (hash << 6) + (hash << 16) - hash;                        
    return hash;                                                                 
  }                                                                              
                                                                                 
  /** Number of non \0 characters in this string */                              
  size_t size() { return size_; }                                                
                                                                                 
  /** Concatenate the strings, return a new object */                            
  String* concat(String* other) {                                                
    char* res = new char[size_ + other->size() + 1];                             
    for (size_t i = 0; i < size_; i++)                                           
      res[i] = val_[i];                                                          
    for (size_t i = size_, j = 0; i < size_ + other->size(); i++, j++)           
      res[i] = val_[j];                                                          
    res[size_] = '\0';                                                           
    return new String(true, res);                                                
  }                                                                              
                                                                                 
  /** Return a newly allocated char* with this string value */                   
  char* to_string() { return duplicate(val_); }                                  
                                                                                 
  /** Print this string on stdout. */                                            
  void print() { p("String(\"").p(val_).p("\")");  }                             
};