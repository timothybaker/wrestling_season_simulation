
// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// main.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <random>
#include <ctime>
#include <thread>
#include <string>
#include "team.h"
#include "meet.h"
#include "tournament.h"
#include "records.h"

using namespace std;

            ///\\\                        ///\\                        //
           ////\\\\                      ////\\\                      ///
          /////\\\\\                    /////\\\\                    ////
         //////\\\\\\                  //////\\\\\                  /////
        ///////\\\\\\\                ///////\\\\\\                //////
       ////////\\\\\\\\              ////////\\\\\\\              ///////
      /////////\\\\\\\\\            /////////\\\\\\\\            ////////
     //////////\\\\\\\\\\          //////////\\\\\\\\\          /////////
    ///////////\\\\\\\\\\\        ///////////\\\\\\\\\\        //////////
   ////////////\\\\\\\\\\\\      ////////////\\\\\\\\\\\      ///////////
  /////////////\\\\\\\\\\\\\    /////////////\\\\\\\\\\\\    ////////////
 //////////////\\\\\\\\\\\\\\  //////////////\\\\\\\\\\\\\  /////////////
///////////////\\\\\\\\\\\\\\\///////////////\\\\\\\\\\\\\\//////////////
int main()
{
//
///
////
/////
//////
///////
/////// create random number engine seeded with time and uniform real distribution
/////// agents for the integer numbers between 10 and 18; and 0 and 1.
     //
     //
     default_random_engine random_eng(time(NULL));
     uniform_real_distribution<double> real_dist_1(10, 19);
     uniform_real_distribution<double> real_dist_2(0,2);
     uniform_real_distribution<double> real_dist3(1,18);
     uniform_real_distribution<double> real_dist4(0,20);

/////// create two lists of teams with 10-18 wrestlers.  one a list of 8 conference
/////// teams, and the other a list of 12 random teams.
     //
     //
     list<team>conference_teams;
     list<team>::iterator conference_teams_itr;
     list<team>::iterator tourney_itr;
     team* conference_teams_ptr;

     for(int i=0;i<8;i++)
     {
          conference_teams_ptr = new team(real_dist_1(random_eng),10000+i);
          conference_teams.push_back(*conference_teams_ptr);
     }


     list<team>random_teams;
     list<team>::iterator random_teams_itr;
     team* random_teams_ptr = &*conference_teams.end();
     random_teams_ptr++;

     for(int i=0;i<12;i++)
     {
          random_teams_ptr = new team(real_dist_1(random_eng),20008+i);
          random_teams.push_back(*random_teams_ptr);
     }

/////// create record book with an entry for each player from each team using the
/////// players unique ID.
     //
     //
     int record_players=0;

     conference_teams_itr = conference_teams.begin();
     while(conference_teams_itr!= conference_teams.end())
     {
            record_players += conference_teams_itr->get_players();
	    conference_teams_itr++;
     }
     random_teams_itr = random_teams.begin();
     while(random_teams_itr!= random_teams.end())
     {
	    record_players += random_teams_itr->get_players();
            random_teams_itr++;
     }

     record_book record_book(record_players); //create record book with array sized record_players

     conference_teams_itr = conference_teams.begin();
     while(conference_teams_itr != conference_teams.end())
     {
          int players = conference_teams_itr->get_players();
          for(int i=0; i<players; i++)
          {
	       record_book.add_player(conference_teams_itr->get_team_id(), conference_teams_itr->get_wrestler(i).get_id(),conference_teams_itr->get_wrestler_ptr(i));
               conference_teams_itr->reset_itr();
          }
          conference_teams_itr->set_record_book_ptr(&record_book);
          conference_teams_itr++;
     }

     random_teams_itr = random_teams.begin();
     while(random_teams_itr != random_teams.end())
     {
          int players = random_teams_itr->get_players();
          for(int i=0; i<players; i++)
          {
               record_book.add_player(random_teams_itr->get_team_id(),random_teams_itr->get_wrestler(i).get_id(),random_teams_itr->get_wrestler_ptr(i));
               random_teams_itr->reset_itr();
          }
          random_teams_itr->set_record_book_ptr(&record_book);
          random_teams_itr++;
     }

/////// run scheduler to create 17 weeks of competition. each conference team meets
/////// each other once, then meets 8 other random non-conference teams.
     //
     //
     int scheduler[20][20];
     for (int row=0;row<20;row++)
     {
	   for(int col=0;col<20;col++)
	   {
	       if(row==col){scheduler[row][col]=-1;}
               else{scheduler[row][col]=0;}
           }
     }

     for (int row=0; row<8;row++)
     {
	   bool checked_out=false;
           for(int col=0;col<8;col++)
	   {
	        if(scheduler[row][col]==0)
		{
		    while(checked_out==false)
		    {
			checked_out=true;
	 	    	int week=real_dist3(random_eng);
			for(int i=0;i<row;i++)
			{
			    if(week==scheduler[i][col])
			    {
			          checked_out=false;
			    }
			}
			for (int i=0;i<col;i++)
			{
			    if(week==scheduler[row][i])
			    {
                                 checked_out=false;
			    }
                        }
			if(week==6 || week==12)
			{
			    checked_out=false;
 	                }
			if(checked_out==true)
			{
 			     scheduler[row][col]=week;
                             scheduler[col][row]=week;
			}
		    }
		    checked_out=false;
		}

           }
     }

     for (int row=0; row<8;row++)
     {
           int less_than_eight=0;
	   while(less_than_eight<8)
 	   {
                bool checked_out=false;
		int disaster_blaster=0;
                int col=real_dist4(random_eng);
                if(scheduler[row][col]==0)
                {
                     while(checked_out==false)
                     {    disaster_blaster++;
	  	          checked_out=true;
                          int week=real_dist3(random_eng);
			  for(int i=0;i<20;i++)
                          {
                               if(week==scheduler[i][col])
                               {
                                   checked_out=false;
                               }
                          }
                          for (int i=0;i<20;i++)
                          {
                              if(week==scheduler[row][i])
                              {
                                  checked_out=false;
                              }
                          }
                          if(week==6 || week==12)
                          {
                               checked_out=false;
                          }
                          if(checked_out==true)
                          {
                               scheduler[row][col]=week;
                               scheduler[col][row]=week;
			       less_than_eight++;
                          }
			  if(disaster_blaster>40){break;} // team can't play that week geez ok
		      }
	         }
            }
      }

/////// Meet for the first five weeks of regular season matches
///////
     //
     //
     weak_meeter(1, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(2, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(3, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(4, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(5, scheduler, conference_teams.begin(), random_teams.begin(), record_book);

/////// week 6 tournament 1
///////
     //
     //

     int random_selecter=-1;
     team* t1;
     team* t2;
     team* t3;
     team* t4;
     team* t5;
     team* t6;
     team* t7;
     team* t8;
     bool t1_found=false;
     bool t2_found=false;
     bool t3_found=false;
     bool t4_found=false;
     bool t5_found=false;
     bool t6_found=false;
     bool t7_found=false;
     bool t8_found=false;

	         //set up tournament 1 week 6
                 while(t1_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t1_found=true;
                                t1=&*tourney_itr;
                           }
                      }
                 }

                 while(t2_found==false)
	         {
                      random_selecter=real_dist4(random_eng);
		      if(random_selecter<8)
	              {
	                   tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
		           {
                               tourney_itr++;
                           }
		           if(tourney_itr->get_tourney_selecter()==false)
	                   {
			       tourney_itr->set_tourney_selecter(true);
		               t2_found=true;
			       t2=&*tourney_itr;
			   }
                      }
                 }
                 while(t3_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                              tourney_itr->set_tourney_selecter(true);
		              t3_found=true;
			      t3=&*tourney_itr;
			    }
		       }
                 } 
                 while(t4_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
		               tourney_itr->set_tourney_selecter(true);
		               t4_found=true;
			       t4=&*tourney_itr;
			   }
		      }
                 }
                 while(t5_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t5_found=true;
                                t5=&*tourney_itr;
                           }
                      }
                 }
                 while(t6_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                               tourney_itr->set_tourney_selecter(true);
                               t6_found=true;
                               t6=&*tourney_itr;
                           }
                      }
                 }
                 while(t7_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t7_found=true;
                                t7=&*tourney_itr;
                           }
                      }
                 }
                 while(t8_found==false)
                 {    
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7) 
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                                tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t8_found=true;
                                t8=&*tourney_itr;
                           }
                       }
                 }
                 // hold tournament 1, week 6
                 tournament tourney1_week6(record_book, t1, t2, t3, t4, t5, t6, t7, t8);
	       
                 //set up tournament two week 6
                 t1_found=false;
	         t2_found=false;
		 t3_found=false;
		 t4_found=false;
		 t5_found=false;
	   	 t6_found=false;
	  	 t7_found=false;
		 t8_found=false;
                 t1=NULL;
  		 t2=NULL;
                 t3=NULL;
  		 t4=NULL;
                 t5=NULL;
  		 t6=NULL;
                 t7=NULL;
  		 t8=NULL;

                 while(t1_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t1_found=true;
                                t1=&*tourney_itr;
                           }
                      }
                 }

                 while(t2_found==false)
	         {
                      random_selecter=real_dist4(random_eng);
		      if(random_selecter<8)
	              {
	                   tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
		           {
                               tourney_itr++;
                           }
		           if(tourney_itr->get_tourney_selecter()==false)
	                   {
			       tourney_itr->set_tourney_selecter(true);
		               t2_found=true;
			       t2=&*tourney_itr;
			   }
                      }
                 }
                 while(t3_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                              tourney_itr->set_tourney_selecter(true);
		              t3_found=true;
			      t3=&*tourney_itr;
			    }
		       }
                 } 
                 while(t4_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
		               tourney_itr->set_tourney_selecter(true);
		               t4_found=true;
			       t4=&*tourney_itr;
			   }
		      }
                 }
                 while(t5_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t5_found=true;
                                t5=&*tourney_itr;
                           }
                      }
                 }
                 while(t6_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                               tourney_itr->set_tourney_selecter(true);
                               t6_found=true;
                               t6=&*tourney_itr;
                           }
                      }
                 }
                 while(t7_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t7_found=true;
                                t7=&*tourney_itr;
                           }
                      }
                 }
                 while(t8_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7) 
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                                tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t8_found=true;
                                t8=&*tourney_itr;
                           }
                       }
                 }
                 // hold tournament two, week 6
                 tournament tourney2_week6(record_book, t1, t2, t3, t4, t5, t6, t7, t8);

                 //set all teams tournament selector to false for week 12 tournament
		 conference_teams_itr=conference_teams.begin();
	         while(conference_teams_itr!=conference_teams.end())
	  	 {
                      conference_teams_itr->set_tourney_selecter(false);
		      conference_teams_itr++;
		 }
                 random_teams_itr=random_teams.begin();
	         while(random_teams_itr!=random_teams.end())
		 {
                     random_teams_itr->set_tourney_selecter(false);
                     random_teams_itr++;
		 }
	         
/////// meet for weeks 7-11
///////
     //
     //
     weak_meeter(7, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(8, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(9, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(10, scheduler,conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(11, scheduler, conference_teams.begin(), random_teams.begin(), record_book);

/////// week 12 tournament 2
///////
     //
     // 
            t1_found=false;
            t2_found=false;
            t3_found=false;
            t4_found=false;
            t5_found=false;
            t6_found=false;
            t7_found=false;
            t8_found=false;
            t1=NULL;
            t2=NULL;
            t3=NULL;
  	    t4=NULL;
            t5=NULL;
  	    t6=NULL;
            t7=NULL;
            t8=NULL;

	         //set up tournament 1 week 12
                 while(t1_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t1_found=true;
                                t1=&*tourney_itr;
                           }
                      }
                 }

                 while(t2_found==false)
	         {
                      random_selecter=real_dist4(random_eng);
		      if(random_selecter<8)
	              {
	                   tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
		           {
                               tourney_itr++;
                           }
		           if(tourney_itr->get_tourney_selecter()==false)
	                   {
			       tourney_itr->set_tourney_selecter(true);
		               t2_found=true;
			       t2=&*tourney_itr;
			   }
                      }
                 }
                 while(t3_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                              tourney_itr->set_tourney_selecter(true);
		              t3_found=true;
			      t3=&*tourney_itr;
			    }
		       }
                 } 
                 while(t4_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
		               tourney_itr->set_tourney_selecter(true);
		               t4_found=true;
			       t4=&*tourney_itr;
			   }
		      }
                 }
                 while(t5_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t5_found=true;
                                t5=&*tourney_itr;
                           }
                      }
                 }
                 while(t6_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                               tourney_itr->set_tourney_selecter(true);
                               t6_found=true;
                               t6=&*tourney_itr;
                           }
                      }
                 }
                 while(t7_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t7_found=true;
                                t7=&*tourney_itr;
                           }
                      }
                 }
                 while(t8_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7) 
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                                tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t8_found=true;
                                t8=&*tourney_itr;
                           }
                       }
                 }

                 tournament tourney1_week12(record_book, t1, t2, t3, t4, t5, t6, t7, t8);
	         
                 //set up tournament two week 12
                 t1_found=false;
	         t2_found=false;
		 t3_found=false;
		 t4_found=false;
		 t5_found=false;
	   	 t6_found=false;
	  	 t7_found=false;
		 t8_found=false;
                 t1=NULL;
  		 t2=NULL;
                 t3=NULL;
  		 t4=NULL;
                 t5=NULL;
  		 t6=NULL;
                 t7=NULL;
  		 t8=NULL;

                 while(t1_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t1_found=true;
                                t1=&*tourney_itr;
                           }
                      }
                 }

                 while(t2_found==false)
	         {
                      random_selecter=real_dist4(random_eng);
		      if(random_selecter<8)
	              {
	                   tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
		           {
                               tourney_itr++;
                           }
		           if(tourney_itr->get_tourney_selecter()==false)
	                   {
			       tourney_itr->set_tourney_selecter(true);
		               t2_found=true;
			       t2=&*tourney_itr;
			   }
                      }
                 }

                 while(t3_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                              tourney_itr->set_tourney_selecter(true);
		              t3_found=true;
			      t3=&*tourney_itr;
			    }
		       }
                 }
 
                 while(t4_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter<8)
                      {
                           tourney_itr=conference_teams.begin();
                           for(int i=0;i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
		               tourney_itr->set_tourney_selecter(true);
		               t4_found=true;
			       t4=&*tourney_itr;
			   }
		      }
                 }

                 while(t5_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t5_found=true;
                                t5=&*tourney_itr;
                           }
                      }
                 }
                 while(t6_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                               tourney_itr->set_tourney_selecter(true);
                               t6_found=true;
                               t6=&*tourney_itr;
                           }
                      }
                 }
                 while(t7_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7)
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                               tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t7_found=true;
                                t7=&*tourney_itr;
                           }
                      }
                 }
                 while(t8_found==false)
                 {
                      random_selecter=real_dist4(random_eng);
                      if(random_selecter>7) 
                      {
                           tourney_itr=random_teams.begin();
                           for(int i=8; i<random_selecter;i++)
                           {
                                tourney_itr++;
                           }
                           if(tourney_itr->get_tourney_selecter()==false)
                           {
                                tourney_itr->set_tourney_selecter(true);
                                t8_found=true;
                                t8=&*tourney_itr;
                           }
                       }
                 }

                 tournament tourney2_week12(record_book, t1, t2, t3, t4, t5, t6, t7, t8);

                 //set all teams tournament selector to false 
		 conference_teams_itr=conference_teams.begin();
	         while(conference_teams_itr!=conference_teams.end())
	  	 {
                      conference_teams_itr->set_tourney_selecter(false);
		      conference_teams_itr++;
		 }
                 random_teams_itr=random_teams.begin();
	         while(random_teams_itr!=random_teams.end())
		 {
                     random_teams_itr->set_tourney_selecter(false);
                     random_teams_itr++;
		 }

/////// meet for weeks 13-17
///////
     //
     //
     weak_meeter(13, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(14, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(15, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(16, scheduler, conference_teams.begin(), random_teams.begin(), record_book);
     weak_meeter(17, scheduler, conference_teams.begin(), random_teams.begin(), record_book);

/////// conference tournament
///////
     //
     //

     conference_teams_itr=conference_teams.begin();
     t1=&*conference_teams_itr;
     conference_teams_itr++;
     t2=&*conference_teams_itr;
     conference_teams_itr++;
     t3=&*conference_teams_itr;
     conference_teams_itr++;
     t4=&*conference_teams_itr;
     conference_teams_itr++;
     t5=&*conference_teams_itr;
     conference_teams_itr++;
     t6=&*conference_teams_itr;
     conference_teams_itr++;
     t7=&*conference_teams_itr;
     conference_teams_itr++;
     t8=&*conference_teams_itr;
     tournament conference(record_book, t1, t2, t3, t4, t5, t6, t7, t8);


/////// final results output
///////
     //
     //

     // create a list of teams to copy and sort conference teams by team points without modifying the order of 
     // the conference teams list
     list<team> conference_results;
     list<team>::iterator conference_results_itr;
  
     conference_teams_itr=conference_teams.begin();
     while(conference_teams_itr!=conference_teams.end())
     {
          conference_results.push_back(*conference_teams_itr);
          conference_teams_itr++;
     }
     conference_results.sort();
     conference_results.reverse();

     // set the finishing place for conference teams based on accumulated season points
     conference_results_itr=conference_results.begin();
     conference_results_itr->set_place("1st -- WE ARE THE CHAMPIONS");
     conference_results_itr++;
     conference_results_itr->set_place("2nd -- FIRST LOSER");
     conference_results_itr++;
     conference_results_itr->set_place("3rd -- SECOND LOSER");
     conference_results_itr++;
     conference_results_itr->set_place("4th -- AVERAGE JOES");
     conference_results_itr++;
     conference_results_itr->set_place("5th -- NOBODY KNOWS");
     conference_results_itr++;
     conference_results_itr->set_place("6th -- SORRY SIXTH");
     conference_results_itr++;
     conference_results_itr->set_place("7th -- \"Hey, We didn't Lose!\"");
     conference_results_itr++;
     conference_results_itr->set_place("8th -- LAST PLACE OUCH TRY HARDER");


     cout<<"\n\nWELCOME TO WRASTLIN SEASON SIMULATION OUTPUT STATION!"<<endl;

     string lister="";
     bool done=false;

     while(done==false)
     {
          int selection=0;

          cout<<"CONFERENCE TEAMS"<<endl;
          cout<<"Team ID"<<"\t\t"<<"# of Wrestlers"<<"\t\t"<<"Team points"<<endl;
          conference_teams_itr=conference_teams.begin();
          while(conference_teams_itr!=conference_teams.end())
          {
              cout<< conference_teams_itr->get_team_id()<<setfill('.')<<setw(18)<<"."<< conference_teams_itr->get_players()<<setfill('.')<<setw(23)<<"."<<setw(3)<<right<< conference_teams_itr->get_team_points()<<endl;
              conference_teams_itr++;
          }

          cout<<"NON-CONFERENCE TEAMS"<<endl;
          cout<<"Team ID"<<"\t\t"<<"# of Wrestlers"<<"\t\t"<<"Team points"<<endl;
          random_teams_itr=random_teams.begin();
          while(random_teams_itr!=random_teams.end())
          {
              cout<< random_teams_itr->get_team_id()<<setfill('.')<<setw(18)<<"."<< random_teams_itr->get_players()<<setfill('.')<<setw(23)<<"."<<setw(3)<<right<<random_teams_itr->get_team_points()<<setfill(' ')<<endl;
	      random_teams_itr++;
          }

         cout<<"\nCHOICES"<<endl;
         cout<<"a - List Players from a team"<<endl;
         cout<<"b - Display Scheduler Matrix"<<endl;
         cout<<"c - Display Season Tournament Results"<<endl;
         cout<<"d - Display Conference Tournament Resuls"<<endl;
         cout<<"e - Display Conference Season Results"<<endl;
         cout<<"x - Exit"<<endl;
         cout<<"Enter CHOICE: ";
         cin>>lister;
         cout<<endl;
         if(lister=="x"){done=true;}

         if(lister=="a")
         {
               cout<<"\nEnter team id (integers ONLY!): ";
	       cin>>selection;
	       cout<<endl;
               conference_teams_itr=conference_teams.begin();
	       while(conference_teams_itr!=conference_teams.end())
               {
                    if(selection==conference_teams_itr->get_team_id())
                    {
                          conference_teams_itr->print_wrestlers();
	 	 	  cout<<endl;
	                  conference_teams_itr->print_selected_wrestlers();
			  cout<<endl;
                    }
                    conference_teams_itr++;
               }
               random_teams_itr=random_teams.begin();
               while(random_teams_itr!=random_teams.end())
               {
                    if(selection==random_teams_itr->get_team_id())
                    {
                         random_teams_itr->print_wrestlers();
	  	 	 cout<<endl;
		         random_teams_itr->print_selected_wrestlers();
		  	 cout<<endl;
                    }
                    random_teams_itr++;
               }
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
               cin.ignore();
          }
   
          if(lister=="b")
          {
               cout<<"\nTeam ID Matrix filled with the week the two teams will meet for Regular Season Meets"<<endl;
               for(int row=0;row<20;row++)
               { 
                    cout<<setfill(' ');
                    if(row<8)
                    {
                         cout<<(10000+row)<<"  ";
	            }
                    if(row>7)
                    {
                         cout<<(20000+row)<<"  ";
                    }
                    for(int col=0;col<20;col++)
	            {
                        cout<<setw(2)<<scheduler[row][col]<<" ";
                    }
	            cout<<endl;
               }
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
               cin.ignore();
          }

          if(lister=="c")
          {
               cout<<"\nWeek 6 Tournament 1"<<endl;
               tourney1_week6.print();
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
               cin.ignore();
               cout<<"Week 6 Tournament 2"<<endl;
               tourney2_week6.print();
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
               cout<<"Week 12 Tournament 1"<<endl;
               tourney1_week12.print();
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
               cout<<"Week 12 Tournament 2"<<endl;
               tourney2_week12.print();
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
          }

          if(lister=="d")
          {
               cout<<"\nConference Tournament"<<endl;
               conference.print();
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
          }

          if(lister=="e")
          {
               cout<<"Team ID"<<"\t\t"<<"Team points"<<"\t"<<"Place"<<endl;
               conference_results_itr=conference_results.begin();
               while(conference_results_itr!=conference_results.end())
               {
                   cout<< conference_results_itr->get_team_id()<<setfill('.')<<setw(11)<<"."<<setw(3)<<right<< conference_results_itr->get_team_points()<<setfill('.')<<setw(13)<<"."<<conference_results_itr->get_place()<<endl;
                   conference_results_itr++;
               }
               cout<<setfill(' ');
               cout<<"Hit Enter to continue"<<endl;
               cin.get();
               cin.ignore();
          }

          if(lister=="tb")
          {
               cout<<"\t              &&&&&&&&&        "<<endl;
               cout<<"\t            &&&&&&&&&&&&&        "<<endl;
               cout<<"\t           &&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t          &&&&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t          &&&&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t          &&&&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t          &&&&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t          &&&&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t          &&&&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t           &&&&&&&&&&&&&&&        "<<endl;
               cout<<"\t            &&&&&&&&&&&&&        "<<endl;
               cout<<"\t              &&&&&&&&&        "<<endl;
               cout<<endl;
               cout<<"Author: Timothy Baker <<>> \"Holding the World Inside\""<<endl;
               cout<<&lister<<" << ERROR: Unknown call to lister::system.egg_hunter(found=TRUE))"<<endl;
               cout<<"Exiting Program..."<<endl;
               done=true;

          }
     }

///////
//////
/////
////
///
//
     return 0;
}
///////////////\\\\\\\\\\\\\\\///////////////\\\\\\\\\\\\\\\///////////////
//////////////  \\\\\\\\\\\\\\//////////////  \\\\\\\\\\\\\\//////////////
/////////////    \\\\\\\\\\\\\/////////////    \\\\\\\\\\\\\/////////////
////////////      \\\\\\\\\\\\////////////      \\\\\\\\\\\\////////////
///////////        \\\\\\\\\\\///////////        \\\\\\\\\\\///////////
//////////          \\\\\\\\\\//////////          \\\\\\\\\\//////////
/////////            \\\\\\\\\/////////            \\\\\\\\\/////////
////////              \\\\\\\\////////              \\\\\\\\////////
///////                \\\\\\\///////                \\\\\\\///////
//////                  \\\\\\//////                  \\\\\\//////
/////                    \\\\\/////                    \\\\\/////
////                      \\\\////                      \\\\////
///                        \\\///                        \\\///
//                          \\//                          \\//

