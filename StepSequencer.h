#pragma once

#include <sstream> // for string stream

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
            PitchClass() //THIS IS AN IMPLEMENTATION
            {
                frequency = 440;
               //TODO: pitch = pitchFromFreq (frequency);
                pitch = 'A';
            }
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

//Constructors
//THIS IS AN IMPLEMENTATION
StepSequencer::StepData::StepData() : 
                                currentStage ( 0 ),
                                gateStatus ( true ),
                                duration ( 1.0 )                            
{ 
    std::cout << "\x1B[33m\u2610\033[0m";
}
//THIS IS AN IMPLEMENTATION
StepSequencer::StepSequencer() : 
                                isPlaying ( false ),
                                numberOfSteps ( 8 ),
                                tempo ( 120 ),
                                id ( 1 ),   
                                isBackwards ( false )
{ 
    std::cout << "Sequencer defined..."; 
}

