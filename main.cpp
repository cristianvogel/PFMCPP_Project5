/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

 Destructors
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 6) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 copied UDT 1:
 */
#include <iostream>
#include <random>
#include <ctime>

//namespace FormTask
struct Form 
{
    bool isVisible;
    std::string formID;
    int fields;
    
    struct CheckBox
    {
        CheckBox()
        {
            size = 16.0f;
            icon = "\u2593";           
        }

        CheckBox (float s) : size (s) {}

        ~CheckBox()
        {
          std::cout << "Destructing check box with icon " << icon << "\n";
        }

        bool isChecked { false };
        bool isVisible { true };
        float size;
        std::string icon;

        //lifetime task func...
        bool animateCheckBox (std::string fieldID, CheckBox& c, float animationTime); 
    };

    struct TextField 
    { 
        float x,y,w,h;
        int alpha;
        std::string fieldID;
        CheckBox checkBox;

        TextField(); 
    };

    //CheckBox checkBox;
    /*
    Didn't need this extra CheckBox object in Form:: scope
    accessed nested CheckBox class through TextField fullName 
    which owns a CheckBox called checkBox
    */
    TextField fullName;

    void mainForm(Form& );
    bool mouseOver (TextField fullName);
    void clearAllCheckBoxes (Form f);
    void checkABox (CheckBox& )
    {
        std::cout << this->fullName.checkBox.icon << " -> \u2713 \n";
        this->fullName.checkBox.isChecked = true;
    }
    void print_IDs()
    {
         std::cout << "FieldID ->  " << fullName.fieldID << "\nFormID ->  " << formID << "\nCheckBox icon ->  " << fullName.checkBox.icon << '\n';
    }

    Form();
    Form(int );

    ~Form();
};
Form::Form() :
            isVisible ( true ),
            formID ( "UserName" ),
            fields ( 2 ),
            fullName ( TextField() ) 
{ } 

Form::Form(int nbrFields) :
            isVisible ( true ),
            formID ( "Fields" ),
            fields ( nbrFields ),
            fullName (  ) 
{ } 

Form::TextField::TextField() : 
                            x ( 80 ), y ( 160 ), w ( 400 ), h ( 90 ),
                            alpha ( 32 ),
                            fieldID ( "FullName" )
{ }

Form::~Form() 
{
std::cout << "\nForm with " << fields << " fields Destructing...\n";
}

//Implementations 4
bool Form::mouseOver (TextField) 
{
    //return true when mouse is over a certain field
    return {};
}

bool Form::CheckBox::animateCheckBox (std::string , CheckBox& check_box, float anim_time )
{
    /*
        do funky animation for a UDT CheckBox
        related to a UDT Field of a certain id
        of course this would be multi threaded or something not with a while loop!
    */
    float startingSize = check_box.size;
    float shrinkingSize = startingSize;
    std::string unicode = "\u2593\n";
    
    while ((check_box.isChecked) && (shrinkingSize > 0.01f)) 
    {
       shrinkingSize -= (anim_time/60.0f);
       if (shrinkingSize/startingSize < 0.75f) unicode = "\u2592\n";
       if (shrinkingSize/startingSize < 0.125f) unicode = "\u2591\n";  
       
       if (!check_box.isChecked) 
        {
            check_box.size = startingSize;
            return false;
        } // user changed their mind during animation
        
        std::cout << unicode; //draw the animation
    }; 
    return true; // vanished!
}

void Form::mainForm(Form& formData)
{
    std::cout << "Memory used by Form -> " << sizeof(Form) << " bytes \n" ;
    formData.print_IDs();
    formData.checkABox(formData.fullName.checkBox);
    formData.fullName.checkBox.animateCheckBox("name", formData.fullName.checkBox, 55.0f);
    std::cout << "\n";
}

/*
 copied UDT 2:
 */
namespace MetersTask
{ 
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

    struct HorizontalMeter 
    {   
        int w,h,x,y;
        float scaleFactor = {0.5f};
        int numberOfSegments = {32};

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
            }

        };

        Segment m_Segment { } ; // Segment of 

        void updateSegment (int meterID, Segment s);
    };

    HorizontalMeter vumeterType1 { 30, 20, 10, 150 };   
    HorizontalMeter vumeterType2 { 30, 40, 10, 150 }; 
};
Meter::HorizontalMeter::Segment::Segment() :
                                        segmentIndex ( 0 ),
                                        opacity ( 1.f ),
                                        activeStatus ( true ),
                                        fadeFactor ( 0.001f )
{}
//Implementation 9
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
    std::string unicode = "\u2593";
    while (local_opacity > 0.1f) 
    {
        local_opacity -= (anim_time/60.0f);
        if (local_opacity/starts < 0.75f) unicode = "\u2592";
        if (local_opacity/starts < 0.25f) unicode = "\u2591";          
        std::cout << unicode; //draw the animation
    }; 
    std::cout << "\n" << std::endl;
}

int main() 
{
    Meter vu;

    std::cout << "Memory used by Meter -> " << sizeof(Meter) << " bytes\n"
    << "VuMeter1 x y w h ->  " << vu.vumeterType1.x << "," << vu.vumeterType1.y
    << "," << vu.vumeterType1.w <<  "," << vu.vumeterType1.h << "\n"
    << "VuMeter2 x y w h ->  " << vu.vumeterType2.x << "," << vu.vumeterType2.y
    << "," << vu.vumeterType2.w <<  "," << vu.vumeterType2.h 
    << "\nDestructor fades out segments -> \n"; 
    std::cout << "\n";
    return 0;
}
}

/*
 copied UDT 3:
 */
//namespace SequencerTask
 
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
            std::cout << "\u2612";
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
        std::cout << "Press return to save sequencer.. ";
        std::cin.get();
        std::cout << "...saved! Quitting...";
        // saveToDisk function here
    }

    StepSequencer();
};
//Out of Class Constructors
StepSequencer::StepData::StepData() : //Definition of Constructor
                                currentStage ( 0 ),
                                gateStatus ( true ),
                                duration ( 1.0 )                            
{ 
    std::cout << "\u2610";
}

StepSequencer::StepSequencer() :
                                isPlaying ( false ),
                                numberOfSteps ( 8 ),
                                tempo ( 120 ),
                                id ( 1 ),   
                                isBackwards ( false )
{ std::cout << "Sequencer defined..."; }

//Implementations 10
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
    for (int i=48; i>1; --i) 
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
    }
}

void StepSequencer::doSomethingWithStepData()
{
    // probably make a beep
    std::cout << " \u266A ";
}

void StepSequencer::run(StepSequencer& s1 )
{
    std::cout << "Memory used by Step Sequencer -> " << sizeof(StepSequencer) << " bytes \n"
    << "Stage Pitch Class -> " << s1.pitchClass << "\n"
    << "Sequencer type is -> " << (s1.isProbabilistic ? "probabilistic" : "normal")
    << "\n\u2610 = Constructing \u2612 = Destructing\n\n"
    << "Press Return to Play\n";
    std::cin.get(); 

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

/*
 new UDT 4:
 */
struct RandomSeq
{
    StepSequencer seq;

    RandomSeq() 
    {  
        seq.isProbabilistic = false;
        seq.isPlaying = false;
        seq.run(seq);
    } 

    ~RandomSeq()
    {
        seq.saveWarning();
    }
};


/*
 new UDT 5:
 */
struct BuildNewForm
{
    Form form;

    BuildNewForm(int i)
    {
        form.isVisible = true;
        form.fields = i;
        form.mainForm(form);
    }

    ~BuildNewForm( )
    {
        form.isVisible = false;
        std::cout << "\nForm vanished.\n";
    }
};



void br()
{
    std::cout <<  "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n"; 
}

int main()
{
    br();
    BuildNewForm formWithFields(3);
    br();
    //  MetersTask::main();
    br();
    RandomSeq rs;
    br();
    std::cout << "good to go!" << std::endl;
}
