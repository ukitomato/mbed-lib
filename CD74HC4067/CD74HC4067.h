//
// Created by Yuki Yamato on 2019-06-25.
//

#ifndef MBED_LIB_CD74HC4067_H
#define MBED_LIB_CD74HC4067_H

#include "mbed.h"

class CD74HC4067 {


private:
    static const int muxChannel[16][4];

    DigitalOut s0;
    DigitalOut s1;
    DigitalOut s2;
    DigitalOut s3;

    AnalogIn sig;

public:
    CD74HC4067(DigitalOut s0, DigitalOut s1, DigitalOut s2, DigitalOut s3, const AnalogIn& sig);

    int read(int channel);

    void select(int channel);
};


#endif //MBED_LIB_CD74HC4067_H
