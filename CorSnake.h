//
// Created by andresold on 25.11.17.
//

#ifndef COM_3SEM_45LABANDREANDVIKA_CORSNAKE_H
#define COM_3SEM_45LABANDREANDVIKA_CORSNAKE_H

class CorSnake
{
    int x, y;
    char ch;
public:
    CorSnake (){ x= y= 0; ch=' ';}
    CorSnake (int a, int b)
    {
        x= a; y= b; ch= ' ' ;
    }
    CorSnake (const CorSnake  &ekans)
    {
        ch= ekans.ch;
        x= ekans.x;
        y= ekans.y;
    }
    void setCh(char x)
    {
        ch= x;
    }
    char getCh()
    {
        return ch;
    }
    int getX()
    {
        return x;
    }
    void setX(int no)
    {
        x= no;
    }
    int getY()
    {
        return y;
    }
    void setY(int no)
    {
        y= no;
    }
};



#endif //COM_3SEM_45LABANDREANDVIKA_CORSNAKE_H
