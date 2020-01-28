
#include "BuildNewForm.h"

BuildNewForm::BuildNewForm(int i) 
{
    form.isVisible = true; //'form' is fully initialized here
    form.fields = i;
    Form f; //your Form::mainForm() wants another named instance of a Form passed to it
    form.mainForm(f); 
}

BuildNewForm::~BuildNewForm( )
{
    form.isVisible = false;
    std::cout << "\n\nDestructing Form.\n";
}
