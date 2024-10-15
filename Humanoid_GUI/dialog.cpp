#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QStringList>
#include <QQmlContext>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , arduino(new QSerialPort(this))
{
    ui->setupUi(this);

    // Inisialisasi QQuickWidget
    QQuickWidget *quickWidget = ui->quickWidget3D;
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setSource(QUrl(QStringLiteral("qrc:/Main3D.qml"))); // Pastikan path benar dan diatur di resources.qrc

    if (quickWidget->status() == QQuickWidget::Error) {
        qDebug() << "Error loading QML:" << quickWidget->errors();
    }

    // Menyediakan pointer atau data ke QML
    quickWidget->rootContext()->setContextProperty("serialHandler", this);

    arduino_is_available = false;
    arduino_port_name = "";

    // Menampilkan jumlah port yang memiliki Vendor ID dan Product ID
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        QString portName = serialPortInfo.portName();
        QString description = serialPortInfo.description();

        qDebug() << "Port Name:" << portName;
        qDebug() << "Description:" << description;

        // **Filter: Hanya proses port yang memiliki Vendor ID dan Product ID**
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            quint16 vendorID = serialPortInfo.vendorIdentifier();
            quint16 productID = serialPortInfo.productIdentifier();

            qDebug() << "Vendor ID:" << vendorID;
            qDebug() << "Product ID:" << productID;

            // **Filter Berdasarkan Vendor ID dan Product ID**
            if(vendorID == arduino_uno_vendorID && productID == arduino_uno_productID){
                arduino_port_name = portName;
                arduino_is_available = true;
                qDebug() << "Arduino ditemukan di port:" << arduino_port_name;
                break; // Keluar dari loop setelah menemukan port yang sesuai
            }
        }
    }

    if(arduino_is_available){
        // Buka dan konfigurasi serial port
        arduino->setPortName(arduino_port_name);
        if(arduino->open(QSerialPort::WriteOnly)){
            qDebug() << "Arduino port berhasil dibuka.";
            arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            arduino->setFlowControl(QSerialPort::NoFlowControl);
        }
        else{
            qDebug() << "Gagal membuka Arduino port.";
            QMessageBox::warning(this, "Port Error", "Tidak bisa membuka Arduino port!");
        }
    }
    else{
        // Menampilkan pesan error jika tidak menemukan Arduino
        QMessageBox::warning(this, "Port Error", "Tidak bisa menemukan Arduino!");
    }

    // Inisialisasi ComboBox Ports (Jika ada)
    populateAvailablePorts();
}

Dialog::~Dialog(){
    if (arduino->isOpen()){
        qDebug() << "Menutup port";
        arduino->close();
    }
    delete ui;
}

void Dialog::on_berdiri_clicked()
{
    servoSetting = "A";
    ui->labelSetting->setText(servoSetting); // A
    updateGerakan(servoSetting);
}

void Dialog::on_lambaikan_clicked()
{
    servoSetting = "B";
    ui->labelSetting->setText(servoSetting);//B
    updateGerakan(servoSetting);
}

void Dialog::on_kuda2_clicked()
{
    servoSetting = "C";
    ui->labelSetting->setText(servoSetting);//C
    updateGerakan(servoSetting);
}

void Dialog::on_pukul_clicked()
{
    servoSetting = "D";
    ui->labelSetting->setText(servoSetting);//D
    updateGerakan(servoSetting);
}

void Dialog::on_senamTgn_clicked()
{
    servoSetting = "E";
    ui->labelSetting->setText(servoSetting);//E
    updateGerakan(servoSetting);
}

void Dialog::on_jalan_clicked()
{
    servoSetting = "F";
    ui->labelSetting->setText(servoSetting);//F
    updateGerakan(servoSetting);
}

void Dialog::on_jalanTempat_clicked()
{
    servoSetting = "G";
    ui->labelSetting->setText(servoSetting);//G
    updateGerakan(servoSetting);
}

void Dialog::on_bonus_clicked()
{
    servoSetting = "Gerakan Bonus";
    ui->labelSetting->setText(servoSetting);
    updateGerakan(servoSetting);
}

void Dialog::updateGerakan(QString command)
{
    if (arduino->isWritable()){
        QByteArray data = command.toUtf8();
        qint64 bytesWritten = arduino->write(data);
        if(bytesWritten == -1){
            qDebug() << "Gagal menulis ke serial port";
        }
        else if(bytesWritten != data.size()){
            qDebug() << "Gagal menulis semua data ke serial port";
        }
        else{
            qDebug() << "Data berhasil ditulis ke serial port:" << command;
        }
    }
    else{
        qDebug() << "Serial port tidak bisa ditulis";
    }
}

// Slot untuk QComboBox port selection, assuming you have a ComboBox
void Dialog::on_comboBox_ports_currentIndexChanged(const QString &portName)
{
    if(arduino->isOpen()){
        arduino->close();
    }

    arduino->setPortName(portName);
    if(arduino->open(QSerialPort::WriteOnly)){
        qDebug() << "Arduino port berhasil dibuka di:" << portName;
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }
    else{
        qDebug() << "Gagal membuka Arduino port di:" << portName;
        QMessageBox::warning(this, "Port Error", "Tidak bisa membuka Arduino port yang dipilih!");
    }
}

void Dialog::readSerialData()
{
    serialData.append(arduino->readAll());

    // Periksa apakah ada newline, yang menunjukkan akhir baris data
    while(serialData.contains('\n')){
        int newlineIndex = serialData.indexOf('\n');
        QByteArray line = serialData.left(newlineIndex);
        serialData.remove(0, newlineIndex + 1); // Hapus data yang telah dibaca

        QString dataStr = QString::fromUtf8(line).trimmed();
        qDebug() << "Data diterima:" << dataStr;

        // Parsing data CSV
        QStringList dataList = dataStr.split(',');

        if(dataList.size() == 6){
            bool ok;

            ax = dataList[0].toInt(&ok);
            if(!ok){ qDebug() << "Error parsing ax"; }
            ay = dataList[1].toInt(&ok);
            if(!ok){ qDebug() << "Error parsing ay"; }
            az = dataList[2].toInt(&ok);
            if(!ok){ qDebug() << "Error parsing az"; }
            gx = dataList[3].toInt(&ok);
            if(!ok){ qDebug() << "Error parsing gx"; }
            gy = dataList[4].toInt(&ok);
            if(!ok){ qDebug() << "Error parsing gy"; }
            gz = dataList[5].toInt(&ok);
            if(!ok){ qDebug() << "Error parsing gz"; }

            // Tampilkan data di UI atau proses sesuai kebutuhan
            QString mpuData = QString("AX: %1, AY: %2, AZ: %3\nGX: %4, GY: %5, GZ: %6")
                                  .arg(ax).arg(ay).arg(az)
                                  .arg(gx).arg(gy).arg(gz);
            ui->textEdit_mpuData->append(mpuData); // Pastikan Anda memiliki QTextEdit dengan objectName "textEdit_mpuData"

            // Kirim data ke QML
            sendDataToQML(QString::number(ax), QString::number(ay), QString::number(az)); // Sesuaikan jika perlu
        }
        else{
            qDebug() << "Format data tidak sesuai. Diharapkan 6 nilai, diterima:" << dataList.size();
        }
    }
}

// Emit dataUpdated signal
void Dialog::sendDataToQML(const QString &roll, const QString &pitch, const QString &yaw)
{
    emit dataUpdated(roll, pitch, yaw);
}

void Dialog::populateAvailablePorts()
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    ui->comboBox_ports->clear(); // Pastikan Anda memiliki QComboBox dengan objectName "comboBox_ports"

    foreach (const QSerialPortInfo &info, ports) {
        QString portInfo = info.portName();
        QString description = info.description();
        QString displayName = portInfo + " - " + description;
        ui->comboBox_ports->addItem(displayName, info.portName());
    }

    emit availablePortsChanged();
}
