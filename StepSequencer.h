#pragma once

#include <sstream> // for string stream
#include <cassert>
#include "LeakedObjectDetector.h"

struct StepSequencer
{
    struct StepData
    {
        /** 
        I don't think PitchClass should be a nested nested struct anymore
        makes things difficult without proper member access privelages
        but leaving as is for now....
        **/
        struct PitchClass 
        {     
            double frequency;
            char pitch;
            
            char pitchFromFreq (double);

            PitchClass();
        };
        
        int currentStage = { 1 };

        PitchClass stepPitchClass;

        char pitchClass = stepPitchClass.pitch;
        bool gateStatus = true;       
        double duration = 1.0;

        StepData(); //Declaration of Constructor
        ~StepData();

    };

    int getCurrentStage (unsigned int id);
    
    StepData interpretStageData (int );

    bool isPlaying;
    int numberOfSteps;
    double tempo;
    unsigned int id;
    char pitchClass { 'A' }; 
    int currentStage { 0 };
    bool isBackwards, isProbabilistic ;

    int step();
    void playEitherWay ( StepSequencer& );
    void playNormal (StepSequencer& );
    void run (StepSequencer&);
    void play (StepSequencer&);
    void doSomethingWithStepData();

    void saveWarning();
    std::string getSeqTypeAsString();
    std::string getStatus( int );

    StepSequencer();
    ~StepSequencer();
};


struct RandomSeq
{
    StepSequencer seq;
    RandomSeq();
    ~RandomSeq();

    JUCE_LEAK_DETECTOR( RandomSeq )
};




