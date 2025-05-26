/**
@file zwapi_feature_shape.h
@copyright (C) Copyright 2023, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Path API
*/

#pragma once
#ifndef ZW_API_FEATURE_SHAPE_H /* this ifndef surrounds entire header */
#define ZW_API_FEATURE_SHAPE_H

#include "zwapi_feature_shape_data.h"
#include "zwapi_feature_general.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name Basic Shape */
    //====================================================================================================================
    
    /**
    @ingroup ZwFeatureShape

    Initializes the parameters of the ZwFeatureExtrudeCreate().

    @see ZwFeatureExtrudeCreate

    @param [out] extrude extruded shape data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureExtrudeInit(szwExtrudeData *extrude);

    /**
    @ingroup ZwFeatureShape

    Creates an extruded shape and adds it to the active part using the
    specified combination method.  If "shapeHandle" is not NULL and
    "extrude->combine = ZW_BOOL_NONE", the handle data of the shape created
    by this function is output via "shapeHandle".  
    If multiple shapes could be created, use ZwEntityCreateListGet() to get their handle's.  

    If user want to use optional extrusion direction, it should set 1 to "extrude->isUseExtrusionDirection".  

    Function Guide: Shape->Basic Shape->Extrude

    @see ZwFeatureExtrudeInit

    @note
    Please use ZwEntityCreateListGet and set the entity type to ZW_ENTITY_SHAPE to get new shapes.  
    Interface ZwFeatureExtrudeInit() can initialize variables of this function.  
    ZwFeatureExtrudeCreate doesn't support multi-base shape since R2024 when boolean type 
    is ZW_BOOL_ADD, and it will set the boolean type to ZW_BOOL_NONE first, and 
    then add a 'Add shape' feature to do the boolean add operation.
    The caller is responsible to free the shapeHandle by using ZwEntityHandleFree().

    @param [in] extrude extrusion input data
    @param [out] shapeHandle handle data of new shape (NULL to ignore)

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
    ZW_API_C ezwErrors ZwFeatureExtrudeCreate(szwExtrudeData extrude, szwEntityHandle *shapeHandle);

    /**
    @ingroup ZwFeatureShape

    Initializes the parameters of the ZwFeatureBoxCreateByCenter().

    If user want to use optional extrusion direction, it should set 1 to "extrude->isUseExtrusionDirection".  

    Function Guide: Shape->Basic Shape->Extrude

    @see ZwFeatureExtrudeInit

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @param [out] data box data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureCenterBoxDataInit(szwCenterBoxData *data);

    /**
    @ingroup ZwFeatureShape

    Creates a box shape and adds it to the active part by using the
    specified combination method.  If "handle" is not NULL and
    "data.combine = ZW_BOOL_BASE", the handleList of the shape created
    by this function is output via "handle".  
    Function Guide: Shape->Basic Shape->Block

    @see ZwFeatureCenterBoxDataInit

    @note
    Interface ZwFeatureCenterBoxDataInit() can initialize variables of this function.
    This command doesn't support multi-base shape since R2024 when boolean type
    is ZW_BOOL_ADD, and it will set the boolean type to ZW_BOOL_BASE first, and
    then add a 'Add shape' feature to do the boolean add operation.
    The caller is responsible to free the handleList by using ZwEntityHandleListFree().

    @param [in] data box definition
    @param [out] count count of new shapes
    @param [out] handleList handles of new shapes

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

    @code
    szwCenterBoxData data{};
    ZwFeatureCenterBoxDataInit(&data);
    ...
    szwEntityHandle *handles=NULL;
    int count;
    ZwFeatureBoxCreateByCenter(data,count,&handles);
    ...
    ZwEntityHandleListFree(count,&handles);
    @endcode
    */
    ZW_API_C ezwErrors ZwFeatureBoxCreateByCenter(szwCenterBoxData data, int *count, szwEntityHandle **handleList);

    /**
    @ingroup ZwFeatureShape

    Initializes the parameters of the ZwFeatureLoftCreate().  

    @note
    Do not assign a value to variable "data" before calling this function.  
    The ZwMemoryZero() is called inside the interface to empty everything.  

    @see ZwFeatureLoftCreate

    @param [out] data template command loft data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureLoftDataInit(szwLoftData *data);

    /**
    @ingroup ZwFeatureShape

    Creates a loft feature.  
    Function Guide: Shape->Basic Shape->Loft

    @note
    Interface ZwFeatureLoftDataInit() can initialize variables of this function.
    The caller is responsible to free the handleList by using ZwEntityHandleListFree().
    Remember to free the memory allocated in data.
    ZwFeatureLoftCreate doesn't support multi-base shape since R2024 when boolean type
    is ZW_BOOL_ADD, and it will set the boolean type to ZW_BOOL_BASE first, and
    then add a 'Add shape' feature to do the boolean add operation.

    @see ZwFeatureLoftDataInit

    @param [in] data loft input data
    @param [out] count count of new shapes (NULL to ignore)
    @param [out] handleList handles of new shapes (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureLoftCreate(szwLoftData data, int *count, szwEntityHandle **handleList);

    /**
    @ingroup ZwFeatureShape

    Initializes the parameters of ZwFeatureSweptRodCreate().

    @note
    Do not assign a value to variable "data" before calling this function.  
    The ZwMemoryZero() is called inside the interface to empty everything.  

    @see ZwFeatureSweptRodCreate

    @param [out] data data of feature 'Swept Rod'

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureSweptRodInit(szwSweptRodData *data);

    /**
    @ingroup ZwFeatureShape

    Creates a 'Swept Rod' feature in active part/assembly file with input parameters.  

    Function Guide: Shape->Basic Shape->Swept Rod  

    @note
    Interface ZwFeatureSweptRodInit() can initialize variables of this function.  
    Remember to free the memory allocated in data.  
    The caller is responsible to free the newShapes by using ZwEntityHandleListFree().  

    @see ZwFeatureSweptRodInit

    @param [in] data data of feature 'Swept Rod'
    @param [out] count count of created shapes, NULL to ignore
    @param [out] newShapes handles of created shapes, NULL to ignore

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureSweptRodCreate(szwSweptRodData data, int *count, szwEntityHandle **newShapes);

    //====================================================================================================================
    /** @name Edit Shape */
    //====================================================================================================================

    /**
    @ingroup ZwFeatureShape

    Initializes the parameters of szwBoolData.

    @note
    Do not assign a value to variable "data" before calling this function.

    @param [out] data bool option data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureBoolDataInit(szwBoolData *data);

    /**
    @ingroup ZwFeatureShape

    Makes boolean add with base shapes and other shapes, the base shape can be more than one.
    Function Guide: Shape->Edit Shape->Add Multiple Shapes

    @note
    Interface ZwFeatureBoolDataInit() can initialize variables of this function.  
    Remember to free the memory allocated in data.  

    @see ZwFeatureBoolDataInit

    @param [in] data bool option data

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

    @code
    szwBoolData data{};
    ZwFeatureBoolDataInit(&data);
    data.baseShapes=...;
    data.baseCount=...;
    data.toolShapes=...;
    data.toolCount=...;
    ....
    ZwFeatureAddMultipleShapeCreate(data);
    //remember to free the memory in data
    @endcode
    */
    ZW_API_C ezwErrors ZwFeatureAddMultipleShapeCreate(szwBoolData data);

    /**
    @ingroup ZwFeatureShape

    Makes boolean add with a base shape and other shapes, the base shape can not be more than one.
    Function Guide: Shape->Edit Shape->Add Shape

    @note
    Interface ZwFeatureBoolDataInit() can initialize variables of this function.  
    Remember to free the memory allocated in data.  

    @see ZwFeatureBoolDataInit

    @param [in] data bool option data

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

    @code
    szwBoolData data{};
    ZwFeatureBoolDataInit(&data);
    data.baseShapes=...;
    data.baseCount=...;
    data.toolShapes=...;
    data.toolCount=...;
    ....
    ZwFeatureAddShapeCreate(data);
    //remember to free the memory in data
    @endcode
    */
    ZW_API_C ezwErrors ZwFeatureAddShapeCreate(szwBoolData data);

    /**
    @ingroup ZwFeatureShape

    Makes boolean remove with base shapes and other shapes.
    Function Guide: Shape->Edit Shape->Remove Shape

    @note
    Interface ZwFeatureBoolDataInit() can initialize variables of this function.  
    Remember to free the memory allocated in data.

    @see ZwFeatureBoolDataInit

    @param [in] data bool option data

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

    @code
    szwBoolData data{};
    ZwFeatureBoolDataInit(&data);
    data.baseShapes=...;
    data.baseCount=...;
    data.toolShapes=...;
    data.toolCount=...;
    ....
    ZwFeatureRemoveShapeCreate(data);
    //remember to free the memory in data
    @endcode
    */
    ZW_API_C ezwErrors ZwFeatureRemoveShapeCreate(szwBoolData data);

    /**
    @ingroup ZwFeatureShape

    Makes boolean intersection with base shapes and other shapes.
    Function Guide: Shape->Edit Shape->Intersect Shape

    @note
    Interface ZwFeatureBoolDataInit() can initialize variables of this function.  
    Remember to free the memory allocated in data.  

    @see ZwFeatureBoolDataInit

    @param [in] data bool option data

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

    @code
    szwBoolData data{};
    ZwFeatureBoolDataInit(&data);
    data.baseShapes=...;
    data.baseCount=...;
    data.toolShapes=...;
    data.toolCount=...;
    ....
    ZwFeatureIntersectShapeCreate(data);
    //remember to free the memory in data
    @endcode
    */
    ZW_API_C ezwErrors ZwFeatureIntersectShapeCreate(szwBoolData data);

    //====================================================================================================================
    /** @name Basic Editing */
    //====================================================================================================================

    /**
    @ingroup ZwFeatureShape
    
    Initializes the parameters of the szwSphereData.
    
    @note
    Do not assign a value to variable "data" before calling this function.  
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see  ZwFeatureSphereCreate
    
    @param [out] data sphere data
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureSphereDataInit(szwSphereData *data);

    /**
    @ingroup ZwFeatureShape
    
    Creates a sphere shape and adds it to the active part using the
    specified combination method.  If "handleList" is not NULL and
    "data.combine = ZW_BOOL_BASE", the handle of the shape created
    by this function is output via "handleList".  
    Function Guide: Shape->Basic Shape->Sphere
    
    @see ZwFeatureSphereDataInit
    
    @note
    The caller is responsible to free the handleList by using ZwEntityHandleListFree().  
    Remember to free the memory allocated in data.  
    Interface ZwFeatureSphereDataInit can initialize variables of this function.  
    This command doesn't support multi-base shape since R2024 when boolean type  
    is ZW_BOOL_ADD, and it will set the boolean type to ZW_BOOL_BASE first, and  
    then add a 'Add shape' feature to do the boolean add operation.  
    
    @param [in] data sphere definition
    @param [out] count count of new shapes (NULL to ignore)
    @param [out] handleList handles of new shapes (NULL to ignore)
    
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
    ZW_API_C ezwErrors ZwFeatureSphereCreate(szwSphereData data, int *count, szwEntityHandle **handleList);

    //====================================================================================================================
    /** @name Engineering Feature */
    //====================================================================================================================
    /**
    @ingroup ZwFeatureShape

    Initializes the parameters of the szwStockData.

    @note
    Do not assign a value to variable "data" before calling this function.
    The ZwMemoryZero() is called inside the interface to empty everything.

    @see ZwFeatureStockCreate

    @param [out] data template command stock data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwFeatureStockDataInit(szwStockData *data);

    /**
    @ingroup ZwFeatureShape

    Uses this function to create an extruded stock feature that completely
    encloses faces, shapes or blocks.
    Function Guide: Shape->Engineering Feature->Stock

    @note
    Interface ZwFeatureStockDataInit can initialize variables of this function.
    The caller is responsible to free the handle by using ZwEntityHandleFree().
    Remember to free the memory allocated in data.

    @see ZwFeatureStockDataInit

    @param [in] data stock input data
    @param [out] handle handle of stock shape (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_CMMD_INTI_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwFeatureStockCreate(szwStockData data, szwEntityHandle *handle);


   /**********************************************************************
   **  END HEADER FILE
   *********************************************************************
   */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_FEATURE_SHAPE_H */
