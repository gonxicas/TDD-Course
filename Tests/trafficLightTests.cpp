#include "../src/trafficLight.h"
#include "../src/TrafficLightTimer.h"
#include "gtest/gtest.h"

TEST(TrafficLightSuite, Change_Color_Follow_Sequence)
{
    auto sut = TrafficLight(Yellow);
    
    sut.Next();
    ASSERT_EQ(sut.GetState(), TrafficLightState::Red);
    sut.Next();
    ASSERT_EQ(sut.GetState(), TrafficLightState::Green);
    sut.Next();
    ASSERT_EQ(sut.GetState(), TrafficLightState::Yellow);
    sut.Next();
    ASSERT_EQ(sut.GetState(), TrafficLightState::Red);
}

TEST(TrafficLightSuite, Emmergency_Mode_Is_Yellow)
{
    auto sut = TrafficLight();

    sut.SetEmergencyMode();

    ASSERT_EQ(sut.GetMode(), TrafficLightMode::EmergencyMode);
    ASSERT_EQ(sut.GetState(), TrafficLightState::Yellow);
    
}

TEST(TrafficLightSuite, After_Emmergency_Mode_Returns_To_Previous_Color)
{
    auto sut = TrafficLight(Red);
    
    sut.SetEmergencyMode();
    sut.ExitEmergencyMode();
    
    ASSERT_EQ(sut.GetMode(), TrafficLightMode::On);
    ASSERT_EQ(sut.GetState(), TrafficLightState::Red);
}

TEST(TrafficLightSuite, If_Is_In_EmergencyMode_Throw_Precondition)
{
    auto sut = TrafficLight();

    sut.SetEmergencyMode();

    EXPECT_THROW(sut.Next(), std::domain_error);
}

TEST(TrafficLightSuite, When_EmergencyMode_After_N_Time_Is_Blinks)
{
    auto timer = TrafficLightTimer(std::chrono::milliseconds(5));
    ASSERT_EQ(timer.GetIsOn(), true);
    timer.SetEmergencyMode();
    timer.InjectTime(std::chrono::milliseconds(7));
    ASSERT_EQ(timer.GetIsOn(), false);
    timer.InjectTime(std::chrono::milliseconds(7));
    ASSERT_EQ(timer.GetIsOn(), true);
}

TEST(TrafficLightSuite, After_N_Time_State_Changes)
{
    auto timer = TrafficLightTimer(std::chrono::milliseconds(5));
    ASSERT_EQ(timer.GetState(), TrafficLightState::Green);
    timer.InjectTime(std::chrono::milliseconds(7));
    ASSERT_EQ(timer.GetState(), TrafficLightState::Yellow);
    timer.InjectTime(std::chrono::milliseconds(7));
    ASSERT_EQ(timer.GetState(), TrafficLightState::Red);
}


