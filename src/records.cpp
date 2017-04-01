// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// records.cpp

#include "records.h"


/////// add wrestler to record book
///////
     //
     //
     void record_book::add_player(int team, int i, wrestler *wrestler)
     {
          entry* entry_ptr;
          entry_ptr=new entry(team,i, wrestler);
          wrestler_entries.push_back(*entry_ptr);
     }

/////// id to array function to find player in array by id for adding win
///////
     //
     //
     void record_book::id_to_array(int id_winner, int id_loser)
     {
	  int winner=0;
	  int loser=0;
	  int incrementing=0;

	  wrestler_entries_itr=wrestler_entries.begin();
	  while(wrestler_entries_itr!=wrestler_entries.end())
	  { 
	      if(wrestler_entries_itr->get_id()==id_winner)
	      {
                   winner=incrementing;
	      }
              if(wrestler_entries_itr->get_id()==id_loser)
	      {
                   loser=incrementing;
              }
	      incrementing++;
	      wrestler_entries_itr++;
          }
          add_win(winner, loser);
     }

/////// array to id
///////
     //
     //
     int record_book::array_to_id(int index)
     {
          wrestler_entries_itr=wrestler_entries.begin();
	  for(int z=0;z<index;z++)
	  {
	      wrestler_entries_itr++;
	  }
	  return wrestler_entries_itr->get_id();
     }

/////// print records
///////
     //
     //
     void record_book::print(std::ostream& out)
     {
          for(int i=0;i<total_entries;i++)
	  {    
               if(i==0)
	       {
                    for(int k=0;k<total_entries;k++)
	            {
	     	        out<<"\t"<<array_to_id(k)<<"\t";
                    }
		    out<<endl;
               }
               out<<array_to_id(i)<<"\t";
	       for(int j=0;j<total_entries;j++)
	       {  
                    out<<records_array[i][j]<<"\t\t";
               }
	       out<<endl;
          }
     }

