/**
@file zwapi_drawing_view.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Drawing View API
*/

#pragma once
#ifndef ZW_API_DRAWING_VIEW_H /* this ifndef surrounds entire header */
#define ZW_API_DRAWING_VIEW_H

#include "zwapi_drawing_view_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name View Create */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the ZwDrawingViewAlignedSectionCreate().  

    @see ZwDrawingViewAlignedSectionCreate

    @param [out] data aligned section view data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewAlignedSectionCreateInit(szwAlignSectionViewData *data);

    /**
    @ingroup ZwDrawingView

    Creates an aligned section view for base view in drawing.

    Function Guide:Drawing->layout->View->Aligned Section

    @see ZwDrawingViewAlignedSectionCreateInit

    @note
    Interface ZwDrawingViewAlignedSectionCreateInit() can initialize variables of this function.
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @param [in] alignSectionViewData aligned section view data
    @param [out] viewHandle handle data of the view created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewAlignedSectionCreate(szwAlignSectionViewData alignSectionViewData, szwEntityHandle *viewHandle); 
    
    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the ZwDrawingViewAuxiliaryCreate().

    @see ZwDrawingViewAuxiliaryCreate

    @param [out] data Auxiliary view data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewAuxiliaryCreateInit(szwAuxiliaryViewData *data);

    /**
    @ingroup ZwDrawingView

    Creates an auxiliary view for base view in drawing.

    Function Guide:Drawing->layout->View->Auxiliary Section

    @see ZwDrawingViewAuxiliaryCreateInit

    @note
    Interface ZwDrawingViewAuxiliaryCreateInit() can initialize variables of this function.
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @param [in] data auxiliary view data
    @param [out] viewHandle handle data of the view created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwDrawingViewAuxiliaryCreate(szwAuxiliaryViewData data, szwEntityHandle *viewHandle);

    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the ZwDrawingViewBreakLineCreate().

    @see ZwDrawingViewBreakLineCreate

    @param [out] data information we need when create break line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewBreakLineCreateInit(szwBreakLineData *data);

    /**
    @ingroup ZwDrawingView

    Creates a break line in drawing for base view in drawing.

    Function Guide:Drawing->layout->View->BreakLine

    @see ZwDrawingViewBreakLineCreateInit

    @note
    Interface ZwDrawingViewBreakLineCreateInit() can initialize variables of this function.
    The caller is responsible to free the breakLineHandle by using ZwEntityHandleFree().

    @param [in] data information needed when create break line
    @param [out] breakLineHandle handle of break line that will create (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewBreakLineCreate(szwBreakLineData data, szwEntityHandle *breakLineHandle);    

    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the ZwDrawingViewDetailCreate().

    @see ZwDrawingViewDetailCreate

    @param [out] data Drawing Detail input information

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewDetailCreateInit(szwDrawingDetailData *data);

    /**
    @ingroup ZwDrawingView

    Creates a local detail view for base view in drawing.

    Function Guide:Drawing->layout->View->Detail 

    @see ZwDrawingViewDetailCreateInit

    @note
    Interface ZwDrawingViewDetailCreateInit() can initialize variables of this function.
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @param [in] data detail data
    @param [out] viewHandle handle data of detail view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewDetailCreate(szwDrawingDetailData data, szwEntityHandle *viewHandle);

    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the ZwDrawingViewBrokenSectionCreate().

    @see ZwDrawingViewBrokenSectionCreate

    @param [out] data Drawing Broken Section input information

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewBrokenSectionCreateInit(szwDrawingBrokenSectionData *data);

    /**
    @ingroup ZwDrawingView

    Creates a broken section.
    A broken section is a cut-away view of the interior of a part.
    It is a section view displayed inside a 2D boundary where an existing view of the part has been cut away.

    Function Guide:Drawing->layout->View->Broken Section

    @see ZwDrawingViewBrokenSectionCreateInit

    @verbatim
    | method(ezwDrawingBoundaryMethod) | the range of values of "countBoundaryPoint" |
    | ZW_RECTANGULAR_BOUNDARY          |    countBPs == 2                  |
    | ZW_CIRCULAR_BOUNDARY             |    countBPs == 2                  |
    | ZW_POLYLINE_BOUNDARY             |    countBPs >= 3                  |
    | ZW_SPLINE_BOUNDARY               |    countBPs >= 3                  |
    @endverbatim

    @note
    Interface ZwDrawingViewBrokenSectionCreateInit() can initialize variables of this function.
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @param [in] data broken section data
    @param [out] viewHandle handle data of section view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewBrokenSectionCreate(szwDrawingBrokenSectionData data, szwEntityHandle *viewHandle);  

    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the ZwDrawingViewFullSectionCreate().

    @param [out] data full section view data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewFullSectionCreateInit(szwFullSectionViewData *data);
        
    /**
    @ingroup ZwDrawingView

    Creates a full section view for base view in drawing.

    Function Guide:Drawing->layout->View->Full Section

    @note
    Interface ZwDrawingViewFullSectionCreateInit() can initialize variables of this function.
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @param [in] data full section view data
    @param [out] viewHandle handle data of the view created (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_eXEC_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OBJ
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewFullSectionCreate(szwFullSectionViewData data, szwEntityHandle *viewHandle);

    //====================================================================================================================
    /** @name View Query */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingView

    Gets the coordinates of the four vertices of the border.

    @param [in] viewHandle handle data of view
    @param [out] coordinate the coordinates of the four vertices of the border.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    szwDrawingDottedBorder coordinate{};
    ezwErrors ret = ZwDrawingViewDottedBorderGet(viewHandle,&coordinate);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewDottedBorderGet(szwEntityHandle viewHandle, szwDrawingDottedBorder *coordinate);

    /**
    @ingroup ZwDrawingView

    Gets shape or sketch handle that geometry in view specified by geometryHandle can be traced back to.
    The file name, part name or reference component handle data is also output if one of them is no NULL.

    @note
    The caller is responsible to free the component by using ZwEntityHandleFree().
    The caller is responsible to free the geometry3DHandle by using ZwEntityHandleFree().
    The caller is responsible to free the shapeHandle by using ZwEntityHandleFree().

    @param [in] geometryHandle handle data of geometry in view
    @param [in] fileNameBytes maximum bytes that fileName can hold
    @param [out] fileName file name of the component of view of line, it can be NULL
    @param [in] partNameBytes maximum bytes that partName can hold
    @param [out] partName part name of the component of view of line, it can be NULL
    @param [out] component reference component handle, it can be NULL
    @param [out] geometry3DHandle handle data of geometry 3D corresponding to geomId, it can be NULL
    @param [out] referenceEntityHandle shape or sketch handle that geometry in view specified by geometryHandle can
                         be traced back to, it can be NULL

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_ENT_PATH_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewGeometryReferenceEntityGet(szwEntityHandle geometryHandle, int fileNameBytes, char *fileName, int partNameBytes, char *partName,
                                                               szwEntityHandle *component, szwEntityHandle *geometry3DHandle, szwEntityHandle *referenceEntityHandle);
    /**
    @ingroup ZwDrawingView

    Gets the geometry handle list depending on the option.

    @note
    The caller is responsible to free the geometryList by using ZwEntityHandleListFree().

    @param [in] viewHandle view handle data
    @param [in] option indicate which type of geometry to obtain. Detail can refer to description.
    @param [out] countGeometry number of list
    @param [out] geometryList pointer to pointer of geometry handle array

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewGeometryListGet(szwEntityHandle viewHandle, ezwDrawingGeometryType option, int *countGeometry, szwEntityHandle **geometryList);
    
    /**
    @ingroup ZwDrawingView

    Associates the specified 2D entities to a drawing view. associated entities will be considered
    part of drawing view and will act accordingly during commands that affect the entire view.
    only one view may be associated with an entity, therefore after an entity is associated with a drawing
    view, it is disassociated from other drawing views.

    @see ZwDrawingViewEntityDisassociate

    @note
    The caller is responsible to free the entityList using ZwEntityHandleListFree().

    @param [in] viewHandle handle of view
    @param [in] count number of entities
    @param [in] entityList list of entity handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    int count = 0;
    szwEntityHandle* entityList = nullptr;
    // some code to get the data of entity handles
    ...

    ezwErrors ret = ZwDrawingViewEntityAssociate(viewHandle, count, entityList);
    ...

    // free memory of handle
    ZwEntityHandleListFree(count, &entityList);
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewEntityAssociate(szwEntityHandle viewHandle, int count, const szwEntityHandle *entityList);
    
    /**
    @ingroup ZwDrawingView

    Outputs a list of drawing views whose reference view is the specified drawing view.

    @note
    The caller is responsible to free the viewList using ZwEntityHandleListFree().

    @param [in] viewHandle handle of view
    @param [out] count number of child views
    @param [out] viewList list of child view handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    int count = 0;
    szwEntityHandle* viewList = nullptr;
    ezwErrors ret = ZwDrawingViewChildViewListGet(viewHandle, &count, &viewList);
    ...

    // free memory of view handles
    ZwEntityHandleListFree(count, &viewList);
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewChildViewListGet(szwEntityHandle viewHandle, int *count, szwEntityHandle **viewList);

    /**
    @ingroup ZwDrawingView

    Gets the attribute data of specified view. if handle of view is nullptr, the 
    function will get the default variables for view layout attributes used.

    @see ZwDrawingViewAttributeSet
    @see ZwDrawingViewLineAttributeGet
    @see ZwDrawingViewLineAttributeSet

    @param [in] viewHandle handle of view (nullptr to get the default variables)
    @param [out] data view attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    szwViewAttribute data = {};
    ezwErrors ret = ZwDrawingViewAttributeGet(&viewHandle, &data);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewAttributeGet(const szwEntityHandle *viewHandle, szwViewAttribute *data);

    /**
    @ingroup ZwDrawingView

    Sets the attribute of specified view. If handle of view is nullptr, the 
    function will set the default variables for view layout attributes.

    @see ZwDrawingViewAttributeGet
    @see ZwDrawingViewLineAttributeGet
    @see ZwDrawingViewLineAttributeSet

    @param [in] viewHandle handle of view (nullptr to set the default variables)
    @param [in] data view attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    szwViewAttribute data = {};
    ezwErrors ret = ZwDrawingViewAttributeGet(&viewHandle, &data);
    ...
    ret = ZwDrawingViewAttributeSet(&viewHandle, &data);

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewAttributeSet(const szwEntityHandle *viewHandle, szwViewAttribute data);

    //====================================================================================================================
    /** @name View Create */
    //====================================================================================================================

    /**
    @ingroup ZwDrawingView

    Initializes the parameters of szwProjectionViewData.

    @note
    Do not assign a value to variable "data" before calling this function.

    @param [out] data projection view data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewProjectionInit(szwProjectionViewData *data);

    /**
    @ingroup ZwDrawingView

    Inserts projection view.
    This function can create a view projected from another existing 3D layout view.
    This interface is used in the engineering drawing environment.  
    Function Guide: Layout -> View ->Projection  

    @note
    The caller is responsible to free the projectionView by using ZwEntityHandleFree().

    @param [in] data projection view attribute
    @param [out] projectionView handle of projection view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewProjection(szwProjectionViewData data, szwEntityHandle *projectionView);

    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the szwViewStandardData.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwDrawingViewStandardCreate

    @param [out] data szwViewStandardData data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewStandardDataInit(szwViewStandardData *data);

    /**
    @ingroup ZwDrawingView

    Inserts Standard View.
    Use this function to create a standard orthographic layout view from a 3D part.  
    If the part has named views created using the View Manager, they can also be inserted as a standard view.  
    This interface is used in the engineering drawing environment.  
    Function Guide: Layout -> View ->Standard  

    @note
    Interface ZwDrawingViewStandardDataInit initializes the szwViewStandardData structure.
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree().

    @see ZwDrawingViewStandardDataInit

    @param [in] data standard setting info
    @param [out] viewHandle handle of standard view(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwDrawingViewStandardCreate(szwViewStandardData data, szwEntityHandle *viewHandle);

    //====================================================================================================================
    /** @name View State */
    //====================================================================================================================

    /**
    @ingroup ZwDrawingView

    Gets the hidden state by referencing the entity handle.
    Notice that the reference can not be the top level of the reference file,
    which means you can not blank the entire file.

    @param [in] reference  handle of reference entity
    @param [out] blank  status of reference entity(1 is blank,else display)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwDrawingViewReferenceBlankGet(szwEntityHandle reference, int *blank);

    /**
    @ingroup ZwDrawingView

    Sets the hidden state by referencing the entity handle.
    Notice that the reference can not be the top level of the reference file,
    which means you can not blank the entire file.

    @param [in] reference  handle of reference entity
    @param [in] blank  status of reference entity(1 is blank,else display)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwDrawingViewReferenceBlankSet(szwEntityHandle reference, int blank);

    //====================================================================================================================
    /** @name View Attribute */
    //====================================================================================================================

    /**
    @ingroup ZwDrawingView

    Gets the wireframe attributes of specified reference entity.

    @param [in] reference handle of reference entity
    @param [out] colorValid 1 from attribute; 0 inherited from view
    @param [out] typeValid 1 from attribute; 0 inherited from view
    @param [out] widthValid 1 from attribute; 0 inherited from view
    @param [out] wireAttribute wireframe attributes, attribute items that are
                       not inherit from view is valid

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewReferenceAttributeGet(szwEntityHandle reference, int *colorValid, int *typeValid, int *widthValid, szwLineAttribute *wireAttribute);

    /**
    @ingroup ZwDrawingView

    Sets the wireframe attributes of specified reference entity.

    @param [in] reference handle of reference entity
    @param [in] colorValid 1 to set base on attribute; 0 to inherit view
    @param [in] typeValid 1 to set base on attribute; 0 to inherit view
    @param [in] widthValid 1 to set base on attribute; 0 to inherit view
    @param [in] wireAttribute wireframe attributes, attribute items that are
                      not inherit from view are set

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_aPI_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewReferenceAttributeSet(szwEntityHandle reference, int colorValid, int typeValid, int widthValid, szwLineAttribute wireAttribute);

    //====================================================================================================================
    /** @name Edit View */
    //====================================================================================================================

    /**
    @ingroup ZwDrawingView

    Initializes the parameters of the szwDrawingRotateViewData.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @param [out] data Rotate View data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingRotateViewDataInit(szwDrawingRotateViewData *data);

    /**
    @ingroup ZwDrawingView

    Rotate view with the parameters of the szwDrawingRotateViewData.
    Function Guide: Drawing->Layout->Edit View->Rotate View.

    @note
    Interface ZwDrawingRotateViewDataInit() can initialize variables of this function.

    @see ZwDrawingViewRotate

    @param [in] viewHandle handle of rotate view
    @param [in] data rotate settings

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewRotate(szwEntityHandle viewHandle, szwDrawingRotateViewData data);
	
    /**
    @ingroup ZwDrawingView

    Outputs parent view of the specified view.  
    parentViewHandle = NULL if there is no parent view in specified view.

    @note
    The caller is responsible to free the parentViewHandle by using ZwEntityHandleFree().

    @param [in] viewHandle view handle
    @param [out] parentViewHandle parent view of view specified by "viewHandle"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewParentViewGet(szwEntityHandle viewHandle, szwEntityHandle *parentViewHandle);
    
    /**
    @ingroup ZwDrawingView

    Outputs reference part information of the specified drawing view.

    @param [in] viewHandle handle of view (NULL to get the active view for the sheet)
    @param [out] part reference part

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    szwReferencePart data = {};
    ezwErrors ret = ZwDrawingViewReferencePartGet(&viewHandle, &data);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewReferencePartGet(const szwEntityHandle *viewHandle, szwReferencePart *part);

    //====================================================================================================================
    /** @name View Query */
    //====================================================================================================================
    /**
    @ingroup ZwDrawingView

    Outputs the coordinate and entity handle of the projection point in the active drawing of the 
    origin of the reference part of the specified drawing view.

    @note
    The caller is responsible to free the projectionOriginalPoint by using ZwEntityHandleFree().

    @param [in] viewHandle handle of view
    @param [out] point the projection point of the origin point of the reference part
    @param [out] projectionOriginalPoint handle of the projection point of the origin point of the reference part (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    szwPoint2 point = {};
    szwEntityHandle projectionOriginalPoint = {};
    ezwErrors ret = ZwDrawingView3DOriginalPointGet(viewHandle, &point, &projectionOriginalPoint);
    ...

    // free memory of handle
    ZwEntityHandleFree(&projectionOriginalPoint);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingView3DOriginalPointGet(szwEntityHandle viewHandle, szwPoint2 *point, szwEntityHandle *projectionOriginalPoint);

    /**
    @ingroup ZwDrawingView

    Outputs the config name in the config table of the reference part of the drawing view.

    @param [in] viewHandle handle of view (NULL to get the active view for the sheet)
    @param [out] config the config name of the reference part
    @param [in] size max size of config

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    zwString256 config = {};
    ezwErrors ret = ZwDrawingViewReferencePartConfigGet(&viewHandle, config, sizeof(config));
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewReferencePartConfigGet(const szwEntityHandle *viewHandle, int size, char *config);

    /**
    @ingroup ZwDrawingView

    Gets the creation method of the specified view.  

    @param [in] viewHandle handle of view
    @param [out] method the creation method of view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    ezwDrawingViewMethod method = ZW_VIEW_NULL;
    ezwErrors ret = ZwDrawingViewMethodGet(viewHandle, &method);
    ...

    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewMethodGet(szwEntityHandle viewHandle, ezwDrawingViewMethod *method);

    /**
    @ingroup ZwDrawingView

    Outputs a list of the view reference handles in the special view.

    @note
    The caller is responsible to free the entityHandleList by using ZwEntityHandleListFree().

    @param [in] viewHandle view handle in drawing
    @param [out] count number of view reference
    @param [out] entityHandleList list of view reference handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewReferenceGet(szwEntityHandle viewHandle, int *count, szwEntityHandle **entityHandleList);


    //====================================================================================================================
    /** @name View Query */
    //====================================================================================================================
    
    /**
    @ingroup ZwDrawingView

    Outputs the coordinate of the location point of the specified drawing view.  
    The location point lies in the bottom left corner of the drawing view.  

    @param [in] viewHandle handle of view
    @param [out] point the location point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    szwPoint2 point = {};
    ezwErrors ret = ZwDrawingViewLocationPointGet(viewHandle, &point);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewLocationPointGet(szwEntityHandle viewHandle, szwPoint2 *point);
    
    /**
    @ingroup ZwDrawingView

    Gets all dimensions associated with the specified view, both visible and hidden.

    @note  
    The caller is responsible to free the dimensions by using ZwEntityHandleListFree().

    @see ZwEntityBlankGet

    @param [in] viewHandle view handle
    @param [in] type view dimension type to query
    @param [out] count number of dimensions
    @param [out] dimensions list of dimension handles 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle;
    // some code to get the data of viewHandle
    ...

    int count = 0;
    szwEntityHandle* dimensions = NULL;
    ezwErrors ret = ZwDrawingViewDimensionListGet(viewHandle, ZW_VIEW_ALL_DIMENSION, &count, &dimensions);

    // free memory of handles
    ZwEntityHandleListFree(count, &dimensions);
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewDimensionListGet(szwEntityHandle viewHandle, ezwViewDimensionType type, int *count, szwEntityHandle **dimensions);

    /**
    @ingroup ZwDrawingView
    
    Gets 3D point in part coordinates corresponding to a pick point on an entity in a drawing sheet view.
    The 3D coordinates are output in point3D.
    
    @param [in] handle point handle in view
    @param [out] point3D 3D point position
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewPoint2DTo3D(szwEntityHandle handle, szwPoint *point3D);

    /**
    @ingroup ZwDrawingView

    Gets 2D point value in drawing sheet corresponding to a 3D point
    value in the part. The 2D coordinate is output in point2D and it is
    converted from the matrix of view.

    @param [in] viewHandle view handle in drawing
    @param [in] point3D 3D point
    @param [out] point2D 2D point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewPoint3DTo2D(szwEntityHandle viewHandle, szwPoint point3D, szwPoint2 *point2D);
    
    
    /**
    @ingroup ZwDrawingView

    This api will block util view completely generates all geometries.

    @note 
    If geometries are not generated, api which associated with them will return error.  
    Such as ZwDrawingViewGeometryListGet() will return error because there is no line generated in view.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwDrawingViewDiscreteProjectionWait();

    /**
    @ingroup ZwDrawingView

    Gets the option of discrete projection in drawing.

    @param [out] option 1 - discrete projection is enabled, 0 - it is disabled.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewDiscreteProjectionGet(int *option);

    /**
    @ingroup ZwDrawingView

    Enables or disables discrete projection in drawing.

    @note
    This setting will take effect after you create a new drawing file.

    @param [in] option 1 to enable discrete projection, 0 to disable it.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewDiscreteProjectionSet(int option);

    /**
    @ingroup ZwDrawingView

    Gets the quality of discrete projection which taking effect on drawing.

    @param [out] quality quality of discrete projection.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewDiscreteProjectionQualityGet(ezwDrawingDiscreteProjectionQuality *quality);

    /**
    @ingroup ZwDrawingView

    Sets the quality of discrete projection.  
    When quality set to ZW_DRAWING_DISCRETE_PROJECT_DISCRETE, there will no geometries are generated in view.

    @note
    This setting will take effect after you create a new drawing file.

    @param [in] quality quality of discrete projection.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewDiscreteProjectionQualitySet(ezwDrawingDiscreteProjectionQuality quality);

        /**
    @ingroup ZwDrawingView

    Gets the state of discrete projection of the specified view.

    @Note
    When it's not a discrete projection, the return value will be assigned ZW_DRAWING_DISCRETE_PROJECT_NOT_DISCRETE.
    When the Discrete View Generation mode is "Discrete", the return value will be assigned ZW_DRAWING_DISCRETE_PROJECT_LOW_QUALITY.
    When the Discrete View Generation mode is "Precise",  if the calculation of 2D geometry data 2D is not completed,
    the return value will be assigned ZW_DRAWING_DISCRETE_PROJECT_HIGH_QUALITY_PRE, and if the calculation of 2D geometry data 2D is completed,
    the return value will be assigned ZW_DRAWING_DISCRETE_PROJECT_HIGH_QUALITY.
    

    @param [in] viewHandle View Handle.
    @param [out] discreteProjectionState the state of discrete projection state.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwDrawingViewDiscreteProjectionStateGet(szwEntityHandle viewHandle,
                                                               ezwDrawingDiscreteProjectionState *discreteProjectionState);

    /**
    @ingroup ZwDrawingView

    Checks whether there are views in calculating 2D geometry data of discrete projection in current file.
    
    @param [out] isInCalculating whether exists view in calculating 2D geometry data of discrete projection.
                                    1 - exist, 0 - not exist.
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwDrawingDiscreteProjectionStateCheck(int *isInCalculating);

    /**
    @ingroup ZwDrawingView

    Gets the option of auto load geometry in drawing.

    @param [out] option 1 - auto load geometry option is enabled, 0 - it is disabled.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewAutoLoadGeometryGet(int *option);

    /**
    @ingroup ZwDrawingView

    Enables or disables auto load geometry in drawing.  
    Enables this option will automatically generate geometry in views even if the
    discrete projection quality is ZW_DRAWING_DISCRETE_PROJECT_DISCRETE.

    @note
    This setting will take effect after you create a new drawing file.

    @param [in] option 1 to enable auto load geometry option, 0 to disable it.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwDrawingViewAutoLoadGeometrySet(int option);

    /**
    @ingroup ZwDrawingView

    Determines whether the orientation of the view is based on the parent object.

    @param [in] viewHandle handle of view
    @param [out] isFromParent 1 if view orientation from parent, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
       int isFromParent = -1;
       szwEntityHandle viewHandle{};
       ...// some code to get the data of viewHandle
       ZwDrawingViewOrientationFromParentGet(viewHandle, &isFromParent);
       ...
       ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewOrientationFromParentGet(szwEntityHandle viewHandle, int *isFromParent);

    /**
    @ingroup ZwDrawingView

    Set whether the orientation of the view is based on the parent object.

    @param [in] viewHandle handle of view
    @param [in] isFromParent 1 if view orientation from parent, else 0

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
       int isFromParent = -1;
       szwEntityHandle viewHandle{};
       ... // some code to get the data of viewHandle
       ZwDrawingViewOrientationFromParentSet(viewHandle, isFromParent);
       ...
       ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewOrientationFromParentSet(szwEntityHandle viewHandle, int isFromParent);

    /**
    @ingroup ZwDrawingView

    Gets the type of the specified view.
    It can't get the corresponding type if "*type = ZW_DRAWING_ALL_VIEW".

    @see ZwDrawingViewMethodGet

    @param [in] viewHandle handle of view
    @param [out] type type of view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    ezwDrawingViewType type = ZW_DRAWING_ALL_VIEW;
    ezwErrors ret = ZwDrawingViewTypeGet(viewHandle, &type);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewTypeGet(szwEntityHandle viewHandle, ezwDrawingViewType *type);

    /**
    @ingroup ZwDrawingView

    Gets the attribute data for the specified view line type in the specified view. If handle of view is nullptr,
    the function will get the default variables for view layout attributes used.

    @see ZwDrawingViewAttributeGet
    @see ZwDrawingViewAttributeSet
    @see ZwDrawingViewLineAttributeSet

    @param [in] viewHandle handle of view (nullptr to get the default variables)
    @param [in] lineType type of view line
    @param [out] lineAttr line attributes (nullptr to ignore)
    @param [out] layer layer (nullptr to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    szwLineAttribute lineAttr = {};
    szwViewObjectLayerData layer = {};
    ezwErrors ret = ZwDrawingViewLineAttributeGet(&viewHandle, ZW_VISIBLE_LINE, &lineAttr, &layer);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewLineAttributeGet(const szwEntityHandle *viewHandle, ezwViewLineType lineType, szwLineAttribute *lineAttr, szwViewObjectLayerData *layer);

    /**
    @ingroup ZwDrawingView

    Sets the attribute data for the specified view line type in the specified view. If handle of view is nullptr,
    the function will set the default variables for view layout attributes used.

    @see ZwDrawingViewAttributeGet
    @see ZwDrawingViewAttributeSet
    @see ZwDrawingViewLineAttributeGet

    @param [in] viewHandle handle of view (nullptr to get the default variables)
    @param [in] lineType type of view line
    @param [in] lineAttr line attributes (nullptr to ignore)
    @param [in] layer layer of line (nullptr to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    szwEntityHandle viewHandle;
    // some code to get the data of viewHandle
    ...

    szwLineAttribute lineAttr = {};
    szwViewObjectLayerData layer = {};
    ezwErrors ret = ZwDrawingViewLineAttributeGet(&viewHandle, ZW_VISIBLE_LINE, &lineAttr, &layer);
    ...
    ret = ZwDrawingViewLineAttributeSet(&viewHandle, ZW_VISIBLE_LINE, &lineAttr, &layer);

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewLineAttributeSet(const szwEntityHandle *viewHandle, ezwViewLineType lineType, const szwLineAttribute *lineAttr, const szwViewObjectLayerData *layer);

    /**
    @ingroup ZwDrawingView

    Lock or unlock the location of the specified view, the locked view can not be moved.

    @see ZwDrawingViewLocationLockGet

    @param [in] viewHandle handle of view
    @param [in] lock lock state (1: lock; 0: unlock)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    int lock = 0;
    ezwErrors ret = ZwDrawingViewLocationLockSet(viewHandle, lock);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewLocationLockSet(szwEntityHandle viewHandle, int lock);

    /**
    @ingroup ZwDrawingView

    Determine whether the specified view is locked.

    @see ZwDrawingViewLocationLockSet

    @param [in] viewHandle handle of view
    @param [out] lock lock state (1: lock; 0: unlock)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    int lock = 0;
    ezwErrors ret = ZwDrawingViewLocationLockGet(viewHandle, &lock);
    ...

    // free memory of view handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewLocationLockGet(szwEntityHandle viewHandle, int *lock);


    /**
    @ingroup ZwDrawingView

    Disassociate the specified 2D entities from drawing view.

    @see ZwDrawingViewEntityAssociate

    @param [in] count number of entities
    @param [in] entityList list of entity handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    int count = 0;
    szwEntityHandle* entityList = nullptr;
    // some code to get the data of entity handles
    ...

    ezwErrors ret = ZwDrawingViewEntityDisassociate(count, entityList);
    ...

    // free memory of handle
    ZwEntityHandleListFree(count, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewEntityDisassociate(int count, const szwEntityHandle *entityList);

    /**
    @ingroup ZwDrawingView

    Gets the alignment state of the specified drawing view. The aligned view cannot move
    independently, but instead moves with the reference view.

    @see ZwDrawingViewAlignmentStateSet

    @param [in] viewHandle handle of view
    @param [out] alignmentState the alignment state (1: on; 0: off)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    int alignmentState = 0;
    ezwErrors ret = ZwDrawingViewAlignmentStateGet(viewHandle, &alignmentState);
    ...

    // free memory of handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewAlignmentStateGet(szwEntityHandle viewHandle, int *align);

    /**
    @ingroup ZwDrawingView

    Sets the alignment state of the specified drawing view. the aligned view cannot move
    independently, but instead moves with the reference view.

    @see ZwDrawingViewAlignmentStateGet

    @param [in] viewHandle handle of view
    @param [in] alignmentState the alignment state (1: on; 0: off)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
    szwEntityHandle viewHandle = {};
    // some code to get the data of viewHandle
    ...

    int alignmentState = 0;
    ezwErrors ret = ZwDrawingViewAlignmentStateSet(viewHandle, alignmentState);
    ...

    // free memory of handle
    ZwEntityHandleFree(&viewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwDrawingViewAlignmentStateSet(szwEntityHandle viewHandle, int align);

    /**
    @ingroup ZwDrawingView

    Sets the blank status for multiple reference entities in the same view.  
    Notice that the reference can not be the top level of the reference file,  
    which means it can not blank the entire file.

    @note
    After calling this, the user can use "cvxDwgRegen" to regenerate the view and its associate view.

    @param [in] count  number of reference entities
    @param [in] referenceList  handle list of the reference entities
    @param [in] blank  status (1: blank, 0: display)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwDrawingViewReferenceListBlankSet(int count, const szwEntityHandle *referenceList, int blank);

    /**
    @ingroup ZwDrawingView

    Gets the type of projection in the active drawing.

    @param [out] type the type of current drawing's projection.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_ROOT_ERROR
    */
    ZW_API_C ezwErrors ZwDrawingViewProjectionTypeGet(ezwViewProjectionType *type);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_DRAWING_VIEW_H */
