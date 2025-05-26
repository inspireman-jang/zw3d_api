/**
@file zwapi_brep_data.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of the Brep
objects.
*/
/**
@defgroup zwapi_brep_data Brep Data
@ingroup BrepEntityModel
@brief
@details THE MODULE FOR THE ZW3D Data Types and Structures of the Brep
objects.
*/

#pragma once
#ifndef ZW_API_BREP_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_BREP_DATA_H

#include "zwapi_util.h"
#include "zwapi_curve_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
    //====================================================================================================================
    /** @name pre-edge Query Data */
    //====================================================================================================================
    /**
    @brief pre-edge information
    @ingroup zwapi_brep_data
    */
    typedef struct svxPreEdge
    {
        svxLimit Limits; /**<@brief  limits of pre-edge within its parameter space */
        int idLoop;      /**<@brief  id of parent loop */
        int idEdge;      /**<@brief  id of parent edge */
        int idNext;      /**<@brief  id of next pre-edge in loop direction */
        int idGeom;      /**<@brief  id of uv curve geometry */
        int EdgeDir;     /**<@brief  direction relative to edge (1=same, -1=opposite) */
        int LoopDir;     /**<@brief  direction relative to loop (1=same, -1=opposite) */
    } svxPreEdge;

    /**
    @brief mass attributes
    @ingroup zwapi_brep_data
    */
    typedef struct svxMassProp
    {
        double Density;    /**<@brief  Density (kg/m^3) */
        double Area;       /**<@brief  Area (mm^2) */
        double Volume;     /**<@brief  Volume (mm^3) */
        double Mass;       /**<@brief  Mass (kg) */
        svxPoint Center;   /**<@brief  Centroid (i.e. Center of Gravity) */
        svxVector Axis[3]; /**<@brief  Principal axes relative to global xyz frame */
        double Im[6];      /**<@brief  Moments of inertia relative to xyz axes */
        double Ip[3];      /**<@brief  Moments of inertia relative to principal axes */
        double Rad[3];     /**<@brief  Radii of gyration relative to principal axes */
    } svxMassProp;

    /**
    @brief weldment attribute
    @ingroup zwapi_brep_data
    */
    typedef struct svxWeldAttr
    {
        svxAttribute spec;        /**<@brief  spec */
        svxAttribute description; /**<@brief  description */
        svxAttribute material;    /**<@brief  material */
        svxAttribute mass;        /**<@brief  mass */
        svxAttribute length;      /**<@brief  length */
    } svxWeldAttr;

    /**
    @brief surface evaluate
    @ingroup zwapi_brep_data
    */
    typedef struct svxEvalSurf
    {
        int level;             /**<@brief  level of evaluation                       */
        svxPoint pnt;          /**<@brief  level 0 - x,y,z on surface                */
        svxPoint normal;       /**<@brief  level 1 - unit normal vector              */
        svxPoint partial_u;    /**<@brief  level 1 - tangential component w/r u      */
        svxPoint partial_v;    /**<@brief  level 1 - tangential component w/r v      */
        svxPoint partial_uu;   /**<@brief  level 2 - 2nd partial w/r u               */
        svxPoint partial_uv;   /**<@brief  level 2 - 2nd partial w/r uv              */
        svxPoint partial_vv;   /**<@brief  level 2 - 2nd partial w/r v               */
        svxPoint partial_uuu;  /**<@brief  level 3 - 3rd partial w.r.t u             */
        svxPoint partial_vuu;  /**<@brief  level 3 - 3rd partial w.r.t uv            */
        svxPoint partial_uvv;  /**<@brief  level 3 - 3rd partial w.r.t uv            */
        svxPoint partial_vvv;  /**<@brief  level 3 - 3rd partial w.r.t v             */
        svxPoint partial_uuuu; /**<@brief  level 4 - 4th partial w.r.t u             */
        svxPoint partial_vuuu; /**<@brief  level 4 - 4th partial w.r.t uv            */
        svxPoint partial_uuvv; /**<@brief  level 4 - 4th partial w.r.t uv            */
        svxPoint partial_uvvv; /**<@brief  level 4 - 4th partial w.r.t vv            */
        svxPoint partial_vvvv; /**<@brief  level 4 - 4th partial w.r.t v             */
    } svxEvalSurf;

    //====================================================================================================================
    /** @name Face Data */
    //====================================================================================================================
    /**
    @brief tolerance type of refine facets
    @ingroup ZwBrepData
    */
    typedef enum ezwRefineFacetsToleranceType
    {
        ZW_FACETS_TOLORANCE_PIXEL,    /**<@brief pixel */
        ZW_FACETS_TOLORANCE_DISTANCE, /**<@brief distance */
        ZW_FACETS_TOLORANCE_ANGLE,    /**<@brief angle */
    } ezwRefineFacetsToleranceType;

    /**
    @brief refine facets data
    @ingroup ZwBrepData
    */
    typedef struct szwRefineFacets
    {
        szwEntityHandle faceHandle;        /**<@brief face handle */
        ezwRefineFacetsToleranceType type; /**<@brief tolerance type.default:ZW_FACETS_TOL_PIXEL */

        double edgeTolorance;    /**<@brief edge tolerance.min=0.001,default:1. apply it if type=ZW_FACETS_TOL_DISTANCE or ZW_FACETS_TOL_ANGLE. */
        double facetTolorance;   /**<@brief facet tolerance.min=0.001.default:1. apply it if type=ZW_FACETS_TOL_DISTANCE. */
        double angleTolorance;   /**<@brief angle tolerance.min=1,max=30,default:5. apply it if type=ZW_FACETS_TOL_ANGLE. */
        double surfaceTolorance; /**<@brief surface tolerance.min=0.1,max=10,default:1. apply it if type=ZW_FACETS_TOL_PIXEL. */
    } szwRefineFacets;

    /**
    @brief refine facets data of multi faces
    @ingroup ZwBrepData
    */
    typedef struct szwRefineFacetsOfMultiFace
    {
        int countFace;               /**<@brief count of face data in list */
        szwEntityHandle *faceHandle; /**<@brief face data list */

        ezwRefineFacetsToleranceType type; /**<@brief tolerance type.default:ZW_FACETS_TOL_PIXEL */
        double edgeTolorance;              /**<@brief edge tolerance.min=0.001,default:1. apply it if type=ZW_FACETS_TOL_DISTANCE or ZW_FACETS_TOL_ANGLE. */
        double facetTolorance;             /**<@brief facet tolerance.min=0.001.default:1. apply it if type=ZW_FACETS_TOL_DISTANCE. */
        double angleTolorance;             /**<@brief angle tolerance.min=1,max=30,default:5. apply it if type=ZW_FACETS_TOL_ANGLE. */
        double surfaceTolorance;           /**<@brief surface tolerance.min=0.1,max=10,default:1. apply it if type=ZW_FACETS_TOL_PIXEL. */
    } szwRefineFacetsOfMultiFace;
    /**
    @brief 3D facets defined by triangle strips
    @ingroup ZwBrepData
    */
    typedef struct szwFacets
    {
        int numberTriangleStrip; /**<@brief  number of triangle strips in triangleStrip */
        int *triangleStrip;      /**<@brief  list of integer indices that define triangle strips
                               **
                               ** This list has the format "num_vertices_in_strip_1,  
                               ** index_of_vertex_1,index_of_vertex_2,...,index_of_vertex_N,  
                               ** num_vertices_in_strip_2,..." where an index is an offset  
                               ** into the list of Vertex/Normal/ST/UV/RGB coordinates, numbered  
                               ** from 0.  A triangle strip defined by N vertices defines  
                               ** N-2 triangles.  For example, if a triangle strip is  
                               ** defined by 5 vertices whose indices are {0,1,2,3,4},  
                               ** then it contains 3 triangles defined by vertices {0,1,2},  
                               ** {2,1,3} and {2,3,4} (when using data from a triangle strip,  
                               ** note that vertex order is implicitly reversed for alternating  
                               ** triangles when calculating the implied normal direction  
                               ** of each triangle's plane). */

        int numberVertex;  /**<@brief   number of vertices in Vertex list */
        szwPointf *vertex; /**<@brief   list of vertex coordinates (x,y,z) */
        szwPointf *normal; /**<@brief   list of vertex normals (i,j,k unit direction vector);
                               ** normal is optional and may be NULL */

        szwPoint2f *st; /**<@brief   list of vertex texture coordinates (s,t from 0.0 to 1.0);
                               ** st is optional and may be NULL */
        szwPoint2f *uv; /**<@brief   list of UV coordinates corresponding to vertex coordinates;
                        ** UV is optional and may be NULL */
        szwColorf *rgb; /**<@brief   list of vertex colors (r,g,b components from 0.0 to 1.0;
                        ** see cvxColorfToColor() for conversion to svxColor);
                        ** RGB is optional and may be NULL
                        ** (NOTE: The RGB field is a placeholder for a future enhancement
                        ** and is not yet supported.  Colors assigned to this field will
                        ** be ignored when a facet block is displayed.) */
    } szwFacets;

    /**
    @brief face appearance
    @ingroup ZwBrepData
    */
    typedef struct szwFaceDisplayAttribute
    {
        /*basic attribute*/
        szwColor frontColor; /**<@brief  color of front side */
        szwColor backColor;  /**<@brief  color of back side */
        int ambient;         /**<@brief  ambient reflection coeff. (0-100) */
        int diffuse;         /**<@brief  diffuse reflection coeff. (0-100) */
        int reflectance;     /**<@brief  reflectance (0-100) */
        int transperance;    /**<@brief  transparency setting (0-100) */
        double refraction;   /**<@brief  refraction (0-6), only one decimal place is supported*/
        int glow;            /**<@brief  emission(0-100) */
        /*Specular*/
        int shine;           /**<@brief  specular exponent (0-128) */
        int glossiness;      /**<@brief  specular reflection coeff. (0-100) */
        szwColor glossColor; /**<@brief  gloss color */
    } szwFaceDisplayAttribute;

    /**
    @brief 3D NURB surface (untrimmed)
    @ingroup ZwBrepData
    */
    typedef struct szwSurface
    {
        ezwSurfaceType Type;    /**<@brief  surface type */
        int outNormal;          /**<@brief  1 if the surface's natural normal points towards
                        ** the outside of the shape it is associated with;
                        ** 0 if the surface's natural normal points inward.
                        */
        szwNurbsParameter U;    /**<@brief  NURB parameter space data in U direction */
        szwNurbsParameter V;    /**<@brief  NURB parameter space data in V direction */
        szwNurbsControlPoint P; /**<@brief  NURB control point data (mm) */
    } szwSurface;

    /**
    @brief Surface continuity tolerance setting
    @ingroup ZwBrepData
    */
    typedef struct szwSurfaceContinuityTolerance
    {
        double positionTolerance;  /**<@brief tolerance of position. default:0.01
                                          Judge whether the two surfaces are G0 continuous tolerance.(in millimeters). */
        double tangentTolerance;   /**<@brief tolerance of tangent. default:0.5
                                          Judge whether the two surfaces are G1 continuous tolerance.(degrees). */
        double curvatureTolerance; /**<@brief tolerance of curvature. default:0.05
                                          Judge whether the two surfaces are G2 continuous tolerance. */
        double flowTolerance;      /**<@brief tolerance of flow. default:0.05
                                          Judge whether the two surfaces are G3 continuous tolerance. */
    } szwSurfaceContinuityTolerance;

    /**
    @brief Surface continuity data
    @ingroup ZwBrepData
    */
    typedef struct szwSurfaceContinuityData
    {
        szwEntityHandle edge1; /**<@brief the entity handle of the first edge
                                         the caller must free memory of the object using ZwEntityHandleFree */
        szwEntityHandle edge2; /**<@brief the entity handle of the second edge, if it is a shared edge, the value will be set to nullptr
                                         the caller must free memory of the object using ZwEntityHandleFree */

        /* position continuity */
        int isPositionContinuous; /**<@brief whether surfaces are G0 position continuity (1: continuity; 0: discontinuity) */
        double averageDistance;   /**<@brief the average distance between sampling points on two surfaces */
        double maxDistance;       /**<@brief the maximum distance between sampling points on two surfaces */

        /* tangent continuity */
        int isTangentContinuous; /**<@brief whether surfaces are G1 tangent continuity (1: continuity; 0: discontinuity) */
        double averageAngle;     /**<@brief the average angle difference between normal vectors of two surfaces at sampling points (unit: degree) */
        double maxAngle;         /**<@brief the maximum angle difference between normal vectors of two surfaces at sampling points (unit: degree) */

        /* curvature continuity */
        int isCurvatureContinuous; /**<@brief whether surfaces are G2 curvature continuity (1: continuity; 0: discontinuity) */
        double averageCurvature;   /**<@brief the average curvature difference between two surfaces at sampling points (unitless ration, 0: perfect; 2: worst possible) */
        double maxCurvature;       /**<@brief the maximum curvature difference between two surfaces at sampling points (unitless ration, 0: perfect; 2: worst possible) */

        /* flow continuity */
        int isFlowContinuous; /**<@brief whether surfaces are G3 flow continuity (1: continuity; 0: discontinuity) */
        double averageFlow;   /**<@brief the average flow difference between two surfaces at sampling points (unitless ration, 0: perfect; 2: worst possible) */
        double maxFlow;       /**<@brief the maximum flow difference between two surfaces at sampling points (unitless ration, 0: perfect; 2: worst possible) */
    } szwSurfaceContinuityData;
    //====================================================================================================================
    /** @name Shape Data */
    //====================================================================================================================
    /**
    @brief Thickness analysis methods
    @ingroup ZwBrepData
    */
    typedef enum ezwPartThicknessMethods
    {
        ZW_PART_THICKNESS_BALL_ROLLING = 1, /**<@brief  Ball-rolling */
        ZW_PART_THICKNESS_RAY_CASTING  = 2, /**<@brief  Ray-casting */
    } ezwPartThicknessMethods;

    //====================================================================================================================
    /** @name Edge Data */
    //====================================================================================================================
    /**
    @brief discrete data of edge
    @ingroup ZwBrepData
    */
    typedef struct szwEdgeDiscreteData
    {
        szwEntityHandle edgeHandle;       /**<@brief handle of edge */
        int numberPoint;                  /**<@brief number of sampled points on edge */
        szwSampledPointOnEdge *pointData; /**<@brief array of sampled points data */
        double tolorance;                 /**<@brief Tolerance used when points were sampled */
    } szwEdgeDiscreteData;

    /**
    @brief shape interference type
    @ingroup ZwBrepData
    */
    typedef enum ezwInterferenceType
    {
        ZW_NONE,         /**<@brief  invalid */
        ZW_A_IN_B,       /**<@brief  interference and A completely contains B */
        ZW_A_OUT_B,      /**<@brief  interference and B completely contains A */
        ZW_INTERFERENCE, /**<@brief  interference */
        ZW_CONTACT,      /**<@brief  contact */
        ZW_NO_CONTACT,   /**<@brief  no contact */
    } ezwInterferenceType;

    /**
    @brief type of edge
    @ingroup ZwEdgeData
    */
    typedef enum ezwEdgeType
    {
        ZW_EDGE_UNKNOWN  = -1, /**<@brief unknown */
        ZW_EDGE_STANDARD = 0,  /**<@brief standard edge */
        ZW_EDGE_SEAM     = 1,  /**<@brief seam edge */
        ZW_EDGE_DEGEN    = 2   /**<@brief degenerate edge */
    } ezwEdgeType;


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ZW_API_BREP_DATA_H */
