#ifndef TRAFFICLIGHTTIMER_H
#define TRAFFICLIGHTTIMER_H
#include <chrono>
#include "trafficLight.h"

class TrafficLightTimer
{
public:
    TrafficLightTimer();
    explicit TrafficLightTimer(std::chrono::milliseconds blinkCooldown);

    [[nodiscard]] bool GetIsOn() const;
    void InjectTime(std::chrono::milliseconds milliseconds);
    void SetEmergencyMode() const;
    [[nodiscard]]bool GetEmergencyMode() const;
    [[nodiscard]]TrafficLightState GetState() const;

private:
    mutable bool isOn;
    std::chrono::milliseconds time;
    std::chrono::milliseconds blinkCooldown;
    std::unique_ptr<TrafficLight> model;
};


#endif
