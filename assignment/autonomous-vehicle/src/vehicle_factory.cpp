#include "vehicle_factory.hpp"

namespace AutonomousVehicleApp
{
		const std::vector<std::shared_ptr<Vehicle> >& VehicleFactory::CreateCarFleet()
		{
			std::shared_ptr<Vehicle> large_truck = CreateCar(LARGE_TRUCK, nullptr);
			std::shared_ptr<Vehicle> small_truck = CreateCar(SMALL_TRUCK, large_truck);
			std::shared_ptr<Vehicle> sedan = CreateCar(SEDAN, small_truck);			
			m_fleet_of_cars.emplace_back(sedan);
			m_fleet_of_cars.emplace_back(small_truck);
			m_fleet_of_cars.emplace_back(large_truck);
			return m_fleet_of_cars;
		}
}

