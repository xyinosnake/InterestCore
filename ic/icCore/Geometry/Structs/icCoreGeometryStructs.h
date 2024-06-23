
#pragma once

#include"../../Common/Types/icCoreCommonTypes.h"
#include"../../Common/Macros/icCoreCommonMacros.h"

ic_info("decs")
ic_info("Points 2D")
    ic_dcl_struct(IC_POINT_2D_I32);
    ic_dcl_struct(IC_POINT_2D_I64);
    ic_dcl_struct(IC_POINT_2D_U32);
    ic_dcl_struct(IC_POINT_2D_U64);
    ic_dcl_struct(IC_POINT_2D_F32);
    ic_dcl_struct(IC_POINT_2D_F64);

ic_info("Points 3D")
    ic_dcl_struct(IC_POINT_3D_I32);
    ic_dcl_struct(IC_POINT_3D_I64);
    ic_dcl_struct(IC_POINT_3D_U32);
    ic_dcl_struct(IC_POINT_3D_U64);
    ic_dcl_struct(IC_POINT_3D_F32);
    ic_dcl_struct(IC_POINT_3D_F64);

ic_info("Cxy")
    ic_dcl_struct(IC_CXY_I32);
    ic_dcl_struct(IC_CXY_I64);
    ic_dcl_struct(IC_CXY_U32);
    ic_dcl_struct(IC_CXY_U64);
    ic_dcl_struct(IC_CXY_F32);
    ic_dcl_struct(IC_CXY_F64);

ic_info("Cxyz")
    ic_dcl_struct(IC_CXYZ_I32);
    ic_dcl_struct(IC_CXYZ_I64);
    ic_dcl_struct(IC_CXYZ_U32);
    ic_dcl_struct(IC_CXYZ_U64);
    ic_dcl_struct(IC_CXYZ_F32);
    ic_dcl_struct(IC_CXYZ_F64);

ic_info("Rect")
    ic_dcl_struct(IC_RECT_I32);
    ic_dcl_struct(IC_RECT_I64);
    ic_dcl_struct(IC_RECT_U32);
    ic_dcl_struct(IC_RECT_U64);
    ic_dcl_struct(IC_RECT_F32);
    ic_dcl_struct(IC_RECT_F64);

ic_info("Rect2")
    ic_dcl_struct(IC_RECT2_I32);
    ic_dcl_struct(IC_RECT2_I64);
    ic_dcl_struct(IC_RECT2_U32);
    ic_dcl_struct(IC_RECT2_U64);
    ic_dcl_struct(IC_RECT2_F32);
    ic_dcl_struct(IC_RECT2_F64);

ic_info("Ellipse")
    ic_dcl_struct(IC_ELLIPSE_F32);
    ic_dcl_struct(IC_ELLIPSE_F64);

ic_info("Circle")
    ic_dcl_struct(IC_CIRCLE_F32);
    ic_dcl_struct(IC_CIRCLE_F64);

ic_info("Spheroid")
    ic_dcl_struct(IC_SPHEROID_F32);
    ic_dcl_struct(IC_SPHEROID_F64);


ic_info("defs")
ic_info("Points")
    struct IC_POINT_2D_I32 {
        int32_t x, y;
    };

    struct IC_POINT_2D_I64 {
        int64_t x, y;
    };

    struct IC_POINT_2D_U32 {
        uint32_t x, y;
    };

    struct IC_POINT_2D_U64 {
        uint64_t x, y;
    };

    struct IC_POINT_2D_F32 {
        flo32_t x, y;
    };

    struct IC_POINT_2D_F64 {
        flo64_t x, y;
    };

    struct IC_POINT_3D_I32 {
        int32_t x, y, z;
    };

    struct IC_POINT_3D_I64 {
        int64_t x, y, z;
    };

    struct IC_POINT_3D_U32 {
        uint32_t x, y, z;
    };

    struct IC_POINT_3D_U64 {
        uint64_t x, y, z;
    };

    struct IC_POINT_3D_F32 {
        flo32_t x, y, z;
    };

    struct IC_POINT_3D_F64 {
        flo64_t x, y, z;
    };

ic_info("Cxy & Cxyz")
    struct IC_CXY_I32 {
        int32_t cx, cy;
    };

    struct IC_CXY_I64 {
        int64_t cx, cy;
    };

    struct IC_CXY_U32 {
        uint32_t cx, cy;
    };

    struct IC_CXY_U64 {
        uint32_t cx, cy;
    };

    struct IC_CXY_F32 {
        flo32_t cx, cy;
    };

    struct IC_CXY_F64 {
        flo64_t cx, cy;
    };

    struct IC_CXYZ_I32 {
        int32_t cx, cy, cz;
    };

    struct IC_CXYZ_I64 {
        int64_t cx, cy, cz;
    };

    struct IC_CXYZ_U32 {
        uint32_t cx, cy, cz;
    };

    struct IC_CXYZ_U64 {
        uint64_t cx, cy, cz;
    };

    struct IC_CXYZ_F32 {
        flo32_t cx, cy, cz;
    };

    struct IC_CXYZ_F64 {
        flo64_t cx, cy, cz;
    };

ic_info("Rect")
    struct IC_RECT_I32 {
        int32_t L, T, R, B; // Left, Top, Right, Bottom
    };

    struct IC_RECT_I64 {
        int64_t L, T, R, B; // Left, Top, Right, Bottom
    };

    struct IC_RECT_U32 {
        uint32_t L, T, R, B; // Left, Top, Right, Bottom
    };

    struct IC_RECT_U64 {
        uint64_t L, T, R, B; // Left, Top, Right, Bottom
    };

    struct IC_RECT_F32 {
        flo32_t L, T, R, B; // Left, Top, Right, Bottom
    };

    struct IC_RECT_F64 {
        flo64_t L, T, R, B; // Left, Top, Right, Bottom
    };

    struct IC_RECT2_I32 {
        int32_t L, T, W, H; // Left, Top, Width, Height
    };

    struct IC_RECT2_I64 {
        int64_t L, T, W, H; // Left, Top, Width, Height
    };

    struct IC_RECT2_U32 {
        uint32_t L, T, W, H; // Left, Top, Width, Height
    };

    struct IC_RECT2_U64 {
        uint64_t L, T, W, H; // Left, Top, Width, Height
    };

    struct IC_RECT2_F32 {
        flo32_t L, T, W, H; // Left, Top, Width, Height
    };

    struct IC_RECT2_F64 {
        flo64_t L, T, W, H; // Left, Top, Width, Height
    };

ic_info("Ellipse")
    struct IC_ELLIPSE_F32 {
        IC_POINT_2D_F32 ct; // center
        flo32_t         rx; // radius X
        flo32_t         ry; // radius Y
    };

    struct IC_ELLIPSE_F64 {
        IC_POINT_2D_F64 ct; // center
        flo64_t         rx; // radius X
        flo64_t         ry; // radius Y
    };

ic_info("Circle")
    struct IC_CIRCLE_F32 {
        IC_POINT_2D_F32 ct; // center
        flo32_t         r;  // radius
    };

    struct IC_CIRCLE_F64 {
        IC_POINT_2D_F64 ct; // center
        flo64_t         r;  // radius
    };

ic_info("Spheroid")
    struct IC_SPHEROID_F32 {
        IC_POINT_3D_F32 ct; // center
        flo32_t         r;  // radius
    };

    struct IC_SPHEROID_F64 {
        IC_POINT_3D_F64 ct; // center
        flo32_t         r;  // radius
    };