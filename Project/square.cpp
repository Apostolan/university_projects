#include "square.h"
#include <iostream>

using namespace std;

square::square() {}
int square::isFree[PLATOS][MHKOS];
bool square::flag[PLATOS][MHKOS];

square::square(const int &x,const int &y)
{
    //srand(time(0));
    setX(x);
    setY(y);
    uncapture(x,y);
    setPaladio(static_cast <float> ((rand()) % 10 + 1) /10);
    setIridio(static_cast <float> ((rand()) % 10 + 1) /10);
    setLeuko(static_cast <float> ((rand()) % 10 + 1) /10);
    setAccess(static_cast <float> ((rand()) % 10 + 1) /10);
}

void square::setPaladio(const float &p)
{
    paladio = p;
}

void square::setIridio(const float &i)
{
    iridio = i;
}

void square::setLeuko(const float &l)
{
    leuko = l;
}

void square::setAccess(const float &a)
{
    access = a;
}


void square::capture(const int &x,const int &y,const int &n)
{
    isFree[x][y]=n;
}

void square::uncapture(const int &x,const int &y)
{
    isFree[x][y]=-1;
}

void square::setX(const int &x1)
{
    x=x1;
}

void square::setY(const int &y1)
{
    y=y1;
}

float square::getPaladio() const
{
    return paladio;
}

float square::getIridio() const
{
    return iridio;
}

float square::getLeuko() const
{
    return leuko;
}

float square::getAccess() const
{
    return access;
}


int square::getIsFree(const int &x,const int &y)
{
    if(isFree[x][y]>-1)  return isFree[x][y];
    else return -1;
}

int square::getX() const
{
    return x;
}

int square::getY() const
{
    return y;
}

square::~square()
{

}

void square::setFlag(const int &x, const int &y)
{
    flag[x][y]=true;
}

bool square::hasFlag(const int &x,const int &y)
{
    return flag[x][y];
}
