#pragma once
// or 
// #ifndef Meter_H
// #define Meter_H

#include <sstream> // for string stream 'ostream'

struct Meter
{
    Meter()
    {
        meterID = 1; peakHold = true;
        colourPallette = 'a';
        slewRise = 0.1f; slewFall = 0.1f;
    }

    int meterID;
    bool peakHold;
    char colourPallette;
    float slewRise, slewFall;
    bool isVisible = {true};

    struct HorizontalMeter 
    {   
        int w,h,x,y;
        std::string label {"HorizontalMeter"};
        float scaleFactor = {0.5f};
        int numberOfSegments =  {32};
        

        struct Segment
        {
            int segmentIndex;
            float opacity;
            bool activeStatus;
            float fadeFactor;

            void fadeOut();
            void draw (int , float );
                       
            Segment(); 

            ~Segment()
            {
                segmentIndex = -1; activeStatus = false;
                fadeOut();
                std::cout << "\n";
            }

        };

        Segment m_Segment { } ; // Segment of 

        void updateSegment (int meterID, Segment s);
    };

    std::string getStatus( int selector ) 
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

    void vuMeterMain(Meter& );

    HorizontalMeter vumeterType1 { 30, 20, 10, 150, "H_Type1" };   
    HorizontalMeter vumeterType2 { 30, 40, 10, 150, "H_Type2" }; 

    float segmentOpacity() { return (this->vumeterType1.m_Segment.opacity); }
};

//Constructor
Meter::HorizontalMeter::Segment::Segment() :
                                        segmentIndex ( 0 ),
                                        opacity ( 0.9f ),
                                        activeStatus ( true ),
                                        fadeFactor ( 0.001f )
{}

// #endif
