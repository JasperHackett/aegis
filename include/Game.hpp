#ifndef GAME_H
#define GAME_H

////#include <Clickable.hpp>
//#include <Unit.hpp>
#include <map>
class Unit;

class Game
{
    public:
        Game();
        virtual ~Game();

        int days; //Stores a counter of days passed
        int manpower; //
////
//        std::map<std::string,Unit> playerArmy;
//        std::map<std::string,Unit> enemyArmy;

    protected:

    private:
};

#endif // GAME_H
