#pragma once

#include "LeakedObjectDetector.h"
#include "StepSequencer.h"

struct RandomSeq
{
    StepSequencer seq;
    
    RandomSeq();
    ~RandomSeq();

    JUCE_LEAK_DETECTOR(RandomSeq)
};
