/****************************************************************************
**
** This code was generated by a code generator based on imatix/gsl
** Any changes in this code will be lost.
**
****************************************************************************/
#ifndef ERROR_SUBSCRIBE_H
#define ERROR_SUBSCRIBE_H
#include <QObject>
#include <QStateMachine>
#include <nzmqt/nzmqt.hpp>
#include <machinetalk/protobuf/message.pb.h>
#include <google/protobuf/text_format.h>

namespace application {

class ErrorSubscribe : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool ready READ ready WRITE setReady NOTIFY readyChanged)
    Q_PROPERTY(QString socketUri READ socketUri WRITE setSocketUri NOTIFY socketUriChanged)
    Q_PROPERTY(QString debugName READ debugName WRITE setDebugName NOTIFY debugNameChanged)
    Q_PROPERTY(State connectionState READ state NOTIFY stateChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)
    Q_PROPERTY(int heartbeatInterval READ heartbeatInterval WRITE setHeartbeatInterval NOTIFY heartbeatIntervalChanged)
    Q_ENUMS(State)

public:
    explicit ErrorSubscribe(QObject *parent = 0);
    ~ErrorSubscribe();

    enum State {
        Down = 0,
        Trying = 1,
        Up = 2,
    };

    QString socketUri() const
    {
        return m_socketUri;
    }

    QString debugName() const
    {
        return m_debugName;
    }

    State state() const
    {
        return m_state;
    }

    QString errorString() const
    {
        return m_errorString;
    }

    int heartbeatInterval() const
    {
        return m_heartbeatInterval;
    }

    bool ready() const
    {
        return m_ready;
    }

public slots:

    void setSocketUri(QString uri)
    {
        if (m_socketUri == uri)
            return;

        m_socketUri = uri;
        emit socketUriChanged(uri);
    }

    void setDebugName(QString debugName)
    {
        if (m_debugName == debugName)
            return;

        m_debugName = debugName;
        emit debugNameChanged(debugName);
    }

    void setHeartbeatInterval(int interval)
    {
        if (m_heartbeatInterval == interval)
            return;

        m_heartbeatInterval = interval;
        emit heartbeatIntervalChanged(interval);
    }

    void setReady(bool ready)
    {
        if (m_ready == ready)
            return;

        m_ready = ready;
        emit readyChanged(ready);

        if (m_ready)
        {
            start();
        }
        else
        {
            stop();
        }
    }

    void addSocketTopic(const QString &name);
    void removeSocketTopic(const QString &name);
    void clearSocketTopics();

protected:
    void start(); // start trigger
    void stop(); // stop trigger

private:
    bool m_ready;
    QString m_debugName;

    QSet<QString> m_socketTopics;   // the topics we are interested in
    QString m_socketUri;
    nzmqt::PollingZMQContext *m_context;
    nzmqt::ZMQSocket *m_socket;

    State         m_state;
    State         m_previousState;
    QStateMachine *m_fsm;
    QString       m_errorString;

    QTimer     *m_heartbeatTimer;
    int         m_heartbeatInterval;
    int         m_heartbeatLiveness;
    int         m_heartbeatResetLiveness;
    // more efficient to reuse a protobuf Messages
    pb::Container m_socketRx;

private slots:

    void heartbeatTimerTick();
    void resetHeartbeatLiveness();
    void resetHeartbeatTimer();
    void startHeartbeatTimer();
    void stopHeartbeatTimer();

    bool startSocket();
    void stopSocket();

    void processSocketMessage(const QList<QByteArray> &messageList);
    void socketError(int errorNum, const QString& errorMsg);


    void fsmDownEntered();
    void fsmDownConnectEvent();
    void fsmTryingEntered();
    void fsmTryingConnectedEvent();
    void fsmTryingDisconnectEvent();
    void fsmUpEntered();
    void fsmUpTimeoutEvent();
    void fsmUpTickEvent();
    void fsmUpMessageReceivedEvent();
    void fsmUpDisconnectEvent();

    void startSlot(); // start trigger
    void stopSlot(); // stop trigger

signals:
    void socketUriChanged(QString uri);
    void socketMessageReceived(const QByteArray &topic, const pb::Container &rx);
    void debugNameChanged(QString debugName);
    void stateChanged(ErrorSubscribe::State state);
    void errorStringChanged(QString errorString);
    void heartbeatIntervalChanged(int interval);
    void readyChanged(bool ready);
    // fsm
    void fsmDownConnect();
    void fsmDownConnectQueued();
    void fsmTryingConnected();
    void fsmTryingConnectedQueued();
    void fsmTryingDisconnect();
    void fsmTryingDisconnectQueued();
    void fsmUpTimeout();
    void fsmUpTimeoutQueued();
    void fsmUpTick();
    void fsmUpTickQueued();
    void fsmUpMessageReceived();
    void fsmUpMessageReceivedQueued();
    void fsmUpDisconnect();
    void fsmUpDisconnectQueued();
    // trigger signals
    void startSignal(QPrivateSignal dummy);
    void stopSignal(QPrivateSignal dummy);
};
}; // namespace application
#endif //ERROR_SUBSCRIBE_H
