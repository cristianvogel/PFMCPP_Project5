#pragma once

#include "../LeakedObjectDetector.h"

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

