#include <iostream>
#include "orc.h"

using namespace MyGame;

constexpr int DAMAGE_TO_HERO_FROM_ORC = 1;

Orc::Orc()
{
    m_healthPoints = 7;
    m_playerName = "Orc";   
}

Orc::Orc(int healthPoints,const std::string &playeName):
m_healthPoints(healthPoints),
m_playerName(playeName)
{
}
Orc::~Orc(){}

void Orc::attack(std::shared_ptr<IPlayer>& player_to_attack) 
{
    player_to_attack->decreaceHealthPoints(DAMAGE_TO_HERO_FROM_ORC);
}

void Orc::decreaceHealthPoints(int points)
{
    if( 0 >= m_healthPoints)
    {
        std::cout << m_playerName << " is dead" <<std::endl;
        std::cout << m_playerName << " loose the game" <<std::endl;
    }
    else	
    {
        (m_healthPoints > points)? m_healthPoints -= points : m_healthPoints = 0;        
        std::cout << m_playerName << " The health is reduced to : " << m_healthPoints <<std::endl;

    }	
}
    
