#pragma once                                                                     
//lang::CwC                                                                                                                                                       
#include "helper.h"                                                                                                                                               
/**                                                                              
 * A class that represents the top of the object hierarchy.                      
 * author: vitekj@me.com */                                                      
class Object : public Sys {                                                      
 public:                                                                         
  size_t hash_;  // cache the hash value                                         
                                                                                 
  /** Default constructor ensure that hash is initialized */                     
  Object() { hash_ = 0; }                                                        
                                                                                 
  /** Default constructor is virtual to support subclasses */                    
  virtual ~Object() {}                                                           
                                                                                 
  /** Returns the object's hash value. Two objects that are equal should         
   * have the same hash; object's that are not, may have the same hash.          
   * Subclasses should implement hash_me_(). */                                  
  size_t hash() {  return  hash_ ? hash_ :  hash_ = hash_me_();  }               
                                                                                 
  /** Trivial hash function. */                                                  
  virtual size_t hash_me_() { return 0; }                                        
                                                                                 
  /** Use the address of the other object to determine equality. */              
  virtual bool equals(Object* other) { return this == other; }                   
                                                                                 
  /** Return a newly allocated string describin the object */                    
  virtual char* to_string() { return duplicate("Object"); }                      
                                                                                 
  /** Print to stdout. */                                                        
  virtual void print() { pln("object");  }                                                                                                                    
};   