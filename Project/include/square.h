#ifndef SQUARE_H
#define SQUARE_H


#include <cstdlib>
#include <ctime>



#define PLATOS 10
#define MHKOS 10

class square
{
    public:
        square();
        square(const int &,const int &);
        virtual ~square();
        void setPaladio(const float &);
        void setIridio(const float &);
        void setLeuko(const float &);
        void setAccess(const float &);
        static void capture(const int &,const int &,const int &);
        static void uncapture(const int &,const int &);
        void setX(const int &);
        void setY(const int &);
        float getPaladio() const;
        float getIridio() const;
        float getLeuko() const;
        float getAccess() const;
        static int getIsFree(const int &,const int &);
        int getX() const;
        int getY() const;
        static void setFlag(const int &,const int &);
        static bool hasFlag(const int &, const int &);


    private:
        float paladio,iridio,leuko,access;
        static bool flag[PLATOS][MHKOS];
        static int isFree[PLATOS][MHKOS];
        int x, y;
};

#endif // SQUARE_H


