#pragma once

//fwd declaration 
struct RandomSeq;

//wrapper class - constructs and destructs through pointer semantics
struct RandomSeqWrapper
{
    RandomSeqWrapper ( RandomSeq* ptr );
    ~RandomSeqWrapper ();

    RandomSeq* pointerToRndSeq = nullptr;
};

