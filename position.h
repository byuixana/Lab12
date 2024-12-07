/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#pragma once
#include <istream>


class Velocity;        // for Position::add()
class Acceleration;    // for Position::add()
class TestPosition;    // for the unit tests
class TestProjectile;      // for the unit tests
class TestHowitzer;
class TestGround;

/*********************************************
 * POSITION
 * A single position on the screen
 *********************************************/
class Position
{
public:
    friend TestPosition;    // for the unit tests
    friend TestProjectile;      // for the unit tests
    friend TestHowitzer;
    friend TestGround;

    // constructors
    Position();
    Position(const Position& pos);
    Position(double x, double y);

    // getters
    double getMetersX() const;
    double getMetersY() const;
    bool operator == (const Position& rhs) const;
    bool operator != (const Position& rhs) const;
    double getZoom();
    double getPixelsX() const;
    double getPixelsY() const;

    // setters
    void setMetersX(double x);
    void setMetersY(double y);
    void addX(double x);
    void addY(double y);
    void add(const Acceleration& a, const Velocity& v, double t);
    Position& operator = (const Position& rhs);
    void setZoom(double metersFromPixels);
    void setPixelsX(double xPixels);
    void setPixelsY(double yPixels);


    void addMetersX(double x);
    void addMetersY(double y);
    void addPixelsX(double x);
    void addPixelsY(double y);


private:
    double x;           // horizontal position
    double y;           // vertical position
    static double metersFromPixels;
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Position& pt);
std::istream& operator >> (std::istream& in, Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
    double x;
    double y;
};


