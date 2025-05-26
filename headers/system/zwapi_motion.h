/**
@file zwapi_motion.h
@copyright (C) Copyright 2024, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Motion API
*/

#pragma once
#ifndef ZW_API_MOTION_H /* this ifndef surrounds entire header */
#define ZW_API_MOTION_H

#include "zwapi_motion_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Motion General */
    //====================================================================================================================

    /*
    DESCRIPTION:
    Outputs a list of entity id of the specified type in the active motion target.
    If there are no entities, "*countEntity" is output as zero and "*entityList" as NULL.
    
    NOTE:
    The caller is responsible to free the entityList by using cvxMemFree.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwMotEntityListGet(ezwMotType eType, int *countEntity, int **entityList);
    
    /*
    DESCRIPTION:
    Get the active status of the motion entity.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwMotEntityActiveGet(int idEntity, int *iActive);

    /*
    DESCRIPTION:
    Activate/deactivate the motion entity.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_OBJ_DATA_SET_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwMotEntityActiveSet(int idEntity, int iActivate);

    /*
    DESCRIPTION:
    Get the name of the motion entity.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_MEMORY_ERROR
            ZW_API_INVALID_ENT_PATH
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwMotEntityNameGet(int idEntity, int nBytes, char *name);

    /*
    DESCRIPTION:
    Assigns the specified name to the specified entity.
    It is assumed the entity resides in the active file.
    It is assumed the entity has a "name" field.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_NAME
            ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwMotEntityNameSet(int idEntity, const char *name);

    /*
    DESCRIPTION:
    Delete the specified motion entity.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_OBJ_DATA_SET_ERROR
            ZW_API_INPUT_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwMotEntityDelete(int idEntity);

    //====================================================================================================================
    /** @name Motion Body */
    //====================================================================================================================

    /*
    DESCRIPTION:
    Get the specified motion body data.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_CMMD_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwMotBodyGet(int idEntity, szwMotBody *zEntity);

    /*
    DESCRIPTION:
    Set the specified motion body data.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_INPUT
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_CMMD_INIT_ERROR
            ZW_API_CMMD_DATA_ERROR
            ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwMotBodySet(int idEntity, szwMotBody zEntity);

    /*
    DESCRIPTION:
    Get the specified motion body transform matrix.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwMotBodyMatrixGet(int idEntity, svxMatrix *zMatrix);

    /*
    DESCRIPTION:
    Set the specified motion body transform matrix.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwMotBodyMatrixSet(int idEntity, svxMatrix zMatrix);

    //====================================================================================================================
    /** @name Motion Joint */
    //====================================================================================================================

    /*
    DESCRIPTION:
    Get the joint type by sub class.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_INVALID_INPUT
            ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwMotJointTypeGetBySubClass(ezwMotJointSubClass eSubClass, ezwMotJointType *eType);
    
    /*
    DESCRIPTION:
    Get the specified motion joint data.
    
    NOTE:
    The caller is responsible to free the zEntity by using ZwMotJointFree.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMotJointGet(int idEntity, szwMotJoint *zEntity);
    
    /*
    DESCRIPTION:
    Free the joint.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMotJointFree(szwMotJoint *zEntity);

    //====================================================================================================================
    /** @name Motion Driver */
    //====================================================================================================================

    /*
    DESCRIPTION:
    Get the specified motion driver data.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMotDriverGet(int idEntity, szwMotDriver *zEntity);
    
    /*
    DESCRIPTION:
    Set the specified motion driver data.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_INPUT
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_INPUT_ERROR
            ZW_API_CMMD_DATA_ERROR
            ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwMotDriverSet(int idEntity, szwMotDriver zEntity);
    
    /*
    DESCRIPTION:
    Check whether the joint can be used to created a driver with the driver type.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwMotDriverValidJointCheck(int idJoint, const ezwMotDriverType *eDriverType);
    
    /*
    DESCRIPTION:
    Create a new driver.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_INPUT
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_INPUT_ERROR
            ZW_API_CMMD_INIT_ERROR
            ZW_API_CMMD_DATA_ERROR
            ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwMotDriverCreate(szwMotDriver zEntity, int *idEntity);

    //====================================================================================================================
    /** @name Motion Solution */
    //====================================================================================================================

    /*
    DESCRIPTION:
    Get the active solution, if no active solution, idSolution will be -1.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwMotActiveSolutionGet(int *idSolution);
    
    /*
    DESCRIPTION:
    Get the specified motion solution degree of freedom.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionDegreeOfFreedomGet(int idEntity, int *iDegreeOfFreedom);
    
    /*
    DESCRIPTION:
    Get the specified motion solution data.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_INVALID_OUTPUT
            ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionGet(int idEntity, szwMotSolution *zEntity);
    
    /*
    DESCRIPTION:
    Get the specified motion solution data.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_INPUT_ERROR
            ZW_API_CMMD_INIT_ERROR
            ZW_API_CMMD_DATA_ERROR
            ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionSet(int idEntity, szwMotSolution zEntity);
    
    /*
    DESCRIPTION:
    Outputs a list of active entity id of the specified type attached to the solution.
    If there are no entities, "*countEntity" is output as zero and "*entityList" as NULL.
    
    NOTE:
    The caller is responsible to free the entityList by using cvxMemFree.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionActiveEntityListGet(int idSolution, ezwMotType eType, int *countEntity,
                                                        int **entityList);
    
    /*
    DESCRIPTION:
    Outputs a list of driver time list of the specified solution.
    If there are no entities, "*countEntity" is output as zero and "*entityList" as NULL.
    
    NOTE:
    The caller is responsible to free the entityList by using cvxMemFree.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionDriverTimeListGet(int idSolution, int *countEntity, szwMotDriverTime **entityList);
    
    /*
    DESCRIPTION:
    Set the driver time list of the specified solution. Only the active driver
    will be added to the solution, see ZwMotSolutionActiveEntityListGet.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_INPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionDriverTimeListSet(int idSolution, int countEntity,
                                                      const szwMotDriverTime *entityList);

    //====================================================================================================================
    /** @name Motion Solve */
    //====================================================================================================================

    /*
    DESCRIPTION:
    Solve the active solution.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_INPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionCalculate(ezwMotSolutionSolveStatus *eStatus);
    
    /*
    DESCRIPTION:
    Outputs a list of every frame solve result of the specified solution.
    If there are no result, "*countFrame" is output as zero and "*resultList" as NULL.
    
    NOTE:
    The caller is responsible to free the resultList by using ZwMotSolutionSolveResultFree.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionSolveResultGet(int idSolution, int *countFrame, szwMotFrameResult **resultList);
    
    /*
    DESCRIPTION:
    Free the result frame list.
    
    Returns:
    succeeds:
            ZW_API_NO_ERROR
    fails:
            ZW_API_GENERAL_ERROR
            ZW_API_ROOT_OBJ_ACT_FAIL
            ZW_API_WRONG_ROOT_ENV
            ZW_API_INVALID_OUTPUT
            ZW_API_INPUT_TYPE_ERROR
            ZW_API_OBJ_DATA_GET_ERROR
            ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwMotSolutionSolveResultFree(int count, szwMotFrameResult **resultList);

    /*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MOTION_H */