#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , serialCommunicator(new SerialCommunicator)
    , serialThread (new QThread)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialCommunicator->moveToThread(serialThread);

    setBindings();

    serialThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBindings()
{
    connect(ui->pushButtonSend, &QPushButton::released, this, &MainWindow::sendButtonClicked);
    connect(this, &MainWindow::sendMsg, serialCommunicator, &SerialCommunicator::sendMsg);

    connect(ui->pushButtonScan, &QPushButton::released, this, &MainWindow::scanButtonClicked);

    connect(ui->pushButtonConnect, &QPushButton::released, this, &MainWindow::connectButtonClicked);
    connect(this, &MainWindow::tryConnection, serialCommunicator, &SerialCommunicator::tryConnection);

    connect(ui->pushButtonTest_1, &QPushButton::released, this, &MainWindow::test1ButtonClicked);
    connect(ui->pushButtonTest_2, &QPushButton::released, this, &MainWindow::test2ButtonClicked);
}

void MainWindow::sendButtonClicked()
{
    ui->textEditConversation->append("PC: " + ui->lineEditMsg->text());

    emit sendMsg(ui->lineEditMsg->text());
    qDebug() << "after emitting";
    ui->lineEditMsg->clear();
}

void MainWindow::scanButtonClicked()
{
    ui->comboBoxPorts->clear();
    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
            qDebug() << port.portName();
            ui->comboBoxPorts->addItem(port.portName());
    }
}

void MainWindow::connectButtonClicked()
{
    emit tryConnection(ui->comboBoxPorts->currentText());
}

void MainWindow::test1ButtonClicked()
{
    emit sendMsg(QString::number(2));
}

void MainWindow::test2ButtonClicked()
{
    emit sendMsg(QString::number(3));
}
