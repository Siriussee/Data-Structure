#include "Plane.h"
#include <iostream>
using namespace std;

Plane::Plane()
{
	flt_num = -1;
	clock_start = -1;

	fuels = -1;

	state = null;
}
Plane::Plane(int flt, int time, Plane_status status)
{
	flt_num = flt;
	clock_start = time;
	state = status;
	cout << "Plane number " << flt << " ready to ";

	//-----------------------------------------------------
	if (status == arriving)
	{
		cout << "land." << endl;
		srand(666);
		fuels = rand() % 3;
	}
	else
	{
		cout << "take off." << endl;
		fuels = -1;
	}
	//-----------------------------------------------------
}
void Plane::refuse() const
{
	cout << "Plane number " << flt_num;
	if (state == arriving)
		cout << " directed to another airport" << endl;
	else
		cout << "told to try to take off again later" << endl;
}
bool Plane::land(int time) const
{
	int wait = time - clock_start;
	if (wait <= fuels)
	{
		cout << time << ":Plane number " << flt_num << " landed after "
			 << wait << " time unit" << ((wait == 1) ? "" : "s")
			 << " in the landing queue." << endl;
		return true;
	}
	else
	{
		cout << time << ":Plane number " << flt_num << " crashed after "
			 << wait << " time unit" << ((wait == 1) ? "" : "s")
			 << " in the landing queue." << endl;
		return false;
	}
}
void Plane::fly(int time) const
{
	int wait = time - clock_start;
	cout << time << ":Plane number " << flt_num << " took off after "
		 << wait << " time unit" << ((wait == 1) ? "" : "s")
		 << " in the takeoff queue." << endl;
}
int Plane::started() const
{
	return clock_start;
}
//-------------------------------------
int Plane::get_fuels() const
{
	return fuels;
}

void Plane::use_fuels()
{
	fuels--;
}
