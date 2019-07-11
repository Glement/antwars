#include "Headers/warrior.h"
#include <ncurses.h>
C_Warrior::~C_Warrior()
{
}

C_Warrior::C_Warrior(const char  & player,const vector<pair<int, int>> & coordinate)
{
    current=make_pair(coordinate[0].first,coordinate[0].second);
    type=player;
    position=coordinate;
}
void C_Warrior::clean()
{
    if((char)(mvinch(current.first, current.second) & A_CHARTEXT)=='1')
    {
        mvaddch(current.first, current.second, '-');
        type = 'X';
        position.clear();
    }
    if(type=='X')
    {
        position.clear();
    }
}
void C_Warrior::move()
{
    char tmp;
    if(type=='B')
    {
        tmp='A';
    }
    else if(type=='A')
    {
        tmp='B';
    }
    if(position.size()>0)
    {
        char cch=(mvinch(current.first, current.second) & A_CHARTEXT);
        if(cch=='1')
        {
            mvaddch(current.first, current.second,'-');
            position.clear();
            type='X';
        }
        else if(cch==tmp)
        {
            mvaddch(current.first, current.second, '-');
            type = 'X';// type x for warrior that dead. in higher function ill detect this and delete object
            position.clear();
        }
        else
        {
            char ch = mvinch(position[0].first, position[0].second) & A_CHARTEXT;
            if (ch == '-')// move to next point if there is nothing
            {
                mvaddch(current.first, current.second, '-');
                mvaddch(position[0].first, position[0].second, type);
                current = make_pair(position[0].first, position[0].second);
                position.erase(position.begin());
            } else if (ch == tmp) //if on next point is enemy, then make this warrior dead and replace by '-'
            {
                mvaddch(position[0].first, position[0].second, '1');
                mvaddch(current.first, current.second, '-');
                type = 'X';// type x for warrior that dead. in higher function ill detect this and delete object
                position.clear();
            }
            else if(ch==type)
            {
                mvaddch(position[0].first, position[0].second, '1');
                mvaddch(current.first, current.second, '-');
                type = 'X';// type x for warrior that dead. in higher function ill detect this and delete object
                position.clear();
            }
        }



    }
    else
    { //if it's reaches end of road it's dead,If it's reach players clan then clan have +1 warrior(writen in clan class), if enemy then -1.
        type='X';
        mvaddch(current.first,current.second,'-');
    }

}
