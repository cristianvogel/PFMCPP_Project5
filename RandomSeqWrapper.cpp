#include "RandomSeqWrapper.h"
#include "RandomSeq.h"

RandomSeqWrapper::RandomSeqWrapper ( RandomSeq* ptr ) : pointerToRndSeq( ptr ) { }
RandomSeqWrapper::~RandomSeqWrapper () { delete pointerToRndSeq; }

