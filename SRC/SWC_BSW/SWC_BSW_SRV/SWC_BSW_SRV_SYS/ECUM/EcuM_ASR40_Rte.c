/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 16.4 (required)
 *     The identifiers used in the declaration and definition of a function
 *     shall be identical.
 *
 *     Reason:
 *     The requirement 'EcuM3011' defines the arguments of EcuM_ShutdownTarget
 *     (ClientServerInterface EcuM_ShutdownTarget) as 'target' and 'mode' but the
 *     EcuM API specification defines the arguments as 'shutdownTarget' and
 *     'sleepMode' respectively. This issue has been reported in
 *     http://www.autosar.org/bugzilla/show_bug.cgi?id=58147
 */

/* !LINKSTO EcuM.EB.ASR32.EcuM016,1 */

/*==================[inclusions]============================================*/

#include <Std_Types.h>          /* AUTOSAR standard types */

/* define guard symbol to prevent redundant declaration of RTE symbols */
#define ECUM_INTERNAL_USE
/* !LINKSTO EcuM.EB.ASR32.EcuM017,1 */
#include <EcuM_BSW.h>    /* own API */
#include <EcuM_Int.h>    /* Internal declarations */

#if (ECUM_INCLUDE_RTE == STD_ON)
/* !LINKSTO EcuM.EB.ASR32.EcuM017,1 */
# include <Rte_EcuM.h> /* API for EcuM as SW-C */
#endif

/*==================[macros]================================================*/

#define ECUM_EB_RTE_NUM_MODES 6

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

#if (ECUM_INCLUDE_RTE == STD_ON)
#if (ECUM_EB_ENABLE_ASR40_SERVICE_API == STD_ON)

#define ECUM_START_SEC_CONST_8BIT
#define ECUM_START_SEC_CONST_8
#include <MemMap.h>

/* \brief map between EcuM's internal state defines and RTE defined modes
 *
 * This mapping table is needed as RTE mode type is generated in alphabetical
 * order whereas the EcuM states has "logical" order as well as decoupling
 * BSW code from RTE code. */
STATIC CONST(uint8, ECUM_CONST) EcuM_EB_ASR40_RteModeMap[ECUM_EB_RTE_NUM_MODES] =
{
  RTE_MODE_EcuM_ASR40_Mode_STARTUP,     /* ECUM_EB_MODE_STARTUP */
  RTE_MODE_EcuM_ASR40_Mode_RUN,         /* ECUM_EB_MODE_RUN */
  RTE_MODE_EcuM_ASR40_Mode_POST_RUN,    /* ECUM_EB_MODE_POST_RUN */
  RTE_MODE_EcuM_ASR40_Mode_SHUTDOWN,    /* ECUM_EB_MODE_SHUTDOWN */
  RTE_MODE_EcuM_ASR40_Mode_SLEEP,       /* ECUM_EB_MODE_SLEEP */
  RTE_MODE_EcuM_ASR40_Mode_WAKE_SLEEP   /* ECUM_EB_MODE_WAKE_SLEEP */
};

#define ECUM_STOP_SEC_CONST_8BIT
#define ECUM_STOP_SEC_CONST_8
#include <MemMap.h>

#endif
#endif

/*==================[external function definitions]=========================*/

#if (ECUM_INCLUDE_RTE == STD_ON)
#if (ECUM_EB_ENABLE_ASR40_SERVICE_API == STD_ON)

#define ECUM_START_SEC_CODE
#include <MemMap.h>

#if (ECUM_ECUM_FIXED_SUPPORT == STD_ON)

FUNC(void, ECUM_CODE) EcuM_ASR40_RteModeSwitch(uint8 mode)
{
  /* Return value is ignored because mode switch indication to Rte is compliant to a
   * fire and forget policy from EcuM's point of view. */
  (void)Rte_Switch_currentMode_ASR40_currentMode(EcuM_EB_ASR40_RteModeMap[mode]);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_RequestRUN(EcuM_ASR40_UserType user)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR40_RequestRUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_ReleaseRUN(EcuM_ASR40_UserType user)
{
  return EcuM_ASR40_ReleaseRUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_RequestPOST_RUN(EcuM_ASR40_UserType user)
{
  return EcuM_ASR40_RequestPOST_RUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_ReleasePOST_RUN(EcuM_ASR40_UserType user)
{
  return EcuM_ASR40_ReleasePOST_RUN(user);
}
#endif /* (ECUM_ECUM_FIXED_SUPPORT == STD_ON) */

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_SelectShutdownTarget
(
    EcuM_ASR40_StateType target,
    uint8                mode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_SelectShutdownTarget(target, mode);
}

/* Deviation MISRA-1 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_GetShutdownTarget
(
    P2VAR(EcuM_ASR40_StateType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)                sleepMode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_GetShutdownTarget(shutdownTarget, sleepMode);
}

/* Deviation MISRA-1 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_GetLastShutdownTarget
(
    P2VAR(EcuM_ASR40_StateType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)                sleepMode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_GetLastShutdownTarget(shutdownTarget, sleepMode);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_SelectShutdownCause
(
  EcuM_ASR40_ShutdownCauseType target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_SelectShutdownCause(target);
}

/* Deviation MISRA-1 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_GetShutdownCause
(
  P2VAR(EcuM_ASR40_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_GetShutdownCause(shutdownCause);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_GetMostRecentShutdown
(
  P2VAR(EcuM_ASR40_StateType, AUTOMATIC, ECUM_APPL_DATA)         target,
  P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)                        mode,
  P2VAR(EcuM_ASR40_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) cause,
  P2VAR(uint32, AUTOMATIC, ECUM_APPL_DATA)                       time
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_GetMostRecentShutdown(target, mode, cause, time);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_ASR40_Rte_GetNextRecentShutdown
(
  P2VAR(EcuM_ASR40_StateType, AUTOMATIC, ECUM_APPL_DATA)         target,
  P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)                        mode,
  P2VAR(EcuM_ASR40_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) cause,
  P2VAR(uint32, AUTOMATIC, ECUM_APPL_DATA)                       time
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_GetNextRecentShutdown(target, mode, cause, time);
}

FUNC(Std_ReturnType,ECUM_CODE) EcuM_ASR40_Rte_SelectBootTarget
(
    EcuM_ASR40_BootTargetType target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_SelectBootTarget(target);
}

FUNC(Std_ReturnType,ECUM_CODE) EcuM_ASR40_Rte_GetBootTarget
(
    P2VAR(EcuM_ASR40_BootTargetType, AUTOMATIC, RTE_APPL_DATA) target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM109,1 */
  return EcuM_ASR40_GetBootTarget(target);
}


#define ECUM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* (ECUM_EB_ENABLE_ASR40_SERVICE_API == STD_ON) */
#endif /* (ECUM_INCLUDE_RTE == STD_ON) */

/*==================[internal function definitions]=========================*/

#if ((ECUM_INCLUDE_RTE == STD_OFF) || \
     (ECUM_EB_ENABLE_ASR40_SERVICE_API == STD_OFF))

#include <TSCompiler.h>           /* usage of macro in TSCompiler_Default.h */

/* Avoid empty translation unit according to ISO C90 */
TS_PREVENTEMPTYTRANSLATIONUNIT

#endif /* ((ECUM_INCLUDE_RTE == STD_OFF) || (ECUM_EB_ENABLE_ASR40_SERVICE_API == STD_OFF)) */

/*==================[end of file]===========================================*/