#include "widget.h"
#include "ui_widget.h"
#include <QVector>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "stdio.h"
#include "stdlib.h"
#include "cstring"
#include "QProgressBar"
#include "math.h"
#define Start 0x06
#define Stop 0x07
#define Resistencia 680000

double RPMMin=0,RPMMax=0,Flag=0,RPm=0,CurrentAct=0;
double siz=0;
float Voltage=0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    ttl = new QSerialPort(this);
    serialBuffer = "";
    parsed_data = "";

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        QString pname = serialPortInfo.portName();
        ui->comboBox->addItem(pname);
    }
}

Widget::~Widget()
{
   if(ttl->isOpen()){
       ttl->close();
       QObject::disconnect(ttl, SIGNAL(readyRead()), this, SLOT(readSerial()));
   }

    delete ui;
}

void Widget::Send(int cmd,uint16_t Info,uint8_t Tam){
    //Protocolo
    uint8_t Count,Parity=0;;
    QByteArray data;
    data.clear();
    data.append(Start);
    data.append(Tam);
    data.append(cmd);
    //if(Info2==0){
    if(Tam<2){
        data.append(Info);
    }
    else {
        data.append(0x00FF & (Info >> 8));
        data.append(0x00FF & Info);
    }
    for(Count=0;Count<data.length();Count++){
        Parity^=data.at(Count);
    }

    data.append(Parity);
    data.append(Stop);
    ttl->write(data,data.length());
}
void Widget::readSerial()
{
    uint8_t Size,Aux,Parity=0,Check,Temp1,Temp2=0;
    double Data;
    QByteArray buffer ;
    serialData.clear();
    buffer.clear();
    buffer= ttl->readAll();
    serialData.append(buffer);
    ui->label_12->setText("Recibiendo datos");
    if(serialData.at(0)==Start && serialData.at(serialData.at(1)+4)==Stop){
        Size=serialData.at(1);
        for(Aux=3;Aux<=Size+3;Aux++){
            if(serialData.at(Aux)<0){
                serialData[Aux]=serialData.at(Aux)+256;
            }
        }
        //9653
        if(Size==1){
            Temp1=(serialData.at(3));
            Data=Temp1;
        }
        else{
            Temp1=serialData.at(3);
            Temp2=serialData.at(4);
            Data=(Temp1 << 8 | Temp2);
        }

        for(Aux =0;Aux<Size+3;Aux++){
            Parity^=serialData.at(Aux);
        }
        Check=serialData.at(Size+3);
        if(Parity==Check || Parity==Check+256){
            processSerial(Data,serialData.at(2));
            serialData.clear();
        }
        else{

            serialData.clear();
        }
    }
}

void Widget::processSerial(double data,int cmd){
    QString Datos,Aux;
    Datos=QString::number(data);
    float Info,Data;
    if(cmd==1){     //Se recibe vadc
        Data=data;
        Info=Data*33/4096;
        Voltage=Info/10;
        Info=Voltage*10;
        Datos.setNum(Voltage);
        ui->label_13->setText("Voltaje Actual: "+Datos+" V");
        ui->Porcentual->setValue(Info*10);
        Datos.setNum(Info*10/3.3);
        ui->label_14->setText("Porcentaje de Carga: "+Datos+" %");

    }
    else if(cmd==4){
        Data=data;
        Info=Data/1000;
        Datos.setNum(Info);
       ui->label_15->setText("Tiempo Tao: "+Datos+"s");
       Info/=Resistencia;
       if(Info>1){
           Aux="F";
       }
       else if(Info>0.001){
           Aux="mF";
           Info*=1000;
       }
       else if(Info>0.000001){
           Aux="uF";
           Info*=1000000;
       }
       else if(Info>0.000000001){
           Aux="nF";
           Info*=1000000000;
       }
       Datos.setNum(Info);

       ui->label_17->setText("Capacitancia: "+Datos+Aux);
       Data=data;
       Info=5*Data/1000;
       Datos.setNum(Info);
       ui->label_16->setText("Tiempo de descarga:"+Datos+"s");
    }
}

void Widget::on_pushButton_2_clicked()
{
    QString ttl_port_name = ui->comboBox->currentText();
    if(ui->pushButton_2->text() == "Abrir"){
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            if(ttl_port_name==serialPortInfo.portName()){
                ttl->setPortName(ttl_port_name);
                ttl->open(QSerialPort::ReadWrite);
                ttl->setBaudRate(QSerialPort::Baud115200);
                ttl->setDataBits(QSerialPort::Data8);
                ttl->setFlowControl(QSerialPort::NoFlowControl);
                ttl->setParity(QSerialPort::NoParity);
                ttl->setStopBits(QSerialPort::OneStop);
                QObject::connect(ttl, SIGNAL(readyRead()), this, SLOT(readSerial()));
                Send(1,5,1);
                ui->label_12->setText("Conectado");
                ui->pushButton_2->setText("Cerrar");

            }
            else{
                ui->label_12->setText("Puerto no disponible");
            }
        }
    }else{
        Send(0,2,1); //Le cierra la Flag a la stm para enviar datos
        ttl->close();
        QObject::disconnect(ttl, SIGNAL(readyRead()), this, SLOT(readSerial()));
        ui->pushButton_2->setText("Abrir");
        ui->label_12->setText("Desconectado");
    }

}

void Widget::on_pushButton_3_clicked()
{
    ui->comboBox->clear();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        QString pname = serialPortInfo.portName();
        ui->comboBox->addItem(pname);
    }
}

void Widget::on_pushButton_4_clicked() //Carga
{    
    if(Voltage>0.09){ //Más del 2.7% de carga entonces lo descargará
        Send(4,1,1);
    }
    else{
        Send(2,1,1);
    }
}


void Widget::on_pushButton_5_clicked() //Descarga
{
    if(Voltage<3.21){ //Más del 97% de carga
        Send(5,1,1);
    }
    else{
        Send(3,1,1);
    }
}

