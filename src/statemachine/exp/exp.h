#ifndef _FSM_H_
#define _FSM_H_

typedef enum {
    EVNET1 = 1;
    EVENT2;
    EVENT3;
} EVENT;

typedef void *hook_t(void* pFsm);

typedef struct tag_act_table {
    EVENT evt;
    hook_t func;
}ACT_TABLE_T;

typedef struct tag_state_table {
    STATE state;
    ACT_TABLE_T *act_table;
}STATE_TABLE_T;

struct tag_fsm
{
    int curState;                        //当前状态机状态
    int curFsmTableSize;                 //当前状态机查询表大小
    STATE_TABLE_T* curFsmTable;          //当前状态机查询表
    FSM_STACK_T stack[MAX_FSM_STACK_DEP];//状态机堆栈
    int curStackTop;                     //栈顶
    FSM_REGIST_T registFsm[MAX_FSM_NUM]; //注册状态机
    int registFsmNum;                    //注册状态机个数
}FSM_T;

void FSM_Init(FSM_T* pFsm);
void FSM_Regist(FSM_T* pFsm,STATE_TABLE_S* pStateTable,int FsmId,int curFsmTableSize);
void FSM_Begin(FSM_T* pFsm,int FsmId);
void FSM_MoveState(FSM_T* pFsm,int state);
void FSM_EventHandle(FSM_T* pFsm,int event);
void FSM_Push(FSM_T* pFsm);
void FSM_Pop(FSM_T* pFsm);

#endif