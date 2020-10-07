#ifndef DRAGON_H_
#define DRAGON_H_

#include "iplayer.h"

namespace MyGame
{
class Dragon : public IPlayer
{
    public:
        Dragon();    
        Dragon(int healthPoints, const std::string &playeName);
        void attack(std::shared_ptr<IPlayer>& player_to_attack) override;  
        void decreaceHealthPoints(int points) override;
        ~Dragon(); 
    private :
        int m_healthPoints;
        std::string m_playerName; 
};

}
#endif