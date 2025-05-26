/**
@file zwapi_layer.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D  Layer API
*/
/**
@defgroup zwapi_layer Layer
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D  Layer API
*/

#pragma once
#ifndef ZW_API_LAYER_H /* this ifndef surrounds entire header */
#define ZW_API_LAYER_H

#include "zwapi_layer_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Layer Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_layer

    Creates a new layer with the specified name.

    @param [in] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerAdd(char *Name);

    /**
    @ingroup zwapi_layer

    Create a layer entity with layer info.
    If "psLayerInfo->sName" is invalid, it will return error.
    if "psLayerInfo->uLayerId & VX_LAYER_INFO_ID" is false, it will allocate an auto layer id.
    if "psLayerInfo->uLayerId & VX_LAYER_INFO_ID" is true but the "psLayerInfo->uLayerId"
    is invalid, it will also allocate an auto id.

    @param [in] psLayerInfo layer info
    @param [out] number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxLayerAdd2(const svxLayerInfo *psLayerInfo, int *number);

    /**
    @ingroup zwapi_layer

    Deletes the specified layer.

    @param [in] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerDel(vxName Name);

    /**
    @ingroup zwapi_layer

    Delete a layer.

    @param [in] number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C evxErrors cvxLayerDel2(int number);

    /**
    @ingroup zwapi_layer

    Activates the specified layer so that newly-created entities are
    automatically assigned to it.

    @param [in] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerActivate(vxName Name);

    /**
    @ingroup zwapi_layer

    Synchronizes entity visibility with layer visibility.

    @deprecated This API will not be updated anymore, please use ZwLayerVisibilityRefresh()
    @see ZwLayerVisibilityRefresh

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C evxErrors cvxLayerSync(void);

    /**
    @ingroup zwapi_layer

    Makes all layers visible.

    @deprecated This API will not be updated anymore, please use ZwLayerVisibilitySetAll()
    @see ZwLayerVisibilitySetAll

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C evxErrors cvxLayerShowAll(void);

    /**
    @ingroup zwapi_layer

    Modify the layer id of layer and related objects, source
    layer id and target layer id must be 0-255.

    @note
    The function does not allow layer id 0 to be modified.

    @param [in] srcNumber  source layer id
    @param [in] tarNumber  target layer id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxLayerIdModify(int srcNumber, int tarNumber);


    //====================================================================================================================
    /** @name Layer Query/Set */
    //====================================================================================================================
    /**
    @ingroup zwapi_layer

    Outputs the name of the active layer.

    @param [out] Name active layer name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxLayerInqActive(vxName Name);

    /**
    @ingroup zwapi_layer

    Determine whether the layer exists in the active target object by name.

    @param [in] Name layer name

    @retval succeeds
    -        1 - the layer exists in the active target object
    -        0 - it does not exist or function fails
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C int cvxLayerExists(vxName Name);

    /**
    @ingroup zwapi_layer

    The number(layer id) must be 0-255.

    @param [in] Number layer id

    @retval succeeds
    -        1 - the layer exists in the active target object
    -        0 - it does not exist or function fails
    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C int cvxLayerExists2(int Number);

    /**
    @ingroup zwapi_layer

    Output the layer id of a specified name.

    @param [in] name name
    @param [out] id layer id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxLayerId(vxName name, int *id);

    /**
    @ingroup zwapi_layer

    Get all entities on the specified layer.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @param [in] Number layer number (0-255)
    @param [out] numEnt no. of entities on the specified layer
    @param [out] Paths pick-path list of entities on the specified layer

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxLayerInqEnts(int Number, int *numEnt, svxEntPath **Paths);

    /**
    @ingroup zwapi_layer

    Assigns the specified entities to the specified layer.

    @param [in] Name layer name
    @param [in] numEnts no. of entities to assign to layer
    @param [in] idEnts list of id's of entities to assign to layer

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerAssign(char *Name, int numEnts, int *idEnts);

    /**
    @ingroup zwapi_layer

    Outputs a list of all layers in the active part or sheet.  
    The calling procedure must deallocate the output list.

    @param [out] Count layer count
    @param [out] Names list of layers

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxLayerList(int *Count, vxName **Names);

    /**
    @ingroup zwapi_layer

    Outputs the name of the layer with the specified number.

    @param [in] Number layer number (0-255)
    @param [out] Name layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerName(int Number, vxName Name);

    /**
    @ingroup zwapi_layer

    Outputs the number of the layer with the specified name.
    Outputs "Number = -1" if the layer is not found.

    @param [in] Name layer name
    @param [out] Number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerNum(vxName Name, int *Number);

    /**
    @ingroup zwapi_layer

    Get all categories in layer manager.

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @deprecated This API will not be updated anymore, please use ZwLayerCategoryListGet()
    @see ZwLayerCategoryListGet

    @param [out] numCate number of categories
    @param [out]  categories name of categories

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxLayerGetAllCategory(int *numCate, vxLongName **categories);

    /**
    @ingroup zwapi_layer

    Get the activate layer number.

    @param [out] number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxActiveLayerNumGet(int *number);

    /**
    @ingroup zwapi_layer

    Set the activate layer.

    @param [in] number layer number (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxActiveLayerNumSet(int number);

    /**
    @ingroup zwapi_layer

    Gets the state of the specified layer.

    @param [in] Name layer name
    @param [out] isVisible 1 = visible; 0 = blanked
    @param [out] isFrozen 1 = frozen, 0 = not frozen

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerStateGet(vxName Name, int *isVisible, int *isFrozen);

    /**
    @ingroup zwapi_layer

    Sets the state of the specified layer.

    The input argument "isFrozen" can be overloaded (set it to -2) to
    prevent this function from logging a "LayerState" history operation
    to record a change in layer visibility if a part is active.   
    In this case, the frozen status of the specified layer remains the same.

    @note
    Some history and entity selection operations are only
    applied to visible entities, so be careful using "isFrozen = -2".  
    This function will redraw the screen, if you will call this function many times,
    you can call cvxDispState() to disable the display and update the display later.
    @code
      vxDispState state ={};
      cvxDispState(0, state);
      for(;;) cvxLayerStateSet();
      cvxDispState(2, state);
    @endcode


    @param [in] Name layer name
    @param [in] isVisible 1 = visible, 0 = blanked, -1 = leave the same
    @param [in] isFrozen 1 = frozen, 0 = not frozen, -1 = leave the same

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxLayerStateSet(vxName Name, int isVisible, int isFrozen);

    //====================================================================================================================
    /** @name Layer Category Operation */
    //====================================================================================================================
    /**
    @ingroup ZwLayer

    Creates a new layer category with the specified name and add to the layer manager.

    @see ZwLayerCategoryDelete
    @see ZwLayerManagerRefresh

    @param [in] name the category name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_NAME_ALREADY_IN_USE
    */
    ZW_API_C ezwErrors ZwLayerCategoryCreate(const char *name);

    /**
    @ingroup ZwLayer

    Rename the layer category with the specified name in the layer manager.

    @see ZwLayerManagerRefresh

    @param [in] name the category name to rename
    @param [in] newName new category name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_NAME_ALREADY_IN_USE
    -        ZW_API_INVALID_OBJ
    -        ZW_API_LAYER_CATEGORY_NAME_CAN_NOT_MODIFIED
    */
    ZW_API_C ezwErrors ZwLayerCategoryNameSet(const char *name, const char *newName);

    /**
    @ingroup ZwLayer

    Delete the layer category with the specified name in the layer manager.

    @see ZwLayerManagerRefresh

    @param [in] name the category name to delete

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME    
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OBJ
    -        ZW_API_LAYER_CATEGORY_CAN_NOT_DELETED
    */
    ZW_API_C ezwErrors ZwLayerCategoryDelete(const char *name);

    /**
    @ingroup ZwLayer

    Gets the names of all layer categories in the layer manager.

    @param [out] count number of the layer categories
    @param [out] names list of the layer category names, the caller must free memory of the variable using ZwMemoryFree

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE

    @code
    int count = 0;
    zwString256* names = nullptr;
    ezwErrors ret = ZwLayerCategoryListGet(&count, &names);
    ZwMemoryFree((void**)&names);
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerCategoryListGet(int *count, zwString256 **names);

    /**
    @ingroup ZwLayer

    Gets the active state of the layer category with the specified name in the layer manager.

    @see ZwLayerCategoryActiveStateSet

    @param [in] type method to specify layer category
    @param [in] name the category name, can be nullptr when type is ZW_CATEGORY_NO_CATEGORY
    @param [out] state the activation state of the layer category (0: unactivated; 1: activated)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OBJ

    @code
    int active = 0;
    //Gets the active state of the layer category with the specified name
    ezwErrors ret = ZwLayerCategoryActiveStateGet(ZW_CATEGORY_SPCIFIED_NAME, "SOLIDS", &active);

    //Gets the active state of the layers with no category set
    ret = ZwLayerCategoryActiveStateGet(ZW_CATEGORY_NO_CATEGORY, nullptr, &active);
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerCategoryActiveStateGet(ezwLayerCategoryType type, const char *name, int *state);

    /**
    @ingroup ZwLayer

    Modifying the active state of the layer category with the specified name in the layer manager.
    A change in the activation state of a layer category changes the visibility of layers with filters
    for that category added. use ZW_CATEGORY_NO_CATEGORY can modify the visibility of layers with no
    category filter set.

    @see ZwLayerCategoryActiveStateGet
    @see ZwLayerVisibilityRefresh
    @see ZwLayerManagerRefresh

    @param [in] type method to specify layer category
    @param [in] name the category name, can be nullptr when type is ZW_CATEGORY_NO_CATEGORY
    @param [in] state the activation state of the layer category (0: deactivate; 1: activate)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OBJ
    -        ZW_API_LAYER_CATEGORY_CAN_NOT_DEACTIVATED

    @code
    int active = 1;
    //Sets the active state of the layer category with the specified name
    ezwErrors ret = ZwLayerCategoryActiveStateSet(ZW_CATEGORY_SPCIFIED_NAME, "SOLIDS", active);

    //Sets the active state of the layers with no category set
    ret = ZwLayerCategoryActiveStateSet(ZW_CATEGORY_NO_CATEGORY, nullptr, active);

    //Refresh entity visibility with layer visibility
    ZwLayerVisibilityRefresh();
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerCategoryActiveStateSet(ezwLayerCategoryType type, const char *name, int state);

    /**
    @ingroup ZwLayer

    Sets the visibility of all layers.

    @note the active layer cannot be set invisible.

    @see ZwLayerVisibilityRefresh
    @see ZwLayerManagerRefresh

    @param [in] visible visibility state (0: invisible; 1: visible)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV

    @code
    int visible = 1;
    ezwErrors ret = ZwLayerVisibilitySetAll(visible);

    //Refresh entity visibility with layer visibility
    ZwLayerVisibilityRefresh();
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerVisibilitySetAll(int visible);

    /**
    @ingroup ZwLayer

    Modifying the visibility state of the layer category with the specified name in the layer manager.
    A change in the visibility of a layer category changes the visibility of layers with filters
    for that category added. use ZW_CATEGORY_NO_CATEGORY can modify the visibility of layers with no
    category filter set.

    @see ZwLayerVisibilityRefresh
    @see ZwLayerManagerRefresh

    @param [in] type method to specify layer category
    @param [in] name the category name, can be nullptr when type is ZW_CATEGORY_NO_CATEGORY.
    @param [in] visible visibility state (0: invisible; 1: visible)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OBJ

    @code
    int visible = 1;
    //Sets the active state of the layer category with the specified name
    ezwErrors ret = ZwLayerCategoryVisibilitySet(ZW_CATEGORY_SPCIFIED_NAME, "SOLIDS", visible);

    //Sets the active state of the layers with no category set
    ret = ZwLayerCategoryVisibilitySet(ZW_CATEGORY_NO_CATEGORY, nullptr, visible);

    //Refresh entity visibility with layer visibility
    ZwLayerVisibilityRefresh();
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerCategoryVisibilitySet(ezwLayerCategoryType type, const char *name, int visible);

    /**
    @ingroup ZwLayer

    Sets the frozen state of all layers.

    @see ZwLayerManagerRefresh

    @param [in] frozen frozen state (0: unfrozen; 1: freeze)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwLayerFrozenStateSetAll(int frozen);

    /**
    @ingroup ZwLayer

    Modifying the frozen state of the layer category with the specified name in the layer manager.
    A change in the frozen state of a layer category changes the frozen state of layers with filters
    for that category added. use ZW_CATEGORY_NO_CATEGORY can modify the frozen state of layers with
    no category filter set.

    @see ZwLayerManagerRefresh

    @param [in] type method to specify layer category
    @param [in] name the category name, can be nullptr when type is ZW_CATEGORY_NO_CATEGORY.
    @param [in] frozen frozen state (0: unfrozen; 1: freeze)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OBJ

    @code
    int frozen = 1;
    //Sets the active state of the layer category with the specified name
    ezwErrors ret = ZwLayerCategoryFrozenStateSet(ZW_CATEGORY_SPCIFIED_NAME, "SOLIDS", frozen);

    //Sets the active state of the layers with no category set
    ret = ZwLayerCategoryFrozenStateSet(ZW_CATEGORY_NO_CATEGORY, nullptr, frozen);
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerCategoryFrozenStateSet(ezwLayerCategoryType type, const char *name, int frozen);

    /**
    @ingroup ZwLayer

    Refresh entity visibility with layer visibility.

    @see ZwLayerManagerRefresh

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwLayerVisibilityRefresh();

    /**
    @ingroup ZwLayer

    Refresh the layer manager form data.

    @see ZwLayerVisibilityRefresh

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwLayerManagerRefresh();

    //====================================================================================================================
    /** @name Layer Information */
    //====================================================================================================================
    /**
    @ingroup zwapi_layer

    Get the layer info.

    You should initialze the 'mask' of 'pLayerInfo' to get the specified information of
    the input layer. If pLayerInfo->mask = 0, it will be set to VX_LAYER_INFOR_ALL in this
    function to get all information.

    @param [in] number layer number (0-255)
    @param [in,out] pLayerInfo layer info

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxLayerInfoGet(int number, svxLayerInfo *pLayerInfo);

    /**
    @ingroup zwapi_layer

    Set the layer info.

    @note
    This function will redraw the screen, if you will call this function many times,
    you can call cvxDispState() to disable the display and update the display later.
    Also, when "pLayerInfo->mask & VX_LAYER_INFO_ID is true, it will modify the layer
    index to pLayerInfo->uLayerId. 
    The function does not allow layer id 0 to be modified.

    @code
      vxDispState state ={};
      cvxDispState(0, state);
      for(;;) cvxLayerInfoSet();
      cvxDispState(2, state);
    @endcode

    @param [in] number layer number (0-255)
    @param [in] pLayerInfo layer info

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxLayerInfoSet(int number, const svxLayerInfo *pLayerInfo);

    /**
    @ingroup zwapi_layer

    Export layers information to specified file.

    @param [in] file export target file full path with extension "zwlyr"

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxLayerInfoExport(const vxLongPath file);

    /**
    @ingroup zwapi_layer

    Import layers information from specified file.

    @param [in] file import target file full path with extension "zwlyr"
    @param [in] overWrite 1 to overwrite existing layers; 0 to append existing layers

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxLayerInfoImport(const vxLongPath file, int overWrite);

    /**
    @ingroup zwapi_layer

    Refreshes display of the layer manager form.

    @deprecated This API will not be updated anymore, please use ZwLayerManagerRefresh()
    @see ZwLayerManagerRefresh
    */
    ZW_API_C void cvxLayerRefresh();


    //====================================================================================================================
    /** @name Layer Rules */
    //====================================================================================================================

    /**
    @ingroup ZwLayer

    Add a layer rule to the specified layer.  
    It's not allowed to use 'ZW_LAYER_RULE_OPERATOR_NONE' when calling this function.

    @warning
    If this function executes successfully, all handles of layer rules will be outdated and
    should call ZwLayerRuleListGet to get them again if need.

    @code
    int layerIndex;
    szwLayerRuleData ruleData;
    ... // get the index of layer and fill the rule data
    ezwErrors err = ZwLayerRuleCreate(layerIndex, ruleData); 
    @endcode

    @param [in] layerIndex layer index (0-255)
    @param [in] ruleData definition of a layer rule

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwLayerRuleCreate(int layerIndex, szwLayerRuleData ruleData);

    /**
    @ingroup ZwLayer

    Delete the specified layer rule.

    @warning
    If this function executes successfully, all handles of layer rules will be outdated and
    should call ZwLayerRuleListGet to get them again if need.

    @code
    szwEntityHandle ruleHandle;
    ...// initialize and get the inner data of ruleHandle
    ezwErrors err = ZwLayerRuleDelete(ruleHandle);
    @endcode

    @param [in] ruleHandle entity handle of the layer rule

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwLayerRuleDelete(szwEntityHandle ruleHandle);

    /**
    @ingroup ZwLayer

    Delete all layer rules of the specified rule.

    @warning
    If this function executes successfully, all handles of layer rules will be outdated and
    should call ZwLayerRuleListGet to get them again if need.

    @code
    int layerIndex;
    ... // get the index of layer
    ezwErrors err = ZwLayerRulesDeleteAll(layerIndex); 
    @endcode

    @param [in] layerIndex layer index (0-255)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwLayerRulesDeleteAll(int layerIndex);

    /**
    @ingroup ZwLayer

    Update the rule data of the specified rule.  
    It's not allowed to use 'ZW_LAYER_RULE_OPERATOR_NONE' when calling this function.

    @warning
    If this function executes successfully, all handles of layer rules will be outdated and
    should call ZwLayerRuleListGet to get them again if need.

    @param [in] layerIndex layer index (0-255)
    @param [in] ruleHandle entity handle of the layer rule
    @param [in] ruleData definition of a layer rule

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
    int layerIndex;
    szwEntityHandle ruleHandle
    ... // get the index of layer and get the inner data of ruleHandle
    szwLayerRuleData ruleData;
    ezwErrors err = ZwLayerRuleDataGet(ruleHandle, &ruleData);
    ... // check the value of err, and modify the data of ruleData
    err = ZwLayerRuleDataSet(layerIndex, ruleHandle, ruleData);
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerRuleDataSet(int layerIndex, szwEntityHandle ruleHandle, szwLayerRuleData ruleData);

    /**
    @ingroup ZwLayer

    Retrieve the rule list of the specified layer.

    @note
    The memory referenced by "ruleHandles" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleListFree(count, &ruleHandles);).

    @param [in] layerIndex layer index (0-255)
    @param [out] count count of rules
    @param [out] ruleHandles entity handle list of layer rules

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR

    @code
    int layerIndex;
    int count = 0;
    szwEntityHandle *rules = NULL; // szwEntityHandle *rules = nullptr; for C++
    ... // get the index of layer
    ezwErrors err = ZwLayerRuleListGet(layerIndex, &count, &rules);
    ...
    ZwEntityHandleListFree(count, rules);
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerRuleListGet(int layerIndex, int *count, szwEntityHandle **ruleHandles);

    /**
    @ingroup ZwLayer

    Retrieve the definition of the layer rule.

    @see ZwLayerRuleDataSet ZwLayerRuleListGet

    @param [in] ruleHandle entity handle of a layer rule
    @param [out] ruleData definition of a layer rule

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwLayerRuleDataGet(szwEntityHandle ruleHandle, szwLayerRuleData *ruleData);

    /**
    @ingroup ZwLayer

    Retrieve the active status of the specified layer.

    @note
    If this function returns ZW_API_LAYER_RULE_NOT_EXISTS, that means there are
    no layer rules in the specified layer.

    @param [in] layerIndex layer index (0-255)
    @param [out] isActive active status of a layer rule, 1-active, 0-inactive

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_LAYER_RULE_NOT_EXISTS

    @code
    int isActive = 0, layerId = 0;
    ... // get the real index of 'layerId'
    ezwErrors err = ZwLayerRuleActiveStateGet(layerId, &isActive);
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerRuleActiveStateGet(int layerIndex, int *isActive);

    /**
    @ingroup ZwLayer

    Set the active status of the specified layer.

    @note
    If this function returns ZW_API_LAYER_RULE_NOT_EXISTS, that means there are
    no layer rules in the specified layer.

    @param [in] layerIndex layer index (0-255)
    @param [in] isActive active status of a layer rule, 1-active, 0-inactive

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_LAYER_RULE_NOT_EXISTS

    @code
    int isActive = 0, layerId = 0;
    ... // get the real index of 'layerId'
    ezwErrors err = ZwLayerRuleActiveStateSet(layerId, isActive);
    @endcode
    */
    ZW_API_C ezwErrors ZwLayerRuleActiveStateSet(int layerIndex, int isActive);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_LAYER_H */
