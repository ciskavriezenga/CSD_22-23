#include <iostream>

// 3 type access specifiers:
// public, protected, private

class Oscillator
{
public:
  Oscillator();
  Oscillator(float freq);
  ~Oscillator();

  // setters and getters
  void setFreq(float frequency);
  float getFreq();
private:
  float freq;
};
