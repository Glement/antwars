#pragma once
#include "warrior.h"
#include <map>
#include <vector>
using namespace std;
///\brief Class Clan that have Class Warriors.
class C_Clan
{
public:
    ///\brief Move all warriors that related to this clan.
    void c_move();
    ///\brief Create Clan with type=player.
    C_Clan(const char &player);
    C_Clan();
    ~C_Clan();
    ///\briefDelete all dead Warriors.
    void clean                                         ();
    ///\brief Return reference to all wariors
    map<char,vector <C_Warrior>>& get_warriors         (){return warriors;};
    ///\brief Add new road from this clan to another clan.
    void add_road                                      (const char & where,const vector<pair<int,int>> & road);
    ///\brief Increment variable count by variable increase if mark=0, and check if there are enemys or aliance near the clan.
    void check                                         (const int mark =0);
    ///\briefReturn reference to all roads from this clan.
    map<char,pair<vector<pair<int,int>>,int>>&get_roads() {return roads;};
    ///\brief return amount of warriors in clan.
    int get_count                                      ()const{return count;};
    ///\brief Return type of Clan.
    char get_type                                      (){return type;};
    ///\brief Set increase of this Clan.
    void set_increase                                  (const int & numb){increase=numb;};
    ///\brief Open road from this Clan to another
    void set_road_type                                 (const char & road,const int & numb){roads[road].second=numb;};
    ///\brief Get road status from this clan to another clan(provided by variable road).
    int get_road_type                                  (const char & road){return roads[road].second;};
    ///\brief Check if road from this clan to another clan exists(provided by variable road).
    int road_exist                                     (char & road){return roads.count(road);};
    ///\brief Get the position of clan on the map.
    pair<int,int>   get_position                       ()const{return position;};
    ///\brief Set clan position on map.
    void set_position                                  (const pair<int,int> & number){position=number;};
    ///\brief Set amount of warriors inside.
    void set_count                                     (const int & number){count=number;};
    ///\brief Return increase.
    int  get_increase                                  ()const {return increase;};
    ///\brief Make type of clan by variable type.
    void set_type                                      (const char & name){type=name;};
    ///\brief Write this clan on screen.
    void view_count                                    (const char & number);
private:
    ///\brief Position on map.
    pair<int,int> position;
    ///\brief Roads from this clan to another  clan.
    map<char,pair<vector<pair<int,int>>,int>> roads;
    ///\brief All wariors that came out from this clan.
    map<char,vector <C_Warrior>>  warriors;
    ///\brief How many warriors left.
    int count;
    ///\brief Amount of warriors restored by 1 turn.
    int increase;
    ///\brief  Type of clan. A user B bot N neutral.
    char type;
};
