// Timothy Baker
// cs361
// Assg: Wrestling Simulator
//
// tournament.h

#ifndef TOURNAMENT_H_INCLUDED
#define TOURNAMENT_H_INCLUDED

#include "weight.h"
#include "team.h"
#include "records.h"
#include "tourneyWeight.h"
#include <list>

using namespace std;

/////// class for tournment object
///////
     //
     //
     class tournament
     {
	 private:
            team* team1;
            team* team2;
	    team* team3;
            team* team4;
	    team* team5;
	    team* team6;
            team* team7;
            team* team8;
            team first_place;
            team second_place;
            team third_place;
            team fourth_place;
            team fifth_place;
            team sixth_place;
            team seventh_place;
            team eigth_place;
	    tourney_weight w_103;
	    tourney_weight w_112;
 	    tourney_weight w_118;
	    tourney_weight w_126;
	    tourney_weight w_132;
	    tourney_weight w_138;
	    tourney_weight w_145;
	    tourney_weight w_155;
	    tourney_weight w_167;
	    tourney_weight w_189;
	    tourney_weight w_212;
	    tourney_weight w_285;

	 public:
	     //constructors and destructor
	     tournament(){}
	     tournament(record_book &record_book, team* t1, team* t2, team* t3, team* t4, team* t5, team* t6, team* t7, team* t8);
	     ~tournament(){}
	     //setters and getters

	     //operator overloading
	   
	     //print
	     void print();

     };

#endif//TOURNAMENT_H_INCLUDED
