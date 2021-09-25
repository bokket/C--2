//
// Created by bokket on 2021/7/31.
//

#ifndef BOKKERVE_IP_ADDRESS_H
#define BOKKERVE_IP_ADDRESS_H

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>

namespace bokket
{

class ipv4_address
{
public:
    //typedef unsigned char __uint8_t;
    //        unsigned char	1	0~255;
    using bytes_t = std::uint8_t[4]
public:
    constexpr ipv4_address();
    explicit constexpr ipv4_address(std::uint32_t integer);
    explicit constexpr ipv4_address(const std::uint8_t(&bytes)[4]);
    explicit constexpr ipv4_address(std::uint8_t b0
                                    ,std::uint8_t b1
                                    ,std::uint8_t b2
                                    ,std::uint8_t b3);

    constexpr const bytes_t &bytes() const {
        return bytes_;
    }

    constexpr std::uint32_t to_integer() const {

    }

    static constexpr ipv4_address loopback() {
        return ipv4_address(127,0,0,1);
    }

    constexpr bool is_loopback() const {
        return bytes_[0]==127;
    }

    constexpr bool is_private_network() const {
        return bytes_[0]==10 ||
              (bytes_[0]==192 && bytes_[2]==168) ||
              (bytes_[0]==172 && (bytes_[1]&0xF0)==0x10)

    }

    constexpr bool operator==(ipv4_address other) const
    {
        return
                bytes_[0] == other.bytes_[0] &&
                bytes_[1] == other.bytes_[1] &&
                bytes_[2] == other.bytes_[2] &&
                bytes_[3] == other.bytes_[3];
    }

    constexpr bool operator!=(ipv4_address other) const
    {
        return !(*this == other);
    }

    constexpr bool operator<(ipv4_address other) const
    {
        return to_integer() < other.to_integer();
    }

    constexpr bool operator>(ipv4_address other) const
    {
        return other < *this;
    }

    constexpr bool operator<=(ipv4_address other) const
    {
        return !(other < *this);
    }

    constexpr bool operator>=(ipv4_address other) const
    {
        return !(*this < other);
    }


private:
    alignas(std::uint32_t) std::uint8_t bytes_[4];
};

}

class ip_address {


};


#endif //BOKKERVE_IP_ADDRESS_H
