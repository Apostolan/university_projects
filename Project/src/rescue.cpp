#include "rescue.h"
#include <iostream>

using namespace std;

int rescue::totalRevives=0;

rescue::rescue(const int &x,const int &y):vehicle(x,y)
{
    cout<<"Rescue   "<<getId()<<" vehicle created"<<endl;
    revives=0;
    setSpeed(3);
    setType('R');
}



rescue::~rescue()
{

}

int rescue::func(square &s)
{
    int x = s.getX();
    int y = s.getY();

    if(x!=0)
    if(square::getIsFree(x-1,y)>0)
    {
        return square::getIsFree(x-1,y);
    }

    if(x!=PLATOS-1)
    if(square::getIsFree(x+1,y)>0)
    {
        return square::getIsFree(x+1,y);
    }

    if(y!=0)
    if(square::getIsFree(x,y-1)>0)
    {
        return square::getIsFree(x,y-1);
    }

    if(y!=MHKOS-1)
    if(square::getIsFree(x,y+1)>0)
    {
        return square::getIsFree(x,y+1);
    }
    return -1;
}

void rescue::epidiorthwsh(vehicle &v)
{
    if(v.getStatus()<50)
    {
        revives++;
        addTotalRevives();
        v.setStatus(50);
        cout<<"The vehicle "<<v.getType()<<":"<<v.getId()<<" revived"<<endl;
    }
}

int rescue::getTotalRevives()
{
    return totalRevives;
}

void rescue::setTotalRevives(const int &x)
{
    totalRevives=x;
}

void rescue::addTotalRevives()
{
    totalRevives++;
}

int rescue::getRevives() const
{
    return revives;
}

void rescue::addRevives()
{
    revives++;
    addTotalRevives();
}

void rescue::printInfo() const
{
    vehicle::printInfo();
    cout<<"Revives that vehicle have done:"<<getRevives()<<endl<<endl;
}
