#ifndef _AUTONOMOUS_VEHICLE_HPP_
#define _AUTONOMOUS_VEHICLE_HPP_

#include "vehicle.hpp"
#include <iostream>
#include <memory>

namespace AutonomousVehicleApp
{
	class AutonomousVehicle : public Vehicle
	{
		public:
		AutonomousVehicle(const VehicleType type, const int throttle, const int break_pressure, const std::shared_ptr<Vehicle>& behind_vehicle);
		AutonomousVehicle(const AutonomousVehicle& autonomous_vehicle);
		AutonomousVehicle& operator= (const AutonomousVehicle& autonomous_vehicle);
		AutonomousVehicle(AutonomousVehicle&& autonomous_vehicle);
		void ApplyThrottle();
		void ApplyBrake();
		VehicleType GetType();
		VehicleState GetState();
		private:
		VehicleType m_vehicle_type;
		VehicleState m_vehicle_state;
		int m_throttle;
		int m_break_pressure;
		std::shared_ptr<Vehicle> m_ptr_to_behind_vehicle;		
		
	};
}
#endif //_AUTONOMOUS_VEHICLE_HPP_


