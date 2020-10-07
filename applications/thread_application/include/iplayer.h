#ifndef I_PLAYER_H
#define I_PLAYER_H

#include <memory>

namespace MyGame
{
	class IPlayer
	{
		public:
		virtual void attack(std::shared_ptr<IPlayer>& player_to_attack) = 0;
		virtual void decreaceHealthPoints(int points) = 0;
		virtual ~IPlayer(){};
	};
}

#endif

