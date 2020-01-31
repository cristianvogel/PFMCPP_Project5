#include "BuildNewFormWrapper.h"
#include "BuildNewForm.h"

BuildNewFormWrapper::BuildNewFormWrapper ( BuildNewForm* ptr ) : pointerToBuildNewForm( ptr ) { }
BuildNewFormWrapper::~BuildNewFormWrapper() { delete pointerToBuildNewForm; }
