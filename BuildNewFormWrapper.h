#pragma once

//fwd declaration 
struct BuildNewForm;

//wrapper class - constructs and destructs through pointer semantics
struct BuildNewFormWrapper
{
    BuildNewFormWrapper ( BuildNewForm*  );
    ~BuildNewFormWrapper ();

    BuildNewForm* pointerToBuildNewForm = nullptr;
};
