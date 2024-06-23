
#pragma once

#include"../Types/icCoreCommonTypes.h"

ic_info("macros")
    #define icSetItv(refItv, iLeft, iRight)  { refItv.left = iLeft; refItv.right = iRight; }
    #define icSetSeg(refSeg, iPos, iDis)     { refSeg.position = iPos; refSeg.distance = iDis; }

ic_info("decs")
    ic_dcl_struct(IC_VER);       // Version Data(YMDT)
    ic_dcl_struct(IC_ITV);       // Interval
    ic_dcl_struct(IC_SEG);       // Segment
    ic_dcl_struct(IC_ALLOC);     // Allocator
    ic_dcl_struct(IC_ALLOC2);    // Allocator2
    ic_dcl_struct(IC_CONSTRUCT); // Constructor
    ic_dcl_struct(IC_P3);        // Pointer x 3
    ic_dcl_struct(IC_P4);        // Pointer x 4
    ic_dcl_struct(IC_MIXED_P3);  // Mixed Segment Buffer
    ic_dcl_struct(IC_STR8);      // Strand8
    ic_dcl_struct(IC_STR16);     // Strand16
    ic_dcl_struct(IC_STR32);     // Strand32
    ic_dcl_struct(IC_SSEG8);     // String Segment 8
    ic_dcl_struct(IC_SSEG16);    // String Segment 16
    ic_dcl_struct(IC_SSEG32);    // String Segment 32

    ic_alias(IC_STR,  IC_STR8);  // Default Strand
    ic_alias(IC_SSEG, IC_SSEG8); // Default String Segment 

ic_info("defs")
    struct IC_VER {
        uint16_t major; // cpl years
        uint8_t  minor; // cpl months
        uint8_t  patch; // cpl days
        uint32_t build; // cpl time
    };

    struct IC_ITV {
        void* left;  // start position of interval.
        void* right; // end   position of interval.
    };

    struct IC_SEG {
        void*  position;
        size_t distance; // size of bytes.
    };

    struct IC_ALLOC {
        ic_alloc_f   alloc;
        ic_dealloc_f dealloc;
    };

    struct IC_ALLOC2 {
        ic_alloc_f   alloc;
        ic_dealloc_f dealloc;
        ic_realloc_f realloc;
    };

    struct IC_CONSTRUCT {
        ic_construct_f construct;
        ic_destruct_f  destruct;
    };

    struct IC_P3 {
        void* ptr[3];
    };

    struct IC_P4 {
        void* ptr[4];
    };

    struct IC_MIXED_P3 {
        void*   ptr[1];    // p0 = ptr[0]; p1 = (void*)distance; p2 = *(void**)buffer;
        size_t  distance;  // size of bytes.
        uint8_t buffer[1]; // at least IC_WORD_SIZE / 8.
    };

    struct IC_STR8 {
        ch8_t* left;
        ch8_t* right;
    };

    struct IC_STR16 {
        ch16_t* left;
        ch16_t* right;
    };

    struct IC_STR32 {
        ch32_t* left;
        ch32_t* right;
    };

    struct IC_SSEG8 {
        ch8_t* position;
        size_t distance; // size of bytes.
    };

    struct IC_SSEG16 {
        ch16_t* position;
        size_t  distance; // size of bytes.
    };

    struct IC_SSEG32 {
        ch32_t* position;
        size_t  distance; // size of bytes.
    };