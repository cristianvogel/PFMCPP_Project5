#pragma once
#include "LeakedObjectDetector.h"
#include <iostream>
#include <sstream>

struct Form 
{ 
    bool isVisible;
    std::string formID;
    int fields;
    
    struct CheckBox
    {
        CheckBox();  
        CheckBox ( float ) ;
        ~CheckBox();

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

    TextField fullName;

    std::string getStatus( int selector_ ); 
    std::string getCBGlyph();
    void mainForm ( Form& );
    bool mouseOver(TextField fullName);
    void clearAllCheckBoxes ( Form );
    void checkABox( CheckBox& );
    void print_IDs();

    Form();
    Form( int );
    ~Form();

    JUCE_LEAK_DETECTOR(Form)
};
