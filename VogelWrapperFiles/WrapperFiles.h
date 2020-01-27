#pragma once

#include "WrappedInterfaces.h"

//wrapper class - constructs and destructs through pointer semantics
struct RandomSeqWrapper
{
    RandomSeqWrapper ( RandomSeq* ptr ) : pointerToRndSeq( ptr ) { }

    ~RandomSeqWrapper () 
    {
        delete pointerToRndSeq;
    }

    RandomSeq* pointerToRndSeq = nullptr;
};
//wrapper class - constructs and destructs through pointer semantics
struct BuildNewFormWrapper
{
    BuildNewFormWrapper ( BuildNewForm* ptr ) : pointerToBuildNewForm( ptr ) { }

    ~BuildNewFormWrapper () 
    {
        delete pointerToBuildNewForm;
    }

    BuildNewForm* pointerToBuildNewForm = nullptr;
};
//wrapper class - constructs and destructs through pointer semantics
struct VuMetersWrapper
{
    VuMetersWrapper ( VuMeters* ptr ) : pointerToVuMeters( ptr ) { }

    ~VuMetersWrapper () 
    {
        delete pointerToVuMeters;
    }

    VuMeters* pointerToVuMeters = nullptr;
};

