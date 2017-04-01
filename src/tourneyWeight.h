// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// tourneyWeight.h

#ifndef TOURNEYWEIGHT_H_INCLUDED
#define TOURNEYWEIGHT_H_INCLUDED

#include "wrestler.h"
#include "records.h"
#include <list>

using namespace std;

/////// class object tourney_weight
///////
     //
     //
     class tourney_weight
     {
          private:
             int weight_class;
             wrestler* seed1;
             wrestler* seed2;
             wrestler* seed3;
             wrestler* seed4;
             wrestler* seed5;
             wrestler* seed6;
             wrestler* seed7;
             wrestler* seed8;
             //round one
             wrestler* winner1;
             wrestler* loser1;
             wrestler* winner2;
             wrestler* loser2;
             wrestler* winner3;
             wrestler* loser3;
             wrestler* winner4;
             wrestler* loser4;
             //round two
             wrestler* winner5;
             wrestler* loser5;
             wrestler* winner6;
             wrestler* loser6;
             wrestler* winner7;
             wrestler* loser7;
             wrestler* winner8;
             wrestler* loser8;
             //round three
             wrestler* winner9;
             wrestler* loser9;
             wrestler* winner10;
             wrestler* loser10;
             wrestler* winner11;
             wrestler* loser11;
             wrestler* winner12;
             wrestler* loser12;
             //round four
             wrestler* winner13;
             wrestler* loser13;
             wrestler* winner14;
             wrestler* loser14;
  

          public:
             //constructors and destructor
             tourney_weight(){weight_class=0;}
             tourney_weight(record_book &record_book, int wc, wrestler* t1, wrestler* t2, wrestler* t3, wrestler* t4, wrestler* t5, wrestler* t6, wrestler* t7, wrestler* t8);
             ~tourney_weight(){}
            //setters and getters
            void set_seed1(wrestler* seed){seed1=seed;}
            wrestler* get_seed1(){return seed1;}
            void set_seed2(wrestler* seed){seed2=seed;}
            wrestler* get_seed2(){return seed2;}
            void set_seed3(wrestler* seed){seed3=seed;}
            wrestler* get_seed3(){return seed3;}
            void set_seed4(wrestler* seed){seed4=seed;}
            wrestler* get_seed4(){return seed4;}
            void set_seed5(wrestler* seed){seed5=seed;}
            wrestler* get_seed5(){return seed5;}
            void set_seed6(wrestler* seed){seed6=seed;}
            wrestler* get_seed6(){return seed6;}
            void set_seed7(wrestler* seed){seed7=seed;}
            wrestler* get_seed7(){return seed7;}
            void set_seed8(wrestler* seed){seed8=seed;}
            wrestler* get_seed8(){return seed8;}
            //other functions
            void print();
      };

#endif//TOURNEYWEIGHT_H_INCLUDED


