#include "VuMetersWrapper.h"
#include "VuMeters.h"

VuMetersWrapper::VuMetersWrapper ( VuMeters* ptr ) : pointerToVuMeters( ptr ) { }
VuMetersWrapper::~VuMetersWrapper () 
{ delete pointerToVuMeters; }
