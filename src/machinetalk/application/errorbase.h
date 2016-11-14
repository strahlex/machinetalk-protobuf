/****************************************************************************
**
** This code was generated by a code generator based on imatix/gsl
** Any changes in this code will be lost.
**
****************************************************************************/
#ifndef ERROR_BASE_H
#define ERROR_BASE_H
#include <QObject>
#include <QStateMachine>
#include <QQmlParserStatus>
#include <nzmqt/nzmqt.hpp>
#include <machinetalk/protobuf/message.pb.h>
#include <google/protobuf/text_format.h>
#include <application/errorsubscribe.h>

namespace application {

class ErrorBase : public QObject
,public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(bool ready READ ready WRITE setReady NOTIFY readyChanged)
    Q_PROPERTY(QString errorUri READ errorUri WRITE setErrorUri NOTIFY errorUriChanged)
    Q_PROPERTY(QString debugName READ debugName WRITE setDebugName NOTIFY debugNameChanged)
    Q_PROPERTY(State connectionState READ state NOTIFY stateChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)
    Q_PROPERTY(int errorHeartbeatInterval READ errorHeartbeatInterval WRITE setErrorHeartbeatInterval NOTIFY errorHeartbeatIntervalChanged)
    Q_ENUMS(State)

public:
    explicit ErrorBase(QObject *parent = 0);
    ~ErrorBase();

    enum State {
        Down = 0,
        Trying = 1,
        Up = 2,
    };

    void classBegin() {}
    /** componentComplete is executed when the QML component is fully loaded */
    void componentComplete()
    {
        m_componentCompleted = true;

        if (m_ready == true)    // the component was set to ready before it was completed
        {
            start();
        }
    }

    QString errorUri() const
    {
        return m_errorChannel->socketUri();
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

    int errorHeartbeatInterval() const
    {
        return m_errorChannel->heartbeatInterval();
    }

    bool ready() const
    {
        return m_ready;
    }

public slots:

    void setErrorUri(QString uri)
    {
        m_errorChannel->setSocketUri(uri);
    }

    void setDebugName(QString debugName)
    {
        if (m_debugName == debugName)
            return;

        m_debugName = debugName;
        emit debugNameChanged(debugName);
    }

    void setErrorHeartbeatInterval(int interval)
    {
        m_errorChannel->setHeartbeatInterval(interval);
    }

    void setReady(bool ready)
    {
        if (m_ready == ready)
            return;

        m_ready = ready;
        emit readyChanged(ready);

        if (m_componentCompleted == false)
        {
            return;
        }

        if (m_ready)
        {
            start();
        }
        else
        {
            stop();
        }
    }

    void addErrorTopic(const QString &name);
    void removeErrorTopic(const QString &name);
    void clearErrorTopics();

protected:
    void start(); // start trigger
    void stop(); // stop trigger

private:
    bool m_componentCompleted;
    bool m_ready;
    QString m_debugName;

    QSet<QString> m_errorTopics;    // the topics we are interested in
    application::ErrorSubscribe *m_errorChannel;

    State         m_state;
    State         m_previousState;
    QStateMachine *m_fsm;
    QString       m_errorString;
    // more efficient to reuse a protobuf Messages
    pb::Container m_errorRx;

private slots:

    void startErrorChannel();
    void stopErrorChannel();
    void errorChannelStateChanged(application::ErrorSubscribe::State state);
    void processErrorChannelMessage(const QByteArray &topic, const pb::Container &rx);

    void fsmDownEntered();
    void fsmDownConnectEvent();
    void fsmTryingEntered();
    void fsmTryingErrorUpEvent();
    void fsmTryingDisconnectEvent();
    void fsmUpEntered();
    void fsmUpErrorTryingEvent();
    void fsmUpDisconnectEvent();

    virtual void emcNmlErrorReceived(const QByteArray &topic, const pb::Container &rx) = 0;
    virtual void emcNmlTextReceived(const QByteArray &topic, const pb::Container &rx) = 0;
    virtual void emcNmlDisplayReceived(const QByteArray &topic, const pb::Container &rx) = 0;
    virtual void emcOperatorTextReceived(const QByteArray &topic, const pb::Container &rx) = 0;
    virtual void emcOperatorErrorReceived(const QByteArray &topic, const pb::Container &rx) = 0;
    virtual void emcOperatorDisplayReceived(const QByteArray &topic, const pb::Container &rx) = 0;
    virtual void updateTopics() = 0;
    virtual void setConnected() = 0;
    virtual void clearConnected() = 0;
    void startSlot(); // start trigger
    void stopSlot(); // stop trigger

signals:
    void errorUriChanged(QString uri);
    void errorMessageReceived(const QByteArray &topic, const pb::Container &rx);
    void debugNameChanged(QString debugName);
    void stateChanged(ErrorBase::State state);
    void errorStringChanged(QString errorString);
    void errorHeartbeatIntervalChanged(int interval);
    void readyChanged(bool ready);
    // fsm
    void fsmDownConnect();
    void fsmDownConnectQueued();
    void fsmTryingErrorUp();
    void fsmTryingErrorUpQueued();
    void fsmTryingDisconnect();
    void fsmTryingDisconnectQueued();
    void fsmUpErrorTrying();
    void fsmUpErrorTryingQueued();
    void fsmUpDisconnect();
    void fsmUpDisconnectQueued();
    // trigger signals
    void startSignal(QPrivateSignal dummy);
    void stopSignal(QPrivateSignal dummy);
};
}; // namespace application
#endif //ERROR_BASE_H
