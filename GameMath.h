#pragma once
#include <bit>
#include <bitset>
#include <iostream>
#include <cinttypes>


/*-------------------Part1-------------------*/

uint32_t myToBytesFloat(float value)
{
    uint32_t byte;
    std::memcpy(&byte, &value, sizeof(float));
    return byte;
}

uint64_t myToBytesDouble(double const& value)
{
    uint64_t byte;
    std::memcpy(&byte, &value, sizeof(double));
    return byte;
}

float myToFloat(uint32_t value) {
    float byte;
    std::memcpy(&byte, &value, sizeof(uint32_t));
    return byte;
}

double myToDouble(uint64_t value) {
    double byte;
    std::memcpy(&byte, &value, sizeof(uint64_t));
    return byte;
}

/*-------------------Part2-------------------*/

template<typename T>
bool myIsFinite(T const& value) {
    
    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt & 0x7FFFFFFF) < 0x7F800000;
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt & 0x7FFFFFFFFFFFFFFF) < 0x7FF0000000000000;
    }

}

template<typename T>
bool myIsAnyInfinity(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt == 0x7F800000 || convertedInt == 0xFF800000);
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt == 0x7FF0000000000000 || convertedInt == 0xFFF0000000000000);
    }

    return false;
}

template<typename T>
bool myIsPosInfinity(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt == 0x7F800000);
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt == 0x7FF0000000000000);
    }

    return false;
}

template<typename T>
bool myIsNegInfinity(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt == 0xFF800000);
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt == 0xFFF0000000000000);
    }

    return false;
}

template<typename T>
bool myIsAnyZero(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt == 0x00000000 || convertedInt == 0x80000000);
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt == 0x0000000000000000 || convertedInt == 0x8000000000000000);
    }

    return false;
}

template<typename T>
bool myIsPosZero(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt == 0b00000000000000000000000000000000);
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt == 0b0000000000000000000000000000000000000000000000000000000000000000);
    }

    return false;
}

template<typename T>
bool myIsNegZero(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt == 0b10000000000000000000000000000000);
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt == 0b1100000000000000000000000000000000000000000000000000000000000000);
    }

    return false;
}

template<typename T>
bool myIsNotANumber(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt & 0x7FFFFFFF) > 0x7F800000;
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt & 0x7FFFFFFFFFFFFFFF) > 0x7FF0000000000000;
    }

    return false;
}

template<typename T>
bool myIsNormal(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        uint32_t exponent = (convertedInt & 0x7F800000) >> 23;
        return exponent > 0 && exponent < 255;
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        uint64_t exponent = (convertedInt & 0x7FF0000000000000) >> 52;
        return exponent > 0 && exponent < 2047;
    }
    return false;
}

template<typename T>
bool myIsNotNormal(T const& value) {

    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        uint32_t exponent = (convertedInt & 0x7F800000) >> 23;
        uint32_t mantissa = convertedInt & 0x007FFFFF;
        return exponent == 0 && mantissa != 0;
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        uint64_t exponent = (convertedInt & 0x7FF0000000000000) >> 52;
        uint64_t mantissa = convertedInt & 0x000FFFFFFFFFFFFF;
        return exponent == 0 && mantissa != 0;
    }
    return false;
}

template<typename T>
bool myIsSigned(T const& value) {
    if (sizeof(value) == 4) {
        uint32_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(float));
        return (convertedInt >> 31) & 1;
    }
    else if (sizeof(value) == 8) {
        uint64_t convertedInt;
        std::memcpy(&convertedInt, &value, sizeof(double));
        return (convertedInt >> 63) & 1;
    }

    return false;
}

template<typename T>
std::string myClassify(T const& value) {
    if (myIsAnyInfinity(value)) {
        return "infinity";
    }
    else if (myIsAnyZero(value)) {
        return "zero";
    }
    else if (myIsNotANumber(value)) {
        return "not a number";
    }
    else if (myIsNotNormal(value)) {
        return "subnormal";
    }
    else if (myIsNormal(value)) {
        return "normal";
    }

    return "unknown";
}

/*-------------------Part3-------------------*/

template<typename T>
T myAbs(T const& value) {
    return (value >= 0) ? value : value * -1;
}

template<typename T>
T myMin(T const& valueA, T const& valueB) {

    if (valueA == valueB) {
        return valueA;
    }
    return (valueA < valueB) ? valueA : valueB;
}

template<typename T>
T myMax(T const& valueA, T const& valueB) {

    if (valueA == valueB) {
        return valueA;
    }
    return (valueA < valueB) ? valueB : valueA;
}

template<typename T>
T myClamp(T const& value, T const& lo, T const& hi) {
    if (hi < lo) {
        return lo;
    }
    return (value < lo) ? lo : (value > hi ? hi : value);
}

/*-------------------Part4-------------------*/


template<typename T, typename M>
bool myIsEqualArbitary(T const& value1, M const& value2, int precision) {

    if (precision < 0) {
        return false;
    }

    if (sizeof(value1) == 4 && sizeof(value2) == 4) {
        if (precision > 31) {
            return false;
        }

        uint32_t newValue1, newValue2;

        std::memcpy(&newValue1, &value1, sizeof(float));
        std::memcpy(&newValue2, &value2, sizeof(float));

        newValue1 >>= precision;
        newValue2 >>= precision;

        return newValue1 == newValue2;
    }
    else if (sizeof(value1) == 8 && sizeof(value2) == 8) {
        if (precision > 63) {
            return false;
        }

        uint64_t newValue1, newValue2;

        std::memcpy(&newValue1, &value1, sizeof(double));
        std::memcpy(&newValue2, &value2, sizeof(double));

        newValue1 >>= precision;
        newValue2 >>= precision;

        return newValue1 == newValue2;
    }
    return false;
}

template<typename T, typename M>
bool myIsEqual(T const& value1, M const& value2, double precision) {

    if (precision < 0) {
        return false;
    }

    if (myAbs(value1 - value2) <= precision) {
        return true;
    }

    return false;

}

template<typename T, typename M>
bool myIsLessArbitary(T const& value1, M const& value2, int precision) {

    if (precision < 0) {
        return false;
    }

    if (sizeof(value1) == 4 && sizeof(value2) == 4) {
        if (precision > 31) {
            return false;
        }

        uint32_t newValue1, newValue2;

        std::memcpy(&newValue1, &value1, sizeof(float));
        std::memcpy(&newValue2, &value2, sizeof(float));

        newValue1 ^= (newValue1 >> 31) ? 0xFFFFFFFF : 0x80000000;
        newValue2 ^= (newValue2 >> 31) ? 0xFFFFFFFF : 0x80000000;

        newValue1 >>= precision;
        newValue2 >>= precision;
        return (myAbs(newValue1) < myAbs(newValue2));
    }
    else if (sizeof(value1) == 8 && sizeof(value2) == 8) {
        if (precision > 63) {
            return false;
        }

        uint64_t newValue1, newValue2;

        std::memcpy(&newValue1, &value1, sizeof(double));
        std::memcpy(&newValue2, &value2, sizeof(double));

        newValue1 ^= (newValue1 >> 63) ? 0xFFFFFFFFFFFFFFFF : 0x8000000000000000;
        newValue2 ^= (newValue2 >> 63) ? 0xFFFFFFFFFFFFFFFF : 0x8000000000000000;

        newValue1 >>= precision;
        newValue2 >>= precision;
        return (myAbs(newValue1) < myAbs(newValue2));
    }
    return false;
}

template<typename T, typename M>
bool myIsLess(T const& value1, M const& value2, int precision) {

    if (precision < 0) {
        return false;
    }

    double difference = value1 - value2;

    if (myAbs(difference) < precision) {
        return true;
    }

    return difference < 0;

}

template<typename T, typename M>
bool myIsGreaterArbitary(T const& value1, M const& value2, int precision) {

    if (precision < 0) {
        return false;
    }

    if (sizeof(value1) == 4 && sizeof(value2) == 4) {
        if (precision > 31) {
            return false;
        }

        uint32_t newValue1, newValue2;

        std::memcpy(&newValue1, &value1, sizeof(float));
        std::memcpy(&newValue2, &value2, sizeof(float));

        newValue1 ^= (newValue1 >> 31) ? 0xFFFFFFFF : 0x80000000;
        newValue2 ^= (newValue2 >> 31) ? 0xFFFFFFFF : 0x80000000;

        newValue1 >>= precision;
        newValue2 >>= precision;

        return newValue1 > newValue2;
    }
    else if (sizeof(value1) == 8 && sizeof(value2) == 8) {
        if (precision > 63) {
            return false;
        }

        uint64_t newValue1, newValue2;

        std::memcpy(&newValue1, &value1, sizeof(double));
        std::memcpy(&newValue2, &value2, sizeof(double));

        newValue1 ^= (newValue1 >> 63) ? 0xFFFFFFFFFFFFFFFF : 0x8000000000000000;
        newValue2 ^= (newValue2 >> 63) ? 0xFFFFFFFFFFFFFFFF : 0x8000000000000000;

        newValue1 >>= precision;
        newValue2 >>= precision;

        return newValue1 > newValue2;
    }
    return false;
}

template<typename T, typename M>
bool myIsGreater(T const& value1, M const& value2, int precision) {

    if (precision < 0) {
        return false;
    }

    double difference = value1 - value2;

    if (myAbs(difference) < precision) {
        return false;
    }

    return difference > 0;

}







