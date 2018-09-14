#ifndef EXPLORE_H
#define EXPLORE_H

#include "vehicle.h"


class explore : public vehicle
{
    public:
        explore(const int &,const int &);
        virtual ~explore();
        static int getTotalFlags();
        virtual int func(square &);
        int getFlags() const;
        static void setTotalFlags(const int &);
        static void addTotalFlag();
        void printInfo() const;

    private:
        int flags;
        static int totalFlags;
};

#endif // EXPLORE_H
