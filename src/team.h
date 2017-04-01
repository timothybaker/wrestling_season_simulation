// Timothy Baker
// cs361
// Assg1: Wrestling Simulator
//
// team.h

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "wrestler.h"
#include "weight.h"
#include "records.h"
#include <list>

using namespace std;

/////// class declaration for team object
///////
     //
     //
     class team
     {
          private:
               int tourney_points;
               int team_points_bak;
               bool tourney_selecter;
               int players;
               int team_id;
               int team_points;
               string place;
               weight w_103;
               weight w_112;
 	       weight w_118;
               weight w_126;
               weight w_132;
               weight w_138;
               weight w_145;
               weight w_155;
               weight w_167;
               weight w_189;
               weight w_212;
               weight w_285;
               list<wrestler*>wrestlers;
               list<wrestler*>::iterator wrestlers_itr;
               record_book* record_book_ptr;

         public:
               // constructors and destructor
               team(){tourney_selecter=false; players=team_id=team_points=team_points_bak=tourney_points=0;}
               team(int p, int id);
               ~team(){}
               // setters and getters
               void set_place(string s){place=s;}
               string get_place(){return place;}
               void set_tourney_selecter(bool selecter){tourney_selecter=selecter;}
               bool get_tourney_selecter(){return tourney_selecter;}
               void set_tourney_points(int tp){tourney_points=tp;}
               int get_tourney_points(){return tourney_points;}
               void add_tourney_points(int atp){tourney_points+=atp;}
               int get_players(){return players;}
	       void set_team_id(int id){team_id=id;set_wrestlers_team(id);}
	       int get_team_id(){return team_id;}
               void set_team_points(int tp){team_points=tp;}
               int get_team_points(){return team_points;}
               void set_team_points_bak(int tp){team_points_bak=tp;}
               int get_team_points_bak(){return team_points;}
	       int* tp_ptr(){return &team_points;}
               record_book* get_record_book_ptr(){return record_book_ptr;}
               void set_record_book_ptr(record_book* rb){record_book_ptr=rb;}
               weight get_w_103(){return w_103;}
               weight get_w_112(){return w_112;}
               weight get_w_118(){return w_118;}
               weight get_w_126(){return w_126;}
               weight get_w_132(){return w_132;}
               weight get_w_138(){return w_138;}
               weight get_w_145(){return w_145;}
               weight get_w_155(){return w_155;}
               weight get_w_167(){return w_167;}
               weight get_w_189(){return w_189;}
               weight get_w_212(){return w_212;}
               weight get_w_285(){return w_285;}
               weight* get_w_103_ptr(){return &w_103;}
               weight* get_w_112_ptr(){return &w_112;}
               weight* get_w_118_ptr(){return &w_118;}
               weight* get_w_126_ptr(){return &w_126;}
               weight* get_w_132_ptr(){return &w_132;}
               weight* get_w_138_ptr(){return &w_138;}
               weight* get_w_145_ptr(){return &w_145;}
               weight* get_w_155_ptr(){return &w_155;}
               weight* get_w_167_ptr(){return &w_167;}
               weight* get_w_189_ptr(){return &w_189;}
               weight* get_w_212_ptr(){return &w_212;}
               weight* get_w_285_ptr(){return &w_285;}
               void set_w_103(weight w){w_103=w;}
               void set_w_112(weight w){w_112=w;}
               void set_w_118(weight w){w_118=w;}
               void set_w_126(weight w){w_126=w;}
               void set_w_132(weight w){w_132=w;}
               void set_w_138(weight w){w_138=w;}
               void set_w_145(weight w){w_145=w;}
               void set_w_155(weight w){w_155=w;}
               void set_w_167(weight w){w_167=w;}
               void set_w_189(weight w){w_189=w;}
               void set_w_212(weight w){w_212=w;}
               void set_w_285(weight w){w_285=w;} 
               wrestler get_wrestler(int i);
	       wrestler* get_wrestler_ptr(int i);
               void reset_itr(){wrestlers_itr=wrestlers.begin();}
               // operator overloading
               team& operator=(const team& copy);
	       bool operator<(const team& other)const;
               // other functions
               void backup_team_points(){team_points_bak=team_points;}
               void team_points_to_tourney_points(){team_points=tourney_points;}
               void restore_team_points(){team_points=team_points_bak;}
               void initialize_wrestlers();
               void set_wrestlers_team(int id);
               void print(std::ostream& out);
               void print_wrestlers();
	       void print_selected_wrestlers();
	       void update_team_points(int additional){team_points+=additional;}
	       void fill_weight_classes();
	       void fill_weight_class(weight& wait);
	       void find_candidate(weight& wait, int lower_bound, int upper_bound);
               void record_tourney_points();
               void gather_tourney_points();
     };

/////// inline functions for << operator
///////
     //
     // 
     inline std::ostream& operator<<(std::ostream& out, team& printer)
     {
          printer.print(out);
          return out;
     }


#endif //TEAM_H_INCLUDED
