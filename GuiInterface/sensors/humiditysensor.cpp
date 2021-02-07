#include "humiditysensor.h"

HumiditySensor::HumiditySensor(QObject *parent) : QObject(parent)
{
    //setting the initial value received from the sensor
    m_humidityVal = 90;

    //setting the data update interval
    m_time.setInterval(5000);

    //make the timer is triggered once
    m_time.setSingleShot(false);


    //the timeout signal is processed in a lambda function
    //that generates new data and outputs a signal with a new value
    connect(&m_time, &QTimer::timeout, this, [this](){

        QDateTime timeNow = QDateTime::currentDateTime();

        uint64_t changeVal = static_cast<uint64_t>(timeNow.time().second() % 8-3);

        m_humidityVal += changeVal;

        emit setHumidityValue(m_humidityVal);

    });

    m_time.start();

}
