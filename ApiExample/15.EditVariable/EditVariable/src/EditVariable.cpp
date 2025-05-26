/*
 * (C) Copyright 2024, ZWSOFT Co., LTD. (Guangzhou) All Rights Reserved.
*/
#include "zwapi_cmd_paramdefine_param.h"
#include "zwapi_cmd_paramdefine_tpl.h"

#include "zwapi_general_ent.h"
#include "zwapi_part_var.h"
#include <vector>
#include "zwapi_variable.h"
#include "zwapi_part_history.h"
#include "zwapi_ui_tablewidget.h"
#include "zwapi_entity.h"

/*******************************************************************/
/* Application includes */
#include "../inc/EditVariablePr.h"

/*******************************************************************/
/*  Global variable declarations */
#define FORM_NAME "EditVariable"
#define SUB_FORM_NAME "Variable"
static int totalVarNum = 0;
std::vector<szwVariableData> allVaribleList{};   //all variables of the current part

/*******************************************************************/
/* Data type definitions */

/* DESCRIPTION: Form Field of EditVariable*/
typedef enum EditVariableField
    {
    ZW_FEATURE = 1,
    ZW_EXPRESSION = 2,
    ZW_VARIABLE_LIST = 3,
    }EditVariableField;

/* DESCRIPTION: Field of sub-form Variable*/
typedef enum VariableField
    {
    ZW_VARIABLE_NAME = 1,
    ZW_VARIABLE_VALUE = 2,
    }VariableField;

/*******************************************************************/
/* Function declarations */
static void EditVariableInit(int idData);
static int EditVariable(int idData);
static int EditVariableCb(char* form, int idField, int item);
static int VariableCb(char* form, int idField, int item);
static void VariableEcho(int idData, void* ohEcho);


/*******************************************************************/
/* Function definition */
int RegisterEditVariable(void)
/*
DESCRIPTION:
   Register callback function of template command.
*/
   {
   /* Start the command by entering command string "!EditVariable" */
   ZwCommandFunctionLoad("EditVariable", (void*)EditVariable, ZW_LICENSE_CODE_GENERAL);
   ZwCommandFunctionLoad("EditVariableInit", (void*)EditVariableInit, ZW_LICENSE_CODE_GENERAL);
   ZwCommandCallbackLoad("EditVariableCb", (void *)EditVariableCb);

   ZwCommandCallbackLoad("VariableEcho", (void*)VariableEcho);
   ZwCommandCallbackLoad("VariableCb", (void*)VariableCb);
   return 0;
   }

/*******************************************************************/
/* Function definition */
int UnloadEditVariable(void)
/*
DESCRIPTION:
   Unload callback function of template command.
*/
   {
    ZwCommandFunctionUnload("EditVariableInit");
    ZwCommandFunctionUnload("EditVariable");
    ZwCommandFunctionUnload("VariableEcho");
    ZwCommandFunctionUnload("EditVariableCb");
    ZwCommandFunctionUnload("VariableCb");
   return 0;
   }

/*******************************************************************/
/* Function definition */
void EditVariableInit
(
    int idData    /* I: index of data container */
)
/*
DESCRIPTION:
   Initialize callback function of command. the function is called when the command
is initialized. In this callback function, you can initialize the data of command,
but the command form has not yet been created at this time, so should not initialize
the command form in this callback function.
*/
    {
    // TODO: Do something

    cvxMsgDisp("EditVaribleInit");
    /*get all variable in the active file*/
    int allVarNum = 0;
    szwVariableData* varList = nullptr;
    if (ZwVariableListGet(NULL, &allVarNum, &varList))
        return;
    for (int i = 0; i < allVarNum; i++)
        allVaribleList.push_back(varList[i]);
    ZwMemoryFree((void**)&varList);
    return;
    }

/*******************************************************************/
/* Function definition */
int EditVariable
(
   int idData    /* I: index of data container */
)
/*
DESCRIPTION:
   Execution function of command. the function is called when the command
is clicked on the OK or APPLY button.
*/
   {
   // TODO: Do something

   cvxMsgDisp("EditVariable");
   cvxEchoEnd();
   /* set the variable list and regen*/
   if (ZwVariableListSet((int)allVaribleList.size(), allVaribleList.data(), 1))
       return 1;
   ZwEntityAutoRegen(ZW_REGEN_FOR_OUTDATED_OBJECTS, 1);
   /* Inquire data of data container */

   return 0;
   }

/*******************************************************************/
/* Function definition */
int EditVariableCb
(
    char* formName,    /* I: form name */
    int idField,       /* I: index of command parameter field */
    int idData         /* I: index of data container */
)
/*
DESCRIPTION:
   Callback function of command parameter field, the function is called when value
of the specify parameter field changes.
*/
    {
    // TODO: Do something
    cvxMsgDisp("EditVariableCb");

    std::vector<svxData> varNameList{};
    std::vector<svxData> varValueList{};
    if (idField == ZW_FEATURE)
        {
        /*get the variable list of the current feature*/
        svxData featureDada{};
        if (cvxDataGet(idData, idField, &featureDada))
            return 1;
        int idDataFeature = 0;
        if (cvxPartInqFtrData(featureDada.idEntity, 1, &idDataFeature) || idDataFeature < 0)
            return 1;

        //find those field which containing variables by traversing all the fields.
        int feaFieldNum = 0;
        svxFldData* feaFldDataList = nullptr;
        if (cvxDataGetAll(idDataFeature, &feaFieldNum, &feaFldDataList))
            return 1;
        for (int i = 0; i < feaFieldNum; i++)
            {
            if (feaFldDataList[i].fld_type == VX_FLD_PNT || feaFldDataList[i].fld_type == VX_FLD_ENT ||
                feaFldDataList[i].fld_type == VX_FLD_TXT || feaFldDataList[i].fld_type == VX_FLD_DATA)
                continue;
            if (feaFldDataList[i].fld_data->isText)
                {
                /*variable name*/
                svxData varName{};
                varName.isText = 1;
                strcpy_s(varName.Text, feaFldDataList[i].fld_data->Text);
                varNameList.push_back(varName);
                /*variable value*/
                svxData varValue{};
                varValue.isNumber = 1;
                varValue.Num = feaFldDataList[i].fld_data->Num;
                varValueList.push_back(varValue);
                }
            }

        /*table data set*/
        for (int i = 0; i < varNameList.size(); i++)
            {
            // active the sub-from, record the referenced original variable name in the corresponding field.
            int idSubData = 0;
            if (cvxDataInit(SUB_FORM_NAME, &idSubData))
                return 1;
            if (cvxDataSet(idSubData, ZW_VARIABLE_NAME, &varNameList[i]))
                return 1;
            if (cvxDataSet(idSubData, ZW_VARIABLE_VALUE, &varValueList[i]))
                return 1;
            int idOut = 0;

            svxData temp{};
            temp.idEntity = idSubData;
            if (cvxDataSet(idData, ZW_VARIABLE_LIST, &temp))
                return 1;
            }
        ZwMemoryFree((void**)&feaFldDataList);
        }

    return 0;
    }

/*******************************************************************/
/* Function definition */
int VariableCb
(
    char* formName,    /* I: form name */
    int idField,       /* I: index of command parameter field */
    int idData         /* I: index of data container */
)
/*
DESCRIPTION:
   Callback function of command parameter field, the function is called when value
of the specify parameter field changes.
*/
    {
    // TODO: Do something
    cvxMsgDisp("VariableCb");

    if (idField == ZW_VARIABLE_VALUE)
        {
        /*get the variable name and value of user input*/
        svxData valueData{}, nameData{};
        if(cvxDataGet(idData, ZW_VARIABLE_VALUE, &valueData))
            return 1;
        if (cvxDataGet(idData, ZW_VARIABLE_NAME, &nameData))
            return 1;

        /* update the variable list */
        szwVariableData tempVar{};
        strcpy_s(tempVar.name, nameData.Text);
        tempVar.type = ZW_VARIABLE_NUMBER;
        tempVar.value.numberValue.number = valueData.Num;

        for (int j = 0; j < allVaribleList.size(); j++)
            {
            if (strcmp(allVaribleList[j].name, tempVar.name) == 0)
                {
                allVaribleList[j] = tempVar;
                }
            }

        }

    return 0;
    }

/*******************************************************************/
/* Function definition */
void VariableEcho(int idData, void* ohEcho)
    {
    cvxEchoStart();
    cvxMsgDisp("VariableEcho");
    /* Inquire data of data container */
    if (ZwVariableListSet((int)allVaribleList.size(), allVaribleList.data(), 0))
        return;
    cvxEchoEnd();
    return;
    }
