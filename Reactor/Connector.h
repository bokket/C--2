//
// Created by bokket on 2021/3/6.
//

#ifndef BOKKET_CONNECTOR_H
#define BOKKET_CONNECTOR_H

#include <atomic>
#include <memory>

#include "EventLoop.h"
#include "InetAddress.h"

namespace bokket
{

class Connector: public noncopyable,
                 public std::enable_shared_from_this<Connector>
{
public:
    using NewConnectionCallback = std::function<void(int sockfd)>;
public:
    Connector(EventLoop* loop,const InetAddress& serverAddr);
    ~Connector();

    void setNewConnectionCallback(const NewConnectionCallback& cb)
    { newConnectionCallback_ = cb; }

    void start();  // can be called in any thread
    void restart();  // must be called in loop thread
    void stop();  // can be called in any thread

private:
    enum class Status {
        kDisconnected,
        lConnecting,
        kConnected,
    };

    void setStatus(Status status) {
        status_=status;
    }

    std::string statusToStr() const;

    static const int kMaxRetryDelayMs=30*1000;
    static const int kInitRetryDelayMs=500;

    void startInLoop();
    void stopInLoop();
    void connect();
    void connecting(int sockfd);
    void handleWrite();
    void retry(int sockfd);
    int removeAndResetChannel();
    void resetChannel();
private:
    EventLoop* loop_;
    Status status_;
    NewConnectionCallback newConnectionCallback_;
    InetAddress serverAddr_;

    int retryDelayMs_;

    std::unique_ptr<Channel> channel_;
};

}



#endif //BOKKET_CONNECTOR_H
