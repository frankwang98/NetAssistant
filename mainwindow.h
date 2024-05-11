#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QDataStream>
#include <QTextStream>
#include  "TcpServer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /**
     * @brief set udp mode
     */
    void setUdpGuiExt();

    /**
     * @brief set tcp server mode
     */
    void setTcpSvrGuiExt();

    /**
     * @brief set tcp client mode
     */
    void setTcpClientGuiExt();

    QList<int> tcpClientSocketDescriptorList;
    int TcpClientLinkCnt;

signals:
    void sendDataToClient(char *msg, int length, int socketDescriptor, int socketDescriptorEx);

private slots:
    /**
     * @brief language changed
     */
    void on_actionEnglish_triggered();

    /**
     * @brief btn for connect net
     * @param checked 
     */
    void on_pBtnNetCnnt_clicked(bool checked);

    /**
     * @brief index of net type changed
     * @param index 
     */
    void on_cBoxNetType_currentIndexChanged(int index);

    /**
     * @brief btn for send data
     */
    void on_pBtnSendData_clicked();

    /**
     * @brief clear data show
     */
    void on_pBtnClearRcvDisp_clicked();

    /**
     * @brief modify udp port
     * @param text 
     */
    void on_lEditUdpPort_textChanged(QString text);

    /**
     * @brief modify udp ip
     * @param text 
     */
    void on_lEditUdpIP_textChanged(QString text);

    /**
     * @brief reset udp count
     */
    void on_pBtnResetCnt_clicked();
    
    char ConvertHexChar(char ch);
    char ConvertHexStr(QString hexSubStr);

    //=======UDP========
    void udpDataReceived();

    //=====TCP Client=====
    void tcpClientDataReceived();

    //=====TCP Server=====
    bool slotTryCreateTcpServer();
    void slotDeleteTcpServer();
    void tcpServerDataReceived(char* msg, int length, int socketDescriptorEx);

    void addClientLink(QString clientAddrPort, int socketDescriptor);
    void removeClientLink(QString clientAddrPort, int socketDescriptor);
    void toSendData();
    void toSendFile();
    void insertDateTimeInRcvDisp();

    void msDelay(unsigned int msec);

    void on_pBtnSaveRcvData_clicked();
    void on_cBoxLoopSnd_toggled(bool checked);
    void on_lEdit_Interval_ms_editingFinished();

    void on_pBtnClearSndDisp_clicked();

    void on_pBtnLoadSndData_clicked();

    void on_StartRcvFile_clicked(bool checked);

    void on_cBoxStartSndFile_clicked(bool checked);

    void on_cBox_SndHexDisp_clicked(bool checked);


    void on_actionChinese_triggered();

private:
    Ui::MainWindow *ui;

    QString m_ip;
    //-----UDP-----
    QUdpSocket *udpSocket;
    QHostAddress lhAddr;
    int lhPort;
    QHostAddress rmtAddr;
    int rmtPort;

    //-----TCP Client-----
    QHostAddress *rmtServerIP;
    QTcpSocket *tcpClientSocket;
    TcpServer *mtcpServer;

    //Global state
    unsigned int rcvDataCnt;
    unsigned int sndDataCnt;
    //bool NetState;
    QTimer *timer;
    bool loopSending;

    QString CurIPPort;

    QString CurPath;
    QFile *curFile;

    QTranslator translator;
};

#endif // MAINWINDOW_H
