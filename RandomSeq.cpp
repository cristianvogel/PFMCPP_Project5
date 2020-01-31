#include "RandomSeq.h"
    
RandomSeq::RandomSeq() 
{  
    seq.isProbabilistic = false;
    seq.isPlaying = false;
    seq.run(seq);
} 

RandomSeq::~RandomSeq()
{
    std::cout << "\n Destructing Sequencer... \n";
    seq.saveWarning();
}
