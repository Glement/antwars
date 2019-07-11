#include "Headers/bot.h"
using namespace std;
bool C_Bot::make_turn (map<char,C_Clan> & clans)
{
    map<char,C_Clan> clans2=clans;
    int tmp=0;
    for(auto it=clans.begin();it!=clans.end();it++)
    {
        if(it->second.get_type()=='B' && it->second.get_count()>3)// open new road each time that bot's clan have more than 3 warriors
        {
            for(auto it2=clans2.begin();it2!=clans2.end();it2++)
            {
                char tmp2=it2->first;
                if(it->first!=it2->first)
                {
                   if(it2->second.get_type()!='B' )
                   {
                       if(it->second.road_exist(tmp2))
                       {
                           if(it->second.get_road_type(tmp2)!=-1)
                           {
                               open_road(it->first,tmp2,clans);
                               tmp = 1;
                               break;
                           }
                       }
                   }
                }
            }
        }
        if(tmp==1)
        {
            break;
        }
    }
    return true;
}
