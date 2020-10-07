#ifndef HERO_H_
#define HERO_H_
#include "iplayer.h"

namespace MyGame
{
    class Hero : public IPlayer
    {
        public:
        Hero();
        Hero(int healthPoints,const std::string& playerName);
        void attack(std::shared_ptr<IPlayer>& player_to_attack) override ;    
        void decreaceHealthPoints(int points) override;
        ~Hero();
        private :
        int m_healthPoints;
        std::string m_playerName;
    };
}
#endif