/**
@file zwapi_global_apply_data.h
@copyright (C) Copyright 2023, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Data Types and Structures of Global Tools functions.
*/

#pragma once
#ifndef ZW_API_GLOBAL_APPLY_DATA_H
#define ZW_API_GLOBAL_APPLY_DATA_H

#include "zwapi_util.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Plugin Data */
    //====================================================================================================================
    /**
    @brief plugin data
    @ingroup ZwGlobalApplicationData
    */
    typedef struct szwPluginData
    {
        zwString256 applicationName; /**<@brief  name of plugin */
        zwString256 libraryName;     /**<@brief  library file name */
        zwPath libraryDirectory;     /**<@brief  absolute path of library directory */
        zwPath resourceFilePath;     /**<@brief  resource file(zrc or rcc) path, it should be an absolute path */
        zwString512 description;     /**<@brief  description of plugin */
    } szwPluginData;


    //====================================================================================================================
    /** @name Application Reactor Data */
    //====================================================================================================================
    /**
    @brief The type of application reactor
    @ingroup ZwGlobalApplicationData
    */
    typedef enum ezwApplicationReactorType
    {
        ZW_APPLICATION_PRECLOSE = 0, /**<@brief  called before process quits */
        ZW_APPLICATION_STARTED,      /**<@brief  called after process started (notify only) */
    } ezwApplicationReactorType;

    /**
    @brief The structure for application reactor
    @ingroup ZwGlobalApplicationData
    */
    typedef struct szwApplicationReactorData
    {
        zwString256 uniqueName;        /**<@brief  unique name to label the callback function */
        int (*callbackFunction)(void); /**<@brief  callback function. This parameter should be a valid function pointer
                                                       when adding it to the application reactor. And to delete the callback, it
                                                       should be NULL and use the same unique name. */
    } szwApplicationReactorData;

    //====================================================================================================================
    /** @name Document Reactor Data */
    //====================================================================================================================
    /**
    @brief The type of document reactor
    @ingroup ZwGlobalApplicationData
    */
    typedef enum ezwDocumentReactorType
    {
        ZW_DOCUMENT_CREATED = 0,   /**<@brief  called after file created (notify only) */
        ZW_DOCUMENT_SAVING,        /**<@brief  called before file saving */
        ZW_DOCUMENT_SAVED,         /**<@brief  called after file saved (notify only) */
        ZW_DOCUMENT_TAB_PRECHANGE, /**<@brief  called before file tab changes to another one (notify only) */
        ZW_DOCUMENT_TAB_CHANGED,   /**<@brief  called after tab changed to another one (notify only) */
        ZW_DOCUMENT_PREOPEN,       /**<@brief  called before file open */
        ZW_DOCUMENT_OPENED,        /**<@brief  called after file opened (notify only) */
        ZW_DOCUMENT_TITLEUPDATE,   /**<@brief  called before the window title updating after file changed (notify only) */
        ZW_DOCUMENT_PREMODIFY,     /**<@brief  called before file modifies */
        ZW_DOCUMENT_MODIFIED,      /**<@brief  called after file modified (notify only) */
        ZW_DOCUMENT_LOADED,        /**<@brief  called after file loaded to the memory (notify only) */
        ZW_DOCUMENT_PRECLOSE,      /**<@brief  called before file closes, the result will not take affect when using 'Close all' command */
        ZW_DOCUMENT_CLOSED,        /**<@brief  called after file closed (notify only) */
    } ezwDocumentReactorType;

    /**
    @brief The structure for document reactor
    @ingroup ZwGlobalApplicationData
    */
    typedef struct szwDocumentReactorData
    {
        zwString256 uniqueName;                              /**<@brief  unique name to label the callback function */
        int (*callbackFunction)(const char *, const char *); /**<@brief  callback function. This parameter should be a valid function pointer
                                                                             when adding it to the document reactor. And to delete the callback,
                                                                             it should be NULL and use the same unique name. */
    } szwDocumentReactorData;

    /**
    @brief The data for document to update the associate file list
    @ingroup ZwGlobalApplicationData
    */
    typedef struct szwDocumentUpdateData
    {
        int count;               /**<@brief count of associate files to update of the opening file */
        zwPath *oldFileList;     /**<@brief the file name list need to be updated of the the opening file, the objects num should be same as 'count' */
        zwPath *newFileList;     /**<@brief the new file name list of the the opening file, the objects num should be same as 'count' */
        zwRootName *oldRootList; /**<@brief the root name list need to be updated, they should match the 'oldFileList', NULL to ignore */
        zwRootName *newRootList; /**<@brief the new root name list, they should match the 'newFileList', NULL to ignore */
    } szwDocumentUpdateData;


    //====================================================================================================================
    /** @name Environment Reactor Data */
    //====================================================================================================================

    /**
    @brief The type of environment reactor
    @ingroup ZwGlobalApplicationData
    */
    typedef enum ezwEnvironmentType
    {
        ZW_ENVIRONMENT_START_UP = 0,      /**<@brief the environment with no open files */
        ZW_ENVIRONMENT_ROOT,              /**<@brief root environment of Z3 files */
        ZW_ENVIRONMENT_PART_AND_ASSEMBLY, /**<@brief Part/Assembly environment of Z3 files */
        ZW_ENVIRONMENT_SKETCH,            /**<@brief sketch environment of Z3/Z3SKH files */
        ZW_ENVIRONMENT_DRAWING,           /**<@brief drawing environment of Z3/Z3DRW files */
        ZW_ENVIRONMENT_CAM = 6,           /**<@brief CAM environment of Z3/Z3CAM files */
        ZW_ENVIRONMENT_ANIMATION,         /**<@brief animation environment */
        ZW_ENVIRONMENT_EXPLODED_VIEW,     /**<@brief exploded view environment */
        ZW_ENVIRONMENT_SKETCH_3D,         /**<@brief 3D sketch environment */
        ZW_ENVIRONMENT_PART,              /**<@brief part environment of Z3PRT files */
        ZW_ENVIRONMENT_ECAD_ASSEMBLY,     /**<@brief ECAD assembly environment of Z3ASM files */
        ZW_ENVIRONMENT_ECAD_PART,         /**<@brief ECAD part environment of Z3PRT files */
        ZW_ENVIRONMENT_ASSEMBLY,          /**<@brief assembly environment of Z3ASM files */
        ZW_ENVIRONMENT_PIPING,            /**<@brief piping environment of Z3ASM files */
        ZW_ENVIRONMENT_HARNESS_ASSEMBLY,  /**<@brief harness assembly environment of Z3ASM files */
        ZW_ENVIRONMENT_HARNESS_PART,      /**<@brief harness assembly environment of Z3PRT files */
        ZW_ENVIRONMENT_MASTER_LAYOUT,     /**<@brief master layout part environment of Z3PRT files  */
        ZW_ENVIRONMENT_MOTION,            /**<@brief motion environment of Z3MDS files */
    } ezwGuiReactorType;

    /**
    @brief The structure for environment reactor
    @ingroup ZwGlobalApplicationData
    */
    typedef struct szwEnvironmentReactorData
    {
        zwString256 uniqueName;                       /**<@brief  unique name to label the callback function */
        void (*callbackFunction)(ezwEnvironmentType); /**<@brief  callback function. This parameter should be a valid function pointer
                                                                      when adding it to the environment reactor. And to delete the callback,
                                                                      it should be NULL and use the same unique name. */
    } szwEnvironmentReactorData;

    //====================================================================================================================
    /** @name Units System */
    //====================================================================================================================
    /**
    @brief Preference number class
    @ingroup ZwGlobalApplicationData
    */
    typedef enum ezwNumberClass
    {
        ZW_UNDEFINED                       = 0,   /**<@brief undefined */
        ZW_DIMENSIONTLESS_NUMBER           = 1,   /**<@brief dimensionless number (e.g. curve degree) */
        ZW_UNIT_DSTANCE                    = 2,   /**<@brief distance                                      [mm] */
        ZW_UNIT_ANGLE                      = 3,   /**<@brief angle                                         [deg] */
        ZW_UNIT_MASS                       = 4,   /**<@brief mass                                          [kg] */
        ZW_UNIT_DENSITY                    = 5,   /**<@brief density                                       [kg/mm^3] */
        ZW_UNIT_AREA                       = 6,   /**<@brief area                                          [m^2] */
        ZW_UNIT_VOLUME                     = 7,   /**<@brief volume                                        [m^3] */
        ZW_UNIT_MASS_MOMENT                = 8,   /**<@brief mass moment of interia                        [kg*mm^2] */
        ZW_UNIT_TIME                       = 9,   /**<@brief time                                          [s] */
        ZW_UNIT_PER_TIME                   = 10,  /**<@brief coefficient per unit time                     [1/s] */
        ZW_UNIT_PER_TIME_SQUARED           = 11,  /**<@brief coefficient per unit time squared             [1/s^2] */
        ZW_UNIT_PER_TIME_CUBED             = 12,  /**<@brief coefficient per unit time cubed               [1/s^3] */
        ZW_UNIT_FREQUENCY                  = 13,  /**<@brief frequency                                     [Hz] */
        ZW_UNIT_PER_FREQUENCY              = 14,  /**<@brief per frequency                                 [1/Hz] */
        ZW_UNIT_VELOCITY                   = 15,  /**<@brief velocity                                      [m/s] */
        ZW_UNIT_ACCELERATION               = 16,  /**<@brief acceleration                                  [m/s^2] */
        ZW_UNIT_JERK                       = 17,  /**<@brief jerk                                          [m/s^3] */
        ZW_UNIT_ANGULAR_VELOCITY           = 18,  /**<@brief angular velocity                              [deg/s] */
        ZW_UNIT_ANGULAR_ACCELERATION       = 19,  /**<@brief angular acceleration                          [rad/s^2] */
        ZW_UNIT_ANGULAR_JERK               = 20,  /**<@brief angular jerk                                  [rad/s^3] */
        ZW_UNIT_LEN_PER_ANG                = 21,  /**<@brief length per angle                              [m/deg] */
        ZW_UNIT_FORCE                      = 22,  /**<@brief force                                         [N] */
        ZW_UNIT_FORCE_PER_ANG              = 23,  /**<@brief force per unit angle                          [N/deg] */
        ZW_UNIT_MOMENT                     = 24,  /**<@brief moment                                        [N*m] */
        ZW_UNIT_MOMENT_PER_ANG             = 25,  /**<@brief moment per angle                              [N*m/deg] */
        ZW_UNIT_SPRING_CONSTANT            = 26,  /**<@brief spring constant                               [N/m] */
        ZW_UNIT_PRESSURE                   = 27,  /**<@brief stress or pressure,                           [kPa] */
        ZW_UNIT_STRESS_COMPLIANCE          = 28,  /**<@brief stress compliance                             [1/kPa] */
        ZW_UNIT_DYNAMIC_VISCOSITY          = 29,  /**<@brief dynamic viscosity                             [N*s/mm^2, kg/(mm*s), Pa*s] */
        ZW_UNIT_SPECIFIC_WEIGHT            = 30,  /**<@brief specific weight                               [N/m^3] */
        ZW_UNIT_PRESSURE_PER_VELOCITY      = 31,  /**<@brief pressure per velocity or mass flux            [N*s/m^3, kg/(m^2*s)] */
        ZW_UNIT_STATIC_FLOW_RESISTIVITY    = 32,  /**<@brief static flow resistivity,                      [N*s/m^4] */
        ZW_UNIT_LEN_PER_PRESSURE           = 33,  /**<@brief length per unit pressure                      [m^3/N] */
        ZW_UNIT_VELOCITY_PER_PRESSURE      = 34,  /**<@brief velocity per pressure                         [m^3/(N*s)] */
        ZW_UNIT_TSAI_WU_COEFF              = 35,  /**<@brief Tsai-Wu coefficient                           [m^4/N^2] */
        ZW_UNIT_VISCOUS_DAMPING            = 36,  /**<@brief viscous damping or mass flow rate             [kg/s, N*s/m] */
        ZW_UNIT_MASS_LEN                   = 37,  /**<@brief mass length                                   [kg*m] */
        ZW_UNIT_MOMENTUM                   = 38,  /**<@brief momentum                                      [kg*m/s] */
        ZW_UNIT_ANGULAR_MOMENTUM           = 39,  /**<@brief angular momentum                              [N*m*s] */
        ZW_UNIT_ANGULAR_MOMENTUM_PER_ANG   = 40,  /**<@brief angular momentum per angle                    [N*m*s/deg] */
        ZW_UNIT_MASS_PER_LEN               = 41,  /**<@brief mass per length                               [kg/m] */
        ZW_UNIT_MASS_PER_AREA              = 42,  /**<@brief mass per area                                 [kg/m^2] */
        ZW_UNIT_PER_LEN                    = 43,  /**<@brief unit per length                               [1/m]*/
        ZW_UNIT_PER_AREA                   = 44,  /**<@brief unit per area                                 [1/m^2] */
        ZW_UNIT_PER_VOLUME                 = 45,  /**<@brief unit per volume                               [1/m^3] */
        ZW_UNIT_DIFFUSIVITY                = 46,  /**<@brief diffusivity                                   [m^2/s] */
        ZW_UNIT_ENERGY_PER_MASS            = 47,  /**<@brief energy per mass                               [m^2/s^2] */
        ZW_UNIT_DISSI_RATE_ENERGY_PER_MASS = 48,  /**<@brief dissipation rate of energy per mass           [m^2/s^3] */
        ZW_UNIT_VOLUME_FLOW_RATE           = 49,  /**<@brief volume flow rate                              [m^3/s] */
        ZW_UNIT_MOMENT_OF_INTERIA          = 50,  /**<@brief moment of interia                             [m^4] */
        ZW_UNIT_WARPING_CONSTANT           = 51,  /**<@brief warping constant                              [m^6] */
        ZW_UNIT_TEMPERATURE                = 52,  /**<@brief temperature, Degree Celsius                   [℃] */
        ZW_UNIT_TEMPERATURE_DIFFERENCE     = 53,  /**<@brief temperature difference                        [dC] */
        ZW_UNIT_THERMAL_EXPANSION_COEFF    = 54,  /**<@brief thermal expansion coefficient                 [1/dC] */
        ZW_UNIT_TEMPERATURE_GRADIENT       = 55,  /**<@brief temperature gradient                          [dC/m] */
        ZW_UNIT_THERMAL_PID_INT_CONSTANT   = 56,  /**<@brief thermal PID integral term constant            [1/(dC*s)] */
        ZW_UNIT_THERMAL_PID_DERI_CONSTANT  = 57,  /**<@brief thermal PID derivative term constant          [s/dC] */
        ZW_UNIT_TEMPERATUR_CHANGE_RATE     = 58,  /**<@brief temperature change rate                       [dC/s] */
        ZW_UNIT_POWER                      = 59,  /**<@brief power or heat flow rate                       [W] */
        ZW_UNIT_HEAT_FLUX                  = 60,  /**<@brief heat flux                                     [W/m^2] */
        ZW_UNIT_HEAT_GENERATION_RATE       = 61,  /**<@brief heat generation rate                          [W/m^3] */
        ZW_UNIT_THERMAL_CONDUCTANCE        = 62,  /**<@brief thermal conductance                           [W/dC] */
        ZW_UNIT_THERMAL_CONDUCTIVITY       = 63,  /**<@brief thermal conductivity or conductance per length[W/(m*dC] */
        ZW_UNIT_HEAT_FLUX_COEFF            = 64,  /**<@brief heat flux coefficient                         [W/(m^2*dC] */
        ZW_UNIT_THERMAL_RESISTANCE         = 65,  /**<@brief thermal resistance                            [dC/W] */
        ZW_UNIT_ENERGY                     = 66,  /**<@brief energy                                        [J] */
        ZW_UNIT_LATENT_HEAT_PER_MASS       = 67,  /**<@brief latent heat per mass                          [J/kg] */
        ZW_UNIT_SPECIFIC_HEAT_CAPACITY     = 68,  /**<@brief specific heat capacity                        [J/(kg*dC)]*/
        ZW_UNIT_THERMAL_ENERGY_PER_AREA    = 69,  /**<@brief thermal energy per area                       [J/m^2] */
        ZW_UNIT_THERMAL_ENERGY_DENSITY     = 70,  /**<@brief thermal energy density                        [J/m^3] */
        ZW_UNIT_THERMAL_CAPACITANCE        = 71,  /**<@brief thermal capacitance                           [J/dC] */
        ZW_UNIT_ELECTRIC_CURRENT           = 72,  /**<@brief electric current                              [A] */
        ZW_UNIT_ELECTRIC_RESISTANCE        = 73,  /**<@brief electric resistance                           [ohm] */
        ZW_UNIT_ELECTRIC_RESISTIVITY       = 74,  /**<@brief electric resistivity                          [ohm*m] */
        ZW_UNIT_ELECTRIC_CONDUCTANCE       = 75,  /**<@brief electric conductance                          [S] */
        ZW_UNIT_ELECTRIC_BULK_CONDUCTIVITY = 76,  /**<@brief electric bulk conductivity                    [S/m] */
        ZW_UNIT_VOLTAGE                    = 77,  /**<@brief voltage                                       [V] */
        ZW_UNIT_VOLTAGE_PER_TEMPERATURE    = 78,  /**<@brief voltage per temperature                       [V/dC] */
        ZW_UNIT_ELECTRIC_INDUCTANCE        = 79,  /**<@brief electric inductance                           [H] */
        ZW_UNIT_VOLTAGE_PER_ANGULAR_VELO   = 80,  /**<@brief voltage per angular velocity                  [V*s/rad] */
        ZW_UNIT_MAGNETIC_FLUX              = 81,  /**<@brief magnetic                                      [Wb] */
        ZW_UNIT_MAGNETIC_FLUX_DENSITY      = 82,  /**<@brief magnetic density                              [T] */
        ZW_UNIT_MAGNETIC_FIELD_STRENGTH    = 83,  /**<@brief magnetic field strength                       [A/m] */
        ZW_UNIT_CURRENT_DENSITY_AREA       = 84,  /**<@brief current density area                          [A/m^2] */
        ZW_UNIT_CURRENT_DENSITY            = 85,  /**<@brief current density                               [A/m^3] */
        ZW_UNIT_ELECTRIC_FIELD_STRENGTH    = 86,  /**<@brief electric field strength                       [V/m] */
        ZW_UNIT_ELECTRIC_CHARGE            = 87,  /**<@brief electric charge                               [C, A*s] */
        ZW_UNIT_ELECTRIC_FLUX_DENSITY      = 88,  /**<@brief electric flux density                         [A*s/m^2] */
        ZW_UNIT_BODY_CHARGE_DENSITY        = 89,  /**<@brief body charge density                           [A*s/m^3] */
        ZW_UNIT_ELECTRIC_CAPACITANCE       = 90,  /**<@brief electric capacitance                          [F] */
        ZW_UNIT_SOLID_ANGLE                = 91,  /**<@brief solid angle                                   [sr] */
        ZW_UNIT_LUMINOUS_INTENSITY         = 92,  /**<@brief luminous intensity                            [cd] */
        ZW_UNIT_LUMINOUS_FLUX              = 93,  /**<@brief luminous flux                                 [lm] */
        ZW_UNIT_LUMINANCE                  = 94,  /**<@brief luminance                                     [cd/m^2] */
        ZW_UNIT_ILLUMINANCE                = 95,  /**<@brief illuminance                                   [lx] */
        ZW_UNIT_AMOUNT_OF_SUBSTANCE        = 96,  /**<@brief amount of substance                           [mol] */
        ZW_UNIT_MOLALITY                   = 97,  /**<@brief molality                                      [mol/kg] */
        ZW_UNIT_MOLAR_CONCENTRATION        = 98,  /**<@brief molar concentration                           [mol/m^3] */
        ZW_UNIT_MOLAR_MASS                 = 99,  /**<@brief molar mass                                    [kg/mol] */
        ZW_UNIT_CURRENCY                   = 100, /**<@brief currency                                      [$] */
        ZW_UNIT_MAGNETIC_VECTOR_POTENTIAL  = 101, /**<@brief magnetic vector potential                     [Wb/m] */
        ZW_UNIT_LINE_CHARGE_DENSITY        = 102, /**<@brief line charge density                           [A*s/m] */
        ZW_NUMBER_CLASS_MAX
    } ezwNumberClass;

    /**
    @brief Unit information
    @ingroup ZwGlobalApplicationData
    */
    typedef struct szwUnitInformation
    {
        ezwNumberClass unitClass; /**<@brief the class of unit */
        zwString64 unitName;      /**<@brief the name of unit */
    } szwUnitInformation;


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif // !ZW_API_GLOBAL_APPLY_DATA_H
