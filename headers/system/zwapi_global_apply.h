/**
@file zwapi_global_apply.h
@copyright (C) Copyright 2022, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Global Tools API
*/
/**
@defgroup zwapi_global_apply Global Apply
@ingroup CommonModel
@brief
@details THE MODULE FOR THE ZW3D Global Tools API
*/

#pragma once
#ifndef ZW_API_GLOBAL_APPLY_H /* this ifndef surrounds entire header */
#define ZW_API_GLOBAL_APPLY_H

#include "zwapi_global_apply_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Global Apply Data */
    //====================================================================================================================
    /**
    @brief part dimension attribute
    @ingroup zwapi_global_apply
    */
    typedef struct svxPartDimAttr
    {
        evxColor color; /**<@brief  color of dimension */
        int decimal;    /**<@brief  number of decimal places of dimension (0 ~ 5) */
    } svxPartDimAttr;

    /**
    @brief global settings
    @ingroup zwapi_global_apply
    */
    typedef enum evxGlobal
    {
        VX_TOLERANCE        = 1, /**<@brief  proximity tolerance (double) */
        VX_AUTO_MERGE       = 2, /**<@brief  1=auto-merge shells before boolean (int) */
        VX_EXACT_MATCH      = 3, /**<@brief  1=exact label matching enabled; 0=disabled (int) */
        VX_LOCALCOORDIDX    = 4, /**<@brief  Local coordinate */
        VX_CONS_DELAY_SOLVE = 5, /**<@brief  1-delay solve the constraint (int) */
        VX_DIM_ATTR         = 6, /**<@brief  part dimension attribute (svxPartDimAttr) */
    } evxGlobal;

    //====================================================================================================================
    /** @name App Action Data */
    //====================================================================================================================
    /**
    @brief application action type
    @see ezwApplicationReactorType
    @ingroup zwapi_global_apply
    */
    typedef enum _evxAppAction
    {
        VX_APP_PRECLOSE = 0, /**<@brief  called before process quit */
        VX_APP_STARTED       /**<@brief  called after process start (notify only) */
    } evxAppAction;

    /**
    @brief application action parameter
    @see szwApplicationReactorData
    @ingroup zwapi_global_apply
    */
    typedef struct _svxAppActionParam
    {
        int (*pfn)(void *param); /**<@brief  callback function */
        void *param;             /**<@brief  parameter */
    } svxAppActionParam;

    //====================================================================================================================
    /** @name Global Apply */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    Retrieves the value of the specified setting.
    To accommodate different data types, "Data" is a void pointer.
    Make sure it references the appropriate storage type.  Look at
    "enum evxGlobal" to see what type of storage is required for each
    setting.

    @param [in] Global global setting to modify
    @param [out] Data data to assign to global setting

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxGlobalGet(evxGlobal Global, void *Data);

    /**
    @ingroup zwapi_global_apply

    Assigns the specified data to the specified setting.
    To accommodate different data types, "Data" is a void pointer.
    Make sure it references the appropriate data type.  Look at
    "enum evxGlobal" to see what type of data is required for each
    setting.

    Be careful using this function to change global settings.  It is only
    meant for temporary modification of a setting while an API function is
    executing.   Always restore the original setting when your function is
    done.

    @param [in] Global global setting to modify
    @param [in] Data data to assign to global setting

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxGlobalSet(evxGlobal Global, void *Data);

    /**
    @ingroup zwapi_global_apply

    Retrieves the "Notes" associated with the active root
    object (or the active file if no root is active) and
    outputs them via "Notes".   The memory referenced by
    "Note" is allocated by this function and must be
    deallocated by the calling procedure.

    If there are not any notes, no memory is allocated
    by this function, and "*Note" is set to NULL.

    @param [out] Note null-terminated text string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxNoteGet(char **Note);

    /**
    @ingroup zwapi_global_apply

    Assigns the specified text to the "Notes" associated
    with the active root object -- or to the active file
    there is not an active root object.

    @param [in] Note null-terminated text string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C evxErrors cvxNoteSet(char *Note);

    /**
    @ingroup zwapi_global_apply

    Gets the status of part "auto regen" (1=ON; 0=OFF).

    @param [out] Status 1 if "auto regen" is ON; 0 if OFF

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxAutoRegenGet(int *Status);

    /**
    @ingroup zwapi_global_apply

    Sets the status of part "auto regen" (1=ON; 0=OFF).
    @param [in] Status 1 if "auto regen" is ON; 0 if OFF

    */
    ZW_API_C void cvxAutoRegenSet(int Status);

    /**
    @ingroup zwapi_global_apply

    Outputs the name of the active language used in ZW3D currently.

    @param [out] Language name of active language

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxLangGet(vxName Language);

    /**
    @ingroup zwapi_global_apply

    Map the zw3d font name to the general font.

    Such as:                                   
    -       "ZW3D Simplex" - "simplex";         
    -       "ZW3D Simplex Roman" - "romans";    
    -       "ZW3D Complex Roman" - "romanc";    
    -       "ZW3D Duplex Roman" - "romand";     
    -       "ZW3D Triplex Roman" - "romant";    
    -       "ZW3D Simplex Script" - "scripts";  
    -       "ZW3D Complex Script" - "scriptc";  
    -       "ZW3D Simplex Greek" - "greeks";    
    -       "ZW3D Complex Greek" - "greekc";    
    -       "ZW3D Gothic German" - "gothicg";   
    -       "ZW3D Gothic Italian" - "gothici";  
    -       "ZW3D Gothic English" - "gothice";  
    -       "ZW3D Complex Italics" - "italicc"; 
    -       "ZW3D Triplex Italics" - "italict"; 
    -       "宋体" - "SimSun";

    @param [in] zw3dFont font name of zw3d
    @param [out] mapFont mapped font name

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxFontMap(const char *zw3dFont, vxLongName mapFont);


    //====================================================================================================================
    /** @name Unit */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    Outputs an integer id that identifies the active user units for linear
    measure (0-microns, 1-millimeters, 2-centimeters, 3-meters, 4-inches, 5-feet).

    If "Name" is not NULL, it is used to output an abbreviation for the name
    of the active units.

    @param [out] Type active linear units type
    @param [out] Name abbreviation for active units (NULL to ignore)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxUnitGet(evxUnitType *Type, vxName Name);

    /**
    @ingroup zwapi_global_apply

    Get the unit type and sub type for the specified unit string .

    @param [in] unit_str the string of unit
    @param [out] sub_type the string of sub type,0/1/2:Constant/Length/Angle
    @param [out] unit_type the string of unit type,Length(1~9):mic/mm/cm/dm/m/mil/in/ft/yd;Angle(1~2):radians/degrees

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxUnitTypeGet(char *unit_str, char *sub_type, char *unit_type);

    /**
    @ingroup zwapi_global_apply

    Sets the active user units for linear measure based on the input "Type"
    (0-microns, 1-millimeters, 2-centimeters, 3-meters, 4-inches, 5-feet).

    @param [in] Type linear unit type

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C void cvxUnitSet(evxUnitType Type);

    /**
    @ingroup zwapi_global_apply

    Converts specified distance from the active user units
    to system units (millimeters).

    @param [in,out] Distance distance

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxUnitToSys(double *Distance);

    /**
    @ingroup zwapi_global_apply

    Converts the specified distance from system units (millimeters)
    to the active user units.

    @param [in,out] Distance distance

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxUnitToUser(double *Distance);

    /**
    @ingroup zwapi_global_apply

    Outputs an integer id that identifies the active user units for linear measure.

    If "name" is not NULL, it is used to output an abbreviation for the name
    of the active units.

    @param [out] type active mass units type
    @param [out] name abbreviation for active mass units (NULL to ignore)

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C evxErrors cvxUnitMassGet(evxMassUnitType *type, vxName name);

    /**
    @ingroup zwapi_global_apply

    Sets the active user units for mass measure based on the input "type".

    @param [in] type mass unit type

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxUnitMassSet(evxMassUnitType type);


    //====================================================================================================================
    /** @name Sketch Grid Spacing */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    Output grid spacing.

    @param [out] spacing grid spacing

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_GET_ERROR
    */
    ZW_API_C evxErrors cvxSkGridSpacingGet(double *spacing);

    /**
    @ingroup zwapi_global_apply

    Set grid spacing.

    @param [in] spacing grid spacing

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OBJ_DATA_SET_ERROR
    */
    ZW_API_C evxErrors cvxSkGridSpacingSet(double spacing);


    //====================================================================================================================
    /** @name Color Utilities */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    This function copies the input svxColorf structure, in which the color
    components are floating point values defined over 0.0 to 1.0, to the
    output svxColor structure, where the color component values are
    defined over 0 to 255.

    @see cvxColorToColorf() to copy svxColor to svxColorf.

    @param [in] rgbf input color (each float component defined over 0.0 to 1.0)
    @param [out] rgb output color (each component defined over 0 to 255)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxColorfToColor(const svxColorf *rgbf, svxColor *rgb);

    /**
    @ingroup zwapi_global_apply

    This function copies the input svxColor structure, in which the color
    component values are defined over 0 to 255, to the output svxColorf
    structure, where the color components are floating point values
    defined over 0.0 to 1.0.

    @see cvxColorfToColor() to copy svxColorf to svxColor.

    @param [in] rgb input color (each component defined over 0 to 255)
    @param [out] rgbf output color (each float component defined over 0.0 to 1.0)

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C void cvxColorToColorf(const svxColor *rgb, svxColorf *rgbf);

    /**
    @ingroup zwapi_global_apply

    Output the RGB components of a standard color or an index color.

    @see cvxColorNear() for a function that finds the evxColor value of the
    nearest standard color when given a color's RGB components.

    @param [in] color one of the evxColor values for a standard color or an index color
    @param [out] rgb RGB components for the input color

    @retval succeeds
    -        ZW_API_NO_ERROR - if the input is an unambiguous color, as defined by the evxColor type.
    @retval fail
    -        ZW_API_GENERAL_ERROR - if the input is not a valid evxColor value or is ambiguous
    -                               (VX_COLOR_NULL or VX_COLOR_RGB). The output will be black.
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxColorRGB(evxColor color, svxColor *rgb);

    /**
    @ingroup zwapi_global_apply

    This function returns the color defined by evxColor type that is the
    nearest match to the input RGB components.  The return value is never
    VX_COLOR_NULL or VX_COLOR_RGB.

    @see cvxColorRGB() for a function that outputs RGB components when given
    a standard color's evxColor value.
    @param [in] rgb RGB components of a color to match to a standard color or an index color

    */
    ZW_API_C evxColor cvxColorNear(const svxColor *rgb);


    //====================================================================================================================
    /** @name Escape Checking */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    When escape checking has been enabled using cvxEscStart(), this function
    returns a non-zero value if the user has pressed the <Esc> key or other
    menu item that generates and "Escape" event with the intention of terminating
    execution of the active command. 

    If no "Escape" event has been triggered
    by the user, this function returns 0.

    */
    ZW_API_C int cvxEscCheck(void);

    /**
    @ingroup zwapi_global_apply

    Disables checking for "Escape" events overriding cvxEscStart().
    This function MUST ALWAYS be paired with a subsequent call to cvxEscRestore().
    The "integer" value output by this function (EscapeState) must be passed to
    the corresponding call to cvxEscRestore().
    @param [out] EscapeState current escape checking state

    */
    ZW_API_C void cvxEscDisable(int *EscapeState);

    /**
    @ingroup zwapi_global_apply

    Re-enables checking for "Escape" events after cvxEscDisable() has been called.
    "EscapeState" should be the value output by a previous call to cvxEscDisable().
    This function MUST ALWAYS be paired with a prior call to cvxEscDisable().
    @param [in] EscapeState original escape checking state

    */
    ZW_API_C void cvxEscRestore(int EscapeState);

    /**
    @ingroup zwapi_global_apply

    This function is used to start "Escape" checking, whereby execution of
    a command is aborted if the user presses the <Esc> button or other menu
    item that generates an "Escape" event.  This presumes that the currently
    executing code is calling cvxEscCheck() periodically to allow escape
    events to be processed.

    THE CALLING PROCEDURE MUST PAIR A CALL TO cvxEscStart() WITH A SUBSEQUENT
    CALL TO cvxEscEnd().

    You should put escape checking in a callback function or other code that
    could take a long time to execute, but that you want to abort if the user
    tries to initiate a new input or action through the user interface. Put
    cvxEscStart() at the beginning of your function and cvxEscEnd() at the end.
    Add calls to cvxEscCheck() between cvxEscStart() and cvxEscEnd(). If a call
    to cvxEscCheck() returns a non-zero value, clean up whatever your function
    has started (including all dynamically allocated memory), call cvxEscEnd()
    and exit your function.

    */
    ZW_API_C void cvxEscStart(void);

    /**
    @ingroup zwapi_global_apply

    This function is used to end "Escape" checking after it has been
    previously initialized with CdEscStart().  Calls to CdEscStart()
    MUST ALWAYS be paired with a call to CdEscEnd().

    */
    ZW_API_C void cvxEscEnd(void);


    //====================================================================================================================
    /** @name Version */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    Returns the active ZW3D version number as an integer (one-hundreths).
    If "vxStatus" is not NULL, a string describing the version is output
    that indicates whether it is Alpha or Beta along with a revision
    number.  If "vxStatus" is not NULL, it should point to at least 80
    bytes of memory.

    @param [out] vxStatus status

    @retval return
    -        the active ZW3D version number as an integer
    @warning
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C int cvxVersion(char *vxStatus);

    /**
    @ingroup zwapi_global_apply

    Get version number string of ZW3D.
    This is the VERNUM date and internal version number that ZW3D displays in its "About" box to identify a specify build of ZW3D.

    @see cvxVersion() to get the current release number for the version of ZW3D that is in use.

    @param [out] verNum version number

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C void cvxVersionNum(vxLongName verNum);


    //====================================================================================================================
    /** @name Filter */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    Get a list of filters' names.

    @code
    int count = 0;
    vxName filterList[30] = {};
    cvxFilterListGet(&count, filterList);
    @endcode

    @param [out] count the count of filters
    @param [out] filterList list of filters' names, request vxName[30]

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxFilterListGet(int *count, vxName *filterList);

    /**
    @ingroup zwapi_global_apply

    Set the color filter according to color index, this value is the index of color picker in ZW3D, and
    it should in the range of V_COLOR_NULL ~ V_COLOR_LAST, it will reset the filter to pick all if index is out of this range.

    @param [in] colorIdx the index of color filter

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_MEMORY_ERROR
    */
    ZW_API_C void cvxColorFilter(int colorIdx);

    /**
    @ingroup zwapi_global_apply

    Get current active filter name.

    @param [out] Filter the name of current active filter

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C evxErrors cvxFilterActiveGet(vxName Filter);


    //====================================================================================================================
    /** @name Tools */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply
    Determine whether label are matched.

    @param [in] Label1 first persistent label (null-terminated integer array)
    @param [in] Label2 second persistent label (null-terminated integer array)

    @retval return
    -        0 - the input labels do not match
    -        1 - the input labels are the same
    -        2 - the input labels are "close" match
    @warning
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C int cvxLabelMatch(int *Label1, int *Label2);

    /**
    @ingroup zwapi_global_apply

    Leading and trailing blank spaces are removed from "name".

    If an positive integer number (4 digits or less) is input as
    name", it is padded with zero's until it is 4 digits long.

    A name that is too long (longer than "size") is truncated.

    It is assumed that the input "name" is no longer than 512 bytes.

    Invalid characters are replaced with underscores.

    @param [in,out] name  name to check
    @param [in] size max size (bytes) of a valid name
    @param [in] option -2 - check and fix name without warning messages
                       -1 - check and fix name with warning messages
                       0 - check name without fixes and messages
                       1 - check name with messages indicating problems

    @retval return
    -        1 - the input name is OK and/or repaired.
    -        0 - the input name is not OK/ empty.
    */
    ZW_API_C int cvxNameIsOkay(char *name, int size, int option);

    /**
    @ingroup zwapi_global_apply

    Outputs the network card id and/or dongle id of the host
    computer for the instance of ZW3D currently executing.

    @note
    Dongle id is not supported from version 14.6 onward.

    Outputs zero for an undefined ID.

    @param [out] idNetwork decimal encoded network id
    @param [out] idDongle decimal encoded dongle id

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    */
    ZW_API_C void cvxHostId(double *idNetwork, double *idDongle);

    /**
    @ingroup zwapi_global_apply

    Notify zw3d to exit.
    @param [in] opt whether inform the user that zw3d will exit. 0-no, 1-yes

    */
    ZW_API_C void cvxNotifyExit(int opt);

    /**
    @ingroup zwapi_global_apply

    Set the value of the Misumi Mold installed mark "VgMoldInstalled".
    @param [in] IsInstalled 1 if Misumi Mold is installed, 0 otherwise

    */
    ZW_API_C void cvxSetMSMMoldInstalled(int IsInstalled);

    /**
    @ingroup zwapi_global_apply

    Set the value of the Misumi Press installed mark "VgPressInstalled".
    @param [in] IsInstalled 1 if Misumi Press is installed, 0 otherwise

    */
    ZW_API_C void cvxSetMSMPressInstalled(int IsInstalled);

    //====================================================================================================================
    /** @name Plugin */
    //====================================================================================================================

    /**
    @ingroup zwapi_global_apply

    Get plugin path of ZW3D in regedit.

    @note
    Release memory of pathList is the caller's responsibility.
    There is an example named 'DllRegister' in ApiExample.

    @param [out] pathList plugin path, an array
    @param [out] pCnt count of pathList
    @param [in] is64 if 0, paths of 32-bit plugin are acquired, else 64-bit plugin path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxPluginRegPathGet(vxPath **pathList, int *pCnt, int is64);

    /**
    @ingroup zwapi_global_apply

    Get plugin path of ZW3D in regedit.

    @note
    Release memory of pathList is the caller's responsibility.
    There is an example named 'DllRegister' in ApiExample.

    @param [out] pathList plugin path, an array
    @param [out] pCnt count of pathList
    @param [in] is64 if 0, paths of 32-bit plugin are acquired, else 64-bit plugin path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    */
    ZW_API_C evxErrors cvxPluginRegPathGetByLongPath(vxLongPath **pathList, int *pCnt, int is64);

    //====================================================================================================================
    /** @name Plugin Manage*/
    //====================================================================================================================
    /**
    @ingroup ZwPlugin

    Initialize the data with input library path, this function will call 'ZwMemoryZero' to
    initialize 'pluginData'. If the input path is valid, the 'libraryName' and
    'libraryDirectory' of 'pluginData' will be filled.

    @code
    szwPluginData pluginData;
    // case 1
    ZwPluginDataInit(NULL, &pluginData); // this is equal to ZwMemoryZero(sizeof(pluginData), &pluginData);

    // case 2
    // pluginData.libraryName will be set as "MyPlugin.dll", pluginData.libraryDirectory will be set as "D:\\test"
    ZwPluginDataInit("D:\\test\\MyPlugin.dll", &pluginData);
    @endcode

    @param [in] libraryPath full path of a liabrary file, it can be NULL
    @param [out] pluginData plugin data
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwPluginDataInit(const char *libraryPath, szwPluginData *pluginData);

    /**
    @ingroup ZwPlugin

    Load the specified plugin from the input data.

    @warning
    Please zero the data of those members of pluginData which not used.

    @code
    szwPluginData pluginData;
    // If there's a library file name 'TestPlugin.dll' in directory 'D:\\test', you can refer to the code below:
    ZwPluginDataInit("D:\\test\\TestPlugin.dll", &pluginData);
    // the application name can be set what you wants, and it will be set as the base name of library file if it is empty
    strcpy_s(pluginData.applicationName, sizeof(pluginData.applicationName), "TestPlugin");
    // the resource file path should be an absolute path, if it is empty, the process will try to find the file under the library path, and it's okay for a plugin without resource file
    strcpy_s(pluginData.resourceFilePath, sizeof(pluginData.resourceFilePath), "D:\\test\\TestPlugin.zrc");
    // the optional description of the plugin
    strcpy_s(pluginData.description, sizeof(pluginData.description), "My test plugin.");
    if (ZW_API_NO_ERROR == ZwPluginLoad(pluginData))
    {
    ...
    }
    @endcode

    @param [in] pluginData plugin data

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_PATH
    -        ZW_API_PLUGIN_LOAD_REPEAT_ERROR
    -        ZW_API_PLUGIN_LOAD_FAIL
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwPluginLoad(szwPluginData pluginData);

    /**
    @ingroup ZwPlugin

    Try to unload the specified plugin by the libratry name.

    @note
    The API will check the plugin loaded or not firstly, then try to unload it asynchronously. Thus, it can't know unload the
    specified plugin successfully or not after you called this API immediately. Please DO NOT use any other API after you called
    this API to unload the plugin itself.

    @code
    // In your code, you should use it like below:
    void yourFunction(...)
    {
    ...// some code for you need
    ZwPluginUnload("xxx.dll"); // make sure it is the last code of the function
    }
    @endcode

    @param [in] libraryName library file name of the plugin

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_NAME
    -        ZW_API_PLGUIN_NOT_LOADED_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwPluginUnload(const char *libraryName);

    /**
    @ingroup ZwPlugin

    Get all plugin list, the list is the same with what you see from the 'Application Manager'.

    @note
    This API will allocate the memory of 'pluginList'. It's the caller's responsibility to release memory.

    @code
    int count = 0;
    szwPluginData *pluginList = NULL; // 'szwPluginData *pluginList = nullptr;' for C++
    if (ZW_API_NO_ERROR == ZwPluginListGet(&count, &pluginList) && count > 0)
    {
    // ...
    }
    ...
    ZwMemoryFree((void**)&pluginList);
    @endcode

    @param [out] count count of plugin list
    @param [out] pluginList data of plugin list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C ezwErrors ZwPluginListGet(int *count, szwPluginData **pluginList);

    //====================================================================================================================
    /** @name Resource File*/
    //====================================================================================================================
    /**
    @ingroup ZwResourceFile
    
    Register a Qt resource file(rcc or zrc file).The rcc/zrc file contains the resources
    used in dll.
    For the input file, it MUST be a rcc (xx.rcc) or a zrc (xx.zrc) file. And if it is an
    absolute file path, this function will try to register it directly. If it is only a
    file name, this function will try to find it and then register.
    
    If developer wants to unregister the rcc/zrc file in file dynamically. It is a MUST to
    run ZwResourceFileUnregister() in the exit function.
    
    @code
    // Register the resource file in your init function
    ZwResourceFileRegister("MyResource.zrc"); // or giving an absolute path of "MyResource.zrc"
    ...
    // Unregister the resource file in your exit function
    ZwResourceFileUnregister("MyResource.zrc"); // or giving an absolute path of "MyResource.zrc"
    @endcode
    
    @param [in] file resource file name
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C ezwErrors ZwResourceFileRegister(const char *file);

    /**
    @ingroup ZwResourceFile
    
    Unregister the Qt resource file(rcc or zrc file) registered via ZwResourceFileRegister().
    If developer wants to unload the DLL plug in file dynamically. The input name
    must be the same as the one used in ZwResourceFileRegister().
    
    @see ZwResourceFileRegister
    
    @param [in] file resource file name
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C ezwErrors ZwResourceFileUnregister(const char *file);

    /**
    @ingroup ZwResourceFile

    Adds the specified file directory to the list of resource paths.  
    This function is used to set search path for resource files such as .ui .png and .zcui.  

    @see ZwResourcePathDelete ZwResourcePathListGet

    @param [in] path directory path name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C ezwErrors ZwResourcePathAdd(const zwString512 path);

    /**
    @ingroup ZwResourceFile

    Deletes the specified path from the current list of resource paths.  

    @note
    You can not delete path which is appended by ZwSearchPathAdd().  
    This function is used to delete the path which is added by ZwResourcePathAdd().  

    @see ZwResourcePathListGet ZwResourcePathAdd

    @param [in] path directory path name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C ezwErrors ZwResourcePathDelete(const zwString512 path);

    /**
    @ingroup ZwResourceFile

    Gets all resource paths.

    @note
    The calling procedure MUST deallocate the pathList with ZwMemoryFree().

    @see ZwResourcePathDelete ZwResourcePathAdd

    @param [out] count path list count
    @param [out] pathList path list

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_MEMORY_ERROR
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwResourcePathListGet(int *count, zwString512 **pathList);

    /**
    @ingroup ZwResourcePath

    Register the unique module name of your plugin to load the customized profiles(*.zcui files).  

    For example, if the customized profiles were under the directory "D:\\Example\\Resource\\...", then 
    we can use "Example" as the unique name to call this function. And remember to call it in the 'init' 
    function of your plugin, if your plugin will be loaded when ZW3D starts, the profiles will be loaded 
    automatically.

    @param [in] moduleName module name from the customized profile path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_NAME

    @code
    // assume that the profiles under the directory "D:\\Example\\Resource\\..."
    ZwProfileModuleNameRegister("Example");
    @endcode
    */
    ZW_API_C ezwErrors ZwProfileModuleNameRegister(const char *moduleName);

    //====================================================================================================================
    /** @name Help Document */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

    Load the context file associated with help chm file in memory.

    @note
    There are two files should be prepared. The first one is a context file and the 
    second is a help document file with 'chm' format. These two files should be put
    in the same directory.
    The content of context file should be like as below:
    Line 1: <!--XXX.chm-->
    Line 2: CommandNameA xx.html
    Line 3: CommandNameB xx.html
    Line 4: FormNameA xx.html
    ...

    @param [in] filePath the context file path

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_PATH
    */
    ZW_API_C evxErrors cvxHelpDocLoad(const vxLongPath filePath);

    //====================================================================================================================
    /** @name App Action Reactor */
    //====================================================================================================================
    /**
    @ingroup zwapi_global_apply

       Set a callback function. When processing the target application option,
    the callback function will be called.

       If this function called many times with the same 'type', only
    the last will take effect.

       If param->pfn is null, the original callback function, if there
    exists, will be removed.

    @note
       If one call this function to register a callback in a dll module,
    he must call this function again, with argument param set as NULL,
    to unregister the callback for each action before the dll module exit.
    Usually we can do this in the exit function of the dll module.

    @deprecated This API will not be updated anymore, please use ZwApplicationReactorSet()
    @see ZwApplicationReactorSet

    @param [in] type action type
    @param [in] param callback function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    */
    ZW_API_C evxErrors cvxAppAction(evxAppAction type, svxAppActionParam *param);

    //====================================================================================================================
    /** @name Application */
    //====================================================================================================================
    /**
    @ingroup ZwApplication

    Sets a callback function of the application reactor of ZW3D. When processing the target application option, 
    the callback function will be called.  

    Each callback function is labeled by the 'data.uniqueName'. This API supports to set different callback 
    functions and try to call them all, but if one of them returns 1, the process will be aborted and the other 
    functions will not be called.  

    To remove a specified callback, you should call this API again with the same 'data.uniqueName' and set 'callbackFunction' be NULL.  

    @note
    Remember, you MUST remove the callback before the plugin exits.

    @code
    int yourCallbackFunction()
    {
    int ret = 0;
    ...
    return ret; // 1 to abort the process, else 0
    }

    // 1. add a callback function
    szwApplicationReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = yourCallbackFunction;
    ZwApplicationReactorSet(ZW_APPLICATION_PRECLOSE, data);

    //2. remove a callback function
    szwApplicationReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = NULL; // or data.callbackFunction = nullptr; for C++
    ZwApplicationReactorSet(ZW_APPLICATION_PRECLOSE, data);
    @endcode

    @param [in] type action type
    @param [in] data reactor data with unique name and callback function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwApplicationReactorSet(ezwApplicationReactorType type, szwApplicationReactorData data);

    //====================================================================================================================
    /** @name Document Reactor */
    //====================================================================================================================
    /**
    @ingroup ZwDocument

    Sets a callback function of the document reactor of ZW3D. When processing the target document option, 
    the callback function will be called.  

    Each callback function is labeled by the 'data.uniqueName'. This API supports to set different callback 
    functions and try to call them all, but if one of them returns 1, the process will be aborted and the other 
    functions will not be called.  

    To remove a specified callback, you should call this API again with the same 'data.uniqueName' and set 'callbackFunction' be NULL.  

    @note
    Remember, you MUST remove the callback before the plugin exits.

    @code
    int yourCallbackFunction(const char* curName, const char* newName)
    {
    // curName : current file name
    // newName : new name to be saved, it may be NULL in some types
    int ret = 0;
    ...
    return ret; // 1 to abort the process, else 0
    }


    // 1. add a callback function
    szwDocumentReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = yourCallbackFunction;
    ZwDocumentReactorSet(ZW_DOCUMENT_CREATED, data);

    //2. remove a callback function
    szwDocumentReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = NULL; // or data.callbackFunction = nullptr; for C++
    ZwDocumentReactorSet(ZW_DOCUMENT_CREATED, data);
    @endcode

    @param [in] type action type
    @param [in] data reactor data with unique name and callback function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwDocumentReactorSet(ezwDocumentReactorType type, szwDocumentReactorData data);


    //====================================================================================================================
    /** @name Environment Reactor */
    //====================================================================================================================

    /**
    @ingroup ZwApplication

    Sets a callback function of the environment reactor of ZW3D. When activated different environment, 
    the callback function will be called.  

    Each callback function is labeled by the 'data.uniqueName'. This API supports to set different callback 
    functions and try to call them all.  

    To remove a specified callback, you should call this API again with the same 'data.uniqueName' and set 'callbackFunction' be NULL.  

    @note
    Remember, you MUST remove the callback before the plugin exits.

    @code
    void yourCallbackFunction(ezwEnvironmentType currentEnvironment)
    {
    ... // do what you want when the environment of 'currentEnvironment' activated
    }

    // 1. add a callback function
    szwEnvironmentReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = yourCallbackFunction;
    szwEnvironmentReactorData(data);

    //2. remove a callback function
    szwEnvironmentReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = NULL; // or data.callbackFunction = nullptr; for C++
    szwEnvironmentReactorData(data);
    @endcode

    @param [in] data reactor data with unique name and callback function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    */
    ZW_API_C ezwErrors ZwEnvironmentReactorSet(szwEnvironmentReactorData data);

    //====================================================================================================================
    /** @name Preference  */
    //====================================================================================================================
    /**
    @ingroup ZwPreference

    Gets the value and unit of tolerance from the active unit system in part or assembly environment.

    @param [out] value the value of tolerance.
    @param [in] size length of bytes need to get from the specified contents.
    @param [out] unitName the unit name of tolerance.
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_OUT_OF_RANGE
    */
    ZW_API_C ezwErrors ZwPreferenceToleranceGet(double *value, int size, char *unitName);

    /**
    @ingroup ZwPreference

    Sets the value and unit of tolerance to the active unit system in part or assembly environment.

    @param [in] value the value of tolerance.
    @param [in] unitName the unit name of tolerance.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_STRING
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    -        ZW_API_INVALID_INPUT
    */
    ZW_API_C ezwErrors ZwPreferenceToleranceSet(double value, const char *unitName);

    /**
    @ingroup ZwPreference

    Gets the free edge alternate display mode in Part Settings.

    @param [Out] isShowFreeEdge Whether to show alternate display of free edges.
                               1 - to show, 0 - not to show.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPreferenceFreeEdgeDisplayModeGet(int *isShowFreeEdge);

    /**
    @ingroup ZwPreference

    Sets the free edge alternate display mode in Part Settings.

    @param [in] isShowFreeEdge Whether to show alternate display of free edges.
                               1 - to show, 0 - not to show.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPreferenceFreeEdgeDisplayModeSet(int isShowFreeEdge);

    /**
    @ingroup ZwPreference

    Gets the mode of Component Light Source in Part Settings.

    @param [out] isUseLightSource Whether to use component light sources.
                               1 - to use, 0 - not to use.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPreferenceComponentLightSourcesModeGet(int *isUseLightSource);

    /**
    @ingroup ZwPreference

    Sets the mode of Component Light Source in Part Settings.

    @param [in] isUseLightSource Whether to use component light sources.
                               1 - to use, 0 - not to use.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPreferenceComponentLightSourcesModeSet(int isUseLightSource);

    /**
    @ingroup ZwPreference

    Gets the current units system in current part or assembly environment.

    @Note
    The caller is responsible to free the unitList by using ZwMemoryFree().

    @param [out] unitSystem the current units system.
    @param [out] countUnits the count of units, NULL to ignore.
    @param [out] unitList the list of units, NULL to ignore.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPreferenceUnitsSystemGet(ezwUnitSystem *unitSystem, int *countUnits, szwUnitInformation **unitList);

    /**
    @ingroup ZwPreference

    Sets the current units system in current part or assembly environment.

    @param [in] unitSystem the current units system.

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_ROOT_OBJ_ACT_FAIL
    -        ZW_API_WRONG_ROOT_ENV
    */
    ZW_API_C ezwErrors ZwPreferenceUnitsSystemSet(ezwUnitSystem unitSystem);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_GLOBAL_APPLY_H */
