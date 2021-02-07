#include "userwindow.h"

UserWindow::UserWindow(QWidget *parent)
    : QWidget(parent)
{
    m_mainLayout = new QGridLayout;
    m_tempSensor = new TempSensor;
    m_humiditySensor = new HumiditySensor;
    m_windSensor = new WindSensor;

    setTempLayout();
    setHumidityLayout();
    setWindLayout();
    setVideoLayout();

    m_mainLayout->addWidget(m_tempGroup, 0, 0);
    m_mainLayout->addWidget(m_humidityGroup, 0, 1);
    m_mainLayout->addWidget(m_windGroup, 1, 0);
    m_mainLayout->addWidget(m_videoGroup, 1, 1);

    //set the app bacground
    setBackColor();

    setLayout(m_mainLayout);

    connect(m_tempSensor, &TempSensor::setTemperature, this,
            &UserWindow::updateTempValue);

    connect(m_humiditySensor, &HumiditySensor::setHumidityValue, this,
            &UserWindow::updateHumidityValue);

    connect(m_windSensor, &WindSensor::setWindValue, this,
            &UserWindow::updateWindValue);

}

UserWindow::~UserWindow()
{
}

void UserWindow::setTempLayout()
{
    m_tempGroup = new QGroupBox("TEMPERATURE");
    m_tempGroup->setStyleSheet("color: white");

    QHBoxLayout *tempWidgetLayout = new QHBoxLayout;
    QLabel *labelTemp = new QLabel;
    QLabel *labelCel = new QLabel;
    m_tempDigitNumber = new QLCDNumber;

    QPixmap myPix(":/img/Weather_clouds_icon.png");
    labelTemp->setPixmap(myPix);

    labelCel->setFrameShape(QFrame::NoFrame);
    labelCel->setText("°CELSIUS");

    m_tempDigitNumber->setFrameStyle(QFrame::NoFrame);
    m_tempDigitNumber->setMinimumSize(200, 200);    

    tempWidgetLayout->addWidget(labelTemp);
    tempWidgetLayout->addWidget(m_tempDigitNumber);
    tempWidgetLayout->addWidget(labelCel);

    m_tempGroup->setLayout(tempWidgetLayout);
}

void UserWindow::setHumidityLayout()
{
    m_humidityGroup = new QGroupBox("HUMIDITY");
    m_humidityGroup->setStyleSheet("color: white");

    QHBoxLayout *humidLayout = new QHBoxLayout;
    QLabel *labelHymidity = new QLabel;
    QLabel *labelDjgHum = new QLabel;
    m_humidityDigital = new QLCDNumber;

    QPixmap myPix(":/img/Storm_icon.png");
    labelHymidity->setPixmap(myPix);

    labelDjgHum->setFrameShape(QFrame::NoFrame);
    labelDjgHum->setText("HUMIDITY AIR");

    m_humidityDigital->setFrameStyle(QFrame::NoFrame);
    m_humidityDigital->setMinimumSize(200, 200);
    m_humidityDigital->display("89");

    humidLayout->addWidget(labelHymidity);
    humidLayout->addWidget(m_humidityDigital);
    humidLayout->addWidget(labelDjgHum);

    m_humidityGroup->setLayout(humidLayout);
}

void UserWindow::setWindLayout()
{
    m_windGroup = new QGroupBox("WIND");
    m_windGroup->setStyleSheet("color: white");

    QHBoxLayout *windLayout = new QHBoxLayout;
    QLabel *windLabel = new QLabel;
    QLabel *label = new QLabel;
    m_windDigital = new QLCDNumber;

    QPixmap myPix(":/img/WindFlagStorm");
    windLabel->setPixmap(myPix);

    label->setFrameShape(QFrame::NoFrame);
    label->setText("M/S");

    m_windDigital->setFrameStyle(QFrame::NoFrame);
    m_windDigital->setMinimumSize(200, 200);
    //m_windDigital->display("13");

    windLayout->addWidget(windLabel);
    windLayout->addWidget(m_windDigital);
    windLayout->addWidget(label);

    m_windGroup->setLayout(windLayout);

}

void UserWindow::setVideoLayout()
{
    m_videoGroup = new QGroupBox("REALTIME VIDEO");
    m_videoGroup->setStyleSheet("color: white");

    QLabel *labelVideo = new QLabel;
    QHBoxLayout *videoLayout = new QHBoxLayout;

    labelVideo->setFrameShape(QFrame::NoFrame);
    labelVideo->setStyleSheet("background-color: black");

    videoLayout->addWidget(labelVideo);

    m_videoGroup->setLayout(videoLayout);

}

void UserWindow::setBackColor()
{
    QPalette dark;

    dark.setColor(QPalette::Window, QColor(53, 53, 53));
    //dark.setColor(QPalette::Text, Qt::gray);
    setPalette(dark);
}

void UserWindow::updateTempValue(const double tempVal)
{
    //qDebug() << tempVal;
    m_tempDigitNumber->display(tempVal);

}

void UserWindow::updateHumidityValue(const uint64_t humVal)
{
    int hum = humVal;
    m_humidityDigital->display(hum);
}

void UserWindow::updateWindValue(const uint64_t windVal)
{
    int wind = windVal;
    m_windDigital->display(wind);
}

