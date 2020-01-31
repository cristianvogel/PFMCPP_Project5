#pragma once

#include <iostream>
#include <sstream>

struct Meter
{
    Meter();

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
            ~Segment();
        };

        Segment m_Segment {} ; 

        void updateSegment (int meterID, Segment s);
    };

    std::string getStatus( int selector );
    void vuMeterMain(Meter& );
    float segmentOpacity();

    HorizontalMeter vumeterType1 { 30, 20, 10, 150, "H_Type1" };   
    HorizontalMeter vumeterType2 { 30, 40, 10, 150, "H_Type2" }; 
};

