
// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// meet.cpp

#include "meet.h"
#include "records.h"
#include "team.h"
#include <random>
#include <cmath>

int determine_points(double i);
int determine_tourney_points(double i);
void chosen_won(int team_one_ability, int team_two_ability, int &power_one, int &power_two);
void bout(int *team_points_one, int *team_points_two, weight *team_one, weight *team_two, record_book &record_book);

/////// randon generator
///////
     //
     //
     default_random_engine random_eng2(time(NULL));
     uniform_int_distribution<int> bool_random_win(0,2);
     
/////// determine Ps and Pw
///////
     //
     //
     void chosen_won(int team_one_ability, int team_two_ability, int &power_one, int &power_two)
     {
         normal_distribution<double> normal_dist_one(team_one_ability, 15);
	 normal_distribution<double> normal_dist_two(team_two_ability, 15);

	power_one=normal_dist_one(random_eng2);
 	power_two=normal_dist_two(random_eng2);
     }
/////// tournament bout
///////
     //
     //
     void tournament_bout(wrestler *&winner, wrestler *&loser, wrestler* one, wrestler* two, record_book &record_book)
     {
	   bool fight=true;
	
           if(one->get_selected()==false)
	   {
                if(two->get_selected()==false)
	        {
                    fight=false;
                    winner=one;
	            loser=two;
                }
		else
	        {
                    fight=false;
                    winner=two;
                    loser=one;
	    	    two->add_team_tourney_points(1);
                }
	   }
	   if(two->get_selected()==false)
	   {
	       if(fight==true && one->get_selected()==true)
	       {
  	           fight=false;
                   winner=one;
                   loser=two;
	    	   one->add_team_tourney_points(1);
	       }
	   }
	   if(fight==true)
	   {
               int power_team_one=0;
	       int power_team_two=0;
	       double how_bad_was_it=0.0;
	       int and_the_winner_is=0;

	       chosen_won(one->get_ability(),two->get_ability(),power_team_one,power_team_two);
	       how_bad_was_it=(abs(power_team_one - power_team_two))/15;
               if(how_bad_was_it==0)
	       {
                   bool random_winner=bool_random_win(random_eng2);
		   if(random_winner==1)
		   {
	    	      one->add_team_tourney_points(2);
                      two->add_team_tourney_points(1);
                      one->add_win();
                      two->add_loss();
                      winner=one;
                      loser=two;
		      record_book.id_to_array(one->get_id(),two->get_id());
                   }
		   if(random_winner==0)
	           {
	    	      two->add_team_tourney_points(2);
                      one->add_team_tourney_points(1);
                      two->add_win();
                      one->add_loss();
                      winner=two;
                      loser=one;
		      record_book.id_to_array(two->get_id(), one->get_id());
                   }
               }
 	       else
               {
   	           and_the_winner_is=determine_tourney_points(how_bad_was_it);
	           if(power_team_one>power_team_two)
	           {
	    	       one->add_team_tourney_points(and_the_winner_is);
                       two->add_team_tourney_points(1);
		       one->add_win();
                       two->add_loss();
                       winner=one;
                       loser=two;
		       record_book.id_to_array(one->get_id(), two->get_id());
	           }
	           if(power_team_one<power_team_two)
	           {
	    	       two->add_team_tourney_points(and_the_winner_is);
                       one->add_team_tourney_points(1);
                       two->add_win();
                       one->add_loss();
                       winner=two;
                       loser=one;
	 	       record_book.id_to_array(two->get_id(), one->get_id());
	           }
              }
	  }
     }

/////// bout definition
///////
     //
     //
     void bout(int *team_points_one, int *team_points_two, weight *team_one, weight *team_two, record_book &record_book)
     {
	   bool fight=true;
	
           if(team_one->get_filled()==false)
	   {
                if(team_two->get_filled()==false)
	        {
                    fight=false;
                }
		else
	        {
                    fight=false;
	    	    *team_points_two+=6;
                }
	   }
	   if(team_two->get_filled()==false)
	   {
	       if(fight==true && team_one->get_filled()==true)
	       {
  	           fight=false;
	           *team_points_one+=6;
	       }
	   }
	   if(fight==true)
	   {
               int power_team_one=0;
	       int power_team_two=0;
	       double how_bad_was_it=0.0;
	       int and_the_winner_is=0;

	       chosen_won(team_one->get_wrestler()->get_ability(),team_two->get_wrestler()->get_ability(),power_team_one,power_team_two);
	       how_bad_was_it=(abs(power_team_one - power_team_two))/15;
               if(how_bad_was_it==0)
	       {
                   bool random_winner=bool_random_win(random_eng2);
		   if(random_winner==1)
		   {
                      *team_points_one+=3;
                      team_one->get_wrestler()->add_win();
		      record_book.id_to_array(team_one->get_wrestler()->get_id(),team_two->get_wrestler()->get_id());
                   }
		   if(random_winner==0)
	           {
                      *team_points_two+=3;
                      team_two->get_wrestler()->add_win();
		      record_book.id_to_array(team_two->get_wrestler()->get_id(), team_one->get_wrestler()->get_id());
                   }
               }
 	       else
               {
   	           and_the_winner_is=determine_points(how_bad_was_it);
	           if(power_team_one>power_team_two)
	           {
                       *team_points_one+=and_the_winner_is;
		       team_one->get_wrestler()->add_win();
		       record_book.id_to_array(team_one->get_wrestler()->get_id(), team_two->get_wrestler()->get_id());
	           }
	           if(power_team_one<power_team_two)
	           {
                       *team_points_two+=and_the_winner_is;
                       team_two->get_wrestler()->add_win();
	 	       record_book.id_to_array(team_two->get_wrestler()->get_id(), team_one->get_wrestler()->get_id());
	           }
              }
	  }
     }

/////// determine team points
///////
     //
     //
     int determine_points(double how_bad_was_it)
     {
          if(how_bad_was_it<0.75){return 3;}
	  if(how_bad_was_it>=.75 && how_bad_was_it<=1.0){return 4;}
          if(how_bad_was_it>1.0 && how_bad_was_it<1.5){return 5;}
 	  if(how_bad_was_it>=1.5){return 6;}
     }

/////// determine tourney_bout points
///////
     //
     //
     int determine_tourney_points(double how_bad_was_it)
     {
          if(how_bad_was_it<1){return 2;}
          if(how_bad_was_it<2 && how_bad_was_it>=1){return 3;}
          if(how_bad_was_it==2){return 4;}
 	  if(how_bad_was_it>2){return 5;}
     }

/////// meet definition
///////
     //
     //
     void meet(int week, team *team_one, team *team_two, record_book &record_book)
     {	
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_103_ptr(), team_two->get_w_103_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_112_ptr(), team_two->get_w_112_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_118_ptr(), team_two->get_w_118_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_126_ptr(), team_two->get_w_126_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_132_ptr(), team_two->get_w_132_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_138_ptr(), team_two->get_w_138_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_145_ptr(), team_two->get_w_145_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_155_ptr(), team_two->get_w_155_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_167_ptr(), team_two->get_w_167_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_189_ptr(), team_two->get_w_189_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_212_ptr(), team_two->get_w_212_ptr(), record_book);
        bout(team_one->tp_ptr(), team_two->tp_ptr(), team_one->get_w_285_ptr(), team_two->get_w_285_ptr(), record_book);
     }


/////// meeter definition
///////
     //
     //
     void weak_meeter(int week,int scheduler[20][20], list<team>::iterator c_meet_itr, list<team>::iterator r_meet_itr, record_book &record_book)
     {
          list<team>::iterator c_reset_itr=c_meet_itr;
	  list<team>::iterator r_reset_itr=r_meet_itr;
	  static bool schedulair[20][20]={false};
          for(int row=0;row<20;row++)
          {
              for(int col=0;col<20;col++)
              {
                  if(scheduler[row][col]==week && schedulair[row][col]==false)
                  {   c_meet_itr=c_reset_itr;
	 	      r_meet_itr=r_reset_itr;
                      team* team_one;
                      team* team_two;
		      schedulair[row][col]=true;
		      schedulair[col][row]=true;
                      for(int i=0;i<20;i++)
                      {
                          if(row+10000==c_meet_itr->get_team_id())
                          {
                              team_one=&*c_meet_itr;
                          }
			  if(row+20000==r_meet_itr->get_team_id())
			  {
			      team_two=&*r_meet_itr;
			  }
                          if(col+10000==c_meet_itr->get_team_id())
                          {
                              team_two=&*c_meet_itr;
                          }
			  if(col+20000==r_meet_itr->get_team_id())
			  {
  	 		       team_two=&*r_meet_itr;
  	 	 	  }
		          c_meet_itr++;
			  r_meet_itr++;
                      }
		      meet(week, team_one, team_two, record_book);
                   }
               }
           }
      }

