#include "TrafficLightTimer.h"

#include <thread>

#include "trafficLight.h"

TrafficLightTimer::TrafficLightTimer() : isOn(true), time(0), blinkCooldown(1000)
{
    model = std::make_unique<TrafficLight>();
}

TrafficLightTimer::TrafficLightTimer(const std::chrono::milliseconds blinkCooldown) : isOn(true),
    time(0), blinkCooldown(blinkCooldown)
{
    model = std::make_unique<TrafficLight>();
}

bool TrafficLightTimer::GetIsOn() const
{
    return isOn;
}

void TrafficLightTimer::InjectTime(std::chrono::milliseconds milliseconds)
{
    time += milliseconds;

    if(time <= blinkCooldown)
        return;
    time -= blinkCooldown;
    
    if(GetEmergencyMode())
        isOn = !isOn;
    else
        model->Next();
}
void TrafficLightTimer::SetEmergencyMode() const
{
    model->SetEmergencyMode();
}

bool TrafficLightTimer::GetEmergencyMode() const
{
    return model->GetMode() == EmergencyMode;
}

TrafficLightState TrafficLightTimer::GetState() const
{
    return model->GetState();
}
