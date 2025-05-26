/**
@file zwapi_general_ent.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Object's(Entity) Common API
*/
/**
@defgroup zwapi_general_ent General Entity API
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Object's(Entity) Common API
*/

#pragma once
#ifndef ZW_API_GENERAL_ENT_H /* this ifndef surrounds entire header */
#define ZW_API_GENERAL_ENT_H

#include "zwapi_util.h"
#include "zwapi_matrix.h"
#include "zwapi_entity.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Entity Calculate Data */
    //====================================================================================================================
    /**
    @brief area properties
    @ingroup zwapi_general_ent
    */
    typedef struct svxAreaProp
    {
        svxPoint refPnt;          /**<@brief  ref point */
        svxPoint centPnt;         /**<@brief  centroid */
        double dArea;             /**<@brief  area(mm^2) */
        double dPerim;            /**<@brief  perimeter(mm)*/
        double dDensity;          /**<@brief  density(kg/mm^3) */
        double dAMass;            /**<@brief  mass(kg)*/
        svxPrfAreaProp *pAreaRef; /**<@brief  area properties about ref */
        svxPrfAreaProp *pAreaCA;  /**<@brief  area properties about centroid */
    } svxAreaProp;

    //====================================================================================================================
    /** @name Entity New */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Returns the id of the last entity of the specified type created
    since the specified operation (StartOp) of the current transaction.  
    Use cvxOpCount() to get the current number of operations in the
    current transaction. 

    @deprecated This API will not be updated anymore, please use ZwEntityCreateGet()
    @see ZwEntityCreateGet
    @see ZwEntityCreateListGet
    @see ZwEntityCreateGetAll

    @note
    All values of evxEntType can be used in this function.  
    If "Type > 0", the specified entity is flagged.  
    If "Type = 0", to signal all entity are valid.  
    If "Type = -1", curve entity (e.g. line,circle, arc,curve) are flagged.  
    If "Type = -2", point entity are flagged.  
    If "Type = -3", history entity (e.g. feature, sketch, datum) are flagged.  
    If "Type = -4", b-rep entity are flagged.  

    @param [in] StartOp starting operation number ( >= 0 )
    @param [in] Type entity type

    @retval return
    -        > 0 - index of new entity
    -         0 -  no entity of the specified type is found or error occurs
    @warning
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C int cvxEntNew(int StartOp, evxEntType Type);

    /**
    @ingroup zwapi_general_ent

    Returns a list of the id's of the entities of the specified type
    created since the specified operation (StartOp) of the current
    transaction.

    Use cvxOpCount() to get the current number of
    operations in the current transaction.

    @deprecated This API will not be updated anymore, please use ZwEntityCreateListGet()
    @see ZwEntityCreateGet
    @see ZwEntityCreateListGet
    @see ZwEntityCreateGetAll

    @note
    This interface can only get the new ID on the feature tree.
    cvxEntNewAll() can get all newly generated IDs.  
    All values of evxEntType can be used in this function.  
    If "Type > 0", the specified entity is flagged.  
    If "Type = 0", to signal all entity are valid.   
    If "Type = -1", curve entity (e.g. line,circle, arc,curve) are flagged.  
    If "Type = -2", point entity are flagged.  
    If "Type = -3", history entity (e.g. feature, sketch, datum) are flagged.  
    If "Type = -4", b-rep entity are flagged.  

    @param [in] StartOp starting operation number ( >= 0)
    @param [in] Type entity type
    @param [out] Count number of new entities
    @param [out] idEnts list of new entities (by id)

    @warning
    -         ZW_API_INVALID_OUTPUT
    -         ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C void cvxEntNewList(int StartOp, evxEntType Type, int *Count, int **idEnts);

    /**
    @ingroup zwapi_general_ent

    Return a list of the id's of the entities of the specified type
    created since the specified operation (StartOp) of the current
    transaction.

    Use cvxOpCount() to get the current number of
    operations in the current transaction.

    @deprecated This API will not be updated anymore, please use ZwEntityCreateGetAll()
    @see ZwEntityCreateGet
    @see ZwEntityCreateListGet
    @see ZwEntityCreateGetAll

    @note
    The caller is responsible to free the idEnts by using cvxMemFree().  
    This interface can get all newly generated IDs.  
    cvxEntNewList() can only get the new ID on the feature tree.  
    All values of evxEntType can be used in this function.  
    If "Type > 0", the specified entity is flagged.  
    If "Type = 0", to signal all entity are valid.  
    If "Type = -1", curve entity (e.g. line,circle, arc,curve) are flagged.  
    If "Type = -2", point entity are flagged.  
    If "Type = -3", history entity (e.g. feature, sketch, datum) are flagged.  
    If "Type = -4", b-rep entity are flagged.  

    @param [in] startOp starting operation number ( >= 0)
    @param [in] type entity type
    @param [out] count number of new entities
    @param [out]  idEnts list of new entities (by id)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -         ZW_API_INVALID_OUTPUT
    -         ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntNewAll(int startOp, evxEntType type, int *count, int **idEnts);

    //====================================================================================================================
    /** @name Name Tag Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Outputs a list of tag names that belong to the current active part.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @deprecated This API will not be updated anymore, please use ZwEntityNameTagGetAll()
    @see ZwEntityNameTagSet
    @see ZwEntityNameTagGet
    @see ZwEntityNameTagGetAll

    @param [out] Count number of tag names
    @param [out] Names list of tag names

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxPartInqTagNames(int *Count, vxLongName **Names);

    //====================================================================================================================
    /** @name Entity State */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Blanks or unblanks the specified entities.

    Call this function during echoing will not log any
    blank/unblank operation to the history, for example:
    @code
       cvxEchoStart();
       cvxEntBlank(1, nEntity, &idEntity);
       cvxEchoEnd();
    @endcode
    Besides, input "Count" as a negative number can
    prevent a blank/unblank operation from being logged to
    the history in the case that this function is being
    applied to a part entity.

    @deprecated This API will not be updated anymore, please use ZwEntityBlankSet()
    @see ZwEntityBlankSet

    @param [in] Show 1 to unblank entities; 0 to blank
    @param [in] Count number of entities
    @param [in] idEnts entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    -        ZW_API_INPUT_ERROR
    */
    ZW_API_C evxErrors cvxEntBlank(int Show, int Count, int *idEnts);

    /**
    @ingroup zwapi_general_ent

    @deprecated This API will not be updated anymore, please use ZwEntityBlankGet()
    @see ZwEntityBlankGet

    @param [in] idEntity entity id (in active file)

    Determine whether the specific entity is blanked.

    @retval return
    -        1 - the specified entity is blanked
    -        0 - the specified entity is visible or error occurs
    @warning
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C int cvxEntIsBlanked(int idEntity);

    /**
    @ingroup zwapi_general_ent

    Highlights the specified entity in the active root object.

    @deprecated This API will not be updated anymore, please use ZwEntityHighlight()
    @see ZwEntityHighlight

    @param [in] idEntity entity id (in active file)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */

    ZW_API_C void cvxEntHighlight(int idEntity);

    /**
    @ingroup zwapi_general_ent

    Un-Highlight the specified entity in the active root object.

    @deprecated This API will not be updated anymore, please use ZwEntityUnHighlight()
    @see ZwEntityUnHighlight

    @param [in] idEntity entity id (in active file)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C void cvxEntUnHighlight(int idEntity);

    /**
    @ingroup zwapi_general_ent

    Highlights the specified entity.

    @deprecated This API will not be updated anymore, please use ZwEntityHighlight()
    @see ZwEntityHighlight

    @param [in] entityPath entity path.

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C void cvxEntHighlightByPath(const svxEntPath *entityPath);

    /**
    @ingroup zwapi_general_ent

    Un-Highlight the specified entity.

    @deprecated This API will not be updated anymore, please use ZwEntityUnHighlight()
    @see ZwEntityUnHighlight

    @param [in] entityPath entity path.

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C void cvxEntUnHighlightByPath(const svxEntPath *entityPath);

    /**
    @ingroup zwapi_general_ent

    Unhighlights all entities.

    @deprecated This API will not be updated anymore, please use ZwEntityUnhighlightAll()
    @see ZwEntityUnhighlightAll

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C void cvxEntUnhighlightAll(void);

    /**
    @ingroup zwapi_general_ent

    Determine whether a valid entity with the specified type exists in the active root.

    @param [in] idEntity entity id
    @param [in] EntType entity type

    @deprecated This API will not be updated anymore, please use ZwEntityExistenceCheck()
    @see ZwEntityExistenceCheck

    @note
    Some of evxEntType(VX_ENT_BREP, VX_ENT_OP, VX_ENT_POINT, VX_ENT_WIRE) are banned in this function.

    @retval succeeds
    -        1 - if a valid entity with the specified type and id exists in the active file
    -        0 - the entity is not found/invalid input/current root is wrong
    @warning
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C int cvxEntExists(int idEntity, evxEntType EntType);

    /**
    @ingroup zwapi_general_ent

    Outputs a list of the selected entity IDs.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @deprecated This API will not be updated anymore, please use ZwEntityPickListGet()
    @see ZwEntityPickListGet

    @param [out] Count number of entities
    @param [out] Ents list of the entity IDs

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxEntInqSelected(int *Count, int **Ents);

    /**
    @ingroup zwapi_general_ent

    Outputs a list of the Picked entity IDs.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @deprecated This API will not be updated anymore, please use ZwEntityPickListGet()
    @see ZwEntityPickListGet

    @param [out] Count number of entities
    @param [out] Ents list of the entity IDs

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no entity was picked
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxEntInqPicked(int *Count, int **Ents);

    /**
    @ingroup zwapi_general_ent

    Outputs a list of the selected entity path.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @deprecated This API will not be updated anymore, please use ZwEntityPickListGet()
    @see ZwEntityPickListGet

    @param [out] Count number of entity path
    @param [out] Paths list of the entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxEntInqPathSelected(int *Count, svxEntPath **Paths);

    /**
    @ingroup zwapi_general_ent

    Outputs a list of the picked entity path.
    The calling procedure MUST deallocate the output list with cvxMemFree().

    @deprecated This API will not be updated anymore, please use ZwEntityPickListGet()
    @see ZwEntityPickListGet

    @param [out] Count number of entity path
    @param [out] Paths list of the entity path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or no entity was picked
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INVALID_OBJ
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxEntInqPathPicked(int *Count, svxEntPath **Paths);

    /**
    @ingroup zwapi_general_ent

    Unpick the entity list in active field.

    @deprecated This API will not be updated anymore, please use ZwEntityUnPickAll()
    @see ZwEntityUnPickAll

    */
    ZW_API_C void cvxEntUnPickAll();

    /**
    @ingroup zwapi_general_ent

    Unpick the last entity in active field.

    @deprecated This API will not be updated anymore, please use ZwEntityUnPickLast()
    @see ZwEntityUnPickLast

    */
    ZW_API_C void cvxEntUnPickLast();

    /**
    @ingroup zwapi_general_ent

    Unpick the entity list in active field.

    @deprecated This API will not be updated anymore, please use ZwEntityUnPick()
    @see ZwEntityUnPick

    @param [in] path pick path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_ENT_PATH
    */
    ZW_API_C evxErrors cvxEntUnPickByPath(const svxEntPath *path);

    /**
    @ingroup zwapi_general_ent

    Add the specified entity to the pick list.

    @deprecated This API will not be updated anymore, please use ZwEntityPickListAdd()
    @see ZwEntityPickListAdd

    @param [in] idx_ent index of entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxEntAddPick(int idx_ent);

    /**
    @ingroup zwapi_general_ent

    Add the specified entity to the pick list.

    @deprecated This API will not be updated anymore, please use ZwEntityPickListAdd()
    @see ZwEntityPickListAdd

    @param [in] entPath pick path of entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_INVALID_OBJ
    */
    ZW_API_C evxErrors cvxEntPathAddPick(svxEntPath *entPath);

    /**
    @ingroup zwapi_general_ent

    Clear the pick data for ray casting

    */
    ZW_API_C void cvxPickDataClear();

    //====================================================================================================================
    /** @name Entity Attribute */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Retrieves attribute data from the specified entity in the active file.  

    The calling procedure MUST deallocate the output list with cvxMemFree().

    @deprecated This API will not be updated anymore, please use ZwEntityUserAttributeGet()
    @see ZwEntityUserAttributeGet

    @param [in] idEnt the entity index
    @param [out] count number of user attributes
    @param [out]  At list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OBJ
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxEntUserAtGet(int idEnt, int *count, svxAttribute **At);

    /**
    @ingroup zwapi_general_ent

    Sets the user attribute for the specified entity(only shape, face and edge) in the current active part. \n
    A new user attribute is inserted if the user attribute for the specified label does not exist.

    @deprecated This API will not be updated anymore, please use ZwEntityUserAttributeSet()
    @see ZwEntityUserAttributeSet

    @param [in] idEnt the entity(ONLY SHAPE, FACE and EDGE) index
    @param [in] count number of user attributes
    @param [in] At list of user attributes

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxEntUserAtSet(int idEnt, int count, svxAttribute *At);

    /**
    @ingroup zwapi_general_ent

    Delete user attribute of the specified entity(ONLY SHELL, FACE and EDGE) in the current active part.  
    the function does not delete any attributes if the specified label is an empty string or the attribute
    specified label is not found.

    @deprecated This API will not be updated anymore, please use ZwEntityUserAttributeDelete()
    @see ZwEntityUserAttributeDelete

    @param [in] idEnt the entity(ONLY SHELL, FACE and EDGE) index
    @param [in] count number of user attributes (0 to delete all user attributes)
    @param [in] At list of user attributes (NULL to delete all user attributes)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxEntUserAtDel(int idEnt, int count, svxAttribute *At);

    /**
    @ingroup zwapi_general_ent

    Gets the standard color number assigned to "idEntity".

    @deprecated This API will not be updated anymore, please use ZwEntityColorGet()
    @see ZwEntityColorGet

    @see cvxEntRgbGet

    @param [in] idEntity entity id (in active file)
    @param [out] Color entity color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxEntColorGet(int idEntity, evxColor *Color);

    /**
    @ingroup zwapi_general_ent

    Assigns the specified color to the specified entities in
    the active object.

    @deprecated This API will not be updated anymore, please use ZwEntityColorSet()
    @see ZwEntityColorSet

    @see cvxEntRgbSet

    @param [in] Color entity color
    @param [in] Count number of entities
    @param [in] idEnts entity id's

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
    ZW_API_C evxErrors cvxEntColorSet(evxColor Color, int Count, int *idEnts);

    /**
    @ingroup zwapi_general_ent

    Gets the color assigned to "idEntity" in RGB format.

    @deprecated This API will not be updated anymore, please use ZwEntityColorRgbGet()
    @see ZwEntityColorRgbGet

    @see cvxEntColorGet

    @param [in] idEntity entity id (in active file)
    @param [out] Color entity RGB color

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntRgbGet(int idEntity, svxColor *Color);

    /**
    @ingroup zwapi_general_ent

    Assigns the specified RGB color to the specified entities in
    the active object.  
    Presently, only face entities support true RGB color.  
    For other entities, the specified RGB color is
    mapped to the closest standard color (evxColor).

    @deprecated This API will not be updated anymore, please use ZwEntityColorRgbSet()
    @see ZwEntityColorRgbSet

    @see cvxEntColorSet

    @param [in] Color entity RGB color
    @param [in] Count number of entities
    @param [in] idEnts entity id's

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
    ZW_API_C evxErrors cvxEntRgbSet(svxColor Color, int Count, int *idEnts);

    /**
    @ingroup zwapi_general_ent

    Same as cvxEntRgbSet() except that no display attribute created.

    @deprecated This API will not be updated anymore, please use ZwEntityTemporaryColorRgbSet()
    @see ZwEntityTemporaryColorRgbSet

    @param [in] Color entity RGB color
    @param [in] Count number of entities
    @param [in] idEnts entity id's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxEntRgbSetNoAt(svxColor Color, int Count, int *idEnts);

    /**
    @ingroup zwapi_general_ent

    Assigns the specified transparency to the specified entities in
    the active object.

    If the input transparency value exceeds 0-100, this function will fail.

    @deprecated This API will not be updated anymore, please use ZwEntityTransparencySet()
    @see ZwEntityTransparencySet

    @param [in] iTrans Entity transparency value, from 0 to 100, both ends included
    @param [in] Count number of entities
    @param [in] idEnts entity id's

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
    ZW_API_C evxErrors cvxEntTransSet(int iTrans, int Count, int *idEnts);

    /**
    @ingroup zwapi_general_ent

    Get the specified transparency to the specified entities in
    the active object.

    @deprecated This API will not be updated anymore, please use ZwEntityTransparencyGet()
    @see ZwEntityTransparencyGet

    @param [in] idEnts entity id
    @param [out] iTrans Entity transparency value, from 0 to 100, both ends included

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_OBJ
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxEntTransGet(int idEnts, int *iTrans);

    /**
    @ingroup zwapi_general_ent

    Get the attributes of specified line.

    @deprecated This API will not be updated anymore, please use ZwLineAttributeGet()
    @see ZwLineAttributeGet

    @param [in] idLine index of entity
    @param [out] At line attribute

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxEntLineAtGet(int idLine, svxLineAt *At);

    /**
    @ingroup zwapi_general_ent

    Sets the attributes of specified lines.if you only
    need to update some of the attributes,you can first
    get the original attributes through cvxEntLineAtGet().

    @deprecated This API will not be updated anymore, please use ZwLineAttributeSet()
    @see ZwLineAttributeSet

    @param [in] At line attribute
    @param [in] Count number of entities
    @param [in] idEnts entity id's

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
    ZW_API_C evxErrors cvxEntLineAtSet(svxLineAt *At, int Count, int *idEnts);

    //====================================================================================================================
    /** @name Entity Info Get/Set */
    //====================================================================================================================

    /**
    @ingroup zwapi_general_ent

    Output the unique identifier of the specified entity.  
    The unique identifier is a tuple of three numbers that, taken together, identify
    the entity in a persistent way across sessions.  
    In contrast to "idEntity" (the entity ID), which usually changes from session to
    session, "Uid" (the unique ID) does not change between sessions and
    can be used to identify the entity in any session.

    A unique ID is unique in the sense that no other entity in the same
    root object should have the same unique ID, but it is possible for two
    entities in different root objects to have the same unique ID.

    @deprecated This API will not be updated anymore, please use ZwEntityUniqueIdGet()
    @see ZwEntityUniqueIdGet

    @see cvxRootCopy().

    @param [in] idEntity entity id
    @param [out] Uid unique id for the specified entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJECT_NO_UNIQUEID
    */
    ZW_API_C evxErrors cvxEntUidGet(int idEntity, svxUid *Uid);

    /**
    @ingroup zwapi_general_ent

    Assign a unique identifier to the specified entity.  
    Refer to cvxEntUidGet() for a description of unique identifiers and how the
    entity ID differs from the entity's unique ID.

    A unique ID should be unique in the sense that no other entity in the
    same root object should have the same unique ID, although it is
    possible for two entities in different root objects to have the same
    unique ID.

    @see cvxRootCopy().

    @deprecated This API will not be updated anymore.

    @param [in] idEntity entity id
    @param [in] Uid unique id to assign to the specified entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxEntUidSet(int idEntity, const svxUid *Uid);

    /**
    @ingroup zwapi_general_ent

    Outputs the persistent label of the specified entity in the active part.

    The label is a null-terminated list of integers.

    The calling procedure is responsible for deallocating the memory
    out via "Label".

    @code
    // Example
    int *Label=NULL;
    int idEntity = 99;

    cvxPartInqEntLabel(idEntity, &Label);
    cvxMemFree((void**)&Label);
    @endcode

    @see cvxLabelMatch() and cvxPartInqEntByLabel().

    @deprecated This API will not be updated anymore, please use ZwEntityUniqueIdGet()
    @see ZwEntityUniqueIdGet

    @param [in] idEntity entity id
    @param [out] Label persistent label as null-terminated array of integers

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJECT_NO_UNIQUEID
    */
    ZW_API_C evxErrors cvxPartInqEntLabel(int idEntity, int **Label);

    /**
    @ingroup zwapi_general_ent

    Outputs the persistent label of the specified entity in the active file,
    or a NULL pointer if the entity does not have a label.  
    Currently, only entities generated by a part history have persistent labels.

    The label is a null-terminated list of integers.

    The calling procedure is responsible for deallocating the memory
    out via "Label" as shown below:

    @code
          int *Label=NULL;
          cvxEntLabelGet(idEntity,&Label);
          cvxMemFree((void**)&Label);
    @endcode

    @see cvxLabelMatch() and cvxEntByLabel().

    @deprecated This API will not be updated anymore, please use ZwEntityUniqueIdGet()
    @see ZwEntityUniqueIdGet

    @param [in] idEntity entity id
    @param [out] Label persistent label as null-terminated array of integers

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJECT_NO_UNIQUEID
    */
    ZW_API_C evxErrors cvxEntLabelGet(int idEntity, int **Label);

    /**
    @ingroup zwapi_general_ent

    Assigns a copy of the input label (i.e. integer null-terminated list
    of integers) to the specified object.  If the object already has a
    label, the existing label is overwritten.  If "label=NULL", this
    function returns without doing anything (no error).

    @deprecated This API will not be updated anymore.

    @param [in] idEntity entity id
    @param [in] Label persistent label as null-terminated array of integers

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxEntLabelSet(int idEntity, int *Label);

    /**
    @ingroup zwapi_general_ent

    Outputs the name of the specified entity.  
    It is assumed the entity resides in the active file.  
    A blank string is output if the entity doesn't have a name.

    @deprecated This API will not be updated anymore, please use ZwEntityNameGet()
    @see ZwEntityNameGet

    @param [in] idEntity entity id
    @param [out] Name entity name
    @param [in] nBytes string max size of entity name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxEntName(int idEntity, char *Name, int nBytes);

    /**
    @ingroup zwapi_general_ent

    Assigns the specified name to the specified entity.  
    It is assumed the entity resides in the active file.  
    It is assumed the entity has a "name" field.

    This function is often used to set the name of dimension/datum/texture/block/config/sheet/equation...  
    You can use function "cvxEntSetNameTag()" to set the name tag of shell/face...

    @deprecated This API will not be updated anymore, please use ZwEntityNameSet()
    @see ZwEntityNameSet

    @param [in] idEntity entity id
    @param [in] Name entity name

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
    ZW_API_C evxErrors cvxEntNameSet(int idEntity, const char *Name);

    /**
    @ingroup zwapi_general_ent

    Assign the input name tag to the specified entity.  
    name:empty-delete the name tag, else add the name tag.

    @deprecated This API will not be updated anymore, please use ZwEntityNameTagSet()
    @see ZwEntityNameTagSet
    @see ZwEntityNameTagGet
    @see ZwEntityNameTagGetAll

    @param [in] idx_ent index of entity
    @param [in] name name tag

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxEntSetNameTag(int idx_ent, char *name);
    
    /**
    @ingroup zwapi_general_ent

    Outputs the name of the specified entity's layer.

    @deprecated This API will not be updated anymore, please use ZwEntityLayerGet()
    @see ZwEntityLayerGet

    @param [in] idEntity entity id
    @param [out] Layer layer name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntLayer(int idEntity, vxName Layer);

    /**
    @ingroup zwapi_general_ent

    Outputs the id of the specified entity's layer.

    @deprecated This API will not be updated anymore, please use ZwEntityLayerGet()
    @see ZwEntityLayerGet

    @param [in] idEntity entity id
    @param [out] LayerId layer id

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntLayerId(int idEntity, int *LayerId);

    /**
    @ingroup zwapi_general_ent

    Outputs the transformation matrix associated with the specified entity.

    @deprecated This API will not be updated anymore, please use ZwEntityMatrixGet()
    @see ZwEntityMatrixGet

    @param [in] idEntity entity id
    @param [out] Matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntMatrix(int idEntity, svxMatrix *Matrix);

    /**
    @ingroup zwapi_general_ent

    Outputs the transformation matrix of the specified entity
    as defined by the input pick-path.  
    The transformation locates the entity relative to the path's root object.

    @deprecated This API will not be updated anymore, please use ZwEntityTransformMatrixGet()
    @see ZwEntityTransformMatrixGet

    @param [in] Entity entity pick path
    @param [out] Matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxEntMatrix2(svxEntPath Entity, svxMatrix *Matrix);

    /**
    @ingroup zwapi_general_ent

    Sets the transformation matrix associated with the specified entity in the active file.  
    If the entity does not support a transformation matrix, nothing is done.

    @deprecated This API will not be updated anymore, please use ZwEntityMatrixSet()
    @see ZwEntityMatrixSet

    @param [in] idEntity entity id
    @param [in] Matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxEntMatrixSet(int idEntity, svxMatrix *Matrix);

    /**
    @ingroup zwapi_general_ent

    Outputs the id of the parent feature of the specified entity
    in the active part.

    @deprecated This API will not be updated anymore, please use ZwEntityParentFeatureGet()
    @see ZwEntityParentFeatureGet

    @param [in] idEntity entity id
    @param [out] idFeature parent feature id (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxPartInqEntFtr(int idEntity, int *idFeature);

    /**
    @ingroup zwapi_general_ent

    This function gets the bounding box of the specified entity in the target file in world coordinate system.  
    if you want to obtain the bounding box of specified entity in custom coordinate system, please use cvxPartInqEntBox().

    @deprecated This API will not be updated anymore, please use ZwEntityBoundingBoxGet()
    @see ZwEntityBoundingBoxGet

    @param [in] idEntity entity id
    @param [out] Box bounding box of specified entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxEntBndBox(int idEntity, svxBndBox *Box);

    /**
    @ingroup zwapi_general_ent

    This function gets the bounding box of the specified entity in the pick path.

    Interface cvxBndBoxTransform can convert envelope boxes to different matrices.  
    Interface cvxBndBoxPnts can convert the envelope box to the coordinate value
    under the current world coordinate system.  
    Interface cvxPntTransform can convert points under different coordinate systems.

    @note When the matrix of the specified entity is not orthogonal to the matrix of 
    the current world coordinate system, it is recommended that fTartCord=0,
    otherwise fTartCord=1.  
    When fTartCord=1, the envelope box output from the interface can be directly converted
    to points. The envelope box drawn according to the coordinates of these points is correct.  
    When fTartCord=0, you need to convert the envelope box to the point coordinates first,
    and then convert the point to the point coordinates under the current coordinate system.
    At this time, the envelope box drawn according to the point coordinates is correct.

    @deprecated This API will not be updated anymore, please use ZwEntityBoundingBoxGet()
    @see ZwEntityBoundingBoxGet

    @param [in] path  entity pick path
    @param [in] fTartCord  the boundary box in target coordinate(1 or 0)
    @param [out] bndBox  bounding box of specified entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ENT_PATH_ERROR
    */
    ZW_API_C evxErrors cvxEntBndBoxByPath(svxEntPath *path, int fTartCord, svxBndBox *bndBox);

    /**
    @ingroup zwapi_general_ent

    Gets the bounding box of the specified entity in the active part.  
    currently, only shape, face and component are support. If "*Mat = NULL",
    initializes "Mat" to the identity matrix.  
    a bounding box relative to the specified local coordinate frame is output.

    @deprecated This API will not be updated anymore, please use ZwEntityBoundingBoxGet()
    @see ZwEntityBoundingBoxGet

    @param [in] idEnt entity id (supported entity: shape,face,component)
    @param [in] Mat optional local frame (or NULL)
    @param [out] Box shape bounding box

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    */
    ZW_API_C evxErrors cvxPartInqEntBox(int idEnt, const svxMatrix *Mat, svxBndBox *Box);

    //====================================================================================================================
    /** @name Entity Find */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Searches the active part for an entity with the specified label.

    @deprecated This API will not be updated anymore, please use ZwEntityGetByUniqueId()
    @see ZwEntityGetByUniqueId

    @param [in] Label persistent label as null-terminated array of integers
    @param [in] Exact 1 for exact match; 0 if partial match is okay
    @param [out] idEntity entity id  (0 is output if no entity is found)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C evxErrors cvxEntByLabel(int *Label, int Exact, int *idEntity);

    /**
    @ingroup zwapi_general_ent

    Searches the active part for an entity with the specified label.

    @deprecated This API will not be updated anymore, please use ZwEntityGetByUniqueId()
    @see ZwEntityGetByUniqueId

    @param [in] Label persistent label as null-terminated array of integers
    @param [in] Exact 1 for exact match; 0 if partial match is okay
    @param [out] idEntity entity id  (0 is output if no entity is found)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR - function fails or entity is not found.
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxPartInqEntByLabel(int *Label, int Exact, int *idEntity);

    /**
    @ingroup zwapi_general_ent

    Searches the active object for the entity with the specified
    name.  
    If it is found, its id is output via "idEntity".  If
    it is not found, "idEntity = 0" is output.

    @deprecated This API will not be updated anymore, please use ZwEntityGetByNameAndType()
    @see ZwEntityGetByNameAndType

    @param [in] Name entity name
    @param [out] idEntity entity id (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxEntByName(const char *Name, int *idEntity);

    /**
    @ingroup zwapi_general_ent

    Searches the specified root object in the specified file for the entity
    with the specified name.  
    If it is found, its id is output via "idEntity".  
    If it is not found, "idEntity = 0" is output.

    @deprecated This API will not be updated anymore, please use ZwEntityGetByNameAndType()
    @see ZwEntityGetByNameAndType

    @param [in] File object file name (File[0]=0 or NULL for active file)
    @param [in] Root root object name (Root[0]=0 or NULL for active target object)
    @param [in] Name entity name
    @param [out] idEntity entity id (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxEntByName2(const vxLongPath File, const vxRootName Root, const vxName Name, int *idEntity);

    /**
    @ingroup zwapi_general_ent

    This function gets the name of the entity specified by a pick path.

    @deprecated This API will not be updated anymore, please use ZwEntityNameGet()
    @see ZwEntityNameGet

    @param [in] Path entity pick path
    @param [out] Name entity name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_ENT_PATH
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxEntNameByPath(const svxEntPath *Path, vxLongName Name);

    /**
    @ingroup zwapi_general_ent

    Searches the active target for an entity with the specified unique
    identifier.

    @deprecated This API will not be updated anymore, please use ZwEntityGetByUniqueId()
    @see ZwEntityGetByUniqueId

    @param [in] Uid unique id of entity to find
    @param [out] idEntity entity id  (0 is output if no entity is found)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxEntByUid(const svxUid *Uid, int *idEntity);

    /**
    @ingroup zwapi_general_ent

    Finds the closest entity of the specified type to "RefPnt"
    and outputs its index via "idEntity" (0 is output if no
    entity is found).  
    If "Pnt" is not NULL, the coordinates
    of "RefPnt" projected onto the entity are output via "Pnt".  
    If "Dist" is not NULL, the shortest distance between the
    entity and "RefPnt" is output via "Dist".

    @deprecated This API will not be updated anymore, please use ZwEntityGetByPoint()
    @see ZwEntityGetByPoint

    @param [in] EntType type of entity to search for
    @param [in] RefPnt reference point
    @param [out] idEntity entity id (0 if undefined)
    @param [out] Pnt point on entity (or NULL to ignore)
    @param [out] Dist distance (mm) from RefPnt (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxEntFind(evxEntFind EntType, svxPoint *RefPnt, int *idEntity, svxPoint *Pnt, double *Dist);

    /**
    @ingroup zwapi_general_ent

    Finds the closest entity of the type specified in "Data" to a
    reference point specified in "Data" using filtering parameters
    specified in "Data".

    @deprecated This API will not be updated anymore, please use ZwEntityGetByPoint()
    @see ZwEntityGetByPoint

    @param [in,out] Data entity search data (input and output)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxEntFind2(svxEntFind *Data);


    //====================================================================================================================
    /** @name Entity Type */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Outputs an ascii text string describing the entity class
    identified by "ClassNumber".   
    The string is stored in the memory referenced by "ClassName", which is assumed
    to be sufficient (min = 64 bytes).

    @deprecated This API will not be updated anymore, please use ZwEntityTypeNameGet()
    @see ZwEntityTypeNameGet

    @param [in] ClassNumber entity class number
    @param [out] ClassName class name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxEntClassName(int ClassNumber, char *ClassName);

    /**
    @ingroup zwapi_general_ent

    Returns the class number of the specified entity in
    the active object.

    @deprecated This API will not be updated anymore, please use ZwEntityTypeNumberGet()
    @see ZwEntityTypeNumberGet

    @param [in] idEntity entity id

    @retval return
    -        "evxEntType" defines a subset of the possible entity class numbers returned by this function
    -        -1 if the entity cannot be located or error occurs
    @warning
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C int cvxEntClassNum(int idEntity);

    /**
    @ingroup zwapi_general_ent

    Returns the class number of the specified entity in
    the active object.

    @deprecated This API will not be updated anymore, please use ZwEntityTypeNumberGet()
    @see ZwEntityTypeNumberGet

    @param [in] entPath entity path

    @retval return
    -        "evxEntType" defines a subset of the possible entity class numbers returned by this function
    -        -1 if the entity cannot be located or error occurs
    @warning
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C int cvxEntClassNumByPath(svxEntPath *entPath);

    /**
    @ingroup zwapi_general_ent

    Determine whether an entity is curve(includes edges and parting lines).

    @deprecated This API will not be updated anymore, please use ZwEntityCurveCheck()
    @see ZwEntityCurveCheck

    @param [in] idEntity entity id (in active file)

    @retval succeeds
    -        1 - the specified entity is curvilinear
    -        0 - the specified entity is not curvilinear or error occurs
    @warning
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C int cvxEntIsCurve(int idEntity);

    /**
    @ingroup zwapi_general_ent

    Determine whether an entity is electrode.

    @deprecated This API will not be updated anymore, please use ZwEntityElectrodeCheck()
    @see ZwEntityElectrodeCheck

    @param [in] idEntity entity id (in active file)

    @retval return
    -        1 - if the specified entity is electrode
    -        0 - if the specified entity is not electrode or error occurs
    @warning
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C int cvxEntIsElectrode(int idEntity);


    //====================================================================================================================
    /** @name Entity Query */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Gets the coordinates of the first "critical" point for
    the specified entity.  
    For a point entity, it is the entity's coordinates.  
    For a line, edge or interpolated curve, it is the start point.  
    For a circle or arc, it is the center point.  
    For a control-point-defined curve, it is the first control point.  
    For a shape, it is the center of the shape's bounding box.  
    For a datum plane, it is the origin. 
    For a dimension, it is the first point of display data.  
    For a symbol, it is the insertion point.

    @deprecated This API will not be updated anymore, please use ZwEntityCriticalPointInfoGet()
    @see ZwEntityCriticalPointInfoGet

    @param [in] idEntity entity id (in active file)
    @param [out] Pnt point coordinates

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntPnt(int idEntity, svxPoint *Pnt);

    /**
    @ingroup zwapi_general_ent

    Outputs the end points of the specified curve entity.

    @param [in] idEntity entity id (in active file)
    @param [out] Start start point
    @param [out] End end point

    @deprecated This API will not be updated anymore, please use ZwCurveEndPointGet()
    @see ZwCurveEndPointGet

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C evxErrors cvxEntEndPnt(int idEntity, svxPoint *Start, svxPoint *End);

    /**
    @ingroup zwapi_general_ent

    Searches sketches within the active part for the specified entity (idEntity).  
    If the entity is found within a sketch, the id of the sketch is output.  
    If the entity is not found inside a sketch, "idSketch" is output as zero.

    @deprecated This API will not be updated anymore, please use ZwEntityParentSketchGet()
    @see ZwEntityParentSketchGet

    @param [in] idEntity entity id
    @param [out] idSketch id of entity's parent sketch (0 if undefined)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C void cvxEntSketch(int idEntity, int *idSketch);

    /**
    @ingroup zwapi_general_ent

    Outputs the id of the parent feature of the specified entity
    in the active part.

    @deprecated This API will not be updated anymore, please use ZwEntityParentGet()
    @see ZwEntityParentGet

    @param [in] idEntity entity id
    @param [out] idFeature parent feature id (0 if undefined)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntParent(int idEntity, int *idFeature);

    /**
    @ingroup zwapi_general_ent

    If "idRefEnt" is a valid parametric reference entity (i.e. reference
    geometry) in the active file, this function outputs the database id
    of the entity (i.e. geometry) that it defines.

    "idEnt" is output as zero if it is undefined for "idRefEnt".

    @deprecated This API will not be updated anymore, please use ZwEntityReferenceGet()
    @see ZwEntityReferenceGet

    @param [in] idRefEnt parametric reference entity id
    @param [out] idEnt id of entity defined by reference entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxEntRefEnt(int idRefEnt, int *idEnt);

    /**
    @ingroup zwapi_general_ent

    Outputs the id of the assembly component associated with the
    specified entity in a 2D drawing view layout from a 3D assembly.

    Assumes that "idEntity" resides in the active target file.

    Outputs "idComp = 0" if no assembly component is found.

    Outputs the names of the component's parent file and object (i.e. part)
    if non-NULL pointers are input to the "char *" variables for "File" and
    "Parent".

    @deprecated This API will not be updated anymore, please use ZwDrawingEntityComponentGet()
    @see ZwDrawingEntityComponentGet

    @param [in] idEntity entity id
    @param [out] idComp component id
    @param [out] File if not NULL, output name of component's parent file
    @param [in] nFileBytes string size of file name
    @param [out] Parent if not NULL, output name of component's parent object
    @param [in] nParentBytes string size of parent object name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOR_OBJ_ACT_FAIL
    -        ZW_API_OBJ_DATA_GET_ERROR
    -        ZW_API_ENT_PATH_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxEntComp(int idEntity, int *idComp, char *File, int nFileBytes, char *Parent, int nParentBytes);

    //====================================================================================================================
    /** @name Entity Edit */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Erase the specified entity in the active root object (part, sketch, 3d sketch or drawing sheet).

    @deprecated This API will not be updated anymore, please use ZwEntityErase()
    @see ZwEntityErase

    @param [in] Ent path to entity to erase

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
    ZW_API_C evxErrors cvxEntErase(svxEntPath *Ent);

    //====================================================================================================================
    /** @name Entity Pick Path Operation */
    //====================================================================================================================
    /**
    @ingroup zwapi_general_ent

    Activates the last target object in the specified path (NewPath) and
    outputs the path of the active target object (OldPath).   
    If "OldPath" is input as a NULL point, the active target path is not output.  
    After activating a new target object with this function, you can pass "OldPath"
    back into this function as "NewPath" in order to re-activate the
    original target object.

    If "UpdateGUI" is non-zero, this function updates the GUI menus to
    reflect a change in the target object.   
    Otherwise, the menus of the original target object remain active.

    The id of the entity referenced by "NewPath" is output via "idEntity".  
    This id can be used to query the entity once its parent object is
    activated by this function.

    @deprecated This API will not be updated anymore, please use ZwEntityActivate() or ZwComponentActivate()

    @param [in] NewPath path into new target object
    @param [in] UpdateGUI 1 to update GUI, else 0
    @param [out] idEntity entity id(input NULL to ignore)
    @param [out] OldPath path of original target(input NULL to ignore)

    @retval return
    -        1 - target object was modified
    -        0 - target object was not modified or error occurs
    @warning
    -        ZW_API_ENT_PATH_ERROR
    */
    ZW_API_C int cvxEntActivate(svxEntPath *NewPath, int UpdateGUI, int *idEntity, svxEntPath *OldPath);
    
/*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_GENERAL_ENT_H */
