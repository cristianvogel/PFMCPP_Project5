#include "Form.h"
#include "LeakedObjectDetector.h"

struct BuildNewForm
{
    Form form;

    BuildNewForm(int i);
    ~BuildNewForm();

    JUCE_LEAK_DETECTOR( BuildNewForm )
};
