#pragma once

#include <sstream> // for string stream

struct Form 
{ 
    bool isVisible;
    std::string formID;
    int fields;
    
    struct CheckBox
    {
        CheckBox()
        {
            size = 16.0f;
            icon = "\u25A3";           
        }

        CheckBox (float s) : size (s) {}

        ~CheckBox()
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

    std::string getStatus( int selector ) 
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
    
    std::string getCBGlyph() { return this->fullName.checkBox.icon; }
    void mainForm(Form& );
    bool mouseOver (TextField fullName);
    void clearAllCheckBoxes (Form f);
    void checkABox (CheckBox& )
    {
        std::cout << this->fullName.checkBox.icon << " -> \u2713 \n";
        this->fullName.checkBox.isChecked = true;
    }
    void print_IDs()
    {
         std::cout << "FieldID ->  " << fullName.fieldID << "\nFormID ->  " << formID << "\nCheckBox icon ->  " << fullName.checkBox.icon << '\n';
    }

    Form();
    Form(int );

    ~Form();

};

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


