#ifndef _RUNWAY_H_
#define _RUNWAY_H_

#include "Extended_queue.h"

enum Runway_activity
{
	idle,
	land,
	takeoff
};
class Runway
{
public:
	Runway(int limit);
	Error_code can_land(const Plane &current);
	Error_code can_depart(const Plane &current);
	Runway_activity activity(int time, Plane &moving);
	void shut_down(int time) const;

private:
	Extended_queue landingQ;
	Extended_queue takeoffQ;
	int queue_limit;
	int num_land_requests;
	int num_takeoff_requests;
	int num_landings;
	int num_takeoffs;
	int num_land_accepted;
	int num_takeoff_accepted;
	int num_land_refused;
	int num_takeoff_refused;
	int land_wait;
	int takeoff_wait;
	int idle_time;

	//----------------
	Extended_queue crashQ;
	int num_crashed;
	int num_insert;
	//-----------------
};
#endif
#pragma once
