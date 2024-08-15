#include "ch6.h"

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        // assign ret*val to ret and decrement val
        // - decrement afterhand so the -- after val
        ret *= val--;
    
    return ret;
}