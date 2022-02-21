#include "vehicle_factory.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <mutex>

using namespace AutonomousVehicleApp;
using namespace std::chrono_literals;


void ObserveStates(std::vector<std::shared_ptr<Vehicle> >& cars_fleet)
{	std::vector<std::shared_ptr<Vehicle> >::iterator itr;
	for(itr = cars_fleet.begin(); itr != cars_fleet.end(); ++itr)
	{ 
		std::shared_ptr<Vehicle>& ptr = (*itr);
		std::cout << "STATE OBSERVER : " << "Vehicle " << AutonomousVehicleApp::EnumToString(ptr->GetType()) << " changed status to " << 
		AutonomousVehicleApp::EnumToString(ptr->GetState()) << std::endl;
	}
}

void SimulationLoop()
{
	VehicleFactory factory;
	int n = 4;
	int counter = 0;
	std::mutex mut;
		
	std::vector<std::shared_ptr<Vehicle> > cars_fleet = factory.CreateCarFleet();
	while(true)
	{
		cars_fleet.at(0)->ApplyThrottle();
		ObserveStates(cars_fleet);
		mut.lock();
		counter++;
		mut.unlock();
		std::this_thread::sleep_for(1000ms);
		if(4 == counter)
		{
			std::cout << "4 times invloked" <<std::endl;
		}
		cars_fleet.at(0)->ApplyBrake();
		ObserveStates(cars_fleet);
		std::this_thread::sleep_for(1000ms);
	}
}



int main(void)
{
	std::thread t(&SimulationLoop);
	
	if(t.joinable())
	{
		t.join();
	}
	return 1;
}


