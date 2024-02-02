#include "Screen.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(nullptr));

    Screen screen;

    screen.update();

    return 0;
}
