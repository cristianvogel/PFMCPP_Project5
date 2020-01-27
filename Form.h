#pragma once

#include <sstream> // for string stream

struct Form 
{ 
    bool isVisible;
    std::string formID;
    int fields;
    
    struct CheckBox
    {
        CheckBox()          HERE
        {                   HERE
            size = 16.0f;   HERE
            icon = "\u25A3"; HERE       
        }                   HERE

        CheckBox (float s) : size (s) {} THIS IS AN IMPLEMENTATION

        ~CheckBox() THIS IS AN IMPLEMENTATION
        {
          std::cout << "Destructing check box with icon " << icon << "\n";
        }

        bool isChecked { false };
        bool isVisible { true };
        float size;
        std::string icon;

        //lifetime task func...
        bool animateCheckBox (std::string fieldID, CheckBox& c, float animationTime); 
    };

    struct TextField 
    { 
        float x,y,w,h;
        int alpha;
        std::string fieldID;
        CheckBox checkBox;

        TextField(); 
    };

    //CheckBox checkBox;
    /*
    Didn't need this extra CheckBox object in Form:: scope
    accessed nested CheckBox class through TextField fullName 
    which owns a CheckBox called checkBox
    */
    TextField fullName;

    std::string getStatus( int selector )  THIS IS AN IMPLEMENTATION
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
    
    std::string getCBGlyph() { return this->fullName.checkBox.icon; } THIS IS AN IMPLEMENTATION
    void mainForm(Form& );
    bool mouseOver (TextField fullName);
    void clearAllCheckBoxes (Form f);
    void checkABox (CheckBox& ) THIS IS AN IMPLEMENTATION
    {
        std::cout << this->fullName.checkBox.icon << " -> \u2713 \n";
        this->fullName.checkBox.isChecked = true;
    }
    void print_IDs() THIS IS AN IMPLEMENTATION
    {
         std::cout << "FieldID ->  " << fullName.fieldID << "\nFormID ->  " << formID << "\nCheckBox icon ->  " << fullName.checkBox.icon << '\n';
    }

    Form();
    Form(int );

    ~Form();

};

Form::Form() : THIS IS AN IMPLEMENTATION
            isVisible ( true ),
            formID ( "UserName" ),
            fields ( 2 ),
            fullName ( TextField() ) 
{ } 

Form::Form(int nbrFields) : THIS IS AN IMPLEMENTATION
            isVisible ( true ),
            formID ( "Fields" ),
            fields ( nbrFields ),
            fullName (  ) 
{ } 

Form::TextField::TextField() :  THIS IS AN IMPLEMENTATION
                            x ( 80 ), y ( 160 ), w ( 400 ), h ( 90 ),
                            alpha ( 32 ),
                            fieldID ( "FullName" )
{ }

Form::~Form()  THIS IS AN IMPLEMENTATION
{
    std::cout << "Form with " << fields << " fields Destructing...\n";
}


