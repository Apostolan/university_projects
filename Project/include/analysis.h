#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "vehicle.h"


class analysis : public vehicle
{
    public:
        analysis(const int &,const int &);
        virtual ~analysis();
        virtual int func(square &);
        void setMaxFortio(const float &);
        float getMaxFortio() const;
        void addFortioP(const float &);
        float getFortioP() const;
        void addFortioI(const float &);
        float getFortioI() const;
        void addFortioL(const float &);
        float getFortioL() const;
        void addTotalP(const float &);
        void addTotalI(const float &);
        void addTotalL(const float &);
        static void setTotalAmount(const float &);
        static float getTotalAmount();
        void mhdenismosFortiwn();
        void moveto(const int &);
        void printInfo() const;

    private:
        float maxFortio;
        float fortioP,fortioI,fortioL;
        static float totalP,totalI,totalL;
};

#endif // ANALYSIS_H
