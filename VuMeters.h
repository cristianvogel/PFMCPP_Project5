#include "LeakedObjectDetector.h"
#include "Meter.h"

struct VuMeters
{
    Meter vu;

    VuMeters();
    ~VuMeters();

    JUCE_LEAK_DETECTOR(VuMeters)
};

