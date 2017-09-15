#include "exp.h"

/*状态1的动作表*/
ACT_TABLE_T state1ActTable[] = {
    {EVENT1,state1Event1Fun},
    {EVENT3,state1Event3Fun},
};
/*状态2的动作表*/
ACT_TABLE_T state2ActTable[] = {
    {EVENT2,state2Event2Fun},
};
/*状态表*/
STATE_TABLE_T FsmTable[] = {
    {STATE1,state1ActTable},
    {STATE2,state2ActTable},
};

int main(int argc, _TCHAR* argv[])
{
    FSM_T fsm;
    /*状态表注册*/
    FSM_Regist(&fsm,FsmTable);
    FSM_MoveState(&fsm,STATE1);
    FSM_EventHandle(&fsm,EVENT1);
    FSM_EventHandle(&fsm,EVENT2);
    return 0;
}
/*客户端提供的状态处理函数*/
void state1Event1Fun(void* pFsm)
{
    FSM_MoveState((FSM_T*)pFsm,STATE2);
    return;
}
void state1Event3Fun(void* pFsm)
{
    FSM_MoveState((FSM_T*)pFsm,STATE3);
    return;
}
void state2Event2Fun(void* pFsm)
{
    FSM_MoveState((FSM_T*)pFsm,STATE3);
    return;
}
