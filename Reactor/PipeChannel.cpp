//
// Created by bokket on 2021/9/4.
//

#include "PipeChannel.h"

#include <sys/unistd.h>

#include "Socket.h"
namespace bokket
{

PipeChannel::PipeChannel() {
    int fd[2];
    int ret=::pipe(fd);
    static_assert(ret==0,"PipeChannel::PipeChannel() pipe error");
    readFd_=fd[0];
    writeFd_=fd[1];

    Socket::ptr readfd=Socket::CreateTcp(readFd_);
    readfd->setNonBlockAndCloseOnExec();

    Socket::ptr writefd=Socket::CreateTcp(writeFd_);
    writefd->setNonBlockAndCloseOnExec();
}

PipeChannel::~PipeChannel() noexcept {
    ::close(readFd_);
    ::close(writeFd_);
}

int PipeChannel::identifier() const {
    return readFd_;
}

bool PipeChannel::handleReadEvent() {
    char ch;
    auto n = ::read(readFd_, &ch, sizeof ch);
    return n == 1;
}

bool PipeChannel::handleWriteEvent() {
    assert (false);
    return false;
}

void PipeChannel::handleErrorEvent() {

}

bool PipeChannel::notify() {
    char ch = 0;
    auto n = ::write(writeFd_, &ch, sizeof ch);
    return n == 1;
}

}