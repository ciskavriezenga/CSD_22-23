#include "oscillator.h"

int main()
{
  std::cout << "\nstart main\n";

  Oscillator osc_test(220.4f);

  Oscillator osc(440.8f);

  //osc.setFreq(220.0);
  std::cout << "\nosc.freq: " << osc.getFreq() << "\n";

  // end program
  return 0;

}
