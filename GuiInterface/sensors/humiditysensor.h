#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include <QObject>
#include <QTimer>
#include <QDateTime>

class HumiditySensor : public QObject
{
    Q_OBJECT
public:
    explicit HumiditySensor(QObject *parent = nullptr);

private:
    uint64_t m_humidityVal;
    QTimer m_time;

signals:
    void setHumidityValue(const uint64_t humVal);

};

#endif // HUMIDITYSENSOR_H
