//
// Created by Yuki Yamato on 2019-06-25.
//

#ifndef MBED_LIB_AD9833_H
#define MBED_LIB_AD9833_H


const float REF_CLOCK = 25000000.0;

class AD9833 {
private:
    void write(short dat);

public:
    AD9833();

    void initialize();

    void setWave(long frequency, int Waveform);

    class WaveType {
    public:
        static const int SINE = 0x2000;
        static const int SQUARE = 0x2028;
        static const int TRIANGLE = 0x2002;
    };
};




#endif //MBED_LIB_AD9833_H
