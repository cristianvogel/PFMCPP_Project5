#include "Form.h"

Form::Form() :
            isVisible ( true ),
            formID ( "UserName" ),
            fields ( 2 ),
            fullName ( TextField() ) 
{ } 

Form::Form(int nbrFields) :
            isVisible ( true ),
            formID ( "Fields" ),
            fields ( nbrFields ),
            fullName (  ) 
{ } 

Form::TextField::TextField() : 
                            x ( 80 ), y ( 160 ), w ( 400 ), h ( 90 ),
                            alpha ( 32 ),
                            fieldID ( "FullName" )
{ }

Form::~Form() 
{
    std::cout << "Form with " << fields << " fields Destructing...\n";
}

Form::CheckBox::CheckBox() { size = 16.0f; icon = "\u25A3"; } 
Form::CheckBox::CheckBox (float s) : size (s) {}

Form::CheckBox::~CheckBox()
{
    std::cout << "Destructing check box with icon " << icon << "\n";
}

std::string Form::getCBGlyph() { return this->fullName.checkBox.icon; }

std::string Form::getStatus( int selector ) 
{
    std::ostringstream status; 
    switch (selector)
    {
        case 0:
        status << (this->isVisible ? "visible" : "hidden"); break;
        case 1:
        status << this->fields ; break;
        case 2: 
        status << this->getCBGlyph(); break;
    }
    return status.str();
}

void Form::checkABox (CheckBox& )
{
    std::cout << this->fullName.checkBox.icon << " -> \u2713 \n";
    this->fullName.checkBox.isChecked = true;
}

void Form::print_IDs()
{
    std::cout << "FieldID ->  " << fullName.fieldID << "\nFormID ->  " << formID << "\nCheckBox icon ->  " << fullName.checkBox.icon << '\n';
}
  
bool Form::mouseOver (TextField) 
{
    //return true when mouse is over a certain field
    return {};
}

bool Form::CheckBox::animateCheckBox (std::string , CheckBox& check_box, float anim_time )
{
    /*
        do funky animation for a UDT CheckBox
        related to a UDT Field of a certain id
        of course this would be multi threaded or something not with a while loop!
    */
    float startingSize = check_box.size;
    float shrinkingSize = startingSize;
    std::string unicode = "\u2593\n";
    
    while ((check_box.isChecked) && (shrinkingSize > 0.01f)) 
    {
       shrinkingSize -= (anim_time/60.0f);
       if (shrinkingSize/startingSize < 0.75f) unicode = "\u2592\n";
       if (shrinkingSize/startingSize < 0.125f) unicode = "\u2591\n";  
       
       if (!check_box.isChecked) 
        {
            check_box.size = startingSize;
            return false;
        } // user changed their mind during animation
        
        std::cout << unicode; //draw the animation
    }; 
    return true; // vanished!
}

void Form::mainForm(Form& formData)
{
    std::cout << "Memory used by Form -> " << sizeof(Form) << " bytes \n" ;
    formData.print_IDs();
    formData.checkABox(formData.fullName.checkBox);
    formData.fullName.checkBox.animateCheckBox("name", formData.fullName.checkBox, 70.0f);
    std::cout << "\n";
}


