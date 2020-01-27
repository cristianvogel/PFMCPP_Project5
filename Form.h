#pragma once

#include <sstream> // for string stream

struct Form 
{ 
    bool isVisible;
    std::string formID;
    int fields;
    
    struct CheckBox
    {
        bool isChecked { false };
        bool isVisible { true };
        float size;
        std::string icon;

        //lifetime task func...
        bool animateCheckBox (std::string fieldID, CheckBox& c, float animationTime); 

        CheckBox();
        CheckBox( float );
        ~CheckBox();
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
   
    void mainForm( Form& );
    bool mouseOver ( TextField );
    void clearAllCheckBoxes ( Form );
    std::string getStatus( int );
    std::string getCBGlyph();
    void checkABox(CheckBox& );
    void print_IDs();

    Form();
    Form( int );

    ~Form();

};




