/**
@file zwapi_motion_data.h
@copyright (C) Copyright 2024, ZWSOFT Co., LTD.(Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of Motion.
*/

#pragma once
#ifndef ZW_API_MOTION_DATA_H /* this ifndef surrounds entire header */
#define ZW_API_MOTION_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    /* the entity types in motion */
    typedef enum ezwMotType
    {
        ZW_MOT_BODY,     /* body */
        ZW_MOT_JOINT,    /* joint */
        ZW_MOT_DRIVER,   /* driver */
        ZW_MOT_SOLUTION, /* solution */

        ZW_MOT_NUM, /* motion entity type total number */
    } ezwMotType;

    /* the body center type */
    typedef enum ezwMotBodyCenterType
    {
        ZW_MOT_BODY_CENTER_NONE, /* body center not set */
        ZW_MOT_BODY_CENTER_AUTO, /* body center auto set */
        ZW_MOT_BODY_CENTER_USER, /* body center set by user */
    } ezwMotBodyCenterType;

    /* the joint type */
    typedef enum ezwMotJointType
    {
        ZW_MOT_JOINT_TYPE_BASIC,      /* basic joint */
        ZW_MOT_JOINT_TYPE_COUPLER,    /* coupler joint */
        ZW_MOT_JOINT_TYPE_CONSTRAINT, /* constraint joint */
    } ezwMotJointType;

    /* the joint sub class */
    typedef enum ezwMotJointSubClass
    {
        /* basic type */
        ZW_MOT_JOINT_REVOLUTE,    /* revolute joint */
        ZW_MOT_JOINT_SLIDER,      /* slider joint */
        ZW_MOT_JOINT_CYLINDRICAL, /* cylindrical joint */
        ZW_MOT_JOINT_SCREW,       /* screw joint */
        ZW_MOT_JOINT_SPHERICAL,   /* spherical joint */
        ZW_MOT_JOINT_PLANAR,      /* planar joint */
        ZW_MOT_JOINT_HOOKE,       /* hooke joint */
        ZW_MOT_JOINT_RIGID,       /* rigid joint */

        /* constraint type */
        ZW_MOT_JOINT_POINT_CURVE,   /* point-curve joint */
        ZW_MOT_JOINT_CURVE_CURVE,   /* curve-curve joint */
        ZW_MOT_JOINT_POINT_SURFACE, /* point-surface joint */

        /* coupler type */
        ZW_MOT_JOINT_GEAR,      /* gear joint */
        ZW_MOT_JOINT_RACK,      /* rack joint */
        ZW_MOT_JOINT_CABLE,     /* cable joint */
        ZW_MOT_JOINT_UNIVERSAL, /* universal joint */
        ZW_MOT_JOINT_GENERAL,   /* general joint */
    } ezwMotJointSubClass;

    /* the driver type */
    typedef enum ezwMotDriverType
    {
        ZW_MOT_DRIVER_DISPLACEMENT,      /* displacement */
        ZW_MOT_DRIVER_VELOCITY,          /* velocity */
        ZW_MOT_DRIVER_ACCELERATION,      /* acceleration */
        ZW_MOT_DRIVER_ANGLE,             /* angle */
        ZW_MOT_DRIVER_ANGLE_VELELOCITY,  /* angular velocity */
        ZW_MOT_DRIVER_ANGLE_ACCELERATION /* angular acceleration */
    } ezwMotDriverType;

    /* the driver function type */
    typedef enum ezwMotDriverFunctionType
    {
        ZW_MOT_DRIVER_FUNCTION_CONST,      /* constant */
        ZW_MOT_DRIVER_FUNCTION_LINEAR,     /* linear */
        ZW_MOT_DRIVER_FUNCTION_COSINE,     /* cosine */
        ZW_MOT_DRIVER_FUNCTION_CYCLOIDAL,  /* cycloid */
        ZW_MOT_DRIVER_FUNCTION_PARABOLIC,  /* parabola */
        ZW_MOT_DRIVER_FUNCTION_POLYNOMIAL, /* polynomial */
        ZW_MOT_DRIVER_FUNCTION_USER,       /* user defined */
        ZW_MOT_DRIVER_FUNCTION_FITTED      /* fitted curve */
    } ezwMotDriverFunctionType;

    typedef enum ezwMotDriverFittedMethod
    {
        ZW_MOT_DRIVER_FITTED_LINEAR, /* fitted by linear type */
        ZW_MOT_DRIVER_FITTED_SPLINE, /* fitted by spline */
    };

    /* the solution analysis type */
    typedef enum ezwMotSolutionType
    {
        ZW_MOT_SOLUTION_LOCATION,   /* location */
        ZW_MOT_SOLUTION_KINEMATICS, /* kinematics */
    } ezwMotSolutionType;

    /* the driver time mode */
    typedef enum ezwMotDriverTimeMode
    {
        ZW_MOT_DRIVER_TIME_USER,    /* use user-defined start/end time */
        ZW_MOT_DRIVER_TIME_DEFAULT, /* use solution start/end time */
    } ezwMotDriverTimeMode;

    /* the solution setting type */
    typedef enum ezwMotSolutionSettingType
    {
        ZW_MOT_SOLUTION_SETTING_TIME_FREQUENCY,   /* time and frame frequency */
        ZW_MOT_SOLUTION_SETTING_TIME_FRAMES,      /* time and total frames */
        ZW_MOT_SOLUTION_SETTING_FREQUENCY_FRAMES, /* frame frequency and total frames */
    } ezwMotSolutionSettingType;

    /* the solution solve status */
    typedef enum ezwMotSolutionSolveStatus
    {
        ZW_MOT_SOLUTION_SOLVED,                   /* successfully solved */
        ZW_MOT_SOLUTION_SOLVE_PARTIAL,            /* partially solved */
        ZW_MOT_SOLUTION_SOLVE_FAILED,             /* solved failed */
        ZW_MOT_SOLUTION_SOLVE_FAILED_PRE_PROCESS, /* process failed before solve */
    } ezwMotSolutionSolveStatus;

    /* motion body data */
    typedef struct szwMotBody
    {
        int idEntity;                     /* entity id */
        int iFix;                         /* fix status */
        ezwMotBodyCenterType eCenterType; /* body center type */
        szwPoint vecCenter;               /* body center */
    } szwMotBody;

    /* basic joint data */
    typedef struct szwMotBasicJoint
    {
        int idActiveBody;           /* id of active body */
        svxMatrix matActiveBody;    /* matrix of active body */
        int idBasicBody;            /* id of basic body */
        svxMatrix matBasicBody;     /* matrix of basic body */
        int iExcludeConstraints[6]; /* the array of constraints to exclude */
        double dUpperLimit;         /* upper limit of joint(revolute/slider) */
        double dLowerLimit;         /* lower limit of joint(revolute/slider) */
        double dScrewPitch;         /* pitch of screw joint. other type joints is invalid */
    } szwMotBasicJoint;

    /* constraint joint data */
    typedef struct szwMotConstraintJoint
    {
        int idBody1;                     /* id of first associated body */
        int countEntity1;                /* select entities count of the first body*/
        szwEntityHandle *entityHandles1; /* select entities of the first body*/
        int idBody2;                     /* id of second associated body */
        int countEntity2;                /* select entities count of the second body*/
        szwEntityHandle *entityHandles2; /* select entities of the second body*/
        int iLockSlip;                   /* scroll or slide for curve-curve joint */
    } szwMotConstraintJoint;

    /* coupler joint data */
    typedef struct szwMotCouplerJoint
    {
        int idJoint1;  /* id of first associated joint */
        int idJoint2;  /* id of second associated joint */
        int idJoint3;  /* id of third associated joint */
        double dGear1; /* ratio or radius */
        double dGear2; /* ratio or radius */
    } szwMotCouplerJoint;

    /* motion joint data */
    typedef struct szwMotJoint
    {
        int idEntity;                  /* id of joint */
        ezwMotJointType eType;         /* joint type */
        ezwMotJointSubClass eSubClass; /* joint sub class */
        union uzwMotJointData
        {
            szwMotBasicJoint zBasic;           /* basic joint data */
            szwMotConstraintJoint zConstraint; /* constraint joint data */
            szwMotCouplerJoint zCoupler;       /* coupler joint data */
        } data;
    } szwMotJoint;

    /* motion driver data */
    typedef struct szwMotDriver
    {
        int idEntity;                           /* id of driver */
        int idJoint;                            /* id of associated joint */
        ezwMotDriverType eType;                 /* driver type */
        ezwMotDriverFunctionType eFunctionType; /* driver function type */
        zwString1024 sFunctionExpression;       /* expression of driver function */
        double dParameter[6];                   /* parameters of driver function. A,B,C,D,L,T */
        double dInitPosition;                   /* initial position */
        double dInitVelocity;                   /* initial velocity */
        zwPath sFittedFile;                     /* fitted external file path */
        ezwMotDriverFittedMethod eFittedMethod; /* fitted method */
    } szwMotDriver;

    /* motion driver time data */
    typedef struct szwMotDriverTime
    {
        int idDriver;                    /* id of driver */
        ezwMotDriverTimeMode iStartMode; /* start time mode */
        double dStartTime;               /* start time */
        ezwMotDriverTimeMode iEndMode;   /* end time mode */
        double dEndTime;                 /* end time */
    } szwMotDriverTime;

    /* motion solution data */
    typedef struct szwMotSolution
    {
        int idEntity;                           /* id of solution */
        ezwMotSolutionType eType;               /* solution analysis type */
        ezwMotSolutionSettingType eSettingType; /* solution setting type */
        int iFrameFrequency;                    /* frame frequency */
        int iTotalFrames;                       /* total frames */
        double dStartTime;                      /* start time, always 0 */
        double dEndTime;                        /* end time */
    } szwMotSolution;

    /* entity result of one frame */
    typedef struct szwMotEntityResult
    {
        int idEntity;                 /* id of entity */
        szwVector zPosition;          /* position */
        szwVector zVelocity;          /* velocity */
        szwVector zAcceleration;      /* acceleration */
        szwVector zEulerAngle;        /* Euler angle */
        szwVector zAngleVelocity;     /* angle velocity */
        szwVector zAngleAcceleration; /* angle acceleration */
        svxMatrix mat;                /* entity transformation matrix */
    } szwMotEntityResult;

    /* motion solve result of one frame */
    typedef struct szwMotFrameResult
    {
        double dTime;                     /* frame time */
        int countBody;                    /* body result count */
        szwMotEntityResult *zBodyResult;  /* all body results of this frame */
        int countJoint;                   /* joint result count */
        szwMotEntityResult *zJointResult; /* all joint results of this frame */
    } szwMotFrameResult;

    /*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_MOTION_DATA_H */