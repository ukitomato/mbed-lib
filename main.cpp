#include "mbed.h"
#include "AD9833/AD9833.h"
#include "CD74HC4067/CD74HC4067.h"

AD9833 ad9833;

AnalogIn _sig(p17);
AnalogIn sig(p18);

DigitalOut s_s0(p19);
DigitalOut s_s1(p20);
DigitalOut s_s2(p21);
DigitalOut s_s3(p22);
CD74HC4067 transSelector(s_s0, s_s1, s_s2, s_s3, _sig);

DigitalOut m_s0(p23);
DigitalOut m_s1(p24);
DigitalOut m_s2(p25);
DigitalOut m_s3(p26);
CD74HC4067 readSelector(m_s0, m_s1, m_s2, m_s3, sig);

Serial pc(USBTX, USBRX);


int frequency = 100000;
const int POINT_NUM = 16;

int main() {

    ad9833.setWave(frequency, AD9833::WaveType::SINE);
    int *data = new int[POINT_NUM];
    while (1) {
        for (int i = 0; i < 1; i++) {
            transSelector.select(i);
            wait_ms(5);
            for (int j = 0; j < 1; j++) {
                data[4 * i + j] = readSelector.read(j);
                wait_ms(5);
            }
        }
        pc.printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                  data[0], data[1], data[2], data[3],
                  data[4], data[5], data[6], data[7],
                  data[8], data[9], data[10], data[11],
                  data[12], data[13], data[14], data[15]
        );
    }
}
