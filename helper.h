#pragma once                                                                     
//lang::Cpp                                                                                                                                                       
#include <cstdlib>                                                               
#include <iostream>                                                                                                                                               
/** Helper class providing some C++ functionality and convenience                
 *  functions. This class has no data, constructors, destructors or              
 *  virtual functions. Inheriting from it is zero cost.                          
 */                                                                              
class Sys {                                                                      
 public:                                                                         
  /* Printing functions: the reason for returning this is to allow chaining:
   *  p("hi").p(" ").p("there"); */
  Sys& p(char* c);                              
  Sys& p(int i);                              
  Sys& p(size_t i);                          
  Sys& p(const char* c);                    
  Sys& pln();                           
  Sys& pln(int i);                  
  Sys& pln(char* c);                
  Sys& pln(const char* c);                                                                                            
  // Copying strings                                                             
  char* duplicate(const char* s);                                                                       
  char* duplicate(char* s);                                                                                                                                                             
  // Function to terminate execution with a message                              
  void exit_if_not(bool b, char* c) ;                                                                                                                                                          
  // Definitely fail                                                             
  void FAIL();                                                                                                                                                            
  // Some utilities for lightweight testing                                      
  void OK(const char* m);                                     
  void t_true(bool p);                                     
  void t_false(bool p);                                     
};           