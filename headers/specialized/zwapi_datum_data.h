/**
@file zwapi_datum_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Datum API Data
*/

#pragma once
#ifndef ZW_API_DATUM_DATA_H
#define ZW_API_DATUM_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Part Datum Axis */
    //====================================================================================================================

    /**
    @brief axis direction types
    @ingroup ZwDatumData
    */
    typedef enum ezwDatumAxisDirectionType
    {
        ZW_AXIS_CURVE_TANGENT       = 0, /**<@brief  tangent */
        ZW_AXIS_CURVE_PERPENDICULAR = 1, /**<@brief  perpendicular */
    } ezwDatumAxisDirectionType;

    /**
    @brief axis types of CSYS
    @ingroup ZwDatumData
    */
    typedef enum ezwDatumAxisType
    {
        ZW_DATUM_AXIS_X = 1, /**<@brief  X axis */
        ZW_DATUM_AXIS_Y = 2, /**<@brief  Y axis */
        ZW_DATUM_AXIS_Z = 3, /**<@brief  Z axis */
    } ezwDatumAxisType;

    //====================================================================================================================
    /** @name Part Datum Plane */
    //====================================================================================================================

    /**
    @brief plane direction types
    @ingroup ZwDatumData
    */
    typedef enum ezwDatumPlaneDirectionType
    {
        ZW_PLANE_CURVE_TANGENT       = 0, /**<@brief  tangent */
        ZW_PLANE_CURVE_PERPENDICULAR = 1, /**<@brief  perpendicular */
    } ezwDatumPlaneDirectionType;

    /**
    @brief plane types of CSYS
    @ingroup ZwDatumData
    */
    typedef enum ezwDatumPlaneType
    {
        ZW_DATUM_PLANE_XY = 1, /**<@brief  XY plane */
        ZW_DATUM_PLANE_YZ = 2, /**<@brief  YZ plane */
        ZW_DATUM_PLANE_XZ = 3, /**<@brief  XZ plane */
    } ezwDatumPlaneType;

    //====================================================================================================================
    /** @name Datum CSYS Data */
    //====================================================================================================================
    /**
    @brief Create method of CSYS: create by three points
    @ingroup ZwDatumCSYSData
    */
    typedef struct szwDatumCSYSMethodThreePoints
    {
        szwPoint origin; /**<@brief  origin point */
        szwPoint xPoint; /**<@brief  point to x axis */
        szwPoint yPoint; /**<@brief  point to x axis */
    } szwDatumCSYSMethodThreePoints;

    /**
    @brief Create method of CSYS: create by origin point x and y axis direction
    @ingroup ZwDatumCSYSData
    */
    typedef struct szwDatumCSYSMethodPointAndDirection
    {
        szwPoint origin;      /**<@brief  origin point */
        szwVector directionX; /**<@brief  direction of x axis */
        szwVector directionY; /**<@brief  direction of y axis */
    } szwDatumCSYSMethodPointAndDirection;

    /**
    @brief Create method of CSYS: create by plane and direction
    @ingroup ZwDatumCSYSData
    */
    typedef struct szwDatumCSYSMethodPlaneAndDirection
    {
        szwEntityHandle plane; /**<@brief  face or datum plane */
        szwPoint point;        /**<@brief  point to locate the origin of the plane */
        szwVector directionX;  /**<@brief  direction of x axis */
        int flip;              /**<@brief  flip the direction of z axis, 0-keep default, 1-flip */
    } szwDatumCSYSMethodPlaneAndDirection;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !ZW_API_DATUM_DATA_H */
