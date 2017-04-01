// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// weight.h

#ifndef WEIGHT_H_INCLUDED
#define WEIGHT_H_INCLUDED

#include "wrestler.h"
#include <list>

using namespace std;

///////
///////
     //
     //
     class weight
     {
          protected:
	  wrestler* wrastler; // chosen wrestler for class, if one exists
          int weight_class;
	  bool filled;
 
          public:
          // constructors and destructors
          weight(){weight_class=0;filled=false;wrastler=new wrestler();}
          weight(int wc){weight_class=wc;filled=false; wrastler= new wrestler();}
          ~weight(){}
          // setters and getters
          void set_wrestler(wrestler* w){filled=true;wrastler=w;}
	  wrestler* get_wrestler(){return wrastler;}
	  void set_weight_class(int wc){weight_class=wc;}
          int get_weight(){return weight_class;}
	  void set_filled(bool f){filled=f;}
	  bool get_filled(){return filled;}
 	  // operator overloading
          weight& operator=(const weight& copy);
          bool operator==(const weight& other)const;
          bool operator!=(const weight& other)const;
          bool operator<(const weight& other)const;
     };

#endif//WEIGHT_H_INCLUDED
