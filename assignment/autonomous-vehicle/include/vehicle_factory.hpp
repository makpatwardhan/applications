
#include "autonomous_vehicle.hpp"
#include <vector>
#include <memory>

namespace AutonomousVehicleApp
{
	class VehicleFactory
	{
		public:
		const std::vector<std::shared_ptr<Vehicle> >& CreateCarFleet();
						
		private:
		template<typename T>
		std::shared_ptr<Vehicle> CreateCar(const T type, std::shared_ptr<Vehicle> vehicle)
		{
			int throttle;
			int break_pressure;
			VehicleType vehicle_type;
			switch(type)
			{
				case SEDAN:
						throttle = 15;
						break_pressure = 35;
						vehicle_type = SEDAN;
				break;
				case SMALL_TRUCK:
						throttle = 50;
						break_pressure = 180;
						vehicle_type = SMALL_TRUCK;
				break;
				case LARGE_TRUCK:
						throttle = 77;
						break_pressure = 320;
						vehicle_type =  LARGE_TRUCK;
				break;
				default:
						throttle = 0;
						break_pressure = 0;
						vehicle_type = UNKNOWN;
				break;
			}
			std::shared_ptr<Vehicle> veh;
			veh = std::make_shared<AutonomousVehicle>(vehicle_type, throttle, break_pressure, vehicle);
			return veh;
		}		
		private:		
		std::vector<std::shared_ptr<Vehicle> >  m_fleet_of_cars;
	};
};
