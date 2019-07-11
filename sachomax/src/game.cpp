#include "Headers/game.h"
#include <fstream>
#include <ncurses.h>
#include <string>
#include <vector>
#include <map>
#include "Headers/user.h"
#include "Headers/bot.h"
#include "Headers/player.h"
bool menu()
{
    while(1)
    {
        erase();
        mvprintw(0,0,"Press space to play or any other key to quit.");
        refresh();
        char tmp=getchar();
        if(tmp==' ')
        {
            erase();
            return true;
        }
        else
        {
            erase();
            return false;
        }

    }
}
bool game()
{
    C_User a('A');
    C_Bot n('N');
    map<char,C_Clan> clans;
    vector<string> maps;
    fstream f;
    int number =1;
    for(int i=1;i<4;i++)
    {
        string map_name="map_"+to_string(i)+".txt";
        maps.push_back(map_name);
    }
    f.open("save.txt");
    if(f.is_open())
    {
        read_save(number,clans);
    }
    while(read_map(maps[number-1],clans))//while there are maps, than play.
    {
        C_Bot b('B');
        b.set_hard(number);
        for(auto it=clans.begin();it!=clans.end();it++)
        {
            it->second.view_count(it->first);
        }
        refresh();
        while(1)
        {
            if(a.make_turn(clans))// take bot's and user's turns and then check all clans and move all warriors outside clans.
            {
                write_save(number,clans);
            }
            b.make_turn(clans);
            if(!b.move(clans))
            {
                clans.clear();
                number++;
                erase();
                break;
            }
            if(!a.move(clans))
            {
                clans.clear();
                erase();
                return false;
            }
            a.check(clans,1);
            b.check(clans,1);
            n.check(clans,1);
            if(!b.move(clans))
            {
                clans.clear();
                number++;
                erase();
                break;
            }
            if(!a.move(clans))
            {
                clans.clear();
                erase();
                return false;
            }
            for(auto it=clans.begin();it!=clans.end();it++)
            {
                if(it->second.get_type()=='A')
                {
                    it->second.set_increase(1);
                }
                else if(it->second.get_type()=='B')
                {
                    it->second.set_increase(number);
                }
                else
                {
                    it->second.set_increase(0);
                }
                it->second.view_count(it->first);//refresh count of warriors  and type of each clan
            }

            refresh();
        }
        clans.clear();
        erase();
        refresh();
    }
    clans.clear();
    erase();
    return true;
}
