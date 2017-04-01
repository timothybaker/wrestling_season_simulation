;// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// wrestler.h

#ifndef WRESTLER_H_INCLUDED
#define WRESTLER_H_INCLUDED

#include <random>
#include <ctime>
#include <iostream>


using namespace std;

/////// class declaration for wrestler object
///////
     //
     //
     class wrestler
     {
          protected:
               int team_tourney_points;
	       int wins;
               int losses;
               int weight;
               int ability;
               int team_id;
               int id;
	       bool selected;
               
          public:
               // constructors and destructor
               wrestler(){wins=losses=weight=ability=id=team_id=0;selected=false;}
	       wrestler(int team_id);
               wrestler(const wrestler& copy);
               ~wrestler(){}
               // setters and getters
               void set_team_tourney_points(int tp){team_tourney_points=tp;}
               int get_team_tourney_points(){return team_tourney_points;}
               void add_team_tourney_points(int atp){team_tourney_points+=atp;}
	       void set_team_id(int id){team_id=id;}
	       int get_team_id(){return team_id;}
               int get_id(){return id;}
               int get_ability(){return ability;}
               int get_weight(){return weight;}
	       bool get_selected(){return selected;}
               void set_selected(bool sel){selected=sel;}
	       int get_wins()const{return wins;}
	       void set_wins(int w){wins=w;}
	       void add_win(){wins++;}
               int get_losses(){return losses;}
	       void set_losses(int l){losses=l;}
	       void add_loss(){losses++;}
               // operator overloading
               wrestler& operator=(const wrestler& copy);
               bool operator==(const wrestler& other)const;
               bool operator!=(const wrestler& other)const;
	       bool operator<(const wrestler& other)const;
	       // print function
               void tourney_print();
	       void print(std::ostream& out);
	       //other functions
	       static bool most_wins(const wrestler one, const wrestler two);

     };

/////// inline functions for << and >> operators
///////
     //
     // 
     inline std::ostream& operator<<(std::ostream& out, wrestler& printer)
     {
          printer.print(out);
          return out;
     }
     inline std::istream& operator>>(std::istream& in, wrestler& reciever)
     {
          in.ignore(100, '\n');
          return in;
     }

#endif//WRESTLER_H_INCLUDED

