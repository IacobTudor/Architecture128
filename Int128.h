#ifndef ARCHITECTURE128_INT128_H
#define ARCHITECTURE128_INT128_H
#include <cstdint>

struct Int128;

extern "C" void add128(const Int128* a, const Int128* b, Int128* c);
extern "C" void sub128(const Int128* a, const Int128* b, Int128* c);
extern "C" void mul128(const Int128* a, const Int128* b, Int128* c);
extern "C" void mul128Value(const Int128* a, uint64_t b, Int128* c);
extern "C" void and128(const Int128* a, const Int128* b, Int128* c);
extern "C" void or128(const Int128* a, const Int128* b, Int128* c);
extern "C" void xor128(const Int128* a, const Int128* b, Int128* c);

struct Int128 {
    uint64_t low=0, high=0;

    constexpr Int128(const uint64_t low_, const uint64_t high_) : low(low_), high(high_) {}

    Int128& operator=(const Int128& other) {
        if (this != &other) {
            low = other.low;
            high = other.high;
        }
        return *this;
    }

    Int128& operator=(const uint64_t value) {
        low = value;
        return *this;
    }

    Int128& operator+=(const Int128& other) {
        add128(this,&other,this);
        return *this;
    }

    Int128& operator+=(const uint64_t value) {
        const uint64_t low_ant = low;
        low += value;
        if (low < low_ant) {
            high++;
        }
        return *this;
    }

    Int128 operator+(const Int128& other) {
        Int128 temp(*this);
        add128(&temp,&other,&temp);
        return temp;
    }

    Int128& operator-=(const Int128& other) {
        sub128(this,&other,this);
        return *this;
    }

    Int128& operator-=(const uint64_t value) {
        uint64_t low_ant = low;
        low -= value;
        if (low_ant < low) {
            high--;
        }
        return *this;
    }

    Int128 operator-(const Int128& other) {
        Int128 temp(*this);
        sub128(&temp,&other,&temp);
        return temp;
    }

    bool operator==(const Int128& other) const {
        return low == other.low && high == other.high;
    }

    bool operator!=(const Int128& other) const {
        return low != other.low || high != other.high;
    }

    bool operator<(const Int128& other) const {
        return low < other.low || (low == other.low && high < other.high);
    }

    bool operator>(const Int128& other) const {
        return other < *this;
    }

    bool operator<=(const Int128& other) const {
        return !(*this > other);
    }

    bool operator>=(const Int128& other) const {
        return !(*this < other);
    }

    Int128& operator*=(const Int128& other) {
        mul128(this,&other,this);
        return *this;
    }

    Int128& operator*=(const uint64_t value) {
        mul128Value(this,value,this);
        return *this;
    }

    Int128 operator*(const Int128& other) {
        Int128 temp(*this);
        mul128(&temp,&other,&temp);
        return temp;
    }

    Int128 operator*(const uint64_t value) {
        Int128 temp(*this);
        mul128Value(&temp,value,&temp);
        return temp;
    }

    Int128& operator&=(const Int128& other) {
        and128(this,&other,this);
        return *this;
    }

    Int128& operator&=(const uint64_t value) {
        this->low &= value;
        return *this;
    }

    Int128 operator&(const Int128& other) {
        Int128 temp(*this);
        and128(&temp,&other,&temp);
        return temp;
    }

    Int128 operator&(const uint64_t value) {
        Int128 temp(*this);
        temp.low&=value;
        return temp;
    }

    Int128& operator|=(const Int128& other) {
        or128(this,&other,this);
        return *this;
    }

    Int128& operator|=(const uint64_t value) {
        this->low |= value;
        return *this;
    }

    Int128 operator|(const Int128& other) {
        Int128 temp(*this);
        or128(&temp,&other,&temp);
        return temp;
    }

    Int128 operator|(const uint64_t value) {
        Int128 temp(*this);
        temp.low|=value;
        return temp;
    }

    Int128& operator^=(const Int128& other) {
        xor128(this,&other,this);
        return *this;
    }

    Int128& operator^=(const uint64_t value) {
        this->low ^= value;
        return *this;
    }

    Int128 operator^(const Int128& other) {
        Int128 temp(*this);
        xor128(&temp,&other,&temp);
        return temp;
    }

    Int128 operator^(const uint64_t value) {
        Int128 temp(*this);
        temp.low^=value;
        return temp;
    }

};

#endif