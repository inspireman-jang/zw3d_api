/**
@file zwapi_geometry_curve.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Object's(Entity) Common API
*/

#pragma once
#ifndef ZW_API_GEOMETRY_CURVE_H /* this ifndef surrounds entire header */
#define ZW_API_GEOMETRY_CURVE_H

#include "zwapi_math_data.h"
#include "zwapi_curve_data.h"
#include "zwapi_preedge.h"
#include "zwapi_shape.h"
#include "zwapi_matrix_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /**
    @ingroup ZwCurve

    Applies transformation matrix "inputMatrix" to "curve".
    Assumes "inputMatrix" is an affine transform.

    @param [in] inputMatrix transformation matrix
    @param [in,out] curve curve to transformation

     @retval succeeds
     -        ZW_API_NO_ERROR
     @retval fail
     -        ZW_API_GENERAL_ERROR
     -        ZW_API_INVALID_INPUT
     -        ZW_API_MATRIX_NONORTHOGONAL

    @code
       szwMatrix inputMatrix=...;
       ...
       szwCurve curve{};
       ZwFaceDataTransform(inputMatrix,&curve);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveDataTransform(szwMatrix inputMatrix, szwCurve *curve);

    /**
    @ingroup ZwCurve

    Check if the specified curve is a straight line.

    @code
       szwEntityHandle curveHandle;
       ...
       int isLine = -1;
       ZwCurveLineCheck(curveHandle,&isLine);
       ...
       ZwEntityHandleFree(&curveHandle);
    @endcode

    @param [in] curveHandle handle of the curve
    @param [out] isLine  0:the specified curve is not a straight line  1: the specified curve is a straight line

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OBJ_TYPE_ERROR
    */
    ZW_API_C ezwErrors ZwCurveLineCheck(szwEntityHandle curveHandle, int *isLine);

    /**
    @ingroup ZwCurve

    Gets point on a curve at a specified fraction of the curve's length.
    For example, to evaluate the curve at its minimum parameter value,
    set frac to 0.0; to evaluate the curve at its maximum parameter value,
    set frac to 1.0; and to evaluate the mid-point of the curve where the
    length from each end is the same, set frac to 0.5.

    @code
       szwEntityHandle curveHandle;
       double fraction =...;
       ...
       svxPoint point{};
       ZwCurvePointGetByLengthFraction(curveHandle,fraction,&point);
       ...
        ZwEntityHandleFree(&curveHandle);
    @endcode

    @param [in] curveHandle handle of the curve
    @param [in] fraction fraction of curve length (0.0 to 1.0)
    @param [out] point output point on curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwCurvePointGetByLengthFraction(szwEntityHandle curveHandle, double fraction, szwPoint *point);

    /**
    @ingroup ZwCurve

    Check the closure of curves.

    @param [in] count count of curve 
    @param [in] curveHandle handles of curves
    @param [out] closure closure of curves
                0 : open
                1 : close, position continuous
                2 : close, tangent continuous

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_WRONG_ROOT_ENV

    @code
       szwEntityHandle curveHandle=...;
       int count =...;
       ...
       int closure =...;
       ZwCurveClosureCheck(count,curveHandle,&closure);
       ...
       ZwEntityHandleListFree(count,&curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveClosureCheck(int count, const szwEntityHandle *curveHandle, int *closure);

    /**
    @ingroup ZwCurve

    Gets the extreme point of curve in the specified direction. if the curve is
    on a plane perpendicular to direction, the extreme point output is critical point
    of curve.

    @note
    Curve with different type has different critical point:  
    Center point is the critical point of Arc and Circle.  
    Start point is the critical point of nurbs curve, line, and ellipse.

    @param [in] curveHandle handle of curve in active part
    @param [in] direction direction
    @param [out] isPerpendicular output 1 if the curve is on a plane perpendicular to direction, else 0
    @param [out] point extreme point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -       ZW_API_GENERAL_ERROR
    -       ZW_API_INVALID_INPUT
    -       ZW_API_INVALID_OUTPUT
    -       ZW_API_ROOT_OBJ_ACT_FAIL
    -       ZW_API_MODELING_DATA_ERROR
    -       ZW_API_MEMORY_ERROR
    -       ZW_API_WRONG_ROOT_ENV
    -       ZW_API_OBJ_TYPE_ERROR

    @code
    szwEntityHandle curveHandle;
    svxVector direction;
    ...
    int isPerpendicular = -1;
    szwPoint point;
    ZwCurveExtremePointGet(curveHandle,direction,&isPerpendicular,&point);
    ...
    ZwEntityHandleFree(&curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveExtremePointGet(szwEntityHandle curveHandle, szwVector direction, int *isPerpendicular, szwPoint *point);

    /**
    @ingroup ZwCurve

    Calculates the length of the specified curve.

    @param [in] curveHandle handle of curve  
    @param [out] length curve length (mm)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_INPUT_TYPE_ERROR

    @code
       szwEntityHandle curveHandle;
       ...
       double length = 0;
       ZwCurveLengthGet(edgeHandle,&length);
       ...
        ZwEntityHandleFree(&curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveLengthGet(szwEntityHandle curveHandle, double *length);

    /**
    @ingroup ZwCurve

    Calculates the curve length of a NURBS curve from the parameter startT to endT.

    @param [in] curveHandle handle of curve
    @param [in] startT T parameter value of start point
    @param [in] endT T parameter value of end point
    @param [out] length length of a NURBS curve from startT to endT

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR

    @code
       szwEntityHandle curveHandle;
       ...
       double startT = ...;
       double endT = ...;
       double length = 0;
       ZwCurveSegmentLengthGet(edgeHandle,startT,endT,&length);
       ...
        ZwEntityHandleFree(&curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveSegmentLengthGet(szwEntityHandle curveHandle, double startT, double endT, double *length);


    /**
    @ingroup ZwCurve

    Get the maximum and minimum radius of the spline curve.
    If curvature of curve = 0, minRad = maxRad = -1 (the radius of curvature is infinite).

    @param [in] curveHandle handle of curve
    @param [out] minRadius minimum radius(NULL to ignore)
    @param [out] maxRadius maximum radius(NULL to ignore)
    @param [out] isFlat 1 if the curve is flat, else 0(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR

    @code
       szwEntityHandle curveHandle;
       ...
       double minRad = 0;
       double maxRad = 0;
       int isFlat = 0;
       ZwCurveRadiusRangeGet(edgeHandle,&minRad,&maxRad,&isFlat);
       ...
       ZwEntityHandleFree(&curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveRadiusRangeGet(szwEntityHandle curveHandle, double *minRadius, double *maxRadius, int *isFlat);


    /**
    @ingroup ZwCurve
    Use the function to find connected chain of curves or edges and output a list
    of edges or curves.

    @note
    If the seed is a curve, the chain consists of curves that are connected end-to-end,
    but without any requirement for tangency between curve.

    If the seed is an edge, the chain consists of edges that are tangent, i.e. smoothly
    connected end-to-end. If type is 0, an edge may bound any number of faces. If type
    is 1, only open edges are included in the chain, the requirement for tangency between
    edges is suspended, so a chain of open edges may continue around sharp corners. If
    type is 2, only manifold edges are included in the chain, i.e. edges that are shared
    by exactly two faces, or edges that have seams with the same face on both sides.

    The calling procedure MUST deallocate the output list with ZwEntityHandleListFree().

    @param [in] seedCount number of seed edges or curves
    @param [in] seedHandles list of handles of seed edges or curves
    @param [in] type type of edges, only effects the find result of the seed edge.
    @param [out] countFound number of curves found
    @param [out] foundHandle list of curves' handles

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_INVALID_OUTPUT

    @code
       int seedCount = ...;
       szwEntityHandle seedHandle[seedCount];
       ezwCurveChainType type = ...;
       ...
       zwEntityHandle* foundHandle= nullptr;
       int countFound = 0;
       ZwCurveChainGet(seedCount,seedHandle,type,&countFound,&foundHandle);
       ...
       ZwEntityHandleListFree(countFound,&foundHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveChainGet(int seedCount, const szwEntityHandle *seedHandles, ezwCurveChainType type, int *countFound, szwEntityHandle **foundHandle);

    /**
    @ingroup ZwCurve

    Outputs the T parameter value of the projection of the input XYZ
    point onto the NURBS representation of the specified curve.  It
    is assumed that "Pnt" lies on or very close to the curve.

    @param [in] curveHandle handle of curve
    @param [in] point coordinates of point to project onto curve
    @param [out] tParameter T parameter value of point-on-curve
    @param [out] projectedPoint XYZ coordinates of projected point

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    
    @code
       szwEntityHandle curveHandle=...;
       zwPoint point=...;
       ...
       szwPoint projectedPoint{};
       double tParameter{};
       ZwCurveProjectionPointGet(curveHandle,point,&tParameter,&projectedPoint);
       ...
        ZwEntityHandleFree(curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveProjectionPointGet(szwEntityHandle curveHandle, szwPoint point, double *tParameter, szwPoint *projectedPoint);

    /**
    @ingroup ZwCurve

    Outputs the minimum and maximum t parameter values of the
    NURBS representation of the specified curve entity.

    @param [in] curveHandle handle of curve
    @param [out] tLimit min/max T values

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    
    @code
       szwEntityHandle curveHandle;
       ...
       szwLimit tLimit{};
       ZwCurveTParameterRangeGet(curveHandle,&tLimit);
       ...
        ZwEntityHandleFree(curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveTParameterRangeGet(szwEntityHandle curveHandle, szwLimit *tLimit);

    /**
    @ingroup ZwCurve

    For all input lines, judge the continuity relationship between two lines.
    CntContinuity is the number of intersections between every two line segments,it may be 0.
    Data is the continuity of the two line segments represented by the intersection.

    @note
    Interface ZwCurveContinuityToleranceListInit() can initialize variables of this function.

    @param [in] count count of curves
    @param [in] curveHandles handles of curve
    @param [in] tolerance tolerance of curve continuity
    @param [out] countContinuity count of data
    @param [out] data list of continuity data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MEMORY_ERROR
    
    @code
       int count = ...;
       szwEntityHandle curveHandles[count];
       szwCurveContinuityToleranceList tolerance;
       ZwCurveContinuityToleranceListInit(&tolerance);
       ...
       int countContinuity = 0;
       szwCurveContinuityToleranceList* data =nullptr;
       ZwCurveContinuityGet(count,curveHandles,tolerance,&countContinuity,&data);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveContinuityGet(int count, const szwEntityHandle *curveHandles, szwCurveContinuityToleranceList tolerance, int *countContinuity, szwCurveContinuityData **data);

    /**
    @ingroup ZwCurve

    Initialize the parameters of the ZwCurveContinuityGet().

    @note
    Do not assign a value to variable "data" before calling this function.

    @param [in,out] data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    
    @code
       szwCurveContinuityToleranceList data;
       ZwCurveContinuityToleranceListInit(&data);
       ...
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveContinuityToleranceListInit(szwCurveContinuityToleranceList *data);

    /**
    @ingroup ZwCurve

    Get point on a curve at a specified distance from the specified
    start point of the curve.

    @param [in] curveHandle curve entity handle data
    @param [in] startT T parameter value of starting point
    @param [in] length Length of interval
    @param [out] T T parameter value of output point(NULL to ignore)
    @param [out] point output point on curve(NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR

    @code
        szwEntityHandle curveHandle;
		double startT=...;
		double lenght=...;
		double T=0.0;
		szwPoint point{};
        ...
		ZwCurvePointGetByDistance(curveHandle, startT, lenght, &T, &point);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurvePointGetByDistance(szwEntityHandle curveHandle, double startT, double length, double *T, szwPoint *point);

    /**
    @ingroup ZwCurve

    Calculates inflection points of the specified curve and outputs the list of  
    parameter value and coordinates of inflection points found.The calling  
    procedure MUST deallocate the output list.

    @param [in] curveHandle handle data of curve in the active object
    @param [out] count number of inflection points found
    @param [out] T T parameter value of each inflection points (NULL to ignore)
    @param [out] inflectPoints the array of inflection points (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    
    @code
		szwEntityHandle curveHandle;
		ZwEntityIdTransfer(1, &idCurve, &curveHandle);
        ...
		int count = -1;
		double* T = nullptr;
        ...
		szwPoint* infPoints = nullptr;
        ...
		ZwCurveInflectionPointGet(curveHandle, &count, &T, &infPoints);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveInflectionPointGet(szwEntityHandle curveHandle, int *count, double **T, szwPoint **inflectPoints);

    /**
    @ingroup ZwCurve

    Find cusps of the specified curve and outputs the list of  
    parameter value and coordinates of cusps.The calling  
    procedure MUST deallocate the output list.

    @param [in] curveHandle entity handle data of curve in the active object
    @param [out] count number of cusps found
    @param [out] T T parameter value of each cusps (NULL to ignore)
    @param [out] cusps the array of cusps found (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    
    @code
		szwEntityHandle curveHandle;
        ...
		int count = -1;
		double* T = NULL;
        ...
		szwPoint* cusps = NULL;
        ...
		ZwCurveCuspsGet(curveHandle, &count, &T, &cusps);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveCuspsGet(szwEntityHandle curveHandle, int *count, double **T, szwPoint **cusps);

    /**
    @ingroup ZwCurve

    Return the extreme points of specified curve and its bounding box.

    The list of extreme points must be freed by caller.

    @param [in] curveHandle entity handle data of curve entity
    @param [out] count extreme point count
    @param [out] points list of extreme points
    @param [out] boundingBox optional curve tight bounding box (or NULL)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    
    @code
        szwEntityHandle curveHandle=...;
        ...
        int count=0;
        ...
        szwPoint* points = nullptr;
        ...
        szwBoundingBox bndBox{};
        ...
        ZwCurveExtremePointAndBoundingBoxGet(curveHandle, &count, &points, &bndBox);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveExtremePointAndBoundingBoxGet(szwEntityHandle curveHandle, int *count, szwPoint **points, szwBoundingBox *boundingBox);

    /**
    @ingroup ZwCurve

    Evaluates curvature, point and unit principal normal vector of a given curve
    at the specified parameter.Use ZwCurveTParameterRangeGet to get the curve's parameter limits.

    @param [in] curveHandle curve entity handle data
    @param [in] t parameter at which the curvature is evaluated
    @param [out] point point at the specified parameter (input NULL to ignore).
    @param [out] normal unit principal normal vector at the specified parameter
                        (input NULL to ignore).
    @param [out] curvature curvature at the specified parameter (input NULL to ignore).

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_OBJ_TYPE_ERROR
    -        ZW_API_MEMORY_ERROR
    
    @code
        szwEntityHandle curveHandle;
        ...
        double t=...;
        ...
        szwPoint point{};
        szwPoint normalP{};

        double curvature=0.0;
        ...
        ZwCurveCurvatureGet(curveHandle, t, &point, &normalP, &curvature);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveCurvatureGet(szwEntityHandle curveHandle, double t, szwPoint *point, szwPoint *normal, double *curvature);

    /**
    @ingroup ZwCurve

    Evaluates the NURBS representation of the curve entity
    specified by "idCurve".  Outputs the point coordinates (Point)
    and normal direction (Normal) at the specified "t" parameter
    value.

    This will Distinguish surface from curve. If the input curve
    "level" specifies the level of evaluation. The higher the level, more
    data gets returned (at the expense of greater computation).

    Also, use ZwCurveCurvatureGet if you need the normal that points toward
    the curve's center of curvature.

    @verbatim
                               level
          |  0  |        1       |       2        |      3      
          +-----+----------------+----------------+-------------
          | pnt |  derivative_1  |  derivative_2  | derivative_3
    @endverbatim

    @param [in] curveHandle curve entity handle
    @param [in] t t parameter value on curve
    @param [in] level level of evaluation(0 ~ 3), See description below
    @param [out] evaluate Result
    @param [out] normal normal at point on curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    
    @code
        szwEntityHandle curveHandle;
        ZwEntityIdTransfer(1, &idCurve, &curveHandle);
        ...
        double t=...;
        ...
        int level=...;
        ...
        szwCurveDerivative eval{};
        szwVector normal{};
        ...
        ZwCurveDifferentiate(curveHandle, t, level, &eval, &normal);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveDifferentiate(szwEntityHandle curveHandle, double t, int level, szwCurveDerivative *evaluate, szwVector *normal);

    /**
    @ingroup ZwCurve
    
    Outputs the end points of the specified curve entity.
    
    @param [in] entityHandle entity handle (in active file)
    @param [out] start start point
    @param [out] end end point
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    */
    ZW_API_C ezwErrors ZwCurveEndPointGet(szwEntityHandle entityHandle, szwPoint *start, szwPoint *end);

    /**
    @ingroup ZwCurve

    Get the centroid point of the curve.

    @param [in] curveHandle handle of the curve
    @param [out] centroidPoint the centroid point of the curve

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_INPUT_TYPE_ERROR

    @code
    szwPoint centroidPoint;
    szwEntityHandle curveHandle;
    ... // get the data of curveHandle
    ZwCurveCentroidPointGet(curveHandle, &centroidPoint);
    ...
    ZwEntityHandleFree(&curveHandle);
    @endcode
    */
    ZW_API_C ezwErrors ZwCurveCentroidPointGet(szwEntityHandle curveHandle, szwPoint *centroidPoint);

    /**
    @ingroup ZwCurve

    Outputs the tessellation sampling points of the specified curve according to the chord height tolerance and length tolerance.

    @param [in] curve the entity handle of the curve
    @param [in] chordTolerance chord height tolerance
    @param [in] lengthTolerance length tolerance
    @param [out] nPoints the number of the tessellation sampling points
    @param [out] points list of the tessellation points, the caller must free memory of the object using ZwMemoryFree

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C ezwErrors ZwCurveTessellationPointListGet(szwEntityHandle curve, double chordTolerance, double lengthTolerance, int *nPoints, szwPoint **points);

    //====================================================================================================================
    /** @name Curve Data */
    //====================================================================================================================
    /**
    @ingroup ZwCurve

    Gets curve geometry for the specified curvilinear entity, including  
    face edges.  If "nurbs" is input as 1, NURBS data is output for  
    analytic curve types (e.g. line, arc, circle).  NURBS data is output  
    via "curve" using memory allocated by this function.
    
    @note
    It is assumed the curve geometry resides in the active part.
    The caller is responsible to free the curve by using ZwCurveFree().

    @param [in] entityHandle entity handle data of curvilinear entity (includes edges)
    @param [in] nurbs 1=get NURBS data for all curve types; else 0
    @param [out] curve curve data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_MODELING_DATA_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C ezwErrors ZwCurveNURBSDataGet(szwEntityHandle entityHandle, int nurbs, szwCurve *curve);

    /**
    @ingroup ZwCurve

    Frees memory associated with the specified curve structure.

    Frees the memory at curve->parameter.knots only when curve->parameter.freeMemory is 1.
    Frees the memory at curve->controlPoint.coordinate only when curve->coordinate.freeMemory is 1.

    @param [in] curve curve structure

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwCurveFree(szwCurve *curve);

    //====================================================================================================================
    /** @name Curve Get */
    //====================================================================================================================
    /**
    @ingroup ZwCurve

    Outputs a list of indices of the curves that belong to the active part.  

    @note
    The caller is responsible to free the curveList by using ZwEntityHandleListFree().

    @param [out] countCurve number of curves
    @param [out] curveList list of curve handle data's

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwCurveListGet(int *countCurve, szwEntityHandle **curveList);

    /**
    @ingroup ZwCurve

    Mutual convert between the interpolation curve and the control point curve.
    Function Guide: Wireframe -> Edit Curve -> Modify

    @param [in] curve the curve to be converted

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INPUT_TYPE_ERROR
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_MODELING_DATA_ERROR
    */
    ZW_API_C ezwErrors ZwCurveModifyTypeConvert(szwEntityHandle curve);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_GEOMETRY_CURVE_H */
