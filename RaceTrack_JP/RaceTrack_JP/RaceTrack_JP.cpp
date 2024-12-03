//  Joshua Pippen


#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <time.h>
#include <random>
#include <iomanip>



#include "Lane_JP.h"
#include "Car_JP.h"
#include "Position_JP.h"

using namespace std;

void setCursor(Position position) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { position.col, position.row };
    SetConsoleCursorPosition(hConsole, coord);
}

const short startLine = 30;
vector<Lane*> lanes;

Car car1(206);
Car car2(36);
Car car3(64);
Car car4(156);
Car car5(146);
Car car6(240);

Lane lane1(1, 10, 20, car1, "Lane 1");
Lane lane2(21, 30, 40, car2, "Lane 2");
Lane lane3(41, 50, 60, car3, "Lane 3");             
Lane lane4(61, 70, 80, car4, "Lane 4");
Lane lane5(81, 90, 100, car5, "Lane 5");
Lane lane6(101, 110, 120, car6, "Lane 6");

int main()
{
    bool gameOver = false;
    bool collision = false;
    bool winner = false;
    Position newPosition;
    int counter = 0;
    short fdBk = 0;
    short lftRt = 0;
    int movement;
    Position oldPosition;
    Position cornerText;
    Position LtBoundLane;
    Position RtBoundLane;
    Position OutOfWay;
    Position finishLine;
    Position winnerPosition;
    char theCar;
    string collisionName;

    short col = 0;
    short row = 0;

    lanes.push_back(&lane1);
    lanes.push_back(&lane2);
    lanes.push_back(&lane3);            //populate vector
    lanes.push_back(&lane4);
    lanes.push_back(&lane5);
    lanes.push_back(&lane6);

    OutOfWay.row = 33;                  //setting cursor out of the way
    OutOfWay.col = 1;

    

    for (Lane* _lanes : lanes) {
        newPosition.col = _lanes->GetCntr();
        newPosition.row = startLine;                    //set position of icons
        _lanes->GetCar()->SetPosition(newPosition);
        setCursor(newPosition);
        cout << _lanes->GetCar()->GetIcon();
    }
    finishLine.col = 2;
    finishLine.row = 1;
    setCursor(finishLine);                                  //set position & draw finish line
    cout << left << setfill('-') << setw(118) << "-";

    for (Lane* _lanes : lanes) {
        newPosition.col = _lanes->GetLtBound();
        for (int i = 0; i < 29; i++) {                      //drawing lanes
            newPosition.row = startLine - i;
            setCursor(newPosition);
            cout << '|';
        }
    }

    newPosition.col = lanes.at(5)->GetRtBound();
    for (int i = 0; i < 29; i++) {                      //drawing far right bound lane
        newPosition.row = startLine - i;
        setCursor(newPosition);
        cout << '|';
    }
    while (counter < 10) {
        counter++;
        while (!gameOver) {

            srand(time(0));

            for (Lane* _lanes : lanes) {
                movement = rand() % 100;
                newPosition = _lanes->GetCar()->GetPosition();
                oldPosition = _lanes->GetCar()->GetPosition(); // temp holder to erase old position
                LtBoundLane.col = _lanes->GetLtBound(); //for collision
                RtBoundLane.col = _lanes->GetRtBound(); //for collision

                if (movement >= 0 && movement <= 6) {
                    fdBk = 1;
                }
                else if (movement >= 7 && movement <= 13) {         //Determine which way it will move
                    lftRt = -1;
                }
                else  if (movement >= 14 && movement <= 20) {
                    lftRt = 1;
                }
                else {
                    fdBk = rand() % 3;
                    fdBk++;
                    fdBk *= -1;
                }

                setCursor(oldPosition);   //Erase Old Position to clear icon
                cout << " ";

                newPosition.row += fdBk;
                newPosition.col += lftRt;       //add the movements to car

                fdBk = 0;               //reset movements
                lftRt = 0;

                _lanes->GetCar()->SetPosition(newPosition);
                setCursor(newPosition);
                cout << _lanes->GetCar()->GetIcon();
               
                newPosition.row += 2;                                   //Move icon out of way
                setCursor(newPosition);

                if (_lanes->GetCar()->GetPosition().row <= 1) {
                    winner = true;                                      //For winner
                    gameOver = true;
                    theCar = _lanes->GetCar()->GetIcon();
                   

                    setCursor(cornerText);
                    cout << left << setw(118) << setfill(' ') << " ";       //clear row 0, had icons getting stuck

                    newPosition.row = 1;
                    _lanes->GetCar()->SetPosition(newPosition);             //Setting car on finish line, I liked the way it looked better
                    setCursor(newPosition);
                    cout << _lanes->GetCar()->GetIcon();

                    break;
                }
                else if (_lanes->GetCar()->GetPosition().col == LtBoundLane.col ||
                    _lanes->GetCar()->GetPosition().col == RtBoundLane.col) {
                    collision = true;                                               //lane collision
                    gameOver = true;
                    collisionName = _lanes->GetName();
                    break;
                }
                Sleep(50);
            
            }
            if (winner == true) {       //display for winner

                setCursor(cornerText);
                cout << theCar << " is the winner!" << "     Games Played: " << counter;
                newPosition.row = 2;
                newPosition.col = 1;
                setCursor(newPosition);
                cout << left << setw(20) << setfill(' ') << '|' << setw(20) << setfill(' ') << '|'      //clear row 2, had icons getting stuck.
                     << setw(20) << setfill(' ') << '|' << setw(20) << setfill(' ') << '|'
                     << setw(20) << setfill(' ') << '|' << setw(19) << setfill(' ') << '|';
                setCursor(OutOfWay);
                break;
            }
            else if (collision == true) {           //display for collision
                setCursor(cornerText);
                cout << "Collision in " << collisionName << "!" << "     Games Played: " << counter;
                setCursor(OutOfWay);
                break;
                }
            }

            
            Sleep(10000);
            setCursor(cornerText);
            cout << left << setw(118) << setfill(' ') << " ";        //erase previous winner text  before next start

            for (Lane* _lanes : lanes) {
                setCursor(_lanes->GetCar()->GetPosition());         //clear icons
                cout << " ";

                setCursor(finishLine);
                cout << left << setfill('-') << setw(118) << "-";

                newPosition.col = _lanes->GetCntr();
                newPosition.row = startLine;                    //reset position of icons
                _lanes->GetCar()->SetPosition(newPosition);
                setCursor(newPosition);
                cout << _lanes->GetCar()->GetIcon();
                setCursor(OutOfWay);

                if (collision == true) {
                    for (Lane* _lanes : lanes) {
                        newPosition.col = _lanes->GetLtBound();
                        for (int i = 0; i < 28; i++) {                      //redrawing lanes
                            newPosition.row = startLine - i;
                            setCursor(newPosition);
                            cout << '|';
                        }
                    }
                    newPosition.col = lanes.at(5)->GetRtBound();
                    for (int i = 0; i < 28; i++) {                      //redrawing far right bound lane
                        newPosition.row = startLine - i;
                        setCursor(newPosition);
                        cout << '|';
                    }
                    setCursor(OutOfWay);
                }
            }
        
       

        Sleep(1000);

        gameOver = false;
        collision = false;                                      //reset bool
        winner = false;
    }
        
        
        return 0;
    }

