#pragma once
#include "clan.h"
#include "map.h"
#include <map>
using namespace std;
///\brief Read current save.
void read_save(int & number_map,map<char,C_Clan> & clans);
///\brief Save current proggres(may cose lost of all wariors that are not inside clans).
void write_save(const int & number_map,map<char,C_Clan> & clans);
