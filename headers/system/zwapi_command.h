/**
@file zwapi_command.h
@copyright (C) Copyright 2024, ZWSOFT CO., LTD. (Guangzhou) All Rights Reserved.
@note THE HEADER FILE FOR THE ZW3D Command Common API
*/


#pragma once
#ifndef ZW_API_COMMAND_H /* this ifndef surrounds entire header */
#define ZW_API_COMMAND_H

#include "zwapi_command_data.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    //====================================================================================================================
    /** @name Command Send */
    //====================================================================================================================
    /**
    @ingroup ZwCommand

    Post the input command string for execution after the current command and
    any previously-buffered command events are finished executing.  

    If "priority" is input as ZW_COMMAND_POST_PRIORITY_HIGH, the input command string is given
    higher priority for execution than command strings buffered with "priority = ZW_COMMAND_POST_PRIORITY_LOW".  

    For example, if you register a pointer to a "void MyFunction(void)" callback
    function using ZwCommandFunctionLoad(), you can cause the function to be invoked after
    pending commands have executed using ZwCommandPost("~MyFunction", ZW_COMMAND_POST_PRIORITY_LOW).
    
    @see ZwCommandPostExecuteAll

    @param [in] command command string
    @param [in] priority priority of execution

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT

    @code
    // if you registered a comamnd named 'MyFunction'
    // posts MyFunction with a lower priority
    ZwCommandPost("~MyFunction", ZW_COMMAND_POST_PRIORITY_LOW);
    // posts MyFunction with a higher priority
    ZwCommandPost("~MyFunction", ZW_COMMAND_POST_PRIORITY_HIGH);
    // executes all posted commands
    ZwCommandPostExecuteAll();
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandPost(const char *command, ezwCommandPostPriority priority);

    /**
    @ingroup ZwCommand

    Execute all posted commands, if the API ZwCommandPost was called several times to
    post commands, this function can execute them all immediately on the main thread.

    @see ZwCommandPost

    @retval
    -        ZW_API_NO_ERROR
    */
    ZW_API_C ezwErrors ZwCommandPostExecuteAll();

    /**
    @ingroup ZwCommand

    Executes the input command synchronously.  

    If you registers a pointer to a "void MyFunction(void)" function by using ZwCommandFunctionLoad(),
    you can invoke this command by this function with the parameter 'command' passes by "~MyFunction".
    
    @note
    The parameter 'command' can't be null pointer, the function ZwCommandPostExecuteAll() do the same thing
    as 'cvxCmdSend(NULL)'.  
    This function will execute the command on the current thread.

    @param [in] command null-terminated ascii command string

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_STRING

    @code
    // if you registered a command named 'MyFunction', it will be executed immediately
    ZwCommandSend("~MyFunction");
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandSend(const char *command);

    //====================================================================================================================
    /** @name Command Operation */
    //====================================================================================================================
    /**
    @ingroup ZwCommand

    Check whether license is valid for the input command name, only the licensed command can be called and executed successfully.
    The license is valid when this function returns 'ZW_API_NO_ERROR'.  
    If the license is not valid or the command by the 'name' is not registered, it returns ZW_API_GENERAL_ERROR.
    
    @param [in] name Command name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT

    @code
    // if you registered a comamnd named 'MyFunction'
    if (ZW_API_NO_ERROR == ZwCommandLicenseCheck("MyFunction"))
    {
        // you can use the command "MyFunction" like below:
        ZwCommandSend("~MyFunction");
    }
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandLicenseCheck(const char *name);

    /**
    @ingroup ZwCommand

    Set a callback function of the command reactor of ZW3D. When processing the target command option,
    the callback function will be called.  

    Each callback function is labled by the 'data.uniqueName'. This API supports to set different callback
    functions and try to call them all, but if one of them returns 1, the process will be aborted and the other
    functions will not be called.  

    To remove a specified callback, you should call this API again with the same 'data.uniqueName' and set 'callbackFunction' be NULL.

    @note
    Remember, you MUST remove the callback before the plugin exits.
    
    @param [in] type action type
    @param [in] data reactor data with unique name and callback function

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_INVALID_INPUT

    @code
    // 1. add a callback function
    szwCommandReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = yourCallbackFunction;
    ZwCommandReactorSet(ZW_COMMAND_START, data);

    //2. remove a callback function
    szwCommandReactorData data;
    strcpy_s(data.uniqueName, sizeof(data.uniqueName), "example");
    data.callbackFunction = NULL; // or data.callbackFunction = nullptr; for C++
    ZwCommandReactorSet(ZW_COMMAND_START, data);
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandReactorSet(ezwCommandReactorType type, szwCommandReactorData data);

    //====================================================================================================================
    /** @name Function Register/Un-register */
    //====================================================================================================================
    /**
    @ingroup ZwCommand

    Registers a function referenced by the "function=" or "custom="
    fields in a command template definition.  The function is
    registered with a ZW3D licensing code.  ZW3D ensures the user has
    the appropriate license before allowing access to the function.  

    Callback functions should be registered in the "Init" function
    called when your library is dynamically loaded by ZW3D at runtime.  

    For a standard command operation, the function should be the following type:

    int StandardCommand(int idInputData, int *idOutputData)  

    For a custom command operation, the function should be the following type:

    int CustomOperation(int idInputData)  

    For a callback function invoked by a command string that is the function
    name preceded by a "tilda" (e.g. ~MyFunction), the function should be one
    of the following types:

    void MyFunction(void) or...  

    void MyFunction(char *string) invoked by sending the string "~MyFunction("text string")"
    using ZwCommandSend() or ZwCommandPost().  

    The API functions beginning with cvxData...() are used to compose and
    to query the data containers referenced by "idInputData" or "idOutputData".  

    For documentation on the the callback function registered in the header of
    a GUI template, see cvxFormFunc().  

    If developer wants to unload the DLL plug in file dynamically. It is a MUST to
    run ZwCommandFunctionUnload() in the exit function.  

    In this case, the pre-existing symbol is kept and the input function is ignored.
    
    @param [in] name function name
    @param [in] functionPointer function pointer
    @param [in] code ZW3D licensing code (e.g. ZW_LICENSE_CODE_GENERAL or ZW_LICENSE_CODE_ASSEMBLY)

    @retval succeeds
    -        ZW_API_NO_ERROR : the input function was successfully registered
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_REGISTER_ERROR : a symbol with the same name as the input function already exists.
                                         In this case, the pre-existing symbol is kept and the input function is ignored.

    @code
    // in your plugin's 'Init' function, you should call this API to register your own command as below:
    // it assumes that there's a function named 'MyFunction'
    ZwCommandFunctionLoad("MyFunction", (zwFunctionPointer)MyFunction, ZW_LICENSE_CODE_GENERAL);

    //in your plugin's 'Exit' function, you MUST unload all functions that registered in the init function:
    ZwCommandFunctionUnload("MyFunction");
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandFunctionLoad(const char *name, zwFunctionPointer functionPointer, ezwCommandLicenseType code);

    /**
    @ingroup ZwCommand

    Registers a pointer to an auxiliary callback function used by
    a command template.  The function does not require a licensing
    code.  The "init=", "exit=", "echo_obj=" and "callback=" fields reference
    auxiliary callback functions.  

    Function pointers should be registered in the "Init" function
    called when your library is dynamically loaded by ZW3D at runtime.  

    The callback function should be of the following type:

    int Callback(char *TemplateName, int idField, int idData)  

    The echo_obj function should be of the following type:
    void Echo(int idData, void *ptr)  

    If developer wants to unload the DLL plug in file dynamically.  
    It is a MUST to run ZwCommandFunctionUnload() in the exit function.

    @param [in] name function name
    @param [in] callbackPointer callback function pointer

    @warning
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_REGISTER_ERROR

    @code
    // in your plugin's 'Init' function, you should call this API to register your callback function as below:
    // it assumes that there's a callback function named 'MyCallback'
    ZwCommandCallbackLoad("MyCallback", (zwFunctionPointer)MyCallback);

    //in your plugin's 'Exit' function, you MUST unload all functions that registered in the init function:
    ZwCommandFunctionUnload("MyCallback");
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandCallbackLoad(const char *name, zwFunctionPointer callbackPointer);

    /**
    @ingroup ZwCommand

    Unload specified function registered via ZwCommandFunctionLoad()/ZwCommandCallbackLoad()
    if developer wants to unload the DLL plug in file dynamically.  
    The input name must be the same as the one
    used in ZwCommandFunctionLoad()/ZwCommandCallbackLoad().

    @pre ZwCommandFunctionLoad ZwCommandCallbackLoad

    @param [in] name function name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_UNLOAD_ERROR
    */
    ZW_API_C ezwErrors ZwCommandFunctionUnload(const char *name);

    /**
    @ingroup ZwCommand

    Registers a pointer to a global variable (i.e. the variable's address)
    referenced in a command template "options" string.  

    Global variables should be registered in the "Init" function
    called when your library is dynamically loaded by ZW3D at runtime.  

    If developer wants to unload the DLL plug in file dynamically.
    It is a MUST to run ZwCommandVariableUnload() in the exit function.  
    
    @param [in] name global variable name
    @param [in] variablePointer pointer to global variable

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_UNLOAD_ERROR

    @code
    // in your plugin's 'Init' function, you should call this API to register your variable as below:
    // it assumes that there's a variable named 'MyVariable'
    ZwCommandVariableLoad("MyVariable", (zwFunctionPointer)MyVariable);

    //in your plugin's 'Exit' function, you MUST unload all variables that registered in the init function:
    ZwCommandFunctionUnload("MyVariable");
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandVariableLoad(const char *name, zwFunctionPointer variablePointer);

    /**
    @ingroup ZwCommand

    Unload the variable registered via cvxCmdVariable() if developer
    wants to unload the DLL plug in file dynamically. The input name
    must be the same as the one used in cvxCmdVariable().

    @pre ZwCommandVariableLoad

    @param [in] name Variable name

    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_NAME
    -        ZW_API_FUN_UNLOAD_ERROR
    */
    ZW_API_C ezwErrors ZwCommandVariableUnload(const char *name);

    //====================================================================================================================
    /** @name Macro */
    //====================================================================================================================
    /**
    @ingroup ZwCommand
    
    Executes a specified macro or the statements with macro format.  
    
    For executing the macro statements, "input" is interpreted as a string
    of one or more newline-delimted macro command strings -- without the 
    macro/endmacro keywords.  A new macro is started, the encoded macro 
    commands are executed and the macro is terminated.  
    
    The contents of variables created by the macro commands are output
    via "outputMessage" as a single comma-delimited, null-terminated ascii string.  
    The first item in the string is the total number of variables encoded
    in the string.  This is followed by an encoding of each variable.  
    Each variable is encoded with its name first, followed by the number
    of array elements in the variable, followed by the array values.  
    Values are either ascii-encoded floating point numbers, or strings
    enclosed in double quotemarks.  The following is an example:  
    
    @verbatim
       # variables
       Num = 25
       Strings = {"hello dolly", "hello world"}
       Array = {100,125,150}
    
       # ascii-encoded variable data
       3,Num,1,25,Strings,2,"hello dolly","hello world",Array,3,100,125,150
    @endverbatim
    
    @note
    Memory for "Output" is allocated by this function.  The memory must be
    deallocated by the calling procedure.  If there is no output data, a
    NULL pointer is output.  
    If user enter a new environment, user need to use the
    cvxDispSceneUpdate() interface to update the environment.  
    If this function errors out anywhere along the way, the string "ERROR"
    will be output via "outputMessage".  
    
    @param [in] macroType macro type to be executed
    @param [in] input null-terminated ascii string of macro commands or a macro file path
    @param [out] outputMessage pointer to of output data string, only used when macroType == ZW_MACRO_STATEMENTS (NULL to ignore)
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_INPUT
    -        ZW_API_INVALID_STRING
    -        ZW_API_INVALID_PATH

    @code
    //1. executes a macro file
    zwPath filePath = "D:\\temp\\test.mac"; \\ your real macro file path
    ZwCommandMacroExecute(ZW_MACRO_FILE, filePath, NULL);
    
    //2. executes some macro statements
    zwPath macroStatements = "";
    char* outputMessage = NULL;
    ZwCommandMacroExecute(ZW_MACRO_STATEMENTS, macroStatements, &outputMessage);
    ...
    ZwMemoryFree((void**)&outputMessage);
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandMacroExecute(ezwMacroType macroType, const char *input, char **outputMessage);

    /**
    @ingroup ZwCommand
    
    Gets the directory and file name of the currently running macro.
    If no running macro, this function returns ZW_API_GENERAL_ERROR.
    The 'directory' and 'fileName' cannot both be NULL.  
    
    The directory that is too long (longer than "directorySize") is truncated.  
    The fileName that is too long (longer than "fileSize") is truncated.  
    
    It is assumed that the input "directory" and "fileName" are no longer than 512 bytes.  
    
    @param [out] directory path of macro (NULL to ignore)
    @param [in] directorySize max size of directory
    @param [out] fileName file name of macro (NULL to ignore)
    @param [in] fileSize max size of fileName
    
    @retval succeeds
    -        ZW_API_NO_ERROR
    @retval fail
    -        ZW_API_GENERAL_ERROR
    -        ZW_API_INVALID_OUTPUT
    -        ZW_API_OUT_OF_RANGE

    @code
    // Call this function as below:
    zwPath macroDirectory = "", macroFile = "";
    ZwCommandMacroPathGet(macroDirectory, sizeof(macroDirectory), macroFile, sizeof(macroFile));
    @endcode
    */
    ZW_API_C ezwErrors ZwCommandMacroPathGet(char *directory, int directorySize, char *fileName, int fileSize);

/*
*********************************************************************
**  END HEADER FILE
*********************************************************************
*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ZW_API_COMMAND_H */
