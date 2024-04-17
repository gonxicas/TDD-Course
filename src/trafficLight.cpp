#include "trafficLight.h"
#include <stdexcept>

TrafficLight::TrafficLight() : state(Green), mode(On)
{
}

TrafficLight::TrafficLight(const TrafficLightState state) : state(state), mode(On)
{
}

void TrafficLight::Next()
{
    if(mode != On)
        throw std::domain_error("Cannot change light while it is not in mode On");
    
    state = static_cast<TrafficLightState>((state + 1) % TrafficLightState::States);
}

void TrafficLight::SetEmergencyMode()
{
    mode = EmergencyMode;
}

TrafficLightState TrafficLight::GetState() const
{
    return mode == EmergencyMode ? Yellow : state;
}

TrafficLightMode TrafficLight::GetMode() const
{
    return mode;
}

void TrafficLight::ExitEmergencyMode()
{
    mode = On;
}
