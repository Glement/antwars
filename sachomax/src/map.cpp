#include "Headers/map.h"
#include <fstream>
#include <ncurses.h>
using namespace std;
bool eat_enter(ifstream & file)//just eat newline
{
    char tmp;
    if(file.read(&tmp,sizeof(char)))
    {
        if(tmp!='\n')
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool read_map(const string & name,map<char,C_Clan> & clans)//read and check  map if it's right .
{
    ifstream file;
    string map_is;
    map_is="src/"+name;
    file.open(map_is);
    vector<vector<char>> map_play;
    vector<char> x;
    char from='s';
    char where='s';
    char tmp='a';
    if(clans.size())
    {
        return true;
    }
    pair<int,int> pos=make_pair(-10,-10);
    if(file.is_open())
    {
        while(1)//read all clans, roads between clans, and clans type.
        {
            int road[2];
            if(file.read(&from,sizeof(char)))
            {
                if(from=='-')//if true than it's the end of clans and roads, and become map reading.
                {
                    break;
                }
                    if(file.read(&tmp,sizeof(char)))
                    {
                        if(tmp!='\n')
                        {
                            return false;
                        }
                        if(file >> pos.first >> pos.second)
                            if(pos.first>0 && pos.first<400 && pos.second>0 && pos.second<400)
                            {
                                if(!eat_enter(file))
                                    return false;
                            }
                        if (file.read(&tmp, sizeof(char)))
                        {
                            if (tmp == 'A' || tmp == 'B' || tmp == 'N')//check if clan type is right.
                            {
                                C_Clan a(tmp);
                                clans[from]=a;
                                clans[from].set_position(pos);
                                if(!eat_enter(file))
                                    return false;
                                int count;
                                if(file >> count)
                                {
                                    if(count>=0 && count < 10)
                                    {
                                        clans[from].set_count(count);
                                    }
                                    else
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                                if(!eat_enter(file))
                                    return false;
                                while(1)
                                {
                                    if (file.read(&where,sizeof(char)))
                                    {
                                        if(where=='-')// end of reading current clan and current clans roads.
                                        {
                                            if(!eat_enter(file))
                                                return false;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        return false;
                                    }
                                    if(clans[from].road_exist(where))
                                    {
                                        return false;
                                    }
                                    if (!eat_enter(file))
                                        return false;
                                    vector<pair<int, int>> path;
                                    while (1)
                                    {
                                        if (file >> road[0] >> road[1])
                                        {
                                            if (road[0] > -1 && road[0] < 401 && road[1] > -1 && road[1] < 401)
                                            {
                                                path.push_back(make_pair(road[0], road[1]));
                                            }
                                            else if (road[0] == -1 && road[1] == -1)//if true than end of reading road from this clan to another.
                                            {
                                                clans[from].add_road(where, path);
                                                path.clear();
                                                if (!eat_enter(file))
                                                    return false;
                                                break;
                                            }
                                            else
                                            {
                                                return false;
                                            }
                                        }
                                        else
                                        {
                                            return false;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        return false;
                    }
            }
            else
            {
                return false;
            }
        }
        if(!eat_enter(file))
            return false;
        while(file.read(&tmp,sizeof(char)))
        {
            if(tmp=='\n')
            {
                map_play.push_back(x);
                x.clear();
            }
            else
            {
                if(tmp==' ' || tmp=='|' || tmp=='-' || tmp=='B' || tmp=='A' || tmp=='N' || tmp=='#')// check if there are no forbiden symbols on map.
                {
                    x.push_back(tmp);
                }
                else
                {
                    return false;
                }
            }

        }

    }
    else
    {
        return false;
    }
    for(auto it=clans.begin();it!=clans.end();it++)
    {
        for(auto it2=it->second.get_roads().begin();it2!=it->second.get_roads().end();it2++)
        {
            for(unsigned int i=0;i<it2->second.first.size();i++)
            {
                if(map_play[it2->second.first[i].first][it2->second.first[i].second]!='-')// check that roads writen by '-'.
                {
                    return false;
                }
            }
        }
    }
    for(unsigned int i=0;i<map_play.size();i++)//check if map not empty(why not).
    {
        if(map_play[i].size()==0)
        {
            return false;
        }
    }
    if(map_play.size()==0)
    {
        return false;
    }

    for(unsigned int i=0;i<map_play.size();i++)
    {
        for(unsigned int ii=0;ii<map_play[i].size();ii++)// write map on screen.
        {
            mvaddch(i,ii,map_play[i][ii]);
        }
    }
    refresh();
    return true;
}
