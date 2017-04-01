// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// weight.cpp

#include "weight.h"

/////// assignment operator
///////
     //
     //
     weight& weight::operator=(const weight& copy)
     {
          if(this==&copy)
          {
               return *this;
          }
          else
          {
               wrastler=copy.wrastler;
               weight_class=copy.weight_class;
               filled=copy.filled;
          }
          return *this;
      }
        
/////// equality operator
///////
     // 
     //
     bool weight::operator==(const weight& other)const
     {
           if(this->weight_class==other.weight_class)
           {
                return true;
           }
           return false;
     }

/////// inequality operator
///////
     //
     //
     bool weight::operator!=(const weight& other)const
     {
          return !(*this==other);
     }

/////// less than operator
///////
     //
     //
     bool weight::operator<(const weight& other)const
     {
         if(this->weight_class<other.weight_class)
         {
              return true;
         }
         return false;
     }

