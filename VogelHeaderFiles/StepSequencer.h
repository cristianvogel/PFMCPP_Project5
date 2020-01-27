#pragma once

struct StepSequencer
{
    struct StepData
    {
        struct PitchClass 
        // I don't think PitchClass should be a nested nested struct anymore
        // makes things difficult without proper member access privelages
        // but leaving as is for now....
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
    
    //StepData stepData;
    StepData interpretStageData (int );

    bool isPlaying;
    int numberOfSteps;
    double tempo;
    unsigned int id;
    /**
    char pitchClass { stepData.pitchClass }; 
    int currentStage { stepData.currentStage };
    **/
    char pitchClass { 'A' }; 
    int currentStage { 0 };
    bool isBackwards, isProbabilistic ;

    int step();
    void playEitherWay ( StepSequencer& );
    void playNormal (StepSequencer& );
    void run (StepSequencer&);
    void play (StepSequencer&);
    void doSomethingWithStepData();
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
        std::ostringstream status;
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