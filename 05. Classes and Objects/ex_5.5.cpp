/*
 * Create two classes DM and DB which store the value of distances. DM stores 
 * distances in metres and centimetres and DB in feet and inches. Write a program
 * that read values for the class objects and add one object of DM with another 
 * object of DB.
 * Use a friend function to carry out the addition operation. The object that
 * stores the results may be a DM object or DB object, depending on the units
 * in which the results are required.
 * The display should be in the format of feet and inches or metres and centimetres
 * depending on the object on display.
*/

#include <iostream>

class DB;

// Stores distances in meters/centimeters.
class DM
{
    int meters;
    float centimeters;

public:
    DM()
    {
        meters = 0;
        centimeters = 0.0;
    };
    DM(int meters, float centimeters)
    {
        meters = meters;
        centimeters = centimeters;
    };
    friend void addToDM(DM, DB);
    friend void addToDB(DM, DB);
};

// Stores distances in feet/inches.
class DB
{
    int feet;
    float inches;

public:
    DB()
    {
        feet = 0;
        inches = 0.0;
    };
    DB(int feet, float inches)
    {
        feet = feet;
        inches = inches;
    };
    friend void addToDB(DM, DB);
    friend void addToDM(DM, DB);
};

void addToDM(DM dm, DB db)
{
    // TODO: logic needs to be fixed for the conversion
    //       from feet and inches to meters and centimeters.
    float m = db.feet * 12 * 2.54;
    dm.meters = m / 100;
    dm.centimeters = db.inches * 2.54;
    dm.centimeters += m % 100;
}

void addToDB(DM dm, DB db)
{
    // TODO: logic needs to be fixed for the conversion
    //       from meters and centimeters to feet and inches.
}