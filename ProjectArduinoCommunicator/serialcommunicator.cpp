#include "serialcommunicator.h"

#include <QDebug>

SerialCommunicator::SerialCommunicator(QObject *parent)
    : QObject{parent}
{
    serialPort = new QSerialPort(this);
}

void SerialCommunicator::configurePort(QString portName)
{
    serialPort->setPortName(portName);
    serialPort->setBaudRate(9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
}

void SerialCommunicator::tryConnection(QString portName)
{
    configurePort(portName);

    if(serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "port is open";
    }
    else
    {
        qDebug() << "port couldnt be opened";
    }
}

void SerialCommunicator::sendMsg(QString dataString)
{
   QByteArray data = QByteArray(dataString.toStdString().c_str());
   serialPort->write(data);
}
