#ifndef _PLANE_H_
#define _PLANE_H_

enum Plane_status{null, arriving, departing};
class Plane {
public:
	Plane();
	Plane(int flt, int time, Plane_status status);
	void refuse() const;
	void land(int time) const;
	void fly(int time) const;
	int started() const;
private:
	int flt_num;
	int clock_start;

	int fuels;	//p5

	Plane_status state;
};
#endif // _PLANE_H_

