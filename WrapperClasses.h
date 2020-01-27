#pragma once

#include <iostream>

#include "LeakedObjectDetector.h"
#include "StepSequencer.h"
#include "Form.h"
#include "Meter.h"


struct RandomSeq
{
    StepSequencer seq;
    RandomSeq() THIS IS AN IMPLEMENTATION
    {  
        seq.isProbabilistic = false;
        seq.isPlaying = false;
        seq.run(seq);
    } 

    ~RandomSeq() THIS IS AN IMPLEMENTATION
    {
        std::cout << "\n Destructing Sequencer... \n";
        seq.saveWarning();
    }

    JUCE_LEAK_DETECTOR(RandomSeq)
};

struct BuildNewForm
{
    Form form;
    BuildNewForm(int i) THIS IS AN IMPLEMENTATION
    {
        form.isVisible = true;
        form.fields = i;
        form.mainForm(form);
    }

    ~BuildNewForm( ) THIS IS AN IMPLEMENTATION
    {
        form.isVisible = false;
        std::cout << "\n\nDestructing Form.\n";
    }

    JUCE_LEAK_DETECTOR(BuildNewForm)
};

struct VuMeters
{
    Meter vu;

    VuMeters() THIS IS AN IMPLEMENTATION
    {
        vu.vuMeterMain(vu);
    }

    ~VuMeters() THIS IS AN IMPLEMENTATION
    {
         std::cout << "\n Destructing Meter Segments \n\n";
    }

    JUCE_LEAK_DETECTOR(VuMeters)
};

//wrapper class - constructs and destructs through pointer semantics
struct RandomSeqWrapper
{
    RandomSeqWrapper ( RandomSeq* ptr ) : pointerToRndSeq( ptr ) { } THIS IS AN IMPLEMENTATION

    ~RandomSeqWrapper () THIS IS AN IMPLEMENTATION
    {
        delete pointerToRndSeq;
    }

    RandomSeq* pointerToRndSeq = nullptr;
};

//wrapper class - constructs and destructs through pointer semantics
struct BuildNewFormWrapper
{
    BuildNewFormWrapper ( BuildNewForm* ptr ) : pointerToBuildNewForm( ptr ) { } THIS IS AN IMPLEMENTATION

    ~BuildNewFormWrapper () THIS IS AN IMPLEMENTATION
    {
        delete pointerToBuildNewForm;
    }

    BuildNewForm* pointerToBuildNewForm = nullptr;
};

//wrapper class - constructs and destructs through pointer semantics
struct VuMetersWrapper
{
    VuMetersWrapper ( VuMeters* ptr ) : pointerToVuMeters( ptr ) { } THIS IS AN IMPLEMENTATION

    ~VuMetersWrapper () THIS IS AN IMPLEMENTATION
    {
        delete pointerToVuMeters;
    }

    VuMeters* pointerToVuMeters = nullptr;
};


