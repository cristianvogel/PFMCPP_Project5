#include "BuildNewForm.h"

BuildNewForm::BuildNewForm(int i)
{
    form.isVisible = true;
    form.fields = i;
    form.mainForm(form);
}

BuildNewForm::~BuildNewForm( )
    {
        form.isVisible = false;
        std::cout << "\n\nDestructing Form.\n";
    }

