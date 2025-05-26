/**
@file zwapi_file_general.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Global File API
*/

#pragma once
#ifndef ZW_API_FILE_GENERAL_H /* this ifndef surrounds entire header */
#define ZW_API_FILE_GENERAL_H

#include "zwapi_util.h"
#include "zwapi_file_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name File */
    //====================================================================================================================
    /**
    @ingroup ZwFileGeneral

    Exits the active part to its parent part if it was activated
    from within an assembly, to its parent CAM plan if it was
    activated from within a CAM plan, to its parent drawing sheet
    if it was activated from a drawing sheet view, or to the
    root object level of its parent file, if it was activated
    from the level of the root object list.


    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR

    */
    ZW_API_C ezwErrors ZwFileParentActivate();

    //====================================================================================================================
    /** @name File Query/Edit */
    //====================================================================================================================
    /**
    @ingroup ZwFileGeneral

    Gets the status whether the specified file is read-only or not.
    If a file opened in the process is read-only, this file can't be saved to the disk.

    @see ZwFileReadOnlyStateSet

    @param [in] fileName file name to check, NULL to get the current active file
    @param [out] status  1 - read-only, 0 - writable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_FILE_ERROR

    @code
    // case 1: get the status of current active file
    int status = 0;
    ZwFileReadOnlyStateGet(nullptr, &status);

    // case 2: get the status of the specified file
    zwPath fileName{};
    ... // code to get the name
    ZwFileReadOnlyStateGet(fileName, &status);
    @endcode
    */
    ZW_API_C ezwErrors ZwFileReadOnlyStateGet(const char *fileName, int *status);

    /**
    @ingroup ZwFileGeneral

    Sets the status whether the specified file is read-only or not.  
    If a file opened in the process is read-only, this file can't be saved to the disk.

    @note
    A file can't switch the permission if it is new created, this function  will return
    ZW_API_FILE_LOCATE_FAIL in this case.  
    It will do nothing if the original status of the specified file is same as the input status.  
    It will not save the changes when switches the permission to read-only.  

    @see ZwFileReadOnlyStateGet

    @param [in] fileName file name to check
    @param [in] status  1 - read-only, 0 - writable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_FILE_ERROR
    -        ZW_API_FILE_LOCATE_FAIL
    -        ZW_API_GENERAL_ERROR

    @code
    // case 1: set the status of current active file
    int status = 0;
    ... // code to update the value of 'status'
    ZwFileReadOnlyStateSet(nullptr, status);

    // case 2: set the status of the specified file
    zwPath fileName{};
    ... // code to get the name
    ZwFileReadOnlyStateGet(fileName, status);
    @endcode
    */
    ZW_API_C ezwErrors ZwFileReadOnlyStateSet(const char *fileName, int status);

    /**
    @ingroup ZwFileGeneral

    Check whether the file name has a valid extension of ZW or not.
    This function returns ZW_API_NO_ERROR if the extension is valid, ZW_API_GENERAL_ERROR if not.

    @param [in] fileName file name to check

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwFileVaildExtensionCheck(const char *fileName);

    /**
    @ingroup ZwFileGeneral

    Updates the link information of the active file or the loading file.

    @note
    This function updates the active file by default, if you calls it in the reactor callbacks of
    ZW_DOCUMENT_LOADED, it will update the link data of the loading file instead.

    @see ZwFileLinkInformationUpdateWithoutModification

    @param [in] data link data to update

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwFileLinkInformationUpdate(szwDocumentUpdateData data);

    /**
    @ingroup ZwFileGeneral

    Updates the link information of the active file or the loading file.

    @note
    This function updates the active file by default, if you calls it in the reactor callbacks of
    ZW_DOCUMENT_LOADED, it will update the link data of the loading file instead.

    @warning
    In this function, it will do the same thing as 'ZwFileLinkInformationUpdate' when you called it for the active file.
    It will not affect the modified flag of the file ONLY if you called it in the reactor callbacks of ZW_DOCUMENT_LOADED,
    which differs from 'ZwFileLinkInformationUpdate'.
    That means, the process will not save the changes if you did not save the files explicitly.
    You can use this function and the reactor callbacks of ZW_DOCUMENT_LOADED to update the link data when opening the files,
    it will be helpful for the PLM applications, if you want to make the users know the files were updated, please use
    ZwFileLinkInformationUpdate.

    @see ZwFileLinkInformationUpdate

    @param [in] data link data to update

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwFileLinkInformationUpdateWithoutModification(szwDocumentUpdateData data);

    //====================================================================================================================
    /** @name File Session */
    //====================================================================================================================
    /**
    @ingroup ZwFileGeneral

    Removes all unused files from the cache.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwFileUnusedCloseAll();

    //====================================================================================================================
    /** @name File State */
    //====================================================================================================================
    /**
    @ingroup ZwFileGeneral

    Lock or unlock the file modified flag, if the file's modified flag is locked, the relevant API functions will
    not change the current modified flag of the file even if the function will modify the file.
    The list of API functions supported by the function is as follows:
    - cvxPartAtSet  
    - cvxPartUserAtSet  
    - cvxPartAtItemSet  
    - cvxPartAtItemSetInFile  
    - cvxPartAtItemLockSet  
    - cvxPartAtItemLockSetInFile  
    - cvxDwgRegen  
    - ZwStandardAttributeSet  
    - ZwUserAttributeSet  
    - ZwUserAttributeLockSet  
    - ZwDrawingRegen  

    @note
    1. The default state is unlocked, and you should unlock the state when you are done.
    2. The state is only valid for the relevant API functions, and it is not valid for the other functions and platform functionality.

    @param [in] state file modified flag keep state (1: on; 0: off)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
    ZwFileModifyFlagLock(1);

    svxAttribute atData = {};
    strcpy_s(atData.data, sizeof(atData.data), "Part description");
    cvxPartAtItemSet(VX_AT_KEYWORD, &atData);
    ...

    ZwFileModifyFlagLock(0);
    @endcode
    */
    ZW_API_C ezwErrors ZwFileModifyFlagLock(int state);

    //====================================================================================================================
    /** @name File Dialog */
    //====================================================================================================================
    /**
    @ingroup ZwFileGeneral

    Displays a file dialog to select or save file.
    The file dialog will display the files specified by "filter", which is a string like the following examples:
    All files:            "All Files (*.*)|*.*|"
    DXF and DWG files:    "DWG File (*.dwg)|*.dwg|DXF File (*.dxf)|*.dxf|"

    @note
    The caller is responsible to free the list by using ZwMemoryFree.

    @param [in] dialogType file dialog type
    @param [in] option file dialog option, refer to ezwFileDialogOption, set multi items by ZW_DIALOG_OPTION_MULTI_SELECT | ZW_DIALOG_OPTION_PROMPT_COVER
    @param [in] dialogTitle file dialog title
    @param [in] directory initial directory (input nullptr to use default path)
    @param [in] filter file filter (input nullptr to use all files)
    @param [out] count number of directories
    @param [out] list directory list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_STRING
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR

    @code
    int count = 0;
    zwPath* list = nullptr;
    ezwErrors ret = ZwFileDialogShow(ZW_DIALOG_TYPE_OPEN, 0, "Open File", nullptr, nullptr, &count, &list);
    // do something
    ...

    ZwMemoryFree((void**)&list);
    @endcode
    */
    ZW_API_C ezwErrors ZwFileDialogShow(ezwFileDialogType dialogType, int option, const char *dialogTitle, const char *directory, const char *filter, int *count, zwPath **list);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FILE_GENERAL_H */
