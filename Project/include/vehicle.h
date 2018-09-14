#ifndef VEHICLE_H
#define VEHICLE_H

#include "square.h"
#include <cstdlib>
#include <ctime>


class vehicle
{

    public:
        vehicle(const int &, const int & );
        virtual ~vehicle();
        virtual int func(square &)=0;
        void setSpeed(const int &);
        float getSpeed() const;
        void setAccessAbility(const float &);
        float getAccessAbility() const;
        void setStatus(const int &);
        int getStatus() const;
        void addMoves();
        void setDamage(const int &);
        int getDamage() const;
        void addDamage(const int &);
        void makeDamage(const square& );
        void setXvYv(const int &,const int &);
        int getXv() const;
        int getYv() const;
        int moveto();
        static void setTotalDamage(const int &);
        static void addTotalDamage(const int &);
        static int getTotalDamage();
        static void setTotalMoves(const int &);
        static void addTotalMoves();
        static int getTotalMoves();
        char getType() const;
        int getId();
        int getMoves() const;
        void printInfo() const;
        void setRound(const int &);
        int getRound() const;
        static void setNum(const int &);
        void setType(const char &);


    private:
        float accessAbility;
        int speed,status;
        int xv,yv;
        char type;
        int moves=0;
        int damage=0;
        int id;
        int round=0;
        static int num;

        static int totalMoves;
        static int totalDamage;

};

#endif // VEHICLE_H


