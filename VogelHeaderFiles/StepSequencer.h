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
            PitchClass()
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
        ~StepData() //Declaration ***AND*** Definition of Destructor
        {
            std::cout << "\x1B[33m\u2612\033[0m";
        }
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

    //TO-DO: In-Class definitions need to get moved out for this task...
    void saveWarning() 
    {
        std::cout << "\x1B[7mType 'Y' to save sequencer.. \033[0m" << std::endl;
        int saveFlag {};
        std::cin >> saveFlag;
        // saveToDisk function here
        std::cout << "...saved! Quitting...";
    }

    std::string getSeqTypeAsString() 
    { 
        return (this->isProbabilistic ? "probabilistic" : "normal"); 
    }

    std::string getStatus( int selector ) 
    {
        std::ostringstream status; //implicitly defined error??
        switch (selector)
        {
            case 0:
                status << (this->isPlaying ? "playing" : "stopped"); break;
            case 1:
                status << this->numberOfSteps ; break;
            case 2: 
                status << this->getSeqTypeAsString(); break;
        }
        return status.str();
    }

    StepSequencer();
};

//Constructors
StepSequencer::StepData::StepData() : //Definition of Constructor
                                currentStage ( 0 ),
                                gateStatus ( true ),
                                duration ( 1.0 )                            
{ 
    std::cout << "\x1B[33m\u2610\033[0m";
}

StepSequencer::StepSequencer() :
                                isPlaying ( false ),
                                numberOfSteps ( 8 ),
                                tempo ( 120 ),
                                id ( 1 ),   
                                isBackwards ( false )
{ std::cout << "Sequencer defined..."; }

