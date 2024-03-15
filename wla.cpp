#include <iostream>
#include <set>
#include <string>

template <typename T> class program_point{
public :
     class program_point **prev;
     class program_point **next;
     int prev_count;
     int next_count;
     int dir; 
     int meet_op;

     std::set<T> set_entry;
     std::set<T> set_exit;
     std::set<T> set_gen;
     std::set<T> set_kill;

     virtual void gen_set();
     virtual void kill_set();
     virtual void transfer_fun_entry();	 
     virtual void transfer_fun_exit();
};

class reaching_def: public program_point
{
public:
     void gen_set()
	  {
	  }
     void kill_set()
	  {
	  }
     void transfer_fun_entry()
	  {
	       std::set<T> temp;
	       for(int i = 0; i < prev_count; i++)
	       {
		    if(prev[i] != NULL)
		    {
			 std::set_union((prev[i]->set_exit).begin(), (prev[i]->set_exit).end(), set_entry.begin(), set_entry.end(), temp.begin());
			 set_entry = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       
	       std::set_difference((set_entry).begin(), (set_entry).end(), (set_kill).begin(), (set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (set_gen).begin(), (set_gen).end(), (set_exit).begin());
	  }
};

class available_exp : Public program_point
{
public:
     void gen_set()
	  {
	  }
     void kill_set()
	  {
	  }
     void transfer_fun_entry()
	  {
	       std::set<T> temp;
	       for(int i = 0; i < prev_count; i++)
	       {


		    if(prev[i] != NULL)
		    {

			 if(i == 0){
			      temp = (prev[i]->set_exit);
			 }
			 std::set_intersection((prev[i]->set_exit).begin(), (prev[i]->set_exit).end(), set_entry.begin(), set_entry.end(), temp.begin());
			 set_entry = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       
	       std::set_difference((set_entry).begin(), (set_entry).end(), (set_kill).begin(), (set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (set_gen).begin(), (set_gen).end(), (set_exit).begin());
	  }
};

class live_var : Public program_point
{
public:
     void gen_set()
	  {
	  }
     void kill_set()
	  {
	  }
     void transfer_fun_entry()
	  {
	       std::set<T> temp;
	       std::set_difference((set_exit).begin(), (set_exit).end(), (set_kill).begin(), (set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (set_gen).begin(), (set_gen).end(), (set_entry).begin());
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       for(int i = 0; i < next_count; i++)
	       {
		    if(next[i] != NULL)
		    {
			 if(i == 0){
			      temp = (next[i]->set_entry);
			 }
			 std::set_union((next[i]->set_entry).begin(), (prev[i]->set_entry).end(), set_exit.begin(), set_exit.end(), temp.begin());
			 set_exit = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
};


class very_busy_exp : Public program_point
{
public:
     void gen_set()
	  {
	  }
     void kill_set()
	  {
	  }
     void transfer_fun_entry()
	  {
	       std::set<T> temp;
	       std::set_difference((set_exit).begin(), (set_exit).end(), (set_kill).begin(), (set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (set_gen).begin(), (set_gen).end(), (set_entry).begin());
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       for(int i = 0; i < next_count; i++)
	       {
		    if(next[i] != NULL)
		    {
			 if(i == 0){
			      temp = (next[i]->set_entry);
			 }
			 std::set_intersection((next[i]->set_entry).begin(), (prev[i]->set_entry).end(), set_exit.begin(), set_exit.end(), temp.begin());
			 set_exit = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
};
