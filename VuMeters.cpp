#include "VuMeters.h"

VuMeters::VuMeters()
{
    vu.vuMeterMain(vu);
}

VuMeters::~VuMeters()
{
    std::cout << "\n Destructing Meter Segments \n\n";
}

