/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include <cassert>
#include <istream>


Position::Position(double x, double y)
{
    this->x = x;
    this->y = y;
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point. Please look ahead to
 * Week 12 C++ reading for an idea of how this works.
 * Basically, we are copying the data from posRHS
 * into this.
 *****************************************/
Position& Position::operator=(const Position& rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}

/************************************************************************
 * UPDATE POSITION
 * Update the current position based on the impulse of velocity
 * taking into account time dilation:
 *
 *   s = s_0 + vt + 1/2 at^2
 *
 *   INPUT  POSITION     The location of the item
 *          VELOCITY     The velocity of the item
 *          ACCELERATION The acceleration of the item
 *          TIME         How much time are we talking about?
 *   OUTPUT POSITION     The location, updated
 *
 *
 *  x = x + dx t + 1/2 ddx t^2
 *  y = y + dy t + 1/2 ddy t^2
 *************************************************************************/
void Position::add(const Acceleration& a, const Velocity& v, double t)
{
    this->x = x + (v.getDX() * t) + ((1.0 / 2.0) * (a.getDDX() * (t * t)));
    this->y = y + (v.getDY() * t) + ((1.0 / 2.0) * (a.getDDY() * (t * t)));
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
    out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
    return out;
}

/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
    double x;
    double y;
    in >> x >> y;

    pt.setMetersX(x);
    pt.setMetersY(y);

    return in;
}

bool Position::operator==(const Position& rhs) const
{
    if (rhs.x == this->x && rhs.y == this->y)
    {
        return true;
    }
    return false;
}
bool Position::operator!=(const Position& rhs) const
{
    if (rhs.x != this->x || rhs.y != this->y)
    {
        return true;
    }
    return false;
}

double Position::getMetersX()const
{
    return x;
}
double Position::getMetersY() const
{
    return y;
}

void Position::setMetersX(double x)
{
    this->x = x;
}

void Position::setMetersY(double y)
{
    this->y = y;
}

Position::Position()
{
    x = 0.0;
    y = 0.0;
}

Position::Position(const Position& pos)
{
    x = pos.x;
    y = pos.y;
}


void Position::addX(double x)
{
    this->x += x;
}

void Position::addY(double y)
{
    this->y += y;
}


double Position::getZoom()
{
    return metersFromPixels;
}

void Position::setZoom(double meterFromPixel)
{
    this->metersFromPixels = meterFromPixel;
}

double Position::getPixelsX() const
{
    return  x / metersFromPixels;
}


double Position::getPixelsY() const
{
    return y / metersFromPixels;
}


void Position::setPixelsX(double xPixels)
{
    this->x = xPixels * metersFromPixels;
}

void Position::setPixelsY(double yPixels)
{
    this->y = yPixels * metersFromPixels;
}

void Position::addMetersX(double x)
{
    this->x += x;
}

void Position::addMetersY(double y)
{
    this->y += y;
}

void Position::addPixelsX(double x)
{
    this->x += x * metersFromPixels;
}

void Position::addPixelsY(double y)
{
    this->y += y * metersFromPixels;
}
