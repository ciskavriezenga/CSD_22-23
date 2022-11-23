#include "oscillator.h"

Oscillator::Oscillator()
{
  std::cout << "Inside Oscillator constructor\n";
}

Oscillator::Oscillator(float freq)
{
  // the 'this pointer' in case the field name == parameter name
  this->freq = freq;
  std::cout << "Inside Oscillator::Oscillator(float freq) constructor\n";
}


Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
}

void Oscillator::setFreq(float frequency)
{
  if(freq > 0 && freq < 22000){
    freq = frequency;
  } else {
    std::cout << "\nRetrieved a frequency outside the range.\n";
  }


  std::cout << "Inside Oscillator::setFreq - freq: "
    << freq << "\n";
}

float Oscillator::getFreq()
{
  return freq;
}