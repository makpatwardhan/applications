#include <iostream>
#include "dragon.h"

using namespace MyGame;

constexpr int DAMAGE_TO_HERO_FROM_DRAGON = 1;

Dragon::Dragon()
{
    m_healthPoints = 20;
    m_playerName = "Dragon";
}
Dragon::Dragon(int healthPoints, const std::string &playeName):
m_healthPoints(healthPoints),
m_playerName(playeName)
{
}
Dragon::~Dragon(){}

void Dragon::attack(std::shared_ptr<IPlayer>& player_to_attack) 
{
    player_to_attack->decreaceHealthPoints(DAMAGE_TO_HERO_FROM_DRAGON);
}
void Dragon::decreaceHealthPoints(int points)
{
    if( 0 >= m_healthPoints)
    {
        std::cout << m_playerName << " is dead" <<std::endl;
        std::cout << m_playerName << " loose the game" <<std::endl;
    }
    else	
    {
        (m_healthPoints > points)? m_healthPoints -= points : m_healthPoints = 0;        
        std::cout << m_playerName << " The health is reduced to : " << m_healthPoints << std::endl;
        m_healthPoints--;
    }	
}