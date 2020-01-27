#include <iostream>
#include "Meter.h"

//Implementations moved from In-Class
//THIS IS AN IMPLEMENTATION
Meter::Meter() : 
            meterID (1), peakHold  (true),
            colourPallette ('a'),
            slewRise (0.1f), slewFall  (0.1f)
{}

Meter::HorizontalMeter::Segment::~Segment() //THIS IS AN IMPLEMENTATION
            {
                segmentIndex = -1; activeStatus = false;
                fadeOut();
                std::cout << "\n";
            }
std::string Meter::getStatus( int selector )  //THIS IS AN IMPLEMENTATION
    {
        std::ostringstream status;
        switch (selector)
        {
            case 0:
                status << (this->isVisible ? "visible" : "hidden"); break;
            case 1:
                status << this->vumeterType1.label; break;
            case 2: 
                status << this->segmentOpacity(); break;
        }
        return status.str();
    }
float Meter::segmentOpacity() 
{ 
    return (this->vumeterType1.m_Segment.opacity); 
}
Meter::HorizontalMeter::Segment::Segment() : //THIS IS AN IMPLEMENTATION
                                        segmentIndex ( 0 ),
                                        opacity ( 0.9f ),
                                        activeStatus ( true ),
                                        fadeFactor ( 0.001f )
{}



void Meter::HorizontalMeter::updateSegment (int, Meter::HorizontalMeter::Segment)
{
    //update segment graphics style
}
void Meter::HorizontalMeter::Segment::draw (int , float )
{   
    // arguments segmentIndex, opacity
    // redraw an instance of a Segment UDT
}
void Meter::HorizontalMeter::Segment::fadeOut()
{
     //executes when removing an instance of a Segment UDT from memory 
     
    float anim_time = 3.0f;
    float starts = opacity;
    float local_opacity = starts;
    std::string unicode = "\x1B[33m\u2593";
    while (local_opacity > 0.1f) 
    {
        local_opacity -= (anim_time/60.0f);
        if (local_opacity/starts < 0.75f) unicode = "\u2592";
        if (local_opacity/starts < 0.25f) unicode = "\u2591";          
        std::cout << unicode; //draw the animation
        this->opacity=local_opacity;
    }; 
    std::cout << "\033[0m"; //  ANSI Esc code reset
}

void Meter::vuMeterMain(Meter & vu)
{
   // Meter vu;

    std::cout << "Memory used by Meter -> " << sizeof(Meter) << " bytes\n"
    << "VuMeter1 x y w h ->  " << vu.vumeterType1.x << "," << vu.vumeterType1.y
    << "," << vu.vumeterType1.w <<  "," << vu.vumeterType1.h << "\n"
    << "VuMeter2 x y w h ->  " << vu.vumeterType2.x << "," << vu.vumeterType2.y
    << "," << vu.vumeterType2.w <<  "," << vu.vumeterType2.h 
    << "\nSegment destructor fades out graphics -> \n"; 
    std::cout << "\n";   
} 
