#include "Headers/save.h"
#include <string>
#include <fstream>
#include <map>
using namespace std;
void read_save(int & number_map,map<char,C_Clan> & clans)
{
    int number;
    ifstream file;
    file.open("src/save.txt");
    char tmp[4];
    int count;
    file >> number;
    string map_name = "map_" + to_string(number)+".txt";
    number_map=number;
    read_map(map_name, clans);
    for (auto it = clans.begin(); it != clans.end(); it++)
    {
        file >> tmp[0] >> tmp[1] >> count;
        clans[tmp[0]].set_type(tmp[1]);
        clans[tmp[0]].set_count(count);
        clans[tmp[0]].view_count(tmp[0]);
    }
    for(auto it=clans.begin();it!=clans.end();it++)
    {
        for(auto it2=clans.begin();it2!=clans.end();it2++)
        {
            char tmp2=it2->first;
            if(it->second.road_exist(tmp2))
            {
                file >> tmp[0] >> tmp[1] >> count;
                clans[tmp[0]].set_road_type(tmp[1],count);
            }
        }
    }
}
void write_save(const int & number_map, map<char,C_Clan> & clans)
{
    ofstream file;
    remove( "save.txt" );
    file.open("save.txt");
    if(file.is_open())
    {
        file << number_map << endl;
        for (auto it = clans.begin(); it != clans.end(); it++)
        {
            file << it->first << it->second.get_type() << it->second.get_count() << endl;
        }
        for(auto it=clans.begin();it!=clans.end();it++)
        {
            for(auto it2=clans.begin();it2!=clans.end();it2++)
            {
                char tmp=it2->first;
                if(it->second.road_exist(tmp))
                {
                    file << it->first << it2->first << it->second.get_road_type(it2->first) << endl;
                }

            }
        }
        file << flush;

    }
}
