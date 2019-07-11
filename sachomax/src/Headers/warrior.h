#pragma once
#include <vector>
using namespace std;
/*!
 \brief Class that introduce Warriors.
 */
class C_Warrior
{
public:
    ~C_Warrior();
    C_Warrior(const char  & player,const vector<pair<int,int>> & coordinate);
    char type; ///\brief type of warrior(A for user B for AI)
    /*!
     \brief Replace this object on map if it's dead.
     */
    void clean();
    /*!
     \brief Move object across the map
     */
    void move();
private:
    ///\brief current coordinates on map
    pair<int,int> current;
    ///\brief road that last.
    vector<pair<int,int>> position;
};
