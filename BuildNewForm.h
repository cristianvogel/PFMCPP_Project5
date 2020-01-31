#pragma once

#include "LeakedObjectDetector.h"
#include "Form.h"

struct BuildNewForm
{
    Form form;

    BuildNewForm(int i);
    ~BuildNewForm();

    JUCE_LEAK_DETECTOR(BuildNewForm)
};

