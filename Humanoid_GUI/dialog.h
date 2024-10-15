#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QQuickWidget> // Header yang benar untuk QQuickWidget
#include <QtCore>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void dataUpdated(const QString &roll, const QString &pitch, const QString &yaw);
        void availablePortsChanged(); // Tambahkan sinyal ini
public slots:
    void updateGerakan(QString command);
    void on_berdiri_clicked();
    void on_lambaikan_clicked();
    void on_kuda2_clicked();
    void on_pukul_clicked();
    void on_senamTgn_clicked();
    void on_jalan_clicked();
    void on_jalanTempat_clicked();
    void on_bonus_clicked();
    // Jika Anda menggunakan QComboBox untuk memilih port
    void on_comboBox_ports_currentIndexChanged(const QString &portName);
    void readSerialData();

private:
    Ui::Dialog *ui;
    QString servoSetting;
    QSerialPort *arduino;
    QByteArray serialData;
    static const quint16 arduino_uno_vendorID = 65521; // 0xfff1
    static const quint16 arduino_uno_productID = 65352;  // 0xff48
    QString arduino_port_name;
    bool arduino_is_available;

    // Variabel untuk menyimpan data MPU6050
    int16_t ax, ay, az;
    int16_t gx, gy, gz;

    void sendDataToQML(const QString &roll, const QString &pitch, const QString &yaw);
    void populateAvailablePorts();
};

#endif // DIALOG_H
