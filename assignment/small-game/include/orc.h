#ifndef ORC_H_
#define ORC_H_

#include "iplayer.h"

namespace MyGame
{

class Orc : public IPlayer
{
    public:
        Orc();    
        Orc(int healthPoints, const std::string &playeName) ;
        void attack(std::shared_ptr<IPlayer>& player_to_attack) override;  
        void decreaceHealthPoints(int points) override;
        ~Orc();  
    private :
        int m_healthPoints;
        std::string m_playerName;
};

}
#endif