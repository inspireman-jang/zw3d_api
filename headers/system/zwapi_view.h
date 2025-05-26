/**
@file zwapi_view.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D View API
*/
/**
@defgroup zwapi_view View
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D View API
*/

#pragma once
#ifndef ZW_API_VIEW_H /* this ifndef surrounds entire header */
#define ZW_API_VIEW_H

#include "zwapi_util.h"
#include "zwapi_view_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name View Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_view

    @deprecated This API will not be updated anymore, please use ZwSectionViewCheck()

    @see ZwSectionViewCheck

    Determine whether the view is a section view.

    @param [in] idView id view

    @retval succeeds
    -        1 - it is section view
    -        0 - it is not section view
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C int cvxViewIsSection(int idView);

    /**
@ingroup zwapi_view

Determine whether the view is a standard view.

@param [in] idView id view

@retval succeeds
-        1 - it is standard view
-        0 - it is not standard view
@retval fail
-        ZW_API_INVALID_INPUT
-        ZW_API_ROOT_OBJ_ACT_FAIL
-        ZW_API_OBJ_TYPE_ERROR
*/
    ZW_API_C int cvxViewIsStandard(int idView);

    /**
    @ingroup zwapi_view

    Gets the specified type of the standard view.

    @param [in] idView id view
    @param [out] type view type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxViewInqStandardType(int idView, evxViewStd *type);

    //====================================================================================================================
    /** @name View Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_view

    Activate the specified view.

    @param [in] idView id view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C evxErrors cvxViewActivate(int idView);

    /**
    @ingroup zwapi_view

    Sets the active view extent.

    @param [in] Extent view extent (mm)

    */
    ZW_API_C void cvxViewExtent(double Extent);

    /**
    @ingroup zwapi_view

    Retrieves the position, orientation and extent of the active view.

    @param [out] Frame align active view with specified coordinate frame
    @param [out] Extent view extent

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_MEMORY
    */
    ZW_API_C void cvxViewGet(svxMatrix *Frame, double *Extent);

    /**
    @ingroup zwapi_view

    Aligns the active view with the specified frame and
    sets the specified view extent.

    @param [in] Frame align active view with specified coordinate frame
    @param [in] Extent view extent

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxViewSet(svxMatrix *Frame, double Extent);

    /**
    @ingroup zwapi_view

    Moves the origin of the active view to the specified point.

    @param [in] Origin new view origin

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxViewOrigin(svxPoint *Origin);

    /**
    @ingroup zwapi_view

    Changes the orientation of the active view (part, sketch, cam plan)  
    to the specified standard view type and then does a "zoom all".

    @note
    the input view extent is only used if the "zoom all"
    doesn't find any geometry.

    @param [in] Type standard view type
    @param [in] NullExtent view extent used if no geometry

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxViewStd(evxViewStd Type, double NullExtent);

    /**
    @ingroup zwapi_view

    Make specified bounding box visible in world coordinates.

    @param [in] Scale scale factor
    @param [in] BndBox the 3D bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxViewSetBndBox(double Scale, const svxBndBox *BndBox);

    /**
    @ingroup zwapi_view

    Get the global or client coordinates of active View.

    @param [in] includeFrame 1=include window frame; 0=exclude window frame;
    @param [in] isGlobal 1=get global coordinates; 0=get client coordinates;
    @param [out] tlX top left X
    @param [out] tlY top left Y
    @param [out] brX bottom right X
    @param [out] brY bottom right Y

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxGetViewRect(int includeFrame, int isGlobal, int *tlX, int *tlY, int *brX, int *brY);

    //====================================================================================================================
    /** @name Custom  View */
    //====================================================================================================================
    /**
    @ingroup zwapi_view

    Add a custom view.

    @param [in] Name custom view name
    @param [in] LyrVis store current layer visibility(1 to store, 0 not to store)
    @param [in] ObjVis store current object visibility(1 to store, 0 not to store)
    @param [out] idView index of view (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCustomViewAdd(char *Name, int LyrVis, int ObjVis, int *idView);

    /**
    @ingroup zwapi_view

    Changes the orientation of the active view (part, sketch, cam plan)  
    to the specified custom view type and then does a "zoom all".

    @note
    the input view extent is only used if the "zoom all"
    doesn't find any geometry.

    @param [in] idView index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C evxErrors cvxCustomViewActivate(int idView);

    /**
    @ingroup zwapi_view

    Delete specified custom view.

    @note
    the view can not be the current active view.

    @param [in] idView index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C evxErrors cvxCustomViewDel(int idView);

    /**
    @ingroup zwapi_view

    Get index of custom view of specified name.

    @param [in] Name custom view name
    @param [out] idView index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxCustomViewId(vxName Name, int *idView);

    /**
    @ingroup zwapi_view

    Get index list of custom view in active file.

    This function allocates memory for the array output via "customViewList". The calling
    procedure is responsible for deallocating the memory.

    @param [out] count number of index in list
    @param [out] customViewList index of custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV*/
    ZW_API_C evxErrors cvxCustomViewListGet(int *count, int **customViewList);

    //====================================================================================================================
    /** @name General View */
    //====================================================================================================================
    /**
    @ingroup ZwGeneralView

    Retrieves the position, orientation and extent of the active view.

     @param [out] frame align active view with specified coordinate frame
     @param [out] extent view extent

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_MEMORY

    @code
       szwMatrix frame{};
       double extent{};
       ZwViewParameterGet(&frame,&extent);
    @endcode
    */
    ZW_API_C ezwErrors ZwViewParameterGet(szwMatrix *frame, double *extent);

    /**
    @ingroup ZwGeneralView

    Aligns the active view with the specified frame and sets the specified view extent.

     @param [in] frame align active view with specified coordinate frame
     @param [in] extent view extent

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_MEMORY

    @code
       szwMatrix frame=...;
       double extent=...;
       ...
       ZwViewParameterSet(frame,extent);
    @endcode
    */
    ZW_API_C ezwErrors ZwViewParameterSet(szwMatrix frame, double extent);

    /**
    @ingroup ZwGeneralView

    Get the matrix view of the entity.

    @note
    If viewHandle is nullptr, get the matrix of the active view.

    @param [in] viewHandle the handle of selected view, if nullptr, get the matrix of the active view.
    @param [out] viewMatrix the matrix of selected view

    @retval succeeds
    -        ZW_API_NO_ERROR

    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwViewMatrixGet(const szwEntityHandle *viewHandle, szwMatrix *viewMatrix);

    /**
    @ingroup ZwGeneralView

    Get the transform matrix between two view.

    @note
    If isReverse is 0, it means:transMat*sourceView matrix=destView matrix;
    else if isReverse is 1, it means:transformMatrix*destView matrix=sourceView matrix.

    @param [in] sourceView the handle of view
    @param [in] destinationView the handle of view
    @param [in] isReverse reverse or not
    @param [out] transformMatrix transform matrix

    @retval succeeds
    -        ZW_API_NO_ERROR

    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    szwEntityHandle sourceView=...;
    szwEntityHandle destView=...;
    int isReverse=0;//not reverse
    szwMatrix transMat{};
    ZwViewTransformMatrixGet(sourceView,destView,isReverse, &transMat);
    @endcode
    */
    ZW_API_C ezwErrors ZwViewTransformMatrixGet(szwEntityHandle sourceView, szwEntityHandle destinationView, int isReverse, szwMatrix *transformMatrix);

    //====================================================================================================================
    /** @name Custom View */
    //====================================================================================================================
    /**
    @ingroup ZwCustomView

    Get the name of specified custom view.

    @param [in] viewHandle view handle data
    @param [in] nameLength the length of custom view 
    @param [out] customViewName the name of the custom view 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
  
    @code
       szwEntityHandle viewHandle=...;
       int nameLength=...;
       zwString32 customViewName{};
       ...
       ZwCustomViewNameGet(viewHandle,nameLength, customViewName);
       ...
       ZwEntityHandleFree(&sectionViewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCustomViewNameGet(szwEntityHandle viewHandle, int nameLength, char *customViewName);

    /**
    @ingroup ZwCustomView

    Modify the name of  the specified custom view. After modify name of section view, users should call ZwCommandSend("~CdGuiUpdate")
    to refresh the section view name.

    @note
    The viewNewName can not be the same as any existing entity or section view.
    The viewNewName must less than 32 bits.

    @param [in] viewHandle view handle data
    @param [in] viewNewName the new name of the specified custom view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_NAME
    -        ZW_API_OBJ_TYPE_ERROR
 
    @code
        szwEntityHandle sectionViewHandle=...;
        zwString32 newName;
        ...
        ZwCustomViewNameSet(sectionViewHandle, newName);
        ZwCommandSend("~CdGuiUpdate");
        ...
        ZwEntityHandleFree(&sectionViewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCustomViewNameSet(szwEntityHandle viewHandle, const zwString32 viewNewName);

    /**
    @ingroup ZwCustomView

    Get the specified custom view by name.

    @note
    When there is no view with the specified name, it will return ZW_API_NO_ERROR and the viewHandle.innerData obtained is Null.

    @param [in] viewName the name of the specified custom
    @param [out] viewHandle view handle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwEntityHandle viewHandleSearchBefore{};
        ...
        zwString32 viewNameSearchFor{};
        ...
        szwEntityHandle viewHandleSearchAfter{};
        ZwCustomViewGetByName(viewNameSearchFor, &viewHandleSearchAfter);
    @endcode
    */
    ZW_API_C ezwErrors ZwCustomViewGetByName(const zwString32 viewName, szwEntityHandle *viewHandle);

    //====================================================================================================================
    /** @name Section View */
    //====================================================================================================================
    /**
    @ingroup ZwSectionView

    Modify the name of section view. After modify name of section view, users should call ZwCommandSend("~CdGuiUpdate")
    to refresh the section view name.

    @note
    The newName can not be the same as any existing entity or section view.
    The newName must less than 32 bits.

    @param [in] sectionViewHandle handle of the section view
    @param [in] newName new name of the section view.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR

    @code
       szwEntityHandle sectionViewHandle=...;
       zwString32 newName{};
       ...
       ZwSectionViewNameSet(sectionViewHandle, newName);
       ZwCommandSend("~CdGuiUpdate");
       ...
       ZwEntityHandleFree(&sectionViewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewNameSet(szwEntityHandle sectionViewHandle, const zwString32 newName);

    /**
    @ingroup ZwSectionView

    Get the name of section view.

    @param [in] sectionViewHandle handle of the section view
    @param [in] nameLength the length of the section view
    @param [out] sectionViewName name of the section view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INPUT_TYPE_ERROR

    @code
       szwEntityHandle sectionViewHandle=...;
       int nameLength=...;
       zwString32 sectionViewName{};
       ...
       ZwSectionViewNameGet(sectionViewHandle,nameLength, sectionViewName);
       ...
       ZwEntityHandleFree(&sectionViewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewNameGet(szwEntityHandle sectionViewHandle, int nameLength, char *sectionViewName);

    /**
    @ingroup ZwSectionView

    Get the list of all section views.

    @note
    This function allocates memory for the array output via "sectionViews".
    The caller is responsible to free the sectionViews by using ZwEntityHandleListFree.

    @param [out] countOfSectionView count of section view
    @param [out] sectionViews  handles of the section view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
       int count = 0;
       szwEntityHandle* sectionViews = NULL;
       ZwSectionViewListGet(&count , &sectionViews);
       ...
       ZwEntityHandleListFree(count, &sectionViews);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewListGet(int *countOfSectionView, szwEntityHandle **sectionViews);

    /**
    @ingroup ZwSectionView

    Reverse the direction of specific section views.

    @note
    This api only takes effect on 3 types of section view(for more detail please see ezwSectionViewMode), including
    ZW_SECTION_VIEW_SECTION_AT_PLANE, ZW_SECTION_VIEW_SECTION_WITH_ENVELOPE and ZW_SECTION_VIEW_SECTION_WITH_SLICE.
    You can use ZwSectionViewParameterGet to get type of section view.

    @param [in] sectionViewHandle  handles of the section view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_MEMORY

    @code
          szwEntityHandle entityhandle=...;
          ...
          ZwSectionViewDirectionReverse(entityhandle);
          ...
          ZwEntityHandleFree(&entityhandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewDirectionReverse(szwEntityHandle sectionViewHandle);

    /**
    @ingroup ZwSectionView

    Get the parameter of specific section views.

    @note
    Interface ZwSectionViewParameterInit() can initialize variables attribute
    of section view of this function.  
    When sectionViewParameter->sectionViewMode = ZW_SECTION_VIEW_SECTION_AT_PLANE, it means section at plane.  
    sectionViewParameter->planeParameter.alignPlane ,sectionViewParameter->planeParameter.optionPlane  
    and sectionViewParameter->planePlacement.offset can be get.  
    sectionViewParameter->sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_ENVELOPE, it means section with envelope.  
    sectionViewParameter->planeParameter.alignPlane ,sectionViewParameter->planeParameter.optionPlane,  
    sectionViewParameter->planePlacement.top, sectionViewParameter->planePlacement.front,  
    sectionViewParameter->planePlacement.right, sectionViewParameter->planePlacement.left,  
    sectionViewParameter->planePlacement.back and sectionViewParameter->planePlacement.bottom can be get.  
    sectionViewParameter->sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_SLICE, it means section with slice.  
    sectionViewParameter->planeParameter.alignPlane ,sectionViewParameter->planeParameter.optionPlane,  
    sectionViewParameter->planePlacement.thickness and sectionViewParameter->planePlacement.offset can be get.  
    sectionViewParameter->sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_PROFILE, it means section with profile.  
    sectionViewParameter->planeParameter.profile, sectionViewParameter->planeParameter.startS and
    sectionViewParameter->planeParameter.endE can be get.  
    sectionViewParameter->sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_3_PLANES, it means section with 3 planes.  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane1IsTurnOn,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane2IsTurnOn,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane3IsTurnOn,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane1,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane2,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane3,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane1Offset,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane2Offset,  
    sectionViewParameter->planeParameter.threePlanesParameter.alignPlane3Offset can be get.  
    The each szwEntityHandle->innerData get from sectionViewParameter->planeParameter (profile,alignPlane,alignPlane1,
    alignPlane2 and alignPlane3) may be nullptr, indicates that there is no corresponding entity.

    @param [in] sectionViewHandle handle of the section view
    @param [out] sectionViewParameter parameter of section view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_MEMORY

    @code
       szwEntityHandle sectionViewHandle=...;
       szwSectionViewParameter sectionViewParameter{};
       ZwSectionViewParameterInit(&sectionViewParameter);
       ...
       ZwSectionViewParameterGet(sectionViewHandle, &sectionViewParameter);
       ...
       ZwEntityHandleFree(&sectionViewHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewParameterGet(szwEntityHandle sectionViewHandle, szwSectionViewParameter *sectionViewParameter);

    /**
    @ingroup ZwSectionView

    Initialize the parameter of section view.

    @note
    Do not assign a value to variable "sectionViewParameter" before calling this function.

    @param [out] sectionViewParameter attribute of section view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT

    @code
       ...
       szwSectionViewParameter sectionViewParameter;
       ZwSectionViewParameterInit(&sectionViewParameter);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewParameterInit(szwSectionViewParameter *sectionViewParameter);

    /**
    @ingroup ZwSectionView

    Create a new section view.

    @note
    Interface ZwSectionViewParameterInit() can initialize variables attribute
    of section view of this function.  
    When sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_AT_PLANE, it means section at plane.  
    sectionViewParameter.planeParameter.alignPlane ,sectionViewParameter.planeParameter.optionPlane  
    and sectionViewParameter.planePlacement.offset should be set.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_ENVELOPE, it means section with envelope.  
    sectionViewParameter.planeParameter.alignPlane ,sectionViewParameter.planeParameter.optionPlane,  
    sectionViewParameter.planePlacement.top, sectionViewParameter.planePlacement.front,  
    sectionViewParameter.planePlacement.right, sectionViewParameter.planePlacement.left,  
    sectionViewParameter.planePlacement.back and sectionViewParameter.planePlacement.bottom should be set.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_SLICE, it means section with slice.  
    sectionViewParameter.planeParameter.alignPlane ,sectionViewParameter.planeParameter.optionPlane,  
    sectionViewParameter.planePlacement.thickness and sectionViewParameter.planePlacement.offset should be set.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_PROFILE, it means section with profile.  
    sectionViewParameter.planeParameter.startS and sectionViewParameter.planeParameter.endE should be set.  
    sectionViewParameter.planeParameter.profile->innerData can not be NULL.  
    sectionViewParameter.planeParameter.profile must be set as entity with plane matrix such as sketch ,datum plane,
    face and so on.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_3_PLANES, it means section with 3 planes.  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane1IsTurnOn,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane2IsTurnOn,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane3IsTurnOn,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane1,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane2,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane3,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane1Offset,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane2Offset,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane3Offset should be set.  
    If the sectionViewName is more than 31 bits, this function will truncate the content after 31 bits
    (the 32nd bit is the terminator).If sectionViewName is the same as any existing entity or view,
    ZW_API_INVALID_INPUT will be return.

    @param [in] sectionViewParameter attribute of section view
    @param [in] sectionViewName name of section view
    @param [out] sectionViewHandle handle of the new section view (can be NULL if no need)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INPUT_TYPE_ERROR

    @code
       szwSectionViewParameter par=...;
       ZwSectionViewParameterInit(&par);
       zwString32 scName;
       szwEntityHandle scHandle;
       ...
       ZwSectionViewCreate(&par, scName, &scHandle);
       ...
       ZwEntityHandleFree(&scHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewCreate(szwSectionViewParameter sectionViewParameter, const zwString32 sectionViewName, szwEntityHandle *sectionViewHandle);

    /**
    @ingroup ZwSectionView

    Get the state of section view action toggle: on/off.

    @param [out] isSectionOn whether the action toggle is on (see ezwSectionViewIsOn)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        ezwSectionViewIsOn isSectionOn = ezwSectionViewIsOn::ZW_SECTION_VIEW_ON;
	    ZwSectionViewOnStateGet(&isSectionOn);
        ...
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewOnStateGet(ezwSectionViewIsOn *isSectionOn);
    
    /**
    @ingroup ZwSectionView

    Set the state of section view action toggle: on/off.

    @param [in] isSectionOn whether the action toggle is on (see ezwSectionViewIsOn)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        ...
        ZwSectionViewOnStateSet(ezwSectionViewIsOn::ZW_SECTION_VIEW_ON);
        ...
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewOnStateSet(ezwSectionViewIsOn isSectionOn);
    
    /**
    @ingroup ZwSectionView

    Insert a plane to the place where the section is.

    @param [in] sectionViewHandle entity handle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwEntityHandle handle{};
        ...
        ZwSectionViewDatumPlaneInsert(handle);    
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewDatumPlaneInsert(szwEntityHandle sectionViewHandle);
    
    /**
    @ingroup ZwSectionView

    Set the parameter of the section view.

    @note
    Interface ZwSectionViewParameterInit() can initialize variables attribute
    of section view of this function.  
    When sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_AT_PLANE, it means section at plane.  
    sectionViewParameter.planeParameter.alignPlane ,sectionViewParameter.planeParameter.optionPlane  
    and sectionViewParameter.planePlacement.offset should be set.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_ENVELOPE, it means section with envelope.  
    sectionViewParameter.planeParameter.alignPlane ,sectionViewParameter.planeParameter.optionPlane,  
    sectionViewParameter.planePlacement.top, sectionViewParameter.planePlacement.front,  
    sectionViewParameter.planePlacement.right, sectionViewParameter.planePlacement.left,  
    sectionViewParameter.planePlacement.back and sectionViewParameter.planePlacement.bottom should be set.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_SLICE, it means section with slice.  
    sectionViewParameter.planeParameter.alignPlane ,sectionViewParameter.planeParameter.optionPlane,  
    sectionViewParameter.planePlacement.thickness and sectionViewParameter.planePlacement.offset should be set.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_PROFILE, it means section with profile.  
    sectionViewParameter.planeParameter.startS and sectionViewParameter.planeParameter.endE should be set.  
    sectionViewParameter.planeParameter.profile->innerData can not be NULL.  
    sectionViewParameter.planeParameter.profile must be set as entity with plane matrix such as sketch ,datum plane,
    face and so on.  
    sectionViewParameter.sectionViewMode = ZW_SECTION_VIEW_SECTION_WITH_3_PLANES, it means section with 3 planes.  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane1IsTurnOn,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane2IsTurnOn,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane3IsTurnOn,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane1,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane2,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane3,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane1Offset,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane2Offset,  
    sectionViewParameter.planeParameter.threePlanesParameter.alignPlane3Offset should be set.  
    If the sectionViewName is more than 31 bits, this function will truncate the content after 31 bits
    (the 32nd bit is the terminator).If sectionViewName is the same as any existing entity or view,
    ZW_API_INVALID_INPUT will be return.

    @param [in] sectionViewHandle entity handle data
    @param [in] sectionViewParameter parameter of section

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwEntityHandle scHandle{};
        szwSectionViewParameter definedSectionViewPrm=...;
        ...
        ZwSectionViewParameterSet(scHandle, definedSectionViewPrm);
        ...
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewParameterSet(szwEntityHandle sectionViewHandle, szwSectionViewParameter sectionViewParameter);
    
    /**
    @ingroup ZwSectionView

    Get the components of the section view

    @param [in] viewHandle entity handle data
    @param [out] countOfComponent the number of components
    @param [out] componentHandles the list of components
    @param [out] isIncluded whether the component is included (see ezwSectionViewComponentIsIncluded)
                - 0 : Exclude selected component
                - 1 : include selected component 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        szwEntityHandle viewHandle{};
        ...
		int count = -1;
		szwEntityHandle* entityHandles = nullptr;
        ...
		ezwSectionViewComponentIsIncluded isIncluded = ezwSectionViewComponentIsIncluded::ZW_SECTION_VIEW_COMPONENT_EXCLUDED;
		ret = ZwSectionViewComponentGet(viewHandle, &count, &entityHandles, &isIncluded);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewComponentGet(szwEntityHandle viewHandle, int *countOfComponent, szwEntityHandle **componentHandles, ezwSectionViewComponentIsIncluded *isIncluded);
    
    /**
    @ingroup ZwSectionView

    Set the state of components: include/exclude

    @param [in] viewHandle entity handle data
    @param [in] countOfComponent the number of components
    @param [in] componentHandles the list of components
    @param [in] isIncluded whether the component is included  (see ezwSectionViewComponentIsIncluded)
                - ezwSectionViewComponentIsIncluded::ZW_SECTION_VIEW_COMPONENT_EXCLUDED : Exclude selected component
                - ezwSectionViewComponentIsIncluded::ZW_SECTION_VIEW_COMPONENT_INCLUDED : Include selected component 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
        int count;
        szwEntityHandle handles = nullptr;
        ...
        ezwSectionViewComponentIsIncluded isIncludedNewSet = ezwSectionViewComponentIsIncluded::ZW_SECTION_VIEW_COMPONENT_EXCLUDED;
		ret = ZwSectionViewComponentSet(viewHandle, count, handles, isIncludedNewSet);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewComponentSet(szwEntityHandle viewHandle, int countOfComponent, const szwEntityHandle *componentHandles, ezwSectionViewComponentIsIncluded isIncluded);

    /**
    @ingroup ZwSectionView

    Determine whether the view is a section view.

    @param [in] viewHandle view handle data
    @param [out] isSectionView whether the input entity is section view
                1 - it is section view
                0 - it is not section view

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwSectionViewCheck(szwEntityHandle viewHandle, int *isSectionView);

    /**
    @ingroup ZwSectionView
    
    Set local control attributes of a section view.  
    Setting "local" control attributes will not change parameters and options shown on the section view command in ZW3D.

    @note
    Opaque that this function sets ranges from 0 to 100.  
    It's recommended to set attributes after using ZwSectionViewLocalDisplayControlGet to obtain attributes if you just want to set a specify attribute.
    
    @param [in] sectionViewHandle section view handle
    @param [in] data local control attributes
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    szwControlLocalAttributes data{};
    szwEntityHandle handle=...;
    ZwSectionViewLocalDisplayControlSet(handle,&data);
    //change the data
    ...
    ZwSectionViewLocalDisplayControlSet(handle,data);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewLocalDisplayControlSet(szwEntityHandle sectionViewHandle, szwControlLocalAttributes data);
    
    /**
    @ingroup ZwSectionView
    
    Set global control attributes of all section views.  
    Setting "global" control attributes will change parameters and options shown on the section view command in ZW3D,
    which means the option or parameter you set by this api will take effect on ZW3D.
    
    @note
    It's recommended to set attributes after using ZwSectionViewGlobalDisplayControlGet to obtain attributes if you just want to set a specify attribute.

    @param [in] data global control attributes
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT

    @code
    szwControlGlobalAttributes data{};
    ZwSectionViewGlobalDisplayControlGet(&data);
    //change the data
    ...
    ZwSectionViewGlobalDisplayControlSet(data);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewGlobalDisplayControlSet(szwControlGlobalAttributes data);
    
    /**
    @ingroup ZwSectionView
    
    Get local control attributes of a section view. for more detail on "local", please see ZwSectionViewLocalDisplayControlSet().
    
    @param [in] sectionViewHandle section view handle
    @param [out] data local control attributes
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_WRONG_ROOT_ENV

    @code
    szwControlLocalAttributes data{};
    szwEntityHandle handle=...;
    ZwSectionViewLocalDisplayControlSet(handle,&data);
    //change the data
    ...
    ZwSectionViewLocalDisplayControlSet(handle,data);
    @endcode

    */
    ZW_API_C ezwErrors ZwSectionViewLocalDisplayControlGet(szwEntityHandle sectionViewHandle, szwControlLocalAttributes *data);

    /**
    @ingroup ZwSectionView
    
    Get global control attributes of all section views. for more detail on "global", please see ZwSectionViewGlobalDisplayControlSet().
    
    @param [out] data global control attributes
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    szwControlGlobalAttributes data{};
    ZwSectionViewGlobalDisplayControlGet(&data);
    //change the data
    ...
    ZwSectionViewGlobalDisplayControlSet(data);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewGlobalDisplayControlGet(szwControlGlobalAttributes *data);

    /**
    @ingroup ZwSectionView
    
    Get attributes of curve in section view.
    
    @param [out] data curve attributes
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    szwCurveAttributes data{};
    ZwSectionViewCurveAttributeGet(&data);
    //change the data
    ...
    ZwSectionViewCurveAttributeSet(data);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewCurveAttributeGet(szwCurveAttributes *data);

    /**
    @ingroup ZwSectionView
    
    Set attributes of curve in section view.

    @note
    It's recommended to set attributes after using ZwSectionCurveAttributeGet to obtain attributes if you just want to set a specify attribute.  
    curveWidth in data can't be 0, it means width undefined.  
    If you want to apply the settings you set, you can refresh by ZwSectionViewUpdate.
    
    @param [in] data curve attributes(curveWidth in data can't be 0)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    szwCurveAttributes data{};
    ZwSectionViewCurveAttributeGet(&data);
    //change the data
    ...
    ZwSectionViewCurveAttributeSet(data);
    @endcode
    */
    ZW_API_C ezwErrors ZwSectionViewCurveAttributeSet(szwCurveAttributes data);

    /**
    @ingroup ZwSectionView

    Refresh the dynamic section command if the toggle is on. Most of the time, this function is used to regenerate the section curves.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwSectionViewUpdate();

    /**
    @ingroup ZwSectionView
    
    Insert datum curve list in section view.
    
    @param [in] sectionViewHandle handle of section view
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwSectionViewDatumCurveListInsert(szwEntityHandle sectionViewHandle);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_VIEW_H */
