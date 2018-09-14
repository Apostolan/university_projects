#ifndef RESCUE_H
#define RESCUE_H

#include "vehicle.h"

class rescue : public vehicle
{
    public:
        rescue(const int &,const int &);
        virtual ~rescue();
        virtual int func(square &);
        void epidiorthwsh(vehicle &);
        static int getTotalRevives();
        static void setTotalRevives(const int &);
        static void addTotalRevives();
        void addRevives();
        int getRevives() const;
        void printInfo() const;

    private:
        int revives;
        static int totalRevives;
};

#endif // RESCUE_H
