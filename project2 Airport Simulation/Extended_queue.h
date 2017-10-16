#ifndef _EQ_H_
#define _EQ_H_
#include "Plane.h"
#define MAX 200

enum Error_code
{
	success,

	fail
};

class Extended_queue {
public:
	Extended_queue();
	~Extended_queue();
	Error_code append(const Plane &current);
	int size() const;
	bool empty();
	Error_code retrieve(Plane &moving);
	Error_code serve();
	
	//--------------------------------------------
	Error_code push_front(const Plane &current);
	Plane top();	//abandon
	Plane &operator[](int i);
	int get_head();
	int get_rear();
	//--------------------------------------------
private:
	int size_num;
	Plane store[MAX];
	int head, rear;


};
#endif
