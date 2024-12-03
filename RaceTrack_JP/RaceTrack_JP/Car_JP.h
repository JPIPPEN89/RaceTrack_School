//  Joshua Pippen

#pragma once
#ifndef CAR_JP_H
#define	CAR_JP_H

#include "Position_JP.h"

class Car {
private:
	int icon;

	Position position;

public:
	Car();

	Car(char _icon);

	void SetIcon(int _icon);

	void SetPosition(Position _position);

	char GetIcon();

	Position GetPosition();

};



#endif