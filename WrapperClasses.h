#pragma once

#include <iostream>

struct BuildNewForm;
struct RandomSeq;
struct VuMeters;

//wrapper class - constructs and destructs through pointer semantics
struct RandomSeqWrapper
{
    RandomSeqWrapper( RandomSeq* );
    ~RandomSeqWrapper();

    RandomSeq* pointerToRndSeq = nullptr;
};

//wrapper class - constructs and destructs through pointer semantics
struct BuildNewFormWrapper
{    
    BuildNewFormWrapper( BuildNewForm* ptr );
    ~BuildNewFormWrapper();

    BuildNewForm* pointerToBuildNewForm = nullptr;
};

//wrapper class - constructs and destructs through pointer semantics
struct VuMetersWrapper
{   
    VuMetersWrapper ( VuMeters* ptr );
    ~VuMetersWrapper();
    
    VuMeters* pointerToVuMeters = nullptr;
};

