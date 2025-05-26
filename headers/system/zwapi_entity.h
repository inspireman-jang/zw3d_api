/**
@file zwapi_entity.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Entity API
*/

#pragma once
#ifndef ZW_API_ENTITY_H /* this ifndef surrounds entire header */
#define ZW_API_ENTITY_H

#include "zwapi_util.h"
#include "zwapi_entity_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Entity Create */
    //====================================================================================================================
    /**
    @ingroup ZwEntity

    Outputs the id of the last entity of the specified type created
    since the specified operation of the current transaction.  

    @see cvxOpCount
    @see ZwEntityCreateListGet
    @see ZwEntityCreateGetAll

    @param [in] operation starting operation number ( >= 0 )
    @param [in] type entity type
    @param [out] entity entity handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR

    @code
    int op = cvxOpCount();
    ...

    szwEntityHandle entity = {};
    ezwErrors ret = ZwEntityCreateGet(op, ZW_ENTITY_SHAPE, &entity);
    ...

    // free memory of handle
    ZwEntityHandleFree(&entity);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityCreateGet(int operation, ezwEntityType type, szwEntityHandle *entity);

    /**
    @ingroup ZwEntity

    Outputs a list of the handles of the entities on the feature tree of the 
    specified type created since the specified operation of the current transaction.

    @see cvxOpCount
    @see ZwEntityCreateGet
    @see ZwEntityCreateGetAll

    @param [in] operation starting operation number ( >= 0)
    @param [in] type entity type
    @param [out] count number of new entities
    @param [out] entityList list of new entity handles, the caller must free memory of the variable using ZwEntityHandleListFree

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_TYPE_ERROR

    @code
    int op = cvxOpCount();
    ...

    int count = 0;
    szwEntityHandle* entityList = nullptr;
    ezwErrors ret = ZwEntityCreateListGet(op, ZW_ENTITY_SHAPE, &count, &entityList);
    ...

    // free memory of handle
    ZwEntityHandleListFree(count, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityCreateListGet(int operation, ezwEntityType type, int *count, szwEntityHandle **entityList);

    /**
    @ingroup ZwEntity

    Outputs a list of the handles of the entities of the specified type
    created since the specified operation of the current transaction. 
    the function will output all newly generated entities, including 
    entities that are not on the feature tree, such as backup entities.

    @see cvxOpCount
    @see ZwEntityCreateGet
    @see ZwEntityCreateListGet

    @param [in] operation starting operation number ( >= 0)
    @param [in] type entity type
    @param [out] count number of new entities
    @param [out] entityList list of new entity handles, the caller must free memory of the variable using ZwEntityHandleListFree

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_TYPE_ERROR

    @code
    int op = cvxOpCount();
    ...

    int count = 0;
    szwEntityHandle* entityList = nullptr;
    ezwErrors ret = ZwEntityCreateGetAll(op, ZW_ENTITY_SHAPE, &count, &entityList);
    ...

    // free memory of handle
    ZwEntityHandleListFree(count, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityCreateGetAll(int operation, ezwEntityType type, int *count, szwEntityHandle **entityList);

    //====================================================================================================================
    /** @name Entity Get */
    //====================================================================================================================

    /**
    @ingroup ZwEntity

    Displays the specified "prompt" and waits for the user to pick
    an entity whose handle is output via "handle".
    @note
    The caller is responsible to free the handle by using ZwEntityHandleFree().

    @param [in] prompt text prompt
    @param [in] option entity input option
    @param [in] emptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] handle entity handle (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityGetByPick(const char *prompt, ezwEntityInputOption option, int emptyOk, szwEntityHandle *handle);

    /**
    @ingroup ZwEntity

    Displays the specified "prompt" and waits for the user to pick
    an entity whose handle is output via "handle" with a list of ezwEntityInputOption.
    @note
    The caller is responsible to free the handle by using ZwEntityHandleFree().

    @param [in] prompt text prompt
    @param [in] option entity input option count
    @param [in] option entity input option list
    @param [in] emptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] handle entity handle (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityGetByPickWithMultipleFilter(const char *prompt, int optionCount, ezwEntityInputOption *optionList, int emptyOk, szwEntityHandle *handle);

    /**
    @ingroup ZwEntity

    Displays the specified "prompt" and waits for the user to pick
    a list of entities, which is output via "handleList".

    @note
    The caller is responsible to free the handle by using ZwEntityHandleListFree().

    @param [in] prompt text prompt
    @param [in] option entity input option
    @param [in] emptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] count number of entity picks
    @param [out] handleList list of entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityListGetByPick(const char *prompt, ezwEntityInputOption option, int emptyOk, int *count, szwEntityHandle **handleList);

    /**
    @ingroup ZwEntity

    Displays the specified "prompt" and waits for the user to pick
    a list of entities with a list of ezwEntityInputOption, which is output via "handleList".

    @note
    The caller is responsible to free the handle by using ZwEntityHandleListFree().

    @param [in] prompt text prompt
    @param [in] option entity input option count
    @param [in] option entity input option list
    @param [in] emptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] count number of entity picks
    @param [out] handleList list of entity handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityListGetByPickWithMultipleFilter(const char *prompt, int optionCount, ezwEntityInputOption *optionList, int emptyOk, int *count, szwEntityHandle **handleList);
	
    /**
    @ingroup ZwEntity

    Finds the closest entity of the specified type to "referencePoint"
    and outputs its index via "entityHandle" (NULL is output if no
    entity is found).
    If "point" is not NULL, the coordinates
    of "referencePoint" projected onto the entity are output via "point".
    If "distance" is not NULL, the shortest distance between the
    entity and "referencePoint" is output via "distance".

    @param [in] entityType type of entity to search for
    @param [in] referencePoint reference point
    @param [out] entityHandle entity Handle (NULL if undefined)
    @param [out] point point on entity (or NULL to ignore)
    @param [out] distance distance (mm) from referencePoint (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    ezwEntityFind entityType=...;
    szwPoint referencePoint=...;

    szwEntityHandle entityHandle{};
    szwPoint point{};
    double distance=0;

    ZwEntityGetByPoint(entityType,referencePoint,&entityHandle,&point,&distance);
    ...
    //remember to free the handle you get.
    ZwEntityHandleFree(&entityHandle);

    @endcode
    */
    ZW_API_C ezwErrors ZwEntityGetByPoint(ezwEntityFind entityType, szwPoint referencePoint, szwEntityHandle *entityHandle, szwPoint *point, double *distance);

    /**
    @ingroup ZwEntity

    Searches for the entity with the specified name and type in active file.

    @note
    If it is found, its handle is output via "entityHandle".
    If it is not found, innerData in entityHandle returns nullptr, but return no error.
    In this function, the entity handle will be allocated memory, so remember to deallocate it by ZwEntityHandleFree().

    @param [in] name entity name
    @param [in] type entity type, ZW_ENTITY_ALL to search all type of entity, may find duplicate entity
    @param [out] entityHandle entity handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_TYPE_ERROR

    @code
    //fill name
    zwString32 name={"..."};
    //fill type
    ezwEntityType type=ezwEntityType::...;
    //prepare handle
    szwEntityHandle entityHandle{};
    //get handle
    ZwEntityGetByNameAndType(name,type,&entityHandle);
    //free handle
    ZwEntityHandleFree(&entityHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityGetByNameAndType(const zwString32 name, ezwEntityType type, szwEntityHandle *entityHandle);

    /**
    @ingroup ZwEntity

    Gets all the entities displayed in the current view area. The function filters the entities
    using platform-activated filters.

    @note
    The caller is responsible to free the entityList by using ZwEntityHandleListFree().

    @param [in] crossBoundary whether to get the entities that intersect the view boundary (1: yes; 0: no)
    @param [out] count number of entities
    @param [out] entityList list of entity handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwEntityGetByCurrentView(int crossBoundary, int *count, szwEntityHandle **entityList);

    /**
    @ingroup ZwEntity
    
    Gets the current active entity.(part, sketch or drawing).  
    When you activate an component in assembly, this API will get the component handle.  
    When you in drawing, this API will get the drawing handle(not sheet handle).  
    If you want to get sheet handle in drawing, please see ZwDrawingSheetListGet().

    @note
    The caller is responsible to free the entityHandle by using ZwEntityHandleFree().  

    @param [out] entityHandle current active entity
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwEntityActiveGet(szwEntityHandle *entityHandle);

    //====================================================================================================================
    /** @name Entity Operate */
    //====================================================================================================================
    /**
    @ingroup ZwEntity
    
    Activates the target of the handle (newHandle) and outputs the handle of the original target object (oldHandle).  
    If "oldHandle" is input as a NULL point, the original target handle is not output.  
    
    If "updateGUI" is non-zero, this function updates the GUI menus to reflect a change in the target object.  
    Otherwise, not update the GUI menus.  

    @note
    The caller is responsible to free the oldHandle by using ZwEntityHandleFree().  
    This api only support to activate sketch, 3d sketch, block in sketch, Sheet Border in drawing and Title Block in drawing.  

    @param [in] newHandle new target object handle
    @param [in] updateGUI 1 to update GUI, else 0
    @param [out] oldHandle old entity handle(input NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_TYPE_ERROR

    @code
    szwEntityHandle newHandle=...;
    int updateGUI=...;
    szwEntityHandle oldHandle{};
    ZwEntityActivate(newHandle, updateGUI, &oldHandle);
    ...
    // remember to revert the environment after doing something.
    ZwEntityActivate(oldHandle, updateGUI, NULL);
    //free the handle you get
    ZwEntityHandleFree(&oldHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityActivate(szwEntityHandle newHandle, int updateGUI, szwEntityHandle *oldHandle);

    /**
    @ingroup ZwEntity
    
    Deletes specified entities in the active root object.  
    
    @param [in] entityHandle entity handle to erase
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OBJ
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMM_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwEntityDelete(szwEntityHandle entityHandle);

    /**
    @ingroup ZwEntity
    
    Erases the specified entity in the active root object(part, sketch, 3d sketch or drawing sheet).  
    Notice that it will create erase feature in part file if you try to erase a shape.  
    You can not erase a feature by this function.  
    
    @param [in] entityHandle entity handle to erase
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OBJ
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMM_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwEntityErase(szwEntityHandle entityHandle);

    /**
    @ingroup ZwEntity
    
    Deletes specified entities in the active root object.  

    @note
    The entities in entityList must have the same type.  
    
    @param [in] count the count of entity handles to delete
    @param [in] entityList entity handles to delete
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OBJ
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMM_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwEntityListDelete(int count, const szwEntityHandle *entityList);

    /**
    @ingroup ZwEntity
    
    Erases specified entities in the active root object(part, sketch, 3d sketch or drawing sheet).  
    Notice that it will create erase feature in part file if you try to erase a shape.  
    You can not erase feature by this function.  

    @note
    The entities in entityList must have the same type.  
    
    @param [in] count the count of entity handles to delete
    @param [in] entityList entity handles to delete
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_INVALID_OBJ
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMM_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwEntityListErase(int count, const szwEntityHandle *entityList);

    //====================================================================================================================
    /** @name Entity State */
    //====================================================================================================================
    /**
    @ingroup ZwEntity

    Blanks or unblanks the specified entities.  

    Besides, input "count" as a negative number can
    prevent a blank/unblank operation from being logged to
    the history in the case that this function is being
    applied to a part entity.

    @see ZwEntityBlankGet

    @param [in] count number of entities
    @param [in] entityList list of new entity handles
    @param [in] blank blank state (1: blank entities; 0: unblank entities)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR

    @code
    int count = 0;
    szwEntityHandle* entityList = nullptr;
    // some code to get the data of entity handles
    ...

    int blank = 1;
    ezwErrors ret = ZwEntityBlankSet(count, entityList, blank);
    ...

    // free memory of handle
    ZwEntityHandleListFree(count, &entityList);
    @endcode

    Call this function during echoing will not log any
    blank/unblank operation to the history, for example:
    @code
       cvxEchoStart();
       cvxEntBlank(1, nEntity, &idEntity);
       cvxEchoEnd();
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityBlankSet(int count, const szwEntityHandle *entityList, int blank);

    /**
    @ingroup ZwEntity

    Determines whether the specific entity is blanked.

    @see ZwEntityBlankSet

    @param [in] entity handle of entity
    @param [out] blanked blank state of entity (1: blanked; 0: visible)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    szwEntityHandle entity = {};
    // some code to get the data of entity
    ...

    int blank = 0;
    ezwErrors ret = ZwEntityBlankGet(entity, &blank);
    ...

    // free memory of handle
    ZwEntityHandleFree(&entity);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityBlankGet(szwEntityHandle entity, int *blanked);

    /**
    @ingroup ZwEntity

    Determines whether a valid entity with the specified type exists in the active root.

    @param [in] entity handle of entity
    @param [in] type entity type
    @param [out] exist entity existence (1: exist; 0: not found)

    @note
    Some of ezwEntityType(ZW_ENTITY_BREP, ZW_ENTITY_HISTORY, ZW_ENTITY_POINT, ZW_ENTITY_WIRE) are banned in this function.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR

    @code
    szwEntityHandle entity = {};
    // some code to get the data of entity
    ...

    int exist = 0;
    ezwErrors ret = ZwEntityExistenceCheck(entity, ZW_ENTITY_SHAPE, &exist);
    ...

    // free memory of handle
    ZwEntityHandleFree(&entity);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityExistenceCheck(szwEntityHandle entity, ezwEntityType type, int *exist);

    /**
    @ingroup ZwEntity

    Outputs the suppress state of specified entity(feature or component).
    
    @note
    You can not use this function to get suppress state of a solid entity.

    @param [in] handle entity handle
    @param [out] suppress the entity suppress state, 1-suppressed 0-unsuppressed.
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwEntitySuppressGet(szwEntityHandle handle, int *suppress);

    /**
    @ingroup ZwEntity

    Sets the status of turning front picking.
    If "isFrontPickOn" == 1, the front pick state is on.
    If "isFrontPickOn" == 0, the front pick state is off.
    When the button is turned on, it will ignore sheltered entities.

    @note
    This interface can only be used in part, assembly, cam, motion, sketch environments.

    @param [in] isFrontPickOn set the Front Pick button  on or off 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_WRONG_ROOT_ENV
    @code
    int i = -1;
    ZwEntityFrontPickStateGet(&i);
    ZwEntityFrontPickStateSet(1);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityFrontPickStateSet(int isFrontPickOn);

    /**
    @ingroup ZwEntity

    Gets the status of turning front picking.
    If "isFrontPickOn" == 1, the front pick state is on.
    If "isFrontPickOn" == 0, the front pick state is off.
    When the button is turned on, it will ignore sheltered entities.

    @note
    This interface can only be used in part, assembly, cam, motion, sketch environments.

    @param [out] isFrontPickOn whether the Front Pick button is on or off 

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
   
    @code
    int isFrontPickOn = -1;
    ZwEntityFrontPickStateGet(&isFrontPickOn);
    ZwEntityFrontPickStateSet(1);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityFrontPickStateGet(int *isFrontPickOn);

    /**
    @ingroup ZwEntity

    Outputs a list of the entities picked in the active field of the active command.

    @param [out] count number of entities
    @param [out] entityList list of entity handles, the caller must free memory of the variable using ZwEntityHandleListFree()

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR

    @code
    int count = 0;
    szwEntityHandle* entityList = nullptr;
    ezwErrors ret = ZwEntityPickListGet(&count, &entityList);
    ...

    // free memory of handle
    ZwEntityHandleListFree(count, &entityList);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityPickListGet(int *count, szwEntityHandle **entityList);

    /**
    @ingroup ZwEntity

    Unpicks the entity list in active field.

    @retval succeeds
    -        ZW_API_NO_ERROR
    */
    ZW_API_C ezwErrors ZwEntityUnPickAll();

    /**
    @ingroup ZwEntity

    Unpicks the last entity in active field.

    @retval succeeds
    -        ZW_API_NO_ERROR
    */
    ZW_API_C ezwErrors ZwEntityUnPickLast();

    /**
    @ingroup ZwEntity

    Unpicks the entity in active field.

    @param [in] entityHandle entity handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityUnPick(szwEntityHandle entityHandle);

    /**
    @ingroup ZwEntity

    Adds the specified entities to the pick list.

    @param [in] entityCount count of entities to pick
    @param [in] entityList handle list of entities

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR

    */
    ZW_API_C ezwErrors ZwEntityPickListAdd(int entityCount, const szwEntityHandle *entityList);

    //====================================================================================================================
    /** @name Entity Attribute */
    //====================================================================================================================
    /**
    @ingroup ZwEntity

    Gets the standard color number assigned to "entityHandle".

    @see ZwEntityColorRgbGet

    @param [in] entityHandle entity handle (in active file)
    @param [out] color entity color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityColorGet(szwEntityHandle entityHandle, ezwColor *color);

    /**
    @ingroup ZwEntity

    Assigns the specified color to the specified entities in the active file.

    @see ZwEntityColorRgbSet

    @param [in] color entity color
    @param [in] count number of entity handles
    @param [in] entityHandleList entity handle list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwEntityColorSet(ezwColor color, int count, const szwEntityHandle *entityHandleList);

    /**
    @ingroup ZwEntity

    Gets the color assigned to "entityHandle" in RGB format.

    @see ZwEntityColorGet

    @param [in] entityHandle entity handle (in active file)
    @param [out] color entity RGB color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwEntityColorRgbGet(szwEntityHandle entityHandle, szwColor *color);

    /**
    @ingroup ZwEntity

    Assigns the specified RGB color to the specified entities in the active object.  
    Presently, only face entities support true RGB color.  
    For other entities, the specified RGB color is mapped to the closest standard color (ezwColor).

    @see ZwEntityColorSet

    @param [in] color entity RGB color
    @param [in] count number of entity handle
    @param [in] entityHandleList entity handle list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwEntityColorRgbSet(szwColor color, int count, const szwEntityHandle *entityHandleList);

    /**
    @ingroup ZwEntity

    Same as ZwEntityColorRgbSet() except that no display attribute created, which means the color you set will expire after regen.

    @param [in] color entity RGB color
    @param [in] count number of entity handle
    @param [in] entityHandleList entity handle list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwEntityTemporaryColorRgbSet(szwColor color, int count, szwEntityHandle *entityHandleList);

    /**
    @ingroup ZwEntity

    Assigns the specified transparency to the specified entities in
    the active file.

    If the input transparency value exceeds 0-100, this function will fail.

    @param [in] transparency Entity transparency value, from 0 to 100, both ends included
    @param [in] count number of entity handle
    @param [in] entityHandleList entity handle list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwEntityTransparencySet(int transparency, int count, const szwEntityHandle *entityHandleList);

    /**
    @ingroup ZwEntity

    Gets the specified transparency to the specified entity in
    the active file.

    @param [in] entityHandle entity handle
    @param [out] transparency entity transparency value, from 0 to 100, both ends included

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors ZwEntityTransparencyGet(szwEntityHandle entityHandle, int *transparency);

    /**
    @ingroup ZwEntity

    Highlights the specified entity in the active root object with color.

    @param [in] entity handle data of entity
    @param [in] color color of object to display (NULL to use default)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwEntityHighlightWithColor(szwEntityHandle entity, const szwColor *color);

    /**
    @ingroup ZwEntity
    
    Un-highlights all entities.
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwEntityUnhighlightAll();

    /**
    @ingroup ZwEntity
    
    Highlights the specified entity in the active root object.
    
    @param [in] entityHandle entity handle(in active file)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityHighlight(szwEntityHandle entityHandle);

    /**
    @ingroup ZwEntity
    
    Un-highlights the specified entity in the active root object.
    
    @param [in] entityHandle entity handle(in active file)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityUnHighlight(szwEntityHandle entityHandle);

    /**
    @ingroup ZwEntity

    Gets the attributes of specified line.

    @param [in] lineHandle line handle
    @param [out] attribute line attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwLineAttributeGet(szwEntityHandle lineHandle, szwLineAttribute *attribute);

    /**
    @ingroup ZwEntity

    Sets the attributes of specified lines.  
    If you only need to update some of the attributes, you can first
    get the original attributes through ZwLineAttributeGet().

    @param [in] attribute line attribute
    @param [in] count number of entity handle
    @param [in] entityHandleList entity handle list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwLineAttributeSet(szwLineAttribute attribute, int count, const szwEntityHandle *entityHandleList);

    //====================================================================================================================
    /** @name Entity Query */
    //====================================================================================================================
    /**
    @ingroup ZwEntity

    This function is to determine whether the point is the critical point of
    the 2D curve with curveHandle in Drawing Sheet.

    Meaning of critical point is the point with start, end, middle or center position
    of the curve.

    @param [in] curveHandle index of 2D curve
    @param [in] point point
    @param [out] isCritical whether the point is critical
    -        1 - it is a critical point
    -        0 - it is not a critical point or error

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT

    @code
        szwEntityHandle lineHandle=...;
        ...
        szwPoint point{};
        ...
        int isCritical=0;
        ZwEntityCriticalPointCheck(lineHandle, &point, &isCritical);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityCriticalPointCheck(szwEntityHandle curveHandle, szwPoint point, int *isCritical);

    /**
    @ingroup ZwEntity
    
    Determines whether an entity is curve (includes edges and parting lines).
    
    @param [in] entityHandle entity handle (in active file)
    @param [out] isCurve the entity is curvilinear
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwEntityCurveCheck(szwEntityHandle entityHandle, int *isCurve);

    /**
    @ingroup ZwEntity
    
    Determines whether an entity is electrode.
    
    @param [in] entityHandle entity handle (in active file)
    @param [out] isElectrode whether the entity is electrode
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityElectrodeCheck(szwEntityHandle entityHandle, int *isElectrode);

    /**
    @ingroup ZwEntity

    Projects "point" onto the specified curve, edge, face or plane
    and outputs the result as "projPoint".

    @param [in] entityHandle entity handle data of curve, edge, face or plane entity
    @param [in] point point to project
    @param [out] projPoint projected point on entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        szwPoint point{};
        ...
        szwEntityHandle curveHandle=...;
        ...
        szwPoint point1{};
        ...
        ZwEntityProjectionPointGet(curveHandle, point, &point1);
    @endcode

    */
    ZW_API_C ezwErrors ZwEntityProjectionPointGet(szwEntityHandle entityHandle, szwPoint point, szwPoint *projPoint);

    /**
    @ingroup ZwEntity

    Outputs the handle of the shape that the specified face
    or edge (entityHandle) belongs to.  It is assumed the
    entity resides in the active object.  If "shapeHandle.innerData == NULL"
    is output, the entity could not be located or didn't
    belong to a face set.

    @note
    The caller is responsible to free the shapeHandle by using ZwEntityHandleFree().

    @param [in] entityHandle entity handle (in active file)
    @param [out] shapeHandle shape handle data (shapeHandle.innerData = NULL if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityShapeGet(szwEntityHandle entityHandle, szwEntityHandle *shapeHandle);

    /**
    @ingroup ZwEntity

    Acquire the minimum distance between the point and the target entity,
    the target entity type includes shape, face, curve, edge, datum plane, point.

    @param [in] entityHandle entity handle data
    @param [in] point point coordinates of the inquiry
    @param [out] targetPoint the closest point on target entity (NULL to ignore)
    @param [out] distance the minimum distance (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOR_OBJ_ACT_FAIL

    @code
        szwEntityHandle shapeHandle=...;
        ...
        szwPoint point{};
        ...
        szwPoint pointT{};
        double distance;
        ...
        ZwEntityPointMinDistanceGet(shapeHandle, point, &pointT, &distance);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityPointMinDistanceGet(szwEntityHandle entityHandle, szwPoint point, szwPoint *targetPoint, double *distance);

    /**
    @ingroup ZwEntity

    Inquires the related file name and root name of the input entity, only component and component reference are supported.  
    'component reference' is the tree node in drawing manager.  

    @param [in] entityHandle entity handle data
    @param [in] fileSize max size of 'fileName' (0 to ignore)
    @param [out] fileName file name to get (NULL to ignore)
    @param [in] rootSize max size of 'rootName' (0 to ignore)
    @param [out] rootName root name to get (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOR_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwEntityReferenceFileNameGet(szwEntityHandle entityHandle, int fileSize, char *fileName, int rootSize, char *rootName);

    //====================================================================================================================
    /** @name Entity Info Get/Set */
    //====================================================================================================================
    /**
    @ingroup ZwEntity
    
    Outputs an ascii text string describing the entity class  
    identified by "typeNumber".  
    The string is stored in the memory referenced by "typeName", which is assumed  
    to be sufficient (min = 64 bytes).  

    @param [in] typeNumber entity class number
    @param [in] nameSize type name size
    @param [out] typeName class name
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR

    @code
    //Prepare enough size
    zwString256 typeName{};
    ezwEntityType type=...;
    ZwEntityTypeNameGet(type,sizeof(zwString256),typeName);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityTypeNameGet(ezwEntityType typeNumber, int nameSize, char *typeName);

    /**
    @ingroup ZwEntity
    
    Returns the class number of the specified entity in the active object.

    @param [in] entityHandle entity handle
    @param [out] type class number
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwEntityTypeNumberGet(szwEntityHandle entityHandle, ezwEntityType *type);

    /**
    @ingroup ZwEntity

    Assigns the specified name to the specified entity.  
    It is assumed the entity resides in the active file.  
    It is assumed the entity has a "name" field.

    @note
    This function is often used to set the name of dimension/datum/texture/block/config/sheet/equation...  
    You can use function "ZwEntityNameTagSet()" to set the name tag of shell/face...

    @param [in] entityHandle entity handle
    @param [in] name entity name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityNameSet(szwEntityHandle entityHandle, const zwString32 name);

    /**
    @ingroup ZwEntity

    Sets the name tag of the specified entity, the character length of name tag can not 
    exceed 256 character.

    @see ZwEntityNameTagGet
    @see ZwEntityNameTagGetAll

    @param [in] entity handle of entity
    @param [in] nameTag name tag (nullptr to delete name tag of entity)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR

    @code
    szwEntityHandle entity = {};
    // some code to get the data of entity
    ...

    zwString256 nameTag = "Tag";
    ezwErrors ret = ZwEntityNameTagSet(entity, nameTag);
    ...

    // free memory of handle
    ZwEntityHandleFree(&entity);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityNameTagSet(szwEntityHandle entity, const char *nameTag);

    /**
    @ingroup ZwEntity

    Gets the name tag of the specified entity.

    @see ZwEntityNameTagSet
    @see ZwEntityNameTagGetAll

    @param [in] entity handle of entity
    @param [out] nameTag name tag
    @param [in] size max size of name tag

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE

    @code
    szwEntityHandle entity = {};
    // some code to get the data of entity
    ...

    zwString256 nameTag = "";
    ezwErrors ret = ZwEntityNameTagGet(entity, nameTag, sizeof(nameTag));
    ...

    // free memory of handle
    ZwEntityHandleFree(&entity);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityNameTagGet(szwEntityHandle entity, char *nameTag, int size);

    /**
    @ingroup ZwEntity

    Outputs a list of name tags of all entities in the current root object.

    @see ZwEntityNameTagSet
    @see ZwEntityNameTagGet

    @param [out] count number of name tags
    @param [out] nameTags list of the name tags, the caller must free memory of the variable using ZwMemoryFree

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE

    @code
    int count = 0;
    zwString256* nameTags = nullptr;
    ezwErrors ret = ZwEntityNameTagGetAll(&count, &nameTags);
    ...

    // free memory
    ZwMemoryFree((void**)&nameTags);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityNameTagGetAll(int *count, zwString256 **nameTags);

    /**
    @ingroup ZwEntity

    Outputs the handle of the specified entity's layer.

    @param [in] entityHandle entity handle
    @param [out] layerHandle layer handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwEntityLayerGet(szwEntityHandle entityHandle, szwEntityHandle *layerHandle);

    /**
    @ingroup ZwEntity

    Outputs the matrix of the specified entity.

    @param [in] entityHandle entity handle
    @param [out] matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwEntityMatrixGet(szwEntityHandle entityHandle, szwMatrix *matrix);

    /**
    @ingroup ZwEntity

    Outputs the transformation matrix associated with the specified entity.

    @verbatim
    ZW3D uses column vector matrix for modeling and transforming entity.
      szwMatrix
      {
    1.identity;

      2.   3.   4.   5.
      xx,  yx,  zx,  xt;
      xy,  yy,  zy,  yt;
      xz,  yz,  zz,  zt;
   
    6.ox, oy, oz, scale;
      }
    1. 1 if identity matrix, else 0
    2. first column is vector on x-direction.
    3. second column is vector on y-direction.
    4. third column is vector on z-direction.
    5. fourth column is offset of entity
    6. original point of matrix and scale. (this row doesn't take effect and always (0,0,0,1) when transform entity in ZW3D.)
    @endverbatim

    @param [in] entityHandle entity handle
    @param [out] matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwEntityTransformMatrixGet(szwEntityHandle entityHandle, szwMatrix *matrix);
    
    /**
    @ingroup ZwEntity

    Sets the transformation matrix associated with the specified entity in the active file.  
    If the entity does not support a transformation matrix, nothing is done.

    @param [in] entityHandle entity handle
    @param [in] matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_MATRIX_NONORTHOGONAL
    */
    ZW_API_C ezwErrors ZwEntityMatrixSet(szwEntityHandle entityHandle, szwMatrix matrix);

    /**
    @ingroup ZwEntity

    Outputs the handle of the parent feature of the specified entity
    in the active file.  
    If you want to get child entity of feature, see ZwFeatureChildEntityListGet().

    @param [in] entityHandle entity handle
    @param [out] featureHandle feature handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwEntityParentFeatureGet(szwEntityHandle entityHandle, szwEntityHandle *featureHandle);

    /**
    @ingroup ZwEntity

    This function gets the bounding box of the specified entity.  

    Interface ZwBoundingBoxTransform() can convert envelope boxes to different matrices.  
    Interface cvxBndBoxPnts() can convert the envelope box to the coordinate value
    under the current world coordinate system.  
    Interface ZwPointTransform() can convert points under different coordinate systems.

    @note
       When the matrix of the specified entity is not orthogonal to the matrix of 
    the current world coordinate system(e.g. you want get bounding box of a component,
    and this component has been rotated in assemble, there are two bounding boxes you can get.)  
       If you want to get its bounding box in original file, please set coordinateSystemType=ZW_COORDINATE_MODEL.  
       If you want to get bounding box in current file set coordinateSystemType=ZW_COORDINATE_WORLD.  
       When coordinateSystemType=ZW_COORDINATE_WORLD, the envelope box output from the interface can be directly converted
    to points. The envelope box drawn according to the coordinates of these points is correct.  
       When coordinateSystemType=ZW_COORDINATE_MODEL, you need to convert the envelope box to the point coordinates first,
    and then convert the point to the point coordinates under the current coordinate system.
       At this time, the envelope box drawn according to the point coordinates is correct.  
    When coordinateSystemType=ZW_COORDINATE_CUSTOM, the envelope box output from the interface is the result of 
    multiplying "matrix" and bounding box in model coordinate system.  
       matrix.xt, matrix.yt and matrix.zt won't take effect on transforming the bounding box.

    @param [in] entityHandle entity handle
    @param [in] coordinateSystemType coordinate system where bounding box in
    @param [in] matrix transform matrix, taking effect only when coordinateSystemType = ZW_COORDINATE_CUSTOM.
    @param [out] box bounding box of specified entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MATRIX_NONORTHOGONAL
    */
    ZW_API_C ezwErrors ZwEntityBoundingBoxGet(szwEntityHandle entityHandle, ezwCoordinateType coordinateSystemType, szwMatrix matrix, szwBoundingBox *box);

    /**
    @ingroup ZwEntity
    
    This function gets the compact bounding box of the specified entity 
    under the local coordinate system.  
    
    This function only supports with component, shape, face, edge, curve and 3D block.

    @note
    A normal bounding box will be calculated with the distances of X, Y and Z more than zero, thus 
    if the entity like a circle or face is parallel to XY, XZ or YZ plane, it can't get the correct 
    result and returns ZW_API_GENERAL_ERROR.
    
    @param [in] entity  entity handle
    @param [out] boudningBox  bounding box of specified entity
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwEntityCompactBoundingBoxGet(szwEntityHandle entity, szwBoundingBox *boudningBox);

    /**
    @ingroup ZwEntity
    
    Gets the info of critical points for the specified entity. 
    
    @note
    The caller is responsible to free the infoList by using ZwMemoryFree.

    @param [in] entityHandle entity handle (in active file)
    @param [out] count number of critical point info
    @param [out] infoList critical point info list
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwEntityCriticalPointInfoGet(szwEntityHandle entityHandle, int *count, szwEntityCriticalPointInfo **infoList);

    /**
    @ingroup ZwEntity
    
    Searches sketches within the active part for the specified entity (entityHandle).

    @note
    If the entity is found within a sketch, the handle of the sketch is output.  
    If the entity is not found inside a sketch, "sketchHandle" innerData is null and no error will be thrown.  
    Remember to deallocate handle if it's innerData is not null.  

    @param [in] entityHandle entity handle
    @param [out] sketchHandle handle of entity's parent sketch
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL

    @code
    szwEntityHandle handle=...;
    szwEntityHandle sketch{};
    ZwEntityParentSketchGet(handle, &sketch);
    ...
    //free the handle you get
    ZwEntityHandleFree(&sketch);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityParentSketchGet(szwEntityHandle entityHandle, szwEntityHandle *sketchHandle);

    /**
    @ingroup ZwEntity
    
    Outputs the handle of the parent feature of the specified entity
    in the active part.

    @note
    If the parent entity is found, the handle of the parent is output.  
    If the parent entity is not found, "parentHandle" innerData is null and no error will be thrown.  
    Remember to deallocate handle if it's innerData is not null.
    
    @param [in] entityHandle entity handle
    @param [out] parentHandle parent feature handle (NULL if undefined)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle handle=...;
    szwEntityHandle parent{};
    ZwEntityParentGet(handle, &parent);
    ...
    //free the handle you get
    ZwEntityHandleFree(&parent);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityParentGet(szwEntityHandle entityHandle, szwEntityHandle *parentHandle);

    /**
    @ingroup ZwEntity

    Gets the entity handle that "referenceHandle" takes it as a reference.

    @note
    If the entity is found, the handle is output.  
    If the entity is not found, "handle" innerData is null and no error will be thrown.  
    Remember to deallocate handle if it's innerData is not null.  

    @param [in] referenceHandle parametric reference entity handle
    @param [out] handle handle of entity defined by reference entity
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR

    @code
    szwEntityHandle referenceHandle=...;
    szwEntityHandle handle{};
    ZwEntityReferenceGet(referenceHandle, &handle);
    ...
    //free the handle you get
    ZwEntityHandleFree(&handle);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityReferenceGet(szwEntityHandle referenceHandle, szwEntityHandle *handle);

    /**
    @ingroup ZwEntity

    Outputs the name of the specified entity.
    It is assumed the entity resides in the active file.
    A blank string is output if the entity doesn't have a name.

    @param [in] entityHandle entity handle
    @param [in] nBytes string max size of entity name
    @param [out] name entity name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwEntityNameGet(szwEntityHandle entityHandle, int nBytes, char *name);

    //====================================================================================================================
    /** @name Entity Handle */
    //====================================================================================================================
    /**
    @ingroup ZwEntity

    Transfers entity indexes to entity handles.

    @note
    The memory referenced by "entityHandles" is allocated by this function.
    The calling procedure is responsible to use ZwEntityHandleFree() to free it.

    @see ZwEntityHandleFree

    @param [in] count the num of entity list
    @param [in] indexes entity list
    @param [out] entityHandles entity handle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       // transfer single entity
       szwEntityHandle entityHandle;
       // assume that there's a variable named entityId(int)
       ZwEntityIdTransfer(1, &entityId, &entityHandle);
       ...
       ZwEntityHandleFree(&entityHandle);

       // transfer entity array
       szwEntityHandle entityHandles[arrayCount];
       // assume that there are a variable named arrayCount(int) and a variable named entityArray(int [] or int *)
       ZwEntityIdTransfer(arrayCount, entityArray, entityHandles);
       ...
       for (int i = 0; i < arrayCount; ++i)
       {
          ZwEntityHandleFree(&entityHandles[i]);
       }
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityIdTransfer(int count, const int *indexes, szwEntityHandle *entityHandles);

    /**
    @ingroup ZwEntity

    Transfers entity paths to entity handles.

    @note
    The memory referenced by "entityHandles" is allocated by this function.
    The calling procedure is responsible to free it.

    @see ZwEntityHandleFree

    @param [in] count the num of entity list
    @param [in] entityPaths entity list
    @param [out] entityHandles entity handle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR

    @code
       // transfer single entity
       szwEntityHandle entityHandle;
       // assume that there's a variable named entityPath(svxEntPath)
       ZwEntityPathTransfer(1, &entityPath, &entityHandle);
       ...
       ZwEntityHandleFree(&entityHandle);

       // transfer entity array
       szwEntityHandle entityHandles[arrayCount];
       // assume that there are a variable named arrayCount(int) and a variable named entityPaths(svxEntPath [] or svxEntPath *)
       ZwEntityIdTransfer(arrayCount, entityPaths, entityHandles);
       ...
       for (int i = 0; i < arrayCount; ++i)
       {
          ZwEntityHandleFree(&entityHandles[i]);
       }
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityPathTransfer(int count, const svxEntPath *entityPaths, szwEntityHandle *entityHandles);

    /**
    @ingroup ZwEntity

    Frees the inner data of the specified entity handle.

    @param [in] entityHandle entity handle data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwEntityHandleFree(szwEntityHandle *entityHandle);

    /**
    @ingroup ZwEntity

    Frees the memory of an entity handle list and the inner data.  
    In this function, it will free each member's inner data of entityList, then  
    free the list.

    @param [in] count the count of entity handle list
    @param [in] entityList entity handle list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwEntityHandleListFree(int count, szwEntityHandle **entityList);

    /**
    @ingroup ZwEntity

    Gets the id of entity specified by entity handle.

    @note
    Before using this function, you need to allocate memory for "entityIdList" first.  
    Id can be used in old style api(cvx***)  
    Id can identify the entity in specified zw3d file, but it can be repetitive in different files.  
    So DON'T get an id from one file and use it in other files.

    @param [in] count number of entity handles
    @param [in] handleList list of entity handle
    @param [out] entityIdList list of entity id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwEntityIdGet(int count, const szwEntityHandle *handleList, int *entityIdList);

    /**
    @ingroup ZwEntity

    Gets the entity path of entity specified by entity handle.

    @note
    Before using this function, you need to allocate memory for "entityPathList" first.  
    Entity path can be used in old style api(cvx***)  
    Entity path can identify the entity in specified zw3d document, but it can be repetitive in different document.  
    So DON'T get an entity path from one document and use it in other document.

    @param [in] count number of entity handles
    @param [in] handleList list of entity handle
    @param [out] entityPathList list of entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwEntityPathGet(int count, const szwEntityHandle *handleList, svxEntPath *entityPathList);

    //====================================================================================================================
    /** @name Entity UniqueId */
    //====================================================================================================================
    /**
    @ingroup ZwEntity

    Outputs the unique id of the specified entity in the active part.

    @note
    The caller is responsible to free the entityId.innerData by using ZwMemoryFree().

    @param [in] entityHandle entity handle
    @param [out] entityId entity id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -    ZW_API_GENERAL_ERROR
    -    ZW_API_ROOT_OBJ_ACT_FAIL
    -    ZW_API_INVALID_OUTPUT
    -    ZW_API_INVALID_INPUT
    -    ZW_API_MEMORY_ERROR
    -    ZW_API_OBJECT_NO_UNIQUEID

    @code
        szwEntityHandle entityHandle{};
        szwEntityIdentifier entityId{};
        ZwEntityUniqueIdGet(entityHandle, &entityId);
        ZwMemoryFree((void**)&entityId.innerData);
    @endcode
    */
    ZW_API_C ezwErrors ZwEntityUniqueIdGet(szwEntityHandle entityHandle, szwEntityIdentifier *entityId);

    /**
    @ingroup ZwEntity
    
    Searches the active part for an entity with the specified label.
    
    @param [in] entityId entity id
    @param [out] entityHandle entity handle(nullptr is output if no entity is found)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwEntityGetByUniqueId(szwEntityIdentifier entityId, szwEntityHandle *entityHandle);

    //====================================================================================================================
    /** @name Entity Regen */
    //====================================================================================================================

    /**
    @ingroup ZwEntity

    Invoke the specified function of entity regenerate of the activated file.
    "regenMode" controls the regen mode:
        ZW_REGEN_FOR_HISTORY means  regen history,
        ZW_REGEN_FOR_OUTDATED_OBJECTS means regen objects,
        ZW_REGEN_FOR_ASSEMBLY_ALL_COMPONENT means regen all component in assembly.
    "prompt" controls the status of prompt dialog for "No need to updated ....".
        0 - enable;
        >0 - disable: the default action is "Yes";
       -<0 - disable: the default action is "No"

    @note
    Only when the active file is an assembly, can the third mode be work.

    @param [in] regenMode regen mode
    @param [in] prompt flag to control the prompt status

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_GENERAL_ERROR
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    -       ZW_API_WRONG_ROOT_ENV
    -       ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwEntityAutoRegen(ezwEntityRegenMode regenMode, int prompt);

    /**
    @ingroup ZwEntity

    Specify the associated lines, edges and other solid objects that need to be 
    queried in the 3D environment (parts, assembly), enter the drawing name and 
    root name to be queried (the root name under a single root file is the same 
    as the file name), and specify the list of views you need to query. 
    
    The interface returns the 2D geometric objects corresponding to 3D solids in 
    the drawing in the view order you specify. It should be noted that the display 
    and hidden state of two-dimensional geometry in the drawing will not affect 
    the acquisition of association, even if the 2D geometric objects are hidden.

    @note
    The caller is responsible to free the referenceList by using ZwEntityReferenceViewGeometryListFree.

    @param [in] entityHandle edge and curve handle
    @param [in] fileName file name
    @param [in] rootName root name
    @param [in] viewCount count of the view
    @param [in] viewHandleList handle list of view
    @param [out] countView the output count of view
    @param [out] referenceList referenced geometry list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_GENERAL_ERROR
    -       ZW_API_INPUT_TYPE_ERROR
    -       ZW_API_INVALID_INPUT
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    -       ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwEntityReferenceDrawingGeometryGetByView(szwEntityHandle entityHandle, zwPath fileName, zwRootName rootName, int viewCount, szwEntityHandle *viewHandleList, int *countView, szwReferenceViewGeometryList **referenceList);

    /**
    @ingroup ZwEntity

    Specify the associated lines, edges and other solid objects that need to be queried 
    in the 3D environment (parts, assembly), enter the drawing name and root name to be 
    queried (the root name under a single root file is the same as the file name), 
    and specify the Sheet list you need to query. The interface returns in the Sheet order 
    you specify, and outputs views and a list of 2D objects that exist corresponding to 
    2D geometric objects. 
    
    It should be noted that the display and hidden state of 2D geometric objects in the 
    drawing will not affect the acquisition of association, even if the 2D geometric objects are hidden.


    @note
    The caller is responsible to free the referenceList by using ZwEntityReferenceViewGeometryListFree.

    @param [in] entityHandle edge and curve handle
    @param [in] fileName file name
    @param [in] rootName root name
    @param [in] sheetCount count of the sheet
    @param [in] sheetHandleList handle list of sheet
    @param [out] countSheet the output count of view
    @param [out] referenceList referenced geometry list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_GENERAL_ERROR
    -       ZW_API_INPUT_TYPE_ERROR
    -       ZW_API_INVALID_INPUT
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    -       ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwEntityReferenceDrawingGeometryGetBySheet(szwEntityHandle entityHandle, zwPath fileName, zwRootName rootName, int sheetCount, szwEntityHandle *sheetHandleList, int *countSheet, szwReferenceSheetGeometryList **referenceList);

    /**
    @ingroup ZwEntity

    Specify the associated lines, edges and other solid objects that need to be queried 
    in the 3D environment (parts, assembly), and enter the drawing name and root name to 
    be queried (the root name is the same as the file name under a single root file). 
    
    This API will return all 2D geometric objects corresponding to 3D entities in the drawing,
    and the output will be based on the Sheet page. Sheet with no corresponding geometry will 
    not be returned, and you can see the corresponding view and 2D geometric objects in its 
    substructures. 
    
    It should be noted that the display and hidden state of 2D geometric objects in the drawing 
    will not affect the acquisition of association, even if the 2D geometric objects are hidden.


    @note
    The caller is responsible to free the referenceList by using ZwEntityReferenceViewGeometryListFree.

    @param [in] entityHandle edge and curve handle
    @param [in] fileName file name
    @param [in] rootName root name
    @param [out] countSheet the output count of view
    @param [out] referenceList referenced geometry list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_GENERAL_ERROR
    -       ZW_API_INPUT_TYPE_ERROR
    -       ZW_API_INVALID_INPUT
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    -       ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwEntityReferenceDrawingGeometryGetAll(szwEntityHandle entityHandle, zwPath fileName, zwRootName rootName, int *countSheet, szwReferenceSheetGeometryList **referenceList);

    /**
    @ingroup ZwEntity

    Frees memory associated with the specified szwReferenceViewGeometryList structure.

    @param [in] countData count of input data
    @param [in] referenceList referenced geometry list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwEntityReferenceViewGeometryListFree(int countData, szwReferenceViewGeometryList **referenceList);

    /**
    @ingroup ZwEntity

    Frees memory associated with the specified szwReferenceSheetGeometryList structure.

    @param [in] countData count of input data
    @param [in] referenceList referenced geometry list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwEntityReferenceSheetGeometryListFree(int countData, szwReferenceSheetGeometryList **referenceList);
/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_ENTITY_H */