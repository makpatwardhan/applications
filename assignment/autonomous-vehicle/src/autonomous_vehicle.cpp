#include "autonomous_vehicle.hpp"


namespace AutonomousVehicleApp
{
	AutonomousVehicle::AutonomousVehicle(
	const VehicleType type, const int throttle, const int break_pressure, const std::shared_ptr<Vehicle>& behind_vehicle):
	m_vehicle_type(type),
	m_throttle(throttle),
	m_break_pressure(break_pressure),
	m_ptr_to_behind_vehicle(behind_vehicle),
	m_vehicle_state(NOT_SET)
	{
	}

	AutonomousVehicle::AutonomousVehicle(const AutonomousVehicle& autonomous_vehicle)
	{
		this->m_vehicle_state = NOT_SET;
		this->m_ptr_to_behind_vehicle = nullptr;
		this->m_vehicle_type = autonomous_vehicle.m_vehicle_type;
		this->m_throttle = autonomous_vehicle.m_throttle;
		this->m_break_pressure = autonomous_vehicle.m_break_pressure;				
	}

	AutonomousVehicle& AutonomousVehicle::operator= (const AutonomousVehicle& autonomous_vehicle)
	{
		this->m_vehicle_state = NOT_SET;
		this->m_ptr_to_behind_vehicle = nullptr;
		this->m_vehicle_type = autonomous_vehicle.m_vehicle_type;
		this->m_throttle = autonomous_vehicle.m_throttle;
		this->m_break_pressure = autonomous_vehicle.m_break_pressure;
		return *this;
	}

	AutonomousVehicle::AutonomousVehicle(AutonomousVehicle&& autonomous_vehicle)
	{
		this->m_vehicle_state = autonomous_vehicle.m_vehicle_state;
		this->m_ptr_to_behind_vehicle = std::move(m_ptr_to_behind_vehicle);
		this->m_vehicle_type = autonomous_vehicle.m_vehicle_type;
		this->m_throttle = autonomous_vehicle.m_throttle;
		this->m_break_pressure = autonomous_vehicle.m_break_pressure;				
		autonomous_vehicle.m_vehicle_state = NOT_SET;
		autonomous_vehicle.m_vehicle_type = UNKNOWN;
		autonomous_vehicle.m_throttle = 0;
		autonomous_vehicle.m_break_pressure;
		m_ptr_to_behind_vehicle.reset();
	}

	void AutonomousVehicle::ApplyThrottle()
	{
		std::cout << "<VehicleType>: " << AutonomousVehicleApp::EnumToString(m_vehicle_type) << std::endl;
		std::cout << "applying throttle = " << m_throttle <<std::endl;
		m_vehicle_state = DRIVING;
		if(m_ptr_to_behind_vehicle)
		{					
			m_ptr_to_behind_vehicle->ApplyThrottle();
		}
					
	}

	void AutonomousVehicle::ApplyBrake()
	{
		std::cout << "<VehicleType>: " << AutonomousVehicleApp::EnumToString(m_vehicle_type) << std::endl;
		std::cout << "applying brake = " << m_break_pressure << std::endl;
		m_vehicle_state = STOPPED;
		if(m_ptr_to_behind_vehicle)
		{
			m_ptr_to_behind_vehicle->ApplyBrake();
		}		
	}

	VehicleType AutonomousVehicle::GetType()
	{
		return this->m_vehicle_type;
	}
	VehicleState AutonomousVehicle::GetState()
	{
		return this->m_vehicle_state;
	}
}

