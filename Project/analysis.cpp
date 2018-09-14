#include "analysis.h"
#include <iostream>

using namespace std;

float analysis::totalP=0;
float analysis::totalI=0;
float analysis::totalL=0;

analysis::analysis(const int &x,const int &y):vehicle(x,y)
{
    cout<<"Analysis "<<getId()<<" vehicle created"<<endl;
    fortioP=0;
    fortioI=0;
    fortioL=0;
    setMaxFortio(5.0F);
    setSpeed(1);
    setType('A');
}

analysis::~analysis()
{
}

void analysis::setMaxFortio(const float &x)
{
    maxFortio=x;
}

float analysis::getMaxFortio() const
{
    return maxFortio;
}

void analysis::addFortioP(const float &p)
{
    fortioP+=p;
    addTotalP(p);
}

float analysis::getFortioP() const
{
    return fortioP;
}

void analysis::addFortioI(const float &i)
{
    fortioI+=i;
    addTotalI(i);
}
float analysis::getFortioI() const
{
    return fortioI;
}

void analysis::addFortioL(const float &l)
{
    fortioL+=l;
    addTotalL(l);
}

float analysis::getFortioL() const
{
    return fortioL;
}

void analysis::addTotalP(const float &p)
{
    totalP+=p;
}

void analysis::addTotalI(const float &i)
{
    totalL+=i;
}

void analysis::addTotalL(const float &l)
{
    totalL+=l;
}

void analysis::mhdenismosFortiwn()
{
    fortioP=0;
    fortioI=0;
    fortioL=0;
}

int analysis::func(square &s)
{
    if(s.getPaladio()>0.2 && s.getIridio()>0.2 && s.getLeuko()>0.2)
    {
    //eksoruksh
    addFortioP(s.getPaladio());
    s.setPaladio(0);
    addFortioI(s.getIridio());
    s.setIridio(0);
    addFortioL(s.getLeuko());
    s.setLeuko(0);
    cout<<"Vehicle "<<getType()<<":"<<this->getId()<<" did the exctraction to point ("<<s.getX()<<","<<s.getY()<<")"<<endl;
    setStatus(getStatus()-5);
    cout<<"Vehicle "<<getType()<<":"<<getId()<<" damaged by 5 points"<<endl;
    this->addDamage(5);
    cout<<"Vehicle's new status is "<<getStatus()<<" points"<<endl;

    if(getStatus()>0)
    {
        if(this->getMaxFortio() <= (this->getFortioP()+this->getFortioI()+this->getFortioL()))
        {
            cout<<"Vehicle "<<getType()<<":"<<getId()<<" goes to base"<<endl;
            return 1;
        }
    }
    }
    return -1;
}

void analysis::moveto(const int &b)
{
    if(b==0)
    {
        square::uncapture(getXv(),getYv());
        setXvYv(2,0);
        mhdenismosFortiwn();
    }
}

void analysis::setTotalAmount(const float &x)
{
    totalP=x;
    totalI=x;
    totalL=x;
}

float analysis::getTotalAmount()
{
    return totalI+totalP+totalL;
}

void analysis::printInfo() const
{
    vehicle::printInfo();
    cout<<"Paladio's load:"<<getFortioP()<<endl<<"Iridio's load:"<<getFortioI()<<endl<<"Leukoxruso's load:"<<getFortioL()<<endl;
    cout<<"Total load:"<<getFortioP()+getFortioI()+getFortioL()<<endl;
}

