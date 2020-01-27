#include <iostream>
#include "WrapperClasses.h"

RandomSeq::RandomSeq() //THIS IS AN IMPLEMENTATION
{  
    seq.isProbabilistic = false;
    seq.isPlaying = false;
    seq.run(seq);
} 

RandomSeq::~RandomSeq() //THIS IS AN IMPLEMENTATION
{
    std::cout << "\n Destructing Sequencer... \n";
    seq.saveWarning();
}

BuildNewForm::BuildNewForm(int i)
{
    form.isVisible = true;
    form.fields = i;
    form.mainForm(form);
}

BuildNewForm::~BuildNewForm( ) //THIS IS AN IMPLEMENTATION
{
    form.isVisible = false;
    std::cout << "\n\nDestructing Form.\n";
}

VuMeters::VuMeters() //THIS IS AN IMPLEMENTATION
{
    vu.vuMeterMain(vu);
}

VuMeters::~VuMeters() //THIS IS AN IMPLEMENTATION
{
    std::cout << "\n Destructing Meter Segments \n\n";
}
