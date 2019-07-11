#pragma once
#include <map>
#include "clan.h"
using namespace std;
///\brief Father class with some functions emplemented.
class C_Player
{
public:
    ///\brief Execute function check in all clans that have same type as player.
    virtual void check      (map<char,C_Clan> & clans,const int mark=0);
    ///\brief Delete all dead warriors from all clans that related to player.
    void clean              (map<char,C_Clan> & clans);
    C_Player                (){};
    ///\brief Open road from clan to clan.
    void open_road  (const char & a, const char & b,map<char,C_Clan> & clans);
    ///\brief Move all Warriors that related to all clans that related to player.
    bool move       (map<char,C_Clan> & clans);
    void close      (const char &a, const char &b,map<char,C_Clan> & clans);///\brief close road.
    ~C_Player               (){};
    ///\brief Get player type.
    virtual char get_type   ()const {return type;};
    ///\brief Set type of player.
    virtual void set_type   (const char & name){type=name;}
    ///\brief Make turn.
    virtual bool make_turn  (map<char,C_Clan> & clans)=0;
private:
    ///\brief Player type.
    char type;
};
