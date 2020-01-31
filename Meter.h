#pragma once

#include <iostream>
#include <sstream>

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

        Segment m_Segment {} ; 

        void updateSegment (int meterID, Segment s);
    };

    std::string getStatus( int selector );
    void vuMeterMain(Meter& );
    float segmentOpacity();

    HorizontalMeter vumeterType1 { 30, 20, 10, 150, "H_Type1" };   
    HorizontalMeter vumeterType2 { 30, 40, 10, 150, "H_Type2" }; 
};

