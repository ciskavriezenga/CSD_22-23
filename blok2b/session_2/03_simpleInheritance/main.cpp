#include "dog.h"
#include "cat.h"

int main ()
{
  Pet aPet("Peter");
  Cat aCat("Foo");
  Dog aDog("Bar");

  aPet.sleep();
  aCat.sleep();
  aDog.sleep();

  aCat.meow();
  // end program
  return 0;
}
