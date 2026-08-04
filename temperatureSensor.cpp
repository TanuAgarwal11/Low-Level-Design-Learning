#include <bits/stdc++.h>
using namespace std;

class TemperatureSensor
{
private:
    vector<double> readings;

public:
    void addReading(double value)
    {
        if (value >= -50 && value <= 150)
        {
            readings.push_back(value);
        }
        else
        {
            cout << "Invalid Reading" << endl;
        }
    }

    double getAverage()
    {
        if (readings.size() != 0)
        {
            double sum = 0;
            for (double x : readings)
            {
                sum += x;
            }
            return sum / readings.size();
        }
        return 0.0;
    }

    int getReadingCount()
    {
        return readings.size();
    }

    vector<double> getReadings()
    {
        vector<double> readingList;
        for (double x : readings)
        {
            readingList.push_back(x);
        }
        sort(readingList.begin(), readingList.end());
        return readingList;
    }
};

int main()
{
    TemperatureSensor sensor;
    sensor.addReading(22.5);
    sensor.addReading(23.1);
    sensor.addReading(200.0); // Should be rejected
    sensor.addReading(-10.0);

    cout << "Count: " << sensor.getReadingCount() << endl;
    cout << "Average: " << sensor.getAverage() << endl;
    vector<double> list = sensor.getReadings();
    for (double x : list)
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}