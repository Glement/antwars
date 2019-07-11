#include "Headers/user.h"
using namespace std;
bool C_User::make_turn(map<char,C_Clan> & clans)
{
    char com[3];
    for(int i=0;i<3;i++)
    {
        com[i]=getchar();
        if(com[i]==' ')
        {
            return false;
        }
    }
    if(com[0]=='S' && com[1]=='A' && com[2]=='V')//if true making save.
    {
        return true;
    }
    if(clans.count(com[0]) && clans.count(com[2]))
    {
        if(com[0]==com[2])
            return false;
        if(clans[com[0]].get_type()=='A')//checking if clans, that making road from is have type same as player.
        {
            if(com[1]=='0')
            {
                if(clans[com[0]].road_exist(com[2]))
                {
                    if(clans[com[2]].get_road_type(com[0])==1)
                    {
                        close(com[2],com[0],clans);
                        close(com[0],com[2],clans);
                    }
                    else
                    {
                        if(clans[com[2]].get_road_type(com[0])==-1)
                        {
                            clans[com[0]].set_road_type(com[2],1);
                        }
                    }
                }

            }
            if(com[1]=='1')
            {
                if(clans[com[0]].road_exist(com[2]))
                {
                    clans[com[0]].set_road_type(com[2],-1);
                    if(clans[com[2]].get_road_type(com[0])!=-1)
                    {
                        clans[com[2]].set_road_type(com[0], 1);
                    }
                }
            }
        }
    }
    return false;
}
