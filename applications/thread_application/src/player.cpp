#include <cstdlib>
#include <unordered_map>
#include "orc.h"
#include "dragon.h"
#include "timer.h"
#include "hero.h"

#include <iostream>

namespace MyGame
{
class Player
	{
		public:
		Player()
		{
            m_players.insert(std::make_pair(std::string("hero"), std::make_shared<Hero>()));
            m_players.insert(std::make_pair(std::string("orc"), std::make_shared<Orc>()));
            m_players.insert(std::make_pair(std::string("dragon"), std::make_shared<Dragon>()));
		}
        std::shared_ptr<IPlayer>& getPlayer(const std::string &name)
        {
                return m_players.at(name);
        }
        void addPlayer(const std::string &name,std::shared_ptr<IPlayer> player)
        {
            m_players.insert(std::make_pair(name, player));
        }		
	
	    void startGame()
        {
            int choice; 
            while(1)
            {
                std::cout << "###########################################"<< std::endl;
                std::cout << "Press 1 to attack orc" << std::endl;
                std::cout << "Press 2 to attack Dragon" << std::endl;
                std::cout << "Press 3 to exit" << std::endl;
                std::cout << "Enter your option : ";
                std::cin >> choice;
                attackPlayer(choice);
                std::cout << "Orc is attacking " <<std::endl;
		        Timer orcTimer{1300};
                orcTimer.start();
		        m_players.at("orc")->attack(m_players.at("hero"));
                std::cout << "Dragon is attacking " <<std::endl;
		        Timer dragonTimer{2600};
		        dragonTimer.start();
		        m_players.at("dragon")->attack(m_players.at("hero"));
            }

        }
        void attackPlayer(int choice)
        {
            if(1 == choice)
            {
                m_players.at("hero")->attack(m_players.at("orc"));
            }
            else if( 2 == choice)
            {
                m_players.at("hero")->attack(m_players.at("dragon"));
            }
            else
            {
                exit(0);
            }

        }
        private:
        std::unordered_map<std::string, std::shared_ptr<IPlayer>> m_players;		
		
	};
	
}


int main(void)
{
    
	MyGame::Player players;
    players.startGame();

}