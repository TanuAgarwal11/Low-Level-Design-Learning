#include <bits/stdc++.h>
using namespace std;

enum class TrafficLight
{
    RED,
    GREEN,
    YELLOW
};

int getDuration(TrafficLight light)
{
    switch (light)
    {
    case TrafficLight::RED:
        return 50;
    case TrafficLight::GREEN:
        return 25;
    case TrafficLight::YELLOW:
        return 10;
    }
    return 0;
}

TrafficLight next(TrafficLight light)
{
    switch (light)
    {
    case TrafficLight::RED:
        return TrafficLight::GREEN;
    case TrafficLight::GREEN:
        return TrafficLight::YELLOW;
    case TrafficLight::YELLOW:
        return TrafficLight::RED;
    }
    return TrafficLight::RED;
}

void display(TrafficLight light)
{
    string color;
    switch (light)
    {
    case TrafficLight::RED:
        color = "RED";
        break;
    case TrafficLight::GREEN:
        color = "GREEN";
        break;
    case TrafficLight::YELLOW:
        color = "YELLOW";
        break;
    }
    cout << "Light : " << color << " Duration : " << getDuration(light) << "seconds" << endl;
}

int main()
{
    TrafficLight light = TrafficLight::RED;
    for (int i = 0; i < 5; i++)
    {
        display(light);
        light = next(light);
    }

    return 0;
}