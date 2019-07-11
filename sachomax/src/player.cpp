#include "Headers/player.h"
#include <map>
void C_Player::check(map<char, C_Clan> &clans,const int mark)
{
    for(auto it=clans.begin();it!=clans.end();it++)
    {
            if (it->second.get_type() == get_type())
            {
                it->second.check(mark);
            }
    }
}

void C_Player::clean(map<char, C_Clan> &clans)
{
        for(auto it=clans.begin();it!=clans.end();it++)
        {
            if (it->second.get_type() == get_type())
            {
                it->second.clean();
            }
        }
}

bool C_Player::move(map<char,C_Clan> & clans)
{
    int d=0;
    for(auto it=clans.begin();it!=clans.end();it++)
    {
        if(it->second.get_type()==get_type())
        {
            it->second.c_move();
        }
    }
    for(auto it=clans.begin();it!=clans.end();it++)
    {
        if(it->second.get_type()==get_type())
        {
            d++;//if there are some clans that have same type as player, than you still have chance to win.
        }
    }
    if(d==0)
    {
        return false;
    }
    else
    {
        return true;
    }

}
void C_Player::open_road(const char &a, const char &b,map<char,C_Clan> & clans)//open roads between two clans, if exists.
{
    char from=a;
    char where=b;
    if(from!=where)
    {
        if(clans.count(from) && clans.count(where))
        {
            if(clans[from].get_type()==get_type())
            {
                if (clans[from].road_exist(where))
                {
                    clans[from].set_road_type(where,-1);
                }
                if(clans[where].get_type()==get_type() && clans[from].get_type()==get_type())
                {
                    if(clans[where].road_exist(from))
                    {
                        clans[where].set_road_type(from,1);
                    }
                }
                else
                {
                    if(clans[where].get_road_type(from) != -1)
                    {
                        clans[where].set_road_type(from,1);
                    }

                }
            }

        }

    }
}
void C_Player::close(const char &a, const char &b,map<char,C_Clan> & clans)//close road between two clans.
{
    char from=a;
    char where=b;
    clans[from].set_road_type(where,0);
}
