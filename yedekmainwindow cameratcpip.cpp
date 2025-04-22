#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <gst/gst.h>
#include <gst/app/gstappsink.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
/*#pragma pack(push, 1)
struct SensorPacket
{
    double latitude;
    double longitude;
    double altitude;

    float accX;
    float accY;
    float accZ;

    uint16_t crc;
};

#pragma pack(pop)
*/
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    GstElement *pipelineServer = nullptr;
    GstElement *appsinkServer = nullptr;

    void startServer();
    void updateFrame(const QImage &image);
    void startSerialReader();
    void updateGpsAndAccelerationDisplay(double latitude, double longitude, double altitude,float accX, float accY, float accZ);
    static GstFlowReturn new_sample_server(GstAppSink *sink, gpointer data);
};

#endif // MAINWINDOW_H
