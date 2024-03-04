#include <stdio.h>
#include "float_vector.h"

int main(int argc, char const *argv[])
{
    FloatVector *vec = FVcreate(10);


    FVprint(vec);

    FVappend(vec, 2.5);
    FVappend(vec, 4.5);
    FVappend(vec, 3.5);
    FVappend(vec, 7.5);

    FVset(vec, 1, 9.56);

    FVprint(vec);

    FVdestroy(&vec);

    FVprint(vec);

    return 0;
}
