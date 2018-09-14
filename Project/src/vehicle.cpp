#include "vehicle.h"
#include <iostream>

using namespace std;


int vehicle::totalDamage = 0;
int vehicle::totalMoves = 0;
int vehicle::num = 0;

vehicle::vehicle(const int &x, const int &y)
{
    setStatus(50);
    setXvYv(x,y);
    num++;
    id=num;
    square::capture(x,y,id);
    setAccessAbility(static_cast <float> ((rand()) % 10 + 1) /10);
}

vehicle::~vehicle()
{
    square::uncapture(getXv(),getYv());
}

void vehicle::setSpeed(const int &s)
{
    speed=s;
}

float vehicle::getSpeed() const
{
    return speed;
}

void vehicle::setDamage(const int &x)
{
    damage=x;
}

int vehicle::getDamage() const
{
    return damage;
}

void vehicle::addDamage(const int &x)
{
    damage+=x;
    addTotalDamage(x);
}

void vehicle::addMoves()
{
    moves++;
    addTotalMoves();
}

void vehicle::setStatus(const int &x)
{
     status=x;
     if(status<0)
     {
         status=0;
     }
}

int vehicle::getStatus() const
{
     return status;
}



void vehicle::setXvYv(const int &a,const int &b)
{
    xv=a;
    yv=b;
}

int vehicle::getXv() const
{
    return this->xv;
}

int vehicle::getYv() const
{
    return this->yv;
}

void vehicle::setAccessAbility(const float &a)
{
    accessAbility=a;
}

float vehicle::getAccessAbility() const
{
    return accessAbility;
}

int vehicle::moveto()
{
   int x=getXv();
   int y=getYv();

      int xr,yr,a;
      int count=0;
      do
      {
          a=rand()%4+1;
          count++;
          if(a==1){xr=x-1;yr=y;}
          else if(a==2){xr=x;yr=y+1;}
          else if(a==3){xr=x+1;yr=y;}
          else if(a==4){xr=x;yr=y-1;}
          if(count>100)
          {
              cout<<"Vehicle "<<getType()<<":"<<getId()<<"can't move"<<endl;
              return 1;
          }

      }while(square::getIsFree(xr,yr)>=0 || xr>=PLATOS || xr<0 ||(xr<=2 && yr==0) || yr>=MHKOS || yr<0 || square::hasFlag(xr,yr));

       cout<<"Vehicle "<<getType()<<":"<<getId()<<" moved from "<<x<<","<<y<<" to ";

        square::uncapture(x,y);

       if(a==1)
       {
           setXvYv(x-1,y);
           square::capture(x-1,y,getId());
           cout<<x-1<<","<<y<<endl;
       }

       else if(a==2)
       {
           setXvYv(x,y+1);
           square::capture(x,y+1,getId());
           cout<<x<<","<<y+1<<endl;
       }

       else if(a==3)
       {
           setXvYv(x+1,y);
           square::capture(x+1,y,getId());
           cout<<x+1<<","<<y<<endl;
       }

       else if(a==4)
       {
           setXvYv(x,y-1);
           square::capture(x,y-1,getId());
           cout<<x<<","<<y-1<<endl;
       }
       addMoves();
       return 0;
}

void vehicle::makeDamage(const square &s)
{
    int d=(s.getAccess()*(1-(this->getAccessAbility()))*30);
    setStatus(getStatus()-d);
    addDamage(d);
    cout<<"Vehicle "<<getType()<<":"<<getId()<<" damaged "<<d<<" points"<<endl;
    cout<<"Vehicle new status:"<<getStatus()<<" points"<<endl;
}

void vehicle::setType(const char &c)
{
    type=c;
}

char vehicle::getType() const
{
    return type;
}

int vehicle::getId()
{
    return id;
}

int vehicle::getMoves() const
{
    return moves;
}

void vehicle::printInfo() const
{
    cout<<endl<<"Status:"<<getStatus()<<endl<<"Damage:"<<getDamage()<<endl<<"Speed:"<<getSpeed()<<" m/r"<<endl<<"Moves:"<<getMoves()<<endl;
    cout<<"Rounds that have problem:"<<getRound()<<endl<<"Access ability:"<<getAccessAbility()<<endl;
}

void vehicle::addTotalDamage(const int &x)
{
    totalDamage+=x;
}

void vehicle::addTotalMoves()
{
    totalMoves++;
}

int vehicle::getTotalDamage()
{
    return totalDamage;
}

int vehicle::getTotalMoves()
{
    return totalMoves;
}

void vehicle::setRound(const int &r)
{
    round=r;
}

int vehicle::getRound() const
{
    return round;
}

void vehicle::setNum(const int &x)
{
    num=x;
}

void vehicle::setTotalDamage(const int &x)
{
    totalDamage=x;
}

void vehicle::setTotalMoves(const int &x)
{
    totalMoves=x;
}
