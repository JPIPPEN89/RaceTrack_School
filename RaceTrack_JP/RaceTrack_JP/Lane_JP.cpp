//Joshua Pippen

#include "Lane_JP.h"
#include "Car_JP.h"

Lane::Lane() {
	rtBound = -1;
	cntr = -1;
	ltBound = -1;
	name = "Unspecified";
}

Lane::Lane(short _ltBound, short _cntr, short _rtBound, Car _car, string _name) {
	rtBound = _rtBound;
	cntr = _cntr;
	ltBound = _ltBound;
	car = _car;
	name = _name;
	
}

void Lane::SetLtBound(short _ltBound) {
	ltBound = _ltBound;
}

void Lane::SetRtBound(short _rtBound) {
	rtBound = _rtBound;
}

void Lane::SetCntr(short _cntr) {
	cntr = _cntr;
}

void Lane::SetCar(Car _car) {
	car = _car;
}

void Lane::SetName(string _name) {
	name = _name;
}

short Lane::GetLtBound() {
	return ltBound;
}

short Lane::GetRtBound() {
	return rtBound;
}

short Lane::GetCntr() {
	return cntr;
}

Car* Lane::GetCar() {
	return &car;
}

string Lane::GetName() {
	return name;
}