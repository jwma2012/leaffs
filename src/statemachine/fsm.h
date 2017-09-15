#ifndef _FSM_H_
#define _FSM_H_

void FSM_Init(FSM_T* pFsm);
void FSM_Regist(FSM_T* pFsm,STATE_TABLE_S* pStateTable,int FsmId,int curFsmTableSize);
void FSM_Begin(FSM_T* pFsm,int FsmId);
void FSM_MoveState(FSM_T* pFsm,int state);
void FSM_EventHandle(FSM_T* pFsm,int event);
void FSM_Push(FSM_T* pFsm);
void FSM_Pop(FSM_T* pFsm);

#endif