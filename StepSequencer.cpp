#include <iostream>
#include <ctime>        //for random seeding
#include <random>       //for random

#include "StepSequencer.h"

//Implementations 
void StepSequencer::saveWarning()  //THIS IS AN IMPLEMENTATION
{
    std::cout << "\x1B[7mType 'Y' to save sequencer.. \033[0m" << std::endl;
    int saveFlag {};
    std::cin >> saveFlag;
    // saveToDisk function here
    std::cout << "...saved! Quitting...";
}

std::string StepSequencer::getSeqTypeAsString()  //THIS IS AN IMPLEMENTATION
{ 
    return (this->isProbabilistic ? "probabilistic" : "normal"); 
}

std::string StepSequencer::getStatus( int selector ) //THIS IS AN IMPLEMENTATION
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

int StepSequencer::step() 
{
    int localStepSize;
    localStepSize = (isBackwards) ? -1 : 1;
    int local_currentStage = currentStage;

    if (isPlaying) 
    {       
        local_currentStage += localStepSize;
        if (local_currentStage < 0) local_currentStage = numberOfSteps-1;
        local_currentStage = local_currentStage % numberOfSteps;
    }
    else local_currentStage = 0;
    
    //Instance of StepData created here is destructed at the end of this scope
    StepData currentStageData = interpretStageData (currentStage);
    
    doSomethingWithStepData();

    //if gate stage is on update member variable stage position else hold prev 
    if (currentStageData.gateStatus) return local_currentStage;
    else                             return currentStage;
}

char StepSequencer::StepData::PitchClass::pitchFromFreq (double)
{
    //here we would actually calculate the pitch class with precision and grace
    char result = 'A';
    return result;
}
StepSequencer::StepData StepSequencer::interpretStageData( int stageNum ) 
{
    // get all current StepData return in a StepData UDT 
    StepData sd;
    sd.currentStage = stageNum;

    sd.gateStatus = isProbabilistic ? (std::rand()%10)<5 // probabilistic gate status
                                    : true;

    sd.stepPitchClass.pitch = 'A'; 
    
    return sd;
}
int StepSequencer::getCurrentStage(unsigned int)
{
    //get stage number of current row with an ID
    return {};
}

void StepSequencer::play( StepSequencer& seq)
{
    (seq.isProbabilistic) ? seq.playEitherWay(seq) : seq.playNormal(seq);
}

void StepSequencer::playNormal(StepSequencer& seq)
{
    seq.isPlaying = true;
    seq.isProbabilistic = false;
    std::string playSign = "";
    //play 48 steps of normal sequencer
    for (int i=48; i>1; --i) 
    {
        playSign = " \u21E8 ";
        std::cout << playSign << " " << seq.currentStage << " ";
        seq.currentStage = seq.step();
    }
}

void StepSequencer::playEitherWay(StepSequencer& seq)
{
    seq.isPlaying = true;
    seq.isProbabilistic = true;
    std::srand(static_cast<unsigned int>(std::time(nullptr))); //initialise biased PRNG
    int randomInt = 0;
    std::string playSign = "";

    //play 48 steps of an either-way probabilistic sequencer
    for (int i=48; i>-1; --i) 
    {
        playSign = " \u21E8 ";
        randomInt = static_cast<int>(std::rand()%10);
        // 50% chance of flipping direction...
        if (randomInt < 4) 
        {
            seq.isBackwards = !seq.isBackwards;
            playSign = " \u21E6 ";
        }
        std::cout << playSign << " " << seq.currentStage << " ";
        seq.currentStage = seq.step( );
        if (i==0) seq.isPlaying = false;
    }
}

void StepSequencer::doSomethingWithStepData()
{
    // probably make a beep
    std::cout << " \u266A ";
}

StepSequencer::StepData::~StepData()
{
    std::cout << "\x1B[33m\u2612\033[0m";
}

void StepSequencer::run(StepSequencer& s1 )
{
    std::cout << "Memory used by Step Sequencer -> " << sizeof(StepSequencer) << " bytes \n"
    << "Stage Pitch Class -> " << s1.pitchClass << "\n"
    << "Sequencer type is -> " << (s1.isProbabilistic ? "probabilistic" : "normal")
    << "\n\x1B[33m\u2610 = Constructing \u2612 = Destructing\n"
    << "\n\x1B[32mType [0] Normal [1] Probabilistic followed by \x1B[7mReturn to Play\n\033[0m";
    std::cin >> s1.isProbabilistic; 
    
    if (!s1.isProbabilistic)
    {
        std::cout << "\nStarting normal sequencer -> \n";
        s1.playNormal(s1);
    } 
    else 
    {
        std::cout << "\nStarting probabilistic sequencer -> \n";
        s1.playEitherWay(s1);
    }
}

