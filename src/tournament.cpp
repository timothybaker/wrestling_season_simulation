// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// tournament.cpp

#include "tournament.h"
#include "meet.h"
#include <fstream>

/////// initializing constructor
///////
     // 
     //
     tournament::tournament(record_book &record_book, team* t1, team* t2, team* t3, team* t4, team* t5, team* t6, team* t7, team* t8)
     {
          team1=t1;
	  team2=t2;
          team3=t3;
	  team4=t4;
 	  team5=t5;
 	  team6=t6;
	  team7=t7;
	  team8=t8;

          w_103=tourney_weight(record_book, 103, team1->get_w_103_ptr()->get_wrestler(), team2->get_w_103_ptr()->get_wrestler(), team3->get_w_103_ptr()->get_wrestler(), team4->get_w_103_ptr()->get_wrestler(), team5->get_w_103_ptr()->get_wrestler(), team6->get_w_103_ptr()->get_wrestler(),  team7->get_w_103_ptr()->get_wrestler(), team8->get_w_103_ptr()->get_wrestler());
          w_112=tourney_weight(record_book, 112, team1->get_w_112_ptr()->get_wrestler(), team2->get_w_112_ptr()->get_wrestler(), team3->get_w_112_ptr()->get_wrestler(), team4->get_w_112_ptr()->get_wrestler(), team5->get_w_112_ptr()->get_wrestler(), team6->get_w_112_ptr()->get_wrestler(),  team7->get_w_112_ptr()->get_wrestler(), team8->get_w_112_ptr()->get_wrestler());
          w_118=tourney_weight(record_book,118, team1->get_w_118_ptr()->get_wrestler(), team2->get_w_118_ptr()->get_wrestler(), team3->get_w_118_ptr()->get_wrestler(), team4->get_w_118_ptr()->get_wrestler(), team5->get_w_118_ptr()->get_wrestler(), team6->get_w_118_ptr()->get_wrestler(),  team7->get_w_118_ptr()->get_wrestler(), team8->get_w_118_ptr()->get_wrestler());
          w_126=tourney_weight(record_book,126, team1->get_w_126_ptr()->get_wrestler(), team2->get_w_126_ptr()->get_wrestler(), team3->get_w_126_ptr()->get_wrestler(), team4->get_w_126_ptr()->get_wrestler(), team5->get_w_126_ptr()->get_wrestler(), team6->get_w_126_ptr()->get_wrestler(),  team7->get_w_126_ptr()->get_wrestler(), team8->get_w_126_ptr()->get_wrestler());
          w_132=tourney_weight(record_book,132, team1->get_w_132_ptr()->get_wrestler(), team2->get_w_132_ptr()->get_wrestler(), team3->get_w_132_ptr()->get_wrestler(), team4->get_w_132_ptr()->get_wrestler(), team5->get_w_132_ptr()->get_wrestler(), team6->get_w_132_ptr()->get_wrestler(),  team7->get_w_132_ptr()->get_wrestler(), team8->get_w_132_ptr()->get_wrestler());
          w_138=tourney_weight(record_book,138, team1->get_w_138_ptr()->get_wrestler(), team2->get_w_138_ptr()->get_wrestler(), team3->get_w_138_ptr()->get_wrestler(), team4->get_w_138_ptr()->get_wrestler(), team5->get_w_138_ptr()->get_wrestler(), team6->get_w_138_ptr()->get_wrestler(),  team7->get_w_138_ptr()->get_wrestler(), team8->get_w_138_ptr()->get_wrestler());
          w_145=tourney_weight(record_book,145, team1->get_w_145_ptr()->get_wrestler(), team2->get_w_145_ptr()->get_wrestler(), team3->get_w_145_ptr()->get_wrestler(), team4->get_w_145_ptr()->get_wrestler(), team5->get_w_145_ptr()->get_wrestler(), team6->get_w_145_ptr()->get_wrestler(),  team7->get_w_145_ptr()->get_wrestler(), team8->get_w_145_ptr()->get_wrestler());
          w_155=tourney_weight(record_book,155, team1->get_w_155_ptr()->get_wrestler(), team2->get_w_155_ptr()->get_wrestler(), team3->get_w_155_ptr()->get_wrestler(), team4->get_w_155_ptr()->get_wrestler(), team5->get_w_155_ptr()->get_wrestler(), team6->get_w_155_ptr()->get_wrestler(),  team7->get_w_155_ptr()->get_wrestler(), team8->get_w_155_ptr()->get_wrestler());
          w_167=tourney_weight(record_book,167, team1->get_w_167_ptr()->get_wrestler(), team2->get_w_167_ptr()->get_wrestler(), team3->get_w_167_ptr()->get_wrestler(), team4->get_w_167_ptr()->get_wrestler(), team5->get_w_167_ptr()->get_wrestler(), team6->get_w_167_ptr()->get_wrestler(),  team7->get_w_167_ptr()->get_wrestler(), team8->get_w_167_ptr()->get_wrestler());
          w_189=tourney_weight(record_book,189, team1->get_w_189_ptr()->get_wrestler(), team2->get_w_189_ptr()->get_wrestler(), team3->get_w_189_ptr()->get_wrestler(), team4->get_w_189_ptr()->get_wrestler(), team5->get_w_189_ptr()->get_wrestler(), team6->get_w_189_ptr()->get_wrestler(),  team7->get_w_189_ptr()->get_wrestler(),  team8->get_w_189_ptr()->get_wrestler());
          w_212=tourney_weight(record_book,212, team1->get_w_212_ptr()->get_wrestler(), team2->get_w_212_ptr()->get_wrestler(), team3->get_w_212_ptr()->get_wrestler(), team4->get_w_212_ptr()->get_wrestler(), team5->get_w_212_ptr()->get_wrestler(), team6->get_w_212_ptr()->get_wrestler(),  team7->get_w_212_ptr()->get_wrestler(), team8->get_w_212_ptr()->get_wrestler());
          w_285=tourney_weight(record_book,285, team1->get_w_285_ptr()->get_wrestler(), team2->get_w_285_ptr()->get_wrestler(), team3->get_w_285_ptr()->get_wrestler(), team4->get_w_285_ptr()->get_wrestler(), team5->get_w_285_ptr()->get_wrestler(), team6->get_w_285_ptr()->get_wrestler(),  team7->get_w_285_ptr()->get_wrestler(), team8->get_w_285_ptr()->get_wrestler());  

     t1->record_tourney_points();
     t2->record_tourney_points();
     t3->record_tourney_points();
     t4->record_tourney_points();
     t5->record_tourney_points();
     t6->record_tourney_points();
     t7->record_tourney_points();
     t8->record_tourney_points();

     t1->backup_team_points();
     t2->backup_team_points();
     t3->backup_team_points();
     t4->backup_team_points();
     t5->backup_team_points();
     t6->backup_team_points();
     t7->backup_team_points();
     t8->backup_team_points();

     t1->team_points_to_tourney_points();
     t2->team_points_to_tourney_points();
     t3->team_points_to_tourney_points();
     t4->team_points_to_tourney_points();
     t5->team_points_to_tourney_points();
     t6->team_points_to_tourney_points();
     t7->team_points_to_tourney_points();
     t8->team_points_to_tourney_points();

     list<team> team_sorter;
     list<team>::iterator team_sorter_itr;
    
     team_sorter.push_back(*t1);
     team_sorter.push_back(*t2);
     team_sorter.push_back(*t3);
     team_sorter.push_back(*t4);
     team_sorter.push_back(*t5);
     team_sorter.push_back(*t6);
     team_sorter.push_back(*t7);
     team_sorter.push_back(*t8);

     team_sorter.sort();
     team_sorter.reverse();

     team_sorter_itr=team_sorter.begin();
     first_place=*team_sorter_itr;
     team_sorter_itr++;
     second_place=*team_sorter_itr;
     team_sorter_itr++;
     third_place=*team_sorter_itr;
     team_sorter_itr++;
     fourth_place=*team_sorter_itr;
     team_sorter_itr++;
     fifth_place=*team_sorter_itr;
     team_sorter_itr++;
     sixth_place=*team_sorter_itr;
     team_sorter_itr++;
     seventh_place=*team_sorter_itr;
     team_sorter_itr++;
     eigth_place=*team_sorter_itr;
     team_sorter_itr++;

     t1->restore_team_points();
     t2->restore_team_points();
     t3->restore_team_points();
     t4->restore_team_points();
     t5->restore_team_points();
     t6->restore_team_points();
     t7->restore_team_points();
     t8->restore_team_points();

     t1->gather_tourney_points();
     t2->gather_tourney_points();
     t3->gather_tourney_points();
     t4->gather_tourney_points();
     t5->gather_tourney_points();
     t6->gather_tourney_points();
     t7->gather_tourney_points();
     t8->gather_tourney_points();

     }
/////// print tournament results to file
///////
     //
     //
     void tournament::print()
     {
          cout<<"Team Victors    "<<"  "<<"Team ID"<<"  "<<"Team Points"<<endl;
          cout<<"First Place   --"<<"  "<<first_place;
          cout<<"Second Place  --"<<"  "<<second_place;
          cout<<"Third Place   --"<<"  "<<third_place;
          cout<<"Fourth Place  --"<<"  "<<fourth_place;
          cout<<"Fifth Place   --"<<"  "<<fifth_place;
          cout<<"Sixth Place   --"<<"  "<<sixth_place;
          cout<<"Seventh Place --"<<"  "<<seventh_place;
          cout<<"Eigth Place   --"<<"  "<<eigth_place;
          cout<<endl;
          cout<<"Hit Enter to View Weigth Class Victors"<<endl;
          cin.get();
          cin.ignore();
          cout<<"Weight Class Victors"<<endl;
          cout<<"103 lbs:"<<endl;
          w_103.print();
          cout<<"112 lbs:"<<endl;
          w_112.print();
          cout<<"118 lbs:"<<endl;
          w_118.print();
          cout<<"126 lbs:"<<endl;
          w_126.print();
          cout<<"132 lbs:"<<endl;
          w_132.print();
          cout<<"138 lbs:"<<endl;
          w_138.print();
          cout<<"145 lbs:"<<endl;
          w_145.print();
          cout<<"155 lbs:"<<endl;
          w_155.print();
          cout<<"167 lbs:"<<endl;
          w_167.print();
          cout<<"189 lbs:"<<endl;
          w_189.print();
          cout<<"212 lbs:"<<endl;
          w_212.print();
          cout<<"285 lbs:"<<endl;
          w_285.print();
     }






