#include <iostream>
#include <set>
#include <string>
#include <algorithm>

template <typename T> 
class program_point {
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

template <typename T> 
class reaching_def: public program_point<T> {
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
	       for(int i = 0; i < this->prev_count; i++)
	       {
		    if(this->prev[i] != NULL)
		    {
			 std::set_union((this->prev[i]->set_exit).begin(), (this->prev[i]->set_exit).end(), this->set_entry.begin(), this->set_entry.end(), temp.begin());
			 this->set_entry = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       
	       std::set_difference((this->set_entry).begin(), (this->set_entry).end(), (this->set_kill).begin(), (this->set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (this->set_gen).begin(), (this->set_gen).end(), (this->set_exit).begin());
	  }
};

template <typename T> 
class available_exp : public program_point<T>{
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
	       for(int i = 0; i < this->prev_count; i++)
	       {
		    if(this->prev[i] != NULL)
		    {

			 if(i == 0){
			      temp = (this->prev[i]->set_exit);
			 }
			 std::set_intersection((this->prev[i]->set_exit).begin(), (this->prev[i]->set_exit).end(), this->set_entry.begin(), this->set_entry.end(), temp.begin());
			 this->set_entry = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       
	       std::set_difference((this->set_entry).begin(), (this->set_entry).end(), (this->set_kill).begin(), (this->set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (this->set_gen).begin(), (this->set_gen).end(), (this->set_exit).begin());
	  }
};

template <typename T> 
class live_var : public program_point<T>{
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
	       std::set_difference((this->set_exit).begin(), (this->set_exit).end(), (this->set_kill).begin(), (this->set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (this->set_gen).begin(), (this->set_gen).end(), (this->set_entry).begin());
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       for(int i = 0; i < this->next_count; i++)
	       {
		    if(this->next[i] != NULL)
		    {
			 if(i == 0){
			      temp = (this->next[i]->set_entry);
			 }
			 std::set_union((this->next[i]->set_entry).begin(), (this->prev[i]->set_entry).end(), this->set_exit.begin(), this->set_exit.end(), temp.begin());
			 this->set_exit = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
};


template <typename T> 
class very_busy_exp : public program_point<T>{
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
	       std::set_difference((this->set_exit).begin(), (this->set_exit).end(), (this->set_kill).begin(), (this->set_kill).end(), (temp).begin());
	       
	       std::set_union((temp).begin(), (temp).end(), (this->set_gen).begin(), (this->set_gen).end(), (this->set_entry).begin());
	  }
     void transfer_fun_exit()
	  {
	       std::set<T> temp;
	       for(int i = 0; i < this->next_count; i++)
	       {
		    if(this->next[i] != NULL)
		    {
			 if(i == 0){
			      temp = (this->next[i]->set_entry);
			 }
			 std::set_intersection((this->next[i]->set_entry).begin(), (this->prev[i]->set_entry).end(), this->set_exit.begin(), this->set_exit.end(), temp.begin());
			 this->set_exit = temp;
			 temp = std::set<T>();
		    }
	       }
	  }
};
