#include <vector>
#include <cassert>
#include <iostream>
#include <C:\Users\dariy\source\repos\GameMath\GameMath.h>


bool testFloatConversion(float value) {
    uint32_t bytes = myToBytesFloat(value);
    float newValue = myToFloat(bytes);

    if (value == newValue) {
        return true;
    }
    return false;
}

bool testDoubleConversion(double value) {
    uint64_t bytes = myToBytesDouble(value);
    double newValue = myToDouble(bytes);

    if (value == newValue) {
        return true;
    }
    return false;
}

void testConvertions() {
    std::vector<double> doubles = {
        0.0f,
        -0.0f,
        1.0f,
        -1.0f,
        7.123456123234123f,
        -7.123456123234123f,
        std::numeric_limits<double>::infinity(),
        std::numeric_limits<double>::max(),
        std::numeric_limits<double>::lowest()
    };

    for (const double& value : doubles) {
        if (testDoubleConversion(value) == false) {
            std::cout << "FAILED FOR DOUBLE: " << value << std::endl;
        }
    }

    std::vector<float> floats = {
        0.0f,
        -0.0f,
        1.0f,
        -1.0f,
        7.123456f,
        -7.123456f,
        std::numeric_limits<float>::infinity(),
        std::numeric_limits<float>::max(),
        std::numeric_limits<float>::lowest()
    };

    for (const float& value : floats) {
        if (testFloatConversion(value) == false) {
            std::cout << "FAILED FOR FLOAT: " << value << std::endl;
        }
    }
}

void testMyToBytesFloat() {
    assert(myToBytesFloat(0.0f) == 0b00000000000000000000000000000000);
    assert(myToBytesFloat(1.0f) == 0b00111111100000000000000000000000);
    assert(myToBytesFloat(-1.0f) == 0b10111111100000000000000000000000);
    assert(myToBytesFloat(0.5f) == 0b00111111000000000000000000000000);
    assert(myToBytesFloat(-0.5f) == 0b10111111000000000000000000000000);
    assert(myToBytesFloat(std::numeric_limits<float>::infinity()) == 0b01111111100000000000000000000000);
    assert(myToBytesFloat(-std::numeric_limits<float>::infinity()) == 0b11111111100000000000000000000000);
}

void testMyToBytesDouble() {
    assert(myToBytesDouble(0.0) == 0b0000000000000000000000000000000000000000000000000000000000000000);
    assert(myToBytesDouble(1.0) == 0b0011111111110000000000000000000000000000000000000000000000000000);
    assert(myToBytesDouble(-1.0) == 0b1011111111110000000000000000000000000000000000000000000000000000);
    assert(myToBytesDouble(0.5) == 0b0011111111100000000000000000000000000000000000000000000000000000);
    assert(myToBytesDouble(-0.5) == 0b1011111111100000000000000000000000000000000000000000000000000000);
    assert(myToBytesDouble(std::numeric_limits<double>::infinity()) == 0b0111111111110000000000000000000000000000000000000000000000000000);
    assert(myToBytesDouble(-std::numeric_limits<double>::infinity()) == 0b1111111111110000000000000000000000000000000000000000000000000000);
}

void testMyToFloat() {
    assert(myToFloat(0b00000000000000000000000000000000) == 0.0f);
    assert(myToFloat(0b00111111100000000000000000000000) == 1.0f);
    assert(myToFloat(0b10111111100000000000000000000000) == -1.0f);
    assert(myToFloat(0b00111111000000000000000000000000) == 0.5f);
    assert(myToFloat(0b10111111000000000000000000000000) == -0.5f);
    assert(myToFloat(0b01111111100000000000000000000000) == std::numeric_limits<float>::infinity());
    assert(myToFloat(0b11111111100000000000000000000000) == -std::numeric_limits<float>::infinity());
}

void testMyToDouble() {
    assert(myToDouble(0b0000000000000000000000000000000000000000000000000000000000000000) == 0.0);
    assert(myToDouble(0b0011111111110000000000000000000000000000000000000000000000000000) == 1.0);
    assert(myToDouble(0b1011111111110000000000000000000000000000000000000000000000000000) == -1.0);
    assert(myToDouble(0b0011111111100000000000000000000000000000000000000000000000000000) == 0.5);
    assert(myToDouble(0b1011111111100000000000000000000000000000000000000000000000000000) == -0.5);
    assert(myToDouble(0b0111111111110000000000000000000000000000000000000000000000000000) == std::numeric_limits<double>::infinity());
    assert(myToDouble(0b1111111111110000000000000000000000000000000000000000000000000000) == -std::numeric_limits<double>::infinity());
}

void testMyIsFinite() {
    assert(myIsFinite(0.0f) == true);
    assert(myIsFinite(1.0f) == true);
    assert(myIsFinite(-1.0f) == true);
    assert(myIsFinite(0.5f) == true);
    assert(myIsFinite(-0.5f) == true);
    assert(myIsFinite(std::numeric_limits<float>::infinity()) == false);
    assert(myIsFinite(-std::numeric_limits<float>::infinity()) == false);
    assert(myIsFinite(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsFinite(0.0) == true);
    assert(myIsFinite(1.0) == true);
    assert(myIsFinite(-1.0) == true);
    assert(myIsFinite(0.5) == true);
    assert(myIsFinite(-0.5) == true);
    assert(myIsFinite(std::numeric_limits<double>::infinity()) == false);
    assert(myIsFinite(-std::numeric_limits<double>::infinity()) == false);
    assert(myIsFinite(std::numeric_limits<double>::quiet_NaN()) == false);
}

void testMyIsAnyInfinity() {
    assert(myIsAnyInfinity(0.0f) == false);
    assert(myIsAnyInfinity(-0.0f) == false);
    assert(myIsAnyInfinity(1.0f) == false);
    assert(myIsAnyInfinity(-1.0f) == false);
    assert(myIsAnyInfinity(0.5f) == false);
    assert(myIsAnyInfinity(-0.5f) == false);
    assert(myIsAnyInfinity(std::numeric_limits<float>::infinity()) == true);
    assert(myIsAnyInfinity(-std::numeric_limits<float>::infinity()) == true);
    assert(myIsAnyInfinity(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsAnyInfinity(0.0) == false);
    assert(myIsAnyInfinity(-0.0) == false);
    assert(myIsAnyInfinity(1.0) == false);
    assert(myIsAnyInfinity(-1.0) == false);
    assert(myIsAnyInfinity(0.5) == false);
    assert(myIsAnyInfinity(-0.5) == false);
    assert(myIsAnyInfinity(std::numeric_limits<double>::infinity()) == true);
    assert(myIsAnyInfinity(-std::numeric_limits<double>::infinity()) == true);
    assert(myIsAnyInfinity(std::numeric_limits<double>::quiet_NaN()) == false);

}

void testMyPosInfinity() {
    assert(myIsPosInfinity(0.0f) == false);
    assert(myIsPosInfinity(-0.0f) == false);
    assert(myIsPosInfinity(1.0f) == false);
    assert(myIsPosInfinity(-1.0f) == false);
    assert(myIsPosInfinity(0.5f) == false);
    assert(myIsPosInfinity(-0.5f) == false);
    assert(myIsPosInfinity(std::numeric_limits<float>::infinity()) == true);
    assert(myIsPosInfinity(-std::numeric_limits<float>::infinity()) == false);
    assert(myIsPosInfinity(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsPosInfinity(0.0) == false);
    assert(myIsPosInfinity(-0.0) == false);
    assert(myIsPosInfinity(1.0) == false);
    assert(myIsPosInfinity(-1.0) == false);
    assert(myIsPosInfinity(0.5) == false);
    assert(myIsPosInfinity(-0.5) == false);
    assert(myIsPosInfinity(std::numeric_limits<double>::infinity()) == true);
    assert(myIsPosInfinity(-std::numeric_limits<double>::infinity()) == false);
    assert(myIsPosInfinity(std::numeric_limits<double>::quiet_NaN()) == false);

}

void testMyNegInfinity() {
    assert(myIsNegInfinity(0.0f) == false);
    assert(myIsNegInfinity(-0.0f) == false);
    assert(myIsNegInfinity(1.0f) == false);
    assert(myIsNegInfinity(-1.0f) == false);
    assert(myIsNegInfinity(0.5f) == false);
    assert(myIsNegInfinity(-0.5f) == false);
    assert(myIsNegInfinity(std::numeric_limits<float>::infinity()) == false);
    assert(myIsNegInfinity(-std::numeric_limits<float>::infinity()) == true);
    assert(myIsNegInfinity(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsNegInfinity(0.0) == false);
    assert(myIsNegInfinity(-0.0) == false);
    assert(myIsNegInfinity(1.0) == false);
    assert(myIsNegInfinity(-1.0) == false);
    assert(myIsNegInfinity(0.5) == false);
    assert(myIsNegInfinity(-0.5) == false);
    assert(myIsNegInfinity(std::numeric_limits<double>::infinity()) == false);
    assert(myIsNegInfinity(-std::numeric_limits<double>::infinity()) == true);
    assert(myIsNegInfinity(std::numeric_limits<double>::quiet_NaN()) == false);

}

void testMyIsZero() {
    assert(myIsAnyZero(0.0f) == true);
    assert(myIsAnyZero(-0.0f) == true);
    assert(myIsAnyZero(1.0f) == false);
    assert(myIsAnyZero(-1.0f) == false);
    assert(myIsAnyZero(std::numeric_limits<float>::infinity()) == false);
    assert(myIsAnyZero(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsAnyZero(0.0) == true);
    assert(myIsAnyZero(-0.0) == true);
    assert(myIsAnyZero(1.0) == false);
    assert(myIsAnyZero(-1.0) == false);
    assert(myIsAnyZero(std::numeric_limits<double>::infinity()) == false);
    assert(myIsAnyZero(std::numeric_limits<double>::quiet_NaN()) == false);
}

void testMyIsPosZero() {
    assert(myIsAnyZero(0.0f) == true);
    assert(myIsAnyZero(-0.0f) == false);
    assert(myIsAnyZero(1.0f) == false);
    assert(myIsAnyZero(-1.0f) == false);
    assert(myIsAnyZero(std::numeric_limits<float>::infinity()) == false);
    assert(myIsAnyZero(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsAnyZero(0.0) == true);
    assert(myIsAnyZero(-0.0) == false);
    assert(myIsAnyZero(1.0) == false);
    assert(myIsAnyZero(-1.0) == false);
    assert(myIsAnyZero(std::numeric_limits<double>::infinity()) == false);
    assert(myIsAnyZero(std::numeric_limits<double>::quiet_NaN()) == false);
}

void testMyIsNegZero() {
    assert(myIsAnyZero(0.0f) == false);
    assert(myIsAnyZero(-0.0f) == true);
    assert(myIsAnyZero(1.0f) == false);
    assert(myIsAnyZero(-1.0f) == false);
    assert(myIsAnyZero(std::numeric_limits<float>::infinity()) == false);
    assert(myIsAnyZero(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsAnyZero(0.0) == false);
    assert(myIsAnyZero(-0.0) == true);
    assert(myIsAnyZero(1.0) == false);
    assert(myIsAnyZero(-1.0) == false);
    assert(myIsAnyZero(std::numeric_limits<double>::infinity()) == false);
    assert(myIsAnyZero(std::numeric_limits<double>::quiet_NaN()) == false);
}

void testMyIsNAN() {
    assert(myIsNotANumber(0.0f) == false);
    assert(myIsNotANumber(-0.0f) == false);
    assert(myIsNotANumber(1.0f) == false);
    assert(myIsNotANumber(-1.0f) == false);
    assert(myIsNotANumber(std::numeric_limits<float>::infinity()) == false);
    assert(myIsNotANumber(std::numeric_limits<float>::quiet_NaN()) == true);


    assert(myIsNotANumber(0.0) == false);
    assert(myIsNotANumber(-0.0) == false);
    assert(myIsNotANumber(1.0) == false);
    assert(myIsNotANumber(-1.0) == false);
    assert(myIsNotANumber(std::numeric_limits<double>::infinity()) == false);
    assert(myIsNotANumber(std::numeric_limits<double>::quiet_NaN()) == true);

}

void testMyIsNormal() {
    assert(myIsNormal(1.0f) == true);
    assert(myIsNormal(-1.0f) == true);
    assert(myIsNormal(7.123123f) == true);
    assert(myIsNormal(0.5f) == true);
    assert(myIsNormal(-0.5f) == true);
    assert(myIsNormal(std::numeric_limits<float>::infinity()) == false);
    assert(myIsNormal(-std::numeric_limits<float>::infinity()) == false);
    assert(myIsNormal(std::numeric_limits<float>::quiet_NaN()) == false);
    assert(myIsNormal(std::numeric_limits<float>::signaling_NaN()) == false);
    assert(myIsNormal(0.0f) == false);
    assert(myIsNormal(-0.0f) == false);

    assert(myIsNormal(1.0) == true);
    assert(myIsNormal(-1.0) == true);
    assert(myIsNormal(7.123123) == true);
    assert(myIsNormal(0.5) == true);
    assert(myIsNormal(-0.5) == true);
    assert(myIsNormal(std::numeric_limits<double>::infinity()) == false);
    assert(myIsNormal(-std::numeric_limits<double>::infinity()) == false);
    assert(myIsNormal(std::numeric_limits<double>::quiet_NaN()) == false);
    assert(myIsNormal(std::numeric_limits<double>::signaling_NaN()) == false);
    assert(myIsNormal(0.0) == false);
    assert(myIsNormal(-0.0) == false);
}

void testMyIsNotNormal() {
    assert(myIsNotNormal(1.0f) == false);
    assert(myIsNotNormal(-1.0f) == false);
    assert(myIsNotNormal(7.123123f) == false);
    assert(myIsNotNormal(0.5f) == false);
    assert(myIsNotNormal(-0.5f) == false);
    assert(myIsNotNormal(std::numeric_limits<float>::infinity()) == false);
    assert(myIsNotNormal(-std::numeric_limits<float>::infinity()) == false);
    assert(myIsNotNormal(std::numeric_limits<float>::quiet_NaN()) == false);
    assert(myIsNotNormal(std::numeric_limits<float>::signaling_NaN()) == false);
    assert(myIsNotNormal(0.0f) == false);
    assert(myIsNotNormal(-0.0f) == false);
    assert(myIsNotNormal(1e-40f) == true);
    assert(myIsNotNormal(-1e-40f) == true);

    assert(myIsNotNormal(1.0) == false);
    assert(myIsNotNormal(-1.0) == false);
    assert(myIsNotNormal(7.123123) == false);
    assert(myIsNotNormal(0.5) == false);
    assert(myIsNotNormal(-0.5) == false);
    assert(myIsNotNormal(std::numeric_limits<double>::infinity()) == false);
    assert(myIsNotNormal(-std::numeric_limits<double>::infinity()) == false);
    assert(myIsNotNormal(std::numeric_limits<double>::quiet_NaN()) == false);
    assert(myIsNotNormal(std::numeric_limits<double>::signaling_NaN()) == false);
    assert(myIsNotNormal(0.0) == false);
    assert(myIsNotNormal(-0.0) == false);
    //assert(myIsNotNormal(1e-40) == true);
    //assert(myIsNotNormal(-1e-40) == true);
}

void testMyIsSigned() {
    assert(myIsSigned(0.0f) == false);
    assert(myIsSigned(-0.0f) == true);
    assert(myIsSigned(1.0f) == false);
    assert(myIsSigned(-1.0f) == true);
    assert(myIsSigned(0.5f) == false);
    assert(myIsSigned(-0.5f) == true);
    assert(myIsSigned(std::numeric_limits<float>::infinity()) == false);
    assert(myIsSigned(-std::numeric_limits<float>::infinity()) == true);
    assert(myIsSigned(std::numeric_limits<float>::quiet_NaN()) == false);

    assert(myIsSigned(0.0) == false);
    assert(myIsSigned(-0.0) == true);
    assert(myIsSigned(1.0) == false);
    assert(myIsSigned(-1.0) == true);
    assert(myIsSigned(0.5) == false);
    assert(myIsSigned(-0.5) == true);
    assert(myIsSigned(std::numeric_limits<double>::infinity()) == false);
    assert(myIsSigned(-std::numeric_limits<double>::infinity()) == true);
    assert(myIsSigned(std::numeric_limits<double>::quiet_NaN()) == false);

}

void testMyClassify() {
    assert(myClassify(std::numeric_limits<float>::infinity()) == "infinity");
    assert(myClassify(-std::numeric_limits<float>::infinity()) == "infinity");
    assert(myClassify(0.0f) == "zero");
    assert(myClassify(-0.0f) == "zero");
    assert(myClassify(std::numeric_limits<float>::quiet_NaN()) == "not a number");
    assert(myClassify(-1e-40f) == "subnormal");
    assert(myClassify(1e-40f) == "subnormal");
    assert(myClassify(1.0f) == "normal");
    assert(myClassify(-1.0f) == "normal");

    assert(myClassify(std::numeric_limits<double>::infinity()) == "infinity");
    assert(myClassify(-std::numeric_limits<double>::infinity()) == "infinity");
    assert(myClassify(0.0) == "zero");
    assert(myClassify(-0.0) == "zero");
    assert(myClassify(std::numeric_limits<double>::quiet_NaN()) == "not a number");
    //assert(myClassify(-1e-40) == "subnormal");
    //assert(myClassify(1e-40) == "subnormal");
    assert(myClassify(1.0) == "normal");
    assert(myClassify(-1.0) == "normal");
}

void testMyAbs() {
    assert(myAbs(1.f) == 1.f);
    assert(myAbs(-1.f) == 1.f);
    assert(myAbs(0.5f) == 0.5f);
    assert(myAbs(-0.5f) == 0.5f);
    assert(myAbs(7.123123) == 7.123123);
    assert(myAbs(-7.123123) == 7.123123);
    assert(myAbs(0.0f) == 0.0f);
    assert(myAbs(0.f) == 0.f);
}

void testMyMin() {
    assert(myMin(7.123123f, 2.45612f) == 2.45612f);
    assert(myMin(-3.14f, -2.71f) == -3.14f);
    assert(myMin(0.0f, 0.0f) == 0.0f);
    assert(myMin(2.000005, 3.789789789789) == 2.000005);
    assert(myMin(-1.0, -1.5) == -1.5);
}

void testMyMax() {
    assert(myMax(7.123123f, 2.45612f) == 7.123123f);
    assert(myMax(-3.14f, -2.71f) == -2.71f);
    assert(myMax(0.0f, 0.0f) == 0.0f);
    assert(myMax(2.000005, 3.789789789789) == 3.789789789789);
    assert(myMax(-1.0, -1.5) == -1.0);
}

void testMyClamp() {
    // this was generated
    assert(myClamp(10.0f, 0.0f, 20.0f) == 10.0f);
    assert(myClamp(-5.0f, 0.0f, 20.0f) == 0.0f);
    assert(myClamp(25.0f, 0.0f, 20.0f) == 20.0f);
    assert(myClamp(0.0f, -10.0f, 10.0f) == 0.0f);
    assert(myClamp(15.0f, 10.0f, 5.0f) == 10.0f);
    assert(myClamp(0.0f, 0.0f, 0.0f) == 0.0f);
    assert(myClamp(7.0f, 5.0f, 5.0f) == 5.0f);
    assert(myClamp(3.14f, 2.0f, 4.0f) == 3.14f);
    assert(myClamp(-3.14f, -2.0f, 4.0f) == -2.0f);
    assert(myClamp(5.0f, 1.0f, 3.0f) == 3.0f);
    assert(myClamp(2.5f, 2.0f, 2.0f) == 2.0f);
    assert(myClamp(0.0f, -1.0f, 1.0f) == 0.0f);
    assert(myClamp(-1.0f, -2.0f, 0.0f) == -1.0f);
    assert(myClamp(1.5f, 2.0f, 0.0f) == 2.0f);
    assert(myClamp(100.0f, 50.0f, 50.0f) == 50.0f);
    assert(myClamp(-100.0f, -50.0f, -50.0f) == -50.0f);
    assert(myClamp(3.14159, 0.0, 3.0) == 3.0);
    assert(myClamp(3.0, 0.0, 3.0) == 3.0);
    assert(myClamp(-10.0, -20.0, -5.0) == -10.0);
    assert(myClamp(-3.5, -5.0, -1.0) == -3.5);
}

void testMyIsEqualArbitary() {
    // this was generated
    assert(myIsEqualArbitary(1.5f, 1.5f, 0) == true);
    assert(myIsEqualArbitary(1.5f, 1.5f, 1) == true);
    assert(myIsEqualArbitary(1.5f, 1.6f, 0) == false);
    assert(myIsEqualArbitary(1.5f, 1.6f, 1) == false);
    assert(myIsEqualArbitary(-1.5f, -1.5f, 0) == true);
    assert(myIsEqualArbitary(-1.5f, -1.5f, 1) == true);
    assert(myIsEqualArbitary(-1.5f, 1.5f, 0) == false);
    assert(myIsEqualArbitary(0.0f, 0.0f, 0) == true);
    assert(myIsEqualArbitary(0.0f, 1.0f, 0) == false);
    assert(myIsEqualArbitary(0.0f, -1.0f, 0) == false);

    assert(myIsEqualArbitary(1.5, 1.5, 0) == true);
    assert(myIsEqualArbitary(1.5, 1.5, 1) == true);
    assert(myIsEqualArbitary(1.5, 1.6, 0) == false);
    assert(myIsEqualArbitary(1.5, 1.6, 1) == false);
    assert(myIsEqualArbitary(-1.5, -1.5, 0) == true);
    assert(myIsEqualArbitary(-1.5, -1.5, 1) == true);
    assert(myIsEqualArbitary(-1.5, 1.5, 0) == false);
    assert(myIsEqualArbitary(0.0, 0.0, 0) == true);
    assert(myIsEqualArbitary(0.0, 1.0, 0) == false);
    assert(myIsEqualArbitary(0.0, -1.0, 0) == false);
}

void testMyIsEqual() {
    assert(myIsEqual(1.5001f, 1.502f, 0.01111) == true);
    assert(myIsEqual(1.5001f, 1.5003f, 0.0001) == false);
    assert(myIsEqual(1.50001, 1.50002, 0.00001) == true);
    assert(myIsEqual(1.50001, 1.50003, 0.00001) == false);
    assert(myIsEqual(0.0f, 0.0f, 0.0) == true);
}

void testMyIsLessArbitary() {
    assert(myIsLessArbitary(1.5001f, 1.5002f, 4) == true);
    assert(myIsLessArbitary(1.5002f, 1.5001f, 4) == false);
    assert(myIsLessArbitary(1.5001f, 1.5001f, 4) == false);
    assert(myIsLessArbitary(1.49999f, 1.50000f, 8) == true);
    assert(myIsLessArbitary(1.50000f, 1.49999f, 8) == false);
    assert(myIsLessArbitary(1.999999, 2.000000, 10) == true);
    assert(myIsLessArbitary(2.000000, 1.999999, 10) == false);
    assert(myIsLessArbitary(0.0001, 0.0002, 16) == true);
    assert(myIsLessArbitary(0.0002, 0.0001, 16) == false);
    assert(myIsLessArbitary(-1.4, -1.5, 5) == false);
    assert(myIsLessArbitary(-1.50001, -1.50002, 6) == false);
    assert(myIsLessArbitary(-1.50002, -1.50001, 6) == true);
    assert(myIsLessArbitary(1.0, 1.0, 32) == false);
    assert(myIsLessArbitary(123.456, 123.457, 12) == true);
    assert(myIsLessArbitary(123.457, 123.456, 12) == false);
    assert(myIsLessArbitary(0.0, 1.0, 2) == true);
    assert(myIsLessArbitary(1.0, 0.0, 2) == false);
    assert(myIsLessArbitary(0.0, -1.0, 2) == false);
    assert(myIsLessArbitary(-1.0, 0.0, 2) == true);
}

void testMyIsLess() {
    assert(myIsLess(1.0, 2.0, 0.1) == true);
    assert(myIsLess(2.0, 1.0, 0.1) == false);
    assert(myIsLess(1.5, 1.50001, 0.0001) == true);
    assert(myIsLess(1.50001, 1.5, 0.0001) == false);
    assert(myIsLess(1.50001, 1.50002, 0.00001) == true);
    assert(myIsLess(1.50002, 1.50001, 0.00001) == false);
    assert(myIsLess(-1.0, 0.0, 0.1) == true);
    assert(myIsLess(0.0, -1.0, 0.1) == false);
}

void testMyIsGreaterArbitary() {
    assert(myIsGreaterArbitary(1.5, 1.4, 5) == true);
    assert(myIsGreaterArbitary(-1.5, -1.4, 5) == false);
    assert(myIsGreaterArbitary(-1.50001, -1.50002, 6) == true);
    assert(myIsGreaterArbitary(-1.50002, -1.50001, 6) == false);
    assert(myIsGreaterArbitary(1.0, 1.0, 32) == false);
    assert(myIsGreaterArbitary(123.457, 123.456, 12) == true);
    assert(myIsGreaterArbitary(123.456, 123.457, 12) == false);
    assert(myIsGreaterArbitary(1.0, 0.0, 2) == true);
    assert(myIsGreaterArbitary(0.0, 1.0, 2) == false);
    assert(myIsGreaterArbitary(-1.0, 0.0, 2) == false);
    assert(myIsGreaterArbitary(0.0, -1.0, 2) == true);
}


void testMyIsGreater() {
    assert(myIsGreaterArbitary(1.5, 1.4, 5) == true);
    assert(myIsGreaterArbitary(-1.5, -1.4, 5) == false);
    assert(myIsGreaterArbitary(-1.50001, -1.50002, 6) == true);
    assert(myIsGreaterArbitary(-1.50002, -1.50001, 6) == false);
    assert(myIsGreaterArbitary(1.0, 1.0, 32) == false);
    assert(myIsGreaterArbitary(123.457, 123.456, 12) == true);
    assert(myIsGreaterArbitary(123.456, 123.457, 12) == false);
    assert(myIsGreaterArbitary(1.0, 0.0, 2) == true);
    assert(myIsGreaterArbitary(0.0, 1.0, 2) == false);
    assert(myIsGreaterArbitary(-1.0, 0.0, 2) == false);
    assert(myIsGreaterArbitary(0.0, -1.0, 2) == true);
}


int main() {

    testConvertions();
    testMyToBytesFloat();
    testMyToBytesDouble();
    testMyToFloat();
    testMyToDouble();

    testMyIsFinite();
    testMyIsAnyInfinity();
    testMyPosInfinity();
    testMyNegInfinity();

    testMyIsZero();
    //testMyIsPosZero(); // does not recognize difference between -0 and 0
    //testMyIsNegZero(); // does not recognize difference between -0 and 0
    testMyIsNAN();
    testMyIsNormal();
    testMyIsNotNormal(); // does not recognize -1e-40 but recognizes -1e-40f

    testMyIsSigned();
    testMyClassify(); // does not recognize -1e-40 but recognizes -1e-40f

    testMyAbs();
    testMyMin();
    testMyMax();
    testMyClamp();
    testMyIsEqualArbitary();
    testMyIsEqual();

    testMyIsLessArbitary();
    testMyIsLess();
    testMyIsGreaterArbitary();
    testMyIsGreater();

    return 0;
}



