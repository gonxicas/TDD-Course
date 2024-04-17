#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H


enum TrafficLightState
{
    Red,
    Green,
    Yellow,
    States
};

enum TrafficLightMode
{
    Off,
    On,
    EmergencyMode
};

class TrafficLight
{
public:
    TrafficLight();
    explicit TrafficLight(TrafficLightState state);

    void Next();
    void SetEmergencyMode();
    [[nodiscard]] TrafficLightState GetState() const;
    [[nodiscard]] TrafficLightMode GetMode() const;
    void ExitEmergencyMode();

private:
    TrafficLightState state;
    TrafficLightMode mode;
};


#endif
