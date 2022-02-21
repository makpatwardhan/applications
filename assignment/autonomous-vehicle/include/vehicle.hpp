#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_
#include <string>

namespace AutonomousVehicleApp
{
	typedef enum
	{
		DRIVING,
		STOPPED,
		NOT_SET
	}VehicleState;
	
	typedef enum
	{
		SEDAN, 
		SMALL_TRUCK, 
		LARGE_TRUCK, 
		UNKNOWN
	}VehicleType;
	
	static std::string EnumToString(const VehicleType vehicle_type)
	{

		switch(vehicle_type)
		{
			case SEDAN:return "SEDAN";
			case SMALL_TRUCK: return "SMALL_TRUCK";
			case LARGE_TRUCK: return "LARGE_TRUCK";
			case UNKNOWN:
			default: return "UNKNOWN";			
		}
	}
	
	static std::string EnumToString(const VehicleState vehicle_type)
	{

		switch(vehicle_type)
		{
			case DRIVING:return "DRIVING";
			case STOPPED: return "STOPPED";
			case NOT_SET:
			default: return "NOT_SET";			
		}
	}
	
	
	class Vehicle
	{
		public:		
		virtual void ApplyThrottle() = 0;
		virtual void ApplyBrake() = 0;
		virtual VehicleType GetType() = 0;
		virtual VehicleState GetState() = 0;
		virtual ~Vehicle(){}
	};
}
#endif //_VEHICLE_HPP
