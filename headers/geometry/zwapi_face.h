/**
@file zwapi_face.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D face API
*/

#pragma once
#ifndef ZW_API_FACE_H /* this ifndef surrounds entire header */
#define ZW_API_FACE_H

#include "zwapi_geometry_surface_data.h"
#include "zwapi_brep_data.h"
#include "zwapi_math_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Face Query */
    //====================================================================================================================
    /**
    @ingroup ZwFace
    
    Gets the handle of the specified face's parent shape (within the active file).
    
    @note
   The caller is responsible to free the shape by using ZwEntityHandleFree().
    
    @param [in] face face handle
    @param [out] shape face's parent shape handle
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwFaceShapeGet(szwEntityHandle face, szwEntityHandle *shape);

    /**
    @ingroup ZwFace

    Outputs the untrimmed NURBS surface geometry of the specified face.  
    It is assumed the specified face resides in the active part.

    @note
    The caller is responsible to free the data by using ZwSurfaceDataFree().

    @param [in] faceHandle face handle
    @param [out] data face's untrimmed NURBS surface geometry data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwFaceSurfaceDataGet(szwEntityHandle faceHandle, szwSurface *data);

    /**
    @ingroup ZwFace

    Frees memory associated with the specified surface structure.

    @param [in] data NURB surface structure

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwSurfaceDataFree(szwSurface *data);

    /**
    @ingroup ZwFace

    Outputs a list of handles of the edges that bound a face in the activated file.  
    Function Guide: Face -> Edge

    @note  
    The caller is responsible to free the edges by using ZwEntityHandleListFree()

    @see ZwEntityHandleListFree

    @param [in] face face handle
    @param [out] count number of edges
    @param [out] edgeList list of edge handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwFaceEdgeListGet(szwEntityHandle face, int *count, szwEntityHandle **edgeList);

    /**
    @ingroup ZwFace

    Outputs a list of indices of the loops (outer and inner) that belong to a face  
    in the active file.Outer loops proceed counterclockwise relative to the natural  
    normal of the parent surface.  Inner loops are clockwise.  
    Function Guide: Face -> Loop

    @note  
    The caller is responsible to free the loops by using ZwEntityHandleListFree()

    @see ZwEntityHandleListFree

    @param [in] face face handle
    @param [in] inner 1 to include inner loops; 0 for just the outer loops
    @param [out] count number of loops
    @param [out] loopList list of loop handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwFaceLoopListGet(szwEntityHandle face, int inner, int *count, szwEntityHandle **loopList);

    /**
    @ingroup ZwFace

    Applies transformation matrix "inputMatrix" to "surface".
    Assumes "inputMatrix" is an affine transform.

    @param [in] inputMatrix transformation matrix
    @param [in,out] surface surface to transformation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix inputMatrix=...;
       ...
       szwSurface surface=...;
       ZwFaceDataTransform(inputMatrix,&surface);
    @endcode
    */
    ZW_API_C ezwErrors ZwFaceDataTransform(szwMatrix inputMatrix, szwSurface *surface);

    /**
    @ingroup ZwFace

    This routine determines which, if any, boundaries of surface are poles.
    It sets the flags in the array poles appropriately.

    @param [in] surface pointer to NURBS surface data structure
    @param [in] tolerance the tolerance
    @param [out] poles[4]  poles[i] = 0 means the i-th boundary is not a pole.
                           poles[i] = 1 means it is a pole.
                           The boundaries are numbered counterclockwise, starting at
                           the bottom (v=0).
                           poles[0] -> pole at loV
                           poles[1] -> pole at hiU
                           poles[2] -> pole at hiV
                           poles[3] -> pole at loU
    @param [out] isPoleFind  0 - No poles found or error occurs
                             1 - At least one pole found

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwSurface surface=...;
        double tolerance=...;
        int poles[4];
        int isPoleFind;
        ...
        ZwFacePoleCheck(surface, tolerance, poles, &isPoleFind);
    @endcode
    */
    ZW_API_C ezwErrors ZwFacePoleCheck(szwSurface surface, double tolerance, int poles[4], int *isPoleFind);

    /**
    @ingroup ZwFace

    Get the pole point of the specified surface in a specified direction.

    @param [in] surface pointer to NURBS surface data structure
    @param [in] direction direction
    @param [out] point pole point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwSurface surface = ...;
        ...
        szwPoint direction{};
        szwPoint point{};
        ZwFacePoleGet(surface, &direction, &point);
    @endcode
    */
    ZW_API_C ezwErrors ZwFacePoleGet(szwSurface surface, szwPoint direction, szwPoint *point);

    //====================================================================================================================
    /** @name Surface Evaluate */
    //====================================================================================================================
    /**
    @ingroup ZwFace

    Evaluates a point in the space of the specified NURBS surface.  Outputs
    the 3D point coordinates (point), normal direction (normalDirection) and UV tangent
    directions at the specified U,V location on the surface.

    @note
    The direction of "normal" is set to reflect the outward
    normal of the face, where "outward" means the direction that points
    towards the outside of the shape that the face is associated with.
    This may be opposite the natural normal of the NURBS surface associated
    with the face.
    If you want the natural normal of the NURBS surface associated with
    the face,  call cvxVecReverse() to reverse the "normalDirection" if surface.outNormal=0.

    @param [in] surface pointer to NURBS surface data structure
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [out] point point on face (input NULL to ignore)
    @param [out] normalDirection normal at point on face (input NULL to ignore)
    @param [out] uTangent U tangent direction (input NULL to ignore)
    @param [out] vTangent V tangent direction (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR

    @code
        szwSurface surface=...;
        ....
        double U=...;
        double V=...;
        szwPoint point{};
        szwVector normalDirection{};
        szwVector uTangent{};
        szwVector vTangent{};
        ...
        ZwFacePointGetByUVparameter(surface, U, V, &point, &normalDirection, &uTangent, &vTangent);
    @endcode
    */
    ZW_API_C ezwErrors ZwFacePointGetByUVparameter(szwSurface surface, double U, double V, szwPoint *point, szwVector *normalDirection, szwVector *uTangent, szwVector *vTangent);

    /**
    @ingroup ZwFace

    Get the surface diameter in the specified UV point. the surface type
    must be one of the following:
    1.Cylinder: the cylinder diameter.
    2.Torus: the distance of the point specified from the axis.
    3.Cone: the distance of the point specified from the axis.

    @param [in] surface pointer to NURB surface data structure
    @param [in] U U parameter value on face
    @param [in] V V parameter value on face
    @param [out] diameter diameter of specified point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwSurface surface=...;
        ...
        double U=...;
        double V=...;
        double diameter=0.0;
        ...
        ZwFaceDiameterGetByUVparameter(surface, U, V, &diameter);
    @endcode
    */
    ZW_API_C ezwErrors ZwFaceDiameterGetByUVparameter(szwSurface surface, double U, double V, double *diameter);

    //====================================================================================================================
    /** @name Surface Query */
    //====================================================================================================================
    /**
    @ingroup ZwFace

    Modify a face to the active part using the specified surface and trim curves.
    The face is sewn to adjacent faces with matching edges.

    It is assumed the trim curves are 2D NURBS curves defined in the UV space of
    the specified surface.  If no trim curves are input (numCurves=0), trim
    curves are automatically created around the "rectangular" surface boundary.

    The input 3D proximity tolerance (tolerance) is used to match the endpoints of
    trim curves when they are sorted into loops, and to match edges of the
    new face to edges to existing faces if the "sew" option is enabled.

    If "tolerance" is input as 0.0, the active part's default proximity tolerance is used.

    This function copies data passed to it.  The calling procedure is
    responsible for deallocating memory referenced by the input data structures.

    @note
    Faces will not modify successfully to the active part unless there
    is an active feature (i.e. history operation) for them to link to.  This is
    accomplished by putting your code inside the callback function associated
    with a command-template-defined custom history operation. When the history
    is regenerated, ZW3D will expect the input parameters defined by the command
    template to provide sufficient input to the callback function to re-create
    (i.e. regenerate) the original geometry.
    The other option is to start your code with cvxPartHistStart(), which
    defines a "static" feature (i.e. history operation) for program-generated
    geometry (e.g. faces) to attach to.  When you are done adding geometry,
    call cvxPartHistEnd().  This function will cause all existing part geometry
    and history to be bundled into a single static "StartData" history operation.

    @param [in] faceHandle index of face
    @param [in] surface NURBS surface geometry
    @param [in] numCurves number of trim curves
    @param [in] trimCurves list of 2D NURBS UV trim curves
    @param [in] sew 1 to sew face to adjacent faces, else 0
    @param [in] tolerance 3D proximity tolerance (mm) (0.0 for default)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
        szwEntityHandle seedFaceHandle;
        ...
        szwSurface surface{};
        ...
        int numCurves = -1;
        szwCurve* trimCurves = nullptr;
        ...
        int sew=...;
        double tolerance=...;
        ...
        ret = ZwModelFaceSet(seedFaceHandle, surface, numCurves, trimCurves, sew, tolerance);
    @endcode
    */
    ZW_API_C ezwErrors ZwModelFaceSet(szwEntityHandle faceHandle, szwSurface surface, int numCurves, szwCurve *trimCurves, int sew, double tolerance);

    /**
    @ingroup ZwFace

    Use the function to find connected groups of faces and output a list
    of indices of the faces. the function provides several methods for
    finding faces that form certain kinds of features, such as bosses,
    pockets, holes and fillets. also support custom method, please refer
    to the description of input variables for details.

    The calling procedure MUST deallocate the output list with ZwMemoryFree().

    @param [in] nSeeds number of seed faces
    @param [in] seedFaceHandles list of id of seed faces
    @param [in] findData face search data
    @param [out] count number of faces found
    @param [out] faceHandles list of faces found

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
        int nSeeds;
        szwEntityHandle* seedFaces;
        ...
        szwFaceFindAttribute findData{};
        findData.option = evxFaceFindType::XXXX;
        ...
        int count = -1;
        szwEntityHandle *faceHandles;
        ....
        ZwFaceConnectedFaceGet(nSeeds, seedFaces, findData, &count, &faceHandles);
    @endcode
    */
    ZW_API_C ezwErrors ZwFaceConnectedFaceGet(int nSeeds, const szwEntityHandle *seedFaceHandles, szwFaceFindAttribute findData, int *count, szwEntityHandle **faceHandles);

    /**
    @ingroup ZwFace

    Use the function to find edges that bound one or more seed faces.

    The calling procedure MUST deallocate the output list with ZwMemoryFree().

    @param [in] nSeeds number of seed faces
    @param [in] seedFaceHandles list of id of seed faces
    @param [in] type type of boundary
    @param [out] count number of edges found
    @param [out] edgeHandles list of edges found

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_MODELING_DATA_ERROR

    @code
        int nSeeds;
        szwEntityHandle* seedFaces;
        ...
        ezwEdgeLoopType type=...;
        int count=0;
        szwEntityHandle *edgeHandles = nullptr;
        ...
        ZwFaceConnectedEdgeGet(nSeeds, seedFaces, type, &count, &edgeHandles);
    @endcode
    */
    ZW_API_C ezwErrors ZwFaceConnectedEdgeGet(int nSeeds, const szwEntityHandle *seedFaceHandles, ezwEdgeLoopType type, int *count, szwEntityHandle **edgeHandles);

    /**
    @ingroup ZwFace

    Adds a face to the active part using the specified surface and trim curves.
    The face is sewn to adjacent faces with matching edges.  

    It is assumed the trim curves are 2D NURBS curves defined in the UV space of
    the specified surface.  If no trim curves are input (numCurves=0), trim
    curves are automatically created around the "rectangular" surface boundary.  

    The input 3D proximity tolerance (tol) is used to match the endpoints of
    trim curves when they are sorted into loops, and to match edges of the
    new face to edges to existing faces if the "Sew" option is enabled.  

    If "tolerance" is input as 0.0, the active part's default proximity tolerance is used.  

    If "faceHandle" is not NULL, the database id of the new face entity is output.  

    This function copies data passed to it.  The calling procedure is
    responsible for deallocating memory referenced by the input data structures.  

    @note
    Faces will not add successfully to the active part unless there
    is an active feature (i.e. history operation) for them to link to.  This is
    accomplished by putting your code inside the callback function associated
    with a command-template-defined custom history operation (see cvxDataInit()).  
    When the history is regenerated, ZW3D will expect the input parameters defined
    by the command template to provide sufficient input to the callback function
    to re-create (i.e. regenerate) the original geometry.  
    The other option is to start your code with cvxPartHistStart(), which
    defines a "static" feature (i.e. history operation) for program-generated
    geometry (e.g. faces) to attach to.  When you are done adding geometry,
    call cvxPartHistEnd().  This function will cause all existing part geometry
    and history to be bundled into a single static "StartData" history operation.

    @param [in] surface surface geometry
    @param [in] numCurves number of trim curves
    @param [in] trimCurves list of 2D NURBS UV trim curves
    @param [in] code non-zero integer code for labeling the face
    @param [in] sew 1 to sew face to adjacent faces, else 0
    @param [in] tolerance 3D proximity tolerance (mm) (0.0 for default)
    @param [out] faceHandle database id of new face entity (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
        szwSurface srf=...;
        ...
        int numCurves=...;
        int code=...;
        int sew=...;
        double tol=...;
        szwCurve *trimCurve = ...;
        ...
        ret = ZwModelFaceCreate(surface, numCurves, trimCurve, 0, 0, 0.01, &faceNewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwModelFaceCreate(szwSurface surface, int numCurves, szwCurve *trimCurves, int code, int sew, double tolerance, szwEntityHandle *faceHandle);

    //====================================================================================================================
    /** @name Face Attribute */
    //====================================================================================================================
    /**
    @ingroup ZwFace

    Outputs the appearance of the specified face or shape.  
    Appearance for a shape are grabbed from the first face in the shape.  
    Function Guide: Face -> Appearance
    
    @note
    It is assumed the specified face or shape resides in the active part.

    @see ZwFaceDisplayAttributeSet and ZwFaceDisplayAttributeSetInit

    @param [in] face face or shape handle
    @param [out] attribute appearance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwFaceDisplayAttributeGet(szwEntityHandle face, szwFaceDisplayAttribute *attribute);

    /**
    @ingroup ZwFace

    Sets appearance of the specified faces or shapes.  
    It is assumed the specified faces or shapes reside in the active part.  
    Function Guide: Face -> Appearance

    @note
    ZwFaceDisplayAttributeSetInit() can initialize variables of this function.

    @see ZwFaceDisplayAttributeGet and ZwFaceDisplayAttributeSetInit

    @param [in] count number of faces (or shapes)
    @param [in] faceList list of face or shape handles
    @param [in] attribute appearance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFaceDisplayAttributeSet(int count, const szwEntityHandle *faceList, szwFaceDisplayAttribute attribute);

    /**
    @ingroup ZwFace

    Initialize the parameters of the ZwFaceDisplayAttributeSet().  
    Function Guide: Face -> Appearance

    @note
    Do not assign a value to variable "data" before calling this function.  

    @see ZwFaceDisplayAttributeGet and ZwFaceDisplayAttributeSet

    @param [out] data faces (or shapes) appearance 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwFaceDisplayAttributeSetInit(szwFaceDisplayAttribute *data);

    //====================================================================================================================
    /** @name Rotational Face */
    //====================================================================================================================
    /**
    @ingroup ZwFace

    Get the axis of the specified surface. the surface type must be
    one of the following: Cylinder, Torus and Cone.

    @param [in] surface pointer to NURBS surface data structure
    @param [out] startPoint start point of axis line
    @param [out] endPoint end point of axis line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR

    @code
        szwSurface surface = ...;
        ...
        szwPoint startPoint{};
        szwPoint endPoint{};
        ...
        ret = ZwRotationalFaceAxisPointGet(&surface, &startPoint, &endPoint)
    @endcode
    */
    ZW_API_C ezwErrors ZwRotationalFaceAxisPointGet(szwSurface surface, szwPoint *startPoint, szwPoint *endPoint);

    /**
    @ingroup ZwFace

    Uses this command to extract centerlines from an existing face. Cylinder, Cone
    and Torus faces are recognized and the appropriate curve type is created.

    @note
    The caller is responsible to free the entityList by using ZwEntityHandleListFree().

    @param [in] countFace count of faces to create centerlines
    @param [in] faceList handle data of faces to create centerlines
    @param [in] extractAxis 1 to display the axis, else 0
    @param [out] countEntity count of new curve entities
    @param [out] entityList handle data of new curve entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFaceCenterCurveGet(int countFace, const szwEntityHandle *faceList, int extractAxis, int *countEntity, szwEntityHandle **entityList);

    /**
    @ingroup ZwFace

    Outputs the facets used to display the specified face along with
    display, texture or shader attributes that may be defined for the
    specified face at specifies refineData.

    It is assumed the specified face (refineData.faceHandle) resides in the active part.

    If the values of tolorance in refineData exceeds the specified range,
    the default value will be used instead.

    @note
    The caller is responsible to free the facetsData by using ZwFaceFacetsDataFree.
    If the face is planar,  all tolorance in refineData will not take effect.

    @param [in] refineData face data
    @param [out] facetsData facets data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwFaceFacetsGet(szwRefineFacets refineData, szwFacets *facetsData);

    /**
    @ingroup ZwFace

    Outputs the facets used to display the specified face 
    that defined for the specified faces of refineData.  

    It is assumed the specified faces (refineData.faceHandle) reside in the active part.  

    If the values of tolorance in refineData exceeds the specified range,
    the default value will be used instead.

    @note
    The caller is responsible to free the facetsDataList by using ZwFaceFacetsDataFree().  
    If the face is planar,  all tolorance in refineData will not take effect.  
    This Api uses multi threads to speed up the calculation of facets.

    @param [in] refineData face data list
    @param [out] countFacets count of facets data in list
    @param [out] facetsData facets data list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwRefineFacetsOfMultiFace refineData = ...;
        ...
        int countFacets = 0;
        szwFacets *facetsDataList = NULL;
        ezwErrors err = ZwFaceListFacetsGet(refineData, &countFacets, &facetsDataList);
        ...
        for (int i = 0; i < countFacets; ++i)
            err = ZwFaceFacetsDataFree(&(facetsDataList[i]));
        ZwMemoryFree((void**)&facetsDataList);
    @endcode
    */
    ZW_API_C ezwErrors ZwFaceListFacetsGet(szwRefineFacetsOfMultiFace refineData, int *countFacets, szwFacets **facetsDataList);

    /**
    @ingroup ZwFace

    Free the memory of szwFacets.

    @param [in] facetsData facets data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwFaceFacetsDataFree(szwFacets *facetsData);

    /**
    @ingroup ZwFace

    Outputs texture attributes of the specified face.

    @note
    If a texture image file is embedded in a multi root file(Z3 file), it is automatically
    extracted to a "temp" sub-folder in the Z3 runtime folder. Path of
    the temp file is output via "texture->file".
    It is assumed the specified face resides in the active part.

    @param [in] faceHandle face handle
    @param [out] texture face texture attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwFaceTextureAttributeGet(szwEntityHandle faceHandle, szwTextureAttribute *texture);

    /**
    @ingroup ZwFace

    Initialize surface continuity tolerance setting data.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @param [out] data surface continuity tolerance setting data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFaceContinuityToleranceInit(szwSurfaceContinuityTolerance *data);

    /**
    @ingroup ZwFace

    Inquire the continuity of two mating surfaces and output the surface continuity data. the function supports
    inquiring the continuity of G0, G1, G2 and G3.

    @note
    Interface ZwFaceContinuityToleranceInit() can initialize surface continuity tolerance.
    The caller is responsible to free the data by using ZwEntityHandleFree() & ZwMemoryFree().

    @param [in] face1 the entity handle of the first face
    @param [in] face2 the entity handle of the second face
    @param [in] nSample the number of points to be sampled along edge, the valid range is [20, 500]
    @param [in] tolerance the judgment tolerance of surface continuity
    @param [out] nContinuityData the number of surface continuity data
    @param [out] data list of surface continuity data, the caller must free memory of the object using ZwMemoryFree()

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    // 1. Initialize tolerance settings
    szwSurfaceContinuityTolerance tol = {};
    ZwFaceContinuityToleranceInit(&tol);

    //2. Inquire surface continuity
    szwEntityHandle face1;
    szwEntityHandle face2;
    ...
    int nDatas = 0;
    szwSurfaceContinuityData* data = nullptr;
    evxErrors err = ZwFaceContinuityGet(face1, face2, 100, tol, &nDatas, &data);

    //3. free memory
    for (int i = 0; i < nDatas; ++i)
       {
       ZwEntityHandleFree(&data[i].edge1);
       ZwEntityHandleFree(&data[i].edge2);
       }
    ZwMemoryFree((void**)&data);
    @endcode
    */
    ZW_API_C ezwErrors ZwFaceContinuityGet(szwEntityHandle face1, szwEntityHandle face2, int nSample, szwSurfaceContinuityTolerance tolerance, int *nContinuityData, szwSurfaceContinuityData **data);


    /*
    *********************************************************************
    **  END HEADER FILE
    *********************************************************************
    */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FCAE_H */
