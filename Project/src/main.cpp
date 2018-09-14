#include "square.h"
#include "vehicle.h"
#include "analysis.h"
#include "explore.h"
#include "rescue.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

using namespace std;

char world[PLATOS][MHKOS];
square* sq[PLATOS][MHKOS];
vector <vehicle *> vehicles;

void showMap()
{
    for(int i=0;i<PLATOS;i++)
    {
        cout<<endl<<"-----------------------------------------------------------------------"<<endl;
        cout<<"|";
        for(int j=0;j<MHKOS;j++)
        {
                if(i==0 && j==0)
                {
                    cout<<"P:";
                    if(sq[i][j]->getPaladio()>=10.0)
                        cout<<setprecision(1)<<fixed<<sq[0][0]->getPaladio()<<"|";
                    else
                        cout<<setprecision(1)<<fixed<<sq[0][0]->getPaladio()<<" |";
                    continue;
                }
                else if(i==1 && j==0)
                {
                    cout<<"I:";
                    if(sq[i][j]->getIridio()>=10.0)
                        cout<<setprecision(1)<<fixed<<sq[1][0]->getIridio()<<"|";
                    else
                        cout<<setprecision(1)<<fixed<<sq[1][0]->getIridio()<<" |";
                    continue;
                }
                else if(i==2 && j==0)
                {
                    cout<<"L:";
                    if(sq[i][j]->getLeuko()>=10.0)
                        cout<<setprecision(1)<<fixed<<sq[2][0]->getLeuko()<<"|";
                    else
                        cout<<setprecision(1)<<fixed<<sq[2][0]->getLeuko()<<" |";
                    continue;
                }
                cout<<world[i][j];
                if(square::getIsFree(i,j)!=-1)
                    cout<<":"<<square::getIsFree(i,j)<<"   |";
                else
                cout<<"     |";

        }
    }

    cout<<endl<<"-----------------------------------------------------------------------"<<endl;
}

int Menu2()
{
    int choice;
    cout<<"1.Insert vehicle\n2.Edit ground's location\n3.Vehicle's Informations\n4.Edit vehicle's status\n5.General Informations\n6.Continue Simulation"<<endl;
    cout<<"7.Exit"<<endl<<endl;
    cout<<"Select one of above:";
    do{
        cin>>choice;
    }while(choice<1 || choice>7);

    return choice;
}

void diagrafh(vehicle* v,int &pos)
{
    cout<<"Vehicle "<<v->getType()<<":"<<v->getId()<<" with coordinates ("<<v->getXv()<<","<<v->getYv()<<") removed"<<endl;
    int x=v->getXv();
    int y=v->getYv();
    square::uncapture(x,y);
    world[x][y]=' ';
    delete(v);
    vehicles.erase(vehicles.begin()+pos);
    showMap();
}

void edafos()
{
    for(int i=0;i<PLATOS;i++)
        for(int j=0;j<MHKOS;j++)
          sq[i][j]= new square(i,j);

    //-------------------bash--------------------


    sq[0][0]->setPaladio(0);
    square::capture(0,0,0);
    sq[1][0]->setIridio(0);
    square::capture(1,0,0);
    sq[2][0]->setLeuko(0);
    square::capture(2,0,0);
}
void giveThesh(int &x,int &y)
{
    while(x>PLATOS-1 || y>MHKOS-1 ||((x<3)&&(y==0))|| x<0 || y<0 || square::getIsFree(x,y)>0)
    {

        if(square::getIsFree(x,y)>0)
        {
            cout<<"There is vehicle in "<<x<<","<<y<<". Give other coordinates:";
            cin>>x>>y;
            continue;
        }
        if((x<3)&&(y==0))
        {
            cout<<"You can't place the vehicle in this position. Give other coordinates:";
            cin>>x>>y;
            continue;
        }


        cout<<endl<<"Enter valid values:";
        cin>>x>>y;
    }
}

void insertAnalysis()
{
    int x,y;
    cout<<"Give coordinates for the new analysis vehicle (x,y) x:(0-"<<PLATOS-1<<")"<<" y:(0-"<<MHKOS-1<<"):";
    cin>>x>>y;
    giveThesh(x,y);
    cout<<endl;
    analysis *a=new analysis(x,y);
    vehicles.push_back(a);

    int h=vehicles.size();
    world[x][y]=vehicles[h-1]->getType();
    showMap();
}

void insertExplore()
{
    int x,y;
    cout<<"Give coordinates for the new explore vehicle (x,y) x:(0-"<<PLATOS-1<<")"<<" y:(0-"<<MHKOS-1<<"):";
    cin>>x>>y;
    giveThesh(x,y);
    cout<<endl;
    vehicles.push_back(new explore(x,y));

    int h=vehicles.size();
    world[x][y]=vehicles[h-1]->getType();
    showMap();
}

void insertRescue()
{
   int x,y;
   cout<<"Give coordinates for the new rescue vehicle (x,y) x:(0-"<<PLATOS-1<<")"<<" y:(0-"<<MHKOS-1<<"):";
    cin>>x>>y;
   giveThesh(x,y);
   cout<<endl;
   vehicles.push_back(new rescue(x,y));

   int h=vehicles.size();
   world[x][y]=vehicles[h-1]->getType();
   showMap();
}

void editGround()
{
    cout<<endl<<"         ----------Edit ground's location----------"<<endl<<endl;

    int x,y;
    cout<<"Give coordinates for the square (x,y) x:(0-"<<PLATOS-1<<")"<<" y:(0-"<<MHKOS-1<<"):";
    cin>>x>>y;
    while(x>PLATOS || y>MHKOS || x<0 || y<0)
    {
        cout<<"Give valid values:";
        cin>>x>>y;
    }
    float pal,iri,leuk,acc;

    do
    {
        cout<<endl<<"Give content of Paladio(0-1):";
        cin>>pal;
    }while(pal>1 || pal<0);

    sq[x][y]->setPaladio(pal);
    cout<<"The new value of paladio in "<<x<<","<<y<<" is:"<<sq[x][y]->getPaladio()<<endl;

    do
    {
        cout<<endl<<"Give content of Iridio(0-1):";
        cin>>iri;
    }while(iri>1 || iri<0);

    sq[x][y]->setIridio(iri);
    cout<<"The new value of iridio in "<<x<<","<<y<<" is:"<<sq[x][y]->getIridio()<<endl;

    do
    {
        cout<<endl<<"Give content of Leukoxruso(0-1):";
        cin>>leuk;
        cout<<endl;
    }while(leuk>1 || leuk<0);

    sq[x][y]->setLeuko(leuk);
    cout<<"The new value of leukoxruso in "<<x<<","<<y<<" is:"<<sq[x][y]->getLeuko()<<endl;

    do
    {
        cout<<endl<<"Give content of dangerous access(0-1):";
        cin>>acc;
    }while(acc>1 || acc<0);

    sq[x][y]->setAccess(acc);
    cout<<"The new value of dangerous access in "<<x<<","<<y<<" is:"<<sq[x][y]->getAccess()<<endl;
    cout<<endl;
}

void editStatus()
{
    cout<<endl<<"         ----------Edit vehicle's status----------"<<endl<<endl;
    int x;

    cout<<"Give vehicle's id:";
    cin>>x;
    int count=0;

    for(int i=0;i<vehicles.size();i++)
    {
        if(vehicles[i]->getId()==x)
        {
            break;
        }
        count++;
        if(count==vehicles.size())
        {
            i=-1;
            count=0;
            cout<<"Give valid id:";
            cin>>x;
        }
    }
    cout<<endl;

    int q;
    do
    {
        cout<<"Give the value for status (0-50):";
        cin>>q;
    }while(q<0 || q>50);

    vehicles[x-1]->setStatus(q);
    cout<<"The new status for vehicle "<<vehicles[x-1]->getType()<<":"<<vehicles[x-1]->getId()<<" is:"<<vehicles[x-1]->getStatus()<<endl;
    cout<<endl;
    system("pause");
}

void VInfo()
{
    cout<<endl<<"         ----------Vehicle's Informations----------"<<endl<<endl;
    int x;
    do{
    cout<<"Give vehicle's id (0-"<<vehicles.size()<<"):";
    try{
    cin>>x;
    }
    catch(exception e)
    {
        exit(1);
    }
    }while(x>vehicles.size());

    if(vehicles[x-1]->getType()=='A')
    {
        analysis* a=dynamic_cast<analysis*>(vehicles[x-1]);
        if(a!=0) a->printInfo();
    }
    else if(vehicles[x-1]->getType()=='E')
    {
        explore* a=dynamic_cast<explore*>(vehicles[x-1]);
        if(a!=0) a->printInfo();
    }
    else if(vehicles[x-1]->getType()=='R')
    {
        rescue* a=dynamic_cast<rescue*>(vehicles[x-1]);
        if(a!=0) a->printInfo();
    }
    cout<<endl;
    system("pause");
}

int insertMenu()
{
    cout<<endl<<"         ----------Insert vehicle----------"<<endl<<endl;
    cout<<"1.Analysis vehicle\n2.Explore vehicle\n3.Rescue vehicle\n"<<endl<<endl;
    int choice1=0;

    do
    {
        cout<<"Select one of above:";
        cin>>choice1;
    }while(choice1<1 || choice1>3);

    return choice1;
}

void print()
{
    cout<<endl<<"         ----------General Informations----------"<<endl<<endl;
    cout<<"Total damage:"<<vehicle::getTotalDamage()<<endl<<"Total flags that have set:"<<explore::getTotalFlags()<<endl;
    cout<<"Total load of extraction:"<<analysis::getTotalAmount()<<endl;
    cout<<"Total moves:"<<vehicle::getTotalMoves()<<endl;
    cout<<"Total revives:"<<rescue::getTotalRevives()<<endl;
    float macc=0;
    float mpal=0;
    float miri=0;
    float mleuk=0;

    for(int i=0;i<PLATOS;i++)
    {
        for(int j=0;j<MHKOS;j++)
        {
            macc+=sq[i][j]->getAccess();
            mpal+=sq[i][j]->getPaladio();
            miri+=sq[i][j]->getIridio();
            mleuk+=sq[i][j]->getLeuko();
        }
    }
    macc=macc/(MHKOS*PLATOS);
    mpal=mpal/(MHKOS*PLATOS);
    miri=miri/(MHKOS*PLATOS);
    mleuk=mleuk/(MHKOS*PLATOS);

    cout<<"Averaged of access ability:"<<macc<<endl;
    cout<<"Averaged of paladio's content:"<<mpal<<endl;
    cout<<"Averaged of iridio's content:"<<miri<<endl;
    cout<<"Averaged of leukoxruso's content:"<<mleuk<<endl<<endl;
}

void info()
{
    cout<<endl<<endl<<"         -----------------------Informations-----------------------";
    cout<<endl<<endl;
    cout<<"In the begginig thera are three vehicles in the map, one of each category. "<<endl;
    cout<<"Each vehicle have a type (e.g 'A') (A for analysis, E for explore and R for"<<endl;
    cout<<"rescue)and a id (e.g 2), that both appear in the map in format like <type>"<<endl;
    cout<<":<id> (e.g E:5). In the simulation time you can press the space button and "<<endl;
    cout<<"it will appear a menu with diffrent things that you can do. In addition,   "<<endl;
    cout<<"analysis vehicles have speed 1 m/r(moves per round), explore vehicles have "<<endl;
    cout<<"2 m/r and rescue vehicles have 3 m/r."<<endl;
    system("pause");
}

int menu()
{
    cout<<"1.Start silulation\n2.Informations\n3.Exit"<<endl;
    int k;
    do
    {
        cout<<"Choose one of above:";
        cin>>k;
    }while(k>3 || k<0);

   return k;
}

void clearWorld()
{
    for(int i=0;i<PLATOS;i++)
        for(int j=0;j<MHKOS;j++)
            world[i][j]=' ';
}

void diagrafhSquare()
{
    for(int i=0;i<PLATOS;i++)
        for(int j=0;j<MHKOS;j++)
            delete(sq[i][j]);
}



int main()
{
while(true){

    int k;
    do
    {
        k=menu();
        if(k==2) info();
            cout<<endl;
    }while(k!=1 && k!=3);

    if(k==3) break;
    system("cls");
    cout<<"            --------------START SIMULATION--------------"<<endl<<endl;
    clearWorld();
    vehicle::setNum(0);
    analysis::setTotalAmount(0);
    explore::setTotalFlags(0);
    vehicle::setTotalDamage(0);
    vehicle::setTotalMoves(0);
    rescue::setTotalRevives(0);
    srand(0);
    edafos();
    showMap();

    //---------------dhmiourgia arxikwn vehicle-----------------
    analysis* v=new analysis(6,7);
    explore* e=new explore(3,8);
    rescue* r=new rescue(2,4);

    //-------------------eisagwgh vehicles sto vector-----------------
    vehicles.push_back(v);
    vehicles.push_back(e);
    vehicles.push_back(r);

    //-------------------eisagwgh typou ston xarth--------------------
    for(int i=0;i<vehicles.size();i++)
    {
        int x=vehicles[i]->getXv();
        int y=vehicles[i]->getYv();
        world[x][y]=vehicles[i]->getType();
    }

    showMap();
    system("pause");

bool telos=false;
    while(true)
    {
        int i=0;
        if(sq[0][0]->getPaladio()>=8.0 && sq[1][0]->getIridio()>=8.0 && sq[2][0]->getLeuko()>=8.0)
        {
            vehicles.clear();
            cout<<"All the necessary content of materials moved to base"<<endl;
            break;
        }

        while(i<vehicles.size() && vehicles.size()>0)
        {
            if(vehicles[i]->getStatus()==0 )
            {
                if(vehicles[i]->getRound()>=2)
                {
                    diagrafh(vehicles[i],i);

                    if(vehicles.size()==0)
                    {
                        telos=true;
                        showMap();
                        break;
                    }
                    system("pause");
                    continue;
                }
                else
                {
                    cout<<"Vehicle "<<vehicles[i]->getType()<<":"<<vehicles[i]->getId()<<" can't move"<<endl;
                    vehicles[i]->setRound(vehicles[i]->getRound()+1);
                    showMap();
                    system("pause");
                    i++;
                    continue;
                }
            }
            vehicles[i]->setRound(0);

            for(int j=0;j<vehicles[i]->getSpeed();j++)
            {
                if(vehicles[i]->getStatus()==0)
                {
                    cout<<"Vehicle "<<vehicles[i]->getType()<<":"<<vehicles[i]->getId()<<" can't move"<<endl;
                    vehicles[i]->setRound(vehicles[i]->getRound()+1);
                    showMap();
                    i++;
                    system("pause");
                    break;
                }

                int xb=vehicles[i]->getXv();
                int yb=vehicles[i]->getYv();
                int m=vehicles[i]->moveto();
                int x=vehicles[i]->getXv();
                int y=vehicles[i]->getYv();
                if(world[xb][yb]!='F')
                world[xb][yb]=' ';
                world[x][y]=vehicles[i]->getType();
                int z=-1;
                if(m==0){
                vehicles[i]->makeDamage(*sq[x][y]);
                z=vehicles[i]->func(*sq[x][y]);}

                if(vehicles[i]->getType()=='A')
                {
                    if(z==1)
                    {
                        if(vehicles[i]->getStatus()>0)
                        {
                            world[x][y]=' ';
                            analysis* r=dynamic_cast<analysis*>(vehicles[i]);
                            if(r!=0){
                            sq[0][0]->setPaladio(sq[0][0]->getPaladio() + r->getFortioP());
                            sq[1][0]->setIridio(sq[1][0]->getIridio() + r->getFortioI());
                            sq[2][0]->setLeuko(sq[2][0]->getLeuko() + r->getFortioL());
                            r->moveto(0);
                            }
                        }
                        else
                        {
                            cout<<"Vehicle "<<vehicles[i]->getType()<<":"<<vehicles[i]->getId()<<" can't move"<<endl;
                            i++;
                            showMap();
                            system("pause");
                            break;
                        }
                    }
                }
                else if(vehicles[i]->getType()=='E')
                {
                    if(z==1)
                    {
                       world[x][y]='F';
                    }
                }
                else if(vehicles[i]->getType()=='R')
                {
                   if(z>0)
                    {
                        int c;
                        for(int l=0;l<vehicles.size();l++)
                        {
                            if(z==vehicles[l]->getId())
                            {
                                c=l;
                                break;
                            }
                        }
                        if((vehicles[c]->getStatus())<50){
                        rescue* r=dynamic_cast<rescue*>(vehicles[i]);
                        if(r!=0)
                        {
                            r->epidiorthwsh(*vehicles[c]);
                        }
                        }
                    }
                }
                showMap();
                system("pause");
            }

            if(GetAsyncKeyState(0x20)!=0)
            {
                int choice;
                while(choice=Menu2())
                {
                    if(choice==1)
                    {
                        int choice1=insertMenu();

                        if(choice1==1) insertAnalysis();
                        else if(choice1==2) insertExplore();
                        else if(choice1==3) insertRescue();
                    }
                    else if(choice==2) editGround();
                    else if(choice==3) VInfo();
                    else if(choice==4) editStatus();
                    else if(choice==5) print();
                    else if(choice==6)
                    {
                        cout<<endl<<endl;
                        break;
                    }
                    else if(choice==7)
                    {
                        cout<<endl<<endl;
                        cout<<"Program terminated"<<endl;
                        exit(0);
                    }
                }
            }
            i++;
        }
        if(telos)
        {
            cout<<"All the vehicles have removed."<<endl;
            break;
        }
    }
    diagrafhSquare();
    cout<<"SIMULATION ENDED"<<endl;
    Sleep(5000);
    system("cls");
}

cout<<"Program terminated"<<endl;
    return 0;
}
