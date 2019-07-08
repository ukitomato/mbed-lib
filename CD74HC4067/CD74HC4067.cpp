//
// Created by Yuki Yamato on 2019-06-25.
//

#include "CD74HC4067.h"


const int CD74HC4067::muxChannel[16][4] = {
        {0, 0, 0, 0}, //channel 0
        {1, 0, 0, 0}, //channel 1
        {0, 1, 0, 0}, //channel 2
        {1, 1, 0, 0}, //channel 3
        {0, 0, 1, 0}, //channel 4
        {1, 0, 1, 0}, //channel 5
        {0, 1, 1, 0}, //channel 6
        {1, 1, 1, 0}, //channel 7
        {0, 0, 0, 1}, //channel 8
        {1, 0, 0, 1}, //channel 9
        {0, 1, 0, 1}, //channel 10
        {1, 1, 0, 1}, //channel 11
        {0, 0, 1, 1}, //channel 12
        {1, 0, 1, 1}, //channel 13
        {0, 1, 1, 1}, //channel 14
        {1, 1, 1, 1}  //channel 15
};

int CD74HC4067::read(int channel) {
    s0 = muxChannel[channel][0];
    s1 = muxChannel[channel][1];
    s2 = muxChannel[channel][2];
    s3 = muxChannel[channel][3];

    return sig.read_u16();
}

void CD74HC4067::select(int channel) {
    s0 = muxChannel[channel][0];
    s1 = muxChannel[channel][1];
    s2 = muxChannel[channel][2];
    s3 = muxChannel[channel][3];

}

CD74HC4067::CD74HC4067(DigitalOut s0, DigitalOut s1, DigitalOut s2, DigitalOut s3, const AnalogIn& sig) : s0(s0), s1(s1),
                                                                                                          s2(s2), s3(s3),
                                                                                                          sig(sig) {
}


