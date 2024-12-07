/***********************************************************************
 * Source File:
 *    PROJECTILE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/


 #include "projectile.h"
 #include "angle.h"
 using namespace std;

 void Projectile::advance(double simulationTime)
 {
     PositionVelocityTime PVT;
     PositionVelocityTime previousPVT = flightPath.back();
     PVT.pos.add(Acceleration(previousPVT.v.getDX(), previousPVT.v.getDY()), previousPVT.v, simulationTime);
     PVT.v.add(Acceleration(previousPVT.v.getDX(), previousPVT.v.getDY()), simulationTime);
     PVT.t = simulationTime;

     flightPath.push_back(PVT);
 }

 void Projectile::fire(Howitzer howitzer)
 {
     PositionVelocityTime initialPVT;
     initialPVT = howitzer;
     Angle hAngle = howitzer.getElevation();
     if (hAngle.getDX() > 0 && hAngle.getDY() > 0)
     {
         initialPVT.v.setDX(howitzer.getMuzzleVelocity());
         initialPVT.v.setDY(howitzer.getMuzzleVelocity());
     }
     else if (hAngle.getDX() > 0 && hAngle.getDY() == 0)
     {
         initialPVT.v.setDX(howitzer.getMuzzleVelocity());
         initialPVT.v.setDY(0);
     }
     else
     {
         initialPVT.v.setDX(0);
         initialPVT.v.setDY(howitzer.getMuzzleVelocity());
     }

     flightPath.push_back(initialPVT);
 }
