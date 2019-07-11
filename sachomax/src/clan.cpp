#include "Headers/clan.h"
#include <ncurses.h>
#include <string>
using namespace std;
void swap (char & a,char & b)
{
    char tmp=a;
    a=b;
    b=tmp;
}
void C_Clan::clean()
{
    for(auto it=get_warriors().begin();it!=get_warriors().end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            it->second[i].clean();
        }
    }
}
C_Clan::C_Clan()
{
    increase=0;
    count=9;
    type='N';
    roads.clear();
}
C_Clan::C_Clan(const char & player)
{
    increase=1;
    count=0;
    type=player;
    roads.clear();
}
void C_Clan::add_road(const char & where,const vector<pair<int, int>> & road)
{
    pair<vector<pair<int,int>>,int> par;
    par=make_pair(road,0);
    roads[where]=par;
}
void C_Clan::check(const int mark)
{
    if(mark)
    {
        count += increase;
    }
    if(count>9)
    {
        count = 9;
    }
    char tmp;
    char tmp2;
    if(type=='B')
    {
        tmp='A';
        tmp2='A';
    }
    else if(type=='A')
    {
        tmp2='B';
        tmp='B';
    }
    else if(type=='N')
    {
        tmp2='A';
        tmp='B';
    }
    for(auto it=roads.begin();it!=roads.end();it++)//check all clans related to current player, if there are any enemys or alience near the clan, and kill them or get them in clan, then incre,ent or decrement variable count.
    {
        if(it->second.second==1)
        {
            if((char)(mvinch(it->second.first[0].first, it->second.first[0].second) & A_CHARTEXT)==tmp ||
                    (char)(mvinch(it->second.first[0].first, it->second.first[0].second) & A_CHARTEXT)==tmp2)
            {
                if(count>0)
                {
                    mvaddch(it->second.first[0].first, it->second.first[0].second,'-');
                    count--;
                }
                else
                {
                    if((char)(mvinch(it->second.first[0].first, it->second.first[0].second) & A_CHARTEXT)==tmp)//if no more warriors in clan and near clan is enemt, then clans become enemy's clan.
                    {
                        mvaddch(it->second.first[0].first, it->second.first[0].second,'-');
                        swap(type,tmp);
                    }
                    else if((char)(mvinch(it->second.first[0].first, it->second.first[0].second) & A_CHARTEXT)==tmp2)
                    {
                        mvaddch(it->second.first[0].first, it->second.first[0].second,'-');
                        swap(type,tmp2);
                    }

                }
            }
            else if((char)(mvinch(it->second.first[0].first, it->second.first[0].second) & A_CHARTEXT)==type)// if not income road and it's aliance there, get him in clan
            {
                count++;
                mvaddch(it->second.first[0].first, it->second.first[0].second,'-');
                if(count>9)
                    count=9;
            }
        }
        else if(it->second.second==-1)
        {
            if((char)(mvinch(it->second.first[0].first, it->second.first[0].second) & A_CHARTEXT)==tmp)// if enemy than kill
            {
                if(count>0)
                {
                    mvaddch(it->second.first[0].first, it->second.first[0].second,'-');
                    count--;
                }
                else
                {
                    mvaddch(it->second.first[0].first, it->second.first[0].second,'-');
                    swap(type,tmp);
                }
            }
            else if((char)(mvinch(it->second.first[0].first, it->second.first[0].second) & A_CHARTEXT)=='-')// if free road then move warrior there.
            {
                if(count>0)
                {
                    C_Warrior tt(type,it->second.first) ;
                    warriors[it->first].push_back(tt);
                    count--;
                }
            }
        }
    }
}
void C_Clan::c_move()//move all warriors
{
    for(auto it=warriors.begin();it!=warriors.end();it++)
    {
        for(unsigned int i=0;i<it->second.size();i++)
        {
            if(it->second[i].type=='X')
            {
                it->second[i].clean();
                it->second.erase(it->second.begin()+i);
            }
            else
            {
                it->second[i].move();
            }
        }
    }
}
void C_Clan::view_count(const char & number)
{
    char nmb;
    nmb=number;
    mvaddch(position.first,position.second,nmb);
    mvaddch(position.first,position.second+1,type);
    mvaddch(position.first,position.second+2,(char)(count+48));
}
C_Clan::~C_Clan()
{

}
