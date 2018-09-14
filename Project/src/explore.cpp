#include "explore.h"
#include <iostream>

using namespace std;

int explore::totalFlags=0;

explore::explore(const int &x,const int &y):vehicle(x,y)
{
    cout<<"Explore  "<<getId()<<" vehicle created"<<endl;
    flags=0;
    setSpeed(2);
    setType('E');
}

explore::~explore()
{
    cout<<"explore destructor runs"<<endl;
}

int explore::getTotalFlags()
{
    return totalFlags;
}

int explore::func(square &s)
{
    if(s.getAccess() > 0.6)
    {
        cout<<"Vehicle "<<getType()<<":"<<this->getId()<<" set a flag to ("<<s.getX()<<","<<s.getY()<<")"<<endl;
        square::setFlag(s.getX(),s.getY());
        flags++;
        addTotalFlag();
        return 1;
    }
    return -1;
}

int explore::getFlags() const
{
    return flags;
}

void explore::setTotalFlags(const int &x)
{
    totalFlags=x;
}

void explore::addTotalFlag()
{
    totalFlags++;
}

void explore::printInfo() const
{
    vehicle::printInfo();
    cout<<"Flags that vehicle have set:"<<getFlags()<<endl<<endl;
}
