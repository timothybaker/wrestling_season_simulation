
// Timothy Baker
// cs361
// Assg: Wrestling Simulator
//
// records.h

#ifndef RECORDS_H_INCLUDED
#define RECORDS_H_INCLUDED

#include "wrestler.h"
#include <list>

using namespace std;

/////// create a struct for a record_book entry that contains the team_id and 
/////// wrastler id.
     //
     //
     struct entry
     {
          private:
               int team_id;
               int id;
               wrestler* wrestler_entry;

          public:
               // constructors and destructor
               entry(){team_id=id=0; wrestler_entry=NULL;}
               entry(int t,int i, wrestler* wrastler)
               {
                    team_id=t;
                    id=i;
                    wrestler_entry=wrastler;
               }
               ~entry(){}
               // setters and getters
               void set_wrestler(wrestler *wrastler){wrestler_entry=wrastler;}
	       wrestler* get_wrestler(){return wrestler_entry;}
               void set_team_id(int tid){team_id=tid;}
               int get_team_id(){return team_id;}
               void set_id(int i){id=i;}
               int get_id(){return id;}
     };

/////// class declaration for record_book object
///////
     //
     //
     class record_book
     {
          private:
               list<entry>wrestler_entries;
               list<entry>::iterator wrestler_entries_itr;
               int **records_array;
               int total_entries;

          public:
               // constructors and destructor
               record_book(int entries)
	       {
		    total_entries=entries;
	 	    records_array=new int *[total_entries]; 
		    for(int i=0;i<total_entries;i++)
	 	    {
			records_array[i]=new int [total_entries];
		    }
               }
               ~record_book(){delete [] records_array;}
               // setters and getters
               void add_player(int team, int id, wrestler *wrastler);
               void increment_entries(){total_entries++;}
               // operator overloading

	       // other functions
               void print(std::ostream& out);
               int array_to_id(int index);
	       void id_to_array(int id_winner, int id_loser);
	       void add_win(int wrestler_one, int wrestler_two){records_array[wrestler_one][wrestler_two]+=1;}
     }; 

#endif//RECORDS_H_INCLUDED
