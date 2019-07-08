//
// Created by Yuki Yamato on 2019-06-25.
//

#include "AD9833.h"
#include "mbed.h"

DigitalOut FSYNC(p8);
SPI spi(p5, p6, p7); // mosi, miso, sclk

AD9833::AD9833() {
    AD9833::initialize();
}

void AD9833::initialize() {
    // SPI初期設定
    spi.format(16, 2);
    spi.frequency(12000000);
}

void AD9833::write(short dat) {
    FSYNC.write(0);
    spi.write(dat);
    FSYNC.write(1);
}


void AD9833::setWave(long frequency, int Waveform) {
    int phase0command = 0x4000;

    float steps_per_Hz = (pow(2, 28)) / REF_CLOCK;

    unsigned long int steps_per_clk = frequency * steps_per_Hz;

    int MSB = (steps_per_clk & 0xFFFC000) >> 14;
    int LSB = steps_per_clk & 0x3FFF;

    LSB |= phase0command;
    MSB |= phase0command;

    write(0x2100);
    write(LSB);
    write(MSB);
    write(0xC000);
    write(Waveform);
}