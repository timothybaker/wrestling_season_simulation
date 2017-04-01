// Timothy Baker
// cs361 
// Assg1: Wrestling Simulator
//
// meet.h

#include "team.h"
#include "records.h"

#ifndef MEET_H_INCLUDED
#define MEET_H_INCLUDED

/////// meet declaration
///////
     //
     //
     void meet(int week, team team_one, team team_two, record_book &record_book);
     void weak_meeter(int week, int scheduler[20][20],list<team>::iterator c_meet_itr, list<team>::iterator r_meet_itr, record_book &record_book);
     void tournament_bout(wrestler *&winner, wrestler *&loser, wrestler* one, wrestler* two, record_book &record_book);
#endif//MEET_H_INCLUDED
