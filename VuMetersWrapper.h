#pragma once

//Fwd Declaration
struct VuMeters;

//wrapper class - constructs and destructs through pointer semantics
struct VuMetersWrapper
{
    VuMetersWrapper ( VuMeters* ptr );
    ~VuMetersWrapper();
    
    VuMeters* pointerToVuMeters = nullptr;
};

