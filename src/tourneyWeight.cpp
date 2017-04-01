
// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// tourneyWeight.cpp

#include "tourneyWeight.h"
#include "meet.h"

/////// constructor for tourney weight
///////
     //
     //
     tourney_weight::tourney_weight(record_book &record_book, int wc, wrestler* t1, wrestler* t2, wrestler* t3, wrestler* t4, wrestler* t5, wrestler* t6, wrestler* t7, wrestler* t8)
     {
         weight_class=wc;

         if(t1==NULL){t1=new wrestler();}
         if(t2==NULL){t2=new wrestler();}
         if(t3==NULL){t3=new wrestler();}
         if(t4==NULL){t4=new wrestler();}
         if(t5==NULL){t5=new wrestler();}
         if(t6==NULL){t6=new wrestler();}
         if(t7==NULL){t7=new wrestler();}
         if(t8==NULL){t8=new wrestler();}

         list<wrestler> tourney_wrestlers;
         list<wrestler>::iterator tourney_wrestlers_itr;

         tourney_wrestlers.push_back(*t1);
         tourney_wrestlers.push_back(*t2);
         tourney_wrestlers.push_back(*t3);
         tourney_wrestlers.push_back(*t4);
         tourney_wrestlers.push_back(*t5);
         tourney_wrestlers.push_back(*t6);
         tourney_wrestlers.push_back(*t7);
         tourney_wrestlers.push_back(*t8);
 
         tourney_wrestlers.sort();
    
         //set seed 8
         tourney_wrestlers_itr=tourney_wrestlers.begin();
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed8=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed8=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed8=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed8=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed8=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed8=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed8=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed8=t8;      
         }
	 // set seed 7
         tourney_wrestlers_itr++;
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed7=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed7=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed7=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed7=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed7=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed7=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed7=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed7=t8;      
         }
         //set seed 6
         tourney_wrestlers_itr++;
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed6=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed6=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed6=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed6=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed6=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed6=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed6=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed6=t8;      
         }
         //set seed 5
         tourney_wrestlers_itr++;
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed5=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed5=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed5=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed5=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed5=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed5=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed5=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed5=t8;      
         }

         //set seed 4
         tourney_wrestlers_itr++;
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed4=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed4=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed4=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed4=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed4=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed4=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed4=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed4=t8;      
         }

         //set seed 3
         tourney_wrestlers_itr++;
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed3=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed3=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed3=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed3=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed3=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed3=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed3=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed3=t8;      
         }
            
         //set seed 2
         tourney_wrestlers_itr++;
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed2=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed2=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed2=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed2=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed2=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed2=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed2=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed2=t8;      
         }

         //set seed 1
         tourney_wrestlers_itr++;
         if(tourney_wrestlers_itr->get_id()==t1->get_id())
         {
              seed1=t1;      
         }
         if(tourney_wrestlers_itr->get_id()==t2->get_id())
         {
              seed1=t2;      
         }
         if(tourney_wrestlers_itr->get_id()==t3->get_id())
         {
              seed1=t3;      
         }
         if(tourney_wrestlers_itr->get_id()==t4->get_id())
         {
              seed1=t4;      
         }
         if(tourney_wrestlers_itr->get_id()==t5->get_id())
         {
              seed1=t5;      
         }
         if(tourney_wrestlers_itr->get_id()==t6->get_id())
         {
              seed1=t6;      
         }
         if(tourney_wrestlers_itr->get_id()==t7->get_id())
         {
              seed1=t7;      
         }
         if(tourney_wrestlers_itr->get_id()==t8->get_id())
         {
              seed1=t8;      
         }


         //////// round one bouts
         ////////
               //
               //
               tournament_bout(winner1, loser1, seed1, seed8, record_book);
               tournament_bout(winner2, loser2, seed4, seed5, record_book);
               tournament_bout(winner3, loser3, seed3, seed6, record_book);
               tournament_bout(winner4, loser4, seed2, seed7, record_book);

         //////// round two bouts
         ////////
               //
               //
               tournament_bout(winner5, loser5, winner1, winner2, record_book);
               tournament_bout(winner6, loser6, winner3, winner4, record_book);
               tournament_bout(winner7, loser7, loser1, loser2, record_book);
               tournament_bout(winner8, loser8, loser3, loser4, record_book);
         
         //////// round three bouts
         ////////
               //
               //
               tournament_bout(winner9, loser9, loser5, winner8, record_book);
               tournament_bout(winner10, loser10, loser6, winner7, record_book);
               tournament_bout(winner11, loser11, loser7, loser8, record_book);
               tournament_bout(winner12, loser12, loser9, loser10, record_book);

         //////// round four bouts
         ////////
               //
               //
               tournament_bout(winner13, loser13, winner9, winner10, record_book);
               tournament_bout(winner14, loser14, winner5, winner6, record_book);
     }

/////// print winners
///////
     //
     //
     void tourney_weight::print()
     {
         cout<<"\t"<<"1st -- "; winner14->tourney_print(); cout<<endl;
         cout<<"\t"<<"2nd -- "; loser14->tourney_print(); cout<<endl;
         cout<<"\t"<<"3rd -- "; winner12->tourney_print(); cout<<endl;
     }



