
// Timothy Baker
// cs361 
// Assg1: Wrestling-Simulation
//
// team.cpp

#include "team.h"

/////// create list of wrestlers
///////
     //
     //
     void team::initialize_wrestlers()
     {
          wrestler* wrestlers_ptr;
          for(int i=0; i<players; i++)
          {
               wrestlers_ptr = new wrestler(team_id);
               wrestlers.push_back(wrestlers_ptr);
          }
     }

/////// initializing constructor
///////
     //
     //
     team::team(int p, int id)
     {
 	  team_id=id;
          team_points=0;
          team_points_bak=0;
          tourney_points=0;
          tourney_selecter=false;
          players=p;
	  this->initialize_wrestlers();
          w_103=weight(103);
	  w_112=weight(112);
	  w_118=weight(118);
	  w_126=weight(126);
	  w_132=weight(132);
	  w_138=weight(138);
	  w_145=weight(145);
	  w_155=weight(155);
	  w_167=weight(167);
	  w_189=weight(189);
	  w_212=weight(212);
	  w_285=weight(285);
          fill_weight_classes();
     }

/////// fill all the weight classes with best candidate
///////
     //
     //
     void team::fill_weight_classes()
     {
          fill_weight_class(w_103); 
	  fill_weight_class(w_112);
	  fill_weight_class(w_118);
	  fill_weight_class(w_126);
          fill_weight_class(w_132);
	  fill_weight_class(w_138);
	  fill_weight_class(w_145);
	  fill_weight_class(w_155);
	  fill_weight_class(w_167);
	  fill_weight_class(w_189);
	  fill_weight_class(w_212);
	  fill_weight_class(w_285);
     }

     //
     //
     void team::fill_weight_class(weight& wait)
     {
               
                   if(wait.get_weight()==103)
		   {
		       find_candidate(wait, 92, 104);
		   }
		   if(wait.get_weight()==112)
	 	   {
                       find_candidate(wait, 92, 113);
		   }
                   if(wait.get_weight()==118)
		   {
                       find_candidate(wait, 103, 119);
                   }
                   if(wait.get_weight()==126)
                   {
                       find_candidate(wait, 112, 127);
                   }
                   if(wait.get_weight()==132)
                   {
		       find_candidate(wait, 118, 133);
                   }
 		   if(wait.get_weight()==138)
		   {
			find_candidate(wait, 127, 139);
                   }
		   if(wait.get_weight()==145)
		   {
  		        find_candidate(wait, 132, 146);
                   }
		   if(wait.get_weight()==155)
		   {
			find_candidate(wait, 138, 156);
                   }
                   if(wait.get_weight()==167)
	           {
                       find_candidate(wait, 145, 168);
                   }
                   if(wait.get_weight()==189)
	           {
                       find_candidate(wait, 155, 190);
                   }
		   if(wait.get_weight()==212)
		   {
                       find_candidate(wait, 167, 213);
                   }
                   if(wait.get_weight()==285)
 	 	   {
                        find_candidate(wait, 189, 286);
                   }
	      
     }

     //
     //
     void team::find_candidate(weight& wait, int lower_bound, int upper_bound)
     {
	  wrestlers_itr=wrestlers.begin();
	  bool candidate_exist=false;
	  bool candidate_is_NULL=true;
	  wrestler* candidate;

	  while(wrestlers_itr!=wrestlers.end())
	  {
               if((*wrestlers_itr)->get_weight() > lower_bound && (*wrestlers_itr)->get_weight() < upper_bound)
	       {
		   if((*wrestlers_itr)->get_selected()==false)
		   {
                        candidate_is_NULL=false;
	 	        candidate=(*wrestlers_itr);
	                candidate_exist=true;
              	        break;
		   }
	       }
	       wrestlers_itr++;
	  }

	  if (candidate_is_NULL==false)
	  {
               while(wrestlers_itr!=wrestlers.end())
	       {
	            if(candidate->get_ability() <= (*wrestlers_itr)->get_ability())
	            {
		         if(candidate->get_ability() < (*wrestlers_itr)->get_ability())
                         {                  
  			         if((*wrestlers_itr)->get_selected()==false)
			         {
                        	      if((*wrestlers_itr)->get_weight() > lower_bound && (*wrestlers_itr)->get_weight() < upper_bound)
		        	      {
                             	           candidate=*(wrestlers_itr);
			                   candidate_exist=true;
                                      }
		    	         }
	       	          }
                          else //equal abilties, heavier won wins
	                  {    
                                 if(candidate->get_weight()<= (*wrestlers_itr)->get_weight())
			         {
                                      if((*wrestlers_itr)->get_weight() > lower_bound && (*wrestlers_itr)->get_weight() < upper_bound)
				      {
				           candidate=*wrestlers_itr;
				           candidate_exist=true;
				      }
			         }	
		          }
                     }
	             wrestlers_itr++;
	        }
	  }
	  if(candidate_exist==true)
	  {
	       candidate->set_selected(true);
	       wait.set_wrestler(candidate);
  	  }
     }

   	 
/////// get wrestler at index i
///////
     //
     //
     wrestler team::get_wrestler(int i)
     {
          this->reset_itr();
          for(int j=0;j<i;j++)
	  {
               wrestlers_itr++;
          }
          return (**wrestlers_itr);
     }

/////// get address of wrestler at index i
///////
     //
     //
     wrestler* team::get_wrestler_ptr(int i)
     {
	 this->reset_itr();
	 for(int j=0;j<i;j++)
	 {
	     wrestlers_itr++;
	 }
         return *wrestlers_itr;
     }

/////// gather team points from wrestlers after tournaments
///////
     //
     //
     void team::gather_tourney_points()
     {
          wrestlers_itr=wrestlers.begin();
          while(wrestlers_itr!=wrestlers.end())
          {
              update_team_points((*wrestlers_itr)->get_team_tourney_points());
              (*wrestlers_itr)->set_team_tourney_points(0);
              wrestlers_itr++;
          }
     }
    
/////// record tourney points for current tournament
///////
     //
     //
     void team::record_tourney_points()
     {
          tourney_points=0;
          wrestlers_itr=wrestlers.begin();
          while(wrestlers_itr!=wrestlers.end())
          {
              add_tourney_points((*wrestlers_itr)->get_team_tourney_points());
              wrestlers_itr++;
          }
     }

/////// print out wrestlers
///////
     //
     //
     void team::print_wrestlers()
     {
          this->wrestlers_itr=this->wrestlers.begin();
          while(this->wrestlers_itr!=this->wrestlers.end())
          {
               (*wrestlers_itr)->print(cout);
               wrestlers_itr++;
          }
     }

/////// print team
///////
     //
     //
     void team::print(std::ostream& out)
     {
          cout<<team_id<<"\t   "<<team_points<<endl;
     }

/////// print selected wrestlers from each weight class
///////
     //
     //
     void team::print_selected_wrestlers()
     { 
          cout<<"CLASS"<<"\t"<<"ID"<<"\t"<<"  WEIGHT"<<"   "<<"ABILITY"<<endl;
          cout<<"103lb"<<"\t"<<w_103.get_wrestler()->get_id()<<"\t  "<<w_103.get_wrestler()->get_weight()<<"\t   "<<w_103.get_wrestler()->get_ability()<<endl;
          cout<<"112lb"<<"\t"<<w_112.get_wrestler()->get_id()<<"\t  "<<w_112.get_wrestler()->get_weight()<<"\t   "<<w_112.get_wrestler()->get_ability()<<endl;
          cout<<"118lb"<<"\t"<<w_118.get_wrestler()->get_id()<<"\t  "<<w_118.get_wrestler()->get_weight()<<"\t   "<<w_118.get_wrestler()->get_ability()<<endl;
          cout<<"126lb"<<"\t"<<w_126.get_wrestler()->get_id()<<"\t  "<<w_126.get_wrestler()->get_weight()<<"\t   "<<w_126.get_wrestler()->get_ability()<<endl;
          cout<<"132lb"<<"\t"<<w_132.get_wrestler()->get_id()<<"\t  "<<w_132.get_wrestler()->get_weight()<<"\t   "<<w_132.get_wrestler()->get_ability()<<endl;
          cout<<"138lb"<<"\t"<<w_138.get_wrestler()->get_id()<<"\t  "<<w_138.get_wrestler()->get_weight()<<"\t   "<<w_138.get_wrestler()->get_ability()<<endl;
          cout<<"145lb"<<"\t"<<w_145.get_wrestler()->get_id()<<"\t  "<<w_145.get_wrestler()->get_weight()<<"\t   "<<w_145.get_wrestler()->get_ability()<<endl;
          cout<<"155lb"<<"\t"<<w_155.get_wrestler()->get_id()<<"\t  "<<w_155.get_wrestler()->get_weight()<<"\t   "<<w_155.get_wrestler()->get_ability()<<endl;
          cout<<"167lb"<<"\t"<<w_167.get_wrestler()->get_id()<<"\t  "<<w_167.get_wrestler()->get_weight()<<"\t   "<<w_167.get_wrestler()->get_ability()<<endl;
          cout<<"189lb"<<"\t"<<w_189.get_wrestler()->get_id()<<"\t  "<<w_189.get_wrestler()->get_weight()<<"\t   "<<w_189.get_wrestler()->get_ability()<<endl;
          cout<<"212lb"<<"\t"<<w_212.get_wrestler()->get_id()<<"\t  "<<w_212.get_wrestler()->get_weight()<<"\t   "<<w_212.get_wrestler()->get_ability()<<endl;
          cout<<"285lb"<<"\t"<<w_285.get_wrestler()->get_id()<<"\t  "<<w_285.get_wrestler()->get_weight()<<"\t   "<<w_285.get_wrestler()->get_ability()<<endl;
     }

/////// less than operator
///////
     //
     //
     bool team::operator<(const team& other)const
     {

      if(this->team_points<other.team_points)
      {
	 return true;
      }
      return false;
     }

/////// assignment operator
///////
     //
     //
     team& team::operator=(const team& copy)
     {
          this->players=copy.players;
	  this->team_id=copy.team_id;
	  this->team_points=copy.team_points;
	  this->w_103=copy.w_103;
          this->w_112=copy.w_112;
          this->w_118=copy.w_118;
          this->w_126=copy.w_126;
          this->w_132=copy.w_132;
          this->w_138=copy.w_138;
          this->w_145=copy.w_145;
          this->w_155=copy.w_155;
          this->w_167=copy.w_167;
          this->w_189=copy.w_189;
          this->w_212=copy.w_212;
          this->w_285=copy.w_285;

          return *this;
     }
     
	
