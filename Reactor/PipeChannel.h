//
// Created by bokket on 2021/9/4.
//

#ifndef BOKKERVE_PIPECHANNEL_H
#define BOKKERVE_PIPECHANNEL_H

#include <memory>

#include "../base/noncopyable.h"

namespace bokket
{
class Channel: public std::enable_shared_from_this<Channel>,
               public noncopyable
{
public:
    Channel()=default;
    virtual ~Channel()=default;

    virtual int identifier() const=0;

    unsigned int getId() const {
        return id_;
    }

    void setId(unsigned int id) {
        id_=id;
    }

    virtual bool handleReadEvent() = 0;

    virtual bool handleWriteEvent() = 0;

    virtual void handleErrorEvent() = 0;
private:
    unsigned int id_=0;
};

class PipeChannel: public Channel,
                   public noncopyable
{
public:
    PipeChannel();
    ~PipeChannel();

    int identifier() const override;

    bool handleReadEvent() override;

    bool handleWriteEvent() override;

    void handleErrorEvent() override;

    bool notify();
private:
    int readFd_;
    int writeFd_;
};

}



#endif //BOKKERVE_PIPECHANNEL_H
