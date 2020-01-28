#include <iostream>
#include "WrapperClasses.h"


BuildNewFormWrapper::BuildNewFormWrapper ( BuildNewForm* ptr ) : pointerToBuildNewForm( ptr ) {} 
BuildNewFormWrapper::~BuildNewFormWrapper () { delete pointerToBuildNewForm; }

RandomSeqWrapper::RandomSeqWrapper ( RandomSeq* ptr ) : pointerToRndSeq( ptr ) {} 
RandomSeqWrapper::~RandomSeqWrapper() { delete pointerToRndSeq; }

VuMetersWrapper::VuMetersWrapper ( VuMeters* ptr ) : pointerToVuMeters( ptr ) {} 
VuMetersWrapper::~VuMetersWrapper () { delete pointerToVuMeters; }
