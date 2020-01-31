#pragma once

#include <iostream>
#include <sstream>

struct StepSequencer
{
    struct StepData
    {
        struct PitchClass 
        {
            PitchClass(); 

            double frequency;
            char pitch;
            
            char pitchFromFreq (double);
        };

        int currentStage = { 1 };
        PitchClass stepPitchClass;
        char pitchClass = stepPitchClass.pitch;
        bool gateStatus = true;       
        double duration = 1.0;

        StepData(); //Declaration of Constructor
        ~StepData(); //Declaration of destructor
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
    std::string getStatus( int selector ); 

    StepSequencer();
    ~StepSequencer();
};

