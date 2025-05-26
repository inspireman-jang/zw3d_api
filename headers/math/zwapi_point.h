/**
@file zwapi_point.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Point API
*/

#pragma once
#ifndef ZW_API_POINT_H /* this ifndef surrounds entire header */
#define ZW_API_POINT_H

#include "zwapi_util.h"
#include "zwapi_point_data.h"
#include "zwapi_math_data.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Point Get */
    //====================================================================================================================

    /**
    @ingroup ZwPoint

    Outputs a list of handles of point objects that belong to
    the active part.

    @note
    The caller is responsible to free the handle by using ZwEntityHandleListFree().

    @param [out] count number of points
    @param [out] pointList list of points' handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPointListGet(int *count, szwEntityHandle **pointList);

    /**
    @ingroup ZwPoint

    Displays the specified "prompt" and waits for the user to input
    a point, which is output via "point".  If the user used a
    "point-on-entity" option, the entity index is output via "handle".

    @note
    The caller is responsible to free the handle by using ZwEntityHandleFree().

    @param [in] prompt text prompt
    @param [in] option point input option
    @param [in] emptyOk 1 if <middle-click> without input is okay; else 0
    @param [out] point point input
    @param [out] handle entity handle (input NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR : error or user-escape
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwPointGetByPick(const char *prompt, ezwPointInputOption option, int emptyOk, szwPoint *point, szwEntityHandle *handle);

    /**
    @ingroup ZwPoint

    Get the mouse cursor positon in the active view, the active view handle will return via viewHandle.

    @note
    The caller is responsible to free the viewHandle by using ZwEntityHandleFree.

    @param [out] point point position
    @param [out] viewHandle the active view handle

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwCursorGet(szwPoint *point, szwEntityHandle *viewHandle);

    //====================================================================================================================
    /** @name Point Calculate */
    //====================================================================================================================
    /**
    @ingroup ZwPoint

    Translates  point" along "vector" by "distance".
    Evaluate the distance of the point moving vector multiplied by the scale.
    For example: point->X = point->X + distance * vector->X.

    @param [in,out] point point
    @param [in] vector direction vector
    @param [in] distance distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        szwPoint point=...;
        ...
        szwVector V=...;
        double distance=...;
        ZwPointTranslateByDistance(&point, V, distance);
    @endcode

    */
    ZW_API_C ezwErrors ZwPointTranslateByDistance(szwPoint *point, szwVector vector, double distance);

    /**
    @ingroup ZwPoint

    Given an array of points "pointList" defining the coordinates of a
    polygon's vertices, this function decomposes the polygon into
    triangles.  The triangles are defined by an array of vertex indices
    "vertexList", which is an int list of indices into the pointList array.

    Every three elements in the output list define one triangle,
    i.e. vertexList[0], vertexList[1] and vertexList[2] contain the pointList array
    indices of the first triangle's vertices, vertexList[3], vertexList[4] and
    vertexList[5] contain the pointList array indices of the second triangle,
    and so on.  The total number of triangle vertices is output in
    vertexCount.  The total number of triangles for the given polygon will be
    (*vertexCount)/3.

    The points in pointList are assumed to be in vertex order around the
    perimeter of the polygon.  The polygon may be concave.

    This function allocates the output array vertexList.  
    The caller is responsible for freeing VtxList using ZwMemoryFree().

    @param [in] pointCount number of points in point list
    @param [in] pointList point list of polygon vertex coordinates
    @param [out] vertexCount number of triangle vertex indices in vertex list
    @param [out] vertexList vertex list of triangle vertex indices (see description below)

    @retval succeeds
    -        ZW_API_NO_ERROR - the polygon is successfully tessellated into triangles.
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        int pointCount=...;
        szwPoint* pointList=...;
        ...

        int vtxCount = -1;
        int* vtxList = nullptr;
        ...
        ZwPointPolygonTriangulation(pointCount, pointList, &vtxCount, &vtxList);
    @endcode
    */
    ZW_API_C ezwErrors ZwPointPolygonTriangulation(int pointCount, const szwPoint *pointList, int *vertexCount, int **vertexList);

    /**
    @ingroup ZwPoint

    Returns the distance between two points.

    @param [in] point1 first point
    @param [in] point2 second point
    @param [out] distance the min distance between the to points

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT

    @code
        szwPoint point1=...;
        szwPoint point2=...;
        double distance=0.0;
        ...
        ZwPointDistanceGet(&point1, &point2, &distance);
    @endcode
    */
    ZW_API_C ezwErrors ZwPointDistanceGet(szwPoint point1, szwPoint point2, double *distance);

    /**
    @ingroup ZwPoint

    Get the minimum distance form a point to an infinite plane by point and direction.

    @param [in] planePoint point on plane
    @param [in] planeNormal normal of plane
    @param [in] point point to measure distance to
    @param [out] distance the minimum distance
    @param [out] projPoint point projected on plane (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    
    @code
        szwPoint planePoint=...;
        szwVector planeNormal=...;
        szwPoint point=...;
        double distance=0.0;
        ...
        szwPoint projPoint{};
        ...
        ZwMathPlanePointDistanceGet(planePoint, planeNormal, point, &distance, &projPoint);
    @endcode
    */
    ZW_API_C ezwErrors ZwMathPlanePointDistanceGet(szwPoint planePoint, szwVector planeNormal, szwPoint point, double *distance, szwPoint *projPoint);

    /**
    @ingroup ZwPoint

    Applies transformation matrix "inputMatrix" to "axis".

    @param [in] inputMatrix transformation matrix
    @param [in,out] axis axis to transformation

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
       szwMatrix inputMatrix=...;
       ...
       szwAxis axis=...;
       ZwAxisTransform(inputMatrix,&axis);
    @endcode
    */
    ZW_API_C ezwErrors ZwAxisTransform(szwMatrix inputMatrix, szwAxis *axis);

    /**
    @ingroup ZwPoint

    Project point onto infinite line defined by point and direction.

    @param [in] axis axis defined by a point and a direction
    @param [in] point point to project
    @param [out] projectPoint point projected on axis

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        szwAxis axis=...;
        szwPoint point=...;
        szwPoint projectPoint{};
        ...
        ZwAxisProjectionPointGet(axis, point, &projectPoint);
    @endcode
    */
    ZW_API_C ezwErrors ZwAxisProjectionPointGet(szwAxis axis, szwPoint point, szwPoint *projectPoint);

    /**
    @ingroup ZwPoint

    Gets the minimum distance from a point to an infinite line defined by point and direction.

    @param [in] axis axis defined by a point and a direction
    @param [in] point point to measure distance to
    @param [out] distance the minimum distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        szwAxis axis=...;
        szwPoint point=...;
        double distance=0.0;
        ...
        ZwAxisPointDistanceGet(axis, point, &distance);
    @endcode
    */
    ZW_API_C ezwErrors ZwAxisPointDistanceGet(szwAxis axis, szwPoint point, double *distance);

    /**
    @ingroup ZwPoint

    Get point on axis at a specified distance from origin of axis.

    @param [in] axis axis defined by a point and a direction
    @param [in] distance distance
                         > 0: along direction of axis
                         < 0: the opppsite direction of axis
    @param [out] point point on the axis at specified distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        szwAxis axis=...;
        szwPoint point=...;
        double distance=0.0;
        ...
        ZwAxisPointGetByDistance(&axis, distance, &point);
    @endcode
    */
    ZW_API_C ezwErrors ZwAxisPointGetByDistance(szwAxis axis, double distance, szwPoint *point);

    /**
    @ingroup ZwPoint

    Given "pointCount" points, this function computes the least squares plane
    fitted through these points. It then checks to see if the points are
    contained within this plane such that for any point (X,Y,Z) in the plane,
    the following equation holds true:

    Normal.x * X + Normal.y * Y + Normal.z * Z + D = 0

    @param [in] pointCount number of points in point list
    @param [in] pointList list of points
    @param [out] normal the unit length normal vector to the plane
    @param [out] D the last term in the plane equation (see description below)
    @param [out] location the location of these points
            -2 : line or point in xy-plane (points do not define a plane).
            -1 : line or point not in xy-plane (points do not define a plane).
            0 : points do not lie in a unique plane.
            1 : points lie in a unique plane (not the xy-plane).
            2 : points lie in the xy-plane.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        int pointCount=...;
        szwPoint* pointList=...;
        ...
        szwVector normal{};
        double D=0;
        int location=0;
        ...
        ZwMathPlaneGetByPoint(pointCount, pointList, &normal, &D, &location);
    @endcode
    */
    ZW_API_C ezwErrors ZwMathPlaneGetByPoint(int pointCount, const szwPoint *pointList, szwVector *normal, double *D, int *location);

    /**
    @ingroup ZwPoint

    Project point onto infinite plane by point and direction.

    @param [in] planePoint point on plane
    @param [in] planeNormal normal of plane
    @param [in] point point to project
    @param [in] projectDirection projection direction (NULL to use normal of plane)
    @param [out] projectPoint point projected on plane
    @param [out] isParallelOrOnPlane whether the point is on the plane
            0 - The projection direction is not parallel.
            1 - The projection direction is parallel to the plane normal and point is on the plane.
            2 - The projection direction is parallel to the plane normal and point is not in the plane.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT

    @code
        szwPoint planePoint{};
        ...
        szwVector planeNormal{};
        ...
        szwPoint point1{};
        ...
        szwPoint projPoint{};
        int isParallelOrOnPlane = -1;

        ZwPlaneProjectPointGetByDirection(planePoint, planeNormal, point1, NULL, &projPoint, &isParallelOrOnPlane);
    @endcode
    */
    ZW_API_C ezwErrors ZwPlaneProjectPointGetByDirection(szwPoint planePoint, szwVector planeNormal, szwPoint point, const szwVector *projectDirection, szwPoint *projectPoint, int *isParallelOrOnPlane);

    /**
    @ingroup ZwPoint

    Calculates a point on the specified face at the midpoint of
    the face's bounding box in UV parameter space.  The 3D point
    coordinates are output in the space of the active part, even
    if the face belongs to a child component of the part.
    The corresponding U,V parameters are output as param[0] and param[1].

    @param [in] faceHandle handle data of face in active part or specified component
    @param [out] parameter[2] u,v parameter values
    @param [out] point point on face (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR

    @code
        szwEntityHandle faceHandle=...;
        ...
        double parameter[2]=...;
        ...
        szwPoint point{};
        ZwFacePointGetByBoundingBoxCenter(faceHandle, parameter, &point);
    @endcode
    */
    ZW_API_C ezwErrors ZwFacePointGetByBoundingBoxCenter(szwEntityHandle faceHandle, double parameter[2], szwPoint *point);

    /**
    @ingroup ZwPoint

    Determine if a given point lies inside, outside or on the boundary of a given curve,
    edge, face or shape.

    @param [in] entityHandle entity handle (only curve, edge, face and shape are supported)
    @param [in] point point coordinates of the inquiry
    @param [out] pointLocation returned status of the point on the entity

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR

    @code
        szwEntityHandle shapeHandle=...;
        ...
        szwPoint point{};
        ...
        ezwPointLocation pointLoaction = ezwPointLocation::ZW_POINT_NULL;
        ZwPointOnEntityCheck(shapeHandle, point, &pointLoaction);
    @endcode
    */
    ZW_API_C ezwErrors ZwPointOnEntityCheck(szwEntityHandle entityHandle, szwPoint point, ezwPointLocation *pointLocation);

    /**
    @ingroup ZwPoint

    Get point on plane that offset the origin by a specified distance in the x-direction and y-direction.

    @param [in] planeOrigin origin of plane
    @param [in] xAxis x-direction of plane
    @param [in] yAxis y-direction of plane
    @param [in] xDistance distance of x-direction (> 0: in same direction; < 0: in opppsite direction)
    @param [in] yDistance distance of y-direction (> 0: in same direction; < 0: in opppsite direction)
    @param [out] point point on the axis at specified distance

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR

    @code
        szwPoint planeOrigin=...;
        szwVector xAxis=...;
        szwVector yAxis=...;
        ...
        double xDistance=...;
        double yDistance=...;
        ...
        szwPoint point{};
        ...
        ZwMathPlanePointGetByXYDistance(&planeOrigin, &xAxis, &yAxis, xDistance, yDistance, &point);
    @endcode
    */
    ZW_API_C ezwErrors ZwMathPlanePointGetByXYDistance(szwPoint planeOrigin, szwVector xAxis, szwVector yAxis, double xDistance, double yDistance, szwPoint *point);

    /**
    @ingroup ZwPoint

    Get a specific point on a 2D line segment consisting of two points.

    @code
       szwPoint2 resultPoint;
       // assume that there's a variable named startPoint(szwPoint2), a variable named endPoint(szwPoint2),
       // and a variable named factor(double)
       ZwMathLinerSegmentPoint2Get(startPoint, endPoint, factor, &resultPoint);
       ...
    @endcode

    @param [in] startPoint start point of the line segment
    @param [in] endPoint end point of the line segment
    @param [in] factor factor of the specific point. If factor entered by the user is greater than 1, factor will be set as 1.
                If factor entered by the user is less than 0, factor will be set as 0.
    @param [out] resultPoint the result point of this function. resultPoint = (factor * startPoint) + ((1-factor) * endPoint)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwMathLinerSegmentPoint2Get(szwPoint2 startPoint, szwPoint2 endPoint, double factor, szwPoint2 *resultPoint);

    /**
    @ingroup ZwPoint

    Get a specific point on a 3D line segment consisting of two points.

    @code
       szwPoint resultPoint;
       // assume that there's a variable named startPoint(szwPoint), a variable named endPoint(szwPoint),
       // and a variable named factor(double)
       ZwMathLinerSegmentPointGet(startPoint, endPoint, factor, &resultPoint);
       ...
    @endcode

    @param [in] startPoint start point of the line segment
    @param [in] endPoint end point of the line segment
    @param [in] factor factor of the specific point. If factor entered by the user is greater than 1, factor will be set as 1.
                If factor entered by the user is less than 0, factor will be set as 0.
    @param [out] resultPoint the result point of this function. resultPoint = (factor * startPoint) + ((1-factor) * endPoint)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C ezwErrors ZwMathLinerSegmentPointGet(szwPoint startPoint, szwPoint endPoint, double factor, szwPoint *resultPoint);

    /*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_POINT_H */