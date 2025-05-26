/**
@file zwapi_sheet_metal.h
@(C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Sheet Metal API*/
#pragma once
#ifndef ZW_API_SHEET_METAL_H /* this ifndef surrounds entire header */
#define ZW_API_SHEET_METAL_H

#include "zwapi_sheet_metal_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Sheet Metal Attribute */
    //====================================================================================================================
    /**
    @ingroup ZwSheetMetal

    Gets the sheet metal attribute values.

    @param [out] attribute sheet metal attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwSheetMetalAttributeGet(szwSheetMetalAttribute *attribute);

    /**
    @ingroup ZwSheetMetal

    Sets the sheet metal attribute values. 
    If there is no sheet metal, it will create one.

    @note
    If you just want to set some specified variables of szwSheetMetalAttribute, 
    please call ZwSheetMetalAttributeGet to get the global values to initialize 
    "attribute" first.

    @see ZwSheetMetalAttributeGet

    @param [in] attribute sheet metal attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwSheetMetalAttributeSet(szwSheetMetalAttribute attribute);

    //====================================================================================================================
    /** @name Flange */
    //====================================================================================================================

    /**
    @ingroup ZwSheetMetal

    Use this function to retrieve the bend information of a bend face.

    @note
    The input parameter 'face' must be a bend face.

    @code
    szwEntityHandle face;
    szwSmdBendInformation bendInformation{};
    // only get the information
    ... // code to get the data of 'face'
    ezwErrors ret = ZwBendInformationGet(face, NULL, &bendInformation);
    ...
    // pass the variable name and it will generate some equations to record the information
    zwString32 variableName = "bend";
    ezwErrors ret = ZwBendInformationGet(face, variableName, &bendInformation);
    @endcode

    @param [in] face bend face
    @param [in] variableName variable name that records the inquiry, it can be NULL
    @param [out] bendInformation bend information

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwBendInformationGet(szwEntityHandle face, const zwString32 variableName, szwSmdBendInformation *bendInformation);

    /**
    @ingroup ZwSheetMetal

    Corrects the transformation matrix of the specified sketch based on the edge to add flange and bending angle
    to meet the rule of "Flange with Profile" command.
    The transformation matrix must satisfy some rules in "Flange with Profile" command.

    @note
    The input sketch is created based on the input edge and the flange face where the edge located.
    The Dir(sketch) = the cross of Dir(edge) and Dir(flange face), the origin point is start/end of the idEdge.
    If the bend angle is not 90, this function will rotate the sketch with the angle.

    @see
    cvxPartSmdProfFlange

    @param [in] sketch handle of sketch to modify the its matrix by the rule
    @param [in] edge handle of edge to add flange with profile
    @param [in] angle the bend angle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwSheetMetalFlangeProfileCorrection(szwEntityHandle sketch, szwEntityHandle edge, double angle);

    /**
    @ingroup ZwSheetMetal

    Finds the same side, opposite and thick faces about the specified seed face of a sheet metal shape.  
    If this function executes successfully, the data 'resultData.sameSideFaces' will contain the seedFace.  

    @note
    if the input 'seedFace' is a thick face, this function will return ZW_API_INVALID_INPUT.  
    The caller is responsible to free the resultData by using ZwSheetMetalFaceSideAndThickFree().  

    @see ZwSheetMetalFaceSideAndThickFree

    @param [in] seedFace seed face to find the relative faces
    @param [out] resultData faces data of the seed face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle seedFace{};
    szwSheetMetalFaceFindData resultData{};
    ... // code to get seedFace
    ezwErrors errorValue = ZwSheetMetalFaceSideAndThickFind(seedFace, &resultData);
    ... // code to handle the resultData
    // free the data
    ZwSheetMetalFaceSideAndThickFree(&resultData);
    @endcode
    */
    ZW_API_C ezwErrors ZwSheetMetalFaceSideAndThickFind(szwEntityHandle seedFace, szwSheetMetalFaceFindData *resultData);

    /**
    @ingroup ZwSheetMetal

    Frees the data which allocated from ZwSheetMetalFaceSideAndThickFind().  

    @see ZwSheetMetalFaceSideAndThickFind

    @param [in] resultData faces data of the seed face

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwSheetMetalFaceSideAndThickFree(szwSheetMetalFaceFindData *resultData);

    /**
    @ingroup ZwSheetMetal

    Checks the interference of the input sheet metal shapes, and output the interference face list.  
    If the input shapeList is NULL, this function will try to find all shapes in active file and 
    check them.  

    Function Guide: Sheet Metal->Bend->Flange Interference

    @note
    The caller is responsible to free the faceList by using ZwEntityHandleListFree().

    @param [in] shapeCount count of shapes to check interference, can be 0
    @param [in] shapeList the list of shapes, can be NULL
    @param [out] faceCount count of interference faces
    @param [out] faceList the list of interference faces

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwSheetMetalFlangeInterferenceCheck(int shapeCount, const szwEntityHandle *shapeList, int *faceCount, szwEntityHandle **faceList);

    /**
    @ingroup ZwSheetMetal

    Get the fold status of the specify metal sheet shape.  
    If all faces of the shape do not have metal sheet fold information, the ZW_SHEET_METAL_FOLD_NO_INFORMATION will be output, which means this shape may not be a metal sheet shape.  
    ZW_SHEET_METAL_FOLD_ALL_FOLD: All faces with metal sheet attributes are folded.  
    ZW_SHEET_METAL_FOLD_ALL_UNFOLD: All faces with metal sheet attributes are unfolded.  
    ZW_SHEET_METAL_FOLD_NOT_FULLY_FOLD: The faces with metal sheet attributes are not all folded.  

    @param [in] shapeHandle handle of the metal sheet handle.  
    @param [out] status the fold status of the specify metal sheet shape.  

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwSheetMetalFoldStateGet(szwEntityHandle shapeHandle, ezwSheetMetalFoldStatus *status);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_SHEET_METAL_H */