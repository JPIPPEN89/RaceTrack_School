//  Joshua Pippen

#pragma once
#ifndef LANE_JP_H
#define	LANE_JP_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#include "Car_JP.h"

class Lane {
private:
	short rtBound;

	short cntr;
	
	short ltBound;
	
	Car car;
	
	string name;

public:
	Lane();

	Lane(short _ltBound, short _cntr, short _rtBound, Car _car, string _name);

	void SetLtBound(short _ltBound);

	void SetRtBound(short _rtBound);

	void SetCntr(short _cntr);

	void SetCar(Car _car);

	void SetName(string _name);

	short GetLtBound();

	short GetRtBound();

	short GetCntr();

	Car* GetCar();

	string GetName();
};




#endif