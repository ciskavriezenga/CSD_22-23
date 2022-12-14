#include "jack_module.h"
#include <cmath>
#include <iostream>


/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */


class CustomCallback : public AudioCallback {
public:
    void prepare (int rate) override {
        sampleRate = (float) rate;
    }

    void process (AudioBuffer buffer) override {
        for (int i = 0; i < buffer.numFrames; ++i) {
            phase += frequency / sampleRate;
            // write sample to buffer at channel 0
            buffer.outputChannels[0][i] = sin (phase * pi * 2.0f);
        }
    }

private:
    const float pi = acos (-1);  //atan(1) * 4; <-- vak van Pieter.
    float phase = 0;
    float frequency = 440;
    float sampleRate = 48000;
};

// ================================================================================

int main() {
    auto callback = CustomCallback {};
    auto jackModule = JackModule { callback };

    jackModule.init (0, 1);

    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
        }
    }
}