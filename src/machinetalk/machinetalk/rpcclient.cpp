/****************************************************************************
**
** This code was generated by a code generator based on imatix/gsl
** Any changes in this code will be lost.
**
****************************************************************************/
#include "rpcclient.h"
#include "debughelper.h"

#if defined(Q_OS_IOS)
namespace gpb = google_public::protobuf;
#else
namespace gpb = google::protobuf;
#endif

using namespace nzmqt;

namespace machinetalk {

/** Generic RPC Client implementation */
RpcClient::RpcClient(QObject *parent) :
    QObject(parent),
    m_ready(false),
    m_debugName("RPC Client"),
    m_socketUri(""),
    m_context(nullptr),
    m_socket(nullptr),
    m_state(Down),
    m_previousState(Down),
    m_fsm(nullptr),
    m_errorString("")
    ,m_heartbeatTimer(new QTimer(this)),
    m_heartbeatInterval(2500),
    m_heartbeatLiveness(0),
    m_heartbeatResetLiveness(2)
{

    m_heartbeatTimer->setSingleShot(true);
    connect(m_heartbeatTimer, &QTimer::timeout, this, &RpcClient::heartbeatTimerTick);

    m_fsm = new QStateMachine(this);
    QState *downState = new QState(m_fsm);
    connect(downState, &QState::entered, this, &RpcClient::fsmDownEntered, Qt::QueuedConnection);
    QState *tryingState = new QState(m_fsm);
    connect(tryingState, &QState::entered, this, &RpcClient::fsmTryingEntered, Qt::QueuedConnection);
    QState *upState = new QState(m_fsm);
    connect(upState, &QState::entered, this, &RpcClient::fsmUpEntered, Qt::QueuedConnection);
    m_fsm->setInitialState(downState);
    m_fsm->start();

    connect(this, &RpcClient::fsmDownStart,
            this, &RpcClient::fsmDownStartQueued, Qt::QueuedConnection);
    downState->addTransition(this, &RpcClient::fsmDownStartQueued, tryingState);
    connect(this, &RpcClient::fsmTryingAnyMsgReceived,
            this, &RpcClient::fsmTryingAnyMsgReceivedQueued, Qt::QueuedConnection);
    tryingState->addTransition(this, &RpcClient::fsmTryingAnyMsgReceivedQueued, upState);
    connect(this, &RpcClient::fsmTryingHeartbeatTimeout,
            this, &RpcClient::fsmTryingHeartbeatTimeoutQueued, Qt::QueuedConnection);
    tryingState->addTransition(this, &RpcClient::fsmTryingHeartbeatTimeoutQueued, tryingState);
    connect(this, &RpcClient::fsmTryingHeartbeatTick,
            this, &RpcClient::fsmTryingHeartbeatTickQueued, Qt::QueuedConnection);
    tryingState->addTransition(this, &RpcClient::fsmTryingHeartbeatTickQueued, tryingState);
    connect(this, &RpcClient::fsmTryingAnyMsgSent,
            this, &RpcClient::fsmTryingAnyMsgSentQueued, Qt::QueuedConnection);
    tryingState->addTransition(this, &RpcClient::fsmTryingAnyMsgSentQueued, tryingState);
    connect(this, &RpcClient::fsmTryingStop,
            this, &RpcClient::fsmTryingStopQueued, Qt::QueuedConnection);
    tryingState->addTransition(this, &RpcClient::fsmTryingStopQueued, downState);
    connect(this, &RpcClient::fsmUpHeartbeatTimeout,
            this, &RpcClient::fsmUpHeartbeatTimeoutQueued, Qt::QueuedConnection);
    upState->addTransition(this, &RpcClient::fsmUpHeartbeatTimeoutQueued, tryingState);
    connect(this, &RpcClient::fsmUpHeartbeatTick,
            this, &RpcClient::fsmUpHeartbeatTickQueued, Qt::QueuedConnection);
    upState->addTransition(this, &RpcClient::fsmUpHeartbeatTickQueued, upState);
    connect(this, &RpcClient::fsmUpAnyMsgReceived,
            this, &RpcClient::fsmUpAnyMsgReceivedQueued, Qt::QueuedConnection);
    upState->addTransition(this, &RpcClient::fsmUpAnyMsgReceivedQueued, upState);
    connect(this, &RpcClient::fsmUpAnyMsgSent,
            this, &RpcClient::fsmUpAnyMsgSentQueued, Qt::QueuedConnection);
    upState->addTransition(this, &RpcClient::fsmUpAnyMsgSentQueued, upState);
    connect(this, &RpcClient::fsmUpStop,
            this, &RpcClient::fsmUpStopQueued, Qt::QueuedConnection);
    upState->addTransition(this, &RpcClient::fsmUpStopQueued, downState);

    connect(this, &RpcClient::fsmDownStart,
            this, &RpcClient::fsmDownStartEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmTryingAnyMsgReceived,
            this, &RpcClient::fsmTryingAnyMsgReceivedEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmTryingHeartbeatTimeout,
            this, &RpcClient::fsmTryingHeartbeatTimeoutEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmTryingHeartbeatTick,
            this, &RpcClient::fsmTryingHeartbeatTickEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmTryingAnyMsgSent,
            this, &RpcClient::fsmTryingAnyMsgSentEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmTryingStop,
            this, &RpcClient::fsmTryingStopEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmUpHeartbeatTimeout,
            this, &RpcClient::fsmUpHeartbeatTimeoutEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmUpHeartbeatTick,
            this, &RpcClient::fsmUpHeartbeatTickEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmUpAnyMsgReceived,
            this, &RpcClient::fsmUpAnyMsgReceivedEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmUpAnyMsgSent,
            this, &RpcClient::fsmUpAnyMsgSentEvent, Qt::QueuedConnection);
    connect(this, &RpcClient::fsmUpStop,
            this, &RpcClient::fsmUpStopEvent, Qt::QueuedConnection);

    m_context = new PollingZMQContext(this, 1);
    connect(m_context, &PollingZMQContext::pollError,
            this, &RpcClient::socketError);
    m_context->start();

     connect(this, &RpcClient::startSignal,
             this, &RpcClient::startSlot, Qt::QueuedConnection);
     connect(this, &RpcClient::stopSignal,
             this, &RpcClient::stopSlot, Qt::QueuedConnection);
}

RpcClient::~RpcClient()
{
    stopSocket();

    if (m_context != nullptr)
    {
        m_context->stop();
        m_context->deleteLater();
        m_context = nullptr;
    }
}

/** Connects the 0MQ sockets */
bool RpcClient::startSocket()
{
    m_socket = m_context->createSocket(ZMQSocket::TYP_DEALER, this);
    m_socket->setLinger(0);

    try {
        m_socket->connectTo(m_socketUri);
    }
    catch (const zmq::error_t &e) {
        QString errorString;
        errorString = QString("Error %1: ").arg(e.num()) + QString(e.what());
        //updateState(SocketError, errorString); TODO
        return false;
    }

    connect(m_socket, &ZMQSocket::messageReceived,
            this, &RpcClient::processSocketMessage);


#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "sockets connected" << m_socketUri);
#endif

    return true;
}

/** Disconnects the 0MQ sockets */
void RpcClient::stopSocket()
{
    if (m_socket != nullptr)
    {
        m_socket->close();
        m_socket->deleteLater();
        m_socket = nullptr;
    }
}

void RpcClient::resetHeartbeatLiveness()
{
    m_heartbeatLiveness = m_heartbeatResetLiveness;
}

void RpcClient::resetHeartbeatTimer()
{
    if (m_heartbeatTimer->isActive())
    {
        m_heartbeatTimer->stop();
    }

    if (m_heartbeatInterval > 0)
    {
        m_heartbeatTimer->setInterval(m_heartbeatInterval);
        m_heartbeatTimer->start();
    }
}

void RpcClient::startHeartbeatTimer()
{
    resetHeartbeatTimer();
}

void RpcClient::stopHeartbeatTimer()
{
    m_heartbeatTimer->stop();
}

void RpcClient::heartbeatTimerTick()
{
    m_heartbeatLiveness -= 1;
    if (m_heartbeatLiveness == 0)
    {
         if (m_state == Up)
         {
             emit fsmUpHeartbeatTimeout();
         }
         if (m_state == Trying)
         {
             emit fsmTryingHeartbeatTimeout();
         }
         return;
    }
    if (m_state == Up)
    {
         emit fsmUpHeartbeatTick();
    }
    if (m_state == Trying)
    {
         emit fsmTryingHeartbeatTick();
    }
}

/** Processes all message received on socket */
void RpcClient::processSocketMessage(const QList<QByteArray> &messageList)
{
    pb::Container &rx = m_socketRx;
    rx.ParseFromArray(messageList.at(0).data(), messageList.at(0).size());

#ifdef QT_DEBUG
    std::string s;
    gpb::TextFormat::PrintToString(rx, &s);
    DEBUG_TAG(3, m_debugName, "server message" << QString::fromStdString(s));
#endif

    // react to any incoming message

    if (m_state == Trying)
    {
        emit fsmTryingAnyMsgReceived();
    }

    if (m_state == Up)
    {
        emit fsmUpAnyMsgReceived();
    }

    // react to ping acknowledge message
    if (rx.type() == pb::MT_PING_ACKNOWLEDGE)
    {
        return; // ping acknowledge is uninteresting
    }

    emit socketMessageReceived(rx);
}

void RpcClient::sendSocketMessage(pb::ContainerType type, pb::Container &tx)
{
    if (m_socket == nullptr) {  // disallow sending messages when not connected
        return;
    }

    tx.set_type(type);
#ifdef QT_DEBUG
    std::string s;
    gpb::TextFormat::PrintToString(tx, &s);
    DEBUG_TAG(3, m_debugName, "sent message" << QString::fromStdString(s));
#endif
    try {
        m_socket->sendMessage(QByteArray(tx.SerializeAsString().c_str(), tx.ByteSize()));
    }
    catch (const zmq::error_t &e) {
        QString errorString;
        errorString = QString("Error %1: ").arg(e.num()) + QString(e.what());
        //updateState(SocketError, errorString);  TODO
        return;
    }
    tx.Clear();

    if (m_state == Up)
    {
        emit fsmUpAnyMsgSent();
    }

    if (m_state == Trying)
    {
        emit fsmTryingAnyMsgSent();
    }
}

void RpcClient::sendPing()
{
    pb::Container &tx = m_socketTx;
    sendSocketMessage(pb::MT_PING, tx);
}

void RpcClient::socketError(int errorNum, const QString &errorMsg)
{
    QString errorString;
    errorString = QString("Error %1: ").arg(errorNum) + errorMsg;
    //updateState(SocketError, errorString);  TODO
}

void RpcClient::fsmDownEntered()
{
    if (m_previousState != Down)
    {
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "State DOWN");
#endif
        m_previousState = Down;
        emit stateChanged(m_state);
    }
}

void RpcClient::fsmDownStartEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event START");
#endif

    m_state = Trying;
    startSocket();
    resetHeartbeatLiveness();
    sendPing();
    startHeartbeatTimer();
}

void RpcClient::fsmTryingEntered()
{
    if (m_previousState != Trying)
    {
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "State TRYING");
#endif
        m_previousState = Trying;
        emit stateChanged(m_state);
    }
}

void RpcClient::fsmTryingAnyMsgReceivedEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event ANY MSG RECEIVED");
#endif

    m_state = Up;
    resetHeartbeatLiveness();
    resetHeartbeatTimer();
}

void RpcClient::fsmTryingHeartbeatTimeoutEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event HEARTBEAT TIMEOUT");
#endif

    m_state = Trying;
    stopSocket();
    startSocket();
    resetHeartbeatLiveness();
    sendPing();
}

void RpcClient::fsmTryingHeartbeatTickEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event HEARTBEAT TICK");
#endif

    m_state = Trying;
    sendPing();
}

void RpcClient::fsmTryingAnyMsgSentEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event ANY MSG SENT");
#endif

    m_state = Trying;
    resetHeartbeatTimer();
}

void RpcClient::fsmTryingStopEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event STOP");
#endif

    m_state = Down;
    stopHeartbeatTimer();
    stopSocket();
}

void RpcClient::fsmUpEntered()
{
    if (m_previousState != Up)
    {
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "State UP");
#endif
        m_previousState = Up;
        emit stateChanged(m_state);
    }
}

void RpcClient::fsmUpHeartbeatTimeoutEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event HEARTBEAT TIMEOUT");
#endif

    m_state = Trying;
    stopSocket();
    startSocket();
    resetHeartbeatLiveness();
    sendPing();
}

void RpcClient::fsmUpHeartbeatTickEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event HEARTBEAT TICK");
#endif

    m_state = Up;
    sendPing();
}

void RpcClient::fsmUpAnyMsgReceivedEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event ANY MSG RECEIVED");
#endif

    m_state = Up;
    resetHeartbeatLiveness();
}

void RpcClient::fsmUpAnyMsgSentEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event ANY MSG SENT");
#endif

    m_state = Up;
    resetHeartbeatTimer();
}

void RpcClient::fsmUpStopEvent()
{
#ifdef QT_DEBUG
    DEBUG_TAG(1, m_debugName, "Event STOP");
#endif

    m_state = Down;
    stopHeartbeatTimer();
    stopSocket();
}

/** start trigger */
void RpcClient::start()
{
    emit startSignal(QPrivateSignal());
}

/** start queued trigger function */
void RpcClient::startSlot()
{
    if (m_state == Down) {
        emit fsmDownStart();
    }
}

/** stop trigger */
void RpcClient::stop()
{
    emit stopSignal(QPrivateSignal());
}

/** stop queued trigger function */
void RpcClient::stopSlot()
{
    if (m_state == Trying) {
        emit fsmTryingStop();
    }
    if (m_state == Up) {
        emit fsmUpStop();
    }
}
}; // namespace machinetalk
