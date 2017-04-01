// Timothy Baker
// cs361
// Assg1: Wrastlin' Simulator
//
// wrestler.cpp

#include "wrestler.h"
#include <iomanip>
#include <iostream>


/////// create random number generator and agents
///////
     //
     //
     default_random_engine random_eng(time(NULL));
     normal_distribution<double> real_dist_weight(155,45);
     normal_distribution<double> normal_dist_ability(100,15);
     uniform_real_distribution<double> real_dist_id(1000000,9999999);

/////// initializing constructor. initializes a wrestler with a random weight, id and 
/////// ability level.
     //
     //
     wrestler::wrestler(int i)
     {
           team_tourney_points=0;
	   wins=0;
           losses=0;
           id=real_dist_id(random_eng);
           ability=normal_dist_ability(random_eng);
           weight=real_dist_weight(random_eng);
	   while(weight>286 || weight<92)
	   {
               weight=real_dist_weight(random_eng);
	   }
	   selected=false;
           team_id=i;
     }

/////// copy constructor
///////
     //
     //
     wrestler::wrestler(const wrestler& copy)
     {
	    weight=copy.weight;
            team_tourney_points=copy.team_tourney_points;
	    ability=copy.ability;
	    id=copy.id;
            team_id=copy.team_id;
	    selected=copy.selected;
	    wins=copy.wins;
            losses=copy.losses;
     }
 
/////// assignment operator
///////
     //
     //
     wrestler& wrestler::operator=(const wrestler& copy)
     {
          if(this==&copy)
          {
               return *this;
          }
          else
          {
               team_tourney_points=copy.team_tourney_points;
               weight=copy.weight;
               ability=copy.ability;
               id=copy.id;
               team_id=copy.team_id;
	       selected=copy.selected;
	       wins=copy.wins;
               losses=copy.losses;
               return *this;
	   }
      }

/////// equality operator
///////
     //
     //
     bool wrestler::operator==(const wrestler& other)const
     {
          if(this->ability==other.ability)
          {
                if(this->weight==other.weight)
                {
                     if(this->id==other.id)
                     {
                           return true;
                     }
                }
          }
          return false;
     }

/////// ineqaulity operator
///////
     //
     //
     bool wrestler::operator!=(const wrestler& other)const
     {
          return !(*this==other);
     }

/////// less than operator
///////
     //
     //
     bool wrestler::operator<(const wrestler& other)const
     {

      if(this->wins<other.wins)
      {
	 return true;
      }
      return false;

     }

/////// determine wrestler with most wins
///////
     //
     //
     bool wrestler::most_wins(const wrestler one,const wrestler two)
     {
         return one.get_wins() < two.get_wins();
     }

/////// tourney print
///////
     //
     //
     void wrestler::tourney_print()
     {
          cout<<"id: "<<team_id<<" "<<id<<"   record: "<<std::setw(2)<<std::right<<wins<<"-"<<std::setw(2)<<std::left<<losses;
     }

/////// print wrestler
///////
     //
     //
     void wrestler::print(std::ostream& out)
     {

               out<<"id: "<<team_id<<" "<<id<<"   record: "<<std::setw(2)<<std::right<<wins<<"-"<<std::setw(2)<<std::left<<losses<<"  weight: "<<std::setw(3)<<weight<<"lbs"<<"   ability: "<<std::setw(3)<<ability<<"   selected: "<<selected<<endl;    

     }
