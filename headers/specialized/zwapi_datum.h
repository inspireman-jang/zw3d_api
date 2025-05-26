/**
@file zwapi_datum.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Datum API
*/

#pragma once
#ifndef ZW_API_DATUM_H
#define ZW_API_DATUM_H

#include "zwapi_datum_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Datum Axis */
    //====================================================================================================================
    /**
    @ingroup ZwDatumAxis

    Create a datum axis object by two certain points, the first point will be set as origin, and 
    compute the vector from 'startPoint' to 'endPoint' that as the direction of the axis, then set
    the length between the points.

    @note
    The memory referenced by "axis" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleFree(&axis)).

    @param [in] startPoint origin point of axis
    @param [in] endPoint point that provides a direction with startPoint
    @param [out] axis axis handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisCreateByTwoPoints(szwPoint startPoint, szwPoint endPoint, szwEntityHandle *axis);

    /**
    @ingroup ZwDatumAxis

    Create a datum axis object by an origin and certain direction.

    @note
    The memory referenced by "axis" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleFree(&axis)).

    @param [in] origin origin point of axis
    @param [in] direction direction of axis
    @param [out] axis axis handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisCreateByPointAndDirection(szwPoint origin, szwVector direction, szwEntityHandle *axis);

    /**
    @ingroup ZwDatumAxis

    Create a datum axis object by two intersected faces or datum planes.

    @note
    The memory referenced by "axis" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleFree(&axis)).

    @param [in] face1 first face/datum plane
    @param [in] face2 second face/datum plane
    @param [in] flip flip the axis direction or not, 0-keep default, 1-flip
    @param [out] axis axis handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisCreateByIntersectedFaces(szwEntityHandle face1, szwEntityHandle face2, int flip, szwEntityHandle *axis);

    /**
    @ingroup ZwDatumAxis

    Create a datum axis object by a curve or edge.

    @note
    The memory referenced by "axis" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleFree(&axis)).

    @param [in] curve curve or edge
    @param [in] percents a certain percent number of the curve, valid range is 0.0-100.0
    @param [in] type direction type
    @param [in] flip flip the axis direction or not, 0-keep default, 1-flip
    @param [out] axis axis handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisCreateByCurve(szwEntityHandle curve, double percents, ezwDatumAxisDirectionType type, int flip, szwEntityHandle *axis);

    /**
    @ingroup ZwDatumAxis

    Create a datum axis object by a cylinder or cone face or arc curve.

    @note
    The memory referenced by "axis" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleFree(&axis)).

    @param [in] geometry a cylinder or cone face or arc curve
    @param [in] flip flip the direction of the axis, 0-keep default, 1-flip
    @param [out] axis axis handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisCreateByCenter(szwEntityHandle geometry, int flip, szwEntityHandle *axis);

    /**
    @ingroup ZwDatumAxis

    Get the length of specified datum axis.

    @param [in] axis datum axis handle
    @param [out] length length of axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisLengthGet(szwEntityHandle axis, double *length);

    /**
    @ingroup ZwDatumAxis

    Set the length of specified datum axis.

    @note
    It's not allowed to set the length of an axis which created by two points. This function
    will return ZW_API_INVALID_INPUT for this condition.

    @param [in] axis datum axis handle
    @param [in] length length of axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisLengthSet(szwEntityHandle axis, double length);

    /**
    @ingroup ZwDatumAxis

    Get all datum axis list in active file.

    @note
    The calling procedure MUST deallocate the output list with ZwEntityHandleListFree().

    @param [out] count count of axis
    @param [out] axisList axis list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisListGet(int *count, szwEntityHandle **axisList);

    /**
    @ingroup ZwDatumAxis

    Retrieve the origin point and direction of the datum axis.

    @param [in] axis datum axis handle
    @param [out] point origin point
    @param [out] direction direction of axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwDatumAxisDirectionGet(szwEntityHandle axis, szwPoint *point, szwPoint *direction);

    //====================================================================================================================
    /** @name Datum Plane */
    //====================================================================================================================

    /**
    @ingroup ZwDatumPlane

    Create a datum plane object by a face.

    For the input parameter 'origin', this function will calculate the projection point on the plane, then use it as the origin of
    the new plane.

    @note
    The memory referenced by "plane" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleFree(&plane)).

    @param [in] originPlane face that references
    @param [in] origin origin point of new plane
    @param [in] offset offset distance
    @param [out] plane plane handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumPlaneCreateByOffsetPlane(szwEntityHandle originPlane, szwPoint origin, double offset, szwEntityHandle *plane);

    /**
    @ingroup ZwDatumPlane

    Create a datum plane object by three points.

    @note
    The memory referenced by "plane" is allocated by this function.
    The caller is responsible to free the plane by using ZwEntityHandleFree().

    @param [in] origin origin point of new datum plane
    @param [in] xPoint point to x axis
    @param [in] yPoint point to direction of y
    @param [in] flip flip the direction of y axis, 0-keep default, 1-flip
    @param [out] plane plane handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumPlaneCreateByThreePoints(szwPoint origin, szwPoint xPoint, szwPoint yPoint, int flip, szwEntityHandle *plane);

    /**
    @ingroup ZwDatumPlane

    Create a datum plane object by an angel to a face or plane.

    @note
    The memory referenced by "plane" is allocated by this function.
    The caller is responsible to free the plane by using ZwEntityHandleFree().

    @param [in] face face or datum plane
    @param [in] axis axis to rotate
    @param [in] origin origin point of new plane
    @param [in] angel rotate angel
    @param [out] plane plane handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumPlaneCreateByAngelToFace(szwEntityHandle face, szwEntityHandle axis, szwPoint origin, double angel, szwEntityHandle *plane);

    /**
    @ingroup ZwDatumPlane

    Create a datum plane object by a curve or edge.

    @note
    The memory referenced by "plane" is allocated by this function.
    The caller is responsible to free the plane by using ZwEntityHandleFree().

    @param [in] curve curve or edge
    @param [in] percents a certain percent number of the curve, valid range is 0.0-100.0
    @param [in] type direction type
    @param [out] plane plane handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumPlaneCreateByCurve(szwEntityHandle curve, double percents, ezwDatumPlaneDirectionType type, szwEntityHandle *plane);

    /**
    @ingroup ZwDatumPlane

    Create a datum plane object by an original point, X axis, Y axis and Z axis.  

    @note
    The memory referenced by "plane" is allocated by this function.  
    The caller is responsible to free the plane by using ZwEntityHandleFree().  
    It requires that the input original point, X axis, Y axis and Z axis can make an orthogonal matrix, 
    so that the input xAxis should be orthogonal with yAxis, the zAxis should be orthogonal with xAxis and yAxis together, 
    this function will return ZW_API_INVALID_INPUT if not.  

    @param [in] position original point of the plane
    @param [in] xAxis X axis direction of the plane
    @param [in] yAxis Y axis direction of the plane
    @param [in] zAxis Z axis direction of the plane
    @param [out] plane plane handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumPlaneCreateByDynamic(szwPoint position, szwVector xAxis, szwVector yAxis, szwVector zAxis, szwEntityHandle *plane);

    /**
    @ingroup ZwDatumPlane

    Create a datum plane object by the specified transform matrix.  
    The matrix will be parsed to an original point, X axis, Y axis and Z axis, thus this function is 
    very similar with ZwDatumPlaneCreateByDynamic().  

    @see ZwDatumPlaneCreateByDynamic
    @see ZwMatrixOrthogonalCheck

    @note
    The memory referenced by "plane" is allocated by this function.  
    The caller is responsible to free the plane by using ZwEntityHandleFree().  
    It requires the input matrix is an orthogonal matrix, this function will return ZW_API_INVALID_INPUT if not.  

    @param [in] planeMatrix transform matrix to create a datum plane
    @param [out] plane plane handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwDatumPlaneCreateByMatrix(szwMatrix planeMatrix, szwEntityHandle *plane);

    //====================================================================================================================
    /** @name Datum CSYS(coordinate system) */
    //====================================================================================================================
    /**
    @ingroup ZwDatumCSYS

    Initializes the parameters of the ZwCSYSCreateByThreePoints().
    threePoints.origin is the origin.
    threePoints.xPoint is the point on the X-axis.
    threePoints.yPoint is the Y-axis projection point.

    @see ZwCSYSCreateByThreePoints

    @param [out] threePoints three points to create the datum CSYS object

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCSYSCreateByThreePointsInit(szwDatumCSYSMethodThreePoints *threePoints);

    /**
    @ingroup ZwDatumCSYS

    Creates a datum CSYS object by three points.

    @see ZwCSYSCreateByThreePointsInit

    @note
    Interface ZwCSYSCreateByThreePointsInit() can initialize variables of this function.
    The caller is responsible to free the csys by using ZwEntityHandleFree().

    @param [in] threePoints three points to create the datum CSYS object
    @param [out] csys csys handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwCSYSCreateByThreePoints(szwDatumCSYSMethodThreePoints threePoints, szwEntityHandle *csys);

    /**
    @ingroup ZwDatumCSYS

    Initializes the parameters of the ZwCSYSCreateByPointAndDirection().
    pointDirection.origin is the origin.
    pointDirection.directionX is the direction of X-axis.
    pointDirection.directionY is the direction of Y-axis.

    @see ZwCSYSCreateByPointAndDirection

    @param [out] pointDirection  origin point, x and y axis direction to create the datum CSYS object

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCSYSCreateByPointAndDirectionInit(szwDatumCSYSMethodPointAndDirection *pointDirection);

    /**
    @ingroup ZwDatumCSYS

    Creates a datum CSYS object by origin point, x and y axis direction.

    @see ZwCSYSCreateByPointAndDirectionInit

    @note
    Interface ZwCSYSCreateByPointAndDirectionInit() can initialize variables of this function.
    The caller is responsible to free the csys by using ZwEntityHandleFree().

    @param [in] pointDirection  origin point, x and y axis direction to create the datum CSYS object
    @param [out] csys csys handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwCSYSCreateByPointAndDirection(szwDatumCSYSMethodPointAndDirection pointDirection, szwEntityHandle *csys);

    /**
    @ingroup ZwDatumCSYS

    Initializes the parameters of the ZwCSYSCreateByPlaneAndDirection().
    planeDirection.plane is the face or datum plane.
    planeDirection.point is the point to locate the origin of the plane.
    planeDirection.directionX is the direction of x axis.
    planeDirection.flip is whether to flip the direction of z axis.

    @see ZwCSYSCreateByPlaneAndDirection

    @note
    The caller is responsible to assign a value to variable "planeDirection.plane" before calling ZwCSYSCreateByPlaneAndDirection().

    @param [out] planeDirection  plane and direction to create the datum CSYS object

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCSYSCreateByPlaneAndDirectionInit(szwDatumCSYSMethodPlaneAndDirection *planeDirection);

    /**
    @ingroup ZwDatumCSYS

    Creates a datum CSYS object by a face or datum plane and x direction.
    It use the normal vector of input plane as the z direction of new CSYS. 

    For the input parameter 'planeDirection.point', this function will calculate the projection point of the plane as the origin.
    For the input parameter 'planeDirection.directionX', this function will calculate the projection vector of the plane as the direction of x axis.

    @see ZwCSYSCreateByPlaneAndDirectionInit

    @note
    Interface ZwCSYSCreateByPointAndDirectionInit() can initialize variables of this function.
    The caller is responsible to free the csys by using ZwEntityHandleFree().

    @param [in] planeDirection  plane and direction to create the datum CSYS object
    @param [out] csys csys handle (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwCSYSCreateByPlaneAndDirection(szwDatumCSYSMethodPlaneAndDirection planeDirection, szwEntityHandle *csys);

    /**
    @ingroup ZwDatumCSYS

    Retrieve the axis of the specified datum CSYS by input type.

    @param [in] csys coordinate system
    @param [in] type axis type
    @param [out] axis datum axis

    @note
    The calling procedure MUST deallocate the axis with ZwEntityHandleFree().

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwCSYSAxisGet(szwEntityHandle csys, ezwDatumAxisType type, szwEntityHandle *axis);

    /**
    @ingroup ZwDatumCSYS

    Retrieve the datum plane of the specified datum CSYS by input type.

    @param [in] csys coordinate system
    @param [in] type plane type
    @param [out] plane datum plane

    @note
    The calling procedure MUST deallocate the plane with ZwEntityHandleFree().

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwCSYSPlaneGet(szwEntityHandle csys, ezwDatumPlaneType type, szwEntityHandle *plane);

    /**
    @ingroup zwapi_datum

    Retrieve the default CSYS in active file.

    @param [out] csys datum CSYS

    @note
    The calling procedure MUST deallocate the csys with ZwEntityHandleFree().

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwDefaultCSYSGet(szwEntityHandle *csys);

    /**
    @ingroup zwapi_datum

    Retrieve all CSYS in active file.

    @param [out] count count of datum CSYS list
    @param [out] csysList datum CSYS list

    @note
    The calling procedure MUST deallocate the csys with ZwEntityHandleListFree().

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwDatumCSYSListGet(int *count, szwEntityHandle **csysList);

    //====================================================================================================================
    /** @name LCS(local coordinate system) */
    //====================================================================================================================
    /**
    @ingroup ZwLCS

    Set the input datum plane or datum CSYS as the active LCS(local coordinate system).

    @param [in] handle datum plane or datum CSYS

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    -        ZW_API_CMMD_INIT_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INPUT_ERROR
    -        ZW_API_CMMD_EXEC_ERROR
    */
    ZW_API_C ezwErrors ZwActiveLCSSet(szwEntityHandle handle);

    /**
    @ingroup ZwLCS

    Get the entity handle of active LCS(local coordinate system). 
    If the LCS is equal to the Default CSYS, handle will be set as the handle of 
    Default CSYS.

    @code
    szwEntityHandle handle;
    ZwActiveLCSGet(&handle);
    ...
    ZwEntityHandleFree(&handle);
    @endcode

    @note
    The memory referenced by "handle" is allocated by this function.
    The calling procedure is responsible to free it (ZwEntityHandleFree(&handle)).

    @param [out] handle handle of the active local coordinate system

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwActiveLCSGet(szwEntityHandle *handle);

    /**
    @ingroup ZwLCS

    Retrieve the transformation matrix of the active LCS(local coordinate system).

    @param [out] matrix transformation matrix

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwLCSMatrixGet(szwMatrix *matrix);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !ZW_API_DATUM_H */
