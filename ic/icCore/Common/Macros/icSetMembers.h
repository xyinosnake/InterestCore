
#pragma once

#include"./icInfo.h" //ic_info

ic_info("icSetMembers")
    #define ic_set_members_x1(obj, m1)                             obj.m1
    #define ic_set_members_x2(obj, m1, m2)                         obj.m1; obj.m2
    #define ic_set_members_x3(obj, m1, m2, m3)                     obj.m1; obj.m2; obj.m3
    #define ic_set_members_x4(obj, m1, m2, m3, m4)                 obj.m1; obj.m2; obj.m3; obj.m4
    #define ic_set_members_x5(obj, m1, m2, m3, m4, m5)             obj.m1; obj.m2; obj.m3; obj.m4; obj.m5
    #define ic_set_members_x6(obj, m1, m2, m3, m4, m5, m6)         obj.m1; obj.m2; obj.m3; obj.m4; obj.m5; obj.m6
    #define ic_set_members_x7(obj, m1, m2, m3, m4, m5, m6, m7)     obj.m1; obj.m2; obj.m3; obj.m4; obj.m5; obj.m6; obj.m7
    #define ic_set_members_x8(obj, m1, m2, m3, m4, m5, m6, m7, m8) obj.m1; obj.m2; obj.m3; obj.m4; obj.m5; obj.m6; obj.m7; obj.m8

ic_info("icSetPtrMembers")
    #define ic_set_ptr_members_x1(ptr, m1)                             ptr->m1
    #define ic_set_ptr_members_x2(ptr, m1, m2)                         ptr->m1; ptr->m2
    #define ic_set_ptr_members_x3(ptr, m1, m2, m3)                     ptr->m1; ptr->m2; ptr->m3
    #define ic_set_ptr_members_x4(ptr, m1, m2, m3, m4)                 ptr->m1; ptr->m2; ptr->m3; ptr->m4
    #define ic_set_ptr_members_x5(ptr, m1, m2, m3, m4, m5)             ptr->m1; ptr->m2; ptr->m3; ptr->m4; ptr->m5
    #define ic_set_ptr_members_x6(ptr, m1, m2, m3, m4, m5, m6)         ptr->m1; ptr->m2; ptr->m3; ptr->m4; ptr->m5; ptr->m6
    #define ic_set_ptr_members_x7(ptr, m1, m2, m3, m4, m5, m6, m7)     ptr->m1; ptr->m2; ptr->m3; ptr->m4; ptr->m5; ptr->m6; ptr->m7
    #define ic_set_ptr_members_x8(ptr, m1, m2, m3, m4, m5, m6, m7, m8) ptr->m1; ptr->m2; ptr->m3; ptr->m4; ptr->m5; ptr->m6; ptr->m7; ptr->m8

ic_info("Micro Keywords - icSetMembers")
    #define ic_sm_x1 ic_set_members_x1
    #define ic_sm_x2 ic_set_members_x2
    #define ic_sm_x3 ic_set_members_x3
    #define ic_sm_x4 ic_set_members_x4
    #define ic_sm_x5 ic_set_members_x5
    #define ic_sm_x6 ic_set_members_x6
    #define ic_sm_x7 ic_set_members_x7
    #define ic_sm_x8 ic_set_members_x8

ic_info("Micro Keywords - icSetPtrMembers")
    #define ic_spm_x1 ic_set_ptr_members_x1
    #define ic_spm_x2 ic_set_ptr_members_x2
    #define ic_spm_x3 ic_set_ptr_members_x3
    #define ic_spm_x4 ic_set_ptr_members_x4
    #define ic_spm_x5 ic_set_ptr_members_x5
    #define ic_spm_x6 ic_set_ptr_members_x6
    #define ic_spm_x7 ic_set_ptr_members_x7
    #define ic_spm_x8 ic_set_ptr_members_x8