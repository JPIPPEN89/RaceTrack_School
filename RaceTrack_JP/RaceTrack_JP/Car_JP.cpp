//  Joshua Pippen

#include "Car_JP.h"
#include "Position_JP.h"

#include <iostream>
#include <cstdlib>


Car::Car() {
	icon = 'N';
}

Car::Car(char _icon) {
	icon = _icon;
}

void Car::SetIcon(int _icon) {
	icon = _icon;
}

void Car::SetPosition(Position _position) {
	this->position = _position;
}

char Car::GetIcon() {
	return icon;
}

Position Car::GetPosition() {
	return position;
}