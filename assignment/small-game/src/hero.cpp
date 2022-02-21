#include <iostream>
#include "hero.h"

constexpr int DAMAGE_TO_MONSTER = 2;

using namespace MyGame;
		
Hero::Hero()
{
	m_healthPoints = 40;
	m_playerName = "Hero";
}
Hero::Hero(int healthPoints,const std::string& playerName):
m_healthPoints(healthPoints),
m_playerName(playerName)
{}

Hero::~Hero(){}

void Hero::attack(std::shared_ptr<IPlayer>& player_to_attack)  
{
	player_to_attack->decreaceHealthPoints(DAMAGE_TO_MONSTER);
}
void Hero::decreaceHealthPoints(int points)
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

	
	
	


