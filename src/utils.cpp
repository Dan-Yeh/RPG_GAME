#include <random>
#include "../Utilities/utils.h"
namespace RNG {

float roll_dice(void)
{
    /* initialize random seed: */
    srand(time(NULL));
    float times = ((double)rand() / (RAND_MAX));
    return times;
}

}
