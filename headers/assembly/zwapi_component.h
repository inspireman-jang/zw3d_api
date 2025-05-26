/**
@file zwapi_component.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Component API
Including create the components of the assembly and some other operations of component.
*/

#pragma once
#ifndef ZW_API_COMPONENT_H /* this ifndef surrounds entire header */
#define ZW_API_COMPONENT_H

#include "zwapi_util.h"
#include "zwapi_component_data.h"
#include "zwapi_configtable.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Component Activate */
    //====================================================================================================================
    /**
    @ingroup ZwComponent
    
    Activates the component specified by newComponentHandle and outputs the handle of the current active component.  
    If "newComponentHandle" is input as a NULL point, the active target handle is not output.  
    
    If "updateGUI" is non-zero, this function updates the GUI menus to reflect a change in the target object.  
    Otherwise, the menus of the original target object remain active.  

    @note
    The caller is responsible to free the oldComponentHandle by using ZwEntityHandleFree().

    @param [in] newComponentHandle new target object handle
    @param [in] updateGUI 1 to update GUI, else 0
    @param [out] oldComponentHandle old entity handle(input NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
    szwEntityHandle newComponentHandle=...;
    int updateGUI=...;
    szwEntityHandle oldComponentHandle{};
    ZwComponentActivate(newComponentHandle, updateGUI, &oldComponentHandle);
    ...
    // remember to revert the environment after doing something.
    ZwComponentActivate(oldComponentHandle, updateGUI, NULL);
    //free the handle you get
    ZwEntityHandleFree(&oldComponentHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwComponentActivate(szwEntityHandle newComponentHandle, int updateGUI, szwEntityHandle *oldComponentHandle);
    
    /**
    @ingroup ZwComponent

    Gets the names of the file and root referenced by the
    specified component. Root used in multi-object.

    @param [in] componentHandle handle data of component in active file
    @param [in] nFileBytes string size of file name
    @param [out] fileName name of the file instanced by the component
    @param [in] nRootBytes string size of root name
    @param [out] rootName name of the root instanced by the component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_aPI_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFileAndRootGet(szwEntityHandle componentHandle, int nFileBytes, char *fileName, int nRootBytes, char *rootName);

    //====================================================================================================================
    /** @name Component Get */
    //====================================================================================================================
    /**
    @ingroup ZwComponent

    Traverses all components start with componentHandle and store them into handleList.

    @note
    The caller is responsible to free the handleList by using ZwEntityHandleListFree().

    @param [in] componentHandle entity handle data to start traversal, NULL to traverse current active part
    @param [in] depth depth of traversing, -1 to traverse all handle
    @param [in] isIgnoreBlank whether to ignore blanked components
    @param [in] isIgnoreSuppress whether to ignore the hidden and suppressed components
    @param [in] isIncludeUnplaced whether to include unplaced components
    @param [out] handleCount number of components
    @param [out] handleList handle list of components

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwComponentListGet(const szwEntityHandle *componentHandle, int depth, int isIgnoreBlank, int isIgnoreSuppress, int isIncludeUnplaced, int *handleCount, szwEntityHandle **handleList);

    //====================================================================================================================
    /** @name Component State */
    //====================================================================================================================
    /**
    @ingroup ZwComponent

    Determines whether the component file is missing.

    @note
    This interface can only check whether the specified component itself is missing. 
    It can not check the loss of its internal child parts or components.

    @param [in] componentHandle handle data of component
    @param [out] isFileLost 1= file is lost; 0= file is not lost.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFileLostCheck(szwEntityHandle componentHandle, int *isFileLost);    
    
    /**
    @ingroup ZwComponent

    Gets component unplaced state.

    @param [in] componentHandle handle data of component
    @param [out] isUnplaced component unplaced state(1 is unplaced, else 0.)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERRORS
    */
    ZW_API_C ezwErrors ZwComponentUnplacedCheck(szwEntityHandle componentHandle, int *isUnplaced);

    /**
    @ingroup ZwComponent

    Gets the visibility of specified component.

    @see ZwComponentVisibilitySet

    @param [in] componentHandle handle of component
    @param [out] isVisible 1-visible, 0-blank

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    */
    ZW_API_C ezwErrors ZwComponentVisibilityGet(szwEntityHandle componentHandle, int *isVisible);

    /**
    @ingroup ZwComponent

    Sets the visibility of specified component.

    @see ZwComponentVisibilityGet

    @param [in] componentHandle handle of component
    @param [in] isVisible 1-visible, 0-blank

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwComponentVisibilitySet(szwEntityHandle componentHandle, int isVisible);

    /**
    @ingroup zwapi_component

    Get the packed status of the specified component.  

    @see ZwComponentPackedSet

    @param [in] componentHandle handle of component
    @param [out] isPacked 1-packed, 0-unpacked

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentPackedGet(szwEntityHandle componentHandle, int *isPacked);

    /**
    @ingroup zwapi_component

    Set the packed status of specified component.  
    If inputs NULL for the componentHandle, this function will handle all components.  

    @see ZwComponentPackedGet

    @param [in] componentHandle handle of component, NULL for all components
    @param [in] isPacked 1-pack, 0-unpack

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_SET_ERROR

    @code
    int packedStatus = 0;

    // case 1, get the packed status of a specified component and reset it
    szwEntityHandle componentHandle{};
    ... // code to get the data of componentHandle
    ezwErrors resultValue = ZwComponentPackedGet(componentHandle, &packedStatus);
    ... // code to update the value of packedStatus
    resultValue = ZwComponentPackedSet(&componentHandle, packedStatus);
    ...
    resultValue = ZwEntityHandleFree(&componentHandle); // free the data

    // case 2, set packed status for all components
    packedStatus = 1;
    // pack all components
    resultValue = ZwComponentPackedSet(NULL, packedStatus); // use nullptr in C++
    ...
    // unpack all components
    packedStatus = 0;
    resultValue = ZwComponentPackedSet(NULL, packedStatus); // use nullptr in C++
    @endcode
    */
    ZW_API_C ezwErrors ZwComponentPackedSet(const szwEntityHandle *componentHandle, int isPacked);

    /**
    @ingroup ZwComponent

    Outputs 2 lists of path and root object name of the components that belong
    to the current active part.

    In the case of single root, the name of Path and the name of Root are the same,
    but it differences from each other in multiple root files.

    The difference between ZwComponentListGet() and ZwComponentPathAndRootListGet() is
    ZwComponentListGet() just get the list of component handles,
    and ZwComponentPathAndRootListGet() get the path(include file name) and root object name.

    @see ZwComponentListGet

    @note
    The caller is responsible to free the pathList by using ZwMemoryFree().
    The caller is responsible to free the nameList by using ZwMemoryFree().

    @param [out]  countComponent number of components
    @param [out]  pathList list of components' path
    @param [out]  nameList list of components' root object name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentPathAndRootListGet(int *countComponent, zwPath **pathList, zwRootName **nameList);

    //====================================================================================================================
    /** @name Component Operate */
    //====================================================================================================================
    /**
    @ingroup ZwComponent

    Initializes the parameters of szwComponentInsertData.  

    Function Guide: Assembly->Component->Insert

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwComponentInsert

    @param [out] data component data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwComponentInsertInit(szwComponentInsertData *data);
    
    /**
    @ingroup ZwComponent

    Inserts a existing component to the active part.  
    If "componentHandle" is not NULL, the handle of the new component is output.  
    If this function is called from a custom history operation,
    the component will be associated with the custom operation
    and will be deleted automatically when the custom operation
    is regenerated and re-inserts the component.

    @note
    Interface ZwComponentInsertInit() can initialize component data
    of this function.  
    If you want to set an unopened file to the specified component,
    "data.file" must include the file name and directory where file will save to.  
    If you want to set an opened file to the specified component,
    "data.file" only need to include file name.  
    If you want to insert a single root file to component, set "data.root" to NULL.
    But if you want to insert a multi root file to component, "data.root" is required.  
    When this function is called from within a custom history
    operation, if "identifyCode" is not NULL, "*identifyCode" must be
    a value greater than 0, and if this function is Cyclically called
    from within a custom history operation, "*identifyCode" CAN'T BE
    THE SAME in every calling, otherwise this function will return
    "ZW_API_INPUT_ERROR". value will be encoded in the component's
    UniqueId to differentiate it from other components added by the
    custom operation.

    @see ZwComponentInsertInit

    @param [in] data component insertion data
    @param [in] identifyCode identify code used in UniqueId, as input when this function is called from custom history operation, NULL to ignore
    @param [out] componentHandle handle of inserted component, as input when this function is called from custom history operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_SINGLE_MULTI_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwComponentInsert(szwComponentInsertData data, const int *identifyCode, szwEntityHandle *componentHandle);

    /**
    @ingroup ZwComponent

    Initializes the parameters of szwComponentInsertNewData.  

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwComponentInsertNew

    @param [out] data component data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwComponentInsertNewInit(szwComponentInsertNewData *data);

    /**
    @ingroup ZwComponent
    
    Dissolves the specify component relation by the assembly feature. 

    @note
    The calling procedure MUST deallocate the componentList with ZwEntityHandleListFree().
    
    @param [in] feature the feature handle 
    @param [out] count the componentList length, NULL to ignore.
    @param [out] componentList components which are dissolved relation, NULL to ignore.
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_NO_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentRelationDissolve(szwEntityHandle feature, int *count, szwEntityHandle **componentList);

    /**
    @ingroup ZwComponent

    Creates a new component and insert to the active part.  
    If "componentHandle" is not NULL, the handle of the new component is output.  
    If this function is called from a custom history operation,
    the component will be associated with the custom operation
    and will be deleted automatically when the custom operation
    is regenerated and re-inserts the component.  
    
    Function Guide: Assembly->Component->New to Insert

    @note
    Interface ZwComponentInsertNewInit() can initialize component data of this function.  
    If you want to create a single root file to component, set "data.root" to NULL.  
    If you want to create a new multi root file and insert to an existing multi root file,
    "data.file" and "data.root" is required and the extension of "data.file" is ".Z3".  
    If you want to add a new root to an existing multi root file and insert to it,
    set "data.file" to NULL and "data.root" is required.  
    When this function is called from within a custom history
    operation, if "identifyCode" is not NULL, "*identifyCode" must be
    a value greater than 0, and if this function is Cyclically called
    from within a custom history operation, "*identifyCode" CAN'T BE
    THE SAME in every calling, otherwise this function will return
    "ZW_API_INPUT_ERROR". value will be encoded in the component's
    UniqueId to differentiate it from other components added by the
    custom operation.

    @see ZwComponentInsertNewInit

    @param [in] data new component insertion data
    @param [in] identifyCode identify code used in UniqueId, as input when this function is called from custom history operation, NULL to ignore
    @param [out] componentHandle handle of inserted component, as input when this function is called from custom history operation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_ROOT_SINGLE_MULTI_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwComponentInsertNew(szwComponentInsertNewData data, const int *identifyCode, szwEntityHandle *componentHandle);

    /**
    @ingroup zwapi_component

    Changes the file referred by the specified component in the active file.

    Function Guide: Assembly->Component->Change

    @note
    If you want to set an unopened file to the specified component,
    "file" must include the file name and directory where file will save to.  
    If you want to set an opened file to the specified component,
    "file" only need to include file name.  
    If you want to set a single root file to component, set "root" to NULL.
    But if you want to set a multi root file to component, "root" is required.

    @param [in] componentHandle handle of component in active file
    @param [in] file name of the file containing the part to instance
    @param [in] root name of the part to instance from "file", NULL to ignore.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFileSet(szwEntityHandle componentHandle, const zwPath file, const zwRootName root);

    //====================================================================================================================
    /** @name Component Save */
    //====================================================================================================================
    /**
    @ingroup ZwComponent

    Saves the file referred by the specified component to the specified path/filename.  

    Option is ZW_COMPONENT_SAVE_AS_OPTION_SINGLE to just update the specified component only,  
    ZW_COMPONENT_SAVE_AS_OPTION_SAME_LEVEL to update all the components in the same parent assembly,  
    and ZW_COMPONENT_SAVE_AS_OPTION_ALL to update all as ZwFileSaveAs (no prompt, save as new and replace original one).

    @note
    If input file name is the same as the original file of component, it will update all component in assemble tree, 
    no matter "updataFlag" is 1 and 0.

    @param [in] componentHandle handle of component
    @param [in] option save as option, please see the description
    @param [in] pathFile path/file to save file (must include the new file name and directory where file will save to)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_FILE_LOACATE_FAIL
    -        ZW_API_FILE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFileSaveAs(szwEntityHandle componentHandle, ezwComponentSaveAsOption option, const zwPath pathFile);

    //====================================================================================================================
    /** @name Component State */
    //====================================================================================================================

    /**
    @ingroup ZwComponent
    
    Sets the component fixed or unfixed.
    Function Guide: Assembly -> Constraint -> Fix
    
    @param [in] handle component handle in active part
    @param [in] isFix set the component handle fixed(1) or unfixed(0)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFixSet(szwEntityHandle handle, int isFix);

    //====================================================================================================================
    /** @name Component Get */
    //====================================================================================================================
    /**
    @ingroup ZwComponent
    
    Outputs the handle of the component from which the specified shape
    was merged.  Outputs "innerData=NULL" if the shape was not merged
    from a component.
    
    @note
    The caller is responsible to free the component by using ZwEntityHandleFree().
    
    @param [in] shape shape handle (in active file)
    @param [out] component shape's parent component (0 if undefined)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwComponentGetByMergeShape(szwEntityHandle shape, szwEntityHandle *component);

    //====================================================================================================================
    /** @name Component Interference */
    //====================================================================================================================
    /**
    @ingroup ZwComponent

    Check if there is interference between shapes within the two input components and output the the intersection volume.

    @note
    The function only calculate the interference between shapes within two components, don't calculate the interference of
    sub-components or sub-assemblies within two components.

    @param [in] component1 the first component
    @param [in] component2 the second component
    @param [in] ignoreOpenShape whether to filter open shape (1: excluding the open shapes; 0: including the open shapes)
    @param [in] ignoreHiddenShape whether to filter hidden shape (1: excluding the hidden shapes; 0: including the hidden shapes)
    @param [out] interference whether there is interference: 1 or 0 (input nullptr to ignore)
    @param [out] volume the interference volume (input nullptr to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentShapeInterferenceCheck(szwEntityHandle component1, szwEntityHandle component2, int ignoreOpenShape, int ignoreHiddenShape, int *interference, double *volume);

    /**
    @ingroup ZwComponent

    Checks if there is interference between components and output the the intersection data.

    @note
    The caller is responsible to free the interferenceData by using ZwComponentInterferenceFree().

    @param [in] data component interference check data
    @param [out] countInterference count of interference result data
    @param [out] interferenceData component interference result data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwComponentInterferenceCheck(szwComponentInterferenceCheckData data, int *countInterference, szwComponentInterferenceResultData **interferenceData);

    /**
    @ingroup ZwComponent

    Frees the data that allocated by ZwComponentInterferenceCheck().

    @param [in] countInterference count of interference result data
    @param [in,out] interferenceData component interference result data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwComponentInterferenceFree(int countInterference, szwComponentInterferenceResultData **interferenceData);

    //====================================================================================================================
    /** @name Component Folder */
    //====================================================================================================================
    /**
    @ingroup ZwComponent

    Inserts components to a new folder using specific name (null to use default name).  
    A folder object has start and end, components reside between them, folderHandle returns folder start.

    @note
    The caller is responsible to free the folderHandle by using ZwEntityHandleFree().  
    Make sure all the components belong to the same parents.  

    @param [in] count count of component
    @param [in] componentHandle component handle
    @param [in] folderName folder name(folderName[0]=0 or NULL for default name)
    @param [out] folderHandle folder handle(pass in NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OBJ
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_STRING
    */
    ZW_API_C ezwErrors ZwComponentFolderCreate(int count, const szwEntityHandle *componentHandle, const zwString32 folderName, szwEntityHandle *folderHandle);

    /**
    @ingroup ZwComponent

    Inserts component to an exist folder.  

    @note
    Make sure component and folder belong to the same parents.  

    @param [in] componentHandle component handle
    @param [in] folderHandle folder handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C ezwErrors ZwComponentFolderInsert(szwEntityHandle componentHandle, szwEntityHandle folderHandle);

    /**
    @ingroup ZwComponent

    Gets entity handles of all folders in active assembly.

    @note
    The caller is responsible to free the folderHandle by using ZwEntityHandleListFree().  
    folderHandle can only used in the assembly where they are from.

    @param [out] folderCount count of folder in active assembly
    @param [out] folderList handle list of folder in active assembly

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFolderListGet(int *folderCount, szwEntityHandle **folderList);

    /**
    @ingroup ZwComponent

    Gets parent component of specified folder.

    @note
    The caller is responsible to free the folderHandle by using ZwEntityHandleFree().

    @param [in] folderHandle handle of folder
    @param [out] componentHandle handle of parent component

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFolderParentComponentGet(szwEntityHandle folderHandle, szwEntityHandle *componentHandle);

    /**
    @ingroup ZwComponent

    Deletes specified folder.

    @note
    You can choose to delete all components while deleting the folder.

    @param [in] folderHandle handle of folder
    @param [in] deleteComponent 1-delete components in folder, 0-only delete folder

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwComponentFolderDelete(szwEntityHandle folderHandle, int deleteComponent);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_COMPONENT_H */
