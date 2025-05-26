/**
@file zwapi_math_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the All
Math functions.
*/
/**
@defgroup zwapi_math_data Math Data
@ingroup MathModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the All
Math functions.
*/

#pragma once
#ifndef ZW_API_MATH_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_MATH_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Intersection of Curve/Face Data */
    //====================================================================================================================
    /**
    @brief face trim-curve option
    @ingroup zwapi_math_data
    */
    typedef enum evxFaceTrim
    {
        VX_TRIM_NONE  = 0, /**<@brief  ignore all trim boundaries */
        VX_TRIM_ALL   = 1, /**<@brief  use all face trim boundaries */
        VX_TRIM_OUTER = 2  /**<@brief  use only the outer trim boundaries */
    } evxFaceTrim;

    /**
    @brief face trim-curve option
    @ingroup ZwMathData
    */
    typedef enum ezwFaceTrim
    {
        ZW_TRIM_NONE, /**<@brief  ignore all trim boundaries */
        ZW_TRIM_ALL,  /**<@brief  use all face trim boundaries */
        ZW_TRIM_OUTER /**<@brief  use only the outer trim boundaries */
    } ezwFaceTrim;

    /**
    @brief intersection point data
    @ingroup ZwMathData
    */
    typedef struct szwIntersectionPoint
    {
        szwPoint point;             /**<@brief  intersection point coordinate */
        szwEntityHandle faceHandle; /**<@brief  face handle at the intersection point */
    } szwIntersectionPoint;

    //====================================================================================================================
    /** @name Curve Evaluate Data */
    //====================================================================================================================
    /**
    @brief curve evaluate
    @ingroup zwapi_math_data
    */
    typedef struct svxEvalCurv
    {
        int level;        /**<@brief  level of evaluation                       */
        svxPoint pnt;     /**<@brief  level 0 - x,y,z (or u,v)                  */
        svxPoint deriv_1; /**<@brief  level 1 - x',y' (or u',v')                */
        svxPoint deriv_2; /**<@brief  level 2 - x'',y'' (or u'',v'')            */
        svxPoint deriv_3; /**<@brief  level 3 - x''',y''',z''' (or u''',v''')   */
    } svxEvalCurv;

    /**
    @brief curve evaluate
    @ingroup ZwMathData
    */
    typedef struct szwCurveDerivative
    {
        int level;             /**<@brief  level of evaluation                       */
        szwPoint pnt;          /**<@brief  level 0 - x,y,z (or u,v)                  */
        szwPoint derivative_1; /**<@brief  level 1 - x',y' (or u',v')                */
        szwPoint derivative_2; /**<@brief  level 2 - x'',y'' (or u'',v'')            */
        szwPoint derivative_3; /**<@brief  level 3 - x''',y''',z''' (or u''',v''')   */
    } szwCurveDerivative;

    //====================================================================================================================
    /** @name Surface Find Face/Edge Data */
    //====================================================================================================================
    /**
    @brief face search types
    @ingroup zwapi_math_data
    */
    typedef enum evxFaceFindType
    {
        VX_FIND_BOSS,   /**<@brief  find the faces that have the geometric characteristics of a boss */
        VX_FIND_POCKET, /**<@brief  find the faces that have the geometric characteristics of a pocket */
        VX_FIND_HOLE,   /**<@brief  find the faces that have the geometric characteristics of a hole */
        VX_FIND_FILLET, /**<@brief  find the faces that have the geometric characteristics of a network of fillet chains */
        VX_FIND_CUSTOM, /**<@brief  find the faces based on the stop conditions set (evxFindRule) */
        VX_FIND_FINDER, /**<@brief  base on seed face, find the faces that conforms to the set rules (evxFindRule) */
    } evxFaceFindType;

    /**
    @brief face search rules
    @ingroup ZwMathData
    */
    typedef enum ezwFindRule
    {
        /*  stop condition, only for ZW_FIND_CUSTOM (ezwFaceFindType) type */
        ZW_STOP_FACE_FILLET     = 0x00000001, /**<@brief  stop at fillet faces (fillets are added) */
        ZW_STOP_EDGE_INNER_LOOP = 0x00000002, /**<@brief  stop at edges on inner loops on either face */
        ZW_STOP_CONVEX_FLLT     = 0x00000004, /**<@brief  stop at convex fillet faces (fillets are added) */
        ZW_STOP_CONCAVE_FLLT    = 0x00000008, /**<@brief  stop at concave fillet faces (fillets are added) */
        ZW_STOP_CONVEX_EDGE     = 0x00000010, /**<@brief  stop at convex edges */
        ZW_STOP_CONCAVE_EDGE    = 0x00000020, /**<@brief  stop at concave edges */
        ZW_STOP_ADJACENCY_LEVEL = 0x00000040, /**<@brief  stop when face region grows through a set number of
                                             cycles, a face region grows in cycles, where the
                                             faces immediately adjacent to the seed are added in
                                             the first cycle, the faces immediately adjacent to
                                             those faces are added in the second cycle, and so on */
        ZW_STOP_BOUNDARY_FACE   = 0x00000080, /**<@brief  stop at boundary faces */


        /*  find rules, only for ZW_FIND_FINDER (ezwFaceFindType) type */
        ZW_FIND_COAXIAL      = 0x00000001, /**<@brief  find coaxial faces, seed face support cylinder,conical,sphere,torus */
        ZW_FIND_TANGENT      = 0x00000002, /**<@brief  find faces which is tangent to the seed */
        ZW_FIND_COPLANAR     = 0x00000004, /**<@brief  find faces which are in the same plane with the seed */
        ZW_FIND_COPL_AXES    = 0x00000008, /**<@brief  find faces whose axes are in the same plane with the seed,
                                                                                seed face support cylinder,conical */
        ZW_FIND_EQUAL_RADIUS = 0x00000010, /**<@brief  find faces whose radius is equal to the seed,
                                      seed face support cylinder and sphere */
        ZW_FIND_SYMMETRIC    = 0x00000020, /**<@brief  find symmetric faces, seed face support cylinder,conical */
        ZW_FIND_OFFSET       = 0x00000040, /**<@brief  find face which has overlap regions with the seed and face normal
                                      is opposite, for a seed, only one offset face exists in a shape */
    } ezwFindRule;

    /**
    @brief face search types
    @ingroup ZwMathData
    */
    typedef enum ezwFaceFindType
    {
        ZW_FIND_BOSS,   /**<@brief  find the faces that have the geometric characteristics of a boss */
        ZW_FIND_POCKET, /**<@brief  find the faces that have the geometric characteristics of a pocket */
        ZW_FIND_HOLE,   /**<@brief  find the faces that have the geometric characteristics of a hole */
        ZW_FIND_FILLET, /**<@brief  find the faces that have the geometric characteristics of a network of fillet chains */
        ZW_FIND_CUSTOM, /**<@brief  find the faces based on the stop conditions set (evxFindRule) */
        ZW_FIND_FINDER, /**<@brief  base on seed face, find the faces that conforms to the set rules (evxFindRule) */
    } ezwFaceFindType;

    /**
    @brief face search data
    @ingroup zwapi_math_data
    */
    typedef struct svxFaceFind
    {
        int numSeeds;           /**<@brief  number of seed faces */
        int *idSeeds;           /**<@brief  list of seed faces */
        evxFaceFindType Option; /**<@brief  type of face to search for */
        int Rule;               /**<@brief  face search rules(evxFindRule),like this:VX_STOP_FACE_FILLET | VX_STOP_FACE_FILLET,
                              used only for VX_FIND_CUSTOM & VX_FIND_FINDER(evxFaceFindType) type */
        int numEdges;           /**<@brief  number of stop edges, used only for VX_FIND_CUSTOM(evxFaceFindType) type  */
        int *idEdges;           /**<@brief  list of stop edges, used only for VX_FIND_CUSTOM(evxFaceFindType) type */
        int AdjCnt;             /**<@brief  adjacency count(>0), used only when Rule contain VX_STOP_ADJACENCY_LEVEL */
        int numFaces;           /**<@brief  number of stop faces, used only when Rule contain VX_STOP_BOUNDARY_FACE */
        int *idFaces;           /**<@brief  list of stop faces, used only when Rule contain VX_STOP_BOUNDARY_FACE */
    } svxFaceFind;

    /**
    @brief face search data attribute
    @ingroup ZwMathData
    */
    typedef struct szwFaceFindAttribute
    {
        ezwFaceFindType option;       /**<@brief  type of face to search for */
        int rule;                     /**<@brief  face search rules(ezwFindRule),like this:ZW_STOP_FACE_FILLET | ZW_STOP_FACE_FILLET,
                              used only for ZW_FIND_CUSTOM & ZW_FIND_FINDER(ezwFaceFindType) type */
        int numberEdges;              /**<@brief  number of stop edges, used only for ZW_FIND_CUSTOM(ezwFaceFindType) type  */
        szwEntityHandle *edgeHandles; /**<@brief  list of stop edges, used only for ZW_FIND_CUSTOM(ezwFaceFindType) type */
        int adjacencyCount;           /**<@brief  adjacency count(>0), used only when Rule contain ZW_STOP_ADJACENCY_LEVEL */
        int numberFaces;              /**<@brief  number of stop faces, used only when Rule contain ZW_STOP_BOUNDARY_FACE */
        szwEntityHandle *faceHandles; /**<@brief  list of s0top faces, used only when Rule contain ZW_STOP_BOUNDARY_FACE */
    } szwFaceFindAttribute;

    /**
    @brief type of loop in which the edge is located
    @ingroup zwapi_math_data
    */
    typedef enum evxEdgeLoopType
    {
        VX_EDGE_LOOP_INNER    = 0, /**<@brief  inner loop edges */
        VX_EDGE_LOOP_OUTER    = 1, /**<@brief  outer loop edges */
        VX_EDGE_LOOP_ALL      = 2, /**<@brief  all edges */
        VX_EDGE_LOOP_SHARED   = 3, /**<@brief  shared edges */
        VX_EDGE_LOOP_BOUNDARY = 4  /**<@brief  boundary edges */
    } evxEdgeLoopType;

    /**
    @brief type of loop in which the edge is located
    @ingroup ZwMathData
    */
    typedef enum ezwEdgeLoopType
    {
        ZW_EDGE_LOOP_INNER    = 0, /**<@brief  inner loop edges */
        ZW_EDGE_LOOP_OUTER    = 1, /**<@brief  outer loop edges */
        ZW_EDGE_LOOP_ALL      = 2, /**<@brief  all edges */
        ZW_EDGE_LOOP_SHARED   = 3, /**<@brief  shared edges */
        ZW_EDGE_LOOP_BOUNDARY = 4  /**<@brief  boundary edges */
    } ezwEdgeLoopType;


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_MATH_DATA_H */
