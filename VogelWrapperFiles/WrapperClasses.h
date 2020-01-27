#pragma once
#include <iostream>

#include "../LeakedObjectDetector.h"

#include "../VogelHeaderFiles/StepSequencer.h"
#include "../VogelHeaderFiles/Form.h"
#include "../VogelHeaderFiles/Meter.h"

struct RandomSeq
{
    StepSequencer seq;
    RandomSeq() 
    {  
        seq.isProbabilistic = false;
        seq.isPlaying = false;
        seq.run(seq);
    } 

    ~RandomSeq()
    {
        std::cout << "\n Destructing Sequencer... \n";
        seq.saveWarning();
    }

    JUCE_LEAK_DETECTOR(RandomSeq)
};

struct BuildNewForm
{
    Form form;
    BuildNewForm(int i)
    {
        form.isVisible = true;
        form.fields = i;
        form.mainForm(form);
    }

    ~BuildNewForm( )
    {
        form.isVisible = false;
        std::cout << "\n\nDestructing Form.\n";
    }

    JUCE_LEAK_DETECTOR(BuildNewForm)
};

struct VuMeters
{
    Meter vu;

    VuMeters()
    {
        vu.vuMeterMain(vu);
    }

    ~VuMeters()
    {
         std::cout << "\n Destructing Meter Segments \n\n";
    }

    JUCE_LEAK_DETECTOR(VuMeters)
};

//wrapper class - constructs and destructs through pointer semantics
struct RandomSeqWrapper
{
    RandomSeqWrapper ( RandomSeq* ptr ) : pointerToRndSeq( ptr ) { }

    ~RandomSeqWrapper () 
    {
        delete pointerToRndSeq;
    }

    RandomSeq* pointerToRndSeq = nullptr;
};
//wrapper class - constructs and destructs through pointer semantics
struct BuildNewFormWrapper
{
    BuildNewFormWrapper ( BuildNewForm* ptr ) : pointerToBuildNewForm( ptr ) { }

    ~BuildNewFormWrapper () 
    {
        delete pointerToBuildNewForm;
    }

    BuildNewForm* pointerToBuildNewForm = nullptr;
};
//wrapper class - constructs and destructs through pointer semantics
struct VuMetersWrapper
{
    VuMetersWrapper ( VuMeters* ptr ) : pointerToVuMeters( ptr ) { }

    ~VuMetersWrapper () 
    {
        delete pointerToVuMeters;
    }

    VuMeters* pointerToVuMeters = nullptr;
};


