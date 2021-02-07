#include "windsensor.h"

WindSensor::WindSensor(QObject *parent) : QObject(parent)
{
    m_windValue = 8;
    m_time.setInterval(6000);
    m_time.setSingleShot(false);

    connect(&m_time, &QTimer::timeout, this, [this](){

        QDateTime timeNow = QDateTime::currentDateTime();

        uint64_t changeValue = static_cast<uint64_t>(timeNow.time().second() % 3+1);

        m_windValue += changeValue;

        emit setWindValue(m_windValue);

    });

    m_time.start();

}
