#include <iostream>
#include <fstream> //file handling
#include <stdlib.h>
#include <vector>
#include <algorithm> // std::find
#include "Plane.h"
#include "Runway.h"
#include "Random.h"
using namespace std;

typedef enum Error_code;
void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate);
void run_idle(int time);
int main()
{
	int end_time;
	int queue_limit;
	int flight_number = 0;
	double arrival_rate, departure_rate;
	Random variable;
	vector<int> bp; //debug-break-point
	
	//-------choose static data mode or not-----------------------
	bool is_static_mode = false;
	char ch;
	cout << "Enable static data mode? (y/n)" << flush;
	cin >> ch;
	if (ch == 'y')
		is_static_mode = true;

	if (is_static_mode)
	{
		end_time = 1000;
		queue_limit = 5;
		arrival_rate = departure_rate = 0.48;
	}
	else
		initialize(end_time, queue_limit, arrival_rate, departure_rate);

	Runway small_airport(queue_limit);
	//--------------------------------------------------------------

	//------debug mod----------------------------------------------
	bool is_debug_mode = false;
	//char ch;
	cout << "Enable debug mode? (y/n)" << flush;
	cin >> ch;
	if (ch == 'y')
	{
		is_debug_mode = true;
		cout << "---        debug toolkits help     ---" << endl
			 << "--- [n] - next time unit           ---" << endl
			 << "--- [b] - set beark point          ---" << endl
			 << "--- [c] - continue until end or bp ---" << endl;
	}
	//------------------------------------------------------------

	//------write a text case to preset-data.txt-------------------
	//ofstream outfile;
	//outfile.open("preset-data.txt", ios::out | ios::trunc );
	//-------------------------------------------------------------

	//-----read test cases from preset-data.txt--------------------
	ifstream infile;
	infile.open("preset-data.txt");
	//-------------------------------------------------------------

	for (int current_time = 0; current_time < end_time; current_time++)
	{

		//------write a text case to preset-data.txt----------------
		//int number_arrivals = variable.poisson(arrival_rate);
		//outfile << number_arrivals << " " << flush;
		//----------------------------------------------------------

		//-----read test cases from preset-data.txt----------------
		int number_arrivals;
		if (is_static_mode)
			infile >> number_arrivals;
		else
			number_arrivals = variable.poisson(arrival_rate);
		//---------------------------------------------------------

		for (int i = 0; i < number_arrivals; i++)
		{
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		//------write a text case to preset-data.txt---------------
		//int number_departures = variable.poisson(departure_rate);
		//outfile << number_departures << endl;
		//-------------------------------------------------------

		//-----read test cases from preset-data.txt----------------
		int number_departures;
		if (is_static_mode)
			infile >> number_departures;
		else
			number_departures = variable.poisson(departure_rate);
		//--------------------------------------------------------

		for (int j = 0; j < number_departures; j++)
		{
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}
		Plane moving_plane;
		switch (small_airport.activity(current_time, moving_plane))
		{
		case land:
			moving_plane.land(current_time);
			break;
		case takeoff:
			moving_plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
			break;
		}
		//------debug mod----------------------------------------------
		if (bp.end() != find(bp.begin(), bp.end(), current_time) || is_debug_mode)
		{
			char debug_option;
			cin >> debug_option;
			if (debug_option == 'n' || debug_option == '\n')
				continue;
			if (debug_option == 'b')
			{
				int line_num;
				cin >> line_num;
				if (current_time < line_num && line_num < end_time)
					bp.push_back(line_num);
				else
				{
					cout << "invaild break point" << endl; //
					system("pause");
				}
			}
			if (debug_option == 'c')
				is_debug_mode = false;
		}
		//-------------------------------------------------------------
	}

	//------write a text case to preset-data.txt---------------
	//outfile.close();
	//--------------------------------------------------------

	//------write a text case to preset-data.txt--------------
	infile.close();
	//----------------------------------------------------------

	small_airport.shut_down(end_time);

	system("pause");
}

void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate)
{
	cout << "This program simulates an airport with only one runway." << endl
		 << "One plane can land or depart in each unit of time." << endl;
	cout << "Up to what number of planes can be waiting to land "
		 << "or take off at any time?" << flush;
	cin >> queue_limit;
	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;
	bool acceptable;
	do
	{
		cout << "Expected number of arrivals per unit time?" << flush;
		cin >> arrival_rate;
		cout << "Expected number of departures per unit time?" << flush;
		cin >> departure_rate;
		if (arrival_rate < 0.0 || departure_rate < 0.0)
			cerr << "These rates must be nonegative." << endl;
		else
			acceptable = true;
		if (acceptable && arrival_rate + departure_rate > 1.0)
			cerr << "Safety warning: This airport will become saturated." << endl;
	} while (!acceptable);
}

void run_idle(int time)
{
	cout << time << ":Runway is idle " << endl;
}
