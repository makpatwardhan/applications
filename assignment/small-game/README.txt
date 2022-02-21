
############################################################################################ README #########################################################################################################

1. file structure 

	a. src folder contains all the .cpp files 
	b. include folder contains all the .h files 

2. Compilation and execution 

	a. chmod a+x start.sh
	b. ./start.sh (This will generate output file game.out)
	
after executing above command you will get into interactive shell for the game.

3. How it is working 

	The current game works in sequential manner .
	e.g if player attacks orc then after that automatically timer will start 1300 ms and after that orc will attack player 
		and again one more timer will start for 2600ms after timer timeouts then dragon will attack player 
		so to summerize once player attack arc or dragon then immidiately orc will attack player for damage of health points 
		and then dragon will attack the player to damage health points for player.

4.Design 
	I have created one interface IPlayer. From IPlayer Hero,Orc and Dragon is created (Inheritence). 
	The player class acts as Observer for Hero as well as orc and Dragon and observes on attack events
	There is seperate Timer class which takes care of timer 1300ms and 2600ms for Orc and Dragon respectively 

5. Pending task .
	The application should be coverted to thread based where orc ,Dragon and Hero can play simulataneously 
	The orc and dragon should be in sperate thread with the timer of 1300ms and 2600ms resp should be running 
	for damaging the hero for health points. I didnt got the time for to complete the thread based implmnetation 
	for Orc and Dragon .

Question :- 

Please implement the following game in C++. The code (and, if you choose, docs and/or tests) should meet your professional standards, as if it were a task at work. If possible, do not try to guess what we "want to see", just solve the problem as you think best. Also, don't spend any time on a nice user experience -- ugly is ok, and you don't need more features than the ones given below. Use any libraries you like. Spend at most two hours; if it would take you longer, stop after the time is up and write a brief explanation of your plan for the rest (in comments or a separate freeform text).

 

The player controls a hero who fights two monsters: an orc and a dragon.
The hero has 40 health points, the orc has 7, the dragon has 20.
Every 1300ms, the orc attacks the hero for 1 damage, which means that the hero loses 1 health point.
Every 2600ms, the dragon attacks the hero for 3 damage.
Each time the player types "attack orc" or "attack dragon", the hero attacks the corresponding monster for 2 damage.
If the orc's or dragon's health points are reduced to zero, it is dead and can neither attack nor be attacked.
If both monsters die, the player wins the game.
If the hero's health points are reduced to zero, the player loses the game.

 
			
	
	




