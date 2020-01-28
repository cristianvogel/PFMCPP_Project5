#pragma once

#include <iostream>

#include "LeakedObjectDetector.h"
#include "StepSequencer.h"
#include "Form.h"
#include "Meter.h"

struct RandomSeq
{
    StepSequencer seq;
    RandomSeq();
    ~RandomSeq();

    JUCE_LEAK_DETECTOR(RandomSeq)
};

struct BuildNewForm
{
    Form form;

    BuildNewForm(int i);
    ~BuildNewForm();

    JUCE_LEAK_DETECTOR(BuildNewForm)
};

struct VuMeters
{
    Meter vu;

    VuMeters();
    ~VuMeters();

    JUCE_LEAK_DETECTOR(VuMeters)
};

//wrapper class - constructs and destructs through pointer semantics
struct RandomSeqWrapper
{
    //THIS IS AN IMPLEMENTATION
    RandomSeqWrapper ( RandomSeq* ptr ) : pointerToRndSeq( ptr ) { } 

    ~RandomSeqWrapper () //THIS IS AN IMPLEMENTATION
    {
        delete pointerToRndSeq;
    }

    RandomSeq* pointerToRndSeq = nullptr;
};

//wrapper class - constructs and destructs through pointer semantics
struct BuildNewFormWrapper
{
    BuildNewFormWrapper ( BuildNewForm* ptr ) : pointerToBuildNewForm( ptr ) { } //THIS IS AN IMPLEMENTATION

    ~BuildNewFormWrapper () //THIS IS AN IMPLEMENTATION
    {
        delete pointerToBuildNewForm;
    }

    BuildNewForm* pointerToBuildNewForm = nullptr;
};

//wrapper class - constructs and destructs through pointer semantics
struct VuMetersWrapper
{
    VuMetersWrapper ( VuMeters* ptr ) : pointerToVuMeters( ptr ) { } //THIS IS AN IMPLEMENTATION

    ~VuMetersWrapper () //THIS IS AN IMPLEMENTATION
    {
        delete pointerToVuMeters;
    }

    VuMeters* pointerToVuMeters = nullptr;
};


